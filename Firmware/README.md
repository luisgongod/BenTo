# Firmware Extra

Some add-ons, Work in progress to increase the library of devices that can be use with Bento.

## Devices tested (mostly)

- M5 Stack family
    - M5 Core Grey 
    - M5 Stick C
    - Atom Matrix
    - Atom lite

- DOIT ESP32 DEVKIT V1
https://github.com/espressif/arduino-esp32/tree/master/variants/doitESP32devkitV1

- LilyGo TTGO_T1 (v1.3)
https://github.com/LilyGO/ESP32-TTGO-T1

Names already added to the `Config.h` along with their corresponded configuration file.

```
#define M5
#define M5Stick
#define DEVKIT1
#define TTGO_T1
```

All of them are "Flowtoys Creator Club" for _Device Type_ or else it wont be recognized by Bento.

The M5's _Atom Matrix, Atom Lite and M5 Stick_ use the same `config_m5stick.h`. IMU was tested on _Matrix_ and _Stick_ (_Lite_ does not have IMU).

In order to use the M5's IMU you will need the `MPU6886` and `MahonyAHRS` libraries (see `\src\sensors\imu`)

I build in VS Code with Platformio, you can use the same configuration if you download as it and just change the
```lib_extra_dirs = C:Users/LG/Documents/Arduino/libraries```
 in the `.ini` file.