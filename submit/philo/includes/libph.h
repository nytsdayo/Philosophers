/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:57:43 by rnakatan          #+#    #+#             */
/*   Updated: 2025/05/04 21:40:36 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPH_H
# define LIBPH_H

# include <stddef.h>

size_t	ph_strlen(const char *str);
long	ph_atol(const char *nptr);
void	ph_putendl_fd(const char *str, int fd);
#endif