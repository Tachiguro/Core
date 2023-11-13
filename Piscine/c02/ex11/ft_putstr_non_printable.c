/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:51:36 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/02 01:33:10 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char symb)
{
	char	c;

	if (symb >= 0 && symb <= 9)
	{
		c = '0' + symb;
		write(1, &c, 1);
		return ;
	}
	c = 'a' + symb - 10;
	write(1, &c, 1);
}

void	check_hex(char np_char)
{
	char	hex_1;
	char	hex_2;

	hex_1 = np_char / 16;
	hex_2 = np_char % 16;
	print_hex(hex_1);
	print_hex(hex_2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			check_hex(str[i]);
		}
		i++;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[] = "Coucou\ntu v \tas b \nien?";
// 	ft_putstr_non_printable(str);
// 	write(1, "\n", 1);
// 	return (0);
// }