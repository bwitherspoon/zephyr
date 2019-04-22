# Copyright (c) 2019 Brett Witherspoon
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

set(SHIELD boostxl_ulpsense)

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(boostxl_ulpsense)

target_sources(app PRIVATE src/main.c)
