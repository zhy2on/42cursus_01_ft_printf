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

void	check_width_and_prec(va_list ap, char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[i] - 48;
		else
			info->prec = info->prec * 10 + format[i] - 48;
	}
	else if (format[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

void	check_info(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_width_and_prec(ap, format, info, i);
}

void	init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

static int	parse_format(va_list ap, char *format)
{
	int		i;
	int		len;
	t_info	*info;

	i = 0;
	len = 0;
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (-1);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			ret += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_info(info);
			while (format[++i] && !(ft_strchr(FLAGS, format[i])))
				check_info(ap, format, info, i);
			info->type = format[i++];
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			len += 
		}
	}

}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = parse_format(ap, (char *)format);
	va_end(ap);
	return (len);
}
