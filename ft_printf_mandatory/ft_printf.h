/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:26:02 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/16 16:27:04 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"

# define SPECS "csdiupxX%"

typedef struct s_info
{
	int		minus;
	int		zero;
	char	spec;
	int		width;
	int		prec;
	int		nbr_base;
	int		nbr_sign;
}			t_info;

/*
*** FT_PRINTF ****
*/

int		ft_printf(const char *format, ...);
int		parse_format(va_list ap, char *format);
void	init_info(t_info *info);
void	check_info(va_list ap, char *format, t_info *info, int i);
void	check_width_and_prec(va_list ap, char *format, t_info *info, int i);