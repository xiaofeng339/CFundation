#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	

void  SelectionSortString(char** arr, int len) {
	for (int i = 0; i < len; ++i) {
		int min = i;
		for (int j = i + 1; j < len; ++j) {
			if (strcmp(arr[j], arr[min]) < 0) {
				min = j;
			}
		}
		if (min != i) {
			char* temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
void  selectionSort1(int arr[],int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}
}

void  selectionSort(int **arr, int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}
}

int printArr(int arr[],int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ",arr[i]);
	}
}
