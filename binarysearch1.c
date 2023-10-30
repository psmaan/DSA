#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key,i;
    int left = 0;
    int right = n - 1;
    int found = 0;
    
    for(i = 0 ; i <n ; i++){
    	printf("%d \n",arr[i]);
	}

    printf("Enter the element to search: ");
    scanf("%d", &key);

    while (left <= right) {
        int mid = (left + right)  / 2;

        if (arr[mid] == key) {
            printf("The element is found at index %d\n", mid);
            found = 1;
            break;
        }

        if (arr[mid] < key) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }

    if (!found) {
        printf("The element is not found\n");
    }

    return 0;
}

