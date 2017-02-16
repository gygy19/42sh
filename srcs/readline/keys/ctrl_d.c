/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblet <mblet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 06:47:20 by mblet             #+#    #+#             */
/*   Updated: 2016/05/17 18:39:04 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	readline_key_ctrl_d(void)
{
	if (sgt_readline()->buffer != NULL && sgt_readline()->buffer[0] != '\0')
		return ;
	sgt_readline()->exit = true;
	ft_strdel(&sgt_readline()->buffer);
	sgt_readline()->buffer = ft_strdup("exit");
	readline_refresh_line();
}
