#pragma once

#include <stdint.h>
#include <stdbool.h>

/*-----------------------\
| Addresses              |
\-----------------------*/

#define GPIO_A_BASE_ADDR                0x40010800
#define GPIO_CRL_OFFSET                 0x00
#define GPIO_CRH_OFFSET                 0x04
#define GPIO_BSRR_OFFSET                0x10
#define GPIO_ODR_OFFSET                 0x0C            

/*-----------------------\
| Registers              |
\-----------------------*/

#define GPIO_CRL_REG                    *((uint32_t *) (GPIO_A_BASE_ADDR + GPIO_CRL_OFFSET))
#define GPIO_CRH_REG                    *((uint32_t *) (GPIO_A_BASE_ADDR + GPIO_CRH_OFFSET))
#define GPIO_BSRR_REG                   *((uint32_t *) (GPIO_A_BASE_ADDR + GPIO_BSRR_OFFSET))
#define GPIO_ODR_REG                   *((uint32_t *) (GPIO_A_BASE_ADDR + GPIO_ODR_OFFSET))


/*-----------------------\
| Config/Mode Offsets    |
\-----------------------*/

#define GPIO_CRL_MODE0_OFFSET           0
#define GPIO_CRL_MODE1_OFFSET           4
#define GPIO_CRL_MODE2_OFFSET           8
#define GPIO_CRL_MODE3_OFFSET           12
#define GPIO_CRL_MODE4_OFFSET           16
#define GPIO_CRL_MODE5_OFFSET           20
#define GPIO_CRL_MODE6_OFFSET           24
#define GPIO_CRL_MODE7_OFFSET           28

#define GPIO_CRL_CNF0_OFFSET            2
#define GPIO_CRL_CNF1_OFFSET            6
#define GPIO_CRL_CNF2_OFFSET            10
#define GPIO_CRL_CNF3_OFFSET            14
#define GPIO_CRL_CNF4_OFFSET            18
#define GPIO_CRL_CNF5_OFFSET            22
#define GPIO_CRL_CNF6_OFFSET            26
#define GPIO_CRL_CNF7_OFFSET            30


/*-----------------------\
| Configs/Modes          |
\-----------------------*/

#define GPIO_CR_INPUT_MODE              0b00 
#define GPIO_CR_OUTPUT_MODE_10MHZ       0b01
#define GPIO_CR_OUTPUT_MODE_2MHZ        0b10
#define GPIO_CR_OUTPUT_MODE_50MHZ       0b11

#define GPIO_CR_CNF_IN_ANALOG           0b00
#define GPIO_CR_CNF_IN_FLOATING         0b01
#define GPIO_CR_CNF_IN_PULL_UP_DOWN     0b10

#define GPIO_CR_CNF_OUT_GP_PUSH_PULL    0b00    /* General Purpose Push Pull */ 
#define GPIO_CR_CNF_OUT_GP_OPEN_DRAIN   0b01    /* General Purpose Open Drain */
#define GPIO_CR_CNF_OUT_AF_PUSH_PULL    0b10    /* Alternate Function Push Pull */
#define GPIO_CR_CNF_OUT_AF_OPEN_DRAIN   0b11    /* Alternate Function Open Drain */

/*-----------------------\
| Set / reset offsets    |
\-----------------------*/

#define GPIO_BSRR_SET_0_BIT             0
#define GPIO_BSRR_SET_1_BIT             1
#define GPIO_BSRR_SET_2_BIT             2
#define GPIO_BSRR_SET_3_BIT             3
#define GPIO_BSRR_SET_4_BIT             4
#define GPIO_BSRR_SET_5_BIT             5
#define GPIO_BSRR_SET_6_BIT             6
#define GPIO_BSRR_SET_7_BIT             7
#define GPIO_BSRR_SET_8_BIT             8
#define GPIO_BSRR_SET_9_BIT             9
#define GPIO_BSRR_SET_10_BIT            10
#define GPIO_BSRR_SET_11_BIT            11
#define GPIO_BSRR_SET_12_BIT            12
#define GPIO_BSRR_SET_13_BIT            13
#define GPIO_BSRR_SET_14_BIT            14
#define GPIO_BSRR_SET_15_BIT            15

