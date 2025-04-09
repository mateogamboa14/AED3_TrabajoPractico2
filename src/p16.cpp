#include <Arduino.h>

uint16_t estadoA;

void setup()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN_Msk;

    GPIOA->CRL |= 0x11111111;              // config.: 00 : output push-pull and mode: 01 : output max speed 10MHz
    GPIOB->CRL |= (1 << 0) & ~(1 << 1)     // Mode
                  & ~(1 << 2) & ~(1 << 3); //
}
void setup()
{
    estadoA = GPIOA->IDR;
    if (estadoA == 01010101)
    {
        GPIOB->BSRR |= (1u << 0);
    }
    else if (estadoA == 10101010)
    {
        GPIOB->BSRR & ~(1u << 0);
    }
}