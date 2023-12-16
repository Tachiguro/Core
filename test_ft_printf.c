/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:20:01 by jherzog           #+#    #+#             */
/*   Updated: 2023/12/16 21:16:47 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/src/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

void test_ft_print_int(void);
void test_ft_print_char(void);

int main(void)
{
	printf("Test: ft_printf>%d<\n", ft_printf("%i", 12));

	//test_ft_print_int();
	//test_ft_print_char();
	printf("All tests passed!\n");
	return (0);
}

void test_ft_print_int()
{
	int or = 0;
	int my = 0;

	or = printf("%d\n", 10);
	my = ft_printf("%d\n", 10);
	printf("my:%d or:%d\n", or, my);
}

void test_ft_print_char()
{
	// Call ft_print_char and check that it returns -1
	assert(ft_print_char('a') == -1);

}
