/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:36:24 by rnakatan          #+#    #+#             */
/*   Updated: 2025/05/05 00:32:56 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ph_error.h"
#include "libph.h"


static void	_ph_print_error(const char *error_msg);

void	ph_print_error(t_ph_error_code error_code)
{
	const char	*error_msg;

	if (error_code == PH_INVALID_ARGC)
		error_msg = PH_ERROR_MSG_INVALID_ARGC;
	else if (error_code == PH_INVALID_ARGV_NOT_NUM)
		error_msg = PH_ERROR_MSG_INVALID_ARGV_NOT_NUM;
	else if (error_code == PH_INVALID_ARGV_OUT_OF_RANGE)
		error_msg = PH_ERROR_MSG_INVALID_ARGV_OUT_OF_RANGE;
	else
		error_msg = PH_ERROR_MSG_UNKNOWN;
	_ph_print_error(error_msg);
}

static void	_ph_print_error(const char *error_msg)
{
	ph_putendl_fd(error_msg, 2);
}


