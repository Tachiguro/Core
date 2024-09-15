/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:30:29 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 19:34:15 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_print_char(char c)
{
	int	counter;

	counter = 0;
	counter = write(1, &c, 1);
	if (counter == -1)
		return (-1);
	return (counter);
}