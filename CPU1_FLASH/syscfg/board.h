/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// EPWM5 -> inverter1 Pinmux
//
//
// EPWM5_A - GPIO Settings
//
#define GPIO_PIN_EPWM5_A 16
#define inverter1_EPWMA_GPIO 16
#define inverter1_EPWMA_PIN_CONFIG GPIO_16_EPWM5_A
//
// EPWM5_B - GPIO Settings
//
#define GPIO_PIN_EPWM5_B 17
#define inverter1_EPWMB_GPIO 17
#define inverter1_EPWMB_PIN_CONFIG GPIO_17_EPWM5_B

//
// EPWM6 -> inverter2 Pinmux
//
//
// EPWM6_A - GPIO Settings
//
#define GPIO_PIN_EPWM6_A 10
#define inverter2_EPWMA_GPIO 10
#define inverter2_EPWMA_PIN_CONFIG GPIO_10_EPWM6_A
//
// EPWM6_B - GPIO Settings
//
#define GPIO_PIN_EPWM6_B 11
#define inverter2_EPWMB_GPIO 11
#define inverter2_EPWMB_PIN_CONFIG GPIO_11_EPWM6_B

//
// EPWM1 -> Sync_adc Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0
#define Sync_adc_EPWMA_GPIO 0
#define Sync_adc_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1
#define Sync_adc_EPWMB_GPIO 1
#define Sync_adc_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B

//
// EPWM2 -> LPF_Graph Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2
#define LPF_Graph_EPWMA_GPIO 2
#define LPF_Graph_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3
#define LPF_Graph_EPWMB_GPIO 3
#define LPF_Graph_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B
//
// GPIO32 - GPIO Settings
//
#define LED_GPIO_PIN_CONFIG GPIO_32_GPIO32

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define current_adc_BASE ADCA_BASE
#define current_adc_RESULT_BASE ADCARESULT_BASE
#define current_adc_SOC0 ADC_SOC_NUMBER0
#define current_adc_FORCE_SOC0 ADC_FORCE_SOC0
#define current_adc_SAMPLE_WINDOW_SOC0 100
#define current_adc_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM1_SOCA
#define current_adc_CHANNEL_SOC0 ADC_CH_ADCIN0
void current_adc_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define inverter1_BASE EPWM5_BASE
#define inverter1_TBPRD 5000
#define inverter1_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define inverter1_TBPHS 0
#define inverter1_CMPA 2500
#define inverter1_CMPB 0
#define inverter1_CMPC 0
#define inverter1_CMPD 0
#define inverter1_DBRED 10
#define inverter1_DBFED 10
#define inverter1_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define inverter1_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define inverter1_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define inverter2_BASE EPWM6_BASE
#define inverter2_TBPRD 5000
#define inverter2_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define inverter2_TBPHS 0
#define inverter2_CMPA 2500
#define inverter2_CMPB 0
#define inverter2_CMPC 0
#define inverter2_CMPD 0
#define inverter2_DBRED 10
#define inverter2_DBFED 10
#define inverter2_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define inverter2_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define inverter2_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define Sync_adc_BASE EPWM1_BASE
#define Sync_adc_TBPRD 5000
#define Sync_adc_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define Sync_adc_TBPHS 0
#define Sync_adc_CMPA 2500
#define Sync_adc_CMPB 0
#define Sync_adc_CMPC 0
#define Sync_adc_CMPD 0
#define Sync_adc_DBRED 0
#define Sync_adc_DBFED 0
#define Sync_adc_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define Sync_adc_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define Sync_adc_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define LPF_Graph_BASE EPWM2_BASE
#define LPF_Graph_TBPRD 5000
#define LPF_Graph_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define LPF_Graph_TBPHS 0
#define LPF_Graph_CMPA 2500
#define LPF_Graph_CMPB 0
#define LPF_Graph_CMPC 0
#define LPF_Graph_CMPD 0
#define LPF_Graph_DBRED 10
#define LPF_Graph_DBFED 10
#define LPF_Graph_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define LPF_Graph_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define LPF_Graph_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define LED 32
void LED_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_current_adc_1
#define INT_current_adc_1 INT_ADCA1
#define INT_current_adc_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_current_adc_1_ISR(void);

// Interrupt Settings for INT_myCPUTIMER0
#define INT_myCPUTIMER0 INT_TIMER0
#define INT_myCPUTIMER0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myCPUTIMER0_ISR(void);

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	CPUTIMER_init();
void	EPWM_init();
void	GPIO_init();
void	INTERRUPT_init();
void	SYNC_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
