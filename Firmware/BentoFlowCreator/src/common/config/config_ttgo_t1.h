/*
Config file for ttg0 t1_v1.3
https://github.com/LilyGO/ESP32-TTGO-T1
SD tested with generic SD card holder
Button Pin not tested.
*/
#pragma once

// Flowtoys Creator Club
#define DEVICE_TYPE "Flowtoys Creator Club"

#ifndef ESP32
#define ESP32
#endif

// main leds config
#define LED_COUNT 34
#define LED_DATA_PIN 16
#define LED_TYPE    WS2812B
#define LED_COLOR_ORDER GRB
// #define LED_INVERT_DIRECTION


// button pin
#define BUTTON_COUNT 34
#define BUTTON_INPUT_MODE INPUT
const int buttonPins[BUTTON_COUNT]{ 17 };

//battery sence TODO:
// #define BATTERY_PIN 35 // takes the measurment from the battery sence. 

// SD config
#define HAS_FILES

#define SDSPEED 27000000

#define SD_MISO 2
#define SD_MOSI 15
#define SD_SCK 14
#define SD_CS 13