/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:55:22 by rnakatan          #+#    #+#             */
/*   Updated: 2025/05/04 21:43:55 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libph.h"

void	ph_putendl_fd(const char *str, int fd)
{
	if (str)
	{
		write(fd, str, ph_strlen(str));
		write(fd, "\n", 1);
	}
}
