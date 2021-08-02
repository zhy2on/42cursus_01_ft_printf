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

void	put_nbr_sub(unsigned long long nbr, char *base, int len, int *ret)
{
	if (!nbr)
		return ;
	put_nbr_sub(nbr / len, base, len, ret);
	*ret += ft_putchar(base[nbr % len]);
}

int	put_nbr_base(unsigned long long nbr, t_info *info)
{
	int		len;
	int		ret;

	ret = 0;
	len = ft_strlen(info->nbr_base);
	if (info->nbr_sign < 0)
	{
		if (info->pad_c != '0')
			ret += ft_putchar('-');
		nbr *= -1;
	}
	if (info->prec > -1)
	{
		while (info->prec-- > info->nbr_len)
			ret += ft_putchar('0');
	}
	if (!nbr)
		return (ret + ft_putchar('0'));
	put_nbr_sub(nbr, info->nbr_base, len, &ret);
	return (ret);
}

void	set_nbr_info(unsigned long long nbr, t_info *info)
{
	if ((info->spec == 'd' || info->spec == 'i') && (int)nbr < 0)
		info->nbr_sign = -1;
	if (info->spec == 'x' || info->spec == 'p')
		info->nbr_base = HEXA;
	else if (info->spec == 'X')
		info->nbr_base = HEXXA;
	info->nbr_len = nbr_base_len(nbr, info);
	if (info->prec > -1 || info->minus)
		info->pad_c = ' ';
	if (info->prec == -1 || info->prec < info->nbr_len)
		info->prec = info->nbr_len;
	info->width -= info->prec;
	if (info->nbr_sign < 0)
		info->width--;
	if (info->spec == 'p')
		info->width -= 2;
}

int	print_nbr(unsigned long long nbr, t_info *info)
{
	int	ret;

	ret = 0;
	set_nbr_info(nbr, info);
	if ((info->minus || info->pad_c == '0') && info->spec == 'p')
		ret += ft_putchar('0') + ft_putchar('x');
	if (info->minus)
		ret += put_nbr_base(nbr, info);
	if (info->nbr_sign < 0 && info->pad_c == '0')
		ret += ft_putchar('-');
	while (info->width-- > 0)
		ret += ft_putchar(info->pad_c);
	if (!(info->minus || info->pad_c == '0') && info->spec == 'p')
		ret += ft_putchar('0') + ft_putchar('x');
	if (!info->minus)
		ret += put_nbr_base(nbr, info);
	return (ret);
}
