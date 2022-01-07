/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:37:20 by alorain           #+#    #+#             */
/*   Updated: 2021/12/12 17:00:44 by augustinlor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <unistd.h>
# include "ft_printf.h"

	/*ft_printf_utils.c*/

void	ft_putchar(char c);
void	ft_putstr(char *str, int len);
void	ft_putnbr(int n);
size_t	is_in(char c, char *str);	
void	ft_putnbr_base(unsigned long n, char *base);

	/* parser.c */

size_t	parse_flags(const char *str, t_printf *flag);

	/* buffer.c */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 120
# endif

size_t	manage_buff(char *str, size_t n);
void	write_buff(char *str, size_t n);

	/* print_arg.c */

void	print_arg(t_printf *flag, va_list vl);

	/* print_arg2.c */

void	manage_char(t_printf *flag, char c);
void	manage_string(t_printf *flag, char *str);
void	print_char(char c, int n);

	/*utils.c*/

size_t	count_digit_base(int n, int base_len);
size_t	count_digit_base_un(unsigned long n, size_t base_len);
int		reg_len(t_printf *flag, char *str);
void	reg_dot(t_printf *flag, int nb_digits, long nbr);

	/*print_arg_utils.c*/

void	manage_0_dot(t_printf *flag);
void	manage_diez(t_printf *flag, int nbr);
void	manage_prefix(t_printf *flag, int nbr);
void	manage_percent(t_printf *flag);
#endif
