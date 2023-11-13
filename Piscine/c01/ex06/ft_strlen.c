/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:53:11 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/29 01:58:39 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int i;
// 	char text[] = "This is a text"; // 14
// 	i = ft_strlen(text);
// 	printf("%i\n", i);
// }