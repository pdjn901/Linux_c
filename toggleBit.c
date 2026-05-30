#include <stdio.h>

void setBit(unsigned int *i, int pos)
{
    *i ^= (1<<pos);
}

int main()
{
    unsigned int i = 0x1234;
    int pos = 2;
    printf("before:%x\n", i);
    setBit(&i,pos);
    printf("After:%x", i);
    return 0;
}