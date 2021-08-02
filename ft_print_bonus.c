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

int	nbr_base_len(unsigned long long nbr, t_info *info)
{
	int	i;
	int	n;

	if (!nbr)
		return (1);
	if (info->nbr_sign < 0)
		nbr *= -1;
	i = 0;
	n = ft_strlen(info->nbr_base);
	while (nbr)
	{
		nbr /= n;
		i++;
	}
	return (i);
}

int	print_char(int c, t_info *info)
{
	int	ret;

	ret = 0;
	if (info->spec == '%' && info->minus == 1)
		info->pad_c = ' ';
	if (info->minus)
		ret += ft_putchar(c);
	while (info->width-- > 1)
		ret += ft_putchar(info->pad_c);
	if (!info->minus)
		ret += ft_putchar(c);
	return (ret);
}

int	print_string(char *str, t_info *info)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	if (!str)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	if (info->minus)
	{
		info->pad_c = ' ';
		while (i < info->prec && str[i])
			ret += ft_putchar(str[i++]);
	}
	while (info->width-- > info->prec)
		ret += ft_putchar(info->pad_c);
	if (!info->minus)
	{
		while (i < info->prec && str[i])
			ret += ft_putchar(str[i++]);
	}
	return (ret);
}
