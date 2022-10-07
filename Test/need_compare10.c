/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_compare10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:36:53 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_la_lb_f_ten(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	int	i;
	int	save;
	int ret;

	i = 0;
	ret = 0;
	save = 0;
	if (!la || !lb)
		return (-1);
	////printf("idxs->saveuuuuuuu == %d\n", idxs->save);
	////printf("lb actually == %d\n", (*lb)->data);
	////printf("la lastorito = %d\n", (*la)->last);
	(*la)->last2 = (*la)->last;
	// //////printf("res == %d\n", res);
	// //////printf("lb taille == %d\n", ft_lstsize(*lb));
	// //////printf("firts max === %d\n", min_int(*la));
	// //////printf("seven firts max === %d\n", seven_first_min(la));
	// //////printf("eleven firts max === %d\n", eleven_first_min(la));
	// //////printf("la ->last == %d\n", (*la)->last);
	//////printf("idxs i == %d && idxs j %d COMPAAAARE\n", idxs->z, idxs->y);
	////printf("max_int lb == %d\n", max_int(*lb));
	if (idxs->save > ten_first_min(la))
	{
		idxs->o = -100;
		return (-100);
	}
	// //////printf("min int (lb == %d\n", min_int(*lb));
	if (idxs->save < min_int(*lb))
	{
		direct_bottom_ten(la, lb, idxs, res);
		// if (ft_lstsize(*lb) > 2)
		// 	//////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
		pb(lb, la);
		if (ft_lstsize(*lb) > 3){
			//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
			//char c;
			//read(0, &c, 1);
		}
		rb(lb);
		return (-100);
	}
	//////printf("eeeasy babe its la last == %d\n", (*la)->last);
	if (idxs->save < (*lb)->data)
	{
		// try_something(la, lb);
		////printf("avant do_for_real_Ten\n");
		do_for_real_ten(la, lb, idxs, res);
		i++;
	}
	else if (idxs->save > (*lb)->data)
	{
		////printf("CA SE PASSE ICI\n");
		if (ft_lstsize(*lb) >= 0 && ft_lstsize(*la) >= 1 && idxs->o != -100)
		{
			////printf("t'entres la dedans\n");
			idxs->i = check_before_rb(lb, idxs);
			if (ft_lstsize(*lb) >= 3)
				idxs->j = check_before_rrb(lb, idxs) - 1;
			////printf("tu sors i == %d, j == %d\n", idxs->i, idxs->j);
		}
		do_op(la, lb, idxs, res);
	}
	// 	pb(lb, la);
	// else
	// 	do_for_real_ten(la, lb, idxs, res);
	save = (*la)->last;
	////printf("save mon boug == %d\n", save);
	////printf("laaaaaaaaa laaaast = %d\n", (*la)->last);
	if ((idxs->z != 0 || idxs->y != 0) && i != 0 && idxs->o != -100)
	{
		// if (ft_lstsize(*lb) > 2)
		// 	//////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
		pb(lb, la);
		////printf("you\n");
		if (ft_lstsize(*lb) > 3){
			//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
			//////printf("1u\n");
			//char c;
			//read(0, &c, 1);
		}
	}
	if ((*lb)->data == -477)
		affichelist(*lb);
	////printf("save  = %d\n", save);
	(*la)->last = save;
	////printf("save 2 = %d\n", save);

	//////printf("laaaaaaaaa laaaast = %d\n", (*la)->last);
	//////printf("idxs z == %d 777 idxs y == %d\n", idxs->z, idxs->y);
	// if ((idxs->z != 0 || idxs->y != 0) && i != 0 && idxs->o != -100)
	// {
	// 	if (idxs->z <= idxs->y)
	// 		save = idxs->z;
	// 	else
	// 		save = idxs->y;
	// }
	// (*la)->last = save;
	////printf("Save  avant try == %d\n", save);
	(*la)->last = save;
	//////printf("TAILLLL == %d\n", ft_lstsize(*lb));
	//////printf("la last == %d\n", (*la)->last);
	// //////printf("la last == %d\n", (*la)->last);
	// //////printf("ici\n");
	if (ft_lstsize(*lb) != 500)
	{
		////printf("PREMIER TRY\n");
		if (try_something(la, lb, save) == 0)
		{
			////printf("tu sors\n");
			////printf("9*la->lsat2 == %d\n", (*la)->last2);
			// ////printf("LA TAILLE DE LB 6 === %d\n", ft_lstsize(*lb));
			return (-5000);
		}
		else
		{
			save = (*la)->last2;
			// /pb(lb, la);
			(*la)->last2 = save;
			// if ((*la)->last2 != 0)
			// {
			// 	////printf("LAAAAA LASSTTTT 2222 == %d\n", (*la)->last2);
			// 	if ((*la)->last2 > 0)
			// 	{
			// 		while ((*la)->last2 > 0)
			// 		{
			// 			rrb(lb);
			// 			(*la)->last2--;
			// 		}
			// 	}
			// 	else
			// 	{
			// 		while ((*la)->last2 < 0)
			// 		{
			// 			rrb(lb);
			// 			(*la)->last2++;
			// 		}
			// 	}
			// }
			// save = 0;
			// (*la)->last = 0;
		}
		////printf("SECOND TRY\n");
		////printf("save pour pas changer == %d, la->lat == %d, la->last2 == %d\n", save, (*la)->last, (*la)->last2);
		(*la)->last = (*la)->last2;
		ret = try_something(la, lb, save);
		////printf("ret == %d\n", ret);
		//////printf("ret == %d\n", ret);
		if (ret < 0)
		// if (ret != 0)
		// {}
		{
			idxs->z = ret;
			idxs->y = ret;
			(*la)->last2 = ret;
			(*la)->last2 = (*la)->last2 * -1;
			while (ret <= 0)
			{
				rb(lb);
				ret++;
				//printf("toi2\n");
			}
			return (*la)->last2;
			// pb(lb, la);
		}
		// else if (ret > 0)
		// {
		// 	(*la)->last2 = ret;
		// 	(*la)->last2 = (*la)->last2;
		// 	while (ret > 0)
		// 	{
		// 		rrb(lb);
		// 		////printf("k\n");
		// 		ret--;
		// 	}
		// 	return (*la)->last2 = 0;
		// }
		else
		{
				idxs->z = -1;
				idxs->o = -100;
		}
		// if (try_something(la, lb, save) != 0)
		// {
		// 	if (idxs->z <= idxs->y)
		// 	{
		// 		idxs->z = idxs->z + try_something(la, lb, save);
		// 	}
		// 	else
		// 		idxs->y = idxs->z + try_something(la, lb, save);
		// }
		// // else if (try_something(la, lb, save) == 0)
		// {
		// 	if (idxs->z <= idxs->y)
		// 	{
		// 		idxs->z = 0;
		// 		idxs->o = -100;
		// 	}
		// 	else
		// 	{
		// 		idxs->y = 0;
		// 		idxs->o = -100;
		// 	}
		// }
	//////printf("THIS OO89ONE la last == %d\n", save);
	}
	// // //////printf("res fct == %d\n", try_something(la, lb, save));
	// ////printf("TROISIEME TRY\n");
	// ret = try_something(la, lb, save);
	// if (ret < 0)
	// // if (ret != 0)
	// // {}
	// {
	// 	if (idxs->z <= idxs->y)
	// 		idxs->z = idxs->z - ret; 
	// 	else
	// 		idxs->y = idxs->y + ret;
	// }
	// else if (ret > 0)
	// {
	// 	if (idxs->z <= idxs->y)
	// 		idxs->z = idxs->z + ret;
	// 	else 
	// 		idxs->y = idxs->y - ret;
	// }
	// else
	// {
	// 	if (idxs->z <= idxs->y){
	// 		idxs->z = -1;
	// 		idxs->o = -100;
	// 	}
	// 	else
	// 	{
	// 		idxs->y = -1;
	// 		idxs->o = -100;
	// 	}
	// }
	// //////printf("idx->z == %d\n", idxs->z);
	// // //////printf("avsant removbe in func\n");
	// if (save == -5000)
	// 	idxs->o = -100;
	// //////printf("idxs saveeee =%d\n", save);
	// //////printf("idxs->o == %d\n", idxs->o);
	return (remove_in_func_ten(la, lb, idxs));
}

