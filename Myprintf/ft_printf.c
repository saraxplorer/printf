/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 17:29:36 by rshaheen      #+#    #+#                 */
/*   Updated: 2023/12/04 20:41:38 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list ap, char *str, size_t *counter)
{

	if (*str == 'c')
		ft_c(va_arg(ap, int), counter);
	else if (*str == 's')
		ft_str(va_arg(ap, char *), counter);
	else if (*str == 'p')
		ft_pointer(va_arg(ap, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_num(va_arg(ap, int), counter);
	else if (*str == 'u')
		ft_unsign(va_arg(ap, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'X')
			ft_hex(va_arg(ap, unsigned int), counter, HEX_UPP_BASE);
		if (*str == 'x')
			ft_hex(va_arg(ap, unsigned int), counter, HEX_LOW_BASE);
	}
	else if (*str == '%')
	{
		ft_c(*str, counter);
		str++;
		if (*str == '%')
		{
			int percent = 0;
			while (*str == '%')
			{
				percent++;
				str++;
			}
			if (percent % 2 != 0)
			{
				str -= percent;
				ft_c(*str, counter);
				str ++;
				ft_c(*str, counter);
			}
		}

	}
		
}
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(ap, (char *)str, &counter);
			if (*str == '\0')
				return (-1);
		}
		else
			ft_c(*str, &counter);
		str++;
	}
	va_end(ap);
	return (counter);
}
