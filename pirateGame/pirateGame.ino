#define CHIP_SELECT 10

#include <SdFat.h>

#include <SPI.h>
#include <Gamebuino.h>
Gamebuino gb;

SdFat sd;
File myFile;


const byte SpritesP1[] PROGMEM = {160,71,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0xC2,0x0,0x0,0x0,0x0,0xF0,0x0,0x0,0xC,0x20,0x0,0x0,0x0,0x0,0x0,0x0,0xC2,0x0,0x0,0x1,0x89,0x0,0x0,0x0,0x3,0x8,0x0,0x0,0x18,0x90,0x0,0x0,0x0,0x0,0x0,0x1,0x89,0x0,0x0,0x7,0x9D,0x0,0x0,0x0,0x6,0x24,0x1C,0x0,0x79,0xD0,0x0,0x0,0x0,0x0,0x0,0x7,0x9D,0x0,0x0,0x1F,0x9D,0x80,0x0,0x0,0x1E,0x74,0x12,0x1,0xF9,0xD8,0x0,0x0,0x0,0x0,0x0,0x1F,0x9D,0x80,0x0,0x22,0x8,0x40,0x0,0x0,0x7E,0x76,0xA,0x2,0x20,0x84,0x0,0x0,0x0,0x0,0x0,0x22,0x8,0x40,0x0,0x22,0x0,0x40,0x0,0x0,0x88,0x21,0x9,0x2,0x20,0x4,0x0,0x0,0x0,0x0,0x0,0x22,0x0,0x40,0x0,0x3F,0xFF,0x80,0x0,0x0,0x88,0x1,0x9,0x3,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0x80,0x0,0x1F,0xC7,0x0,0x0,0x0,0xFF,0xFE,0x9,0x0,0xFC,0x70,0x0,0x0,0x0,0x0,0x0,0x1F,0xC7,0x0,0xC0,0x7F,0xB7,0x80,0x0,0x0,0x7F,0x1C,0x9,0x0,0xFB,0x78,0x0,0x0,0x0,0x0,0x0,0x7F,0xB7,0x80,0xA0,0x3C,0x80,0x40,0x60,0x3,0xFE,0xDE,0x11,0x3,0xC8,0x4,0x0,0x0,0x0,0x0,0x0,0x3C,0x80,0x40,0xA0,0xFC,0x88,0x40,0x50,0x3,0xF2,0x1,0x11,0x7,0xC8,0x84,0x0,0x0,0x0,0x0,0x0,0xFC,0x88,0x41,0x20,0xE7,0xCF,0x80,0x50,0x1,0xF2,0x21,0x11,0x3,0xFC,0xF8,0x0,0x0,0x0,0x0,0x7,0x7,0xCF,0x81,0x20,0x41,0xDF,0x80,0x90,0x1E,0x1F,0x3E,0x12,0xF,0xFD,0xF8,0x0,0x0,0x0,0x0,0x8,0xC1,0xDF,0x82,0x23,0x80,0xF9,0xC0,0x90,0x21,0x7,0x7E,0x7E,0x2,0x7F,0x9C,0x0,0x0,0x0,0x0,0xC,0x38,0xF9,0xC4,0x44,0x6C,0xFF,0xC1,0x10,0x20,0xC3,0xE7,0xB2,0x4,0x7F,0xFC,0x0,0x0,0x0,0x0,0x10,0x30,0xFF,0xC8,0x46,0x18,0xFF,0xC2,0x20,0x3C,0xF3,0xFF,0x32,0x4,0x3F,0xFC,0x0,0x0,0x0,0x0,0x1F,0x60,0x7F,0xD0,0x84,0x10,0x7F,0xC4,0x20,0x47,0x63,0xFF,0x32,0x4,0xCF,0xFC,0x0,0x0,0x0,0x0,0x11,0xA0,0x3F,0xF1,0x5,0xF0,0x3F,0xC8,0x40,0x4A,0x41,0xFF,0x24,0x3,0x85,0xFC,0x0,0x0,0x0,0x0,0x12,0xBF,0xC7,0xEE,0x2,0x3F,0xE3,0xB8,0x80,0x3C,0x40,0xFF,0x38,0x3,0x8,0x88,0x0,0x0,0x0,0x0,0xF,0x20,0xC5,0xE4,0x2,0x58,0x62,0xB7,0x0,0x0,0x7F,0x8E,0xC0,0x3,0x49,0x88,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xC4,0x1,0xFF,0xFF,0xF2,0x0,0x0,0xC1,0x8A,0x0,0x3,0x7F,0xFC,0x18,0x0,0x0,0x0,0x0,0x7F,0xFE,0x88,0x0,0x3F,0xFF,0x62,0x0,0x3,0xFF,0xFF,0x80,0x1,0x7F,0xF3,0xE8,0x0,0x0,0x0,0x0,0x7C,0x3C,0xF0,0x0,0x3E,0x1E,0x44,0x0,0x4,0xFF,0xFF,0x40,0x0,0x7F,0xE0,0x8,0x0,0x0,0x0,0x0,0x88,0x42,0x0,0x0,0x44,0x21,0x78,0x0,0x6,0x78,0x1F,0x28,0x0,0x42,0x70,0x30,0x0,0x0,0x0,0x0,0xF8,0x62,0x0,0x0,0x7C,0x31,0x0,0x0,0x19,0x40,0x6,0x38,0x0,0x63,0xCF,0xC0,0x0,0x0,0x0,0x0,0xA0,0x3C,0x0,0x0,0x50,0x1E,0x0,0x0,0x7,0x80,0x2,0xF0,0x0,0x7E,0x80,0x0,0x0,0x0,0x0,0x1,0x40,0x3E,0x0,0x0,0xA0,0x1F,0x0,0x0,0x18,0x0,0x3,0xC0,0x0,0x6E,0x80,0x0,0x0,0x0,0x0,0x1,0x40,0x37,0x0,0x0,0xA0,0x1B,0x80,0x0,0x0,0x0,0x0,0xC0,0x0,0xE,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF0,0x0,0x0,0x8,0x30,0x0,0x0,0xF8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0x8,0x0,0x0,0xE,0x8,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x6,0x24,0x0,0x0,0x1,0x84,0x0,0x1,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1E,0x74,0x0,0x0,0x0,0x42,0x0,0x0,0x30,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7E,0x76,0x1,0x80,0x0,0x23,0x80,0x0,0x8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x88,0x21,0x1,0x40,0x0,0x12,0x40,0x0,0x4,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x88,0x1,0x1,0x40,0x0,0x7C,0x20,0x0,0x2,0x40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xFE,0x2,0x40,0x1,0x87,0x20,0x0,0xF,0x80,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0x1C,0x2,0x40,0x3,0x13,0xA0,0x0,0x30,0xE0,0x0,0x0,0x0,0xC2,0x0,0x0,0x0,0x0,0x0,0x1,0xFE,0xDE,0x4,0x40,0xF,0x3B,0xE0,0x0,0x62,0x74,0x0,0x0,0x1,0x89,0x0,0x0,0x0,0x0,0x0,0x0,0xF2,0x1,0x8,0x80,0x3F,0x3B,0xC0,0x1,0xE7,0x7C,0x0,0x0,0x7,0x9D,0x0,0x0,0x0,0x0,0x0,0x3,0xF2,0x21,0x10,0x80,0x44,0x10,0xA0,0x7,0xE7,0x78,0x0,0x0,0x1F,0x9D,0x80,0x0,0x0,0x0,0x0,0x1C,0x1F,0x3E,0x21,0x0,0x44,0x0,0xA0,0x8,0x82,0x14,0x0,0x0,0x22,0x8,0x40,0x0,0x0,0x0,0x0,0x23,0x7,0x7E,0xE2,0x0,0x7F,0xFF,0x20,0x8,0x80,0x14,0x0,0x0,0x22,0x0,0x40,0x0,0x0,0x0,0x0,0x30,0xE3,0xE7,0x5C,0x0,0x3F,0x8E,0xC0,0xF,0xFF,0xE4,0x0,0x0,0x3F,0xFF,0x80,0x0,0x0,0x0,0x0,0x40,0xC3,0xFF,0xC8,0x0,0xFF,0x6F,0x0,0x7,0xF1,0xD8,0x0,0x0,0x1F,0xC7,0x0,0x0,0x0,0x0,0x0,0x7D,0x81,0xFF,0x88,0x0,0x79,0x0,0x80,0x1F,0xED,0xE0,0x0,0x0,0x7F,0xB7,0x80,0x0,0x0,0x0,0x0,0x46,0x80,0xFF,0x10,0x1,0xF9,0x10,0x80,0xF,0x20,0x10,0x0,0x0,0x3C,0x80,0x40,0x0,0x0,0x0,0x0,0x4A,0xFF,0x1F,0xE0,0x1,0xCF,0x9F,0x0,0x3F,0x22,0x10,0x0,0x0,0xFC,0x88,0x40,0x0,0x0,0x0,0x0,0x3C,0x83,0x14,0x0,0x0,0x83,0xBF,0x0,0x39,0xF3,0xE0,0x0,0x7,0x7,0xCF,0xE7,0x80,0x0,0x0,0x0,0x0,0xFF,0xFF,0x0,0x7,0x1,0xF3,0x80,0x10,0x77,0xE0,0x0,0x8,0xC1,0xDF,0x98,0x40,0x0,0x0,0x0,0x1,0xFF,0xFE,0x80,0x8,0xD9,0xFF,0x80,0xE0,0x3E,0x70,0x0,0xC,0x38,0xF9,0xC9,0xC0,0x0,0x0,0x0,0x1,0xF0,0x3E,0x50,0xC,0x31,0xFF,0x81,0x1B,0x3F,0xF0,0x0,0x10,0x30,0xFF,0xCB,0x20,0x0,0x2,0x0,0x2,0x20,0xC,0x70,0x8,0x20,0xFF,0x81,0x86,0x3F,0xF0,0x0,0x1F,0x60,0x7F,0xFF,0x9E,0x0,0xC,0x0,0x3,0xE0,0x5,0xE0,0xB,0xE0,0x7F,0x81,0x4,0x1F,0xF0,0x0,0x11,0xA0,0x3F,0xC6,0xF8,0x0,0x70,0x0,0x2,0x80,0x7,0x80,0x4,0x7F,0xC7,0x1,0x7C,0xF,0xF0,0x0,0x12,0xBF,0xC7,0x82,0x8,0xF,0x80,0x0,0x5,0x0,0x1,0x80,0x4,0xB0,0xC5,0x0,0x8F,0xF8,0xE0,0x0,0xF,0x20,0x45,0x1,0xF,0xF0,0x0,0x0,0x5,0x0,0x0,0x0,0x3,0xFF,0xFF,0x0,0x96,0x18,0xA0,0x0,0x0,0x7F,0xFE,0x1,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0xFE,0x0,0x7F,0xFF,0xE0,0x0,0x0,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7C,0x3C,0x0,0xF,0xFF,0xC0,0x0,0x0,0xF8,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x88,0x42,0x0,0xF,0x87,0x80,0x0,0x1,0x10,0x42,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF8,0x62,0x0,0x11,0x8,0x40,0x0,0x1,0xF0,0x62,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xA0,0x3C,0x0,0x1F,0xC,0x40,0x0,0x1,0x40,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x40,0x3E,0x0,0x14,0x7,0x80,0x0,0x2,0x80,0x7C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x40,0x37,0x0,0x28,0x7,0xC0,0x0,0x2,0x80,0x6E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x28,0x6,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,};
const byte SpritesP1Mask[] PROGMEM = {160,71,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0xFE,0x0,0x0,0x0,0x0,0xF0,0x0,0x0,0xF,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0xFE,0x0,0x0,0x1,0xFF,0x0,0x0,0x0,0x3,0xF8,0x0,0x0,0x1F,0xF0,0x0,0x0,0x0,0x0,0x0,0x1,0xFF,0x0,0x0,0x7,0xFF,0x0,0x0,0x0,0x7,0xFC,0x1C,0x0,0x7F,0xF0,0x0,0x0,0x0,0x0,0x0,0x7,0xFF,0x0,0x0,0x1F,0xFF,0x80,0x0,0x0,0x1F,0xFC,0x1E,0x1,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x1F,0xFF,0x80,0x0,0x3F,0xFF,0xC0,0x0,0x0,0x7F,0xFE,0xE,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xFF,0xC0,0x0,0x0,0xFF,0xFF,0xF,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xFF,0x80,0x0,0x0,0xFF,0xFF,0xF,0x3,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0x80,0x0,0x1F,0xFF,0x0,0x0,0x0,0xFF,0xFE,0xF,0x0,0xFF,0xF0,0x0,0x0,0x0,0x0,0x0,0x1F,0xFF,0x0,0xC0,0x7F,0xFF,0x80,0x0,0x0,0x7F,0xFC,0xF,0x0,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x7F,0xFF,0x80,0xE0,0x3F,0xFF,0xC0,0x60,0x3,0xFF,0xFE,0x1F,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xC0,0xE0,0xFF,0xFF,0xC0,0x70,0x3,0xFF,0xFF,0x1F,0x7,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0xFF,0xFF,0xC1,0xE0,0xFF,0xFF,0x80,0x70,0x1,0xFF,0xFF,0x1F,0x3,0xFF,0xF8,0x0,0x0,0x0,0x0,0x7,0xFF,0xFF,0x81,0xE0,0x7F,0xFF,0x80,0xF0,0x1F,0xFF,0xFE,0x1E,0xF,0xFF,0xF8,0x0,0x0,0x0,0x0,0xF,0xFF,0xFF,0x83,0xE3,0xFF,0xFF,0xC0,0xF0,0x3F,0xFF,0xFE,0x7E,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0xF,0xFF,0xFF,0xC7,0xC7,0xFF,0xFF,0xC1,0xF0,0x3F,0xFF,0xFF,0xFE,0x7,0xFF,0xFC,0x0,0x0,0x0,0x0,0x1F,0xFF,0xFF,0xCF,0xC7,0xFF,0xFF,0xC3,0xE0,0x3F,0xFF,0xFF,0xFE,0x7,0xFF,0xFC,0x0,0x0,0x0,0x0,0x1F,0xFF,0xFF,0xDF,0x87,0xFF,0xFF,0xC7,0xE0,0x7F,0x7F,0xFF,0xFE,0x7,0xFF,0xFC,0x0,0x0,0x0,0x0,0x1F,0xBF,0xFF,0xFF,0x7,0xFF,0xFF,0xCF,0xC0,0x7E,0x7F,0xFF,0xFC,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0x1F,0xBF,0xFF,0xFE,0x3,0xFF,0xFF,0xFF,0x80,0x3C,0x7F,0xFF,0xF8,0x3,0xFF,0xF8,0x0,0x0,0x0,0x0,0xF,0x3F,0xFF,0xFC,0x3,0xFF,0xFF,0xFF,0x0,0x0,0x7F,0xFE,0xC0,0x3,0x7F,0xF8,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xFC,0x1,0xFF,0xFF,0xFE,0x0,0x0,0xFF,0xFE,0x0,0x3,0x7F,0xFC,0x18,0x0,0x0,0x0,0x0,0x7F,0xFE,0xF8,0x0,0x3F,0xFF,0x7E,0x0,0x3,0xFF,0xFF,0x80,0x1,0x7F,0xFF,0xF8,0x0,0x0,0x0,0x0,0x7C,0x3C,0xF0,0x0,0x3E,0x1E,0x7C,0x0,0x7,0xFF,0xFF,0xC0,0x0,0x7F,0xFF,0xF8,0x0,0x0,0x0,0x0,0xF8,0x7E,0x0,0x0,0x7C,0x3F,0x78,0x0,0x7,0xF8,0x1F,0xE8,0x0,0x7F,0xFF,0xF0,0x0,0x0,0x0,0x0,0xF8,0x7E,0x0,0x0,0x7C,0x3F,0x0,0x0,0x1F,0xC0,0x7,0xF8,0x0,0x7F,0xCF,0xC0,0x0,0x0,0x0,0x0,0xE0,0x3C,0x0,0x0,0x70,0x1E,0x0,0x0,0x1F,0x80,0x3,0xF0,0x0,0x7F,0x80,0x0,0x0,0x0,0x0,0x1,0xC0,0x3E,0x0,0x0,0xE0,0x1F,0x0,0x0,0x18,0x0,0x3,0xC0,0x0,0x6F,0x80,0x0,0x0,0x0,0x0,0x1,0xC0,0x37,0x0,0x0,0xE0,0x1B,0x80,0x0,0x0,0x0,0x0,0xC0,0x0,0xF,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF0,0x0,0x0,0xF,0xF0,0x0,0x0,0xF8,0x0,0x0,0x0,0x0,0x0,0x1,0xE0,0x0,0x0,0x0,0x0,0x3,0xF8,0x0,0x0,0xF,0xF8,0x0,0x1,0xFE,0x0,0x0,0x0,0x0,0x0,0x0,0x1F,0x0,0x0,0x0,0x0,0x7,0xFC,0x0,0x0,0x1,0xFC,0x0,0x1,0xFF,0xC0,0x0,0x0,0x0,0x0,0x0,0x1F,0x0,0x0,0x0,0x0,0x1F,0xFC,0x0,0x0,0x0,0x7E,0x0,0x0,0x3F,0xF0,0x0,0x0,0x0,0x0,0x0,0x7,0xC0,0x0,0x0,0x0,0x7F,0xFE,0x1,0x80,0x0,0x3F,0x80,0x0,0xF,0xF8,0x0,0x0,0x0,0x0,0x0,0x1,0xF0,0x0,0x0,0x0,0xFF,0xFF,0x1,0xC0,0x0,0x1F,0xC0,0x0,0x7,0xFE,0x0,0x0,0x0,0x0,0x0,0x1,0xFC,0x0,0x0,0x0,0xFF,0xFF,0x1,0xC0,0x0,0x7F,0xE0,0x0,0x3,0xFF,0x0,0x0,0x0,0x0,0x0,0x1,0xFE,0x0,0x0,0x0,0xFF,0xFE,0x3,0xC0,0x1,0xFF,0xE0,0x0,0xF,0xFF,0x80,0x0,0x0,0x3C,0x0,0x0,0x7F,0x0,0x0,0x0,0x7F,0xFC,0x3,0xC0,0x3,0xFF,0xE0,0x0,0x3F,0xFF,0xC0,0x0,0x0,0xFE,0x0,0x0,0x7F,0x80,0x0,0x1,0xFF,0xFE,0x7,0xC0,0xF,0xFF,0xE0,0x0,0x7F,0xFF,0xE0,0x0,0x1,0xFF,0x0,0x0,0x7F,0xC0,0x0,0x0,0xFF,0xFF,0xF,0x80,0x3F,0xFF,0xC0,0x1,0xFF,0xFD,0xE0,0x0,0x7,0xFF,0x0,0x0,0x7F,0xE0,0x0,0x3,0xFF,0xFF,0x1F,0x80,0x7F,0xFF,0xE0,0x7,0xFF,0xF8,0xF0,0x0,0x1F,0xFF,0x80,0x0,0x7F,0xE0,0x0,0x1F,0xFF,0xFE,0x3F,0x0,0x7F,0xFF,0xE0,0xF,0xFF,0xFC,0x70,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xF0,0x0,0x3F,0xFF,0xFE,0xFE,0x0,0x7F,0xFF,0xE0,0xF,0xFF,0xFC,0x38,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xF0,0x0,0x3F,0xFF,0xFF,0xFC,0x0,0x3F,0xFF,0xC0,0xF,0xFF,0xFC,0x18,0x0,0x3F,0xFF,0x80,0x0,0x3F,0xF8,0x0,0x7F,0xFF,0xFF,0xF8,0x0,0xFF,0xFF,0x0,0x7,0xFF,0xF8,0x10,0x0,0x1F,0xFF,0x0,0x0,0x3F,0xF8,0x0,0x7F,0xFF,0xFF,0xF8,0x0,0x7F,0xFF,0x80,0x1F,0xFF,0xE0,0x0,0x0,0x7F,0xFF,0x80,0x0,0x3F,0xFC,0x0,0x7E,0xFF,0xFF,0xF0,0x1,0xFF,0xFF,0x80,0xF,0xFF,0xF0,0x0,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xFC,0x0,0x7E,0xFF,0xFF,0xE0,0x1,0xFF,0xFF,0x0,0x3F,0xFF,0xF0,0x0,0x0,0xFF,0xFF,0xC0,0x0,0x7F,0xFC,0x0,0x3C,0xFF,0xFC,0x0,0x0,0xFF,0xFF,0x0,0x3F,0xFF,0xE0,0x0,0x7,0xFF,0xFF,0xE7,0x80,0x7F,0xFE,0x0,0x0,0xFF,0xFF,0x0,0x7,0xFF,0xFF,0x80,0x1F,0xFF,0xE0,0x0,0xF,0xFF,0xFF,0xFF,0xC0,0x7F,0xFE,0x0,0x1,0xFF,0xFF,0x80,0xF,0xFF,0xFF,0x80,0xFF,0xFF,0xF0,0x0,0xF,0xFF,0xFF,0xFF,0xC0,0x7F,0xFE,0x0,0x1,0xF0,0x3F,0xD0,0xF,0xFF,0xFF,0x81,0xFF,0xFF,0xF0,0x0,0x1F,0xFF,0xFF,0xFF,0xE0,0xFF,0xFE,0x0,0x3,0xE0,0xF,0xF0,0xF,0xFF,0xFF,0x81,0xFF,0xFF,0xF0,0x0,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x0,0x3,0xE0,0x7,0xE0,0xF,0xFF,0xFF,0x81,0xFF,0xFF,0xF0,0x0,0x1F,0xBF,0xFF,0xC7,0xFF,0xFF,0xF0,0x0,0x3,0x80,0x7,0x80,0x7,0xFF,0xFF,0x1,0xFF,0xFF,0xF0,0x0,0x1F,0xBF,0xFF,0x83,0xFF,0xFF,0x80,0x0,0x7,0x0,0x1,0x80,0x7,0xFF,0xFF,0x0,0xFF,0xFF,0xE0,0x0,0xF,0x3F,0xFF,0x1,0xFF,0xF0,0x0,0x0,0x7,0x0,0x0,0x0,0x3,0xFF,0xFF,0x0,0xFF,0xFF,0xE0,0x0,0x0,0x7F,0xFE,0x1,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0xFE,0x0,0x7F,0xFF,0xE0,0x0,0x0,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7C,0x3C,0x0,0xF,0xFF,0xC0,0x0,0x0,0xF8,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF8,0x7E,0x0,0xF,0x87,0x80,0x0,0x1,0xF0,0x7E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF8,0x7E,0x0,0x1F,0xF,0xC0,0x0,0x1,0xF0,0x7E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xE0,0x3C,0x0,0x1F,0xF,0xC0,0x0,0x1,0xC0,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xC0,0x3E,0x0,0x1C,0x7,0x80,0x0,0x3,0x80,0x7C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xC0,0x37,0x0,0x38,0x7,0xC0,0x0,0x3,0x80,0x6E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x38,0x6,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,};

