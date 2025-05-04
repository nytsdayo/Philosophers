/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:59:05 by rnakatan          #+#    #+#             */
/*   Updated: 2025/05/04 21:30:35 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_CHECK_H
# define ARGUMENT_CHECK_H

// structure
typedef struct s_cmd_argument
{
	int		argc;
	char	*argv[];
}	t_cmd_argumnent;

// enum
typedef enum e_arg_check_status
{
	VALID_ARG,
	INVALID_ARGC,
	INVALID_ARGV,
}	t_arg_check_status;

// constants
# define ARG_RANGE_MIN 1
# define ARG_RANGE_MAX 2147483647

// function
int	ph_argument_check(const int argc, const char **argv);

#endif