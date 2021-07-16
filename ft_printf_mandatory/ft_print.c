/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:14:57 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/16 17:14:59 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(va_list ap, t_info *info)
{
	int		len;
	char	type;

	len = 0;
	type = info->type;
	if (type == 'c')
		len = print_char(va_arg(ap, int), info);
	else if (type == '%')
		len = print_char('%', info);
	else if (type == 's')
		len = print_string(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		len = print_nbr(va_arg(ap, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		len = print_nbr(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		len = print_nbr(va_arg(ap, unsigned long long), info);
	return (len);
}
