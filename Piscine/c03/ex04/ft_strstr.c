/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:57:53 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/15 17:30:30 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		cnt_str;
	int		cnt_to_find;
	int		found_char;

	cnt_str = 0;
	cnt_to_find = 0;
	if (to_find[cnt_to_find] == '\0')
		return (str);
	while (str[cnt_str] != '\0')
	{
		cnt_to_find = 0;
		if (str[cnt_str] == to_find[cnt_to_find])
		{
			found_char = cnt_str;
			while (to_find[cnt_to_find] == str[cnt_str])
			{
				cnt_to_find++;
				cnt_str++;
			}
			if (to_find[cnt_to_find] == '\0')
				return (&str[found_char]);
		}
		cnt_str++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char	str[];
	char	to_find[] = "TeST";
	char	*p_result;
	printf("str:%s\n", str);
	printf("to_find:%s\n", to_find);
	p_result = ft_strstr("TEST", NULL);
	printf("my_result :%s\n", p_result);
	p_result = strstr(str, to_find);
	printf("org_result:%s\n", p_result);
	return (0);
}