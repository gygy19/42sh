/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr_to_str.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 20:08:37 by mblet             #+#    #+#             */
/*   Updated: 2016/05/10 21:42:27 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WSTR_TO_STR_H
# define WSTR_TO_STR_H

# include "printf.h"

# include <wchar.h>

char	*wstr_to_str(t_printf *t, wchar_t *s);

#endif
