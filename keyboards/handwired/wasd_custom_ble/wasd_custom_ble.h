/* Copyright 2020 Andrey Shertsinger
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef WASD_CUSTOM_BLE_H
#define WASD_CUSTOM_BLE_H

#include "quantum.h"

#define LAYOUT( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011,       K013, K014,       \
    K100, K101, K102, K103, K104, K105, K106, K107,             K110, K111,       K113, K114, K115, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210,       K212, K213, K214, K215, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,             K314, K315, \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413,       K415, \
    K500,       K502, K503, K504, K505,       K507, K508, K509, K510, K511,       K513,       K515, \
    K600, K601, K602, K603, K604, K605, K606,       K608, K609, K610,             K613, K614,       \
                      K703, K704,             K707, K708, K709, K710, K711,       K713,       K715  \
) { \
    { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  KC_NO, K013,  K014,  KC_NO }, \
    { K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  KC_NO, KC_NO, K110,  K111,  KC_NO, K113,  K114,  K115 }, \
    { K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  KC_NO, K212,  K213,  K214,  K215 }, \
    { K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  KC_NO, KC_NO, K314,  K315 }, \
    { K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412,  K413,  KC_NO, K415 }, \
    { K500,  KC_NO, K502,  K503,  K504,  K505,  KC_NO, K507,  K508,  K509,  K510,  K511,  KC_NO, K513,  KC_NO, K515 }, \
    { K600,  K601,  K602,  K603,  K604,  K605,  K606,  KC_NO, K608,  K609,  K610,  KC_NO, KC_NO, K613,  K614,  KC_NO }, \
    { KC_NO, KC_NO, KC_NO, K703,  K704,  KC_NO, KC_NO, K707,  K708,  K709,  K710,  K711,  KC_NO, K713,  KC_NO, K715 }  \
}
#define KEYMAP( \
    _ESC,         _F1,   _F2,  _F3,  _F4,  _F5,  _F6,  _F7,  _F8,   _F9,  _F10,  _F11,  _F12,    _PSCR, _SLCK, _PAUS, \
    _GRV,  _1,    _2,    _3,   _4,   _5,   _6,   _7,   _8,   _9,    _0,   _MINS, _EQL,  _BSPC,   _INS,  _HOME, _PGUP,   _NLCK, _PSLS, _PAST, _PMNS, \
    _TAB,  _Q,    _W,    _E,   _R,   _T,   _Y,   _U,   _I,   _O,    _P,   _LBRC, _RBRC, _BSLS,   _DEL,  _END,  _PGDN,   _P7,   _P8,   _P9,   _PPLS, \
    _CAPS,        _A,    _S,   _D,   _F,   _G,   _H,   _J,   _K,    _L,   _SCLN, _QUOT, _ENT,                           _P4,   _P5,   _P6,          \
    _LSFT,        _Z,    _X,   _C,   _V,   _B,   _N,   _M,   _COMM, _DOT, _SLSH,        _RSFT,          _UP,            _P1,   _P2,   _P3,   _PENT, \
    _LCTL, _LGUI, _LALT,                   _SPC,                    _RALT, _RGUI, _APP, _RCTL,   _LEFT, _DOWN, _RGHT,   _P0,          _PDOT         \
) LAYOUT( \
    _GRV,  _F1,   _F2,   _5,    _6,    _EQL,  _F8,   _MINS, _DEL,  _INS,  _PGUP, _HOME,        _F9,   _LCTL,        \
    _1,    _2,    _3,    _4,    _7,    _8,    _9,    _0,                  _PGDN, _END,         _F10,  _F5,   _PSCR, \
    _TAB,  _CAPS, _F3,   _T,    _Y,    _RBRC, _F7,   _LBRC, _P4,   _P5,   _P6,          _LSFT, _BSPC, _LGUI, _APP,  \
    _Q,    _W,    _E,    _R,    _U,    _I,    _O,    _P,    _P7,   _P8,   _P9,   _PPLS,               _PAUS, _SLCK, \
    _A,    _S,    _D,    _F,    _J,    _K,    _L,    _SCLN, _P1,   _P2,   _P3,   _PENT, _RSFT, _BSLS,        _RGUI, \
    _ESC,         _F4,   _G,    _H,    _F6,          _QUOT, _SPC,  _P0,   _PDOT, _UP,          _F11,         _LALT, \
    _Z,    _X,    _C,    _V,    _M,    _COMM, _DOT,         _NLCK, _PSLS, _PAST,               _ENT,  _RCTL,        \
                         _B,    _N,                  _SLSH, _DOWN, _RGHT, _PMNS, _LEFT,        _F12,         _RALT  \
)

#endif
