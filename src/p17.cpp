#include <Arduino.h>

uint16_t estB;

void setup()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN_Msk;

    GPIOA->CRL |= 0x11111111;             // config.: 00 : output push-pull and mode: 01 : output max speed 10MHz
    GPIOB->CRL &= ~(1u << 0) & ~(1u << 1) // mode: 00 : input
                      & ~(1u << 2) |
                  (1u << 3); // config.: 01 : floating input
}
void loop()
{
    estB = GPIOB->IDR & (1 << 0);
    if (estB == '0')
    {
        GPIOA->BSRR |= (1u << 0) | (1u << 2) | (1u << 4) | (1u << 6);
    }
    else
    {
        GPIOB->BSRR |= (1u << 1) | (1u << 3) | (1 << 5) | (1 << 7);
    }
}