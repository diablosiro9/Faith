/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_hundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:53:56 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_hundred(t_list **la, t_list **lb)
{
	int		z;
	int		i;

	z = 0;
	i = 1;
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 20)
		sort_range(la, lb);
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 40)
		do_sec_range(la, lb);
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 60)
		do_third_range(la, lb);
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 80)
		do_four_range(la, lb);
	if (ft_lstsize(*la) >= 1 && ft_lstsize(*lb) < 100)
		do_last_range(la, lb);
	if (ft_lstsize(*la) == 1)
		last_for_la(z, la, lb);
	while (ft_lstsize(*lb) > 0)
		pa(la, lb);
	// affichelist(*la);
	// ////printf("Fct == %d\n", is_tri(la));
}

void	do_last_range(t_list **la, t_list **lb)
{
	while (ft_lstsize(*lb) >= 80 && ft_lstsize(*lb) < 100)
	{
		sort_range5(la, lb);
	}
}

void	sort_range5(t_list **la, t_list **lb)
{
	while (ft_lstsize(*lb) < 100 && ft_lstsize(*la) >= 1)
	{
		if (ft_lstsize(*lb) >= 1)
			just_do_it(la, lb);
	}
}

void	do_four_range(t_list **la, t_list **lb)
{
	while (ft_lstsize(*lb) >= 60 && ft_lstsize(*lb) < 80)
	{
		sort_range4(la, lb);
	}
}

void	sort_range4(t_list **la, t_list **lb)
{
	while (ft_lstsize(*lb) < 80 && ft_lstsize(*la) >= 1)
	{
		if (ft_lstsize(*lb) >= 1)
			just_do_it(la, lb);
	}
}
