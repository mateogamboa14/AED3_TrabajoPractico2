#include <Arduino.h>
uint16_t estadoB;
void setuo(){

RCC -> APB2ENR |=RCC_APB2ENR_IOPAEN_Msk;
RCC -> APB2ENR |=RCC_APB2ENR_IOPBEN_Msk;

GPIOA -> CRL |= 0X11111111;
GPIOA -> CRH |= 0X11111111;
GPIOB -> CRL |= 0X44444444;
GPIOB -> CRH |= 0X44444444;

}
void loop(){

estadoB = GPIOB -> IDR;
 GPIOA -> BSRR =~estadoB;


}