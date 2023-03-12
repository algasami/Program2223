#include<stdio.h>

int count = 0;
// need to sort the grade, but since it spans from 0 to 100, I can use a hash table
int hash[101] = {0}; // don't forget that 100!!!

int main()
{
    scanf("%d", &count);
    for(int i=0;i<count;i++)
    {
        int grade; scanf("%d", &grade);
        hash[grade] += 1;
    }
    int highest_fail = -1;
    int lowest_pass = -1;
    int pass_once = 0;
    for(int g=0;g<101;g++)
    {
        if(hash[g] > 0)
        {
            if(g < 60)
                highest_fail = g;
            else if(!pass_once)
            {
                pass_once = 1;
                lowest_pass = g;
            }
        }
        for(int j=0;j<hash[g];j++)
        {
            printf("%d ", g);
        }
    }
    printf("\n");
    if(highest_fail < 0)
        printf("best case\n");
    else
        printf("%d\n", highest_fail);
    if(lowest_pass < 0)
        printf("worst case\n");
    else
        printf("%d\n", lowest_pass);

    return 0;
}
