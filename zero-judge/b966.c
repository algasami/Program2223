#include<stdio.h>
#include<limits.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b
// To make interval overlapping easier and faster, we can compute all of them after
// registering the interval.
//
// Given an interval a[x, y)
// I[x] += 1
// I[y] -= 1
//
// Example:
// I = [0, 0, 0, 0, 0, 0]
// Interval [1,4)
// I = [0, 1, 0, 0, -1, 0]
// Compute:
// I = [0, 1, 1, 1, 0, 0]
//
// Time complexity: O(n) compute

char buffer[10000000 + 7000];
int min_l = INT_MAX;
int max_r = 0;

int main()
{
    int n; scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        // I have no idea why I should do Presuf+1 but it just works lol
        buffer[l+1]++; buffer[r+1]--;
        min_l = min(min_l, l+1);
        max_r = max(max_r, r+1);
    }
    int len=0;
    for(int i=max(1,min_l-5);i<=max_r+5;i++)
    {
        buffer[i] += buffer[i-1];
        if(buffer[i] > 0)
            len++;
    }
    printf("%d", len);
    return 0;
}
