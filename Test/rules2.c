/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:52:37 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:47 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **lb, t_list **la)
{
	t_list	*tmp;

	tmp = malloc_cell((*la)->data);
	ft_lstdeletefirst(la);
	ft_lstadd_front(lb, tmp);
	write(1, "pb\n", 3);
	////printf("lbbbbbb == %d \n", (*lb)->data);
	// if ((*lb)->data == 4)
	// 	affichelist(*lb);
	// if (ft_lstsize(*lb) >= 237|| (*lb)->data == 43){
	// char c;
	// read(0, &c, 1);
	// }
	if ((*lb)->data == 4)
		affichelist(*lb);
	// if ((*lb)->next)
	// 	////printf("lb nextt = %d\n", (*lb)->next->data);
	// if ((*lb)->data == -490 || ft_lstsize(*lb) >= 474)
	// {
	// 	char c;
	// 	read(0, &c, 1);
	// }
}

void	rb(t_list **l)
{	
	t_list	*tmp;

	tmp = malloc_cell((*l)->data);
	ft_lstdeletefirst((l));
	ft_lstadd_back(l, tmp);
	write(1, "rb\n", 3);
}

void	rb_copy(t_list **l)
{	
	t_list	*tmp;

	tmp = malloc_cell((*l)->data);
	ft_lstdeletefirst((l));
	ft_lstadd_back(l, tmp);
}

void	rrb(t_list **l)
{
	t_list	*tmp;

	tmp = malloc_cell(ft_lstlast(*l)->data);
	ft_lstdeletelast(*l);
	ft_lstadd_front(l, tmp);
	write(1, "rrb\n", 4);
}

void	rrb_copy(t_list **l)
{
	t_list	*tmp;

	tmp = malloc_cell(ft_lstlast(*l)->data);
	//////printf("this size is egual === %d\n", ft_lstsize(*l));
	ft_lstdeletelast(*l);
	ft_lstadd_front(l, tmp);
	// //////printf("fin\n");
}
