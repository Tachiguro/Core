/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:57:53 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/15 18:19:39 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		found_char;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			found_char = i;
			while ((to_find[j] == str[i]))
			{
				j++;
				i++;
			}
			if (to_find[j] == '\0' || str[i] == '\0')
				return (&str[found_char]);
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char	*str;
	char	*p_result;
	p_result = strstr("", str);
	printf("org_result:%s\n", p_result);
	p_result = ft_strstr(str, str);
	printf("my_result :%s\n", p_result);
	return (0);
}