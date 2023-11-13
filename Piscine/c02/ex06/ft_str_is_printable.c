/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:09:32 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/03 10:04:46 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	int	i;
// 	char	only_printable[] = "12346 5UIAENRDXVLCHGQ";
// 	i = ft_str_is_printable(only_printable);
// 	printf("only_printable:%d\n", i);
// 	char	mix[] = "\a\b\t\n\vuiaenNRDmb";
// 	i = ft_str_is_printable(mix);
// 	printf("mix:%i\n", i);
// 	return (0);
// }