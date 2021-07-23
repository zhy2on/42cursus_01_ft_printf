/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:21:23 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/21 20:21:26 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_base_len(unsigned long long nbr, int base)
{
	int	i;

	if (!nbr)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

void	put_nbr_sub(unsigned long long nbr, char *base, int len, int *ret)
{
	if (!nbr)
		return ;
	put_nbr_sub(nbr / len, base, len, ret);
	*ret += ft_putchar(base[nbr % len]);
}

int	print_nbr_prec(t_info *info)
{
	int ret;

	ret = 0;
	if (info->prec > -1)
	{
		while (info->prec-- > info->nbr_len)
			ret += ft_putchar('0');
	}
	return (ret);
}

int	put_nbr_base(unsigned long long nbr, t_info *info)
{
	int		len;
	int		ret;
	char	c;

	ret = 0;
	len = ft_strlen(info->nbr_base);
	if (nbr < 0)
	{
		ret += ft_putchar('-');
		ret += print_nbr_prec(info);
		put_nbr_sub(-(nbr / len), info->nbr_base, len, &ret);
		c = base[-(nbr % len)];
	}
	else
	{
		ret += print_nbr_prec(info);
		put_nbr_sub(nbr / len, info->nbr_base, len, &ret);
		c = base[nbr % len];
	}
	ret += ft_putchar(c);
	return (ret);
}

int	print_nbr(unsigned long long nbr, t_info *info)
{
	int	ret;

	ret = 0;
	if (info->spec == 'x' || info->spec == 'p')
		info->nbr_base = HEXA;
	if (info->spec == 'X' )
		info->nbr_base = HEXXA;
	if (info->spec == 'd' || info->spec == 'i')
	{
		info->nbr_len = nbr_base_len(nbr, 10);
		info->nbr_base = DECI;
	}
	if (info->prec > -1 || info->minus)
		info->pad_c = ' ';
	if (info->prec == -1 || info->prec < info->nbr_len)
		info->prec = info->nbr_len;
	info->width -= info->prec;
	if (info->minus)
		ret += put_nbr_base(nbr, info);
	while (info->width--)
		ret += ft_putchar(info->pad_c);
	if (!info->minus)
		ret += put_nbr_base(nbr, info);
	return (ret);
}
