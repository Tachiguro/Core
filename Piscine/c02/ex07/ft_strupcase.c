/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:16:55 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/01 19:17:58 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int	main()
// {
// 	char	to_upper[] = "n1r2dtrn3t drn4dtrn6 uidatrnduitae";
// 	char	*p_str;
// 	p_str = ft_strupcase(to_upper);
// 	printf("p_str:%s\n", p_str);
// 	printf("to_upper:%s\n", to_upper);
// 	return (0);
// }