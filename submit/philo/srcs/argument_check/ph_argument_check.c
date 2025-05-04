/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_argument_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:58:29 by rnakatan          #+#    #+#             */
/*   Updated: 2025/05/05 06:34:33 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argument_check.h"
#include "ph_error.h"
#include <stdbool.h>
#include "libph.h"

static bool	ph_is_valid_argc(const int argc);
static bool	ph_is_value_num(const char *argv[]);
static bool	ph_is_value_range(const char *argv[]);

int	ph_argument_check(const int argc,const char **argv)
{
	if (ph_is_valid_argc(argc) == false)
		return (PH_INVALID_ARGC);
	if (ph_is_value_num(argv) == false)
		return (PH_INVALID_ARGV_NOT_NUM);
	if (ph_is_value_range(argv) == false)
		return (PH_INVALID_ARGV_OUT_OF_RANGE);
	return (VALID_ARG);
}

static bool	ph_is_valid_argc(const int argc)
{
	return (argc == 5 || argc == 6);
}

static bool	ph_is_value_num(const char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ph_atol(argv[i]) == 0 && argv[i][0] != '0')
			return (false);
		i++;
	}
	return (true);
}

static bool	ph_is_value_range(const char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ph_atol(argv[i]) < ARG_RANGE_MIN
			|| ph_atol(argv[i]) > ARG_RANGE_MAX)
			return (false);
		i++;
	}
	return (true);
}
