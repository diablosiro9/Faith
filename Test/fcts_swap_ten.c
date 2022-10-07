/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_swap_ten.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:21:25 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ten_last_res_down(t_list **la, t_list **lb, int res)
{
	while (res <= 0 && (*la)->last <= 0)
	{
		rrr(la, lb);
		(*la)->last++;
		res++;
	}
	while (res < 0)
	{
		rra(la);
		res++;
	}
	while ((*la)->last <= 0)
	{
		rb(lb);
		//printf("why not\n");
		(*la)->last++;
	}
}

void	swap_ten_res_equal(t_list **la, t_list **lb)
{
	if ((*la)->last >= 0)
	{
		while ((*la)->last)
		{
			rb(lb);
			//printf("u maybe\n");
			(*la)->last--;
		}
	}
	else
	{
		while ((*la)->last <= 0)
		{
			rrb(lb);
			// //////printf("b\n");
			(*la)->last++;
		}
	}
}

void	swap_ten_last_down_res_up(t_list **la, t_list **lb, int res)
{
	// while ((*la)->last <= 0)
	// {
	// 	rrb(lb);
	// 	// //////printf("c\n");
	// 	(*la)->last++;
	// }
	(void)*lb;
	while (res > 0)
	{
		ra(la);
		res--;
	}
}

void	swap_ten_last_res_up(t_list **la, t_list **lb, int res)
{
	while ((*la)->last >= 0 && res >= 0)
	{
		rr(la, lb);
		//printf("2323");
		(*la)->last--;
		res--;
	}
	while ((*la)->last >= 0)
	{
		rb(lb);
		//printf("why \n");
		(*la)->last--;
	}
}

void	swap_ten_last_equal(t_list **la, int res)
{
	if (res != 0)
	{
		if (res > 0)
		{
			while (res > 0)
			{
				ra(la);
				res--;
			}
		}
		else
		{
			while (res < 0)
			{
				rra(la);
				res++;
			}
		}
	}
}


void	swap_ten_last_up_res_down(t_list **la, t_list **lb, int res)
{
	(void)lb;
	while (res < 0)
	{
		rra(la);
		res++;
	}
}