#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

const int SENSOR_READ_PIN = 15;
const int SENSOR_WRITE_PIN = 16;

void setup() {
    wiringPiSetup(); //Setup WiringPi
    pinMode(SENSOR_READ_PIN, INPUT);
    pinMode(SENSOR_WRITE_PIN, OUTPUT);
    system("echo -n \"$(date +%s)\""); //Bad practice I know but can't be arsed to engage the full C date stuff
}

uint8_t read_sensor() {
    uint8_t value = 0;
    // 8 bits in reverse order
    for (int x = 0; x < 8; x++) {
        digitalWrite(SENSOR_WRITE_PIN, HIGH);
        delay(10);
        uint8_t bit = (digitalRead(SENSOR_READ_PIN) == LOW) ? 0x1 : 0x0;
        value |= bit << x;
        digitalWrite(SENSOR_WRITE_PIN, LOW);
        delay(10);
    }
    return value;
}

int main() {
    setup();
    printf("%u\n", read_sensor());
}
