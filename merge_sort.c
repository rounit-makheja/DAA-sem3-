#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r) {
	int *temp = (int *)malloc((r+1) * sizeof(int));
	int i=l, j=m+1, k=l;
	while (i <= m && j <=r)
		temp[k++]=(arr[i] <= arr[j]) ? arr[i++] : arr[j++];
	while(i<=m) temp[k++] = arr[i++];
	while(j<=r) temp[k++] = arr[j++];
	for(i=l; i<=r; i++) arr[i] = temp[i];
	free(temp);
}

void mergeSort(int arr[], int l, int r) {
	if(l<r) {
		int m=l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
