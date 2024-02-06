/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network
 * Copyright (c) 2004-2018 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    Common_UI.h
 * Purpose: Common user interface implementation (Network examples)
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#include "RTE_Components.h"             // Component selection
#include "Common_UI.h"
#include "pin_mux.h"                    // NXP::Board Support:SDK Project Template:project_template
#include "fsl_gpio.h"                   // NXP::Device:SDK Drivers:gpio

/* Board Support API Enable (when available) */
#define BSP_ENABLE_LED           0      // LED: 0 - Disabled, 1 - Enabled
#define BSP_ENABLE_BUTTONS       0      // Buttons: 0 - Disabled, 1 - Enabled
#define BSP_ENABLE_ADC           0      // A/D converter: 0 - Disabled, 1 - Enabled
#define BSP_ENABLE_CONSOLE       2      // Console: 0 - Disabled, 1 - GLCD, 2 - STDOUT (prinf)

#if (BSP_ENABLE_LED == 1)
#include "Board_LED.h"                  // ::Board Support:LED
#endif
#if (BSP_ENABLE_BUTTONS == 1)
#include "Board_Buttons.h"              // ::Board Support:Buttons
#endif
#if (BSP_ENABLE_ADC == 1)
#include "Board_ADC.h"                  // ::Board Support:A/D Converter
#endif
#if (BSP_ENABLE_CONSOLE == 1)
#include "Board_GLCD.h"                 // ::Board Support:Graphic LCD
#include "GLCD_Config.h"
#endif

#if (BSP_ENABLE_CONSOLE == 1)
extern GLCD_FONT GLCD_Font_16x24;
#endif

/* Initialize user interface peripherals */
void UI_Initialize (void) {
#if (BSP_ENABLE_ADC == 1)
  ADC_Initialize();
#endif

#if (BSP_ENABLE_BUTTONS == 1)
  Buttons_Initialize();
#endif

#if (BSP_ENABLE_LED == 1)
  LED_Initialize();
#endif

#if (BSP_ENABLE_CONSOLE == 1)
  GLCD_Initialize ();
#endif
}

/* Read 12-bit analog input */
uint16_t UI_GetAnalogValue (void) {
#if (BSP_ENABLE_ADC == 1)
  int32_t val = 0;

  ADC_StartConversion();
  while (ADC_ConversionDone () < 0);
  val = ADC_GetValue();

  /* Return 12-bit A/D conversion result */
  return ((uint16_t)val);
#else
  return (0U);
#endif
}

/* Read digital inputs */
uint8_t UI_GetButtonState (void) {
#if (BSP_ENABLE_BUTTONS == 1)
  return ((uint8_t)Buttons_GetState ());
#else
  return (!GPIO_PinRead(BOARD_INITBUTTONS_USER_BUTTON_PORT, BOARD_INITBUTTONS_USER_BUTTON_PIN));
#endif
}

/* Set LED states to given value */
void UI_SetLedOutput (uint32_t val) {
#if (BSP_ENABLE_LED == 1)
  LED_SetOut(val);
#else
  (void)val;
#endif
}

void UI_SetIP (char *ipv4, char *ipv6) {
#if (BSP_ENABLE_CONSOLE == 1)
  char buf[64];
  uint32_t x = 0;

  if (ipv4 != NULL) {
    /* Set/Update IPv4 address */
    sprintf (buf, "IP4:%-16s", ipv4);
    GLCD_DrawString (x*16, 4*24, buf);
  }

  if (ipv6 != NULL) {
    /* Set/Update IPv4 address */
    sprintf (buf, "IP6:%.16s", ipv6);
    GLCD_DrawString ( x    *16, 5*24, buf);
    sprintf (buf, "%s", ipv6+16);
    GLCD_DrawString ((x+10)*16, 6*24, buf);
  }
#elif (BSP_ENABLE_CONSOLE == 2)
  if (ipv4 != NULL) {
    /* Set/Update IPv4 address */
    printf ("IP4:%-16s\n", ipv4);
  }

  if (ipv6 != NULL) {
    /* Set/Update IPv4 address */
    printf ("IP6:%s\n", ipv6);
  }
#else
  (void)ipv4;
  (void)ipv6;
#endif
}

void UI_SetText (char *line1, char *line2) {
#if (BSP_ENABLE_CONSOLE == 1)
  char buf[64];
  uint32_t x = 0;

  /* Update user text lines */
  if (line1 != NULL) {
    sprintf (buf, "%-20s", line1);
    GLCD_DrawString (x*16, 7*24, buf);
  }

  if (line2 != NULL) {
    sprintf (buf, "%-20s", line2);
    GLCD_DrawString (x*16, 8*24, buf);
  }
#elif (BSP_ENABLE_CONSOLE == 2)
  /* Update user text lines */
  if (line1 != NULL) {
    printf ("Line 1: ");
    printf ("%-20s\n", line1);
  }

  if (line2 != NULL) {
    printf ("Line 2: ");
    printf ("%-20s\n", line2);
  }
#else
  (void)line1;
  (void)line2;
#endif
}

void UI_SetHello (char *hello) {
#if (BSP_ENABLE_CONSOLE == 1)
  char buf[64];
  uint32_t x = 0;

  /* Setup GLCD */
  GLCD_SetBackgroundColor (GLCD_COLOR_BLUE);
  GLCD_SetForegroundColor (GLCD_COLOR_WHITE);
  GLCD_ClearScreen        ();
  GLCD_SetFont            (&GLCD_Font_16x24);
  GLCD_DrawString         (x*16, 1*24, "       MDK-MW       ");

  if (hello != NULL) {
    sprintf (buf, "%-20s", hello);
    GLCD_DrawString (x*16, 2*24, buf);
  }
#elif (BSP_ENABLE_CONSOLE == 2)
  printf ("       MDK-MW       \n");
  if (hello != NULL) {
    printf ("%-20s\n\n", hello);
  }
#else
  (void)hello;
#endif
}
