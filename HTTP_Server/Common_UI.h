/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network
 * Copyright (c) 2004-2018 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    Common_UI.h
 * Purpose: Common board to user interface header
 *----------------------------------------------------------------------------*/

#ifndef COMMON_UI_H__
#define COMMON_UI_H__

#include <stdint.h>

/* Common board to user interface */
extern void     UI_Initialize     (void);
extern uint16_t UI_GetAnalogValue (void);
extern uint8_t  UI_GetButtonState (void);
extern void     UI_SetLedOutput   (uint32_t val);
extern void     UI_SetIP          (char *ipv4,  char *ipv6);
extern void     UI_SetText        (char *line1, char *line2);
extern void     UI_SetHello       (char *hello);


#endif /* COMMON_UI_H__ */
