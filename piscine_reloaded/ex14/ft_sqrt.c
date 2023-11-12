/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:52:51 by jherzog           #+#    #+#             */
/*   Updated: 2023/11/12 14:57:45 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int			l;
	int			r;
	int			mid;
	long long	sq;

	l = 0;
	r = nb;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		sq = (long long)mid * (long long)mid;
		if (nb == sq)
			return (mid);
		else if (nb > sq)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return (0);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	i;
// 	i = INT_MAX;
// 	while (i > 0)
// 	{
// 		if (ft_sqrt(i) != 0)
// 			printf("sqrt: %d\n",ft_sqrt(i));
// 		i--;
// 	}

// 	return (0);
// }
