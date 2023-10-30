#include<stdio.h>
void  selectionsort(int arr[], int n){
	int i , j  , temp , min, count;
	for(i = 0 ; i < n - 1 ; i++){
		min = i;
		count++;
		int flag;
		for(j = i + 1 ; j < n ; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
	}       flag = 1;
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		if(flag == 0 ){
		break;
	}
	}
	
}

void  printlist(int arr[] , int n){
	int i ;
	for(i  = 0 ; i < n ; i++){
		printf("%d\n" , arr[i]);
	}
}

int main(){
	int arr[]= {10,20,30,50,40};
	int n  = sizeof(arr)  / sizeof(arr[0]);
	
	printf("Array elements before sorting");
	printlist(arr,n);
	
	selectionsort(arr,n);
	
	printf("Array elements after sorting");
	printlist(arr,n);
}
