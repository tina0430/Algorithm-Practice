#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r){

	int tmp_len = r-p+1;
	int* tmp = new int [tmp_len];
	memset(tmp, 0, tmp_len * sizeof(int));
	int i = p, j = q+1, t = 1;

	while ( i <= q && j <= r) {
		tmp[t++]  = arr[i] <= arr[j] ? arr[i++] : arr[j++];
	}
	while (i <= q) {
		tmp[t++] = arr[i++];
	}
	while (j <= r) {
		tmp[t++] = arr[j++];
	}

	//tmp 배열에 있는 정렬이 완료된 수를 원래 배열에 옮기기
	i = p; t = 1;
	while( i <= r ) {
		arr[i++] = tmp[t++];
	}
}

void mergeSort(int arr[], int p, int r){
	if ( p < r ) {
		int q = (p+r)/2;
		mergeSort(arr, p, q);
		mergeSort(arr, q+1, r);
		merge(arr, p, q,  r);
	}
}

/*
int main () {
	int arr[] =  {9,2,4,6,10,3,8,1,5,7,11};
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, arr_len-1);
	for ( int i = 0 ; i < arr_len ; i ++) {
		cout <<"arr["<<i<<"] : " << arr[i] <<endl;
	}
    return 0;
}
*/