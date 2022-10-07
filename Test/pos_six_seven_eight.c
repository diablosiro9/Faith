/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_six_seven_eight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:17:40 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_six_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == six_first_min(&l))
			return (i);
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

int	six_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = five_first_min(la);
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

	// if (ft_lstsize(*la) < 481)	{
	// 	//////printf("k2 == %d\n", k);
	// 	////char c;
	// 	////read(0, &c, 1);
	// }
	return (k);
}

int	pos_seven_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == seven_first_min(&l))
			return (i);
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

int	seven_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = six_first_min(la);
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
	// if (ft_lstsize(*la) < 484)	{
	// 	//////printf("k == %d\n", k);
	// 	////char c;
	// 	////read(0, &c, 1);
	// }
	return (k);
}

int	pos_eight_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == eight_first_min(&l))
			return (i);
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}
