/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:18:58 by dojannin          #+#    #+#             */
/*   Updated: 2022/07/31 17:46:10 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_int(t_list *l)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	j = l->data;
	tmp = l;
	while (tmp)
	{
		i = tmp->data;
		if (i > j)
			j = i;
		tmp = tmp->next;
	}
	return (j);
}

int	min_int(t_list *l)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	j = l->data;
	tmp = l;
	while (tmp)
	{
		i = tmp->data;
		if (i < j)
			j = i;
		tmp = tmp->next;
	}
	return (j);
}

int	pos_max_cell(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == max_int(tmp))
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

int	pos_min_cell(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == min_int(l))
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
