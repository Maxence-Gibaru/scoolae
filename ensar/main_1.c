#include "stm32f4xx.h"

void delay(uint32_t count)
{
  while (count--)
    ;
}

int main(void)
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN;
  GPIOA->MODER |= GPIO_MODER_MODER5_0;
  GPIOA->MODER &= ~GPIO_MODER_MODER5_1;
  GPIOC->MODER &= ~(GPIO_MODER_MODER13_0 | GPIO_MODER_MODER13_1);
  GPIOC->PUPDR |= GPIO_PUPDR_PUPD13_0;

  int blinking = 0;
  int button_pressed = 0;

  while (1)
  {
    if ((GPIOC->IDR & GPIO_IDR_ID13) == 0)
    {
      if (!button_pressed)
      {
        button_pressed = 1;
        blinking = !blinking;
      }
    }
    else
    {
      button_pressed = 0;
    }

    if (blinking)
    {
      GPIOA->ODR ^= GPIO_ODR_OD5;
      delay(1000000);
    }
    else
    {
      GPIOA->ODR &= ~GPIO_ODR_OD5;
    }

    delay(100000);
  }
}
