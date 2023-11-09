/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:03:49 by emirzaza          #+#    #+#             */
/*   Updated: 2023/05/22 21:36:23 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		arr[12];
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	while (n > 0)
	{
		arr[i++] = n % 10 + '0';
		n = n / 10;
	}
	while (i--)
		write(fd, &arr[i], 1);
}
