// Copyright 2021 Dawid Wojda (@dawiidio)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k000,\
    k001,\
    k002\
) { \
    { k000 }, \
    { k001 }, \
    { k002 } \
}
