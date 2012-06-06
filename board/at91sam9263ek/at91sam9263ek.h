/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2006, Atmel Corporation

 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __AT91SAM9263EK_H__
#define __AT91SAM9263EK_H__

/*
 * PMC Settings
 *
 * The main oscillator is enabled as soon as possible in the c_startup
 * and MCK is switched on the main oscillator.
 * PLL initialization is done later in the hw_init() function
 */
#if defined(CONFIG_CPU_CLK_200MHZ)
#if defined(CONFIG_CRYSTAL_16_36766MHZ)
#define MASTER_CLOCK		(199919000/2)
#define PLL_LOCK_TIMEOUT	1000000
#define PLLA_SETTINGS		0x20AABF0E
#define PLLB_SETTINGS		0x10483F0E
#endif /* #if defined(CONFIG_CRYSTAL_16_36766MHZ) */

#if defined(CONFIG_CRYSTAL_18_432MHZ)
#define MASTER_CLOCK		(198656000/2)
#define PLL_LOCK_TIMEOUT	1000000
#define PLLA_SETTINGS		0x2060BF09
#define PLLB_SETTINGS		0x10483F0E
#endif /* #if defined(CONFIG_CRYSTAL_18_432MHZ) */
#endif /* #if defined(CONFIG_CPU_CLK_200MHZ) */

#if defined(CONFIG_CPU_CLK_240MHZ)
#if defined(CONFIG_CRYSTAL_16_36766MHZ)
#error "240 MHz not supported for a 16.36766 MHz crystal (Only 200 MHz)"
#endif

#if defined(CONFIG_CRYSTAL_18_432MHZ)
#define MASTER_CLOCK		(240000000/2)
#define PLL_LOCK_TIMEOUT	1000000
#define PLLA_SETTINGS		0x2271BF30
#define PLLB_SETTINGS		0x10483F0E
#endif /* #if defined(CONFIG_CRYSTAL_18_432MHZ) */
#endif /* #if defined(CONFIG_CPU_CLK_240MHZ) */

/* Switch MCK on PLLA output PCK = PLLA = 2 * MCK */
#define MCKR_SETTINGS		(AT91C_PMC_PRES_CLK | AT91C_PMC_MDIV_2)
#define MCKR_CSS_SETTINGS	(AT91C_PMC_CSS_PLLA_CLK | MCKR_SETTINGS)

/*
 * SDRAM Controller
 */
#define AT91C_BASE_SDRAMC	AT91C_BASE_SDRAMC0

/*
* DataFlash Settings
*/
#define CONFIG_SYS_SPI_CLOCK	AT91C_SPI_CLK
#define CONFIG_SYS_SPI_BUS	0
#define CONFIG_SYS_SPI_MODE	SPI_MODE0

#if CONFIG_SYS_SPI_BUS == 0
#define CONFIG_SYS_BASE_SPI	AT91C_BASE_SPI0
#elif CONFIG_SYS_SPI_BUS == 1
#define CONFIG_SYS_BASE_SPI	AT91C_BASE_SPI1
#endif

#if (AT91C_SPI_PCS_DATAFLASH == AT91C_SPI_PCS0_DATAFLASH)
#define CONFIG_SYS_SPI_CS	0
#define CONFIG_SYS_SPI_PCS	AT91C_PIN_PA(5)
#elif (AT91C_SPI_PCS_DATAFLASH == AT91C_SPI_PCS1_DATAFLASH)
#define CONFIG_SYS_SPI_CS	1
#define CONFIG_SYS_SPI_PCS	AT91C_PIN_PA(3)
#endif

/*
 * NandFlash Settings
 */
#define CONFIG_SYS_NAND_BASE		AT91C_BASE_EBI0_CS3
#define CONFIG_SYS_NAND_MASK_ALE	(1 << 21)
#define CONFIG_SYS_NAND_MASK_CLE	(1 << 22)

#define CONFIG_SYS_NAND_ENABLE_PIN	AT91C_PIN_PD(15)
#define CONFIG_SYS_NAND_READY_PIN	AT91C_PIN_PA(22)

/*
 * MCI Settings
 */
#define CONFIG_SYS_BASE_MCI		AT91C_BASE_MCI1

/*
 * Recovery Button
 */
#define CONFIG_SYS_RECOVERY_BUTTON_PIN	AT91C_PIN_PC(4)
#define RECOVERY_BUTTON_NAME	"BP2"

/* export function */
extern void hw_init(void);

extern void nandflash_hw_init(void);
extern void nandflash_config_buswidth(unsigned char busw);
extern unsigned int nandflash_get_ready_pin(void);

extern void at91_spi0_hw_init(void);

extern void at91_mci0_hw_init(void);

#endif /* #ifndef __AT91SAM9263EK_H__ */
