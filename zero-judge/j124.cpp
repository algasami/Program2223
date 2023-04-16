#include <bits/stdc++.h>

int64_t sum = 0;

int input()
{
    int mark;
    if (scanf("%d", &mark) == EOF)
        return 0;
    if (mark == 0)
        return 0;

    if (mark % 2)
    {
        int left = input();
        int mid = input();
        int right = input();
        if (left != 0)
            sum += abs(mark - left);
        if (mid != 0)
            sum += abs(mark - mid);
        if (right != 0)
            sum += abs(mark - right);
    }
    else
    {
        int left = input();
        int right = input();
        if (left != 0)
            sum += abs(mark - left);
        if (right != 0)
            sum += abs(mark - right);
    }

    return mark;
}

int main()
{
    input();
    printf("%lld", sum);
    return 0;
}