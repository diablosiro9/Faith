/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_eleven_minus_i.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:12:34 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_eleven_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == eleven_first_min(&l))
			return (i);
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

int	eleven_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = ten_first_min(la);
	j = 0;
	tmp = (*la);
	k = tmp->data;
	while (tmp)
	{
		j = tmp->data;
		if (j > i && j < k)
			k = j;
		tmp = tmp->next;
	}
	return (k);
}

void	i_minus_j(t_list **lb, t_index idxs)
{
	if (idxs.i && idxs.j)
	{
		if (idxs.i <= idxs.j && idxs.z != -1)
		{
			idxs.z = idxs.i;
			while (idxs.i)
			{
				rb(lb);
				// //////printf("dingue\n");
				idxs.i--;
			}
			// //////printf("hunder armor\n");
		}
	}
}

void	j_minus_i(t_list **lb, t_index *idxs)
{
	idxs->y = idxs->j;
	while (idxs->j)
	{
		rrb(lb);
		// //////printf("o\n");
		idxs->j--;
	}
}

t_index	*init_struct(t_index *idxs)
{	
	idxs = malloc(sizeof(t_index) * 1);
	if (!idxs)
		return (NULL);
	idxs->i = 0;
	idxs->j = 0;
	idxs->y = 0;
	idxs->z = 0;
	idxs->o = 0;
	return (idxs);
}
