 /**
 ******************************************************************************
 *
 * @file       pios_board.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @brief      Defines board hardware for the OpenPilot Version 1.1 hardware.
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef STM32103CB_PIPXTREME_H_
#define STM32103CB_PIPXTREME_H_

#define ADD_ONE_ADC

//------------------------
// Timers and Channels Used
//------------------------
/*
Timer | Channel 1 | Channel 2 | Channel 3 | Channel 4
------+-----------+-----------+-----------+----------
TIM1  |  Servo 4  |           |           |
TIM2  |  RC In 5  |  RC In 6  |  Servo 6  |
TIM3  |  Servo 5  |  RC In 2  |  RC In 3  |  RC In 4
TIM4  |  RC In 1  |  Servo 3  |  Servo 2  |  Servo 1
------+-----------+-----------+-----------+----------
*/

//------------------------
// DMA Channels Used
//------------------------
/* Channel 1  - 				*/
/* Channel 2  - 				*/
/* Channel 3  - 				*/
/* Channel 4  - 				*/
/* Channel 5  - 				*/
/* Channel 6  - 				*/
/* Channel 7  - 				*/
/* Channel 8  - 				*/
/* Channel 9  - 				*/
/* Channel 10 - 				*/
/* Channel 11 - 				*/
/* Channel 12 - 				*/


//------------------------
// BOOTLOADER_SETTINGS
//------------------------
#define BOARD_READABLE	TRUE
#define BOARD_WRITABLE	TRUE
#define MAX_DEL_RETRYS	3


//------------------------
// WATCHDOG_SETTINGS
//------------------------
#define PIOS_WATCHDOG_TIMEOUT    500
#define PIOS_WDG_REGISTER        BKP_DR4
#define PIOS_WDG_TELEMETRY       0x0001
/*#define PIOS_WDG_RADIORX         0x0002
#define PIOS_WDG_RADIOTX         0x0004
#define PIOS_WDG_RFM22B          0x0008*/

//------------------------
// TELEMETRY
//------------------------
#define TELEM_QUEUE_SIZE         20

//------------------------
// PIOS_LED
//------------------------
#define PIOS_LED_LINK	0

//-------------------------
// System Settings
//-------------------------
#define PIOS_MASTER_CLOCK			72000000
#define PIOS_PERIPHERAL_CLOCK			(PIOS_MASTER_CLOCK / 2)

//-------------------------
// Interrupt Priorities
//-------------------------
#define PIOS_IRQ_PRIO_LOW			12		// lower than RTOS
#define PIOS_IRQ_PRIO_MID			8		// higher than RTOS
#define PIOS_IRQ_PRIO_HIGH			5		// for SPI, ADC, I2C etc...
#define PIOS_IRQ_PRIO_HIGHEST			4 		// for USART etc...

//------------------------
// PIOS_I2C
// See also pios_board.c
//------------------------
#define PIOS_I2C_MAX_DEVS			1
extern uint32_t pios_i2c_flexi_adapter_id;
#define PIOS_I2C_MAIN_ADAPTER			(pios_i2c_flexi_adapter_id)

//------------------------
// PIOS_SPI
// See also pios_board.c
//------------------------
#define PIOS_SPI_MAX_DEVS               1

//-------------------------
// PIOS_USART
//-------------------------
#define PIOS_USART_MAX_DEVS			3

//-------------------------
// PIOS_COM
//
// See also pios_board.c
//-------------------------
#define PIOS_COM_MAX_DEVS			5

