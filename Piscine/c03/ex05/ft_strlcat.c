/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:15:40 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/07 15:50:45 by jherzog          ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	pos_dest;
	unsigned int	pos_src;
	unsigned int	i;

	i = 0;
	pos_dest = ft_strlen(dest);
	pos_src = ft_strlen(src);
	while (src[i] != '\0' && i < (size - pos_dest - 1))
	{
		dest[pos_dest + i] = src[i];
		i++;
	}
	dest[pos_dest + i] = '\0';
	return (pos_dest + pos_src);
}

// #include <stdio.h>
// #include <bsd/string.h> // cc ft_strlcat.c -lbsd
// int	main()
// {
// 	char	src[] = "1";
// 	char	dest[100] = "abcde";
// 	int		i;
// 	i = ft_strlcat(dest, src, 10);
// 	printf("dest:%s\nsrc:%s len%d\n", dest, src, i);
// 	char	src1[] = "1";
// 	char	dest1[100] = "abcde";
// 	i = strlcat(dest1, src1, 10);
// 	printf("dest:%s\nsrc:%s len%d\n", dest1, src1, i);
// 	return (0);
// }