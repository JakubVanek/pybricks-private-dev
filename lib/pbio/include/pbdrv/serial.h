// SPDX-License-Identifier: MIT
// Copyright (c) 2018-2020 The Pybricks Authors

#include <unistd.h>
#include <stdint.h>

#include <pbio/error.h>
#include <pbio/port.h>

typedef struct _pbdrv_serial_t pbdrv_serial_t;

pbio_error_t pbdrv_serial_get(pbdrv_serial_t **_ser, pbio_port_t port, int baudrate);

pbio_error_t pbdrv_serial_write(pbdrv_serial_t *ser, const void *buf, size_t count);

pbio_error_t pbdrv_serial_in_waiting(pbdrv_serial_t *ser, size_t *waiting);

pbio_error_t pbdrv_serial_read(pbdrv_serial_t *ser, uint8_t *buf, size_t count, size_t *received);

pbio_error_t pbdrv_serial_clear(pbdrv_serial_t *ser);
