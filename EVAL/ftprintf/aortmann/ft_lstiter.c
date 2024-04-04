/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortmann <aortmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 06:21:01 by aortmann          #+#    #+#             */
/*   Updated: 2024/01/07 18:16:14 by aortmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node.*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;
	t_list	*next;

	current = lst;
	while (current != NULL)
	{
		next = current->next;
		f(current->content);
		current = next;
	}
}
