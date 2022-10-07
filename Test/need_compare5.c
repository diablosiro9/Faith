/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_compare5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:48:32 by dojannin          #+#    #+#             */
/*   Updated: 2022/08/18 20:52:50 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare_five_first(t_list **la)
{
	t_index_f		*idxs;
	int				i;
	int				y;

	i = 0;
	y = 0;
	idxs = malloc(sizeof(t_index_f) * 1);
	attribute_struct_cent(la, idxs);
	det_pos_first_cent(la, idxs);
	y = return_plus_petit_cent(*idxs);
	do_op_ra_rra_cent(la, idxs, y);
}

void	attribute_struct_cent(t_list **la, t_index_f *idxs)
{
	idxs->pos[0] = pos_min_cell(*la);
	idxs->pos[1] = pos_second_min(*la);
	idxs->pos[2] = pos_third_min(*la);
	idxs->pos[3] = pos_four_min(*la);
	idxs->pos[4] = pos_five_min(*la);
	idxs->dis[0] = dist_top_bottom_five(la, idxs->pos[0]);
	idxs->dis[1] = dist_top_bottom_five(la, idxs->pos[1]);
	idxs->dis[2] = dist_top_bottom_five(la, idxs->pos[2]);
	idxs->dis[3] = dist_top_bottom_five(la, idxs->pos[3]);
	idxs->dis[4] = dist_top_bottom_five(la, idxs->pos[4]);
}

void	det_pos_first_cent(t_list **la, t_index_f *idxs)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (idxs->pos[i] <= ft_lstsize(*la) / 2)
			idxs->pos[i] = 1;
		else
			idxs->pos[i] = -1;
		i++;
	}
}

int	return_plus_petit_cent(t_index_f idxs)
{
	int	i;

	i = 0;
	while (plus_petit_cent(idxs, i) != 1)
		i++;
	return (i);
}

int	plus_petit_cent(t_index_f idxs, int index)
{
	int	j;

	j = 0;
	while (j < 5)
	{	
		if (j == index && j + 1 != 5)
			j++;
		if (idxs.dis[index] > idxs.dis[j])
			return (0);
		j++;
	}
	return (1);
}
