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
