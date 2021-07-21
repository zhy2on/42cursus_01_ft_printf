/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:23:59 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/17 18:24:01 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
