/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:44:24 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/08 01:15:06 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	if ((str[i] >= 'a' && str[i] <= 'z') && (i == 0))
	{
		str[i] -= 32;
	}
	while (str[i] != '\0')
	{
		if (!(str[i - 1] >= '0' && str[i - 1] <= '9')
			&& !(str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			&& !(str[i - 1] >= 'a' && str[i - 1] <= 'z')
			&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	to_u_f[] = "saLut, tu vas ? 42mots qUarante-deux; cinquante+et+un";
// 	char	*p_str;
// 	printf("to_u_f:%s\n", to_u_f);
// 	p_str = ft_strcapitalize(to_u_f);
// 	printf("p_str:%s\n", p_str);
// 	return (0);
// }