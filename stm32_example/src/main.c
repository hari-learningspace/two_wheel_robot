include<stm32f40x.h> // File name depends on device used

    uint32_t volatile msTicks; // Counter for millisecond Interval

void SysTick_Handler(void) { // SysTick Interrupt Handler
  msTicks++;                 // Increment Counter
}

void WaitForTick(void) {
  uint32_t curTicks;

  curTicks = msTicks;           // Save Current SysTick Value
  while (msTicks == curTicks) { // Wait for next SysTick Interrupt
    __WFE();                    // Power-Down until next Event/Interrupt
  }
}

void TIM1_UP_IRQHandler(void) { // Timer Interrupt Handler
  ;                             // Add user code here
}

void timer1_init(int frequency) {    // Set up Timer (device specific)
  NVIC_SetPriority(TIM1_UP_IRQn, 1); // Set Timer priority
  NVIC_EnableIRQ(TIM1_UP_IRQn);      // Enable Timer Interrupt
}

void Device_Initialization(void) {              // Configure & Initialize MCU
  if (SysTick_Config(SystemCoreClock / 1000)) { // SysTick 1mSec
       : // Handle Error
  }
  timer1_init(); // setup device-specific timer
}

// The processor clock is initialized by CMSIS startup + system file
void main(void) {           // user application starts here
  Device_Initialization();  // Configure & Initialize MCU
  while (1) {               // Endless Loop (the Super-Loop)
    __disable_irq();        // Disable all interrupts
    Get_InputValues();      // Read Values
    __enable_irq();         // Enable all interrupts
    Calculation_Response(); // Calculate Results
    Output_Response();      // Output Results
    WaitForTick();          // Synchronize to SysTick Timer
  }
}