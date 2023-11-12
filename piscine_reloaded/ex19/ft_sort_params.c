/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:26:43 by jherzog           #+#    #+#             */
/*   Updated: 2023/11/12 17:54:03 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_putchar(char c);
static void	ft_putstr(char *str);
static int	ft_strcmp(char *s1, char *s2);
static void	ft_sort_str_arr(char **arr, int n);
static void	ft_swap_str(char **s1, char **s2);

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc <= 1)
		return (1);
	ft_sort_str_arr(argv, argc);
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
	}
	return (0);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

static int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	ft_swap_str(char **s1, char **s2)
{
	char	*s_temp;

	s_temp = *s1;
	*s1 = *s2;
	*s2 = s_temp;
}

static void	ft_sort_str_arr(char **arr, int n)
{
	int	fin;
	int	i;

	fin = 0;
	while (fin == 0)
	{
		fin = 1;
		i = 0;
		while (++i < n -1)
		{
			if (ft_strcmp(arr[i - 1], arr[i]) > 0)
			{
				ft_swap_str(&arr[i -1], &arr[i]);
				fin = 0;
			}
		}
	}
}
