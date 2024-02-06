# Using CMSIS-View and CMSIS-Compiler

The [µVision](https://developer.arm.com/Tools%20and%20Software/Keil%20MDK) projects in this repository were used in the webinar ["Using CMSIS-View and CMSIS-Compiler"](https://on-demand.arm.com/flow/arm/devhub/sessionCatalog/page/pubSessCatalog/session/1706872120089001ictY).

## Fault_VHT_MPS2_Cortex-M7

This project is a simple **Fault** component example running on **Arm Cortex-M7** microcontroller simulated by 
[**Arm Virtual Hardware**](https://arm-software.github.io/AVH/main/simulation/html/Using.html) with the **VHT_MPS2_Cortex-M7** model simulator.

The application allows triggering of specific faults upon which the fault information is saved and system is reset.
When system restarts the fault information is output via the **Event Recorder**.

## File_Demo

This is a File System file manipulation example. You can format the drive and create, read, copy and delete files on it.

A detailed description is [available](https://www.keil.com/pack/doc/MW/FileSystem/html/fs_examples.html#fs_standalone_example).

## Hello_IMXRT1050-EVKB

This is a simple Hello World example for the NXP [IMXRT1050-EVKB](https://www.nxp.com/part/IMXRT1050-EVKB#/) Evaluation Kit.
This example prints "Hello World" and a counter value via the standard output which is routed to the debug console through Virtual COM port.

## HTTP_Server

This is a HTTP_Server example. It shows you how to use the Web Server CGI interface as well.

Detailed description is [available](https://www.keil.com/pack/doc/MW/Network/html/_compact__web__server__example.html).

Use this example to connect an evaluation board to a LAN with DHCP server (most LANs have this). The example will configure the network parameters automatically using a DHCP protocol.
