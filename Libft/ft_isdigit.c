/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:41:32 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/08 15:20:27 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*  Function: ft_isdigit                                                      */
/*  --------------------                                                      */
/*  The isdigit() function checks whether a character is an digit or not.     */
/*                                                                            */
/*  c: character to be checked                                                */
/*  return: Non-zero value if the c is a digit, zero otherwise.               */
/* ************************************************************************** */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
