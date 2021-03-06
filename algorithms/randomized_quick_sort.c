#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomized_quick_sort(int data[], int p, int r);
int randomized_partition(int data[], int p, int r);
int partition(int data[], int p, int r);

int main() {
    int data[] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int count = sizeof(data)/sizeof(int);

    randomized_quick_sort(data, 0, count - 1);

    int i = 0;
    for(; i < count; i++)
        printf("%d\t", data[i]);
    printf("\n");
    return 0;
}

void randomized_quick_sort(int data[], int p, int r)
{
    if (p < r) {
        int q = partition(data, p , r);
        randomized_quick_sort(data, p, q - 1);
        randomized_quick_sort(data, q + 1, r);
    }
}

int randomized_partition(int data[], int p, int r) {
    srand(time(0));
    int range = r - p + 1;
    int i = rand() % range + p;
    int temp = data[i];
    data[i] = data[r];
    data[r] = temp;
    return partition(data, p, r);
}

int partition(int data[], int p, int r)
{
    int x = data[r], i = p - 1, j = p, temp;
    for (; j < r; j++) {
        if (data[j] > x) {
            i++;
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }

    i++;
    data[r] = data[i];
    data[i] = x;
    return i;
}
