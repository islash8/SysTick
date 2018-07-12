#include "tm4c123gh6pm.h"
#include <stdint.h>


/**
 * main.c
 */
int main(void)
{
    uint32_t x;
    SYSCTL_RCGC2_R |= 0x20;
    GPIO_PORTF_DIR_R = 0x0E;
    GPIO_PORTF_DEN_R = 0x0E;

    NVIC_ST_RELOAD_R = 0xFFFFFF; // reload reg. with max value
    NVIC_ST_CTRL_R = 5; // enable it, no interrupt, use system clock

    while(1)
    {
        x = NVIC_ST_CURRENT_R;
        x = x >> 20;
        GPIO_PORTF_DATA_R = x;
    }
	return 0;
}
