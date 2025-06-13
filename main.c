#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_NONSTDC_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N_NUMBERS  10

void initialize_array(int A[], int size);
void print_array(int A[], int size);
int find_max1(int A[], int n);
int find_max2(int A[], int left, int high);
void find_max3(int A[], int size, int index, int* max);

int main() {
	int A[N_NUMBERS];
	initialize_array(A, N_NUMBERS);
	print_array(A, N_NUMBERS);
	printf("max1 = %d\n", find_max1(A, N_NUMBERS-1));
	printf("max2 = %d\n", find_max2(A, 0, N_NUMBERS - 1));
	int max = 0;
	find_max3(A, N_NUMBERS, 0, &max);
	printf("max2 = %d\n", max);
	return 0;
}

void initialize_array(int A[], int size) {
	for (int i = 0; i < size; i++) {
		A[i] = rand() % 100;  // 0~99 사이의 난수
	}
}
void print_array(int A[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%3d ", A[i]);
	}
	printf("\n");
}


int find_max1(int A[], int n) {
	if (n == 0) return A[n];
	int max = find_max1(A, n - 1);
	return A[n] > max ? A[n] : max;
}

int find_max2(int A[], int left, int right) {
	if (left == right) return A[left];
	int mid = (left + right) / 2;
	int max_left = find_max2(A, left, mid);
	int max_right = find_max2(A, mid + 1, right);
	return (max_left > max_right) ? max_left : max_right;
}

void find_max3(int A[], int size, int index, int* max)
{
	if (index != size) {
		if (A[index] > *max)
			*max = A[index];
		find_max3(A, size, ++index, max);
	}
}