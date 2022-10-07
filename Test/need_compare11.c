/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_compare11.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:54:24 by marvin            #+#    #+#             */
/*   Updated: 2022/08/14 22:54:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_eleven_first(t_list **la, t_index_b *idxs)
{
	int				i;
	int				y;
	int				save;

	i = 0;
	y = 0;
	save = (*la)->last;
	// if (save == 0 && (*la)->last2 != 0)
	// {
	// 	(*la)->last2 = save;
	// }
	det_pos_first(la, idxs);
	y = return_plus_petit(*idxs);
	i = do_op_ra_rra(la, idxs, y);
	//////printf("ft_taille == %d\n", ft_lstsize(*la));
	(*la)->last = save;
	////printf("voir\n");
	////printf("i retourne de nombre de ra ou rra == %d\n", i);
	return (i);
}

void	attribute_struct(t_list **la, t_index_b *idxs)
{
	// //////printf("entre ..\n");
	idxs->pos[0] = pos_min_cell(*la);
	// //////printf("ici\n");
	idxs->pos[1] = pos_second_min(*la);
	// //////printf("ici2\n");
	// //////printf("idxs->pos[2] == %d\n", idxs->pos[2]);
	// //////printf("pos third min -- %d\n", pos_third_min(*la));
	idxs->pos[2] = pos_third_min(*la);
	// //////printf("ici3\n");
	idxs->pos[3] = pos_four_min(*la);
	// //////printf("ici4\n");
	idxs->pos[4] = pos_five_min(*la);
	// //////printf("ici\n");
	idxs->pos[5] = pos_six_min(*la);
	if (ft_lstsize(*la) < 484)
	{
		// //////printf("ftlstsize == %d\n", ft_lstsize(*la));
		// //////printf("idxs->pos[1] == %d, seven firs == %d\n", idxs->pos[1], second_first_min(la));
		// ////char c;
		// ////read(0, &c, 1);
	}
	idxs->pos[6] = pos_seven_min(*la);
	// if (ft_lstsize(*la) < 484)
	// {
	// 	// //////printf("idxs->pos[6] == %d, seven firs == %d\n", idxs->pos[6], seven_first_min(la));
	// 	// ////char c;
	// 	// ////read(0, &c, 1);
	// }
	idxs->pos[7] = pos_eight_min(*la);
	idxs->pos[8] = pos_nine_min(*la);
	idxs->pos[9] = pos_ten_min(*la);
	idxs->pos[10] = pos_eleven_min(*la);
	idxs->dis[0] = dist_top_bottom_five(la, idxs->pos[0]);
	idxs->dis[1] = dist_top_bottom_five(la, idxs->pos[1]);
	idxs->dis[2] = dist_top_bottom_five(la, idxs->pos[2]);
	idxs->dis[3] = dist_top_bottom_five(la, idxs->pos[3]);
	idxs->dis[4] = dist_top_bottom_five(la, idxs->pos[4]);
	idxs->dis[5] = dist_top_bottom_five(la, idxs->pos[5]);
	idxs->dis[6] = dist_top_bottom_five(la, idxs->pos[6]);
	idxs->dis[7] = dist_top_bottom_five(la, idxs->pos[7]);
	idxs->dis[8] = dist_top_bottom_five(la, idxs->pos[8]);
	idxs->dis[9] = dist_top_bottom_five(la, idxs->pos[9]);
	idxs->dis[10] = dist_top_bottom_five(la, idxs->pos[10]);
	// //////printf("mais sors pas..\n");
}

void	det_pos_first(t_list **la, t_index_b *idxs)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (idxs->pos[i] <= ft_lstsize(*la) / 2)
			idxs->pos[i] = 1;
		else
			idxs->pos[i] = -1;
		i++;
	}
}

int	return_plus_petit(t_index_b idxs)
{
	int	i;

	i = 0;
	while (plus_petit(idxs, i) != 1)
		i++;
	// //////printf("i == %d\n", i);
	return (i);
}

int	plus_petit(t_index_b idxs, int index)
{
	int	j;

	j = 0;
	while (j < 11)
	{	
		if (j == index && j + 1 != 11)
			j++;
		if (idxs.dis[index] > idxs.dis[j])
			return (0);
		j++;
	}
	return (1);
}
