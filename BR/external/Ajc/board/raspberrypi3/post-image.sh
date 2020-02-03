#!/bin/bash

if ! grep -qE '^dtparam=i2c' "${BINARIES_DIR}/rpi-firmware/config.txt"; then
	cat << __EOF__ >> "${BINARIES_DIR}/rpi-firmware/config.txt"

#enable i2c tool
dtparam=i2c_arm=on
dtparam=i2c1=on
__EOF__
fi
