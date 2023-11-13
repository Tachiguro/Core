/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:49:34 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/01 19:15:44 by jherzog          ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(src);
	if (size <= 0)
		return (len);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

// #include <stdio.h>
// int	main()
// {
// 	char	src[] = "012345uiaeuiae";
// 	char	dest[] = "9876543210";
// 	int	i;
// 	printf("dest:%s\n", dest);
// 	i = ft_strlcpy(dest, src, 32);
// 	printf("dest:%s\n", dest);
// 	printf("dest:%i\n", i);
// 	return (0);
// }