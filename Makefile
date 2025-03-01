.PHONY: clean
clean:
	rm -rf .pio

.PHONY: firmware
firmware: clean
	pio run -e feather

.PHONY: upload
upload: clean
	pio run -e feather --target upload

.PHONY: monitor
monitor:
	pio device monitor

.PHONY: udev-rules
udev-rules:
	curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core/develop/platformio/assets/system/99-platformio-udev.rules | sudo tee /etc/udev/rules.d/99-platformio-udev.rules
