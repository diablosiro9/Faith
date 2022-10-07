/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:54:48 by dojannin          #+#    #+#             */
/*   Updated: 2022/08/26 20:15:28 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **l)
{
	t_list	*tmp;

	tmp = malloc_cell(ft_lstlast(*l)->data);
	ft_lstdeletelast(*l);
	ft_lstadd_front(l, tmp);
	write(1, "rra\n", 4);
}

void	rra_copy(t_list **l)
{
	t_list	*tmp;

	tmp = malloc_cell(ft_lstlast(*l)->data);
	ft_lstdeletelast(*l);
	ft_lstadd_front(l, tmp);
}

void	sa(t_list **la)
{
	int		tmp;

	tmp = (*la)->data;
	(*la)->data = (*la)->next->data;
	(*la)->next->data = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_list **lb)
{
	int		tmp;

	tmp = (*lb)->data;
	(*lb)->data = (*lb)->next->data;
	(*lb)->next->data = tmp;
	write(1, "sb\n", 3);
}

void	ra(t_list **l)
{	
	t_list	*tmp;

	tmp = malloc_cell((*l)->data);
	ft_lstdeletefirst((l));
	ft_lstadd_back(l, tmp);
	write(1, "ra\n", 3);
}
