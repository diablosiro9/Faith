/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:08:49 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_range_five_hundred(t_list **la, t_list **lb, t_index_b *idxs)
{
	int		i;

	i = 0;
	while (ft_lstsize(*lb) < 500 && ft_lstsize(*la) >= 1)
	{	
		////printf("do u\n");
		// if (ft_lstsize(*lb) > 269)
		// {
		// 	affichelist(*lb);
		// 	char c;
		// 	read(0, &c, 1);
		// }
		if (ft_lstsize(*lb) == 0)
		{
			attribute_struct(la, idxs);
			i = compare_eleven_first(la, idxs);
			first_round(la, i);
			pb(lb, la);
			free(idxs);
		}
		idxs = init_struct_b(idxs);
		attribute_struct(la, idxs);
		if (ft_lstsize(*lb) >= 1)
		{
			////printf("je serre\n");
			just_do_it_f(la, lb, idxs);
			////printf("sorti\n");
			free(idxs);
			if (ft_lstsize(*lb) == 500)
				return ;
			if (is_tri_reverse(lb) == 1)
				(*la)->last = 0;
			////printf("why\n");
			////printf("ft_lstsize(la) == %d\n", ft_lstsize(*lb));
			// if (ft_lstsize(*lb) == 476){
			// 	affichelist(*lb);
			// 	char c;
			// 	read(0, &c, 1);
			// }
		}
	}
}

void	first_round(t_list **la, int i)
{
	if (i > 0)
	{	
		while (i)
		{
			ra(la);
			i--;
		}
	}
	else
	{
		while (i < 0)
		{
			rra(la);
			// //////printf("mon\n");
			i++;
		}
	}
}

void	sort_range(t_list **la, t_list **lb)
{
	while (ft_lstsize(*lb) < 20 && ft_lstsize(*la) > 1)
	{
		if (ft_lstsize(*lb) == 0)
		{
			compare_five_first(la);
			pb(lb, la);
		}
		if (ft_lstsize(*lb) >= 1)
			just_do_it(la, lb);
	}
}

void	just_do_it(t_list **la, t_list **lb)
{
	t_index	*idxs;
	int		j;

	j = 0;
	idxs = NULL;
	compare_five_first(la);
	idxs = init_struct(idxs);
	j = compare_la_lb(la, lb, idxs);
	if (j == 0)
		pb(lb, la);
	free(idxs);
}

