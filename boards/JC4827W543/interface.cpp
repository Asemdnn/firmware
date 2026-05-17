#include "core/powerSave.h"
#include "core/utils.h"
#include <Arduino.h>
#include <interface.h>

#include "CYD28_TouchscreenR.h"
CYD28_TouchR touch(TFT_WIDTH, TFT_HEIGHT);
#define XPT2046_CS XPT2046_SPI_CONFIG_CS_GPIO_NUM

void _setup_gpio() {
    pinMode(XPT2046_CS, OUTPUT);
    digitalWrite(XPT2046_CS, HIGH);

    if (!touch.begin()) {
        Serial.println("Touch IC not Started");
        log_i("Touch IC not Started");
    } else {
        log_i("Touch IC Started");
    }

    bruceConfig.colorInverted = 0;
}

void _post_setup_gpio() {
    pinMode(TFT_BL, OUTPUT);
    ledcAttach(TFT_BL, TFT_BRIGHT_FREQ, TFT_BRIGHT_Bits);
    ledcWrite(TFT_BL, 255);
}

void _setBrightness(uint8_t brightval) {
    int dutyCycle;
    if (brightval == 100) dutyCycle = 255;
    else if (brightval == 75) dutyCycle = 130;
    else if (brightval == 50) dutyCycle = 70;
    else if (brightval == 25) dutyCycle = 20;
    else if (brightval == 0) dutyCycle = 0;
    else dutyCycle = ((brightval * 255) / 100);

    ledcWrite(TFT_BL, dutyCycle);
}

void InputHandler(void) {
    static long d_tmp = 0;
    if (millis() - d_tmp > 200 || LongPress) {
        if (touch.touched()) {
            auto t = touch.getPointScaled();
            
            // Apply rotation adjustments if necessary for the board's screen orientation
            if (bruceConfigPins.rotation == 1 || bruceConfigPins.rotation == 3) {
                // Adjust if needed
            }

            if (!wakeUpScreen()) AnyKeyPress = true;
            else goto END;

            touchPoint.x = t.x;
            touchPoint.y = t.y;
            touchPoint.pressed = true;
            touchHeatMap(touchPoint);
        END:
            d_tmp = millis();
        }
    }
}

void powerOff() {
    esp_sleep_enable_ext0_wakeup(GPIO_NUM_0, LOW);
    esp_deep_sleep_start();
}

void checkReboot() {}
