/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:38:03 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	y_minus_z(t_list **lb, t_index *idxs)
{
	idxs->i = 0;
	while (idxs->i != idxs->y)
	{
		rb(lb);
		idxs->i++;
	}
	rb(lb);
	// //////printf("got trouble\n");
	return (idxs->y);
}

void	z_minus_y(t_list **lb, t_index *idxs)
{
	idxs->i = 0;
	if (idxs->z != -1)
	{
		while (idxs->i != idxs->z)
		{
			rrb(lb);
			// //////printf("l\n");
			idxs->i++;
		}
	}
}

int	case_less_one(t_list **la, t_list **lb)
{
	if (!la || !lb)
		return (-1);
	if (top_la_inf_lb(la, lb) == -1)
		return (-1);
	return (0);
}

int	finish_func(t_list **la, t_list **lb, t_index *idxs)
{
	if (idxs->z != -1)
		idxs->z = idxs->i;
	if ((idxs->z != 0 && idxs->z != -1) || idxs->y != 0)
	{
		// if (ft_lstsize(*lb) > 2)
		// 	//////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
		pb(lb, la);
		//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
		////char c;
		////read(0, &c, 1);
	}
	if (idxs->y <= idxs->z && idxs->y != 0 && (idxs->z != 0 && idxs->z != -1))
	{
		idxs->y = y_minus_z(lb, idxs);
		return (idxs->y);
	}
	else
		z_minus_y(lb, idxs);
	return (idxs->z);
}

void	choose_minus(t_list **lb, t_index *idxs)
{
	if (idxs->i <= idxs->j && idxs->z != -1)
		i_minus_j(lb, *idxs);
	else if (idxs->j <= idxs->i && idxs->z != -1)
		j_minus_i(lb, idxs);
}
