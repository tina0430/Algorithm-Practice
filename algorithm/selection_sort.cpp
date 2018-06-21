#include <iostream>
#include <queue>
using namespace std;

#include <stdio.h>


void selectionSort(int arr[], int arr_len){
	for ( int i = 0 ; i < arr_len-1 ; i++ ){
		
		int min_num = arr[i];
		int min_idx = i;
		for ( int j = i+1 ; j < arr_len ; j ++) {
			if (arr[j] < min_num){
				min_num = arr[j];
				min_idx = j;
			}
		}
		
		if (min_idx != i) {
			int temp = arr[i];
			arr[i] = min_num;
			arr[min_idx] = temp;
		}
	}
}


/*
int main () {
	int arr[] =  {9,2,11,4,6,10,3,8,1,5,7};
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, arr_len);
	
	for ( int i = 0 ; i < arr_len ; i ++) {
		printf("arr[%d] : %d\n", i, arr[i]);
	}
}
*/