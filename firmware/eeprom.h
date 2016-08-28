// Copyright 2015 Mike Tsao
//
// WebLight firmware
// https://github.com/sowbug/weblight

#if !defined(__EEPROM_H__)
#define __EEPROM_H_

#include <avr/io.h>

// Memory map
//
//     0-3: Signature ('WebL')
//     4-5: Version (BCD, 1.0 = 0x0100)
//    6-21: Serial number (16-digit string)
//      22: NEXT_ITEM (was LED count) (uint8_t)

//     255: size of saved program
// 22-    : saved program

#define EEPROM_SIG 'WebL'
#define EEPROM_SIG_START (0)
#define EEPROM_SIG_LENGTH (4)

#define EEPROM_VERSION_START (4)
#define EEPROM_VERSION_LENGTH (2)

#define EEPROM_SERIAL_START (6)
#define EEPROM_SERIAL_LENGTH (16)

#define EEPROM_WEBUSB_URLS_START (128)

#define EEPROM_PROGRAM_SIZE (22)
#define EEPROM_PROGRAM_START (EEPROM_PROGRAM_SIZE + 1)
#define EEPROM_PROGRAM_MAX_SIZE (EEPROM_WEBUSB_URLS_START - \
                                 EEPROM_PROGRAM_START)

void ReadEEPROM();

uint8_t ReadLightProgram(uint8_t *opcode_buf, uint8_t opcode_buf_len);
void WriteLightProgram(const uint8_t *opcode_buf, uint8_t opcode_buf_len);

#endif  // #if !defined(__EEPROM_H__)
