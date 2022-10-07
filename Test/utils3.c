/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:18:58 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	doublon(t_list **l)
{
	t_list	*tmp;
	int		i;
	t_list	*tmp2;

	tmp = (*l);
	tmp2 = (*l);
	i = (tmp2)->data;
	while (tmp2->next != NULL)
	{
		tmp = tmp2;
		while (tmp != NULL && tmp->next != NULL)
		{
			if (i == tmp->next->data)
			{
				write(1, "Error\n", 6);
				return (0);
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
		i = tmp2->data;
	}
	return (1);
}

void	last_for_la(int z, t_list **la, t_list **lb)
{
	z = check_before_push(la, lb);
	if (z != 0)
	{
		while (z)
		{
			rrb(lb);
			z--;
		}
	}
}

int	do_op_ra_rra(t_list **la, t_index_b *idxs, int index)
{
	t_list	*tmp;
	int		i;
	t_list	*tmp2;

	tmp = (*la);
	i = 0;
	tmp2 = copie_b(&tmp);
	//////printf("OOOOOOOOOOH\n");
	// //////printf("favor lb = %d\n", (*lb)->data);
	if (idxs->pos[index] == 1)
	{
		while (idxs->dis[index])
		{
			ra_copy(&tmp2);
			idxs->dis[index]--;
			i++;
		}
		//////printf("ouais\n");
	}
	else
	{
		while (idxs->dis[index])
		{
			rra_copy(&tmp2);
			idxs->dis[index]--;
			i++;
		}
		i = i * (-1);
		//////printf("non\n");
	}
	idxs->save = tmp2->data;
	// //////printf("tmp2 top == %d\n", tmp2->data);
	delete_list(&tmp2);
	//////printf("all good\n");
	//////printf("i do op ra == %d\n", i);
	return (i);
}

void	do_op_ra_rra_cent(t_list **la, t_index_f *idxs, int index)
{
	if (idxs->pos[index] == 1)
	{
		while (idxs->dis[index])
		{
			ra(la);
			idxs->dis[index]--;
		}
	}
	else
	{
		while (idxs->dis[index])
		{
			rra(la);
			idxs->dis[index]--;
		}
	}
	free(idxs);
}

int	check_before_push(t_list **la, t_list **lb)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	i = 0;
	tmp = *la;
	tmp2 = *lb;
	if (ft_lstsize(*la) == 1)
	{
		if ((*la)->data < (*lb)->data)
		{
			rb(lb);
			i++;
			if ((*la)->data > (*lb)->data)
				return (i);
		}
	}
	return (i);
}
