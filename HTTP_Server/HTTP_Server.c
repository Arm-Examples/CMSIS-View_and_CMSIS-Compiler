/*------------------------------------------------------------------------------
 * MDK Middleware - Component ::Network
 * Copyright (c) 2004-2019 Arm Limited (or its affiliates). All rights reserved.
 *------------------------------------------------------------------------------
 * Name:    HTTP_Server.c
 * Purpose: HTTP Server example
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#include "rl_net.h"                     // Keil.MDK-Pro::Network:CORE

#include "HTTP_Server.h"
#include "Common_UI.h"

/* Main stack size must be multiple of 8 Bytes */
#define APP_MAIN_STK_SZ (1024U)
static uint64_t app_main_stk[APP_MAIN_STK_SZ / 8];
const osThreadAttr_t app_main_attr = {
  .stack_mem  = &app_main_stk[0],
  .stack_size = sizeof(app_main_stk)
};

/* Function declarations */
static void BlinkLed (void *arg);
static void ServerUI (void *arg);
static void AppInitialize (void);

/* Application state */
APP_STATE App;

/* Set application initial states */
static void AppInitialize (void) {

  /* Initialize application state structure */
  memset (&App, 0x00, sizeof(App));

  strcpy (App.ip_v4,   "Waiting for DHCP");
  strcpy (App.text[0], "LCD line 1");
  strcpy (App.text[1], "LCD line 2");

  UI_Initialize();
  UI_SetHello ("HTTP Server example");
}

/* IP address change notification */
void netDHCP_Notify (uint32_t if_num, uint8_t option, const uint8_t *val, uint32_t len) {

  (void)if_num;
  (void)val;
  (void)len;

  if (option == NET_DHCP_OPTION_IP_ADDRESS) {
    /* IP address change, trigger user interface update */
    osThreadFlagsSet (App.thread_ui, SERVER_FLAG_DHCP);
  }
}

/*----------------------------------------------------------------------------
  Thread 'ServerUI': User interface update and control
 *---------------------------------------------------------------------------*/
static __NO_RETURN void ServerUI (void *arg) {
  uint8_t  ip_addr[NET_ADDR_IP6_LEN];
  uint32_t flags;

  (void)arg;

  /* Retrieve Link-local IPv6 address */
  netIF_GetOption (NET_IF_CLASS_ETH,
                   netIF_OptionIP6_LinkLocalAddress, ip_addr, sizeof(ip_addr));

  netIP_ntoa(NET_ADDR_IP6, ip_addr, App.ip_v6, sizeof(App.ip_v6));

  UI_SetIP (App.ip_v4, App.ip_v6);

  flags = 0U;

  while(1) {
    if ((flags & SERVER_FLAG_DHCP) != 0U) {
      /* DHCP callback, retrieve assigned IPv4 address */
      netIF_GetOption (NET_IF_CLASS_ETH,
                       netIF_OptionIP4_Address, ip_addr, sizeof(ip_addr));

      netIP_ntoa (NET_ADDR_IP4, ip_addr, App.ip_v4, sizeof(App.ip_v4));
      
      UI_SetIP (App.ip_v4, NULL);
    }
    
    if ((flags & SERVER_FLAG_TEXT) != 0U) {
      /* Update user text lines */
      UI_SetText (App.text[0], App.text[1]);
    }

    /* Wait until any flag received */
    flags = osThreadFlagsWait (SERVER_FLAG_MASK, osFlagsWaitAny, osWaitForever);
  }
}

/*----------------------------------------------------------------------------
  Thread 'BlinkLed': Blink the LEDs on an eval board
 *---------------------------------------------------------------------------*/
static __NO_RETURN void BlinkLed (void *arg) {
  uint8_t state = 0U;

  (void)arg;
  App.led_state = 1U;

  while(1) {
    if (App.led_state == 1U) {
      state ^= 1U;
      UI_SetLedOutput (state);
    }
    osDelay (100U);
  }
}

/*----------------------------------------------------------------------------
  Main Thread 'app_main': Run Network
 *---------------------------------------------------------------------------*/
__NO_RETURN void app_main (void *arg) {
  (void)arg;

  AppInitialize ();
  netInitialize ();

  App.thread_led = osThreadNew (BlinkLed, NULL, NULL);
  App.thread_ui  = osThreadNew (ServerUI, NULL, NULL);

  osThreadExit();
}