const byte SpritesP2[] PROGMEM = {160,71,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0xC2,0x0,0x0,0x0,0x0,0xF0,0x0,0x0,0xC,0x20,0x0,0x0,0x0,0x0,0x0,0x0,0xC2,0x0,0x0,0x1,0x89,0x0,0x0,0x0,0x3,0x8,0x0,0x0,0x18,0x90,0x0,0x0,0x0,0x0,0x0,0x1,0x89,0x0,0x0,0x7,0x9D,0x0,0x0,0x0,0x6,0x24,0x1C,0x0,0x79,0xD0,0x0,0x0,0x0,0x0,0x0,0x7,0x9D,0x0,0x0,0x1F,0x9D,0x80,0x0,0x0,0x1E,0x74,0x12,0x1,0xF9,0xD8,0x0,0x0,0x0,0x0,0x0,0x1F,0x9D,0x80,0x0,0x22,0x8,0x40,0x0,0x0,0x7E,0x76,0xA,0x2,0x20,0x84,0x0,0x0,0x0,0x0,0x0,0x22,0x8,0x40,0x0,0x22,0x0,0x40,0x0,0x0,0x88,0x21,0x9,0x2,0x20,0x4,0x0,0x0,0x0,0x0,0x0,0x22,0x0,0x40,0x0,0x3F,0xFF,0x80,0x0,0x0,0x88,0x1,0x9,0x3,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0x80,0x0,0x1F,0xC7,0x0,0x0,0x0,0xFF,0xFE,0x9,0x0,0xFC,0x70,0x0,0x0,0x0,0x0,0x0,0x1F,0xC7,0x0,0xC0,0x7F,0xB7,0x80,0x0,0x0,0x7F,0x1C,0x9,0x0,0xFB,0x78,0x0,0x0,0x0,0x0,0x0,0x7F,0xB7,0x80,0xA0,0x3C,0x80,0x40,0x60,0x3,0xFE,0xDE,0x11,0x3,0xC8,0x4,0x0,0x0,0x0,0x0,0x0,0x3C,0x80,0x40,0xA0,0xFC,0x88,0x40,0x50,0x3,0xF2,0x1,0x11,0x7,0xC8,0x84,0x0,0x0,0x0,0x0,0x0,0xFC,0x88,0x41,0x20,0xE7,0xCF,0x80,0x50,0x1,0xF2,0x21,0x11,0x3,0xFC,0xF8,0x0,0x0,0x0,0x0,0x7,0x7,0xCF,0x81,0x20,0x41,0xDF,0x80,0x90,0x1E,0x1F,0x3E,0x12,0xF,0xFD,0xF8,0x0,0x0,0x0,0x0,0x8,0xC1,0xDF,0x82,0x23,0x80,0xF9,0xC0,0x90,0x21,0x7,0x7E,0x7E,0x2,0x7F,0x9C,0x0,0x0,0x0,0x0,0xC,0x38,0xF9,0xC4,0x44,0x6C,0xFF,0xC1,0x10,0x20,0xC3,0xE7,0xB2,0x4,0x7F,0xFC,0x0,0x0,0x0,0x0,0x10,0x30,0xFF,0xC8,0x46,0x18,0xFF,0xC2,0x20,0x3C,0xF3,0xFF,0x32,0x4,0x3F,0xFC,0x0,0x0,0x0,0x0,0x1F,0x60,0x7F,0xD0,0x84,0x10,0x7F,0xC4,0x20,0x47,0x63,0xFF,0x32,0x4,0xCF,0xFC,0x0,0x0,0x0,0x0,0x11,0xA0,0x3F,0xF1,0x5,0xF0,0x3F,0xC8,0x40,0x4A,0x41,0xFF,0x24,0x3,0x85,0xFC,0x0,0x0,0x0,0x0,0x12,0xBF,0xC7,0xEE,0x2,0x3F,0xE3,0xB8,0x80,0x3C,0x40,0xFF,0x38,0x3,0x8,0x88,0x0,0x0,0x0,0x0,0xF,0x20,0xC5,0xE4,0x2,0x58,0x62,0xB7,0x0,0x0,0x7F,0x8E,0xC0,0x3,0x49,0x88,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xC4,0x1,0xFF,0xFF,0xF2,0x0,0x0,0xC1,0x8A,0x0,0x3,0x7F,0xFC,0x18,0x0,0x0,0x0,0x0,0x7F,0xFE,0x88,0x0,0x3F,0xFF,0x62,0x0,0x3,0xFF,0xFF,0x80,0x1,0x7F,0xF3,0xE8,0x0,0x0,0x0,0x0,0x7C,0x3C,0xF0,0x0,0x3E,0x1E,0x44,0x0,0x4,0xFF,0xFF,0x40,0x0,0x7F,0xE0,0x8,0x0,0x0,0x0,0x0,0x88,0x42,0x0,0x0,0x44,0x21,0x78,0x0,0x6,0x78,0x1F,0x28,0x0,0x42,0x70,0x30,0x0,0x0,0x0,0x0,0xF8,0x62,0x0,0x0,0x7C,0x31,0x0,0x0,0x19,0x40,0x6,0x38,0x0,0x63,0xCF,0xC0,0x0,0x0,0x0,0x0,0xA0,0x3C,0x0,0x0,0x50,0x1E,0x0,0x0,0x7,0x80,0x2,0xF0,0x0,0x7E,0x80,0x0,0x0,0x0,0x0,0x1,0x40,0x3E,0x0,0x0,0xA0,0x1F,0x0,0x0,0x18,0x0,0x3,0xC0,0x0,0x6E,0x80,0x0,0x0,0x0,0x0,0x1,0x40,0x37,0x0,0x0,0xA0,0x1B,0x80,0x0,0x0,0x0,0x0,0xC0,0x0,0xE,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF0,0x0,0x0,0x8,0x30,0x0,0x0,0xF8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0x8,0x0,0x0,0xE,0x8,0x0,0x1,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x6,0x24,0x0,0x0,0x1,0x84,0x0,0x1,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1E,0x74,0x0,0x0,0x0,0x42,0x0,0x0,0x30,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7E,0x76,0x1,0x80,0x0,0x23,0x80,0x0,0x8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x88,0x21,0x1,0x40,0x0,0x12,0x40,0x0,0x4,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x88,0x1,0x1,0x40,0x0,0x7C,0x20,0x0,0x2,0x40,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xFF,0xFE,0x2,0x40,0x1,0x87,0x20,0x0,0xF,0x80,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0x1C,0x2,0x40,0x3,0x13,0xA0,0x0,0x30,0xE0,0x0,0x0,0x0,0xC2,0x0,0x0,0x0,0x0,0x0,0x1,0xFE,0xDE,0x4,0x40,0xF,0x3B,0xE0,0x0,0x62,0x74,0x0,0x0,0x1,0x89,0x0,0x0,0x0,0x0,0x0,0x0,0xF2,0x1,0x8,0x80,0x3F,0x3B,0xC0,0x1,0xE7,0x7C,0x0,0x0,0x7,0x9D,0x0,0x0,0x0,0x0,0x0,0x3,0xF2,0x21,0x10,0x80,0x44,0x10,0xA0,0x7,0xE7,0x78,0x0,0x0,0x1F,0x9D,0x80,0x0,0x0,0x0,0x0,0x1C,0x1F,0x3E,0x21,0x0,0x44,0x0,0xA0,0x8,0x82,0x14,0x0,0x0,0x22,0x8,0x40,0x0,0x0,0x0,0x0,0x23,0x7,0x7E,0xE2,0x0,0x7F,0xFF,0x20,0x8,0x80,0x14,0x0,0x0,0x22,0x0,0x40,0x0,0x0,0x0,0x0,0x30,0xE3,0xE7,0x5C,0x0,0x3F,0x8E,0xC0,0xF,0xFF,0xE4,0x0,0x0,0x3F,0xFF,0x80,0x0,0x0,0x0,0x0,0x40,0xC3,0xFF,0xC8,0x0,0xFF,0x6F,0x0,0x7,0xF1,0xD8,0x0,0x0,0x1F,0xC7,0x0,0x0,0x0,0x0,0x0,0x7D,0x81,0xFF,0x88,0x0,0x79,0x0,0x80,0x1F,0xED,0xE0,0x0,0x0,0x7F,0xB7,0x80,0x0,0x0,0x0,0x0,0x46,0x80,0xFF,0x10,0x1,0xF9,0x10,0x80,0xF,0x20,0x10,0x0,0x0,0x3C,0x80,0x40,0x0,0x0,0x0,0x0,0x4A,0xFF,0x1F,0xE0,0x1,0xCF,0x9F,0x0,0x3F,0x22,0x10,0x0,0x0,0xFC,0x88,0x40,0x0,0x0,0x0,0x0,0x3C,0x83,0x14,0x0,0x0,0x83,0xBF,0x0,0x39,0xF3,0xE0,0x0,0x7,0x7,0xCF,0xE7,0x80,0x0,0x0,0x0,0x0,0xFF,0xFF,0x0,0x7,0x1,0xF3,0x80,0x10,0x77,0xE0,0x0,0x8,0xC1,0xDF,0x98,0x40,0x0,0x0,0x0,0x1,0xFF,0xFE,0x80,0x8,0xD9,0xFF,0x80,0xE0,0x3E,0x70,0x0,0xC,0x38,0xF9,0xC9,0xC0,0x0,0x0,0x0,0x1,0xF0,0x3E,0x50,0xC,0x31,0xFF,0x81,0x1B,0x3F,0xF0,0x0,0x10,0x30,0xFF,0xCB,0x20,0x0,0x2,0x0,0x2,0x20,0xC,0x70,0x8,0x20,0xFF,0x81,0x86,0x3F,0xF0,0x0,0x1F,0x60,0x7F,0xFF,0x9E,0x0,0xC,0x0,0x3,0xE0,0x5,0xE0,0xB,0xE0,0x7F,0x81,0x4,0x1F,0xF0,0x0,0x11,0xA0,0x3F,0xC6,0xF8,0x0,0x70,0x0,0x2,0x80,0x7,0x80,0x4,0x7F,0xC7,0x1,0x7C,0xF,0xF0,0x0,0x12,0xBF,0xC7,0x82,0x8,0xF,0x80,0x0,0x5,0x0,0x1,0x80,0x4,0xB0,0xC5,0x0,0x8F,0xF8,0xE0,0x0,0xF,0x20,0x45,0x1,0xF,0xF0,0x0,0x0,0x5,0x0,0x0,0x0,0x3,0xFF,0xFF,0x0,0x96,0x18,0xA0,0x0,0x0,0x7F,0xFE,0x1,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0xFE,0x0,0x7F,0xFF,0xE0,0x0,0x0,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7C,0x3C,0x0,0xF,0xFF,0xC0,0x0,0x0,0xF8,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x88,0x42,0x0,0xF,0x87,0x80,0x0,0x1,0x10,0x42,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF8,0x62,0x0,0x11,0x8,0x40,0x0,0x1,0xF0,0x62,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xA0,0x3C,0x0,0x1F,0xC,0x40,0x0,0x1,0x40,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x40,0x3E,0x0,0x14,0x7,0x80,0x0,0x2,0x80,0x7C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x40,0x37,0x0,0x28,0x7,0xC0,0x0,0x2,0x80,0x6E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x28,0x6,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,};
const byte SpritesP2Mask[] PROGMEM = {160,71,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x3C,0x0,0x0,0x0,0xFE,0x0,0x0,0x0,0x0,0xF0,0x0,0x0,0xF,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0xFE,0x0,0x0,0x1,0xFF,0x0,0x0,0x0,0x3,0xF8,0x0,0x0,0x1F,0xF0,0x0,0x0,0x0,0x0,0x0,0x1,0xFF,0x0,0x0,0x7,0xFF,0x0,0x0,0x0,0x7,0xFC,0x1C,0x0,0x7F,0xF0,0x0,0x0,0x0,0x0,0x0,0x7,0xFF,0x0,0x0,0x1F,0xFF,0x80,0x0,0x0,0x1F,0xFC,0x1E,0x1,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x1F,0xFF,0x80,0x0,0x3F,0xFF,0xC0,0x0,0x0,0x7F,0xFE,0xE,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xFF,0xC0,0x0,0x0,0xFF,0xFF,0xF,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xFF,0x80,0x0,0x0,0xFF,0xFF,0xF,0x3,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0x80,0x0,0x1F,0xFF,0x0,0x0,0x0,0xFF,0xFE,0xF,0x0,0xFF,0xF0,0x0,0x0,0x0,0x0,0x0,0x1F,0xFF,0x0,0xC0,0x7F,0xFF,0x80,0x0,0x0,0x7F,0xFC,0xF,0x0,0xFF,0xF8,0x0,0x0,0x0,0x0,0x0,0x7F,0xFF,0x80,0xE0,0x3F,0xFF,0xC0,0x60,0x3,0xFF,0xFE,0x1F,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xC0,0xE0,0xFF,0xFF,0xC0,0x70,0x3,0xFF,0xFF,0x1F,0x7,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0xFF,0xFF,0xC1,0xE0,0xFF,0xFF,0x80,0x70,0x1,0xFF,0xFF,0x1F,0x3,0xFF,0xF8,0x0,0x0,0x0,0x0,0x7,0xFF,0xFF,0x81,0xE0,0x7F,0xFF,0x80,0xF0,0x1F,0xFF,0xFE,0x1E,0xF,0xFF,0xF8,0x0,0x0,0x0,0x0,0xF,0xFF,0xFF,0x83,0xE3,0xFF,0xFF,0xC0,0xF0,0x3F,0xFF,0xFE,0x7E,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0xF,0xFF,0xFF,0xC7,0xC7,0xFF,0xFF,0xC1,0xF0,0x3F,0xFF,0xFF,0xFE,0x7,0xFF,0xFC,0x0,0x0,0x0,0x0,0x1F,0xFF,0xFF,0xCF,0xC7,0xFF,0xFF,0xC3,0xE0,0x3F,0xFF,0xFF,0xFE,0x7,0xFF,0xFC,0x0,0x0,0x0,0x0,0x1F,0xFF,0xFF,0xDF,0x87,0xFF,0xFF,0xC7,0xE0,0x7F,0x7F,0xFF,0xFE,0x7,0xFF,0xFC,0x0,0x0,0x0,0x0,0x1F,0xBF,0xFF,0xFF,0x7,0xFF,0xFF,0xCF,0xC0,0x7E,0x7F,0xFF,0xFC,0x3,0xFF,0xFC,0x0,0x0,0x0,0x0,0x1F,0xBF,0xFF,0xFE,0x3,0xFF,0xFF,0xFF,0x80,0x3C,0x7F,0xFF,0xF8,0x3,0xFF,0xF8,0x0,0x0,0x0,0x0,0xF,0x3F,0xFF,0xFC,0x3,0xFF,0xFF,0xFF,0x0,0x0,0x7F,0xFE,0xC0,0x3,0x7F,0xF8,0x0,0x0,0x0,0x0,0x0,0x3F,0xFF,0xFC,0x1,0xFF,0xFF,0xFE,0x0,0x0,0xFF,0xFE,0x0,0x3,0x7F,0xFC,0x18,0x0,0x0,0x0,0x0,0x7F,0xFE,0xF8,0x0,0x3F,0xFF,0x7E,0x0,0x3,0xFF,0xFF,0x80,0x1,0x7F,0xFF,0xF8,0x0,0x0,0x0,0x0,0x7C,0x3C,0xF0,0x0,0x3E,0x1E,0x7C,0x0,0x7,0xFF,0xFF,0xC0,0x0,0x7F,0xFF,0xF8,0x0,0x0,0x0,0x0,0xF8,0x7E,0x0,0x0,0x7C,0x3F,0x78,0x0,0x7,0xF8,0x1F,0xE8,0x0,0x7F,0xFF,0xF0,0x0,0x0,0x0,0x0,0xF8,0x7E,0x0,0x0,0x7C,0x3F,0x0,0x0,0x1F,0xC0,0x7,0xF8,0x0,0x7F,0xCF,0xC0,0x0,0x0,0x0,0x0,0xE0,0x3C,0x0,0x0,0x70,0x1E,0x0,0x0,0x1F,0x80,0x3,0xF0,0x0,0x7F,0x80,0x0,0x0,0x0,0x0,0x1,0xC0,0x3E,0x0,0x0,0xE0,0x1F,0x0,0x0,0x18,0x0,0x3,0xC0,0x0,0x6F,0x80,0x0,0x0,0x0,0x0,0x1,0xC0,0x37,0x0,0x0,0xE0,0x1B,0x80,0x0,0x0,0x0,0x0,0xC0,0x0,0xF,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xC0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF0,0x0,0x0,0xF,0xF0,0x0,0x0,0xF8,0x0,0x0,0x0,0x0,0x0,0x1,0xE0,0x0,0x0,0x0,0x0,0x3,0xF8,0x0,0x0,0xF,0xF8,0x0,0x1,0xFE,0x0,0x0,0x0,0x0,0x0,0x0,0x1F,0x0,0x0,0x0,0x0,0x7,0xFC,0x0,0x0,0x1,0xFC,0x0,0x1,0xFF,0xC0,0x0,0x0,0x0,0x0,0x0,0x1F,0x0,0x0,0x0,0x0,0x1F,0xFC,0x0,0x0,0x0,0x7E,0x0,0x0,0x3F,0xF0,0x0,0x0,0x0,0x0,0x0,0x7,0xC0,0x0,0x0,0x0,0x7F,0xFE,0x1,0x80,0x0,0x3F,0x80,0x0,0xF,0xF8,0x0,0x0,0x0,0x0,0x0,0x1,0xF0,0x0,0x0,0x0,0xFF,0xFF,0x1,0xC0,0x0,0x1F,0xC0,0x0,0x7,0xFE,0x0,0x0,0x0,0x0,0x0,0x1,0xFC,0x0,0x0,0x0,0xFF,0xFF,0x1,0xC0,0x0,0x7F,0xE0,0x0,0x3,0xFF,0x0,0x0,0x0,0x0,0x0,0x1,0xFE,0x0,0x0,0x0,0xFF,0xFE,0x3,0xC0,0x1,0xFF,0xE0,0x0,0xF,0xFF,0x80,0x0,0x0,0x3C,0x0,0x0,0x7F,0x0,0x0,0x0,0x7F,0xFC,0x3,0xC0,0x3,0xFF,0xE0,0x0,0x3F,0xFF,0xC0,0x0,0x0,0xFE,0x0,0x0,0x7F,0x80,0x0,0x1,0xFF,0xFE,0x7,0xC0,0xF,0xFF,0xE0,0x0,0x7F,0xFF,0xE0,0x0,0x1,0xFF,0x0,0x0,0x7F,0xC0,0x0,0x0,0xFF,0xFF,0xF,0x80,0x3F,0xFF,0xC0,0x1,0xFF,0xFD,0xE0,0x0,0x7,0xFF,0x0,0x0,0x7F,0xE0,0x0,0x3,0xFF,0xFF,0x1F,0x80,0x7F,0xFF,0xE0,0x7,0xFF,0xF8,0xF0,0x0,0x1F,0xFF,0x80,0x0,0x7F,0xE0,0x0,0x1F,0xFF,0xFE,0x3F,0x0,0x7F,0xFF,0xE0,0xF,0xFF,0xFC,0x70,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xF0,0x0,0x3F,0xFF,0xFE,0xFE,0x0,0x7F,0xFF,0xE0,0xF,0xFF,0xFC,0x38,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xF0,0x0,0x3F,0xFF,0xFF,0xFC,0x0,0x3F,0xFF,0xC0,0xF,0xFF,0xFC,0x18,0x0,0x3F,0xFF,0x80,0x0,0x3F,0xF8,0x0,0x7F,0xFF,0xFF,0xF8,0x0,0xFF,0xFF,0x0,0x7,0xFF,0xF8,0x10,0x0,0x1F,0xFF,0x0,0x0,0x3F,0xF8,0x0,0x7F,0xFF,0xFF,0xF8,0x0,0x7F,0xFF,0x80,0x1F,0xFF,0xE0,0x0,0x0,0x7F,0xFF,0x80,0x0,0x3F,0xFC,0x0,0x7E,0xFF,0xFF,0xF0,0x1,0xFF,0xFF,0x80,0xF,0xFF,0xF0,0x0,0x0,0x3F,0xFF,0xC0,0x0,0x3F,0xFC,0x0,0x7E,0xFF,0xFF,0xE0,0x1,0xFF,0xFF,0x0,0x3F,0xFF,0xF0,0x0,0x0,0xFF,0xFF,0xC0,0x0,0x7F,0xFC,0x0,0x3C,0xFF,0xFC,0x0,0x0,0xFF,0xFF,0x0,0x3F,0xFF,0xE0,0x0,0x7,0xFF,0xFF,0xE7,0x80,0x7F,0xFE,0x0,0x0,0xFF,0xFF,0x0,0x7,0xFF,0xFF,0x80,0x1F,0xFF,0xE0,0x0,0xF,0xFF,0xFF,0xFF,0xC0,0x7F,0xFE,0x0,0x1,0xFF,0xFF,0x80,0xF,0xFF,0xFF,0x80,0xFF,0xFF,0xF0,0x0,0xF,0xFF,0xFF,0xFF,0xC0,0x7F,0xFE,0x0,0x1,0xF0,0x3F,0xD0,0xF,0xFF,0xFF,0x81,0xFF,0xFF,0xF0,0x0,0x1F,0xFF,0xFF,0xFF,0xE0,0xFF,0xFE,0x0,0x3,0xE0,0xF,0xF0,0xF,0xFF,0xFF,0x81,0xFF,0xFF,0xF0,0x0,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x0,0x3,0xE0,0x7,0xE0,0xF,0xFF,0xFF,0x81,0xFF,0xFF,0xF0,0x0,0x1F,0xBF,0xFF,0xC7,0xFF,0xFF,0xF0,0x0,0x3,0x80,0x7,0x80,0x7,0xFF,0xFF,0x1,0xFF,0xFF,0xF0,0x0,0x1F,0xBF,0xFF,0x83,0xFF,0xFF,0x80,0x0,0x7,0x0,0x1,0x80,0x7,0xFF,0xFF,0x0,0xFF,0xFF,0xE0,0x0,0xF,0x3F,0xFF,0x1,0xFF,0xF0,0x0,0x0,0x7,0x0,0x0,0x0,0x3,0xFF,0xFF,0x0,0xFF,0xFF,0xE0,0x0,0x0,0x7F,0xFE,0x1,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7F,0xFE,0x0,0x7F,0xFF,0xE0,0x0,0x0,0xFF,0xFC,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7C,0x3C,0x0,0xF,0xFF,0xC0,0x0,0x0,0xF8,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF8,0x7E,0x0,0xF,0x87,0x80,0x0,0x1,0xF0,0x7E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF8,0x7E,0x0,0x1F,0xF,0xC0,0x0,0x1,0xF0,0x7E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xE0,0x3C,0x0,0x1F,0xF,0xC0,0x0,0x1,0xC0,0x3C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xC0,0x3E,0x0,0x1C,0x7,0x80,0x0,0x3,0x80,0x7C,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xC0,0x37,0x0,0x38,0x7,0xC0,0x0,0x3,0x80,0x6E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x38,0x6,0xE0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,};


