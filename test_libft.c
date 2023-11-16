/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:58:34 by jherzog           #+#    #+#             */
/*   Updated: 2023/11/16 13:59:20 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./libft/libft.h"

void	del(void *content);

int	main(void)
{
	t_list	*list;
	t_list	*temp;
	t_list	*third;

	list = ft_lstnew("TEST1");
	ft_lstadd_back(&list, ft_lstnew("TEST2"));
	ft_lstadd_front(&list, ft_lstnew("TEST0"));
	ft_lstadd_back(&list, ft_lstnew("TEST3"));

	printf("Size:%d\n", ft_lstsize(list));

	printf("List contents after creating: \n");
	temp = list;
	while (temp != NULL) {
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");

	// Example of deleting a node, e.g., the second node
	temp = list->next; // Get the second node
	list->next = temp->next; // Adjust the 'next' pointer of the first node

	ft_lstdelone(temp, del); // Delete the second node

	printf("List contents at the end: \n");
	temp = list; // Reset the temporary pointer
	while (temp != NULL) {
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	return (0);
}

void	del(void *content)
{
	free(content);
}