void	direct_bottom_ten(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	if (idxs->save > ten_first_min(la))
		return ;
	if (idxs->save < min_int(*lb))
	{
		if (res >= 0 && ((*la)->last && (*la)->last > 0))
			do_direct_ten_res_last_up(la, lb, res);
		else if (res < 0 && ((*la)->last && (*la)->last > 0))
			do_direct_ten_last_up_res(la, lb, res);
		else if (res > 0 && (*la)->last < 0)
			do_direct_ten_last_down_res(la, lb, res);
		else if (res <= 0 && (*la)->last <= 0)
			do_direct_ten_last_res_down(la, lb, res);
		else
			do_direct_ten_last_equal(la, res);
	}
}

int	do_op_ra_rra_ten(t_list **la, t_list **lb, t_index_b *idxs, int index)
{
	t_list	*tmp;
	int		i;
	t_list	*tmp2;
	int		last;
	int		save;

	last = 0;
	tmp = (*la);
	i = 0;
	tmp2 = copie_b(&tmp);
	if ((*la)->last2 != 0)
		(*la)->last = (*la)->last2;
	if ((*la)->last != 0)
		last = (*la)->last;
	////printf("la--------- last === %d\n", (*la)->last);
	////printf("la--------- last2222 === %d\n", (*la)->last2);
	////printf("idxs->save == %d\n", idxs->save);
	////printf("idxs->dis == %d && la last == %d\n",  idxs->dis[index], (*la)->last2);
	if (idxs->dis[index] == 0)
		do_op_ten_dis_equal(la, lb, idxs, tmp2);
	else if ((*la)->last == 0 && (*la)->last2 == 0)
	{
		if (idxs->pos[index] == 1)
		{
			while (idxs->dis[index])
			{
				ra_copy(&tmp2);
				idxs->dis[index]--;
				i++;
			}
		}
		else
		{
			while (idxs->dis[index] <= 0)
			{
				rra_copy(&tmp2);
				idxs->dis[index]++;
				i++;
			}	
		}
		idxs->save = tmp2->data;
		(*la)->last2 = (*lb)->data;
		(*la)->last3 = (*lb)->next->data;
		////printf("(*lb)->data = %d (*lb)->next->data = %d\n", (*lb)->data, (*lb)->next->data);
	}
	else
	{
		if ((*la)->last == 0)
			(*la)->last = (*la)->last2;
		//////printf("la last value = %d\n", (*la)->last);
		// try_something(la, lb,);
		last = (*la)->last;
		save = (*la)->last;
		if (idxs->pos[index] == 1)
		{
			if (ft_lstsize(*lb) >= 2)
			{
				if ((*la)->last > 0)
				{
					while (last + 1 > 0 && idxs->dis[index] > 0)
					{
						rr(la, lb);
						//printf("lukaku\n");
						last--;
						idxs->dis[index]--;
						ra_copy(&tmp2);
						save++;
					}
					// while (last + 1 > 0)
					// {
					// 	rb(lb);
					// 	//printf("uuu\n");
					// 	last--;
					// 	save++;
					// }
					// //////printf("ah\n");
					(*la)->last2 = (*lb)->data;
					(*la)->last3 = (*lb)->next->data;
					while (idxs->dis[index] > 0)
					{
						ra_copy(&tmp2);
						idxs->dis[index]--;
						i++;
					}
					if (idxs->save > (*lb)->data && idxs->save < max_int(*lb))
					{
						////printf("are you the choosen one ?\n");
						////printf("idxs->sbe == %d\n", idxs->save);
						////printf("lb datoi = %d\n", (*lb)->data);
						// if (ft_lstsize(*lb) > 248){
						// char c;
						// read(0, &c, 1);
						// }
						// while (idxs->save > (*lb)->data && idxs->save < max_int(*lb))
						// {
						// 	rb(lb);
						// 	save++;
						// 	//printf("zac il craint degun\n");
						// }
					}
					idxs->save = (tmp2)->data;
					(*la)->last2 = (*lb)->data;
					(*la)->last3 = (*lb)->next->data;
					(*la)->last = save;
					return (i);
				}
				else
				{
					////printf("la ->lasterio = %d\n", (*la)->last);
					while (last < 0 && idxs->save > (*lb)->data)
					{
						rrb(lb);
						//printf("d\n");
						// char c;
						// read(0, &c, 1);
						last++;
						save--;
						// (*la)->last++;
						////printf("la ->lasteritorio = %d\n", (*la)->last);
						////printf("lb data por favor senor == %d\n", (*lb)->data);
						////printf("return_data(*lb, ft_lstsize(*lb) == %d\n", return_data(*lb, ft_lstsize(*lb) - 1));
						if (return_data(*lb, ft_lstsize(*lb) - 1) > idxs->save)
						{
							(*la)->last = last;
							last = 0;
						}
					}
					// //////printf("ma direction\n");
					(*la)->last2 = (*lb)->data;
					(*la)->last3 = (*lb)->next->data;
					(*la)->last = save;
					while (idxs->dis[index] >= 0)
					{
						if (idxs->dis[index] == 0)
						{
							idxs->save = (tmp2)->data;
							return (i);
						}
						ra_copy(&tmp2);
						idxs->dis[index]--;
						i++;
					}
					i = i - 1;
					idxs->save = (tmp2)->data;
					(*la)->last2 = (*lb)->data;
					(*la)->last3 = (*lb)->next->data;
					return (i);
				}
				idxs->save = (tmp2)->data;
				(*la)->last2 = (*lb)->data;
				(*la)->last3 = (*lb)->next->data;
				return (i);
			}
		}	
		else if (idxs->pos[index] == -1)
		{
			if ((*la)->last > 0)
			{
				while ((*la)->last > 0)
				{
					rrb(lb);
					// //////printf("tes \n");
					save--;
					(*la)->last--;
				}
				// //////printf("jai pete les plombs\n");
				while (idxs->dis[index] < 0)
				{
					rra_copy(&tmp2);
					idxs->dis[index]++;
					i++;
				}
				idxs->save = tmp2->data;
				(*la)->last2 = (*lb)->data;
				(*la)->last3 = (*lb)->next->data;
				(*la)->last = save;
			}
			else
			{
				while ((*la)->last < 0 && idxs->dis[index] <= 0)
				{
					idxs->dis[index]++;
					rra_copy(&tmp2);
					i++;
				}
				while ((*la)->last < 0)
				{
					rb(lb);
					//printf("d1\n");
					// save--;
					(*la)->last++;
				}
				while (idxs->dis[index] < 0)
				{
					rra_copy(&tmp2);
					idxs->dis[index]++;
					i++;
				}
				idxs->save = tmp2->data;
				(*la)->last2 = (*lb)->data;
				(*la)->last3 = (*lb)->next->data;
				// (*la)->last = save;
			}
		}
	}
	// (*la)->last = 0;
	idxs->save = tmp2->data;
	(*la)->last2 = (*lb)->data;
	(*la)->last3 = (*lb)->next->data;
	delete_list(&tmp2);
	return (i);
}

