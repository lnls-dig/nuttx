/****************************************************************************
 * arch/sim/src/sim/sim_copyfullstate.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <string.h>
#include <arch/irq.h>

#include "sim_internal.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: sim_copyfullstate
 *
 * Description:
 *    Copy the entire register save area
 *
 ****************************************************************************/

void sim_copyfullstate(xcpt_reg_t *dest, xcpt_reg_t *src)
{
  /* In the sim model, the state is copied from the stack to the TCB,
   * but only a reference is passed to get the state from the TCB.  So the
   * following check avoids copying the TCB save area onto itself:
   */

  if (src != dest)
    {
      memmove(dest, src, XCPTCONTEXT_REGS * sizeof(xcpt_reg_t));
    }
}
