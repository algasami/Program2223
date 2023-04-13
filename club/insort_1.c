#include <stdio.h>
int arr[1007] = {0};
int size = 0;

void pt_array()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i != size - 1)
            printf(",");
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
        int chosen = arr[i], j = i;
        while (j > 0 && arr[j - 1] > chosen)
            arr[j--] = arr[j];
        arr[j] = chosen;
        pt_array();
    }
    return 0;
}