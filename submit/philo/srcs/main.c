/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:36:01 by rnakatan          #+#    #+#             */
/*   Updated: 2025/05/05 06:42:09 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argument_check.h"
#include "ph_error.h"
#include "libph.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		ret;

	ret = ph_argument_check(argc, (const char**)argv);
	if (ret != PH_VALID_ARG)
	{
		ph_print_error(ret);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
