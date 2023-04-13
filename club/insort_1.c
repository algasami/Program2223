#include <stdio.h>
int arr[10] = {0};
int size = 0;

void pt_array()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int x;
    while (scanf("%d", &x) != EOF)
        arr[size++] = x;
    pt_array();

    for (int i = 1; i < size; i++)
    {
        int chosen = arr[i];
        int j = i;
        while (j > 0 && arr[--j] > chosen)
            arr[j + 1] = arr[j];
        arr[j] = chosen;
        pt_array();
    }
    return 0;
}