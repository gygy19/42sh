/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:33:39 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/18 09:36:28 by mblet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef struct			s_st
{
	int				fd[2];
	int				fd2[2];
	int				in;
	int				out;
}						t_st;

typedef struct			s_tree
{
	char				*cmd;
	char				**args;
	short				prio;
	struct s_tree		*right;
	struct s_tree		*left;
	char				*full_path;
	int					pid;
	int					status;
	struct s_st			st;
	int					action;
	short				type;
	short				error;
	short				sub;
}						t_tree;

#endif
