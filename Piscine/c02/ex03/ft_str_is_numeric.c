/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:52:43 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/01 15:23:02 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] < '0') || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	int	i;
// 	char	only_numb[] = "0123456789";
// 	i = ft_str_is_numeric(only_numb);
// 	printf("only_numb:%d\n", i);
// 	char	mix[] = "( //01\\\\a23 456b7r8t9)";
// 	i = ft_str_is_numeric(mix);
// 	printf("mix:%i\n", i);
// 	return (0);
// }