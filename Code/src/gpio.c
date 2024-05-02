#include <gpio.h>


struct gpio gpio_new (enum gpio_port port) 
{
    struct gpio result = {
        .port   =   port,
        .write  =   gpio_write,
        .read   =   gpio_read,
        .set    =   gpio_set,
        .reset  =   gpio_reset,
    };
    return result;
}

bool gpio_write (struct gpio self, uint32_t mask) 
{
    //currently only port A is suported
    GPIO_BSRR_REG = mask;
    return true;
}

uint32_t gpio_read (struct gpio self) 
{
    return GPIO_ODR_REG;
}

bool gpio_set (struct gpio self, uint32_t mask) 
{
    self.write(self, mask & 0xFFFF);
    return true;
}

bool gpio_reset (struct gpio self, uint32_t mask) 
{
    self.write(self, mask & 0xFFFF0000);
    return true;
}
