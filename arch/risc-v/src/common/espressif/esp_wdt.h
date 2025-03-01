/****************************************************************************
 * arch/risc-v/src/common/espressif/esp_wdt.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_RISCV_SRC_COMMON_ESPRESSIF_ESP_WDT_H
#define __ARCH_RISCV_SRC_COMMON_ESPRESSIF_ESP_WDT_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* IOCTL Commands ***********************************************************/

/* The watchdog driver uses a standard character driver framework.  However,
 * since the watchdog driver is a device control interface and not a data
 * transfer interface, the majority of the functionality is implemented in
 * driver ioctl calls.
 *
 * See nuttx/timers/watchdog.h for the IOCTLs handled by the upper half.
 *
 * These are detected and handled by the "lower half" watchdog timer driver.
 *
 * WDIOC_RSTCLK     - Restores the xtal32k clock
 *                    Argument: Ignored
 */

#define WDIOC_RSTCLK      _WDIOC(0x032)

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* Instances of Watchdog Timer  */

enum esp_wdt_inst_e
{
  ESP_WDT_MWDT0 = 0,  /* Main System Watchdog Timer (MWDT) of Timer Group 0 */
  ESP_WDT_MWDT1,      /* Main System Watchdog Timer (MWDT) of Timer Group 1 */
  ESP_WDT_RWDT,       /* RTC Watchdog Timer (RWDT) */
  ESP_WDT_XTAL32K     /* XTAL32K Watchdog Timer (XTWDT) */
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Name: esp_wdt_initialize
 *
 * Description:
 *   Initialize the watchdog timer.
 *
 * Input Parameters:
 *   devpath - The full path to the watchdog.  This should
 *             be of the form /dev/watchdogX
 *   wdt_id  - A Watchdog Timer instance to be initialized.
 *
 * Returned Values:
 *   Zero (OK) is returned on success; a negated errno value is returned on
 *   any failure.
 *
 ****************************************************************************/

int esp_wdt_initialize(const char *devpath, enum esp_wdt_inst_e wdt_id);

#endif /* __ARCH_RISCV_SRC_COMMON_ESPRESSIF_ESP_WDT_H */
