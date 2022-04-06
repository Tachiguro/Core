/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:39:57 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/08 14:59:44 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*	Function: ft_isalpha													  */
/*	--------------------													  */
/*	The isalpha() function checks whether a character is an alphabet or not.  */
/*																			  */
/*  c: character to be checked												  */
/*	return: Non-zero value if the character is an alphabetic character,		  */
/*		zero otherwise.														  */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
