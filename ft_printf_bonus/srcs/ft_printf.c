/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:08:55 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/04 15:09:10 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_treat_flags(va_list ap, t_flags fl)
{
	int	j;

	j = 0;
	while (fl.set[j] && ft_strchr)
}

static void	ft_parse(va_list ap, const char *format, int *len, int *i)
{
	t_info	fl;
	
	while (ft_is_in_str(SPECS, format[*i]))
	{
		if (format[*i])
	}


}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (fotmat[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i++], 1);
			len++;
		}
		else
		{
			i++;
			ft_parse(args, format, &len, &i);
			if (len == -1)
				return (-1);
		}
	}
	va_end(ap);
	return (len);
}
