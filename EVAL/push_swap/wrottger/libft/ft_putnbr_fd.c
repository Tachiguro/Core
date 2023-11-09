/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:30:41 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/23 08:38:39 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

static void	print_char_number(char *arr, int fd)
{
	int	i;

	if (arr[0] == '-')
		ft_putchar(fd, '-');
	i = 1;
	while (arr[i] == '0')
		i++;
	while (i < 12)
	{
		ft_putchar(fd, arr[i]);
		i++;
	}
}

static int	handle_special_cases(int n, int fd)
{
	if (n == 0)
	{
		ft_putchar(fd, '0');
		return (1);
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		current_digit;
	int		i;
	char	arr[12];

	if (handle_special_cases(n, fd))
		return ;
	if (n < 0)
	{
		arr[0] = '-';
		n = -1 * n;
	}
	else
		arr[0] = '0';
	i = 11;
	while (i)
	{
		current_digit = n % 10;
		arr[i] = current_digit + '0';
		n = n / 10;
		i--;
	}
	print_char_number(arr, fd);
}
