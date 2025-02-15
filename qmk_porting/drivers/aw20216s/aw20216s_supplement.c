/*
Copyright 2022 Huckies <https://github.com/Huckies>

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

#include "rgb_matrix.h"
#include "aw20216s_supplement.h"

static volatile bool aw20216s_powered_on = true;

inline bool aw20216s_power_status_get()
{
    return aw20216s_powered_on;
}

inline void aw20216s_power_toggle(bool status)
{
    if (status) {
        gpio_write_pin_high(AW20216S_EN_PIN);
        gpio_set_pin_output(AW20216S_EN_PIN);
    } else {
        gpio_write_pin_low(AW20216S_EN_PIN);
        gpio_set_pin_output(AW20216S_EN_PIN);
    }
    aw20216s_powered_on = status;
}

void aw20216s_power_check()
{
    if (!aw20216s_power_status_get()) {
        aw20216s_power_toggle(true);
    }
}
