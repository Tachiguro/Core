/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:34:13 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/09 13:41:05 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft\libft.h"

int main ()
{
  int a = 12;

  int *p = &a;

	ft_printf("char:%c string:%s decimal:%d int:%i x:%x, X:%X %%\n p:%p\n", 'c', "string", -12, 7, 31, 63, p);
	printf("char:%c string:%s decimal:%d int:%i x:%x, X:%X %%\n p:%p\n", 'c', "string", -12, 7, 31, 63, p);
	return (0);
}
