/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_bash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:42:32 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 10:42:34 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_bash			*create_sig_bash(t_bash *left, t_bash *father, int type)
{
	t_bash *baby;

	if (!(baby = (t_bash *)malloc(sizeof(t_bash))))
		return (NULL);
	baby->start = -1;
	baby->end = -1;
	baby->father = father;
	baby->child = NULL;
	baby->left = left;
	baby->next = NULL;
	baby->type = type;
	baby->boucle = 0;
	return (baby);
}

t_bash			*end_child_bash(void)
{
	t_bash *op;

	op = sig_bash();
	while (op->child)
		op = op->child;
	return (op);
}

t_bash			*end_next_bash(void)
{
	t_bash *op;

	op = sig_bash();
	while (op->next)
		op = op->next;
	return (op);
}

t_bash			*current_bash(t_bash *bash)
{
	static t_bash *op;

	if (bash == NULL)
		return (op);
	op = bash;
	return (NULL);
}

t_bash			*sig_bash(void)
{
	static t_bash	*op = NULL;

	if (op == NULL)
		op = create_sig_bash(NULL, NULL, 0);
	return (op);
}
