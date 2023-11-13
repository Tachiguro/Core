/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 04:37:47 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/06 22:51:38 by jherzog          ###   ########.fr       */
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

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	temp;

	start = 0;
	while (size > start)
	{
		temp = tab[start];
		tab[start] = tab[size - 1];
		tab[size - 1] = temp;
		size--;
		start++;
	}
}

void	ft_print_nbr(int nb, int len, int neg)
{
	int		i;
	int		arr[10];
	char	c;

	i = -1;
	while (i++ < len - 1)
	{
		arr[i] = (nb % 10);
		nb /= 10;
	}
	ft_rev_int_tab(arr, len);
	if (neg == 1)
		write(1, "-", 1);
	i = -1;
	while (i++ < len - 1)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
	}
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

// #include <stdio.h>
// int	main(void)
// {
// 	ft_putnbr(-123456789);
// 	write(1, "\n", 1);
// 	return (0);
// }