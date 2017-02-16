/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:42:37 by mblet             #+#    #+#             */
/*   Updated: 2016/03/29 15:20:53 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INI_PRINTF_H
# define INI_PRINTF_H

# include "printf/printf.h"

t_printf	*ini_printf(void);
void		ini_flags(t_printf *t);

#endif
