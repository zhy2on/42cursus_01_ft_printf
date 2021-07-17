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

char	*parse_buf(char *str, int end, int len)
{
	int		i;
	char	*buf;

	if (end >= len)
		end = len;
	buf = (char *)malloc(sizeof(char) * (end + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < end)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}