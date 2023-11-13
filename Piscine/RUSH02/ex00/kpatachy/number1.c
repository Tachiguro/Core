/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpatachy <kpatachy@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:29:17 by kpatachy          #+#    #+#             */
/*   Updated: 2023/02/12 15:39:10 by kpatachy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	three_dig_work(long short_number, int *counter);

int	cut_number(long number)
{
	int		counter;
	long	short_number;
	long	divider;

	counter = 4;
	divider = 1000000000;
	while (counter > 0)
	{
		short_number = number / divider;
		if (short_number > 0)
			three_dig_work(short_number, &counter);
		counter--;
		divider /= 1000;
	}
	return (1);
}

int	three_dig_work(long short_number, int *counter)
{
	long	hundreds;
	long	tens;
	long	units;

	if (short_number > 999)
		short_number %= 1000;
	hundreds = short_number / 100;
	if (hundreds > 1)
		printf("%li hundreds ", hundreds);
	else if (hundreds == 1)
		printf("%li hundred ", hundreds);
	tens = short_number % 100 / 10 * 10;
	units = short_number % 10;
	if (tens >= 10)
	{
		printf("%li ", tens);
		if (tens != 10 && units > 0 && units <= 9)
			printf("%li", units);
	}
	else if (tens == 0)
		printf("%li", units);
	if (*counter == 2)
		printf(" thousands "); //int thousands from dict
	else if (*counter == 3)
		printf(" millions "); //int millions from dict
	else if (*counter == 4)
		printf(" billions "); //int millions from dict
	return (1);
}


int	main(void)
{
	long	number;
	
	number = 1111111;
	cut_number(number);
	printf("\n");
}