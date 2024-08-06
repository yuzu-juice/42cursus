#include "libftprintf.h"
#include <stdio.h>

int	main() {
	ft_printf("Hello, World!\n");
	ft_printf("Char: %c\n", 'a');
	ft_printf("String: %s\n", "abcde");
	ft_printf("Int: %d, %i\n", 5, 10);

	return 0;
}

int	ft_printf(const char *fmt, ...) {
	va_list	ap;
	char	c;
	char	*s;
	int		i;

	va_start(ap, fmt);
	while (*fmt) {
		if (*fmt == '%') {
			fmt++;
			if (*fmt == 'c')
			{
				c = va_arg(ap, int);
				print_c(c);
			}
			else if (*fmt == 's')
			{
				s = va_arg(ap, char *);
				print_s(s);
			}
			else if (*fmt == 'p') {}
			else if (*fmt == 'd')
			{
				i = va_arg(ap, int);
				print_d(i);
			}
			else if (*fmt == 'i')
			{
				i = va_arg(ap, int);
				print_i(i);
			}
			else if (*fmt == 'u') {}
			else if (*fmt == 'x') {}
			else if (*fmt == 'X') {}
			else if (*fmt == '%') {}
			fmt++;
		} else {
			ft_putchar(*fmt);
			fmt++;
		}
	}

	va_end(ap);

	return 0;
}
