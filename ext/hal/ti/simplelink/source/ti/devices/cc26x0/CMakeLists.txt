zephyr_include_directories(
  .
  )

zephyr_library()
zephyr_library_compile_definitions(${COMPILER})
zephyr_library_sources(
  # Needed for SystemTrimDevice which is not in ROM
  driverlib/setup.c
  driverlib/setup_rom.c
  driverlib/chipinfo.c
  driverlib/osc.c
  driverlib/ddi.c
  driverlib/cpu.c
  # Needed for TRNG functions not in ROM
  driverlib/trng.c
  )
