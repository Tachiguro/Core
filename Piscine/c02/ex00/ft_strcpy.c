/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:00:11 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/31 20:19:33 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// int	main()
// {
// 	char	src[] = "0123456";
// 	char	dest[] = "9876543210";
// 	printf("dest:%s\n", dest);
// 	ft_strcpy(dest, src);
// 	printf("dest:%s\n", dest);
// 	return (0);
// }