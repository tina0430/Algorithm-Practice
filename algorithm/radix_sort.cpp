#include <iostream>
#include <queue>
using namespace std;


void radixSort(int arr[], int arr_len){
	queue<int> que[10];
	
	//자릿수 구하기
	int j = arr[0];
	for (int i = 1 ; i < arr_len ; i ++)
		if (arr[i] > j)	
			j = arr[i];

	int r = 1;
	while ( r*10 < j )	
		r *= 10;
	

	for ( int i = 1 ; i <= r ; i = i*10 ) {
		//큐에 넣기
		for ( int j = 0 ; j < arr_len ; j++ ) {
			int que_idx = (arr[j]%(i*10))/i;
			que[que_idx].push(arr[j]);
		}
		
		//큐에서 빼기
		int arr_idx = 0;
		for (int j = 0 ; j < 10 ; j++ ) {
			int que_len = que[j].size();
			for ( int s = 0 ; s < que_len ; s++ ) {
				if (!que[j].empty()){
					arr[arr_idx++] = que[j].front();
					que[j].pop();
				}
			}
		}
	}
	
}

/*
int main () {
	int arr[] =  {9,92,475,6,10,23,58,1,5,107,11, 3304, 22};
	int arr_len = sizeof(arr) / sizeof(arr[0]);
	radixSort(arr, arr_len);
	
	for ( int i = 0 ; i < arr_len ; i ++) {
		cout << "arr[" << i << "] : " << arr[i] <<endl;
	}
   return 0;
}
*/