/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:14:57 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/17 17:34:39 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_info *info)
{
	int	len;

	len = 0;
	if (info->spec == '%' && info->minus == 1)
		info->pad_c = ' ';
	if (info->minus == 1)
		len += ft_putchar(c);
	while (info->width-- > info->prec)
		len += ft_putchar(info->pad_c);
	if (info->minus == 0)
		len += ft_putchar(c);
	return (len);
}

int	print_string(char *str, t_info *info)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	if (info->minus == 1)
	{
		info->pad_c = ' ';
		while (i < info->prec && str[i])
			len += ft_putchar(str[i++]);
	}
	while (info->width-- > info->prec)
		len += ft_putchar(info->pad_c);
	if (info->minus == 0)
	{
		while (i < info->prec && str[i])
			len += ft_putchar(str[i++]);
	}
	return (len);
}

int	print_spec(va_list ap, t_info *info)
{
	int		len;
	char	spec;

	len = 0;
	spec = info->spec;
	if (spec == 'c')
		len = print_char(va_arg(ap, int), info);
	else if (spec == '%')
		len = print_char('%', info);
	else if (spec == 's')
		len = print_string(va_arg(ap, char *), info);
		/*
	else if (spec == 'd' || spec == 'i')
		len = print_nbr(va_arg(ap, int), info);
	else if (spec == 'x' || spec == 'X' || spec == 'u')
		len = print_nbr(va_arg(ap, unsigned int), info);
	else if (spec == 'p')
		len = print_nbr(va_arg(ap, unsigned long long), info);*/
	return (len);
}
