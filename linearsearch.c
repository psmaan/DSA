#include<stdio.h>
int main(){
	int arr[] = {10,20,30,40,50};
	int n = sizeof(arr) / sizeof(arr[0]);
	int key;
	int flag = 0  ,i ;

	
	for(i = 0 ; i < n; i++){
		printf("The elements are %d \n", arr[i]);
	}
	
	printf("Enter the element to search : ");
	scanf("%d", &key);
   for(i = 0 ; i < n ; i++)	{
   	if(key == arr[i]){
		printf("The element is found at index %d");
		flag = 1;
		break;
	}
   	
   }
	
	
	if(flag == 0){
		printf("The element is not found");
	}
	
	return 0;
}