#define GPIO_BSRR_RESET_0_BIT           16
#define GPIO_BSRR_RESET_1_BIT           17
#define GPIO_BSRR_RESET_2_BIT           18
#define GPIO_BSRR_RESET_3_BIT           19
#define GPIO_BSRR_RESET_4_BIT           20
#define GPIO_BSRR_RESET_5_BIT           21
#define GPIO_BSRR_RESET_6_BIT           22
#define GPIO_BSRR_RESET_7_BIT           23
#define GPIO_BSRR_RESET_8_BIT           24
#define GPIO_BSRR_RESET_9_BIT           25
#define GPIO_BSRR_RESET_10_BIT          26
#define GPIO_BSRR_RESET_11_BIT          27
#define GPIO_BSRR_RESET_12_BIT          28
#define GPIO_BSRR_RESET_13_BIT          29
#define GPIO_BSRR_RESET_14_BIT          30
#define GPIO_BSRR_RESET_15_BIT          31


/*-----------------------\
| Struct                 |
\-----------------------*/

struct gpio {
    enum gpio_port  port                               ;
    bool            (*write)    (struct gpio, uint32_t);
    uint32_t        (*read)     (struct gpio          );
    bool            (*set)      (struct gpio, uint32_t);
    bool            (*reset)    (struct gpio, uint32_t);
};

/*-----------------------\
| Enum                   |
\-----------------------*/

enum gpio_port {
    PORT_A  =   0,
    PORT_B  =   1,
    PORT_C  =   2,
    PORT_D  =   3,
    PORT_E  =   4,
    PORT_F  =   5,
    PORT_G  =   6,
};

/*-----------------------\
| Functions              |
\-----------------------*/

/**
 * @brief   
 *      Creates a new gpio struct with the
 *      correct set function pointers
 * 
 * @param   port:
 *      "enum gpio_port" of the Port that should
 *      be used by the gpio struct
 * 
 * @return
 *      "struct gpio" a new initialized struct
 *      of the given "port"
*/
struct gpio     gpio_new        (enum gpio_port port);

/**
 * @brief   
 *      writes the given mask to the gpio
 *      register
 * 
 * @param   self:
 *      "struct gpio" on which the function
 *      get called.
 * 
 * @param   mask:
 *      "uint32_t" value that overwrites the current
 *      gpio values.
 * 
 * @return
 *      "bool" value that states if the current gpio
 *      register corresponds with the desired
 *      mask
*/
bool            gpio_write      (struct gpio self, uint32_t mask);

/**
 * @brief   
 *      reads the current register value of the
 *      GPIO
 * 
 * @param   self:
 *      "struct gpio" on which the function
 *      get called.
 * 
 * @return
 *      "uint32_t" value of the current gpio register
*/
uint32_t        gpio_read       (struct gpio self);

/**
 * @brief
 *      Sets the bits, set in the given mask,
 *      in the GPIO register
 * 
 * @param   self:
 *      "struct gpio" on which the function
 *      gets called.
 * 
 * @param   mask:
 *      "uint32_t" value that sets the bits
 *      set in mask, inside the gpio register.
 * 
 * @return
 *      "bool" value that states if the current gpio
 *      register corresponds with the desired
 *      mask   
*/
bool            gpio_set        (struct gpio self, uint32_t mask);

/**
 * @brief
 *      Resets the bits, set in the given mask,
 *      in the GPIO register
 * 
 * @param   self:
 *      "struct gpio" on which the function
 *      gets called.
 * 
 * @param   mask:
 *      "uint32_t" value that resets the bits
 *      set in mask, inside the gpio register.
 * 
 * @return
 *      "bool" value that states if the current gpio
 *      register corresponds with the desired
 *      mask
*/
bool            gpio_reset      (struct gpio self, uint32_t mask);




