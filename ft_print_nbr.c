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
	else if (info->plus && info->pad_c != '0')
		ret += ft_putchar('+');
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

void	set_nbr_info_sub(unsigned long long nbr, t_info *info)
{
	info->nbr_len = nbr_base_len(nbr, info);
	if (info->prec > -1 || info->minus)
		info->pad_c = ' ';
	if ((nbr || info->prec)
		&& (info->prec == -1 || info->prec < info->nbr_len))
		info->prec = info->nbr_len;
	info->width -= info->prec;
	if (info->nbr_sign < 0 || info->plus)
		info->width--;
	if (info->spec == 'p' || info->hex_c)
		info->width -= 2;
}

void	set_nbr_info(unsigned long long nbr, t_info *info)
{
	if ((info->spec == 'd' || info->spec == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		info->sign_c = '-';
		info->space = 0;
	}
	if (info->spec != 'd' && info->spec != 'i')
	{
		info->plus = 0;
		info->space = 0;
	}
	if (((info->spec != 'x' && info->spec != 'X') || nbr == 0)
		&& info->spec != 'p')
		info->hex_c = '\0';
	if (info->hex_c && info->spec == 'X')
		info->hex_c = 'X';
	if (info->spec == 'x' || info->spec == 'p')
		info->nbr_base = HEXA;
	else if (info->spec == 'X')
		info->nbr_base = HEXXA;
	set_nbr_info_sub(nbr, info);
}

int	print_nbr(unsigned long long nbr, t_info *info)
{
	int	ret;

	ret = 0;
	set_nbr_info(nbr, info);
	if (info->space && (info->width <= 0))
	{
		ret += ft_putchar(' ');
		info->width--;
	}
	if ((info->minus || info->pad_c == '0') && (info->hex_c))
		ret += ft_putchar('0') + ft_putchar(info->hex_c);
	if (info->minus && (nbr || info->prec))
		ret += put_nbr_base(nbr, info);
	if ((info->nbr_sign < 0 || info->plus) && info->pad_c == '0')
		ret += ft_putchar(info->sign_c);
	while (info->width-- > 0)
		ret += ft_putchar(info->pad_c);
	if (!(info->minus || info->pad_c == '0') && (info->hex_c))
		ret += ft_putchar('0') + ft_putchar(info->hex_c);
	if (!info->minus && (nbr || info->prec))
		ret += put_nbr_base(nbr, info);
	return (ret);
}
