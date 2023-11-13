/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:23:33 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/03 00:31:43 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
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
// 	i = ft_strncmp(s1, s2, 10);
// 	printf("my_result:%i\n", i);
// 	i = strncmp(s1, s2, 10);
// 	printf("org_result:%i\n", i);
// 	printf("s1:%s\n", s1);
// 	printf("s3:%s\n", s3);
// 	i = ft_strncmp(s1, s3, 10);
// 	printf("result:%i\n", i);
// 	i = strncmp(s1, s3, 10);
// 	printf("org_result:%i\n", i);
// 	printf("s1:%s\n", s1);
// 	printf("s3:%s\n", s3);
// 	i = ft_strncmp(s1, s3, 4);
// 	printf("result:%i\n", i);
// 	i = strncmp(s1, s3, 4);
// 	printf("org_result:%i\n", i);
// 	return (0);
// }