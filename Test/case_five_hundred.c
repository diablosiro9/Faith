/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_five_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:59:43 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:32:11 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_five_hundred(t_list **la, t_list **lb)
{
	int			z;
	int			tmp;
	t_index_b	*idxs;

	z = 0;
	tmp = min_int(*la);
	idxs = NULL;
	idxs = malloc(sizeof(t_index_b) * 1);
	idxs = init_struct_b(idxs);
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 500)
		sort_range_five_hundred(la, lb, idxs);
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 306)
		do_sec_range_five_hundred(la, lb, idxs);
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 300)
		do_third_range_five_hundred(la, lb, idxs);
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 400)
		do_four_range_five_hundred(la, lb, idxs);
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 500)
		do_last_range_five_hundred(la, lb, idxs);
	if (ft_lstsize(*la) == 1)
		last_for_la(z, la, lb);
	else if (ft_lstsize(*la) == 0)
		while (ft_lstsize(*lb) > 0)
			pa(la, lb);
	affichelist(*la);
	printf("Fct == %d\n", is_tri(la));
	// system("leaks push_swap");
}

void	do_last_range_five_hundred(t_list **la, t_list **lb, t_index_b *idxs)
{
	while (ft_lstsize(*lb) >= 400 && ft_lstsize(*lb) < 500)
	{
		sort_range5_five_hundred(la, lb, idxs);
	}
}

void	sort_range5_five_hundred(t_list **la, t_list **lb, t_index_b *idxs)
{	
	while (ft_lstsize(*lb) < 500 && ft_lstsize(*la) >= 1)
	{
		if (ft_lstsize(*lb) >= 1)
		{
			idxs = init_struct_b(idxs);
			attribute_struct(la, idxs);
			just_do_it_f(la, lb, idxs);
			//////printf("sorti\n");
			free(idxs);
		}
	}
}

void	do_four_range_five_hundred(t_list **la, t_list **lb, t_index_b *idxs)
{
	while (ft_lstsize(*lb) >= 300 && ft_lstsize(*lb) < 400)
	{
		sort_range4_five_hundred(la, lb, idxs);
	}
}

void	sort_range4_five_hundred(t_list **la, t_list **lb, t_index_b *idxs)
{	
	while (ft_lstsize(*lb) < 400 && ft_lstsize(*la) >= 1)
	{
		if (ft_lstsize(*lb) >= 1)
		{	
			idxs = init_struct_b(idxs);
			attribute_struct(la, idxs);
			just_do_it_f(la, lb, idxs);
			free(idxs);
		}
	}
}
