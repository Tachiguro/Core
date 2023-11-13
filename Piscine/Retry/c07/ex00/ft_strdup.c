/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 02:52:45 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/14 02:30:21 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	while (src[i] != '\0')
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	src[] = "This is a Test!";
// 	char	*new_str;
// 	new_str = ft_strdup(src);
// 	printf("src    :%s\n", src);
// 	printf("new_str:%s\n", new_str);
// 	printf("src    :%p\n", src);
// 	printf("new_str:%p\n", new_str);
// 	char	*src1 = "This is a Test!";
// 	char	*new_str1;
// 	new_str1 = strdup(src1);
// 	printf("src    :%s\n", src1);
// 	printf("new_str:%s\n", new_str1);
// 	printf("src    :%p\n", src1);
// 	printf("new_str:%p\n", new_str1);
// 	free(new_str);
// 	free(new_str1);
// 	return (0);
// }