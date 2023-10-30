#include<stdio.h>

int partition(int arr[], int low  , int high){
	
	int temp,pivot,start,end;
	pivot = arr[low];
	start = low;
	end  = high;

	while(start < end ){
		
	
		while(arr[start] <= pivot){
			start ++;
		}
	
		while(arr[end] >  pivot){
			end -- ;
		}
	
		if(start < end){
			temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
	
	}

		temp  = arr[low];
		arr[low] = arr[end];
		arr[end] = temp;

	return end;

}

void QuickSort(int arr[] , int start , int end){
	if(start < end){
		
		int p = partition(arr, start ,end);
		QuickSort(arr,start, p - 1);
		QuickSort(arr,p + 1, end);
	}
}

void printlist( int arr[], int n){
	int i ;  
	for(i = 0 ; i < n ;  i++){
		printf("%d \n",arr[i]);
	}
}

int main(){
	
	int start , end;
	int arr[] = {10,7,9,20,4,15};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Array elements before sorting.....\n");
	printlist(arr,n);
	QuickSort(arr,0,n-1);
	printf("Array elements after sorting..........\n");
	printlist(arr,n);
	
	return 0;

}
