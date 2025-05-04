/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:33:19 by rnakatan          #+#    #+#             */
/*   Updated: 2025/05/05 00:35:43 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_ERROR_H
# define PH_ERROR_H

// enum

typedef enum e_ph_error_code
{
	PH_SUCCESS = 0,
	PH_VALID_ARG = 0,
	PH_INVALID_ARGC,
	PH_INVALID_ARGV_NOT_NUM,
	PH_INVALID_ARGV_OUT_OF_RANGE,
}	t_ph_error_code;

// constants
# define PH_ERROR_MSG_INVALID_ARGC "Error: Invalid number of arguments."
# define PH_ERROR_MSG_INVALID_ARGV_NOT_NUM "Error: Argument is not a number."
# define PH_ERROR_MSG_INVALID_ARGV_OUT_OF_RANGE \
			"Philo: Argument is out of range."
# define PH_ERROR_MSG_UNKNOWN "Error: Unknown Error."

// function

void	ph_print_error(t_ph_error_code error_code);

#endif