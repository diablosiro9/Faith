/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_five_hundred2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:59:42 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_third_range_five_hundred(t_list **la, t_list **lb, t_index_b *idxs)
{
	while (ft_lstsize(*lb) >= 200 && ft_lstsize(*lb) < 300)
	{
		sort_range3_five_hundred(la, lb, idxs);
	}
}

void	sort_range3_five_hundred(t_list **la, t_list **lb, t_index_b *idxs)
{
	while (ft_lstsize(*lb) < 300 && ft_lstsize(*la) >= 1)
	{
		//////printf("do i see u\n");
		if (ft_lstsize(*lb) >= 1)
		{
			idxs = init_struct_b(idxs);
			attribute_struct(la, idxs);
			just_do_it_f(la, lb, idxs);
			//////printf("sorti3\n");

			free(idxs);
		}
	}
}

void	do_sec_range_five_hundred(t_list **la, t_list **lb, t_index_b *idxs)
{
	while (ft_lstsize(*lb) >= 100 && ft_lstsize(*lb) < 200)
	{
		sort_range2_five_hundred(la, lb, idxs);
	}
}

void	sort_range2_five_hundred(t_list **la, t_list **lb, t_index_b *idxs)
{
	while (ft_lstsize(*lb) < 250 && ft_lstsize(*la) >= 1)
	{
		//////printf("ti rentres ] po \n");
		if (ft_lstsize(*lb) >= 100)
		{
			//////printf("ouee\n");
			idxs = init_struct_b(idxs);
			attribute_struct(la, idxs);
			just_do_it_f(la, lb, idxs);
			//////printf("sorti2\n");
			free(idxs);
			//////printf("sorti\n");
			//////printf("ft_lstsize( == %d\n", ft_lstsize(*la));
		}
		//////printf("i\n");
	}
	//////printf("dont know\n");
}