void	just_do_it_f(t_list **la, t_list **lb, t_index_b *idxs)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	////printf("sharingan \n");
	////printf("la last == %d\n", (*la)->last2);
	if (is_tri_reverse(lb) == 1)
		(*la)->last2 = 0;
	i = (*la)->last2;
	j = compare_eleven_first(la, idxs);
	////printf("la lastt2 --- %d\n", (*la)->last2);
	j = compare_la_lb_f(la, lb, idxs, j);
	// if (pos_max_cell(*lb) != 0)
	// {
	// 	i = dist_top_bottom(lb, max_int(*lb));
	// 	if (pos_max_cell(*lb) < ft_lstsize(*lb) / 2)
	// 		i = -i;
	// 	(*la)->last = i;
	// }
	////printf("COMPARE ELEVEN && TAILLE LA === %d\n", ft_lstsize(*la));
	// char c;
	// // read(0, &c, 1);
	// if ((*la)->last2 != 0)
	// {
	// 	if ((*la)->last2 < 0)
	// 	{
	// 		while ((*la)->last2 < 0)
	// 		{
	// 			rb(lb);
	// 			(*la)->last2++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while ((*la)->last2 > 0)
	// 		{
	// 			rrb(lb);
	// 			(*la)->last2++;
	// 		}
	// 	}
	// }
	////printf("lassssssss = %d\n", (*la)->last);
	////printf("LAAAST222 === %d\n", (*la)->last2);
	if (j == 0)
	{
		// if (ft_lstsize(*lb) > 2)
		////printf("lb == %d && lb->next == %d lb->next->next == %d\n", (*lb)->data, (*lb)->next->data, (*lb)->next->next->data);
		pb(lb, la);
		if (ft_lstsize(*lb) > 3){
			//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
			//char c;
			//read(0, &c, 1);
		//////char c;
		}
		//////read(0, &c, 1);
	}
	(*la)->last2 = i;
	i = 0;
	////printf("taille finale == %d\n", ft_lstsize(*lb));
	// if (ft_lstsize(*lb) == 500)
	// {
	// 	affichelist(*lb);
	// }
	// try_something(la, lb);
	// if (ft_lstsize(*lb) == 500)
	// 	//////printf("la last - %d\n", (*la)->last);
	if (ft_lstsize(*lb) < 500)
	{
		// try_something(la, lb);
		// //////printf("try avant compare_ten\n");
		////printf("la last du tieks == %d\n", (*la)->last);
		////printf("la last2 du tieks 000  == %d\n", (*la)->last2);
		(*la)->last2 = (*la)->last + (*la)->last2; 
		if (is_tri_reverse(lb) == 1)
			(*la)->last2 = 0;
		// if ((*la)->last != 0 && (*la)->last < 0)
		// {
		// 	if ((*la)->last2 != 0 && (*la)->last2 < 0)
		// 	{
		// 		(*la)->last2 = (*la)->last + (*la)->last2; 
		// 	} 
		// 	else if ((*la)->last2 != 0 && (*la)->last2 > 0)
		// 	{
		// 		(*la)->last2 = (*la)->last + (*la)->last2;
		// 	}
		// }
		// if ((*la)->last != 0 && (*la)->last > 0)
		// {
		// 	if ((*la)->last2 != 0 && (*la)->last2 < 0)
		// 	{
		// 		(*la)->last2 = (*la)->last + (*la)->last2; 
		// 	}
		// 	else if ((*la)->last2 != 0 && (*la)->last2 > 0)
		// 	{
		// 		(*la)->last2 = (*la)->last + (*la)->last2; 
		// 	}
		// }
		////printf("la last2 du tieks  == %d\n", (*la)->last2);
		// (*la)->last2 = 0;
		// if ((*la)->last2 < 0)
		// {
		// 	(*la)->last2 = (*la)->last2 - 2;
		// }
		if ((*la)->last2 != 0)
			(*la)->last = (*la)->last2;
		i = compare_ten_first(la, lb, idxs);
		// try_something(la, lb);
		// (*la)->last = (*la)->last2;
		////printf("la last == %d\n", (*la)->last);
		////printf("i ==== %d\n", i);
		i = compare_la_lb_f_ten(la, lb, idxs, i);
		////printf("i2 ==== %d\n", i);
		////printf("taille de a pour savoir stp == %d\n", ft_lstsize(*la));
		////printf("taille de b pour savoir stp == %d\n", ft_lstsize(*lb));
		//////printf("see me\n");
		// ////printf("SORTIE TEN && SIZE LA == %d\n", ft_lstsize(*la));
		// char c;
		// read(0, &c, 1);
		if (ft_lstsize(*lb) == 500)
			return ;
		j = (*la)->last2;
		if (i == 0)
		{
			// if (ft_lstsize(*lb) > 2)
			// 	//////printf("FINIIISHH = lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
			pb(lb, la);
			// if (ft_lstsize(*lb) > 3){
			// 	//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
			// 	//char c;
			// 	//read(0, &c, 1);
			// }
			//////char c;
			//////read(0, &c, 1);
		}
		(*la)->last2 = j;
		////printf("okey with me\n");
		// if (is_tri_reverse(lb) == 0)
		// {
		// 	if ((*la)->last2 != 0)
		// 	{
		// 		if ((*la)->last2 > 0)
		// 		{
		// 			while ((*la)->last2 > 0)
		// 			{
		// 				rb(lb);
		// 				(*la)->last2--;
		// 			}
		// 		}
		// 		else
		// 		{
		// 			while ((*la)->last2 < 0)
		// 			{
		// 				rrb(lb);
		// 				(*la)->last2++;
		// 			}
		// 		}
		// 	}
		// }
		if (is_tri_reverse(lb) == 1)
		{
			////printf("ft_lstsizE(lb() == %d\n", ft_lstsize(*lb));
			affichelist(*lb);
			// char c;
			// read(0, &c, 1);
		}
		// if (ft_lstsize(*lb) != 500)
		// 	try_something(la, lb);
		//////printf("okeeeeeeyyeyyyy\n");
	}	
}
