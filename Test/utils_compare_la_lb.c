/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compare_la_lb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:59:59 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_your_life(t_list **la, t_list **lb)
{
	if (la)
	{
		condi(la, lb);
		delete_list(la);
	}
}

int	compare_la_lb(t_list **la, t_list **lb, t_index *idxs)
{
	if (case_less_one(la, lb) == -1)
		return (-1);
	if ((*la)->data < (*lb)->data)
	{
		if (top_la_sec_lb(la, lb) == -1)
			idxs->z = -1;
		if (ft_lstsize(*lb) > 1 && ft_lstsize(*la) >= 1 && idxs->z != -1)
		{
			idxs->i = check_before_rb_cent(la, lb);
			if (ft_lstsize(*lb) >= 3)
				idxs->j = check_before_rrb_cent(la, lb) - 1;
		}
		choose_minus(lb, idxs);
	}
	idxs->i = finish_func(la, lb, idxs);
	return (idxs->i);
}

// RES =  COMPARE_ELEVEN -> NOMBRE COUPS POUR METTRE + RAPIDE EN HAUT,
//  PAS ENCORE FAIT (CHERCHE A OPTI AVEC B)
// RECALE B DU DERNIER PUSH, PAR RR OU RRR SI POSSIBLE POUR MONTER LE PROCHAIN,
//  SI PAS POSSIBLE D'ABORD RECALE, PUIS REMONTER NEXT
// DIRECT BOTTOM = PROCHAIN VA EN BAS MAIS B TOUJOURS PAS RECALER,
//  A FAIRE AVANT DE REMONTER LE SUIVANT (DONC AVANT OU PDT QUIL BOUGE)
// DO_FOR_REAL = SI SWAP OKAY, RECALE D'ABORD B, REMONTER NEXT_PUSH ET ENVOYER
// suite do_for_real = Check nombre de rb ou rrb necessaire pour le prochain
//  et donne a i le nb de coups a faire, MAIS B TJR PAS REMONTER TRIER

