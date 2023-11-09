/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:52:51 by jherzog           #+#    #+#             */
/*   Updated: 2023/11/10 00:39:43 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	l;
	int	r;
	int	mid;

	l = 0;
	r = nb;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (nb == mid * mid)
			return (mid);
		else if (nb > mid * mid)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return (0);
}

//     if ((long long)(l - 1) * (long long)(l - 1) == nb) {
//         return l - 1;
//     }

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	i;
// 	i = INT_MAX;
// 	printf("sqrt: %d i: %d\n", ft_sqrt(i), i);
// 	return (0);
// }
