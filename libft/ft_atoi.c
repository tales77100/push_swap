/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:37:54 by jsantini          #+#    #+#             */
/*   Updated: 2025/11/05 10:38:30 by jsantini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			final;
	int			neg;

	final = 0;
	neg = 1;
	while (*nptr == ' ' || (*nptr <= 13 && *nptr >= 9))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg *= -1;
		nptr++;
	}
	while (*nptr <= '9' && *nptr >= '0')
	{
		final *= 10;
		final += (*nptr - '0');
		nptr++;
	}
	return (final * neg);
}
