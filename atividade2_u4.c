#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <string.h>
#include "hash.h"

#define LED_GREEN_PIN 11
#define LED_BLUE_PIN 12
#define LED_RED_PIN 13

#define BUZZER_PIN 21
#define BUZZER_FREQ 4000

const unsigned long RED = 193468640;
const unsigned long GREEN = 221376950;
const unsigned long BLUE = 2088931085;
const unsigned long WHITE = 239997158;
const unsigned long YELLOW = 3699751457;
const unsigned long CYAN = 2088980528;
const unsigned long MAGENTA = 3352243490;
const unsigned long BUZZER = 2819130183;

char command[10];
unsigned long hash_code;

void setup();
void turn_leds(bool red, bool green, bool blue);
void pwm_init_buzzer(uint pin);
void beep(uint pin, uint duration_ms);

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

// Definição de uma função para inicializar o PWM no pino do buzzer
void pwm_init_buzzer(uint pin) {
    // Configurar o pino como saída de PWM
    gpio_set_function(pin, GPIO_FUNC_PWM);

    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o PWM com frequência desejada
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQ * 4096)); // Divisor de clock
    pwm_init(slice_num, &config, true);

    // Iniciar o PWM no nível baixo
    pwm_set_gpio_level(pin, 0);
}

void beep(uint pin, uint duration_ms) {
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o duty cycle para 50% (ativo)
    pwm_set_gpio_level(pin, 2048);

    // Temporização
    sleep_ms(duration_ms);

    // Desativar o sinal PWM (duty cycle 0)
    pwm_set_gpio_level(pin, 0);

    // Pausa entre os beeps
    sleep_ms(100); // Pausa de 100ms
}

void turn_leds(bool red, bool blue, bool green){
  gpio_put(LED_RED_PIN, red);
  gpio_put(LED_BLUE_PIN, blue);
  gpio_put(LED_GREEN_PIN, green);
}