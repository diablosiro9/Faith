/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:25:30 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/03 18:02:24 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_b	*init_struct_b(t_index_b *idxs)
{	
	int	i;

	i = 0;
	idxs = malloc(sizeof(t_index_b) * 1);
	if (!idxs)
		return (NULL);
	while (i < 11)
	{
		idxs->dis[i] = 0;
		idxs->pos[i] = 0;
		i++;
	}
	idxs->i = 0;
	idxs->j = 0;
	idxs->y = 0;
	idxs->z = 0;
	idxs->o = 0;
	idxs->save = 0;
	idxs->next_move = 0;
	idxs->last = 0;
	idxs->last2 = 0;
	return (idxs);
}

int	is_tri(t_list **sta)
{
	t_list	*tmp;

	tmp = (*sta);
	while (tmp->next != NULL)
	{
		if (tmp->next != NULL
			&& tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_tri_reverse(t_list **sta)
{
	t_list	*tmp;

	tmp = (*sta);
	while (tmp->next != NULL)
	{
		if (tmp->next != NULL
			&& tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	return_data(t_list *l, int pos)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!l || i > pos)
		return (0);
	tmp = l;
	while (tmp && i < pos)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->data);
}
