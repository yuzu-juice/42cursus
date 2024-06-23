#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
void	print_c(char c);
void	print_s(char *s);
void	print_p(void *p);
void	print_d(int d);
void	print_i(int i);
void	print_u(unsigned int u);
void	print_lower_x(int x);
void	print_upper_x(int x);
void	print_percent(void);

#endif
