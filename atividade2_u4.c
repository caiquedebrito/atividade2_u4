#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <string.h>

#define LED_GREEN_PIN 11
#define LED_BLUE_PIN 12
#define LED_RED_PIN 13

#define BUZZER_PIN 21

const unsigned long RED = 193468640;
const unsigned long GREEN = 221376950;
const unsigned long BLUE = 2088931085;
const unsigned long WHITE = 239997158;
const unsigned long YELLOW = 3699751457;
const unsigned long CYAN = 2088980528;
const unsigned long MAGENTA = 3352243490;

void setup();
void turn_leds(bool red, bool green, bool blue);
void pwm_init_buzzer(uint pin);

char command[10];
unsigned long hash_code;

void setup() {
    stdio_init_all();
    pwm_init_buzzer(BUZZER_PIN);

    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
}

void turn_leds(bool red, bool blue, bool green){
  gpio_put(LED_RED_PIN, red);
  gpio_put(LED_BLUE_PIN, blue);
  gpio_put(LED_GREEN_PIN, green);
}