// #############################################################################
//
//  FILE:   empty_driverlib_main.c
//
//! \addtogroup driver_example_list
//! <h1>Empty Project Example</h1>
//!
//! This example is an empty project setup for Driverlib development.
//!
//
// #############################################################################
//
//
// $Copyright:
// Copyright (C) 2024 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
// #############################################################################

//
// Included Files
//
#include "adc.h"
#include "board.h"
#include "c2000ware_libraries.h"
#include "device.h"
#include "driverlib.h"

#include "epwm.h"
#include "math.h"
#include "stdint.h"

#define PI 3.14159265358979
#define SINE_FREQ 50 // 50Hz sine wave frequency
#define ISR_FREQUENCY 10000

#define MAX_COMP 5000;

float V_mod_inverter = 0;
uint16_t compare1, compare2;
#define ADC_BUF_LEN 10
uint16_t AdcBuf[ADC_BUF_LEN];

interrupt void INT_myCPUTIMER0_ISR();
interrupt void INT_myADCA_1_ISR(void);

//
// Main
//
void main(void) {

  //
  // Initialize device clock and peripherals
  //
  Device_init();

  //
  // Disable pin locks and enable internal pull-ups.
  //
  Device_initGPIO();

  //
  // Initialize PIE and clear PIE registers. Disables CPU interrupts.
  //
  Interrupt_initModule();

  //
  // Initialize the PIE vector table with pointers to the shell Interrupt
  // Service Routines (ISR).
  //
  Interrupt_initVectorTable();

  //
  // PinMux and Peripheral Initialization
  //
  Board_init();

  //
  // C2000Ware Library initialization
  //
  C2000Ware_libraries_init();

  //
  // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
  //
  EINT;
  ERTM;

  while (1) {

    compare1 = V_mod_inverter * MAX_COMP;
    compare2 = -1 * V_mod_inverter * MAX_COMP;
    // EPWM_setCounterCompareValue(myEPWM5_BASE, EPWM_COUNTER_COMPARE_A,
    //                             compare1);
    // EPWM_setCounterCompareValue(myEPWM6_BASE, EPWM_COUNTER_COMPARE_A,
    //                             compare2);
  }
}

interrupt void INT_myCPUTIMER0_ISR() {
  // GPIO_togglePin(LED);
  static uint16_t index = 0;
  static const float step = 2 * PI * SINE_FREQ / ISR_FREQUENCY;
  V_mod_inverter = sin(step * index);
  index++;
  if (index >= (ISR_FREQUENCY / SINE_FREQ))
    index = 0;

  Interrupt_clearACKGroup(INT_myCPUTIMER0_INTERRUPT_ACK_GROUP);
}

interrupt void INT_myADCA_1_ISR(void) {
  static uint16_t *AdcBufPtr = AdcBuf;
  static volatile uint16_t LED_count = 0;
  // Read the ADC Result
  *AdcBufPtr++ = ADC_readResult(myADCA_RESULT_BASE, myADCA_SOC0);
  // Brute Force the circular buffer
  if (AdcBufPtr == (AdcBuf + ADC_BUF_LEN)) {
    AdcBufPtr = AdcBuf;
  }

  // Clear ADC before clear ACK!!!
  ADC_clearInterruptStatus(myADCA_BASE, ADC_INT_NUMBER1);
  Interrupt_clearACKGroup(INT_myADCA_1_INTERRUPT_ACK_GROUP);
}

//
// End of File
//
