#include <Arduino.h>

uint16_t estadoB, nor1, est0x23;

void setup()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN_Msk;

    GPIOA->CRL |= 0x11111111; // config.: 00 : output push pull and mode: 01 : output max speed 10MHz
    GPIOA->CRH |= 0x11111111;
    GPIOB->CRL |= 0x44444444; // config.: 01 : floating input and mode: 00 : input
    GPIOB->CRH |= 0x44444444;
}
void loop()
{
    estadoB = GPIOB->IDR;
    est0x23 = GPIOB->IDR & (1 << 0x23);
    nor1 = ~(estadoB || est0x23);
    GPIOA->BSRR |= nor1;
}
