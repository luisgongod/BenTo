/* 
M5Stack Config file. 
Tested in Bake mode and Also for Baking (SD)
IMU not tested, it should be the same as M5 Stick C
*/

#pragma once

// Flowtoys Creator Club
#define DEVICE_TYPE "Flowtoys Creator Club"

#ifndef ESP32
#define ESP32
#endif

// main leds config
#define LED_COUNT 64
#define LED_DATA_PIN 26
#define LED_TYPE    WS2812B
#define LED_COLOR_ORDER GRB
// #define LED_INVERT_DIRECTION

// button pin
#define BUTTON_COUNT 1
#define BUTTON_INPUT_MODE INPUT
const int buttonPins[BUTTON_COUNT]{ 39 };

// SD config
#define HAS_FILES

#define SDSPEED 27000000

#define SD_MISO 19
#define SD_MOSI 23
#define SD_SCK 18
#define SD_CS 4