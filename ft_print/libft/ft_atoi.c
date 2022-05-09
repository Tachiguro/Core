/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:32:36 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/09 15:22:15 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long	i;
	char	*s;
	long	result;
	int		sign;

	sign = 1;
	s = (char *)str;
	result = 0;
	i = 0;
	while (((s[i] >= 9) && (s[i] <= 13)) || (s[i] == 32))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] < 48 || s[i] > 57)
			return (sign * result);
		result = result * 10 + s[i] - 48;
		i++;
	}
	return (sign * result);
}
