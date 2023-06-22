#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include "device_launch_parameters.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#define CHANNELS 3
#define BLUR_SIZE 19

void Usage(char prog_name[]);
__global__
void blurKernel(unsigned char* Input_Image, unsigned char* Outpu_Image, int width, int height, int channel);

int main(int argc, char** argv)
{
    if (argc != 2) {
        Usage(argv[0]);
    }

    const char* file_name = argv[1];
    int width, height, channels;
    unsigned char* h_origImg, * h_resultImg;

    cv::Mat origImg = cv::imread(file_name);

    width = origImg.cols; 
    height = origImg.rows; 
    channels = origImg.channels(); 
    printf("Image size = (%d x %d x %d)\n", width, height, channels); 
    assert(channels == CHANNELS); 

    cv::Mat half; 
    cv::resize(origImg, half, cv::Size(width / 2, height / 2)); 
    cv::imshow("image", half); 
    cv::waitKey(0); 

    h_origImg = (unsigned char*)malloc(width * height * channels * sizeof(unsigned char));
    
    h_resultImg = (unsigned char*)malloc(width * height * channels * sizeof(unsigned char));
    
    (void)memcpy(h_origImg, origImg.data, width * height * channels);  


    unsigned char* d_origImg, * d_resultImg; 
    cudaMalloc((void**)&d_origImg, width * height * channels * sizeof(unsigned char));
    
    cudaMalloc((void**)&d_resultImg, width * height * channels * sizeof(unsigned char));
    


    cudaMemcpy(d_origImg, h_origImg, width * height * channels * sizeof(unsigned char), cudaMemcpyHostToDevice);
    


    const int block_size = 16; 
    dim3 threads(block_size, block_size, channels); 
    dim3 grid(ceil(height / (double)threads.x), ceil(width / (double)threads.y));
    
    blurKernel << <grid, threads >> > (d_origImg, d_resultImg, width, height, channels);
    


    cudaMemcpy(h_resultImg, d_resultImg, width * height * channels * sizeof(unsigned char), cudaMemcpyDeviceToHost);
    

    cv::Mat resultImg(height, width, CV_8UC3); 
    memcpy(resultImg.data, h_resultImg, width * height * channels); 


    
    cudaFree(d_origImg);
    cudaFree(d_resultImg);

    
    free(h_origImg);
    free(h_resultImg);


    cv::resize(resultImg, resultImg, cv::Size(width / 2, height / 2));
    cv::imwrite("Image_Blur.jpg", resultImg);

    return 0;
}

void Usage(char prog_name[])
{
    fprintf(stderr, "Usage: %s <image file path>\n", prog_name);
    exit(EXIT_FAILURE);
}

__global__
void blurKernel(unsigned char* Input_Image, unsigned char* Outpu_Image, int width, int height, int channel)
{
    int Plane = blockIdx.z * blockDim.z + threadIdx.z;
    int Row = blockIdx.y * blockDim.y + threadIdx.y;
    int Col = blockIdx.x * blockDim.x + threadIdx.x;

    if (Row < height && Col < width && Plane < channel) {
        int pixelVal = 0;
        int pixelCnt = 0;

        for (int bRow = -BLUR_SIZE; bRow < BLUR_SIZE; bRow++) {
            for (int bCol = -BLUR_SIZE; bCol < BLUR_SIZE; bCol++) {
                int curRow = Row + bRow;
                int curCol = Col + bCol;

                if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width) {
                    pixelVal += Input_Image[(curRow * width + curCol) * channel + Plane];
                    pixelCnt++;
                }
            }
        }

        Outpu_Image[(Row * width + Col) * channel + Plane] = (unsigned char)(pixelVal / pixelCnt);
    }
}