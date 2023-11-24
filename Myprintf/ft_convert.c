/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 13:47:20 by rshaheen      #+#    #+#                 */
/*   Updated: 2023/11/24 19:23:10 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

char	*ft_convert_helper(unsigned long n, char *base, char *hex, int len)
{
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n > 0)
	{
		len--;
		if (ft_strncmp(base, HEX_UPP_BASE, 16) == 0)
			str[len] = HEX_UPP_BASE[n % ft_strlen(base)];
		else
			str[len] = hex[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (str);
}

char	*ft_convert(unsigned long n, char *base)
{
	char			*hex;
	int				len;
	unsigned long	temp;

	hex = "0123456789abcdef";
	if (n == 0)
		return (strdup("0"));
	len = 0;
	temp = n;
	while (temp > 0 && ++len)
		temp /= ft_strlen(base);
	return (ft_convert_helper(n, base, hex, len));
}