const byte player1_sprites[][4] PROGMEM = {
  {3,2,32,28}, //STATE 0 IDLE
  {37,1,31,29}, //STATE 0
  {73,2,31,28}, //STATE 1 RUN
  {108,1,25,29}, //STATE 1
  {1,34,33,29}, //STATE 2 jump
  {36,33,23,36}, //STATE 2
  {63,34,30,36}, //STATE 3 punch
  {99,34,52,35} //STATE 3
};


const byte player2_sprites[][4] PROGMEM = {
  {3,2,32,28}, //STATE 0 IDLE
  {37,1,31,29}, //STATE 0
  {73,2,31,28}, //STATE 1 RUN
  {108,1,25,29}, //STATE 1
  {1,34,33,29}, //STATE 2 jump
  {36,33,23,36}, //STATE 2
  {63,34,30,36}, //STATE 3 punch
  {99,34,52,35} //STATE 3
};

#define NB_STATE 11
#define NB_SPRITE_STATE 2
#define TIME_ATTACK 6
#define SPEED_RUN 3
#define GROUND_Y 47
#define TIME_DEF 2
#define NB_MOVE_SAVE 4
#define TIME_FALL  5


int8_t selectedCharacter;

typedef struct {
  uint8_t currentState; // IDL : 0 ,run : 1, jump : 2, punchLeft : 3
  uint8_t currentSprite;//sprite 1 or 2
  float posX,posY;
  float vx,vy;
  //uint8_t height,width;
  uint8_t currentCharater;
  int8_t life;
  int8_t oldLife;
  int8_t cadance;//speed of change sprite
  int8_t damage; //damage current punch
  byte dir; //NOFLIP -> and FLIPH <-
  int8_t timeAttack,timeNextAttack;
  boolean isJump;
  byte cptVictory;
  byte isDef;
  //Ayouken ayouken;
  byte combo[NB_MOVE_SAVE];
  uint8_t timeFall;  
}
Figther;

