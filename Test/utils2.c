/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:54:58 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	condi(t_list **la, t_list **lb)
{
	if (!(*la))
		return ;
	if (ft_lstsize(*la) == 0)
		return ;
	if (ft_lstsize(*la) == 2)
		ft_case_two(la);
	if (ft_lstsize(*la) == 3)
		ft_case_three(la);
	if (ft_lstsize(*la) == 5)
		ft_case_five(la, lb);
	if (ft_lstsize(*la) == 100)
		ft_case_hundred(la, lb);
	if (ft_lstsize(*la) == 500)
		ft_case_five_hundred(la, lb);
}

int	dist_top_bottom(t_list **la, int min)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		count;

	tmp = (*la);
	i = min;
	j = 0;
	count = 0;
	if (i <= (ft_lstsize(tmp) / 2))
	{
		count = i;
	}
	else
	{
		j = (ft_lstsize(tmp) - 1) - i;
		count = j;
	}
	return (count + 1);
}

int	dist_top_bottom_five(t_list **la, int min)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		count;

	tmp = (*la);
	i = min;
	j = 0;
	count = 0;
	if (i <= (ft_lstsize(tmp) / 2))
	{
		count = i;
		return (count);
	}
	else
	{
		j = (ft_lstsize(tmp)) - i;
		count = j;
		return (count);
	}
}

int	pos_second_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == second_first_min(&l))
		{	
			return (i);
		}
		else
		{
			tmp = tmp->next;
		}
		i++;
	}
	return (i);
}

int	second_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = min_int(*la);
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
	// if (ft_lstsize(*la) == 241)
		//////printf("k == %d\n", k);
	return (k);
}
