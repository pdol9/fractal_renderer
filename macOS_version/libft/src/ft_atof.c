/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:19:17 by pdolinar          #+#    #+#             */
/*   Updated: 2022/07/17 21:14:38 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static
int	return_pos(const char *string, int *sign)
{
	int	i;

	i = 0;
	while ((string[i] == ' ') || (string[i] == '\t') || (string[i] == '\n')
		|| (string[i] == '\v') || (string[i] == '\r') || (string[i] == '\f'))
		i++;
	if (string[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (string[i] == '+')
		i++;
	return (i);
}

static
double	return_fraction(const char *string, int i)
{
	double	frac;
	int		len;
	int		j;

	len = 0;
	j = i;
	while (string[j++])
		len++;
	frac = 0;
	while (string[i] >= '0' && string[i] <= '9')
	{
		frac = frac * 10 + (string[i] - '0');
		i++;
	}
	while (len--)
		frac /= 10;
	return (frac);
}

/* return the sum of a whole and decimal-fraction number == double */
double	ft_atof(const char *string)
{
	int		whole;
	int		sign;
	int		i;

	if (string == NULL)
		return (0);
	whole = 0;
	sign = 1;
	i = return_pos(string, &sign);
	while (string[i] >= '0' && string[i] <= '9' && string[i] != '.')
	{
		whole = whole * 10 + (string[i] - '0');
		i++;
	}
	if (string[i] == '.')
		i++;
	return (sign * (whole + return_fraction(string, i)));
}
