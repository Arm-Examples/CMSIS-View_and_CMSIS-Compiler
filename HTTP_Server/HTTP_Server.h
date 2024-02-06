/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network
 * Copyright (c) 2004-2018 ARM Germany GmbH. All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    HTTP_Server.h
 * Purpose: HTTP Server example header
 *----------------------------------------------------------------------------*/

#ifndef HTTP_SERVER_H__
#define HTTP_SERVER_H__

#include "cmsis_os2.h"                  // ::CMSIS:RTOS2

#define SERVER_FLAG_DHCP 1U
#define SERVER_FLAG_TEXT 2U

#define SERVER_FLAG_MASK (SERVER_FLAG_DHCP | SERVER_FLAG_TEXT)

/* Application state structure */
typedef struct {
  char ip_v4[20];                       /* IPv4 address */
  char ip_v6[40];                       /* IPv6 address */
  char text[2][20+1];                   /* Two lines of text */
  uint16_t led_state;                   /* 0: not running, 1: running */
  osThreadId_t thread_ui;               /* Thread ID: User interface updater */
  osThreadId_t thread_led;              /* Thread ID: LED runner */
} APP_STATE;

/* Application state variable */
extern APP_STATE App;

/* Application main thread function */
extern void app_main (void *arg);

/* application main thread attributes */
extern const osThreadAttr_t app_main_attr;

#endif /* HTTP_SERVER_H__ */
