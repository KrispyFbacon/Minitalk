/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:47:12 by frbranda          #+#    #+#             */
/*   Updated: 2024/07/25 12:28:06 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstr_pf(char *s, int fd);
int		ft_putchar_pf(char c, int fd);
int		ft_putnbr_pf(long n, int fd);
int		get_len_nbr(long n);
int		ft_putnbr_base(unsigned int n, unsigned int base, char *digits);
int		ft_putnbr_base_p(unsigned long n, unsigned int base, char *digits);

#endif