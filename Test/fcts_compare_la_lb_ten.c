/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts_compare_la_lb_ten.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:58:31 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_for_real_ten(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	// //////printf("va tu jusquici\n");
	////printf("idxs->o == %d\n", idxs->o);
	////printf("res == %d\n", res);
	////printf("la darta == %d && lb data == %d\n", idxs->save, (*lb)->data);
	if (swap_ten_is_okay(la, idxs) == -100){
		do_swap_ten(la, lb, idxs, res);
		////printf("okeyyyy\n");
		// return ;
	}
	else if (ft_lstsize(*lb) >= 0 && ft_lstsize(*la) >= 1 && idxs->o != -100)
	{
		////printf("t'entres la dedans\n");
		idxs->i = check_before_rb(lb, idxs);
		if (ft_lstsize(*lb) >= 3)
			idxs->j = check_before_rrb(lb, idxs) - 1;
		////printf("tu sors i == %d, j == %d\n", idxs->i, idxs->j);
	}
	// //////printf("top lb == %ds\n", (*lb)->data);
	////printf("TU ME SUIS\n");
	if (idxs->o == -100)
		return ;
	idxs->z = idxs->i;
	idxs->y = idxs->j;
	////printf("sors\n");
	if (idxs->save > ten_first_min(la))
		return ;
	// try_something(la, lb);
	do_op(la, lb, idxs, res);
	////printf("sors\n");
	//////printf("LAAAA LAAAAST === %d\n", (*la)->last);
}

void	do_swap_ten(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	//////printf("entre swap teneeeee\n");
	int	ret;

	ret = (*la)->last;
	////printf("LA LAST1 == %d\n", (*la)->last);
	if ((*la)->last == 0)
		swap_ten_last_equal(la, res);
	else if ((*la)->last > 0 && res > 0)
		swap_ten_last_res_up(la, lb, res);
	else if ((*la)->last <= 0 && res > 0)
		swap_ten_last_down_res_up(la, lb, res);
	else if (res < 0 && (*la)->last < 0)
		swap_ten_last_res_down(la, lb, res);
	else if (res < 0 && (*la)->last > 0)
		swap_ten_last_up_res_down(la, lb, res);
	else if (res == 0)
		swap_ten_res_equal(la, lb);
	// if (ft_lstsize(*lb) > 2)
	// 	//////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
	pb(lb, la);
	if (ft_lstsize(*lb) > 3){
		//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
		////char c;
		////read(0, &c, 1);
	}
	sb(lb);
	(*la)->last = ret;

	// if (ret < 0)
	// 	(*la)->last = ret - 1;
	////printf("LA LAST2 == %d\n", (*la)->last);
	idxs->o = -100;
	// //////printf("LAST  ========= %D\n", (*la)->last);
}

int	remove_in_func_ten(t_list **la, t_list **lb, t_index_b *idxs)
{
	// t_list	*tmp;
	int		i;
	// t_list	*tmp2;

	//////printf("okey \n");
	// tmp = (*lb);
	i = 0;
	//////printf("okey \n");
	// tmp2 = copie_b(&tmp);
	if (idxs->o == -100)
		return (-100);
	//////printf("okey \n");
	i = do_remove_in_ten(la, lb, idxs);
	return (i);
}

int	do_remove_in_ten(t_list **la, t_list **lb, t_index_b *idxs)
{
	// //////printf("la last avant rrmooove == %d && z avant == %d, y == %d\n", (*la)->last, idxs->z, idxs->y);
	// if (idxs->z != 0 && idxs->z != -1)
	// {
	// 	add_to_remove(la, lb, idxs);
	// }
	//////printf("pourquoi\n");
	(void)la;
	// if ((*la)->last != 0 && idxs->z && idxs->y)
	//////printf("yes\n");
	// if ((*la)->last)
	// {
	// 	if ((*la)->last == -5000){
	// 		//////printf("last === %d\n", (*la)->last);
	// 		return -5000;
	// 	}
	// }
	// if (idxs->z && idxs->y)
	////printf("IIIIIIIIIIdxs z == %d, idxs->y == %d\n", idxs->z, idxs->y);
	// char c;
	// read(0, &c, 1);
	// 	//////printf("la last after rrmooove == %d && z == %d et y avant == %d\n", (*la)->last, idxs->z,idxs->y);
	if (idxs->y < idxs->z && idxs->y != 0 && (idxs->z != 0
			&& idxs->z != -1 && idxs->y != -5000))
	{
		idxs->z = idxs->y;
		while (idxs->z < 0)
		{
			////printf("toi1\n");
			// char c;
			// read(0, &c, 1);
			rrb(lb);
			idxs->z++;
		}
		// //////printf("lost\n");
		////printf("lb -- %d\n", (*lb)->data);
		return (idxs->y);
	}
	else if (idxs->z <= idxs->y && idxs->y != -5000 && (idxs->z != 0
			&& idxs->z != -1))
	{
		idxs->y = idxs->z;
		while (idxs->y > 0)
		{
			//printf("what the f*\n");
			rb(lb);
			////printf("117\n");
			// //////printf("without u\n");
			// //////printf("toi\n");
			idxs->y--;
		}
		return (idxs->z);
	}
	else if (idxs->z <= idxs->y && idxs->y == -5000 && (idxs->z != 0
			&& idxs->z != -1))
	{
		idxs->y = idxs->z;
		////printf("debut embrouille\n");
		// char c;
		// read(0, &c, 1);
		while (idxs->y)
		{
			rrb(lb);
			////printf("118\n");
			// //////printf("toi\n");
			////printf("idxs->y == %d\n", idxs->y);
			idxs->y++;
		}
		return (idxs->z);
	}
	return (-5000);
}

