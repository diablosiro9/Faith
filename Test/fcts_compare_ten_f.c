/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_compare_ten_f.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:12:31 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_ten_first(t_list **la, t_list **lb, t_index_b *idxs)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (ft_lstsize(*lb) < 500)
	{
		////printf("on se suit\n");
		////printf("la last == %dd\n", (*la)->last2);
		attribute_struct_ten(la, idxs);
		////printf("on se separe\n");
		det_pos_first_ten(la, idxs);
		////printf("ici\n");
		////printf("la data == %d\n", (*la)->data);
		////printf("taille de la entree compare == %d\n", ft_lstsize(*la));
		y = return_plus_petit_ten(la, *idxs);
		////printf("maintenant\n");
		////printf("y == %d\n", y);
		idxs->save = det(la, y);
		// //////printf("idxs->y ten first == %d\n", idxs->dis[y]);
		//////printf("la last compare-ten == %d\n", (*la)->last);
		// //////printf("lb avant ra ten -- %d\n", (*lb)->data);
		if (idxs->pos[y] == -1)
			idxs->dis[y] *= -1;
		// try_something(la, lb, (*la)->last);
		// //////printf("la last entre deux == %d\n", (*la)->last);
		i = do_op_ra_rra_ten(la, lb, idxs, y);
		// //////printf("lb apres ra ten -- %d\n", (*lb)->data);
		if (idxs->pos[y] == -1)
			i *= -1;
	}
	////printf("dernier i === %d\n", i);
	if (is_tri_reverse(lb) == 1)
	{
		if (idxs->save > (*lb)->data)
		{
			if (i >= 0)
			{
				while (i > 0)
				{
					ra(la);
					i--;
				}
			}
			else
			{
				while (i < 0)
				{
					rra(la);
					i++;
				}
			}
		}
		(*la)->last = 0;
	}
	////printf("LAAA LASSTERIIX == %d\n", (*la)->last);
	////printf("LAAA222 LASSTERIIX == %d\n", (*la)->last2);
	// if (ft_lstsize(*lb) > 140){ 
	// char c;
	// read(0, &c, 1);
	// }
	//////printf("la last fin compare-ten == %d\n", (*la)->last);
	return (i);
}

void	attribute_struct_ten(t_list **la, t_index_b *idxs)
{
	idxs->pos[0] = pos_min_cell(*la);
	////printf("2 == %d\n", third_first_min(la));
	idxs->pos[1] = pos_second_min(*la);
	idxs->pos[2] = pos_third_min(*la);
	idxs->pos[3] = pos_four_min(*la);
	idxs->pos[4] = pos_five_min(*la);
	idxs->pos[5] = pos_six_min(*la);
	////printf("5 === %d\n", five_first_min(la));
	////printf("6 ===== %d\n", six_first_min(la));
	idxs->pos[6] = pos_seven_min(*la);
	idxs->pos[7] = pos_eight_min(*la);
	idxs->pos[8] = pos_nine_min(*la);
	idxs->pos[9] = pos_ten_min(*la);
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
}

void	det_pos_first_ten(t_list **la, t_index_b *idxs)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (idxs->pos[i] <= ft_lstsize(*la) / 2)
			idxs->pos[i] = 1;
		else
			idxs->pos[i] = -1;
		i++;
	}
}

int	return_plus_petit_ten(t_list **la, t_index_b idxs)
{
	int	i;

	// ////printf("wsh\n");
	i = 0;
	// ////printf("ok\n");
	while (plus_petit_ten(la, idxs, i) != 1)
	{
		i++;
		// ////printf("i == %d\n", i);
	}
	////printf("i ====== %d\n", i);
	return (i);
}

int	plus_petit_ten(t_list **la, t_index_b idxs, int index)
{
	int	j;
	int i;

	i = 0;
	j = 0;
	// ////printf("nice\n");
	// ////printf("la->data == %d\n", (*la)->data);
	// ////printf("la last  == %d\n", (*la)->last);
	if (!(*la)->last) 
	{	
		// ////printf("attention\n");
		while (j < 10)
		{	
			// ////printf("index == %d\n", index);
			// ////printf("j == %d\n", j);
			if (j == index && j + 1 != 10)
				j++;
			// ////printf("idxs.dis[index] == %d\n", idxs.dis[index]);
			// ////printf("idxs.dis[j] == %d\n", idxs.dis[j]);
			if (idxs.dis[index] > idxs.dis[j])
				return (0);
			j++;
		}
		return (1);
	}
	if ((*la)->last != 0)
	{
		if ((*la)->last > 0)
		{
			while (idxs.pos[i])
			{
				if (idxs.pos[i] == 1)
				{
					while (j < 10)
					{
						if (j == index && j + 1 != 10)
							j++;
						if (idxs.dis[index] > idxs.dis[j])
							return (0);
						else 
							j++;
					}
					return (1);
				}
				i++;
			}
		}
		else
		{
			while (idxs.pos[i])
			{
				if (idxs.pos[i] == -1)
				{
					while (j < 10)
					{
						if (j == index && j + 1 != 10)
							j++;
						if (idxs.dis[index] > idxs.dis[j])
							return (0);
						else
							j++;
					}
				}
				i++;
			}
		}
	}
	// while (j < 10)
	// {	
	// 	if (j == index && j + 1 != 10)
	// 		j++;
	// 	if (idxs.dis[index] > idxs.dis[j])
	// 		return (0);
	// 	j++;
	// }
	return (1);
}
