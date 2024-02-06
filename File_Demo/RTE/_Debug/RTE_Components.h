
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'File_Demo' 
 * Target:  'Debug' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "fsl_device_registers.h"

/* ARM::CMSIS-Compiler:OS Interface:CMSIS-RTOS2@2.0.0 */
#define RTE_CMSIS_Compiler_OS_Interface       /* Compiler OS Interface */
        #define RTE_CMSIS_Compiler_OS_Interface_RTOS2 /* Compiler OS Interface: CMSIS-RTOS2 */
        /* Features */
        #define RTE_CMSIS_Compiler_OS_Interface_RTOS2_LOCKS     /* Implements _mutex functions */
        #define RTE_CMSIS_Compiler_OS_Interface_RTOS2_LIBSPACE  /* Implements per-thread static data management */
/* ARM::CMSIS-Compiler:STDERR:Custom@1.0.0 */
#define RTE_CMSIS_Compiler_STDERR                /* CMSIS-Compiler STDERR */
        #define RTE_CMSIS_Compiler_STDERR_Custom         /* CMSIS-Compiler STDERR: Custom */
/* ARM::CMSIS-Compiler:STDIN:Custom@1.0.0 */
#define RTE_CMSIS_Compiler_STDIN                 /* CMSIS-Compiler STDIN */
        #define RTE_CMSIS_Compiler_STDIN_Custom          /* CMSIS-Compiler STDIN: Custom */
/* ARM::CMSIS-Compiler:STDOUT:Custom@1.0.0 */
#define RTE_CMSIS_Compiler_STDOUT                /* CMSIS-Compiler STDOUT */
        #define RTE_CMSIS_Compiler_STDOUT_Custom         /* CMSIS-Compiler STDOUT: Custom */
/* ARM::CMSIS-View:Event Recorder&DAP@1.5.3 */
#define RTE_CMSIS_View_EventRecorder
        #define RTE_CMSIS_View_EventRecorder_DAP
/* ARM::CMSIS:RTOS2:Keil RTX5&Source@5.8.0 */
#define RTE_CMSIS_RTOS2                 /* CMSIS-RTOS2 */
        #define RTE_CMSIS_RTOS2_RTX5            /* CMSIS-RTOS2 Keil RTX5 */
        #define RTE_CMSIS_RTOS2_RTX5_SOURCE     /* CMSIS-RTOS2 Keil RTX5 Source */
/* Keil::CMSIS Driver:MCI@1.5.0 */
#define RTE_Drivers_MCI0        (1U)    /* Driver MCI0 */
        #define RTE_Drivers_MCI1        (1U)    /* Driver MCI1 */
/* Keil::CMSIS-Compiler:File Interface:MDK-MW File System@1.0.0 */
#define RTE_CMSIS_Compiler_File_Interface        /* CMSIS-Compiler File Interface */
        #define RTE_CMSIS_Compiler_File_Interface_MDK_MW /* CMSIS-Compiler File Interface: MDK-Middleware File System */
/* Keil::File System&MDK-Plus:CORE&LFN Debug@6.16.6 */
#define RTE_FileSystem_Core             /* File System Core */
          #define RTE_FileSystem_LFN              /* File System with Long Filename support */
          #define RTE_FileSystem_Debug            /* File System Debug Version */
/* Keil::File System&MDK-Plus:Drive:Memory Card@6.16.6 */
#define RTE_FileSystem_Drive_MC_0       /* File System Memory Card Drive 0 */

/* NXP::Board Support:SDK Project Template:project_template&evkbimxrt1050@1.0.0 */
#ifndef XIP_EXTERNAL_FLASH
#define XIP_EXTERNAL_FLASH 1
#endif
#ifndef XIP_BOOT_HEADER_ENABLE
#define XIP_BOOT_HEADER_ENABLE 1
#endif
/* NXP::Device:SDK Utilities:serial_manager_uart@1.0.0 */
#ifndef SERIAL_PORT_TYPE_UART
#define SERIAL_PORT_TYPE_UART 1
#endif


#endif /* RTE_COMPONENTS_H */