extern uint32_t pios_com_telem_usb_id;
extern uint32_t pios_com_telem_vcp_id;
extern uint32_t pios_com_telem_uart_telem_id;
extern uint32_t pios_com_telem_uart_flexi_id;
extern uint32_t pios_com_telemetry_id;
extern uint32_t pios_com_rfm22b_id;
extern uint32_t pios_com_radio_id;
extern uint32_t pios_ppm_rcvr_id;
extern uint32_t pios_ppm_out_id;
#define PIOS_COM_TELEM_USB         (pios_com_telem_usb_id)
#define PIOS_COM_TELEM_VCP         (pios_com_telem_vcp_id)
#define PIOS_COM_TELEM_UART_FLEXI  (pios_com_telem_uart_flexi_id)
#define PIOS_COM_TELEM_UART_TELEM  (pios_com_telem_uart_telem_id)
#define PIOS_COM_TELEMETRY         (pios_com_telemetry_id)
#define PIOS_COM_RFM22B            (pios_com_rfm22b_id)
#define PIOS_COM_RADIO             (pios_com_radio_id)
#define PIOS_PPM_RECEIVER          (pios_ppm_rcvr_id)
#define PIOS_PPM_OUTPUT            (pios_ppm_out_id)

#define RFM22_DEBUG 1

//-------------------------
// ADC
// None
//-------------------------
//#define PIOS_ADC_OVERSAMPLING_RATE		1
#define PIOS_ADC_USE_TEMP_SENSOR		1
#define PIOS_ADC_TEMP_SENSOR_ADC		ADC1
#define PIOS_ADC_TEMP_SENSOR_ADC_CHANNEL	1

#define PIOS_ADC_PIN1_GPIO_PORT			GPIOB			// PB0
#define PIOS_ADC_PIN1_GPIO_PIN			GPIO_Pin_0		// ADC12_IN8
#define PIOS_ADC_PIN1_GPIO_CHANNEL		ADC_Channel_8
#define PIOS_ADC_PIN1_ADC			ADC2
#define PIOS_ADC_PIN1_ADC_NUMBER		1

#define PIOS_ADC_PIN2_GPIO_PORT			GPIOB			// PB1
#define PIOS_ADC_PIN2_GPIO_PIN			GPIO_Pin_1		// ADC12_IN9
#define PIOS_ADC_PIN2_GPIO_CHANNEL		ADC_Channel_5
#define PIOS_ADC_PIN2_ADC			ADC1
#define PIOS_ADC_PIN2_ADC_NUMBER		2

#define PIOS_ADC_NUM_PINS			2

#define PIOS_ADC_PORTS				{PIOS_ADC_PIN1_GPIO_PORT, PIOS_ADC_PIN2_GPIO_PORT}
#define PIOS_ADC_PINS				{PIOS_ADC_PIN1_GPIO_PIN, PIOS_ADC_PIN2_GPIO_PIN}
#define PIOS_ADC_CHANNELS			{PIOS_ADC_PIN1_GPIO_CHANNEL, PIOS_ADC_PIN2_GPIO_CHANNEL}
#define PIOS_ADC_MAPPING			{PIOS_ADC_PIN1_ADC, PIOS_ADC_PIN2_ADC}
#define PIOS_ADC_CHANNEL_MAPPING		{PIOS_ADC_PIN1_ADC_NUMBER, PIOS_ADC_PIN2_ADC_NUMBER}
#define PIOS_ADC_NUM_CHANNELS			(PIOS_ADC_NUM_PINS + PIOS_ADC_USE_TEMP_SENSOR)
#define PIOS_ADC_NUM_ADC_CHANNELS		2
#define PIOS_ADC_USE_ADC2			1
#define PIOS_ADC_CLOCK_FUNCTION			RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_ADC2, ENABLE)
#define PIOS_ADC_ADCCLK				RCC_PCLK2_Div8
/* RCC_PCLK2_Div2: ADC clock = PCLK2/2 */
/* RCC_PCLK2_Div4: ADC clock = PCLK2/4 */
/* RCC_PCLK2_Div6: ADC clock = PCLK2/6 */
/* RCC_PCLK2_Div8: ADC clock = PCLK2/8 */
#define PIOS_ADC_SAMPLE_TIME			ADC_SampleTime_239Cycles5
/* Sample time: */
/* With an ADCCLK = 14 MHz and a sampling time of 239.5 cycles: */
/* Tconv = 239.5 + 12.5 = 252 cycles = 18�s */
/* (1 / (ADCCLK / CYCLES)) = Sample Time (�S) */
#define PIOS_ADC_IRQ_PRIO			PIOS_IRQ_PRIO_LOW

