/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_direct_ten.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:26:40 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_direct_ten_last_equal(t_list **la, int res)
{
	if (res < 0)
	{
		while (res < 0)
		{
			ra(la);
			res++;
		}
	}
	else
	{
		while (res > 0)
		{
			ra(la);
			res--;
		}
	}
}

void	do_direct_ten_last_res_down(t_list **la, t_list **lb, int res)
{
	while (res <= 0 && (*la)->last <= 0)
	{
		rrr(la, lb);
		res++;
		(*la)->last++;
	}
	// (*la)->last = 0;
	while ((*la)->last <= 0)
	{
		rrb(lb);
		// //////printf("lui\n");
		(*la)->last++;
	}
	while (res <= 0)
	{
		rra(la);
		// //////printf("tu\n");
		res++;
	}
}

void	do_direct_ten_last_down_res(t_list **la, t_list **lb, int res)
{
	while ((*la)->last <= 0)
	{
		//printf("ptetre oit\n");
		rb(lb);
		(*la)->last++;
	}
	while (res >= 0)
	{
		ra(la);
		res--;
	}
}

void	do_direct_ten_last_up_res(t_list **la, t_list **lb, int res)
{
	while ((*la)->last >= 0)
	{
		rrb(lb);
		//////printf("ah\n");
		(*la)->last--;
	}
	while (res <= 0)
	{
		ra(la);
		res++;
	}
}

void	do_direct_ten_res_last_up(t_list **la, t_list **lb, int res)
{
	if (res >= 0 && ((*la)->last && (*la)->last > 0))
	{
		while (res >= 0 && (*la)->last >= 0)
		{
			rr(la, lb);
			res--;
			(*la)->last--;
			//printf("t9i8\n");
		}
		//printf("wait\n");
		while ((*la)->last >= 0)
		{
			rb(lb);
			//printf("*la last == %d\n", (*la)->last);
			////printf("or u\n");
			(*la)->last--;
		}
		while (res > 0)
		{
			ra(la);
			res--;
		}
	}
}