int	compare_la_lb_f(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	int	i;
	int j;
	int	save;

	i = 0;
	j = 0;
	save = 0;
	////printf("ON EST ENSEMBLE\n");
	if (!la || !lb)
		return (-1);
	////printf("idxs=>save = %d\n", idxs->save);
	if (idxs->save > eleven_first_min(la))
	{
		idxs->o = -100;
		return (-100);
	}
	if (idxs->save < min_int(*lb))
	{
		direct_bottom(la, lb, idxs, res);
		// if (ft_lstsize(*lb) > 2)
		// 	//////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
		pb(lb, la);
		if (ft_lstsize(*lb) > 3){
			//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
			//char c;
			//read(0, &c, 1);
		}
		//////char c;
		//////read(0, &c, 1);
		rb(lb);
		return (-100);
	}
	if (idxs->save < (*lb)->data)
	{
		// try_something(la, lb);
		////printf("avant fdo for real\n");
		do_for_real(la, lb, idxs, res);
		i++;
	}
	// else if (idxs->save > max_int(*lb) && (*la)->last2 == 0)
	// {

	// }
	else if ((*la)->last2 != 0)
	{
		////printf("EL DERNIER LASTO = %d\n", (*la)->last);
		////printf("EL DERNIER LASTO22 = %d\n", (*la)->last2);
		// j = (*la)->last2;
		////printf("ON SE SUIT LA LAST2 == %d\n", (*la)->last2);
		if ((*la)->last2 > 0)
		{
			if (res > 0)
			{
				////printf("res sup == %d\n", res);
				////printf("ON SE SUIT LA LAST2 == %d\n", (*la)->last2);
				// j = (*la)->last2;
				////printf("lb11 comme demande == %d, quant a idxs->save == %d\n", (*lb)->data, idxs->save);
				while (res > 0)
				{
					ra(la);
					res--;
					i++;
				}
				while (j > 0 && (*lb)->data < idxs->save)
				{
					rrb(lb);
					j--;
					
				}
				(*la)->last = 0;
				(*la)->last2 = 0;
			}
			else
			{
				// j = (*la)->last2;
				////printf("la variable j de mehdi (pour melo qui comprend pas)<-(pour mehdi qui comprend plus) == %d\n", j);
				// if (ft_lstsize(*lb) > 183)
				// {
				// 	char c;
				// 	read(0, &c, 1);
				// }
				while (res < 0 && j > 0 && (*lb)->data < idxs->save)
				{
					rrr(la, lb);
					//printf("432\n");
					res++;
					j--;
					i++;
					////printf("lb0 comme demande == %d, quant a idxs->save == %d\n", (*lb)->data, idxs->save);
				}
				while (res < 0)
				{	
					rra(la);
					res++;
					i++;
				}
				while (j > 0 && (*lb)->data < idxs->save)
				{
					rrb(lb);
					j--;
					//printf("jamaique\n");
				}
				// (*la)->last = 0;
				// (*la)->last2 = 0;
			}

		}
		else
		{
			if (res > 0)
			{
				while (j < 0 && res > 0 && (*lb)->data < idxs->save)
				{
					rr(la, lb);
					//printf("waiche\n");
					j++;
					res--;
					i++;
				}
				while (res)
				{
					ra(la);
					res--;
					i++;
				}
				while (j < 0 && (*lb)->data < idxs->save)
				{
					rb(lb);
					//printf("zac est bo\n");
					j++;
				}
			}
			else
			{		
				while (res < 0)
				{	
					rra(la);
					res++;
					i++;
				}
				while (j < 0 && (*lb)->data > idxs->save)
				{
					rb(lb);
					//printf("efomewkfq\n");
					j++;
				}
			}
		}
		// return (idxs->o);
	}
	////printf("EL DERNIER LASTO = %d\n", (*la)->last);
	////printf("EL DERNIER LASTO22 = %d\n", (*la)->last2);
	idxs->i = check_before_rb(lb, idxs);
	if (ft_lstsize(*lb) > 3)
		idxs->j = check_before_rrb(lb, idxs);
	if (idxs->i < idxs->j && idxs->i != -5000)
	{
		while (idxs->i < 0)
		{
			rb(lb);
			i++;
		}
	}
	////printf("la last == %d\n", (*la)->last);
	save = (*la)->last;
	if ((idxs->z != 0 || idxs->y != 0) && i != 0 && idxs->o != 0)
	{
		// if (ft_lstsize(*lb) > 2)
		
		// i = (*la)->last;
		// 	//////printf("lb && lb->next == %d %d\n", (*lb)->data, (*lb)->next->data);
		pb(lb, la);
		if (ft_lstsize(*lb) > 3){
			//////printf("lb avant push == %d et lb next == %d\n", (*lb)->next->data, (*lb)->next->next->data);
			//char c;
			//read(0, &c, 1);
		}
		//////char c;
		//////read(0, &c, 1);
	}
	(*la)->last = save;
	// (*la)->last = i;
	// //////printf("idxs sav === %d\n", idxs->save);
	// // try_something(la, lb);
	// //////printf("avatn remover\n");
	////printf("lassssterrrey == %d\n", (*la)->last);
	return (remove_in_func(la, lb, idxs));
}

void	direct_bottom(t_list **la, t_list **lb, t_index_b *idxs, int res)
{
	if (idxs->save < min_int(*lb))
	{
		if (res > 0 && ((*la)->last && (*la)->last > 0))
		{
			while (res && (*la)->last)
			{
				rr(la, lb);
				//printf("not bad\n");
				res--;
				(*la)->last--;
			}
			while ((*la)->last > 0)
			{
				rb(lb);
				//printf("cbm \n");
				(*la)->last--;
			}
			while (res)
			{
				ra(la);
				res--;
			}
		}
		else if (res < 0 && ((*la)->last && (*la)->last > 0))
		{
			while ((*la)->last > 0)
			{
				rb(lb);
				//printf("lol\n");
				(*la)->last--;
			}
			while (res < 0)
			{
				rra(la);
				res++;
			}
		}
		else if (res > 0 && (*la)->last < 0)
		{
			while ((*la)->last <= 0)
			{
				rrb(lb);
				//printf("j\n");
				(*la)->last++;
			}
			while (res)
			{
				ra(la);
				res--;
			}
		}
		else if (res < 0 && (*la)->last < 0)
		{
			while (res <= 0 && (*la)->last <= 0)
			{
				rrr(la, lb);
				res++;
				idxs->next_move++;
			}
			while ((*la)->last <= 0)
			{
				rrb(lb);
				//printf("k\n");
				(*la)->last++;
			}
			while (res <= 0)
			{
				rra(la);
				res++;
			}
		}
		else
		{
			if (res < 0)
			{
				while (res < 0)
				{
					rra(la);
					res++;
				}
			}
			else
			{
				while (res)
				{
					ra(la);
					res--;
				}
			}
		}
	}
}
