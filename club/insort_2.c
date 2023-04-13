#include <stdio.h>
int arr[1007] = {0};
int sorted[1007] = {0};
int size = 0, sorted_size = 1;

void pt_array()
{
    for (int i = 0; i < sorted_size; i++)
    {
        printf("%d", sorted[i]);
        if (i != sorted_size - 1)
            printf(",");
    }
    printf("\n");
}

int main()
{
    int x;
    while (scanf("%d", &x) != EOF)
        arr[size++] = x;

    sorted[0] = arr[0]; // holds true (loop invariant)
    printf("\n");
    pt_array();
    for (int i = 1; i < size; i++)
    {
        sorted_size++;
        int chosen = arr[i], j = i;
        while (j > 0 && sorted[j - 1] > chosen)
            sorted[j--] = sorted[j];
        sorted[j] = chosen;
        pt_array();
    }
    return 0;
}