/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:19:02 by dojannin          #+#    #+#             */
/*   Updated: 2022/08/17 14:18:05 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_high_four(t_list **la, t_list **lb)
{
	int		j;

	j = pos_max_cell(*la);
	if (ft_lstsize(*la) == 4)
	{
		move_high_four(j, la, lb);
	}
}

void	move_high_four(int j, t_list **la, t_list **lb)
{
	if (j == 0)
		pb(lb, la);
	else if (j == 1)
	{
		sa(la);
		pb(lb, la);
	}
	else if (j == 2)
	{
		rra(la);
		rra(la);
		pb(lb, la);
	}
	else if (j == 3)
	{
		rra(la);
		pb(lb, la);
	}
}

void	push_min_four(t_list **la, t_list **lb)
{
	int		i;
	int		j;

	i = min_int(*la);
	j = pos_min_cell(*la);
	if (ft_lstsize(*la) == 4)
		move_min_four(j, la, lb);
}

void	move_min_four(int j, t_list **la, t_list **lb)
{
	if (ft_lstsize(*la) == 4)
	{
		if (j == 0)
			pb(lb, la);
		else if (j == 1)
		{
			sa(la);
			pb(lb, la);
		}
		else if (j == 2)
		{
			rra(la);
			rra(la);
			pb(lb, la);
		}
		else if (j == 3)
		{
			rra(la);
			pb(lb, la);
		}
	}
}

int	four_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = third_first_min(la);
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
