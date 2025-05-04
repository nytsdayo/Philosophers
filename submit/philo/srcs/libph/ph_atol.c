/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:12:55 by rnakatan          #+#    #+#             */
/*   Updated: 2025/05/04 21:38:53 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libph.h"
#include <limits.h>

static int	overflow(int mnsflag, long res, const char c);
static int	jugde_flag(char nptr);

long	ph_atol(const char *nptr)
{
	int		i;
	int		mnsflag;
	long	res;

	i = 0;
	res = 0;
	mnsflag = 1;
	while (nptr[i] >= 9 && nptr[i] <= 13)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		mnsflag = jugde_flag(nptr[i++]);
	while (nptr[i] == '0')
		i++;
	if ((nptr[i] < '0' && nptr[i] > '9') || nptr[i] == '0')
		return (0);
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (overflow(mnsflag, res, nptr[i]) == 0)
			return (0);
		else if (overflow(mnsflag, res, nptr[i]) == -1)
			return (-1);
		res = res * 10 + (nptr[i++] - '0');
	}
	return (res * mnsflag);
}

static int	overflow(int mnsflag, long res, const char c)
{
	if ((res * mnsflag > LONG_MAX / 10 || (res * mnsflag == LONG_MAX / 10 && (c
					- '0') > LONG_MAX - res * mnsflag * 10)) || res
		* mnsflag < LONG_MIN / 10 || (res * mnsflag == LONG_MIN / 10 && -(c
				- '0') < LONG_MIN - res * mnsflag * 10))
	{
		if (mnsflag == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

static int	jugde_flag(char nptr)
{
	if (nptr == '-')
		return (-1);
	else
		return (1);
}

