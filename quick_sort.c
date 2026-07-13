#include <stdio.h>
void quickSort(int arr[], int low, int high) {
	if(low>=high) return;
	int pivot= arr[high], i=low,temp;
	for(int j=low;j<high;j++) {
		if(arr[j]<pivot){
			temp=arr[i];arr[i]=arr[j];arr[j]=temp;
			i++;
		}
	}
	arr[high]=arr[i];arr[i]=pivot;
	quickSort(arr,low,i-1);
	quickSort(arr,i+1,high);
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    // Input the size of the array
    scanf("%d", &n);
    int arr[n];
    
    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Print the original array
    printArray(arr, n);

    // Sort the array using quick sort
    quickSort(arr, 0, n - 1);
    
    // Print the sorted array
    printArray(arr, n);

    return 0;
}
