#include<stdio.h>
#include<string.h>

#define max(a, b) (a > b ? (a) : (b))
int mat[11][11];
int op_buffer[11] = {0};
int r, c, m;

void swap(int* a, int*b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void mirror()
{
    for(int i=0;i<r/2;i++)
        for(int j=0;j<c;j++)
            swap(&mat[i][j], &mat[r-i-1][j]);
}

void transpose()
{
    for(int i=0;i<max(r, c);i++)
        for(int j=i;j<max(r, c);j++)
            swap(&mat[i][j], &mat[j][i]);
    swap(&r, &c);
    for(int i=0;i<r/2;i++)
        for(int j=0;j<c;j++)
            swap(&mat[i][j], &mat[r-i-1][j]);
}


int solve()
{
    memset(mat, 0, sizeof(mat));
    if(scanf("%d %d %d", &r, &c, &m) == EOF) return -1;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d", &mat[i][j]);

    for(int i=0;i<m;i++)
    {
        scanf("%d", &op_buffer[i]);
    }
    for(int i=m-1;i>=0;i--)
    {
        if(op_buffer[i] == 0)
            transpose();
        else
            mirror();
    }
    printf("%d %d\n", r, c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d", mat[i][j]);
            if(j!=c-1)
            {
                printf(" ");
            }
        }

        printf("\n");
    }
    return 0;
}

int main()
{
    while(solve() != -1);
    return 0;
}
