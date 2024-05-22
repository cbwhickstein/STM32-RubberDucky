#include <rcc.h>
#include <gpio.h>

int main() 
{
    
    struct rcc rcc;
    struct gpio gpio;
    
    rcc = rcc_new();
    gpio = gpio_new(PORT_A);

    rcc.init();


    while (1) {
        gpio.set(gpio, GPIO_BSRR_SET_0_BIT);
        for (volatile int i = 0; i<100000; i++); //eddit the max boundary for changeing delay time
        gpio.reset(gpio, GPIO_BSRR_RESET_0_BIT);
        for (volatile int i = 0; i<100000; i++); //eddit the max boundary for changeing delay time
    }

    return 0;
}