#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

#ifndef DEVICE_NAME
#define DEVICE_NAME "JC4827W543"
#endif

// =============================================
// Display Configuration (Arduino_GFX)
// NV3041A via QSPI
// =============================================
#define USE_ARDUINO_GFX 1
#define TFT_DATABUS_N 1
#define TFT_CS   45
#define TFT_SCLK 47
#define TFT_D0   21
#define TFT_D1   48
#define TFT_D2   40
#define TFT_D3   39

#define TFT_DISPLAY_DRIVER_N 19 // NV3041A
#define TFT_RST      -1
#define TFT_ROTATION 0
#define TFT_IPS      1
#define TFT_WIDTH    272
#define TFT_HEIGHT   480
#define TFT_COL_OFS1 0
#define TFT_ROW_OFS1 0
#define TFT_COL_OFS2 0
#define TFT_ROW_OFS2 0

#define TFT_BL 1 // PWM Backlight
#define TFT_BACKLIGHT_ON HIGH

#define TFT_BRIGHT_FREQ 5000
#define TFT_BRIGHT_Bits 8

#define HAS_SCREEN 1
#define ROTATION 1
#define MINBRIGHT 1
#define BACKLIGHT 1

// =============================================
// Touch Configuration (XPT2046)
// =============================================
#define HAS_TOUCH 1
#define TOUCH_XPT2046_SPI 1
#define XPT2046_SPI_CONFIG_CS_GPIO_NUM 38
#define XPT2046_SPI_BUS_SCLK_IO_NUM 12
#define XPT2046_SPI_BUS_MISO_IO_NUM 13
#define XPT2046_SPI_BUS_MOSI_IO_NUM 11
#define XPT2046_TOUCH_CONFIG_INT_GPIO_NUM 3
#define TOUCH_ROTATION 0
#define HAS_RESISTIVE_TOUCH 1

// =============================================
// System SPI Bus (Mapped to Touch SPI)
// =============================================
#define SPI_SS_PIN 38
static const uint8_t SS = SPI_SS_PIN;
static const uint8_t MOSI = XPT2046_SPI_BUS_MOSI_IO_NUM;
static const uint8_t SCK = XPT2046_SPI_BUS_SCLK_IO_NUM;
static const uint8_t MISO = XPT2046_SPI_BUS_MISO_IO_NUM;

// =============================================
// I2C
// =============================================
#define GROVE_SDA 8
#define GROVE_SCL 4
static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;

// =============================================
// UART
// =============================================
#define SERIAL_TX 43
#define SERIAL_RX 44
static const uint8_t TX = SERIAL_TX;
static const uint8_t RX = SERIAL_RX;

// =============================================
// SD Card (Not populated by default, mapping dummy)
// =============================================
#define SDCARD_CS -1
#define SDCARD_SCK -1
#define SDCARD_MISO -1
#define SDCARD_MOSI -1

// =============================================
// Font Sizes
// =============================================
#define FP 1
#define FM 2
#define FG 3

#endif
