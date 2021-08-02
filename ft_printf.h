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
# include "./libft/libft.h"

# define SPECS "csdiupxX%"
# define DECI "0123456789"
# define HEXA "0123456789abcdef"
# define HEXXA "0123456789ABCDEF"

typedef struct s_info
{
	int		minus;
	char	pad_c;
	char	spec;
	int		width;
	int		prec;
	char	*nbr_base;
	int		nbr_len;
	int		nbr_sign;
}			t_info;

/*
*** FT_PRINTF ****
*/

int		ft_printf(const char *format, ...);
int		parse_format(va_list ap, char *format);
void	init_info(t_info *info);
void	check_info(char *format, t_info *info);
int		print_spec(va_list ap, t_info *info);

/*
*** FT_PRINT %c, %s ***
*/
int		print_char(int c, t_info *info);
int		print_string(char *str, t_info *info);

/*
*** FT_PRINT %d, %u, %x, %X ***
*/
int		print_nbr(unsigned long long nbr, t_info *info);
void	set_nbr_info(unsigned long long nbr, t_info *info);
int		put_nbr_base(unsigned long long nbr, t_info *info);
void	put_nbr_sub(unsigned long long nbr, char *base, int len, int *ret);
int		nbr_base_len(unsigned long long nbr, t_info *info);

#endif