// Currently analog acquistion hard coded at 480 Hz
// PCKL2 = HCLK / 16
// ADCCLK = PCLK2 / 2
#define PIOS_ADC_RATE		(72.0e6 / 1.0 / 8.0 / 252.0 / (PIOS_ADC_NUM_CHANNELS >> PIOS_ADC_USE_ADC2))
#define PIOS_ADC_MAX_OVERSAMPLING               36

//------------------------
// PIOS_RCVR
// See also pios_board.c
//------------------------
#define PIOS_RCVR_MAX_DEVS          3
#define PIOS_RCVR_MAX_CHANNELS      12
#define PIOS_GCSRCVR_TIMEOUT_MS     100

//-------------------------
// Receiver PPM input
//-------------------------
#define PIOS_PPM_MAX_DEVS     1
#define PIOS_PPM_NUM_INPUTS   8

//-------------------------
// Servo outputs
//-------------------------
#define PIOS_SERVO_UPDATE_HZ                    50
#define PIOS_SERVOS_INITIAL_POSITION            0 /* dont want to start motors, have no pulse till settings loaded */

//--------------------------
// Timer controller settings
//--------------------------
#define PIOS_TIM_MAX_DEVS			3

//-------------------------
// GPIO
//-------------------------
#define PIOS_GPIO_PORTS				{ }
#define PIOS_GPIO_PINS				{ }
#define PIOS_GPIO_CLKS				{ }
#define PIOS_GPIO_NUM				0

//-------------------------
// USB
//-------------------------
#define PIOS_USB_HID_MAX_DEVS                   1
#define PIOS_USB_ENABLED                        1
#define PIOS_USB_HID_MAX_DEVS                   1
#define PIOS_USB_MAX_DEVS                       1
#define PIOS_USB_DETECT_GPIO_PORT               GPIOC
#define PIOS_USB_DETECT_GPIO_PIN                GPIO_Pin_15
#define PIOS_USB_DETECT_EXTI_LINE               EXTI_Line15

//-------------------------
// RFM22
//-------------------------

#if defined(PIOS_INCLUDE_RFM22B)
extern uint32_t pios_spi_rfm22b_id;
#define PIOS_RFM22_SPI_PORT             (pios_spi_rfm22b_id)
extern uint32_t pios_rfm22b_id;
#endif /* PIOS_INCLUDE_RFM22B */

//-------------------------
// Packet Handler
//-------------------------
extern uint32_t pios_packet_handler;
#define PIOS_PACKET_HANDLER (pios_packet_handler)
#define PIOS_PH_MAX_PACKET 255
#define PIOS_PH_WIN_SIZE 3
#define PIOS_PH_MAX_CONNECTIONS 1
#define RS_ECC_NPARITY 4

//-------------------------
// Reed-Solomon ECC
//-------------------------

#define RS_ECC_NPARITY 4

//-------------------------
// Flash EEPROM Emulation
//-------------------------

#define PIOS_FLASH_SIZE 0x20000
#define PIOS_FLASH_EEPROM_START_ADDR 0x08000000
#define PIOS_FLASH_PAGE_SIZE 1024
#define PIOS_FLASH_EEPROM_ADDR (PIOS_FLASH_EEPROM_START_ADDR + PIOS_FLASH_SIZE - PIOS_FLASH_PAGE_SIZE)
#define PIOS_FLASH_EEPROM_LEN PIOS_FLASH_PAGE_SIZE

#endif /* STM32103CB_PIPXTREME_H_ */