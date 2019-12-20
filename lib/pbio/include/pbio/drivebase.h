// SPDX-License-Identifier: MIT
// Copyright (c) 2019 Laurens Valk

#ifndef _PBIO_DRIVEBASE_H_
#define _PBIO_DRIVEBASE_H_

#include <pbio/servo.h>

#if PBDRV_CONFIG_NUM_MOTOR_CONTROLLER != 0

typedef struct _pbio_drivebase_t {
    pbio_servo_t *left;
    pbio_servo_t *right;
    fix16_t wheel_diameter;
    fix16_t axle_track;
    fix16_t turn_counts_per_diff;
    fix16_t drive_counts_per_sum;
    pbio_log_t log;
    pbio_control_t control_heading;
} pbio_drivebase_t;

pbio_error_t pbio_drivebase_get(pbio_drivebase_t **_db, pbio_servo_t *left, pbio_servo_t *right, fix16_t wheel_diameter, fix16_t axle_track);

pbio_error_t pbio_drivebase_stop(pbio_drivebase_t *db, pbio_actuation_t after_stop);

pbio_error_t pbio_drivebase_start(pbio_drivebase_t *db, int32_t speed, int32_t turn_rate);

void _pbio_drivebase_poll(void);

#else

static inline void _pbio_drivebase_poll(void) { }

#endif // PBDRV_CONFIG_NUM_MOTOR_CONTROLLER

#endif // _PBIO_DRIVEBASE_H_
