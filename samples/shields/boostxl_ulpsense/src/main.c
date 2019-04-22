/*
 * Copyright (c) 2019 Brett Witherspoon
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <sensor.h>
#include <stdio.h>

void main(void)
{
	double x, y, z;
	struct sensor_value accel_xyz[3];
	struct device *adxl362 = device_get_binding(DT_ADI_ADXL362_0_LABEL);

	if (adxl362 == NULL) {
		printf("ADXL362: Could not get device \n");
		return;
	}

	while (1) {
		if (sensor_sample_fetch(adxl362) < 0) {
			printf("ADXL362: Sample fetch error\n");
			return;
		}

		if (sensor_channel_get(adxl362, SENSOR_CHAN_ACCEL_X, &accel_xyz[0]) < 0) {
			printf("ADXL362: Channel get error\n");
			return;
		}

		if (sensor_channel_get(adxl362, SENSOR_CHAN_ACCEL_Y, &accel_xyz[1]) < 0) {
			printf("ADXL362: Channel get error\n");
			return;
		}

		if (sensor_channel_get(adxl362, SENSOR_CHAN_ACCEL_Z, &accel_xyz[2]) < 0) {
			printf("ADXL362: Channel get error\n");
			return;
		}

		x = sensor_value_to_double(&accel_xyz[0]);
		y = sensor_value_to_double(&accel_xyz[1]);
		z = sensor_value_to_double(&accel_xyz[2]);

		printf("ADXL362: x: %.1f, y: %.1f, z: %.1f (m/s^2)\n", x, y, z);

		k_sleep(1000);
	}
}
