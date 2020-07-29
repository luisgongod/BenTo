#pragma once

// #define DEVICE_TYPE "M5Stick"
#define DEVICE_TYPE "Flowtoys Creator Club"

#ifndef ESP32
#define ESP32
#endif

// main leds config
#define LED_COUNT 34
#define LED_DATA_PIN 26
#define LED_TYPE    WS2812B
#define LED_COLOR_ORDER GRB
// #define LED_INVERT_DIRECTION


// button pin
#define BUTTON_COUNT 1
#define BUTTON_INPUT_MODE INPUT
const int buttonPins[BUTTON_COUNT]{ 39 };

#define HAS_M5_IMU