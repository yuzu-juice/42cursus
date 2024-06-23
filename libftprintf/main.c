#include "libftprintf.h"
#include <stdio.h>

int main() {
    // 文字列を出力
    ft_printf("Hello, World!\n");

    // 整数と浮動小数点数を出力
    ft_printf("Integer: %d, Double: %.2f\n", 42, 3.14159);

    return 0;
}

int ft_printf(const char *format, ...) {
    va_list args;
    int done;

    va_start(args, format);
    done = vprintf(format, args);
    va_end(args);

    return done;
}
