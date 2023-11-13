/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:43:56 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/07 15:50:27 by jherzog          ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	pos_dest;
	int	pos_src;

	pos_src = 0;
	pos_dest = ft_strlen(dest);
	while (src[pos_src] != '\0')
	{
		dest[pos_dest] = src[pos_src];
		pos_src++;
		pos_dest++;
	}
	dest[pos_dest] = '\0';
	return (dest);
}

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char	src[] = "0123456";
// 	char	dest[] = "abcde";
// 	char	src1[] = "0123456";
// 	char	dest1[] = "abcde";
// 	char	*test;
// 	test = ft_strcat(dest, src);
// 	printf("my_result :%s\n", dest);
// 	test = strcat(dest1, src1);
// 	printf("org_result:%s\n", dest1);
// 	return (0);
// }