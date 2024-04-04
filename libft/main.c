/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:48:58 by jherzog           #+#    #+#             */
/*   Updated: 2024/04/04 11:56:55 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	del(void *content)
{
	free(content);
}

void	*increment(void *content)
{
	int	*new_content;

	new_content = malloc(sizeof(int));
	if (!new_content)
		return ;
	*new_content = *(int *)content + 1;
	return (new_content);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*new_lst;
	int		*content;
	int		i;
	int		arr[3];

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	i = 0;
	lst = NULL;
	new_lst = NULL;
	content = NULL;
	while (++i < 5)
	{
		content = malloc(sizeof(int));
		*content = arr[i];
		ft_lstadd_back(&lst, ft_lstnew(content));
	}
	new_lst = ft_lstmap(lst, increment, del);
	print_list(new_lst);
	ft_lstclear(&lst, del);
	ft_lstclear(&new_lst, del);
	return (0);
}