Figther Player1 = {0,0,8,18,0,0,0,100,100,2,5,NOFLIP,4,8,false,0,0,0};
Figther Player2 = {0,0,8,19,0,0,0,100,100,2,5,FLIPH,4,8,false,0,0,0};

byte xoffsetCptGras;
byte yoffsetTimeUp;
byte cptTechArena;


byte stateGame = 3; //3 main menu, 0 game , 1 multiplayer menu , 2 option , 4 final screen ..... 

void leftFigther(Figther * player);
void rightFigther(Figther * player);
void highFigther(Figther * player);
void bottomFigther(Figther * player);
void punchFigther(Figther * player);
void kickFigther(Figther * player);
void initPlayer(boolean isStartGame);
void moveIAPlayer(Figther * player,Figther * human);
void initSpritePlayer(Figther * player, uint8_t numero);


void drawBitmapMask(int8_t dst_x, int8_t dst_y, int8_t dst_w, int8_t dst_h, int src_x, int src_y, const uint8_t *bitmap, const uint8_t *mask);
void drawBitmapMask(int8_t dst_x, int8_t dst_y, int8_t dst_w, int8_t dst_h, int8_t src_x, int8_t src_y, const uint8_t *bitmap, const uint8_t *mask,uint8_t rotation, uint8_t flip);
void drawBitmapCustom(byte state,byte sprite, byte dst_x, byte dst_y,uint8_t rotation, uint8_t flip,byte numP);
const byte* getSpriteSheetPlayer(byte numPlayer, boolean mask);





