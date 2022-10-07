/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:09:54 by dojannin          #+#    #+#             */
/*   Updated: 2022/08/22 15:38:21 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_five(t_list **la, t_list **lb)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *la;
	tmp2 = *lb;
	if (ft_lstsize(tmp) == 5)
	{
		push_min_five(la, lb);
	}
	push_min_four(la, lb);
	ft_case_three(la);
	pa(la, lb);
	pa(la, lb);
}

void	ft_case_five_reverse(t_list **la, t_list **lb)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *la;
	tmp2 = *lb;
	if (ft_lstsize(tmp) == 5)
	{
		push_highest_five(lb, la);
	}
	push_high_four(lb, la);
	ft_case_three_reverse(lb);
}

void	push_highest_five(t_list **la, t_list **lb)
{
	int		j;

	j = pos_max_cell(*la);
	move_highest_five(j, la, lb);
}

void	move_highest_five(int j, t_list **la, t_list **lb)
{
	if (j == 0)
		pb(lb, la);
	if (j == 1)
	{
		sa(la);
		pb(lb, la);
	}
	if (j == 2)
	{
		ra(la);
		ra(la);
		pb(lb, la);
	}
	if (j == 3)
	{
		rra(la);
		rra(la);
		pb(lb, la);
	}
	if (j == 4)
	{
		rra(la);
		pb(lb, la);
	}
}

t_list	*push_min_five(t_list **la, t_list **lb)
{
	int		j;

	j = pos_min_cell(*la);
	if (ft_lstsize(*la) == 5)
	{
		if (j == 0)
			pb(lb, la);
		else if (j == 1)
			sa(la);
		else if (j == 2)
		{
			ra(la);
			ra(la);
		}
		else if (j == 3)
		{
			rra(la);
			rra(la);
		}
		else if (j == 4)
			rra(la);
		if (j != 0)
			pb(lb, la);
	}
	return (*lb);
}
