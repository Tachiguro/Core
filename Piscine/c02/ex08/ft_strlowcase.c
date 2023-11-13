/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:30:37 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/01 15:47:52 by jherzog          ###   ########.fr       */
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

// #include <stdio.h>
// int	main()
// {
// 	char	to_lower[] = "12346 5UIAENRDXVLCHGQ";
// 	char	*p_str;
// 	p_str = ft_strlowcase(to_lower);
// 	printf("p_str:%s\n", p_str);
// 	printf("to_lower:%s\n", to_lower);
// 	return (0);
// }