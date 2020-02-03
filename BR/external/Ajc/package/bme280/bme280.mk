BME280_SOURCE = bme280.tar.gz
BME280_SITE = https://github.com/andreiva/raspberry-pi-bme280

define BME280_BUILD_CMDS
	$(TARGET_CONFIGURE_OPTS) $(MAKE) -C $(@D)
endef

define BME280_INSTALL_TARGET_CMDS
	$(TARGET_CONFIGURE_OPTS) $(MAKE) -C $(@D) DESTDIR="$(TARGET_DIR)" install
endef

define BME280_INSTALL_INIT_SYSV
        $(INSTALL) -D -m 0755 ../external/Ajc/package/bme280/S99bme280  $(TARGET_DIR)/etc/init.d/S99bme280
endef

$(eval $(generic-package))
