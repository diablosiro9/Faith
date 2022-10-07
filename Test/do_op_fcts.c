/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_fcts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:09:00 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_op(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	// //////printf("")
	int	tmp;
	int tmp2;

	tmp2 = (*la)->last2;
	// ////printf("sasso est bo == %d\n", (*la)->last);
	// ////printf("tac est trop bo == %d\n", (*la)->last2);
	//////printf("el maxo == %d\n", max_int(*lb));
	tmp = (*la)->last;
	// ////printf("tkmp sil te plait == %d\n", tmp);
	if (idxs->o != -1 && idxs->o != -100)
	{
		//////printf("iiiiiidxs->i1 == %d idxs->j == %d\n", idxs->i, idxs->j);
		if (idxs->i <= idxs->j)
		{
			tmp2 = idxs->i;
			idxs->z = idxs->z;
			//////printf("iiiiiidxs->i2 == %d idxs->j == %d\n", idxs->i, idxs->j);
			//////printf("(*la)->last == %d\n", (*la)->last);
			// (*la)->last = (*la)->last * (-1);
			if (res >= 0)
			{
				// try_something(la, lb);
				until_res_and_i_rb(la, lb, idxs, res);
			}
			else if (res < 0)
			{
				// try_something(la, lb);
				res_down_until_i_rb(la, lb, idxs, res);
			}
			(*la)->last = tmp + tmp2;
			// (*la)->last = (*la)->last * (-1);
			//////printf("(*la)->last == %d\n", (*la)->last);
		}
		else
		{
			idxs->y = idxs->j;
			// (*la)->last = (*la)->last * (-1);
			//////printf("idddddddxs->i3 == %d idxs->j == %d\n", idxs->i, idxs->j);
			// (*la)->last = idxs->j;
			tmp2 = idxs->j;
			// tmp = (*la)->last;
			//////printf("(*lasssss)->last == %d\n", (*la)->last);
			if (res <= 0)
			{
				//try_something(la, lb);
				untils_res_and_i_rrb(la, lb, idxs, res);
			}
			else if (res > 0)
			{
				// try_something(la, lb);
				res_up_until_i_rrb(la, lb, idxs, res);
			}
			(*la)->last = tmp + tmp2;
			(*la)->last = (*la)->last * (-1);
			//////printf("(*la)->last == %d\n", (*la)->last);
		}
	}
	// ////printf("la last sil te plait == %d\n", (*la)->last);
}

void	until_res_and_i_rb(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	// //////printf("res == %d && idxs->ii == %d\n", res, idxs->i);
	while (res && idxs->i > 0)
	{	
		rr(la, lb);
		idxs->i--;
		res--;
		idxs->o++;
		//printf("0\n");
	}
	// //////printf("cets toi\n");
	while (res > 0)
	{
		ra(la);
		res--;
	}
	if ((*la)->last != 0)
	{
		if ((*la)->last < 0 && (idxs->i + (*la)->last >= 0))
			idxs->i = idxs->i + (*la)->last;
	}
	while (idxs->i > 0)
	{
		//printf("1\n");
		rb(lb);
		idxs->i--;
		idxs->o++;
		// ////printf("toi1s\n");
	}
	// //////printf("mehdi il est bo\n");
}

void	res_down_until_i_rb(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	if (res < 0)
	{
		while (res < 0)
		{
			rra(la);
			res++;
		}
	}
	if ((*la)->last != 0)
	{
		if ((*la)->last < 0 && (idxs->i + (*la)->last >= 0))
			idxs->i = idxs->i + (*la)->last;
	}
	if (idxs->i > 0)
	{
		while (idxs->i > 0)
		{
			rb(lb);
			idxs->i--;
			idxs->o++;
			//printf("124\n");
		}
	}
}

void	untils_res_and_i_rrb(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	while (res < 0 && idxs->j > 0)
	{	
		rrr(la, lb);
		idxs->j--;
		res++;
		idxs->o++;
	}
	while (res < 0)
	{
		rra(la);
		res++;
	}
	if ((*la)->last != 0)
	{
		if ((*la)->last > 0 && (idxs->i + (*la)->last >= 0))
			idxs->j = idxs->j - (*la)->last;
	}
	while (idxs->j > 0)
	{
		rrb(lb);
		// //////printf("p\n");
		idxs->j--;
		idxs->o++;
	}
}

void	res_up_until_i_rrb(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	while (res > 0)
	{
		ra(la);
		res--;
	}
	if ((*la)->last != 0)
	{
		if ((*la)->last > 0 && (idxs->i + (*la)->last >= 0))
			idxs->j = idxs->j - (*la)->last;
	}
	while (idxs->j > 0)
	{
		rrb(lb);
		// //////printf("oit\n");
		//////printf("119\n");
		idxs->j--;
		idxs->o++;
	}
}
