#include <Arduino.h>

uint16_t estB;

void setup()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN_Msk;

    GPIOA->CRL |= 0x11111111;           // config.: 00 : output push-pull and mode: 01 : output max speed 10MHz
    GPIOB->CRL &= ~(1 << 0) & ~(1 << 1) // mode: 00 : input
                      & ~(1 << 2) |
                  (1 << 3); // config.: 01 : floating input
}
void loop()
{
    estB = GPIOB->IDR & (1 << 0);
    if (estB = '1')
    {
        GPIOA->BSRR |= 0x000F; // 0b,0000,0000,0000,1111
    }
    else
    {
        GPIOA->BSRR |= 0x00F0; // 0b,0000,0000,1111,0000;
    }
}