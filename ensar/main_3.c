#include "stm32f4xx.h"

// Segments definitions for hexadecimal numbers
const uint8_t segment_map[16] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
    0b01110111, // A
    0b01111100, // B
    0b00111001, // C
    0b01011110, // D
    0b01111001, // E
    0b01110001  // F
};

// Function prototypes
void setup_GPIO(void);
void display_digit(uint8_t digit, uint8_t value);
void display_number(uint16_t number);
void delay(uint32_t count);
void handle_buttons(void);

// Global variables
volatile uint16_t result = 0;

int main(void)
{
  setup_GPIO();

  while (1)
  {
    display_number(result);
    handle_buttons();
    delay(100000); // Small delay for button debounce
  }
}

void setup_GPIO(void)
{
  // Enable clock for GPIOA, GPIOB, GPIOC
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;

  // Configure GPIOs for segments (assuming segments are connected to PA0-PA6)
  GPIOA->MODER = 0x55555555; // Set all PA pins as output

  // Configure GPIOs for digit select (assuming digits are connected to PB0-PB3)
  GPIOB->MODER = 0x00005555; // Set PB0-PB3 as output

  // Configure GPIOs for buttons (assuming buttons are connected to PC0-PC2)
  GPIOC->MODER &= ~0x0000003F; // Set PC0-PC2 as input
  GPIOC->PUPDR |= 0x00000015;  // Enable pull-up resistors for PC0-PC2
}

void display_digit(uint8_t digit, uint8_t value)
{
  // Turn off all digits
  GPIOB->ODR &= ~0x0F;

  // Set the segments
  GPIOA->ODR = segment_map[value];

  // Enable the specified digit
  GPIOB->ODR |= (1 << digit);
}

void display_number(uint16_t number)
{
  display_digit(0, (number >> 12) & 0xF);
  delay(10000);
  display_digit(1, (number >> 8) & 0xF);
  delay(10000);
  display_digit(2, (number >> 4) & 0xF);
  delay(10000);
  display_digit(3, number & 0xF);
  delay(10000);
}

void handle_buttons(void)
{
  // Check if button 1 is pressed (increment)
  if ((GPIOC->IDR & GPIO_IDR_ID0) == 0)
  {
    result++;
    while ((GPIOC->IDR & GPIO_IDR_ID0) == 0)
      ; // Wait for button release
  }

  // Check if button 2 is pressed (decrement)
  if ((GPIOC->IDR & GPIO_IDR_ID1) == 0)
  {
    result--;
    while ((GPIOC->IDR & GPIO_IDR_ID1) == 0)
      ; // Wait for button release
  }

  // Check if button 3 is pressed (reset)
  if ((GPIOC->IDR & GPIO_IDR_ID2) == 0)
  {
    result = 0;
    while ((GPIOC->IDR & GPIO_IDR_ID2) == 0)
      ; // Wait for button release
  }
}

void delay(uint32_t count)
{
  while (count--)
    ;
}
