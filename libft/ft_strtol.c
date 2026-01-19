/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:18:21 by jsantini          #+#    #+#             */
/*   Updated: 2026/01/19 15:04:25 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

static int	check_sign(char **str)
{
	if (**str == '-' || **str == '+')
	{
		(*str)++;
		if (*((*str) - 1) == '-')
			return (-1);
	}
	return (1);
}

static long	do_return(long fin, int digit, int sign, char *str)
{
	if ((fin * sign) - digit == -2147483648 && *str == '\0')
		return (-2147483648);
	if (sign == -1)
		return (LONG_MIN);
	return (LONG_MAX);
}

long	ft_strtol(char *str, char **endp)
{
	long	fin;
	int		sign;
	int		digit;

	while (ft_isspace(*str))
		str++;
	fin = 0;
	sign = check_sign(&str);
	while (ft_isdigit(*str))
	{
		fin *= 10;
		digit = *str - '0';
		str++;
		if (fin > (INT_MAX - digit))
		{
			if (endp)
				*endp = str;
			return (do_return(fin, digit, sign, str));
		}
		fin += digit;
	}
	return (fin * sign);
}
/*
int	main(int c, char **v)
{
	long	i;

	(void)c;
	i = ft_strtol(v[1], NULL);
}*/