void setup()
{
  gb.begin();
  initSD();
  checkDataFile();
}


void loop(){

 if(gb.update())
 {
   //gb.display.print("The game");
    if(gb.buttons.pressed(BTN_C)){
     //go to game
      goTitleScreen();
    }
    
    //3 states combat, pause, final screen
    switch(stateGame)
    {
      case 0 :
        updatePlayer();
        updateArena();
        moveIAPlayer(&Player2,&Player1);      
        
        drawArena();
        drawPlayer(); 
      break;  
      case 1 : 
      break;  
      
    }
  } 
}

void returnToMenu()
{
  gb.display.clear();
  gb.display.print(F("Swords of the Sea Wolves \n\35 Flashing\n  menu...\n\nDON'T TURN OFF!"));
  gb.display.update();
  load_game("PIRATES");
}

#define BASE_NAME "PIRATE.JC"

void initSD()
{
  if (!sd.begin(CHIP_SELECT)) {
    Serial.println(F("begin error"));
    gb.popup(F("ERROR SD"),10);
    //return;
  }
}

void checkDataFile()
{
  selectedCharacter = 0;//ONLY for simbuino test
  return;//ONLY for simbuino test
  //O_RDONLY
  myFile = sd.open(BASE_NAME, O_RDONLY);
  if (!myFile) {
    Serial.println(F("open error"));
    gb.popup(F("ERROR SD"),10);
    //return;
  }
  int i = myFile.parseInt();
  
  myFile.close();  
  if(i < 10) 
  {
    //TODO return to menu
    //myFile.close();
    gb.popup(F("return to menu"),10);
    returnToMenu();
  }
  else {
    gb.popup(F("Go to fight"),10);
  }
  
  myFile = sd.open(BASE_NAME, O_RDWR|O_CREAT|O_TRUNC);
  myFile.println("0");
  myFile.close();  
  
  selectedCharacter = i-10;
}

