/*
 * Copyright (c) 2019 Brett Witherspoon
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <stdio.h>
#include <device.h>
#include <drivers/sensor.h>

void main(void)
{
	struct sensor_value val;

	struct device *dev = device_get_binding(DT_INST_0_TI_OPT3001_LABEL);
	if (dev == NULL) {
		printf("Failed to get device: %s\n", DT_INST_0_TI_OPT3001_LABEL);
		return;
	}

	while (true) {
		if (sensor_sample_fetch(dev) < 0) {
			printf("Failed to fetch sample\n");
			return;
		};

		if (sensor_channel_get(dev, SENSOR_CHAN_LIGHT, &val) < 0) {
			printf("Failed to get channel\n");
			return;
		}

		printf("lux: %.2f\n", sensor_value_to_double(&val));

		k_sleep(K_MSEC(1000));
	}
}