int	swap_ten_is_okay(t_list **la, t_index_b *idxs)
{
	idxs->o = 0;
	if (idxs->save > ten_first_min(la))
		return (idxs->o);
	////printf("idxs->save == %d, (*la)->last2 = %d, (*la)->last3 =%d\n", idxs->save, (*la)->last2, (*la)->last3);
	if (idxs->save < (*la)->last2 && idxs->save > (*la)->last3)
	{
		idxs->o = -100;
	}
	return (idxs->o);
}


void	add_to_remove(t_list **la, t_list **lb, t_index_b *idxs)
{
	int	max;
	int	min;

	max = (*lb)->data + 20;
	min = (*lb)->data - 20;
	if (ft_lstsize(*lb) != 500)
	{
		//////char c;
		//////read(0, &c, 1);
		// //////printf("test == top + 10 && top - 10 %d %d\n", ((*lb)->data + 10), ((*lb)->data - 10));
		// //////printf("los idxs son z = %d, y = %d\n", idxs->z, idxs->y);
		// if ((*la)->data > max_int(*lb) && (*la)->data >= ten_first_min(la))
		// {
		// 	pb(lb, la);
		// 	return ;
		// }
		if (idxs->y < idxs->z)
		{
			if ((*la)->data <= max && (*la)->data >= min)
			{
				// //////printf("la et lb == %d %d\n", (*la)->data, (*lb)->data);
				if ((*la)->data > (*lb)->data)
				{
					while ((*la)->data > (*lb)->data  && (*lb)->data != min_int(*lb) 
							&& (*la)->data <= max && (*la)->data >= min)
					{
						rb(lb);
						//printf("quoi tu crois zac il fixe tjr le code?\n");
						////printf("impossible\n");
						// //////printf("la et lb == %d %d\n", (*la)->data, (*lb)->data);
						idxs->y--;
						//////char c;
						//////read(0, &c, 1);
					}
					// if (ft_lstsize(*lb) > 2)
					// 	//////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
					pb(lb, la);
					//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
					sb(lb);
					//char c;
					//read(0, &c, 1);
					// //////printf("is that u\n");
					idxs->y = -5000;
					// return (idxs->z);
				}
				else
				{
					while ((*la)->data < (*lb)->data && (*lb)->data != max_int(*lb)
							&& (*la)->data <= max && (*la)->data >= min)
					{
						rrb(lb);
						//////printf("1198\n");
						// //////printf("la et lb == %d %d\n", (*la)->data, (*lb)->data);
						// //////printf("ah mon boug\n'");
						idxs->z--;
					}
					// if (ft_lstsize(*lb) > 2)
					// 	//////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
					pb(lb, la);
					//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
					//char c;
					//read(0, &c, 1);
					idxs->z = -5000;
					// return (idxs->z);
				}
			}
			else 
				return ;
		}
		// else if (idxs->y < idxs->z)
		// {
		// 	if ((*la)->data <= (*lb)->data + 10 || (*la)->data >= (*lb)->data - 10)
		// 	{
		// 		if ((*la)->data > (*lb)->data)
		// 		{
		// 			while ((*la)->data > (*lb)->data)
		// 			{
		// 				rrb(lb);
		// 				idxs->z--;
		// 			}
		// 			pb(lb, la);
		// 			sb(lb);
		// 			idxs->y = 0;
		// 			return (idxs->z);
		// 		}
		// 		else
		// 		{
		// 			while ((*la)->data < (*lb)->data)
		// 			{
		// 				rb(lb);
		// 				idxs->y--;
		// 			}
		// 			pb(lb, la);
		// 			idxs->y = 0;
		// 			return (idxs->z);
		// 		}
		// 	}
		
	}
	// //////printf("finito\n");
		// else
	// 		// return (-5000);
	// else
	// 	return (-5000);
	// return (-5000);
}