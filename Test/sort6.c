/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:09:47 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_for_real(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	if (swap_is_okay(la, lb, idxs) == -100)
	{
		swap_ten_last_equal(la, res);
		// if (ft_lstsize(*lb) > 2)
		// 	//////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
		pb(lb, la);
		//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
		//char c;
		//read(0, &c, 1);
		//////char c;
		//////read(0, &c, 1);
		sb(lb);
		idxs->o = -100;
	}
	else if (ft_lstsize(*lb) >= 1 && ft_lstsize(*la) >= 1 && idxs->o != -100)
	{
		idxs->i = check_before_rb(lb, idxs);
		if (ft_lstsize(*lb) >= 3)
			idxs->j = check_before_rrb(lb, idxs) - 1;
		////printf("idxs->i == %d, idxs->j == %d\n", idxs->i, idxs->j);
	}
	idxs->z = idxs->i;
	idxs->y = idxs->j;
	do_op(la, lb, idxs, res);
}

int	swap_is_okay(t_list **la, t_list **lb, t_index_b *idxs)
{
	////printf("tu enres]\n");
	if (idxs->save < (*lb)->data && idxs->save > (*lb)->next->data)
		idxs->o = -100;
	else if (idxs->save < (*la)->last2 && idxs->save > (*la)->last3)
		idxs->o = -100;
	if (idxs->save < (*lb)->data && idxs->save > (*lb)->next->data)
		idxs->o = -100;
	return (idxs->o);
}

int	remove_in_func(t_list **la, t_list **lb, t_index_b *idxs)
{
	t_list	*tmp;
	int		i;
	t_list	*tmp2;

	tmp = (*lb);
	i = 0;
	tmp2 = copie_b(&tmp);
	if (!(ft_lstsize(*lb) == 500))
	{
		////printf("le printf pour mehdi\n");
		if (idxs->y <= idxs->z && idxs->y != 0
			&& (idxs->z != 0 && idxs->z != -1))
		{
			////printf("KKKK = %d\n", (*la)->last);
			idxs->z = idxs->y + 1;
			while (idxs->z)
			{
				rb_copy(&tmp2);
				idxs->z--;
			}
			(*la)->last = idxs->y;
			(*la)->last2 = tmp2->data;
			if (tmp2->next != NULL)
			{
				tmp2 = tmp2->next;
				(*la)->last3 = tmp->data;
			}
			return (idxs->y + 1);
		}
		else if (idxs->z <= idxs->y && idxs->y != 0
			&& (idxs->z != 0 && idxs->z != -1))
		{
			////printf("KKKK22 = %d\n", (*la)->last2);
			idxs->y = idxs->z;
			while (idxs->y)
			{
				rrb_copy(&tmp2);
				idxs->y--;
			}
			// (*la)->last = idxs->z * -1;
			(*la)->last2 = tmp2->data;
			if (tmp2->next != NULL)
			{
				tmp2 = tmp2->next;
				(*la)->last3 = tmp->data;
			}
			return (idxs->z);
		}
	}
	if (ft_lstsize(*lb) == 500)
	{
		if (idxs->y <= idxs->z && idxs->y != 0 && (idxs->z != 0
				&& idxs->z != -1))
		{
			idxs->z = idxs->y + 1;
			while (idxs->z)
			{
				rb(lb);
				idxs->z--;
			}
			return (idxs->y);
		}
		else if (idxs->z <= idxs->y && idxs->y != 0 && (idxs->z != 0
				&& idxs->z != -1))
		{
			idxs->y = idxs->z;
			while (idxs->y)
			{
				rrb(lb);
				// //////printf("u\n");
				idxs->y--;
			}
			return (idxs->z);
		}
	}
	free(tmp2);
	return (1);
}
