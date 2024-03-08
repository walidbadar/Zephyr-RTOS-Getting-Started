/*
 * Copyright (c) 2020 PHYTEC Messtechnik GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */
//0x01 0x04 0x03 0xe8 0x00 0x01

#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/modbus/modbus.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(mbc_sample, LOG_LEVEL_INF);

static int client_iface;

const static struct modbus_iface_param client_param = {
	.mode = MODBUS_MODE_RTU,
	.rx_timeout = 5000000,
	.serial = {
		.baud = 9600,
		.parity = UART_CFG_PARITY_NONE,
		.stop_bits_client = UART_CFG_STOP_BITS_1,
	},
};

#define MODBUS_NODE DT_COMPAT_GET_ANY_STATUS_OKAY(zephyr_modbus_serial)

static int init_modbus_client(void)
{
	const char iface_name[] = {DEVICE_DT_NAME(MODBUS_NODE)};

	client_iface = modbus_iface_get_by_name(iface_name);

	return modbus_init_client(client_iface, client_param);
}

int main(void)
{
	uint16_t temperature = 0;
	uint16_t getTempAddress = 0x03E8;
	static uint8_t node = 1;
	
	if (init_modbus_client()) {
		LOG_ERR("Modbus RTU client initialization failed");
		return 0;
	}

	while (true) {
		modbus_read_input_regs(client_iface, node, getTempAddress, &temperature, 1);
		
		printk("Temperature: %d°C\n", temperature);

		k_msleep(1000);
	}
}
