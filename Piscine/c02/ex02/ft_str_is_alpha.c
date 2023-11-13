/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:29:54 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/01 15:22:42 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] < 'A') || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	int	i;
// 	char	only_alpha[] = "auiaenrtdzAUIAENRDZ";
// 	i = ft_str_is_alpha(only_alpha);
// 	printf("only_alpha:%d\n", i);
// 	char	mix[] = "a1uiae.nrt dzAUI():-A\\/{}ENRDZ";
// 	i = ft_str_is_alpha(mix);
// 	printf("mix:%i\n", i);
// 	char	nothing[] = "";
// 	i = ft_str_is_alpha(nothing);
// 	printf("mix:%i\n", i);
// 	return (0);
// }