// int	do_op_ten_last_dis_up(t_list **la, t_list **lb, t_index_b *idxs
				// , t_list *tmp2)
// {
// 	int	i;
// 	int	last;

// 	i = 0;
// 	last = (*la)->last;
// 	while (last + 1 > 0 && idxs->dis[index] > 0)
// 	{
// 		rr(la, lb);
// 		last--;
// 		idxs->dis[index]--;
// 		ra_copy(&tmp2);
// 	}
// 	while (last + 1 > 0)
// 	{
// 		rb(lb);
// 		(*la)->last--;
// 	}
// 	(*la)->last2 = (*lb)->data;
// 	(*la)->last3 = (*lb)->next->data;
// 	while (idxs->dis[index] > 0)
// 	{
// 		ra_copy(&tmp2);
// 		idxs->dis[index]--;
// 		i++;
// 	}
// 	idxs->save = (tmp2)->data;
// 	(*la)->last2 = (*lb)->data;
// 	(*la)->last3 = (*lb)->next->data;
// 	return (i);
// }

void	do_op_ten_dis_equal(t_list **la, t_list **lb, t_index_b *idxs,
												t_list *tmp2){
	////printf("t'es chez toi\n");
	(void)tmp2;
	// (void)idxs;
	// if (ft_lstsize(*lb) == 470)
	////printf("la laassttey == %d\n", (*la)->last);
	////printf("la laassttey22 == %d\n", (*la)->last2);
	if ((*la)->last > 0)
	{
		while ((*la)->last > 0 && (idxs->save < (*lb)->data) && return_data(*lb, ft_lstsize(*lb) - 1) != min_int(*lb))
		{
			rrb(lb);
			// //////printf("fou\n");
			(*la)->last--;
		}
		// //////printf("whats else\n");c
	}
	else
	{
		while ((*la)->last < 0 && (idxs->save < (*lb)->data))
		{
			rb(lb);
			//printf("e\n");
			(*la)->last++;
		}
		// //////printf("lb et lb next apres recale == %d %d\n", (*lb)->data, (*lb)->next->data);
	}
	(*la)->last = (*la)->last2;
	// idxs->save = tmp2->data;
	(*la)->last2 = (*lb)->data;
	(*la)->last3 = (*lb)->next->data;
	////printf("la laassttey FINALOOOO 	== %d\n", (*la)->last);
}

// int	do_op_ten_last_equal(t_list **la, t_list **lb, t_index_b *idxs,
												// t_list *tmp2)
// {
// 	int	i;

// 	i = 0;
// 	if (idxs->pos[(*la)->index] == 1)
// 	{
// 		while (idxs->dis[(*la)->index])
// 		{
// 			ra_copy(&tmp2);
// 			idxs->dis[(*la)->index]--;
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (idxs->dis[(*la)->index] <= 0)
// 		{
// 			rra_copy(&tmp2);
// 			idxs->dis[(*la)->index]++;
// 			i++;
// 		}	
// 	}
// 	idxs->save = tmp2->data;
// 	(*la)->last2 = (*lb)->data;
// 	(*la)->last3 = (*lb)->next->data;
// 	return (i);
// }