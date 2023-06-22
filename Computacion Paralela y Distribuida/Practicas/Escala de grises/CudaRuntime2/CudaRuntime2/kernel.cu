#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include "device_launch_parameters.h"
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#define CHANNELS 3

void Usage(char prog_name[]) 
{
    fprintf(stderr, "Usage: %s <image file path>\n", prog_name);
    exit(EXIT_FAILURE);
}

__global__      
void colorToGreyscaleConversion(unsigned char* Input_Image, unsigned char* Output_Image, int width, int height)
{
    int Col = blockIdx.x * blockDim.x + threadIdx.x;  
    int Row = blockIdx.y * blockDim.y + threadIdx.y; 

    if (Row < height && Col < width) { 
        int offset = Row * width + Col;
        
        int rgbOffset = offset * CHANNELS;
        

        unsigned char r = Input_Image[rgbOffset]; 

        unsigned char g = Input_Image[rgbOffset + 1];  

        unsigned char b = Input_Image[rgbOffset + 2];   


        Output_Image[offset] = 0.21f * r + 0.71f * g + 0.07f * b;
        
    }
}


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
    

    h_origImg = (unsigned char*)malloc(width * height * channels * sizeof(unsigned char));
   
    h_resultImg = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    
    (void)memcpy(h_origImg, origImg.data, width * height * channels);
    

    unsigned char* d_origImg, * d_resultImg;
   
    cudaMalloc((void**)&d_origImg, width * height * channels * sizeof(unsigned char));
    
    cudaMalloc((void**)&d_resultImg, width * height * sizeof(unsigned char));
    

    cudaMemcpy(d_origImg, h_origImg, width * height * channels * sizeof(unsigned char), cudaMemcpyHostToDevice);
    

    const int block_size = 16; 
    dim3 threads(block_size, block_size); 
    dim3 grid(ceil(width / (double)threads.x), ceil(height / (double)threads.y));


    colorToGreyscaleConversion << <grid, threads >> > (d_origImg, d_resultImg, width, height);
    

    cudaMemcpy(h_resultImg, d_resultImg, width * height * sizeof(unsigned char), cudaMemcpyDeviceToHost);


    cv::Mat resultImg(height, width, CV_8UC1); 
    memcpy(resultImg.data, h_resultImg, width * height); 

    cudaFree(d_origImg); 
    cudaFree(d_resultImg); 

    free(h_origImg); 
    free(h_resultImg); 

    cv::resize(resultImg, resultImg, cv::Size(width / 2, height / 2));


    cv::imwrite("grey.jpg", resultImg);

    return 0;
}



