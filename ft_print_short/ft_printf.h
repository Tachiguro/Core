/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:21:11 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/12 22:57:17 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
char	*ft_ultoh(unsigned long number);
int		ft_print_u(va_list args);
int		ft_print_pointer(va_list args);
int		ft_print_hex(va_list args, int is_upper);
int		ft_print_int(va_list args);
int		ft_print_string(va_list args);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
int		ft_toupper(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
