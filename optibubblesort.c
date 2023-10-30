#include<stdio.h>

void bubblesort(int arr[],int n){
	int i , j , temp, count = 0;
	for(i = 0 ; i < n - 1 ; i++){
			count++;
			int flag;
		for(j = 0 ; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				flag = 1;
				temp  = arr[j];
				arr[j] = arr[j+1];
				arr[j+1 ] = temp;
			}
			if(flag == 0){
				break;
			}
		}
	}
}

void printlist(int arr[],  int n){
	int i ;
	for(i = 0 ; i < n ; i++){
		printf("%d \n", arr[i]);
	}
}

int main(){
	int arr[] = {10,20,30,40,60,50};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("Array before sorting.....");
	printlist(arr,n);
	
	bubblesort(arr,n);
	
	printf("Array after sorting");
	printlist(arr,n);
}
