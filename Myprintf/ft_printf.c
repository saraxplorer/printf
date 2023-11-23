/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 17:29:36 by rshaheen      #+#    #+#                 */
/*   Updated: 2023/11/22 20:45:52 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_c(va_arg(va, int), counter);
	else if (*str == 's')
		ft_str(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_pointer(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_num(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_unsign(va_arg(va, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_hex(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
		else if (*str == 'X')
			ft_hex(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
	}
	else if (*str == '%')
		ft_c(*str, counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &counter);
		}
		else
			ft_c(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}

int	main(void)
{
 char *s = "hello";
 ft_printf("%s\n", s);
 printf("%s\n", s);
 char ch = 'A';
 ft_printf("%c\n", ch);
 printf("%c\n", ch);
 int num = -42;
 ft_printf("Intiger: %d\n", num);
 printf("realInteger: %d\n", num);
 void *ptr = (void*)0x0;
    ft_printf("Pointer: %p\n", ptr);
	printf("realPointer: %p\n", ptr);
unsigned int u_num = 123;
    ft_printf("Unsigned Integer: %u\n", u_num);
	printf("realUnsigned Integer: %u\n", u_num);
unsigned int hex_num = 255;
    ft_printf("Hexadecimal low: %x\n", hex_num);
	printf("real Hexadecimal low: %x\n", hex_num);
unsigned int hex_UP = 12345;
    ft_printf("Uppercase Hexadecimal up: %X\n", hex_UP);
	printf("real Hexadecimal up: %x\n", hex_UP);
 return 0;
}

// //cc ft_printf.c ft_c.c ft_str.c ft_num.c ft_unsign.c ft_hex.c ft_pointer.c ft_convert.c -o ft_printf -I./libft -L./libft -lft
//./ft_printf
// or make then cc ft_printf.c libftprintf.a then ./a.out
