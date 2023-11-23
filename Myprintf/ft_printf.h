/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 21:03:54 by rshaheen      #+#    #+#                 */
/*   Updated: 2023/11/17 20:15:29 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdint.h>
# include <limits.h>
# include "./libft/libft.h"

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);

void	ft_c(char c, size_t *counter);
void	ft_str(char *str, size_t *counter);
void	ft_num(int num, size_t *counter);
void	ft_unsign(unsigned int num, size_t *counter);
void	ft_hex(unsigned long long num, size_t *counter, char *base);
void	ft_pointer(void *ptr, size_t *counter);

char	*ft_convert(unsigned long n, char *base);

#endif