/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_hundred2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:06:45 by dojannin          #+#    #+#             */
/*   Updated: 2022/08/18 20:29:22 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_third_range(t_list **la, t_list **lb)
{
	while (ft_lstsize(*lb) >= 40 && ft_lstsize(*lb) < 60)
	{
		sort_range3(la, lb);
	}
}

void	sort_range3(t_list **la, t_list **lb)
{
	while (ft_lstsize(*lb) < 60 && ft_lstsize(*la) >= 1)
	{
		if (ft_lstsize(*lb) >= 1)
			just_do_it(la, lb);
	}
}

void	do_sec_range(t_list **la, t_list **lb)
{
	while (ft_lstsize(*lb) >= 20 && ft_lstsize(*lb) < 40)
	{
		sort_range2(la, lb);
	}
}

void	sort_range2(t_list **la, t_list **lb)
{
	while (ft_lstsize(*lb) < 40 && ft_lstsize(*la) >= 1)
	{
		if (ft_lstsize(*lb) >= 1)
			just_do_it(la, lb);
	}
}
