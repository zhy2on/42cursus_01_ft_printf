#include <stdio.h>
#include "ft_printf.h"
int main()
{
	int ret;

	ret = printf("%03d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%03d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%03.2d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%03.2d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%03.4d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%03.4d\n", -123);
	printf("ret = %d\n", ret);

	ret = printf("%04d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%04d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%04.2d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%04.2d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%04.5d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%04.5d\n", -123);
	printf("ret = %d\n", ret);

	ret = printf("%07d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%07d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%07.2d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%07.2d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%07.5d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%07.5d\n", -123);
	printf("ret = %d\n", ret);

	printf("-----------\n");

	ret = printf("%7.4d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%7.4d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%7d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%7d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%-7.4d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%-7.4d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%5.2d\n", 1234);
	printf("ret = %d\n", ret);
	ret = ft_printf("%5.2d\n", 1234);
	printf("ret = %d\n", ret);
	ret = printf("%010d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%010d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%010.4d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%010.4d\n", -123);
	printf("ret = %d\n", ret);
	ret = printf("%10d\n", -123);
	printf("ret = %d\n", ret);
	ret = ft_printf("%10d\n", -123);
	printf("ret = %d\n", ret);
}
