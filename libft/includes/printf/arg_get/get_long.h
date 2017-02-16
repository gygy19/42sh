/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:46:45 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 10:19:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_LONG_H
# define GET_LONG_H

# include "printf/printf.h"

unsigned long			arg_get_ulong(t_printf *t);
long int				arg_get_long_int(t_printf *t);
unsigned long int		arg_get_ulong_int(t_printf *t);
long long int			arg_get_long_long_int(t_printf *t);
unsigned long long int	arg_get_ulong_long_int(t_printf *t);

#endif
