/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 13:47:20 by rshaheen      #+#    #+#                 */
/*   Updated: 2023/11/22 16:33:21 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

char	*ft_convert(unsigned long n, char *base)
{
	char	*str;
	char	*hex;

	hex = "0123456789abcdef";
	if (n == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	int len = 0;
	unsigned long temp = n;

	while (temp > 0)
	{
		temp /= ft_strlen(base);
		len++;
	}

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);

	str[len] = '\0';

	while (n > 0)
	{
		len--;
		str[len] = hex[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}

	return (str);
}
