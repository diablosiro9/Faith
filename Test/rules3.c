/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:16:55 by dojannin          #+#    #+#             */
/*   Updated: 2022/09/23 11:39:52 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **la, t_list **lb)
{	
	t_list	*tmp;
	t_list	*tmp2;

	tmp = malloc_cell((*la)->data);
	tmp2 = malloc_cell((*lb)->data);
	ft_lstdeletefirst((la));
	ft_lstadd_back(la, tmp);
	ft_lstdeletefirst((lb));
	ft_lstadd_back(lb, tmp2);
	write(1, "rr\n", 3);
}

void	rrr(t_list **la, t_list **lb)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = malloc_cell(ft_lstlast(*la)->data);
	tmp2 = malloc_cell(ft_lstlast(*lb)->data);
	ft_lstdeletelast(*la);
	ft_lstadd_front(la, tmp);
	ft_lstdeletelast(*lb);
	ft_lstadd_front(lb, tmp2);
	write(1, "rrr\n", 4);
}

void	pa(t_list **la, t_list **lb)
{
	t_list	*tmp;

	tmp = malloc_cell((*lb)->data);
	ft_lstdeletefirst(lb);
	ft_lstadd_front(la, tmp);
	write(1, "pa\n", 3);
}
