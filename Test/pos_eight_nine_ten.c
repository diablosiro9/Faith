/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_eight_nine_ten.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:16:26 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	eight_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = seven_first_min(la);
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
	// 	return (k);
	// }
	return (k);
}

int	pos_nine_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == nine_first_min(&l))
			return (i);
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

int	nine_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = eight_first_min(la);
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

int	pos_ten_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == ten_first_min(&l))
			return (i);
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ten_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = nine_first_min(la);
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
	// if (ft_lstsize(*la) < 270)
	// 	//////printf("k == %d\n", k);
	return (k);
}
