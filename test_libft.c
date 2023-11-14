/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:58:34 by jherzog           #+#    #+#             */
/*   Updated: 2023/11/14 18:48:42 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"

int	main(void)
{
	t_list	*list;
	t_list	*temp;

	list = ft_lstnew("Test1");
	printf("Content: %s, Next: %p\n", (char *)list->content, list->next);

	ft_lstadd_front(&list, ft_lstnew("Test0"));
	printf("ft_lstadd_front: New front: %s\n", (char *)list->content);

	ft_lstadd_back(&list, ft_lstnew("Test2"));
	temp = ft_lstlast(list);
	printf("ft_lstadd_back: New back: %s\n", (char *)temp->content);

	printf("ft_lstsize: Size of list: %d\n", ft_lstsize(temp));

	temp = list;
	printf("List contents: ");
	while (temp != NULL)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	return (0);
}
