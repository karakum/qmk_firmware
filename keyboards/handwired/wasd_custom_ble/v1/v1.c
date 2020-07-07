
#include "nrf_gpio.h"
#include "app_ble_func.h"
#include "led.h"
#include "../board/custom_board.h"

void matrix_init_user() {
  nrf_gpio_cfg_input(CHARGED, NRF_GPIO_PIN_PULLUP);
  nrf_gpio_cfg_input(VBATADC, NRF_GPIO_PIN_PULLDOWN);
  led_init_ports();
}

void led_init_ports() {
  nrf_gpio_cfg_output(LED1);
  nrf_gpio_cfg_output(LED2);
  nrf_gpio_cfg_output(LED3);
}

void led_set_user(uint8_t usb_led) {
  nrf_gpio_pin_write(LED1, (usb_led & (1 << USB_LED_NUM_LOCK)) > 0 ? 0 : 1);
  nrf_gpio_pin_write(LED2, (usb_led & (1 << USB_LED_CAPS_LOCK)) > 0 ? 0 : 1);
  nrf_gpio_pin_write(LED3, (usb_led & (1 << USB_LED_SCROLL_LOCK)) > 0 ? 0 : 1);
}
