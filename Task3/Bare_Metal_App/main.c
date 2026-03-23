#include "BCM2837_GPIO.h"
#include <stdint.h>

#define ENABLE_RED_LED()    *(volatile uint32_t *)BCM2837_GPFSEL1 |= 1 << 18;
#define ENABLE_YELLOW_LED() *(volatile uint32_t *)BCM2837_GPFSEL2 |= 1 << 00;
#define ENABLE_GREEN_LED() *(volatile uint32_t *)BCM2837_GPFSEL2 |= 1 << 03;

#define RED_LED_ON()    *(volatile uint32_t *)BCM2837_GPSET0 = 1 << 16;
#define YELLOW_LED_ON() *(volatile uint32_t *)BCM2837_GPSET0 = 1 << 20;
#define GREEN_LED_ON()  *(volatile uint32_t *)BCM2837_GPSET0 = 1 << 21;

#define RED_LED_OFF()    *(volatile uint32_t *)BCM2837_GPCLR0 = 1 << 16;
#define YELLOW_LED_OFF() *(volatile uint32_t *)BCM2837_GPCLR0 = 1 << 20;
#define GREEN_LED_OFF()  *(volatile uint32_t *)BCM2837_GPCLR0 = 1 << 21;

int main(void)
{
    // Init
    ENABLE_RED_LED();

    uint32_t counter = 600000000;
    while (1)
    {
        /* code */
        counter = 600000000;
        
        RED_LED_ON();

        // Delay 
        while(counter--);

        RED_LED_OFF();

        counter = 600000000;

        while(counter--);

    }
    
}