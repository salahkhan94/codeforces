#include <stdlib.h>
#include <stdio.h>

int inspect_bits(unsigned int number)
{
    unsigned int n=1;
    while(number!=0){
        if(number%2) n|=n<<1;
        else n=1;

        if(n==7) return 1;
        
        number/=2;
    }
    return 0;
}

#ifndef RunTests
int main ()
{
    printf("%d", inspect_bits(5));
}
#endif