#include "stm32f4xx.h"

void setup_GPIO(void)
{
  // Enable clock for GPIOA
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

  // Configure PA5, PA6, PA7, and PA8 as output
  GPIOA->MODER |= GPIO_MODER_MODER5_0 | GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0 | GPIO_MODER_MODER8_0;
  GPIOA->MODER &= ~(GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_1 | GPIO_MODER_MODER7_1 | GPIO_MODER_MODER8_1);
}

void setup_Timer(void)
{
  // Enable clock for TIM2
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

  // Configure TIM2: prescaler and auto-reload value
  TIM2->PSC = 16000 - 1;      // Prescaler to have the timer tick every 1ms
  TIM2->ARR = 200 - 1;        // Auto-reload value for 200ms intervals
  TIM2->DIER |= TIM_DIER_UIE; // Enable update interrupt
  TIM2->CR1 |= TIM_CR1_CEN;   // Enable timer

  // Enable TIM2 interrupt in NVIC
  NVIC_EnableIRQ(TIM2_IRQn);
}

volatile int led_state = 0;

void TIM2_IRQHandler(void)
{
  if (TIM2->SR & TIM_SR_UIF)
  {                          // If update interrupt flag is set
    TIM2->SR &= ~TIM_SR_UIF; // Clear update interrupt flag

    // Update LED state
    GPIOA->ODR &= ~(GPIO_ODR_OD5 | GPIO_ODR_OD6 | GPIO_ODR_OD7 | GPIO_ODR_OD8); // Turn off all LEDs
    switch (led_state)
    {
    case 0:
      GPIOA->ODR |= GPIO_ODR_OD5; // Turn on LED on PA5
      break;
    case 1:
      GPIOA->ODR |= GPIO_ODR_OD6; // Turn on LED on PA6
      break;
    case 2:
      GPIOA->ODR |= GPIO_ODR_OD7; // Turn on LED on PA7
      break;
    case 3:
      GPIOA->ODR |= GPIO_ODR_OD8; // Turn on LED on PA8
      break;
    }
    led_state = (led_state + 1) % 4; // Move to the next LED
  }
}

int main(void)
{
  setup_GPIO();
  setup_Timer();

  while (1)
  {
    // Main loop does nothing, everything is handled by interrupts
  }
}
