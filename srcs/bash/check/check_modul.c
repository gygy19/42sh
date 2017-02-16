/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:01:23 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/20 17:01:25 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			final_bash_check(int *tab)
{
	int error;

	error = 0;
	if (tab[0] != tab[3] || tab[0] != tab[4])
	{
		ft_printf("While ");
		error = 1;
	}
	if (tab[1] != tab[2] || tab[1] != tab[5])
	{
		ft_printf("if ");
		error = 1;
	}
	if (error == 1)
	{
		ft_printf("Error syntax\n");
		return (0);
	}
	return (1);
}

int			check_modul(char *code)
{
	int *tab;
	int	i;

	tab = (int[10]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	i = -1;
	while (code[++i])
	{
		if (!ft_strncmp(code + i, "while", 5))
			tab[0]++;
		else if (!ft_strncmp(code + i, "if", 2))
			tab[1]++;
		else if (!ft_strncmp(code + i, "fi", 2))
			tab[2]++;
		else if (!ft_strncmp(code + i, "done", 4))
			tab[3]++;
		else if (!ft_strncmp(code + i, "do", 2))
			tab[4]++;
		else if (!ft_strncmp(code + i, "then", 4))
			tab[5]++;
	}
	return (final_bash_check(tab));
}
