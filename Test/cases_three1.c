/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_three1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:49:20 by dojannin          #+#    #+#             */
/*   Updated: 2022/08/16 18:08:25 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_123(t_list **l)
{
	t_list	*tmp;
	int		tp;

	tp = 0;
	tmp = *l;
	while (tmp)
	{
		if ((tmp->data < tmp->next->data)
			&& (tmp->next->data < tmp->next->next->data)
			&& (tmp->data < tmp->next->next->data))
			return ;
		tmp = tmp->next;
	}
}

void	case_123_reverse(t_list **l)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = *l;
	i = 0;
	j = 0;
	if (tmp)
	{
		if ((tmp->data < tmp->next->data)
			&& (tmp->next->data < tmp->next->next->data)
			&& (tmp->data < tmp->next->next->data))
		{
			do_123_reverse(i, j, l, tmp);
		}
		tmp = tmp->next;
	}
}

void	do_123_reverse(int i, int j, t_list **l, t_list *tmp)
{
	i = return_data(tmp, 0);
	j = return_data(tmp, 1);
	change_data(l, 0, j);
	change_data(l, 1, i);
	i = return_data(tmp, 1);
	j = return_data(tmp, 2);
	change_data(l, 1, j);
	change_data(l, 2, i);
}

void	case_132(t_list **l)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = *l;
	i = 0;
	j = 0;
	if (tmp && ft_lstsize(tmp) == 3 && (check_order(tmp) == 132))
	{
		i = return_data(tmp, 1);
		j = return_data(tmp, 2);
		change_data(l, 1, j);
		change_data(l, 2, i);
	}
}

void	case_132_reverse(t_list **l)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = *l;
	i = 0;
	j = 0;
	if (tmp && ft_lstsize(tmp) == 3 && (check_order(tmp) == 132))
	{
		i = return_data(tmp, 0);
		j = return_data(tmp, 1);
		change_data(l, 0, j);
		change_data(l, 1, i);
		i = return_data(tmp, 1);
		j = return_data(tmp, 2);
		change_data(l, 1, j);
		change_data(l, 2, i);
	}
}
