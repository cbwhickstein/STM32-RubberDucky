#include <rcc.h>

struct rcc rcc_new() 
{
    struct rcc result = 
    {
        .init = rcc_init
    };    
}


void rcc_init() 
{

    // activate oscillators
    RCC_CR_REG   =  RCC_CR_HSEON_MASK       |\
                    RCC_CR_PLLON_MASK;

    // wait until HSE and PLL are ready
    while ( (RCC_CR_REG & RCC_CR_HSERDY_MASK) &&\
                (RCC_CR_REG & RCC_CR_PLLRDY_MASK));

    // set CFGR register bitmasks
    RCC_CFGR_REG =  RCC_CFGR_USBPRE_MASK    |\
                    RCC_CFGR_PLLMUL_MASK    |\
                    RCC_CFGR_PLLXTPRE_MASK  |\
                    RCC_CFGR_PLLSRC_MASK    |\
                    RCC_CFGR_PPRE2_MASK     |\
                    RCC_CFGR_PPRE1_MASK     |\
                    RCC_CFGR_HPRE_MASK      |\
                    RCC_CFGR_SW_MASK;                       //Maybe this results in an error
                
    // enable AFIOs
    RCC_APB2ENR_REG = RCC_APB2ENR_IOPAEN_MASK |\
                      RCC_APB2ENR_AFIOEN_MASK;

    RCC_APB1ENR_REG = RCC_APB1ENR_USBEN_MASK |\
                      RCC_APB1ENR_USART2EN_MASK;

}