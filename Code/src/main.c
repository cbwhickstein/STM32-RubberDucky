#include <rcc.h>

int main() 
{
    struct rcc rcc = rcc_new();
    rcc.init();

    volatile int i = 1;

    while (1){
        i += 1;
        i += 2;
        i -= 3;
    }

    return i;
}