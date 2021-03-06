/*! \file comm.h	
	\brief All the defines for the COMM.c usage.
 *Author: Christoffer Boothby and James Alexander Cowie
 *Comments:
 */

#pragma once

#ifndef COMM_H_
#define COMM_H_
#include <stdint.h>

#define F_CPU (14745600UL) // Physical clock speed

// Defines for ports on the SPI settings
	//PCB 1
#define ADV_CONVERSION_START_1			DDRE2
#define ADC_READ_1						DDRE3 
#define ADC_1_BUSY						DDRC0
	// PCB 2
#define ADV_CONVERSION_START_2			DDRD6
#define ADC_READ_2						DDRD7
#define ADC_2_BUSY						DDRB0

// DAC PORTS:
	//PCB 1
#define CS_DAC_2						DDRC1				
#define LD_DAC_2						DDRC2
	//PCB 2
#define CS_DAC_1						DDRB1
#define LD_DAC_1						DDRB2 


// SPI Defines for LTC1859
// Single-Ended Channel Address 
#define LTC1859_CH0						0b10001000
#define LTC1859_CH1						0b11001000
#define LTC1859_CH2						0b10010100
#define LTC1859_CH3						0b11010100
#define LTC1859_CH4						0b10100100
#define LTC1859_CH5						0b11100100
#define LTC1859_CH6						0b10110100
#define LTC1859_CH7						0b11110100

// Forspenninger p� gridsa
#define GT1 						(uint16_t)0xFFF 
#define MP							(uint16_t)0x666
#define GB1							(uint16_t)0x000

#define GT2							(uint16_t)0x000
#define SP							(uint16_t)0x800
#define GB2							(uint16_t)0xFFF

// DAC8420 ADRESSES for channels
#define DAC_B							0x4
#define DAC_C							0x8
#define DAC_D							0xC

//SPI functions
void spi_init_dac();
void watchdog_enable();
void spi_init_adc();

//ADC functions - LTC1859
void spiTransmitADC_1(uint8_t * dataout, uint8_t datain);
void spiTransmitADC_2(uint8_t * dataout, uint8_t datain);

//DAC functions
void spiTransmitDAC_1(uint8_t dacAdress, uint8_t dacData);
void spiTransmitDAC_2(uint8_t dacAdress, uint8_t dacData);

#endif /* COMM_H_ */