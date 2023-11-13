/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:57:23 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/01 15:23:13 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	int	i;
// 	char	only_low[] = "uiaenrdxvlchgqpzmb";
// 	i = ft_str_is_lowercase(only_low);
// 	printf("only_low:%d\n", i);
// 	char	mix[] = "uiaenrdxvlchgqpAzmb";
// 	i = ft_str_is_lowercase(mix);
// 	printf("mix:%i\n", i);
// 	return (0);
// }