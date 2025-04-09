#include <Arduino.h>

uint16_t estadoB, CA1;

void setup()
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN_Msk;
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN_Msk;

  GPIOA->CRL |= 0x11111111; // conf.: 0b00: output push-pull and mode: 0b01: output max speed 10MHz
  GPIOA->CRH |= 0x11111111;
  GPIOB->CRL |= 0x44444444; // conf.: 0b01: floating input and mode: 0b00: input, equivalent 0x4
  GPIOB->CRH |= 0x44444444;
}
void loop()
{
  estadoB = GPIOB->IDR;
  CA1 = ~estadoB;
  GPIOA->BSRR |= CA1 + 1;
}
