/*
 * Copyright (c) 2019 Brett Witherspoon
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>

#include <driverlib/setup.h>

static int ti_cc13x0_cc26x0_init(struct device *dev)
{
	ARG_UNUSED(dev);

	/* Performs necessary trim of the device. */
	SetupTrimDevice();

	return 0;
}

SYS_INIT(ti_cc13x0_cc26x0_init, PRE_KERNEL_1, 0);
