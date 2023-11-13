/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:44:23 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/03 00:30:28 by jherzog          ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				pos_dest;
	unsigned int	pos_src;

	pos_src = 0;
	pos_dest = ft_strlen(dest);
	while (src[pos_src] != '\0' && pos_src < nb)
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
// 	test = ft_strncat(dest, src, 5);
// 	printf("my_result :%s\n", dest);
// 	test = strncat(dest1, src1, 5);
// 	printf("org_result:%s\n", dest1);
// 	return (0);
// }