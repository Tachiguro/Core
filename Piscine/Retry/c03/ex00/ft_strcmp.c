/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:39:21 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/07 15:50:11 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	char	s1[] = "9876543210";
// 	char	s2[] = "9876543210";
// 	char	s3[] = "9870123456";
// 	int	i;
// 	printf("s1:%s\n", s1);
// 	printf("s2:%s\n", s2);
// 	i = ft_strcmp(s1, s2);
// 	printf("my_result :%i\n", i);
// 	i = strcmp(s1, s2);
// 	printf("org_result:%i\n", i);
// 	printf("s1:%s\n", s1);
// 	printf("s3:%s\n", s3);
// 	i = ft_strcmp(s1, s3);
// 	printf("my_result :%i\n", i);
// 	i = strcmp(s1, s3);
// 	printf("org_result:%i\n", i);
// 	printf("s1:%s\n", s1);
// 	printf("s3:%s\n", s3);
// 	i = ft_strcmp(s1, s3);
// 	printf("my_result :%i\n", i);
// 	i = strcmp(s1, s3);
// 	printf("org_result:%i\n", i);
// 	return (0);
// }