#include "printf.h"
#include "utils.h"
#include "mini_uart.h"

void kernel_main(void)
{
        int el;

	uart_init();
	init_printf(0, putc);

	el = get_el();
	printf("Exception level: %d \r\n", el);

	while (1) {
		uart_send(uart_recv());
	}
}
