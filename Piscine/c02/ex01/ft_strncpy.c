/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:23:44 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/02 01:41:03 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// int	main()
// {
// 	char	src[] = "0123456";
// 	char	dest[] = "9876543210";
// 	printf("dest:%s\n", dest);
// 	ft_strncpy(dest, src, 7);
// 	printf("dest:%s\n", dest);
// 	return (0);
// }