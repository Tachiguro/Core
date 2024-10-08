/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:58:46 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/09 20:15:45 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_int(int n);
int		ft_print_uint(unsigned int n);
int		ft_print_hex(unsigned int n, char begin);
int		ft_print_ptr(unsigned long n);
#endif
