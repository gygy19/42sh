/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:46:32 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:17:52 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CHAR_H
# define GET_CHAR_H

# include "printf/printf.h"

# include <wchar.h>

char			arg_get_char(t_printf *t);
unsigned char	arg_get_uchar(t_printf *t);
wchar_t			arg_get_wchar(t_printf *t);

#endif
