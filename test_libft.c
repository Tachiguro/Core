/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:58:34 by jherzog           #+#    #+#             */
/*   Updated: 2023/12/07 15:09:00 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"

int	main(void)
{
	t_list	*numbers;
	int		n;
	int		f;
	int		b;

	n = 5;
	f = 4;
	b = 6;

	numbers = ft_lstnew(&n);
	printf("New:%d Size:%d\n", *(int *)numbers->content, ft_lstsize(numbers));

	ft_lstadd_front(&numbers, ft_lstnew(&f));
	printf("New:%d Size:%d\n", *(int *)numbers->content, ft_lstsize(numbers));

	ft_lstadd_back(&numbers, ft_lstnew(&b));
	printf("New:%d Size:%d\n", *(int *)ft_lstlast(numbers)->content, ft_lstsize(numbers));


	return (0);
}
