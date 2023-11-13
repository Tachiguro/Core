/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:01:56 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/16 17:43:28 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

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

void	ft_print_nbr(int nb, int len, int neg)
{
	char	arr[11];
	int		i;

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}

// int	main(int argc, char **argv)
// {
// 	struct	s_stock_str	*t_stc;
// 	t_stc = ft_strs_to_tab(argc, argv);

// 	ft_show_tab(t_stc);
// 	free(t_stc);
// 	return (0);
// }