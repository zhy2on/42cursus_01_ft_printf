/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:09:34 by jihoh             #+#    #+#             */
/*   Updated: 2021/07/04 15:10:07 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# define FLAGS "-+#0 "
# define ALL_FLAGS "-+#0 *.0123456789lh"
# define SPECS "cspdiuxX%onfge"

typedef struct s_info
{
	char	spe_c;
	char	pad_c;
	char	minus;
	char	plus;
	char	hash;
	char	space;
	int		width;
	char	point;
	int		precision;
	int		length;
}				t_info;

/*
** ft_printf_utils.c
*/
int	ft_is_in_str(char *s, char c);