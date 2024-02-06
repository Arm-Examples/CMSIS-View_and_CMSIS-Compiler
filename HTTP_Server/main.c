/*------------------------------------------------------------------------------
 * Example main module
 * Copyright (c) 2018-2022 Arm Limited (or its affiliates). All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    main.c
 * Purpose: Main module
 *----------------------------------------------------------------------------*/

#include "cmsis_os2.h"                  // ::CMSIS:RTOS2

#include "peripherals.h"                // Keil::Board Support:SDK Project Template:Project_Template
#include "pin_mux.h"                    // Keil::Board Support:SDK Project Template:Project_Template
#include "board.h"                      // Keil::Board Support:SDK Project Template:Project_Template
#include "fsl_iomuxc.h"                 // NXP::Device:SDK Drivers:iomuxc


extern       void           app_main (void *arg);
extern const osThreadAttr_t app_main_attr;

/*------------------------------------------------------------------------------
 * main function
 *----------------------------------------------------------------------------*/
int main (void) {

  // System initialization
  BOARD_ConfigMPU();
  BOARD_InitBootPeripherals();
  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();

  // Update System Core Clock info
  SystemCoreClockUpdate();

  // Reset Ethernet PHY (Required 100 us delay for PHY power on reset)
  GPIO_PinWrite(GPIO1,  9U, 0U);
  SDK_DelayAtLeastUs(500U, CLOCK_GetFreq(kCLOCK_CpuClk));
  GPIO_PinWrite(GPIO1,  9U, 1U);

  osKernelInitialize ();                        // Initialize CMSIS-RTOS2
  osThreadNew (app_main, NULL, &app_main_attr); // Create application main thread
  osKernelStart ();                             // Start thread execution

  for (;;) {}
}
