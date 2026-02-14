#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BTN_A   2
#define BTN_B   3
#define BTN_SEL 4
#define BTN_ST  5
#define BTN_UP  6
#define BTN_DN  7
#define BTN_LT  8
#define BTN_RT  9

int main() {
    stdio_init_all();

    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);

    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);

    gpio_init(BTN_SEL);
    gpio_set_dir(BTN_SEL, GPIO_IN);
    gpio_pull_up(BTN_SEL);

    gpio_init(BTN_ST);
    gpio_set_dir(BTN_ST, GPIO_IN);
    gpio_pull_up(BTN_ST);

    gpio_init(BTN_UP);
    gpio_set_dir(BTN_UP, GPIO_IN);
    gpio_pull_up(BTN_UP);

    gpio_init(BTN_DN);
    gpio_set_dir(BTN_DN, GPIO_IN);
    gpio_pull_up(BTN_DN);

    gpio_init(BTN_LT);
    gpio_set_dir(BTN_LT, GPIO_IN);
    gpio_pull_up(BTN_LT);

    gpio_init(BTN_RT);
    gpio_set_dir(BTN_RT, GPIO_IN);
    gpio_pull_up(BTN_RT);

    while (true) {
        uint8_t input_state = 0;
        input_state |= (!gpio_get(BTN_A)) << 0;
        input_state |= (!gpio_get(BTN_B)) << 1;
        input_state |= (!gpio_get(BTN_SEL)) << 2;
        input_state |= (!gpio_get(BTN_ST)) << 3;
        input_state |= (!gpio_get(BTN_UP)) << 4;
        input_state |= (!gpio_get(BTN_DN)) << 5;
        input_state |= (!gpio_get(BTN_LT)) << 6;
        input_state |= (!gpio_get(BTN_RT)) << 7;

        printf("Input state: %d\n", input_state);
        sleep_ms(10);
    }

    return 0;
}