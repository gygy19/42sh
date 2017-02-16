/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:43:50 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:31:43 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_STRING_H
# define TO_STRING_H

# include "printf/printf.h"

void	to_string(t_printf *t, char *s);
void	to_char(t_printf *t, char c);
void	to_wchar(t_printf *t, wchar_t c);

#endif
