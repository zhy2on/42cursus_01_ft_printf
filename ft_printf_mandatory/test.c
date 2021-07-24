#include <stdio.h>
#include "ft_printf.h"
int main()
{
	printf("%3d\n", -123);
	ft_printf("%3d\n", -123);
	printf("%3.2d\n", -123);
	ft_printf("%3.2d\n", -123);
	printf("%3.4d\n", -123);
	ft_printf("%3.4d\n", -123);

	printf("%4d\n", -123);
	ft_printf("%4d\n", -123);
	printf("%4.2d\n", -123);
	ft_printf("%4.2d\n", -123);
	printf("%4.5d\n", -123);
	ft_printf("%4.5d\n", -123);

	
	printf("-----------\n");

	printf("%7.4d\n", -123);
	ft_printf("%7.4d\n", -123);
	printf("%7d\n", -123);
	ft_printf("%7d\n", -123);
	printf("%-7.4d\n", -123);
	ft_printf("%-7.4d\n", -123);
	printf("%5.2d\n", 1234);
	ft_printf("%5.2d\n", 1234);
	printf("%010d\n", -123);
	ft_printf("%010d\n", -123);
	printf("%010.4d\n", -123);
	ft_printf("%010.4d\n", -123);
	printf("%10d\n", -123);
	ft_printf("%10d\n", -123);
}
