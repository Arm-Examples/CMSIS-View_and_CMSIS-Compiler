/*------------------------------------------------------------------------------
 * Example main module
 * Copyright (c) 2018-2022 Arm Limited (or its affiliates). All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    main.c
 * Purpose: Main module
 *----------------------------------------------------------------------------*/

#include "RTE_Components.h"

#include "cmsis_os2.h"                  // ::CMSIS:RTOS2

#include "peripherals.h"                // Keil::Board Support:SDK Project Template:Project_Template
#include "pin_mux.h"                    // Keil::Board Support:SDK Project Template:Project_Template
#include "board.h"                      // Keil::Board Support:SDK Project Template:Project_Template


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

  osKernelInitialize();                         // Initialize CMSIS-RTOS2
  osThreadNew(app_main, NULL, &app_main_attr);  // Create application main thread
  osKernelStart();                              // Start thread execution

  for (;;) {}
}
