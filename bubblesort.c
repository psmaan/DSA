#include<stdio.h>

void bubblesort(int arr[],int n){
	int i , j , temp;
	for(i = 0 ; i < n - 1 ; i++){
		for(j = 0 ; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				temp  = arr[j];
				arr[j] = arr[j+1];
				arr[j+1 ] = temp;
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
	int arr[] = {20,40,30,50,10,60};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("Array before sorting.....");
	printlist(arr,n);
	
	bubblesort(arr,n);
	
	printf("Array after sorting");
	printlist(arr,n);
}
