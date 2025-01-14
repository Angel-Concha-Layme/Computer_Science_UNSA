﻿#include<cuda.h>
#include<cuda_runtime_api.h>
#include<device_launch_parameters.h>
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include"matrix_helper.h"
#include"gpu_timer.h"
#include"cuda_runtime.h"
#include"device_launch_parameters.h"

#define BLOCK_SIZE 16

__global__ void kernel_matrix_multiply(float* M, float* N, float* P, int M_rows, int M_cols, int N_rows, int N_cols)
{
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < M_rows && col < N_cols)
    {
        float Pvalue = 0;
        for (int k = 0; k < M_cols; k++) {
            Pvalue += M[row * M_cols + k] * N[k * N_cols + col];
        }
        P[row * N_cols + col] = Pvalue;
    }
}


__global__ void kernel_matrix_multiply_block(float* M, float* N, float* P, int M_rows, int M_cols, int N_rows, int N_cols){
    int tx = threadIdx.x;
    int ty = threadIdx.y;
    int row_in_P = blockIdx.y * BLOCK_SIZE + threadIdx.y;
    int col_in_P = blockIdx.x * BLOCK_SIZE + threadIdx.x;
    __shared__ float M_sub[BLOCK_SIZE][BLOCK_SIZE];
    __shared__ float N_sub[BLOCK_SIZE][BLOCK_SIZE];

    float Pvalue = 0;
    for (int j = 0; j < ceil(M_cols / (float)BLOCK_SIZE); j++) {
        if ((row_in_P < M_rows) && (j * BLOCK_SIZE + tx < M_cols))
            M_sub[ty][tx] = M[row_in_P * M_cols + j * BLOCK_SIZE + tx];
        else M_sub[ty][tx] = 0;

        if ((j * BLOCK_SIZE + ty < N_rows) && (col_in_P < N_cols))
            N_sub[ty][tx] = N[(j * BLOCK_SIZE + ty) * N_cols + col_in_P];
        else N_sub[ty][tx] = 0;

        __syncthreads();

        for (int k = 0; k < BLOCK_SIZE; k++) {
            Pvalue += M_sub[ty][k] * N_sub[k][tx];
        }

        __syncthreads();
    }
    if ((row_in_P < M_rows) && (col_in_P < N_cols)) P[row_in_P * N_cols + col_in_P] = Pvalue;
}


void gpu_matrix_multiply(float* M, float* N, float* P, int M_rows, int M_cols, int N_rows, int N_cols,
    void(*kernel)(float* M, float* N, float* P, int M_rows, int M_cols, int N_rows, int N_cols))
{
    float* d_M, * d_N, * d_P;
    cudaMalloc((void**)&d_M, M_rows * M_cols * sizeof(float));
    cudaMalloc((void**)&d_N, N_rows * N_cols * sizeof(float));
    cudaMalloc((void**)&d_P, M_rows * N_cols * sizeof(float));

    cudaMemcpy(d_M, M, M_rows * M_cols * sizeof(float), cudaMemcpyHostToDevice);    
    cudaMemcpy(d_N, N, N_rows * N_cols * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemset(d_P, 0, M_rows * N_cols * sizeof(float));

    dim3 block(BLOCK_SIZE, BLOCK_SIZE);
    dim3 grid((N_cols - 1) / block.y + 1, (M_rows - 1) / block.x + 1);
    GpuTimer timer;
    timer.Start();
    kernel << <grid, block >> > (d_M, d_N, d_P, M_rows, M_cols, N_rows, N_cols);
    timer.Stop();
    printf("Time cost:%f ms\n", timer.Elapsed());

    cudaMemcpy(P, d_P, M_rows * N_cols * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(d_M);
    cudaFree(d_N);
    cudaFree(d_P);
}


int main(int argc, char** argv)
{
    if (argc == 1) {
        int test_size = 1024;
        float* M1 = (float*)malloc(test_size * test_size * sizeof(float));
        float* N1 = (float*)malloc(test_size * test_size * sizeof(float));
        printf("Matrix Multiplication (GPU):\n");
        float* P1 = (float*)malloc(test_size * test_size * sizeof(float));
        float* Pb1 = (float*)malloc(test_size * test_size * sizeof(float));

        gpu_matrix_multiply(M1, N1, P1, test_size, test_size, test_size, test_size, kernel_matrix_multiply);
        gpu_matrix_multiply(M1, N1, Pb1, test_size, test_size, test_size, test_size, kernel_matrix_multiply_block);
        if (compare_matrix(P1, Pb1, test_size, test_size) == 1) { printf("##Passed!\n\n"); }
        else { printf("@@Failed!\n\n"); }
        free(M1);
        free(N1);
        free(P1);
        free(Pb1);
        exit(-1);
    }

    if (argc < 4) {
        printf("Usage: command    matrix-M-filename    matrix-N-filename   matrix-P-filename   matrix-R-filename");
        return -1;
    }


    const char* matrix_M_filename = argv[1];
    const char* matrix_N_filename = argv[2];
    const char* matrix_P_filename = argv[3];
    const char* matrix_R_filename = argv[4];



    int M_rows, M_cols;
    float* M = read_matrix(matrix_M_filename, &M_rows, &M_cols);

 
    int N_rows, N_cols;
    float* N = read_matrix(matrix_N_filename, &N_rows, &N_cols);

    if (M_cols != N_rows) {
        printf("Rows and Cols don't match!");
        exit(-1);
    }

 
    printf("Matrix Multiplication (GPU):\n");
    float* P = (float*)malloc(M_rows * N_cols * sizeof(float));

    gpu_matrix_multiply(M, N, P, M_rows, M_cols, N_rows, N_cols, kernel_matrix_multiply);


    printf("Block Matrix Multiplication (GPU):\n");
    float* Pb = (float*)malloc(M_rows * N_cols * sizeof(float));

    gpu_matrix_multiply(M, N, Pb, M_rows, M_cols, N_rows, N_cols, kernel_matrix_multiply_block);
    if (compare_matrix(P, Pb, M_rows, N_cols) == 1) { printf("##Passed!\n\n"); }
    else { printf("@@Failed!\n\n"); }

    write_matrix(matrix_P_filename, P, M_rows, N_cols);


    if (matrix_R_filename != NULL) {
        printf("\n Checking results ... \n");
        int R_rows, R_cols;
        float* R = read_matrix(matrix_R_filename, &R_rows, &R_cols);;
        if (compare_matrix(P, R, R_rows, R_cols) == 1) { printf("##Passed!\n\n"); }
        else { printf("@@Failed!\n\n"); }
        free(R);
    }

    free(M);
    free(N);
    free(P);
    free(Pb);

    return 0;
}