#include <stdio.h>

int a[100];
int subset[100];
int result[100][100];
int resultSize[100];
int n, target;
int total = 0;

void subsetSum(int index, int sum, int size) {
    if (sum == target) {
        for (int i = 0; i < size; i++)
            result[total][i] = subset[i];

        resultSize[total] = size;
        total++;
        return;
    }

    if (index == n || sum > target)
        return;

    subset[size] = a[index];
    subsetSum(index + 1, sum + a[index], size + 1);

    subsetSum(index + 1, sum, size);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &target);

    subsetSum(0, 0, 0);

    if (total == 0) {
        printf("-1\n");
    } else {
        for (int i = total - 1; i >= 0; i--) {
            for (int j = 0; j < resultSize[i]; j++)
                printf("%d ", result[i][j]);

            printf("\n");
        }
    }

    return 0;
}
