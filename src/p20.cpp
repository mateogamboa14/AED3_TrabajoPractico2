#include <Arduino.h>

uint estB0, estB1, estB2, estB3;

void setup()
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk;
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN_Msk;

    GPIOA->CRL |= 0x11111111; // config.: 00 : output push-pull and mode: 01 : output max speed 10MHz
    GPIOB->CRL |= 0x00004444; // config.: 01 : floating input and mode: 00 : input
}
void loop()
{
    estB0 = GPIOB->IDR & (1 << 0);
    estB1 = GPIOB->IDR & (1 << 1);
    estB2 = GPIOB->IDR & (1 << 2);
    estB3 = GPIOB->IDR & (1 << 3);
    if (estB0 == '1')
    {
        GPIOA->BSRR |= (1 << 0) | (1 << 1);
    }
    else if (estB1 == '1')
    {
        GPIOA->BSRR |= (1 << 2) | (1 << 3);
    }
    else if (estB2 == '1')
    {
        GPIOA->BSRR |= (1 << 4) | (1 << 5);
    }
    else if (estB3 == '1')
    {
        GPIOA->BSRR |= (1 << 6) | (1 << 7);
    }
}