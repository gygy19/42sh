/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 04:08:29 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/19 16:54:38 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>
#include <sh.h>
#include <signal.h>

void	resize(int sig)
{
	if (sig != SIGWINCH)
		return ;
	readline_signal_resize();
}

void	ctrlc(int sig)
{
	if (sig != SIGINT)
		return ;
	if (!g_signal_ctrlc)
		readline_signal_ctrl_c();
	else if (sgt_sh()->in_current_process)
		sgt_sh()->in_current_process = 0;
	else
		readline_signal_ctrl_c();
}

void	ctrlz(int sig)
{
	if (sig != SIGTSTP)
		return ;
}
