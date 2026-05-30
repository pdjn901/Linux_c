#include <stdio.h>
#include <stdbool.h>


bool check_prime(int *num)
{
    if ((*num % 2) == 0)
        return 0;
    else 
        return 1;
}

int main()
{
    int i, j, n;
    printf("enter number to check prime or not:");
    scanf("%d",&n);
    if(check_prime(&n) == 0)
    {
        printf("prime");
    }
    else
    {
        printf("not prime");
    }
}