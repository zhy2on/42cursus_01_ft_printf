/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:25:18 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/16 16:25:42 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_spec(va_list ap, t_info *info)
{
	int		ret;
	char	spec;

	ret = 0;
	spec = info->spec;
	if (spec == 'c')
		ret = print_char(va_arg(ap, int), info);
	else if (spec == '%')
		ret = print_char('%', info);
	else if (spec == 's')
		ret = print_string(va_arg(ap, char *), info);
	else if (spec == 'd' || spec == 'i')
		ret = print_nbr(va_arg(ap, int), info);
	else if (spec == 'u' || spec == 'x' || spec == 'X')
		ret = print_nbr(va_arg(ap, unsigned int), info);
	else if (spec == 'p')
		ret = print_nbr(va_arg(ap, unsigned long long), info);
	return (ret);
}

void	check_info(char *format, t_info *info, int i)
{
	if (format[i] == '0' && !info->width && info->prec == -1)
		info->pad_c = '0';
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[i] - '0';
		else
			info->prec = info->prec * 10 + format[i] - '0';
	}
}

void	init_info(t_info *info)
{
	info->minus = 0;
	info->pad_c = ' ';
	info->spec = '\0';
	info->width = 0;
	info->prec = -1;
	info->nbr_base = DECI;
	info->nbr_len = 0;
	info->nbr_sign = 1;
}

int	parse_format(va_list ap, char **format, t_info *info)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while ((*format)[++i] && !(ft_strchr(SPECS, (*format)[i])))
		check_info(*format, info, i);
	if ((*format)[i])
	{
		info->spec = (*format)[i];
		*format += i + 1;
		ret += print_spec(ap, info);
	}
	else
	{
		ret += ft_putchar('%');
		(*format)++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_info	*info;
	va_list	ap;

	va_start(ap, format);
	ret = 0;
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (-1);
	while (*format)
	{
		while (*format && *format != '%')
			ret += ft_putchar(*format++);
		if (*format == '%')
		{
			init_info(info);
			ret += parse_format(ap, (char **)&format, info);
		}
	}
	free(info);
	va_end(ap);
	return (ret);
}
