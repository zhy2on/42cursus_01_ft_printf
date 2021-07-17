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

int	put_width_str(char **buf, t_info *info)
{
	char	*width_buf;
	char	*tmp;
	int		i;

	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	width_buf = (char *)malloc(sizeof(char) * (info->width - ft_strlen(*buf) + 1));
	i = 0;
	while ((size_t)i < info->width - ft_strlen(*buf))
	{
		if (info->zero == 1)
			width_buf[i++] = '0';
		else
			width_buf[i++] = ' ';
	}
	width_buf[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(width, *buf);
	else
		*buf = ft_strjoin(*buf, width_buf);
	return (info->width);
}

int	print_string(char *str, t_info *info)
{
	int		len;
	char	*buf;

	len = 0;
	if (!str)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	len = put_width_str(&buf, info);
	ft_putstr(buf);
	free(buf);
	return (len);
}
