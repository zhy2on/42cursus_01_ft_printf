/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:30:18 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/17 17:30:20 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, t_info *info)
{
	int	len;

	len = 0;
	if (info->sepc == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		len += ft_putchar(c);
	len += put_width(info->width, 1, info->zero);
	if (info->minus == 0)
		len += ft_putchar(c);
	return (len);
}

int	put_width(int width, int len, int zero)
{
	int	ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
		{
			ft_putchar(' ');
			len++;
			ret++;
		}
	}
	return (ret);
}
