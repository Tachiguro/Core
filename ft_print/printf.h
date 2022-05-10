/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:21:11 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/10 15:52:27 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
char	*ft_ultoh(unsigned long number);
int		ft_print_u(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_hex(va_list args);
int		ft_print_int(va_list args);
int		ft_print_string(va_list args);
int		ft_prit_char(va_list args);

#endif
