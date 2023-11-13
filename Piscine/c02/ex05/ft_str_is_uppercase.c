/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:01:29 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/01 15:23:18 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	int	i;
// 	char	only_upper[] = "UIAENRDXVLCHGQ";
// 	i = ft_str_is_uppercase(only_low);
// 	printf("only_upper:%d\n", i);
// 	char	mix[] = "uiaenNRDmb";
// 	i = ft_str_is_uppercase(mix);
// 	printf("mix:%i\n", i);
// 	return (0);
// }