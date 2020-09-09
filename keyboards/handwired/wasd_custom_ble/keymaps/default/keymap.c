/*
Copyright (c) 2018, Sekigon
Copyright (c) 2020, Andrey Shertsinger

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "app_ble_func.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_gpio.h"
#include "nrf_drv_usbd.h"


enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
};

//TD Declarations
enum {
  CAL = 0,
};

extern keymap_config_t keymap_config;

enum {
  BASE=0,
  MEDIA
};

// Fillers to make layering more clear
// #define _______ KC_TRNS
// #define XXXXXXX KC_NO

  /* Layer 0, default layer
  *  ,-------.         ,---------------------------------. ,---------------------------------. ,----------------------------------.  ,-------------------------.
  *  |  Esc  |         |  F1   |   F2   |   F3   |   F4  | |  F5   |   F6   |   F7   |   F8  | |  F9   |  F10   |   F11  |   F12  |  | Print |  ScrL  |  Pause |
  *  `-------'         `---------------------------------' `---------------------------------' `----------------------------------'  `-------------------------'
  *  ,----------------------------------------------------------------------------------------------------------------------------.  ,-------------------------.  ,----------------------------------.
  *  |  ~`   |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |    -   |    =   | BkSpc  |  | Insert|  Home  |  PgUp  |  |NumLck |   /    |   *    |   -    |
  *  |----------------------------------------------------------------------------------------------------------------------------|  |-------------------------|  |----------------------------------|
  *  | Tab   |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |    {   |    }   | \      |  | Delete|  End   |  PgDn  |  |  7    |   8    |   9    |   +    |
  *  |----------------------------------------------------------------------------------------------------------------------------|  `-------------------------'  |-------------------------|        |
  *  | Caps           |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |    ;   |    '   | Return |                               |  4    |   5    |   6    |        |
  *  |----------------------------------------------------------------------------------------------------------------------------|          ,--------.           |----------------------------------|
  *  | LShft          |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   ,    |   .    |    /   | RShft           |          |   Up   |           |  1    |   2    |   3    |  En    |
  *  |----------------------------------------------------------------------------------------------------------------------------|  ,-------------------------.  |-------------------------|        |
  *  | Ctrl  |   Win  |  Alt   |                      Space                               |  Alt  |   Win  |  Fn  |    Ctrl       |  |  Left |  Down  |  Right |  |   0            |   .    |        |
  *  `----------------------------------------------------------------------------------------------------------------------------'  `-------------------------'  `----------------------------------'
  */


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE]=KEYMAP(
      KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_PSCR, KC_SLCK, KC_PAUS,
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,   TD(CAL), KC_PSLS, KC_PAST, KC_PMNS,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
      KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                                 KC_P4,   KC_P5,   KC_P6,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,            KC_UP,              KC_P1,   KC_P2,   KC_P3,   KC_PENT,
      KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                KC_RALT, KC_RGUI, LT(1, KC_APP), KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT,   KC_P0,            KC_PDOT
  ),
  [MEDIA]=KEYMAP(
      XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, USB_EN,  USB_DIS, BLE_EN,  BLE_DIS,   XXXXXXX, XXXXXXX, KC_MUTE,
      ENT_DFU, AD_WO_L, DELBNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MPLY, KC_MSTP, KC_VOLU,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_MPRV, KC_MNXT, KC_VOLD,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,            XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX,                   BATT_LV,                               XXXXXXX, XXXXXXX, LT(1, KC_APP), XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,          XXXXXXX
  ),
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [CAL] = ACTION_TAP_DANCE_DOUBLE(KC_NLCK, KC_CALC),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[32];
  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      return false;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      return false;
    case USB_EN:
      set_usb_enabled(true);
      return false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      return false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      return false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      return false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      return false;
    case ADV_ID1:
      restart_advertising_id(1);
      return false;
    case ADV_ID2:
      restart_advertising_id(2);
      return false;
    case ADV_ID3:
      restart_advertising_id(3);
      return false;
    case ADV_ID4:
      restart_advertising_id(4);
      return false;
    case DEL_ID0:
      delete_bond_id(0);
      return false;
    case DEL_ID1:
      delete_bond_id(1);
      return false;
    case DEL_ID2:
      delete_bond_id(2);
      return false;
    case DEL_ID3:
      delete_bond_id(3);
      return false;
    case BATT_LV:
    	NRF_LOG_DEBUG("Battery level %4dmV\n", get_vcc());
      if (nrf_drv_usbd_is_started()) { // CHARGING
        if (!nrf_gpio_pin_read(CHARGED)) { // CHARGED
          sprintf(str, "%4dmV OK\n", get_vcc());
        } else {
          sprintf(str, "%4dmV CHRG\n", get_vcc());
        }
      } else { // DISCHARGING
        sprintf(str, "%4dmV\n", get_vcc());
      }
      send_string(str);
      return false;
    case ENT_DFU:
      bootloader_jump();
      return false;
    }
  }
  else if (!record->event.pressed) {
    switch (keycode) {
    case ENT_SLP:
      sleep_mode_enter();
      return false;
    }

  }
  return true;
}
;




