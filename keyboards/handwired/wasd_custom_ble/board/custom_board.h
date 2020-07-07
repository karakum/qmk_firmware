/**
 * Copyright (c) 2014 - 2017, Nordic Semiconductor ASA
 * Copyright (c) 2018, Sekigon
 * Copyright (c) 2020, Andrey Shertsinger
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

//#include "nrf_gpio.h"

#define NRF_GPIO_PIN_MAP(port, pin) (((port) << 5) | ((pin) & 0x1F))

#define COL00 NRF_GPIO_PIN_MAP(1,11)
#define COL01 NRF_GPIO_PIN_MAP(1,10)
#define COL02 NRF_GPIO_PIN_MAP(0,3)
#define COL03 NRF_GPIO_PIN_MAP(1,13)
#define COL04 NRF_GPIO_PIN_MAP(0,1)
#define COL05 NRF_GPIO_PIN_MAP(0,26)
#define COL06 NRF_GPIO_PIN_MAP(0,12)
#define COL07 NRF_GPIO_PIN_MAP(0,7)
#define COL08 NRF_GPIO_PIN_MAP(0,0)
#define COL09 NRF_GPIO_PIN_MAP(0,5)
#define COL10 NRF_GPIO_PIN_MAP(1,9)
#define COL11 NRF_GPIO_PIN_MAP(0,8)
#define COL12 NRF_GPIO_PIN_MAP(0,6)
#define COL13 NRF_GPIO_PIN_MAP(0,4)
#define COL14 NRF_GPIO_PIN_MAP(0,2)
#define COL15 NRF_GPIO_PIN_MAP(0,28)
#define ROW0 NRF_GPIO_PIN_MAP(1,2)
#define ROW1 NRF_GPIO_PIN_MAP(0,24)
#define ROW2 NRF_GPIO_PIN_MAP(1,0)
#define ROW3 NRF_GPIO_PIN_MAP(1,4)
#define ROW4 NRF_GPIO_PIN_MAP(0,17)
#define ROW5 NRF_GPIO_PIN_MAP(0,30)
#define ROW6 NRF_GPIO_PIN_MAP(0,10)
#define ROW7 NRF_GPIO_PIN_MAP(0,9)

#define LED1 NRF_GPIO_PIN_MAP(0,29)
#define LED2 NRF_GPIO_PIN_MAP(0,13)
#define LED3 NRF_GPIO_PIN_MAP(0,15)

#define VBATADC NRF_GPIO_PIN_MAP(0,31)
#define CHARGED NRF_GPIO_PIN_MAP(0,22)
#define STATUSLED NRF_GPIO_PIN_MAP(0,20)


// Low frequency clock source to be used by the SoftDevice
#ifdef S210
// #define NRF_CLOCK_LFCLKSRC      NRF_CLOCK_LFCLKSRC_XTAL_20_PPM
#else
#define NRF_CLOCK_LFCLKSRC      {.source        = NRF_CLOCK_LF_SRC_RC,            \
                                 .rc_ctiv       = 16,                                \
                                 .rc_temp_ctiv  = 2,                                \
                                 .xtal_accuracy = 0}
#endif

#ifdef __cplusplus
}
#endif

#endif // CUSTOM_BOARD_H
