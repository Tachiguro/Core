/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameltsen <ameltsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:33:32 by ameltsen          #+#    #+#             */
/*   Updated: 2023/02/12 10:38:19 by ameltsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int arr_char(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}


// #include <stdio.h>

// int only_numbers(char *str);

// int main(void)
// {
//     char str1[] = "123456";
//     char str2[] = "1234abc";
//     char str3[] = "";

//     printf("%d\n", arr_char(str1)); // Output: 1
//     printf("%d\n", arr_char(str2)); // Output: 0
//     printf("%d\n", arr_char(str3)); // Output: 1

//     return 0;
// }