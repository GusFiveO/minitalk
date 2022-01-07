/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <alorain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:58:55 by alorain           #+#    #+#             */
/*   Updated: 2022/01/03 18:22:12 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

typedef struct s_printf
{
	int		minus;
	int		plus;
	int		zero;
	int		diez;
	int		dot;
	int		space;
	int		count;
	char	type;

}		t_printf;

int	ft_printf(const char *str, ...);

#endif