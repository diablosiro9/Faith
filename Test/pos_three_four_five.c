/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_three_four_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:11:41 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_third_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	// //////printf("why\n");
	while (tmp)
	{
		// //////printf("e≈plain\n");
		if (tmp->data == third_first_min(&l))
		{	
			// //////printf("i == %d\n", i);
			// //////printf("tmp = %d\n", tmp->data);
			return (i);
		}
		else
		{
			tmp = tmp->next;
		}
		i++;
	}
	// //////printf("i == %d\n", i);
	// //////printf("tmp = %d\n", tmp->data);
	return (i);
}

int	third_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = second_first_min(la);
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
	// //////printf("k == %d\n", k);
	return (k);
}

int	pos_five_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == five_first_min(&l))
			return (i);
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

int	five_first_min(t_list **la)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	i = four_first_min(la);
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
	// 	//////printf("k1 == %d\n", k);
	// 	////char c;
	// 	////read(0, &c, 1);
	// }
	return (k);
}

int	pos_four_min(t_list *l)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (tmp->data == four_first_min(&l))
			return (i);
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}
