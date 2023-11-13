/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 05:38:43 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/16 17:36:45 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_num_lengh(int nb)
{
	int	counter;

	counter = 0;
	while (nb > 0)
	{
		nb /= 10;
		counter++;
	}
	return (counter);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_nbr(int nb, int len, int neg)
{
	char	arr[11];
	int		i;
	char	c;

	i = 0;
	arr[len] = '\0';
	while (--len >= 0)
	{
		arr[len] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	if (neg == 1)
		write(1, "-", 1);
	ft_putstr(arr);
}

void	ft_putnbr(int nb)
{
	int	negative;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	negative = 0;
	if (nb < 0)
	{
		negative++;
		nb *= (-1);
	}
	ft_print_nbr(nb, ft_num_lengh(nb), negative);
}

int	main(void)
{
	ft_putnbr(321654);
	write(1, "\n", 1);
	return (0);
}