#include <Arduino.h>

uint16_t estB;

void setup()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN_Msk;

    GPIOA->CRL |= 0x11111111;           // config.: 00 : output push-pull and mode: 01 : output max speed 10MHz
    GPIOB->CRL &= ~(1 << 0) & ~(1 << 1) // Mode : 00 : input
                      & ~(1 << 2) |
                  (1 << 3); // config.: 01 : floating input
}
void setup()
{
    estB = GPIOB->IDR & (1u << 0);
    if (estB == '1')
    {
        GPIOA->BSRR |= (1u << 0) | (1u << 2) | (1u << 4) | (1u << 6);
    }
    else
    {
        GPIOB->BSRR |= (1u << 1) | (1U << 3) | (1U << 5) | (1u << 7);
    }
}