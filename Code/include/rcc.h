/**
 * Contributions: 
 *      cbwhickstein
 * 
 * Description:
 *      This file contains the Reset and Clock Controll
 *      specific defines, enums, structs and functions.     
*/

#pragma once

/*-----------------------\
| Includes               |
\-----------------------*/
#include <stdint.h>

/*-----------------------\
| Register addresses     |
\-----------------------*/

#define RCC_BASE_ADDRESS            0x40021000
#define RCC_CR_OFFSET               0x00
#define RCC_CFGR_OFFSET             0x0C
#define RCC_APB2ENR_OFFSET          0x18
#define RCC_APB1ENR_OFFSET          0x1C

/*-----------------------\
| Registers              |
\-----------------------*/
#define RCC_CR_REG                  *((volatile uint32_t *)(RCC_BASE_ADDRESS + RCC_CR_OFFSET))
#define RCC_CFGR_REG                *((volatile uint32_t *)(RCC_BASE_ADDRESS + RCC_CFGR_OFFSET))
#define RCC_APB2ENR_REG             *((volatile uint32_t *)(RCC_BASE_ADDRESS + RCC_APB2ENR_OFFSET))
#define RCC_APB1ENR_REG             *((volatile uint32_t *)(RCC_BASE_ADDRESS + RCC_APB1ENR_OFFSET))


/*-----------------------\
| Bit offsets            |
\-----------------------*/

#define RCC_CR_PLLRDY_OFFSET        25
#define RCC_CR_PLLON_OFFSET         24
#define RCC_CR_HSERDY_OFFSET        17
#define RCC_CR_HSEON_OFFSET         16

#define RCC_CFGR_USBPRE_OFFSET      22
#define RCC_CFGR_PLLMUL_OFFSET      18
#define RCC_CFGR_PLLXTPRE_OFFSET    17
#define RCC_CFGR_PLLSRC_OFFSET      16
#define RCC_CFGR_PPRE2_OFFSET       11
#define RCC_CFGR_PPRE1_OFFSET       8
#define RCC_CFGR_HPRE_OFFSET        4
#define RCC_CFGR_SWS_OFFSET         2
#define RCC_CFGR_SW_OFFSET          0

#define RCC_APB2ENR_IOPAEN_OFFSET   2
#define RCC_APB2ENR_AFIOEN_OFFSET   0

#define RCC_APB1ENR_USBEN_OFFSET    23
#define RCC_APB1ENR_USART2EN_OFFSET 17

/*-----------------------\
| Bit values             |
\-----------------------*/

#define RCC_CR_PLLRDY_VALUE         0b1         /* PLL is ready  */
#define RCC_CR_PLLON_VALUE          0b1         /* Activate PLL  */
#define RCC_CR_HSERDY_VALUE         0b1         /* HSE CLK ready */
#define RCC_CR_HSEON_VALUE          0b1         /* Activate HSE  */

#define RCC_CFGR_USBPRE_VALUE       0b0         /* /1.5          */
#define RCC_CFGR_PLLMUL_VALUE       0b0111      /* x9            */
#define RCC_CFGR_PLLXTPRE_VALUE     0b0         /* /1            */
#define RCC_CFGR_PLLSRC_VALUE       0b1         /* HSE-CLK       */
#define RCC_CFGR_PPRE2_VALUE        0b000       /* /1            */
#define RCC_CFGR_PPRE1_VALUE        0b100       /* /2            */
#define RCC_CFGR_HPRE_VALUE         0b0000      /* /1            */
#define RCC_CFGR_SWS_VALUE          0b10        /* switched CLK  */
#define RCC_CFGR_SW_VALUE           0b10        /* PLLCLK        */

#define RCC_APB2ENR_IOPAEN_VALUE    0b1         /* Enable Port A */
#define RCC_APB2ENR_AFIOEN_VALUE    0b1         /* Enable AFIOs  */

#define RCC_APB1ENR_USBEN_VALUE     0b1         /* Enable USB    */
#define RCC_APB1ENR_USART2EN_VALUE  0b1         /* Enable USART2 */

/*-----------------------\
| Bit masks              |
\-----------------------*/

#define RCC_CR_PLLRDY_MASK          (RCC_CR_PLLRDY_VALUE << RCC_CR_PLLRDY_OFFSET)
#define RCC_CR_PLLON_MASK           (RCC_CR_PLLON_VALUE << RCC_CR_PLLON_OFFSET)
#define RCC_CR_HSERDY_MASK          (RCC_CR_HSERDY_VALUE << RCC_CR_HSERDY_OFFSET)
#define RCC_CR_HSEON_MASK           (RCC_CR_HSEON_VALUE << RCC_CR_HSEON_OFFSET)

#define RCC_CFGR_USBPRE_MASK        (RCC_CFGR_USBPRE_VALUE << RCC_CFGR_USBPRE_OFFSET)
#define RCC_CFGR_PLLMUL_MASK        (RCC_CFGR_PLLMUL_VALUE << RCC_CFGR_PLLMUL_OFFSET)
#define RCC_CFGR_PLLXTPRE_MASK      (RCC_CFGR_PLLXTPRE_VALUE << RCC_CFGR_PLLXTPRE_OFFSET)
#define RCC_CFGR_PLLSRC_MASK        (RCC_CFGR_PLLSRC_VALUE << RCC_CFGR_PLLSRC_OFFSET)
#define RCC_CFGR_PPRE2_MASK         (RCC_CFGR_PPRE2_VALUE << RCC_CFGR_PPRE2_OFFSET)
#define RCC_CFGR_PPRE1_MASK         (RCC_CFGR_PPRE1_VALUE << RCC_CFGR_PPRE1_OFFSET)
#define RCC_CFGR_HPRE_MASK          (RCC_CFGR_HPRE_VALUE << RCC_CFGR_HPRE_OFFSET)
#define RCC_CFGR_SWS_MASK           (RCC_CFGR_SWS_VALUE << RCC_CFGR_SWS_OFFSET)
#define RCC_CFGR_SW_MASK            (RCC_CFGR_SW_VALUE << RCC_CFGR_SW_OFFSET)

#define RCC_APB2ENR_IOPAEN_MASK     (RCC_APB2ENR_IOPAEN_VALUE << RCC_APB2ENR_IOPAEN_OFFSET)
#define RCC_APB2ENR_AFIOEN_MASK     (RCC_APB2ENR_AFIOEN_VALUE << RCC_APB2ENR_AFIOEN_OFFSET)

#define RCC_APB1ENR_USBEN_MASK      (RCC_APB1ENR_USBEN_VALUE << RCC_APB1ENR_USBEN_OFFSET)
#define RCC_APB1ENR_USART2EN_MASK   (RCC_APB1ENR_USART2EN_VALUE << RCC_APB1ENR_USART2EN_OFFSET)


/*-----------------------\
| Struct                 |
\-----------------------*/

struct rcc {
   uint8_t (*init)(void);
};

/*-----------------------\
| Functions              |
\-----------------------*/

/**
 * @brief   Creates a new rcc struct with the 
 *          correct set init function
*/
struct rcc     rcc_new     (void);

/**
 * @brief   Inits the rcc of the STM32 according to
 *          the application. Enabled ports can be seen
 *          in documentation.
*/
void           rcc_init    (void);

