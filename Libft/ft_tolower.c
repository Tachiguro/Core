/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:14:22 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/08 15:43:11 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*  Function: ft_tolower                                                      */
/*  --------------------                                                      */
/*  The ft_tolower() function Converts the given character to lovercase.      */
/*                                                                            */
/*  c: Character to be converted.                                             */
/*  return: Converted character or ch if no lovercase version.                */
/* ************************************************************************** */
int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		return (c + 32);
	}
	return (c);
}
