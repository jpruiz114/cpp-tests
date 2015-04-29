#include "cuda_runtime.h"

#include <stdio.h>

// device = GPU
// host = CPU

// This will run on the device (GPU).
__global__ void add(int *a, int *b, int *c) {
	*c = *a + *b;
}

int main(void) {
	// host copies of a, b, c
	int a, b, c;

	// device copies of a, b, c
	int *d_a, *d_b, *d_c;

	int size = sizeof(int);

	// Allocate space for device copies of a, b, c
	cudaMalloc((void **)&d_a, size);
	cudaMalloc((void **)&d_b, size);
	cudaMalloc((void **)&d_c, size);
	
	// Setup input values
	a = 4;
	b = 6;
	
	// Copy inputs to device
	cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

	// Launch add() kernel on GPU
	add<<<1,1>>>(d_a, d_b, d_c);
	
	// Copy result back to host
	cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
	
	// Cleanup
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);

	printf("%d + %d = %d", a, b, c);
	
	return 0;
}