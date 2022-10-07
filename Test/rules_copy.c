/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:33:22 by dojannin          #+#    #+#             */
/*   Updated: 2022/09/06 15:18:17 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_copy(t_list **la, t_list **lb)
{	
	t_list	*tmp;
	t_list	*tmp2;

	tmp = malloc_cell((*la)->data);
	tmp2 = malloc_cell((*lb)->data);
	ft_lstdeletefirst((la));
	ft_lstadd_back(la, tmp);
	ft_lstdeletefirst((lb));
	ft_lstadd_back(lb, tmp2);
}

void	rrr_copy(t_list **la, t_list **lb)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = malloc_cell(ft_lstlast(*la)->data);
	tmp2 = malloc_cell(ft_lstlast(*lb)->data);
	ft_lstdeletelast(*la);
	ft_lstadd_front(la, tmp);
	ft_lstdeletelast(*lb);
	ft_lstadd_front(lb, tmp2);
}

void	ra_copy(t_list **l)
{	
	t_list	*tmp;

	tmp = malloc_cell((*l)->data);
	ft_lstdeletefirst((l));
	ft_lstadd_back(l, tmp);
}
