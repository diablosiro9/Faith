/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:03:50 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/07 22:31:20 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	try_something(t_list **la, t_list **lb, int save)
{
	int			ret;
	int			y;
	t_index_b	*idxs;
	t_list		*tmp;
	t_list 		*tmp2;

	y = 0;
	ret = 0;
	tmp = (*lb);
	tmp2 = NULL;
	tmp2 = copie_b(&tmp);
	idxs = NULL;
	// (*la)->last = (*la)->last2;
	////printf("savotchino == %d\n", save);
	////printf("la lastoo = %d\n", (*la)->last);
	// if ((*la)->last2 != 0)
	// 	(*la)->last = (*la)->last2;
	////printf("ENTRE && TAILLE LB == %d\n", ft_lstsize(*la));
	// char c;
	// read(0, &c, 1);
	idxs = init_struct_b(idxs);
	if (!idxs)
	{
		// //////printf("tu plantes\n");
		return 0;
	}
	attribute_struct(la, idxs);
	det_pos_first(la, idxs);
	y = return_plus_petit(*idxs);
	////printf("y == %d\n", y);
	idxs->last2 = det(la, y);
	////printf("idx-s>last2 == %d\n", idxs->last2);
	if (ft_lstsize(*lb) == 500)
	{
		free(idxs);
		free(tmp2);
		return 0;
	}
	save = (*la)->last;
	////printf("SAVE === %d\n", save);
	////printf("FIRST LA LAST === %d\n", (*la)->last);
	//////printf("plus vraimemnt\n");
	if (idxs->dis[y] <= 100)
	{
		// //////printf("my\n");
		//////printf("just for me == %d\n", (*lb)->data);
		y = do_op_ra_rra(la, idxs, y);
		// //////printf("y en sortie == %d\n", y);
		idxs->o = y;
		////printf("LA TALLE DE LA  == %d\n", ft_lstsize(*la));
	}
	else
		return -5000;
	////printf("y == %d\n", y);
	save = (*la)->last;
	if (y <= abs(save) || abs(y) <= 70)
	{
		////printf("can see u\n");
		// if (y > 0)
		// {
		// 	while (y > 0)
		// 	{
		// 		ra(la);
		// 		y--;
		// 	}
		// }
		// else
		// {
		// 	while (y < 0)
		// 	{
		// 		rra(la);
		// 		y++;
		// 	}
		// }
		if (y >= 0)
			y = y_up(la, y);
		else
			y = y_down(la, y);
		////printf("y == %d\n", y);
		////printf("LA TAILLE DE LB 333 === %d\n", ft_lstsize(*la));
		(*la)->last = save;
		t_passing pass;
		pass = create_copies(la, lb, tmp2, idxs);
		////printf("LA TAILLE DE LA 444 === %d\n", ft_lstsize(*la));
		////printf("LA TAILLE DE LB 444 === %d\n", ft_lstsize(pass.lb));
		*lb = pass.lb;
		// char c;
		// read(0, &c, 1);
		////printf("000 idxs->i = %d apres et idxs->j apres == %d\n", idxs->i, idxs->j);
		(*la)->last = save;

		if ((*la)->last < 0)
				(*la)->last = (*la)->last - 1;
		////printf("LA LAST == %d\n", (*la)->last);
		if (idxs->i <=  idxs->j && idxs->i != -5000 && idxs->j != -5000)
		{
			// if (idxs->i != 0)
			// 	idxs->i = idxs->i + 1;
			// if (idxs->i == 2)
			// 	idxs->i = idxs->i - 1;
			////printf("first save == %d\n", save);
			if (save == 0)
				(*la)->last = save + idxs->i;
			else
			{
				if ((*la)->last < 0)
					(*la)->last = save - idxs->i;
				else
					(*la)->last = save + idxs->i;
			}
			save = (*la)->last;
			////printf("second save == %d\n", save);
			ret = idxs->i;
			if (y >= 0)
			{
				while (y > 0 && idxs->i > 0)
				{
					rr(la, lb);
					//printf("bizarre le poto\n");
					y--;
					idxs->i--;
					idxs->j++;
				}
				while (y > 0)
				{
					ra(la);
					////printf("3\n");
					y--;
				}
				while (idxs->i > 0)
				{
					rb(lb);
					//printf("kodo\n");
					idxs->i--;
					idxs->j++;
				}
				if ((*la)->data > (*lb)->data)
					
				affichelist(*lb);
			}
			else
			{
				// while (y < 0 && idxs->i > 0)
				// {
				// 	rrr(la, lb);
				// 	////printf("5.1\n");
				// 	y++;
				// 	idxs->i--;
				// }
				while (y < 0)
				{
					rra(la);
					y++;
				}
				while (idxs->i > 0)
				{
					rb(lb);
					idxs->i--;
					idxs->j++;
				}
				// if ((*la)->data > (*lb)->data)
				// 	rb(lb);

			}
			pb(lb, la);
			////printf("tes al alph\n");
			if (ft_lstsize(*lb) == 500)
			{
				if (ret > 0)
				{
					while (ret > 0)
					{
						rrb(lb);
						ret--;
					}
				}
				return 0;
			}
			(*la)->last2 = save;
			if ((*la)->last2 < 0)
				(*la)->last2 = (*la)->last2 - 1;
			////printf("idxs->j -- %d\n", idxs->j);
			// affichelist(*lb);
			save = 0;
			return 0;
		}
		else if (idxs->j < idxs->i && idxs->i != -5000 && idxs->j != -5000)
		{
			// if (idxs->j != 0)
			// 	idxs->j = idxs->j + 1;
			if (idxs->j == 0 && return_data(*lb, ft_lstsize(*lb) - 1) != max_int(*lb))
				idxs->j = (*la)->last;
			// if ((*la)->last < 0)
			if (idxs->save > (*lb)->data && idxs->save < return_data(*lb, ft_lstsize(*lb) - 1))
				idxs->j = 0;
			// 	(*la)->last = (*la)->last - 1;
			idxs->i = (*la)->last;
			ret = idxs->j;
			if (y >= 0)
			{
				////printf("la last0 == %d\n", (*la)->last);
				// while (y > 0 && idxs->j > 0)
				// {
				// 	////printf("la last 0.1 == %d\n", (*la)->last);
				// 	rr(la, lb);
				// 	y--;
				// 	idxs->j--;
				// 	idxs->i++;
				// 	////printf("la last 0.2 == %d\n", (*la)->last);
				// }
				////printf("la last1 == %d\n", (*la)->last);

				while (y > 0)
				{
					ra(la);
					////printf("4\n");
					y--;
				}
				while (idxs->j > 0)
				{
					rrb(lb);
					idxs->j--;
					idxs->i--;
				}
				(*la)->last = idxs->i;
				////printf("la last2 == %d\n", (*la)->last);
				// while ((*la)->last > 0)
				// {
				// 	rrb(lb);
				// 	(*la)->last--;
				// }
			}
			else
			{
				while (y < 0 && idxs->j > 0)
				{
					rrr(la, lb);
					////printf("5.0\n");
					y++;
					idxs->j--;
					idxs->i--;
				}	
				while (y < 0)
				{
					rra(la);
					y++;
				}
				while (idxs->j > 0)
				{
					rrb(lb);
					idxs->j--;
					idxs->i--;
				}
				(*la)->last = idxs->i;
			}
			// (*la)->last = idxs->i;
			// idxs->i = (*la)->last;
			////printf("idxs->i === %d\n", idxs->i);
			////printf("idxs->j = %d\n", idxs->j);
			////printf("la last3 == %d\n", (*la)->last);
			// pb(lb, la);
			// (*la)->last2 = idxs->i;
			// (*la)->last = idxs->i;
			// ////printf("idxs->j -- %d\n", idxs->j);
			// return 0;
			// if (idxs->i == 0 && idxs->j == 0)
			// 	(*la)->last2 = (*la)->last;
			////printf("la last3 == %d\n", (*la)->last);
			(*la)->last2 = (*la)->last;
			////printf("LAAAAAAAAA last3 == %d\n", (*la)->last);
			// if ((*la)->last2 <= 0)
			// {
			// 	while ((*la)->last2 < 0)
			// 	{
			// 		rb(lb);
			// 		////printf("ui\n");
			// 		(*la)->last2++;
			// 	}
			// }
			// else
			// {
			// 	while ((*la)->last2 > 0)
			// 	{
			// 		rrb(lb);
			// 		(*la)->last2--;
			// 	}
			// }
			////printf("ret == %d\n", ret);
			(*la)->last2 = (*la)->last;
			y = (*la)->last2;
			// if (decalage avant sup donc rrb a faire, que nouveau decalage et aussi rb, augmente decalage, sinon soustrait)
			////printf("fin == %d\n", (*la)->last2);
			// (*la)->last = 0;
			pb(lb, la);
			(*la)->last2 = y;
			if (abs((*la)->last2) > ft_lstsize(*lb) / 2 && (*la)->last2 < 0)
				(*la)->last2 = ft_lstsize(*lb) + ((*la)->last2);
			if (abs((*la)->last2) > ft_lstsize(*lb) / 2 && (*la)->last2 > 0)
				(*la)->last2 = ft_lstsize(*lb) - ((*la)->last2);
			////printf("VRAI fin == %d\n", (*la)->last2);
			// affichelist(*lb);
			if ((*la)->last2 < 0)
				(*la)->last2 = (*la)->last2 - 1;
			if (is_tri_reverse(lb) == 1)
			{
				(*la)->last2 = 0;
			}				
			return ret;
		}
		if ((idxs->i == 0 || idxs->j == 0) || idxs->i == -5000 || idxs->j == -5000)
		{
			if (y >= 0)
			{
				while (y > 0)
				{
					ra(la);
					y--;
					////printf("0\n");
				}
			}
			else
			{
				while (y < 0)
				{
					rra(la);
					y++;
				}
			}
			return 0;	
		}
		if 	(idxs->i == -5000)
		{
			if (y >= 0)
			{
				while (y >= 0 && idxs->j > 0)
				{
					rr(la, lb);
					//printf("dam\n");
					y--;
					idxs->j--;
				}
				while (y >= 0)
				{
					ra(la);
					////printf("1\n");
					y--;
				}
				while (idxs->j >= 0)
				{
					rb(lb);
					idxs->j--;
				}
			}
			else
			{
				while (y <= 0)
				{
					rra(la);
					y++;
				}
				while (idxs->j > 0)
				{
					rb(lb);
					idxs->j--;
				}
			}
			(*la)->last = 0;
			return 0;
		}
		else if (idxs->j == -5000)
		{
			if (y >= 0)
			{
				// while (y >= 0 && idxs->i >= 0)
				// {
				// 	rr(la, lb);
				// 	y--;
				// 	idxs->j--;
				// }
				while (y > 0)
				{
					ra(la);
					////printf("2\n");
					y--;
				}
				while (idxs->i > 0)
				{
					rrb(lb);
					idxs->i--;
				}
			}
			else
			{
				while (y < 0 && idxs->i > 0)
				{
					rrr(la, lb);
					////printf("5\n");
					y++;
					idxs->i--;
				}
				while (y <= 0)
				{
					rra(la);
					y++;
				}
				while (idxs->i > 0)
				{
					rrb(lb);
					idxs->i--;
				}
			}
			(*la)->last = 0;
			return 0;
		}
		pb(lb, la);
		////printf("idxs->i = %d apres et idxs->j apres == %d\n", idxs->i, idxs->j);
		// char c;
		// read(0, &c, 1);
		// char c;
		// read(0, &c, 1);
	}
	return (ret);
}

t_passing	create_copies(t_list **la, t_list **lb, t_list *tmp2, t_index_b *idxs)
{
	// int	save;
	t_list	*save_l;
	t_list	**tmp3 = NULL;
	t_list	**tmp4 = NULL;
	t_passing	pass;

	// pass = NULL;
	save_l = tmp2;
	//////printf("tmp2 = %d et taille tmp2 = %d\n", tmp2->data, ft_lstsize(tmp2));
	tmp3 = malloc(sizeof(t_list **));
	tmp4 = malloc(sizeof(t_list **));
	*tmp3 = copie_b(&tmp2);
	*tmp4 = copie_b(&save_l);
	pass = *(t_passing *)malloc(sizeof(t_passing ));
	////printf("LA LAST ====== %d\n", (*la)->last);
	////printf("TAILLLLE LB === %d\n", ft_lstsize(*lb));
	////printf("not okey\n");
	// if ()
	// 	return ;
	pass.la = *la;
	// ÷ß////printf("pass->la[3]->last == %d et max int de la dans pass = %d\n", pass.la->last, max_int(pass.la));
	
	pass.lb = *lb;
	pass.tmp3 = *tmp3;
	// ////printf("pass lb -- %d\n", ft_lstsize(pass.lb));
	// char c;
	// read(0, &c, 1);
	// pass = attribute_pass(pass, la, lb, tmp3);
	////printf("loading\n");
	pass.tmp4 = *tmp4;
	pass.idxs = idxs;
	////printf("issue de secours\n");
	////printf("TAILLLLE LB11 === %d\n", ft_lstsize(*lb));

	// idxs->o = nombre de moove;
	if (is_tri_reverse(&pass.lb) == 1)
    {
		////printf("does it u\n");
		////printf("TAILLLLE LB 22=== %d\n", ft_lstsize(*lb));
		
        if (pass.idxs->last2 > max_int(pass.lb))
            return pass;
        else
        {
			////printf("pass.tmp3->data == %d\n", pass.tmp3->data);
            while (pass.tmp3->data > pass.idxs->last2)
            {
                rb_copy(&pass.tmp3);
                pass.idxs->i++;
				// ////printf(" 1) pass.idxs->i == %d\n", pass.idxs->i);
				// char c;
				// read(0, &c, 1);
			}
			////printf("pass.tmp3->data dos == %d\n", pass.tmp3->data);
			////printf("pass.idxs->last2 == %d\n", pass.idxs->last2);
			////printf("ass.tmp4->data == %d\n", pass.tmp4->data);
            while (pass.idxs->last2 < pass.tmp4->data)
            {
                rrb_copy(&pass.tmp4);
                pass.idxs->j++;
				////printf(" 2) pass.idxs->j == %d\n", pass.idxs->j);
				// char c;
				// read(0, &c, 1);
            }
			////printf("pass.tmp4->data == %d\n", pass.tmp4->data);
            while (pass.idxs->last2 > pass.tmp4->data)
            {
                rrb_copy(&pass.tmp4);
                pass.idxs->j++;
				// ////printf("3) pass.idxs->j == %d\n", pass.idxs->j);
				// char c;
				// read(0, &c, 1);
            }
            if (pass.idxs->last2 < pass.tmp4->data)
                pass.idxs->j = pass.idxs->j + 1;
        }

    }
    else
    {
		////printf("or u\n");
		////printf("TAILLLLE LB 333 === %d\n", ft_lstsize(*lb));

        if (pass.la->last != 0)
        {
			////printf("u\n");
            //Surement des RB FAITS
            if (pass.la->last > 0)
			{
				////printf("why]\n");
                pass = decalage_rb(pass);
				////printf("pass.idxs->i == %d pass.idxs->j == %d\n", pass.idxs->i, pass.idxs->j);
				////printf("TAILLLLE LB 4444 === %d\n", ft_lstsize(pass.lb));

				// char c;
				// read(0, &c, 1);
				return pass;
			}
			else
			{
				////printf("TAILLLLE LB === %d\n", ft_lstsize(*lb));
				////printf("not\n");
                pass = decalage_rrb(pass);
				////printf("pass.idxs->j == %d\n", pass.idxs->j);
				////printf("TAILLLLE LB 5555 === %d\n", ft_lstsize(pass.lb));

				// char c;
				// read(0, &c, 1);
				return pass;
			}
		}
		else
		{
			if (pass.idxs->last2 > max_int(pass.lb))
         	   return pass;
        	else
			{
				if (pass.idxs->last2 < pass.lb->data)
				{
					while (pass.idxs->last2 < pass.tmp3->data)
					{
						rb_copy(&pass.tmp3);
						pass.idxs->i++;
						// ////printf(" 1) pass.idxs->i == %d\n", pass.idxs->i);
						// char c;
						// read(0, &c, 1);
					}
					while (pass.idxs->last2 < pass.tmp4->data)
					{
						rrb_copy(&pass.tmp4);
						pass.idxs->j++;
						////printf(" 2) pass.idxs->j == %d\n", pass.idxs->j);
						// char c;
						// read(0, &c, 1);
					}
					while (pass.idxs->last2 > pass.tmp4->data)
					{
						rrb_copy(&pass.tmp4);
						pass.idxs->j++;
						// ////printf("3) pass.idxs->j == %d\n", pass.idxs->j);
						// char c;
						// read(0, &c, 1);
					}
					if (pass.idxs->last2 < pass.tmp4->data)
						pass.idxs->i = pass.idxs->i - 1;
				}
				else
				{
					while (pass.idxs->last2 > pass.tmp3->data)
					{
						rb_copy(&pass.tmp3);
						pass.idxs->i++;
						// ////printf(" 1) pass.idxs->i == %d\n", pass.idxs->i);
						// char c;
						// read(0, &c, 1);
					}
					while (pass.idxs->last2 > pass.tmp4->data)
					{
						rrb_copy(&pass.tmp4);
						pass.idxs->j++;
						////printf(" 2) pass.idxs->j == %d\n", pass.idxs->j);
						// char c;
						// read(0, &c, 1);
					}
					// while (pass.idxs->last2 < pass.tmp4->data)
					// {
					// 	rrb_copy(&pass.tmp4);
					// 	pass.idxs->j++;
					// 	////printf("3) pass.idxs->j == %d\n", pass.idxs->j);
					// 	// char c;
					// 	// read(0, &c, 1);
					// }
					if (pass.idxs->last2 < pass.tmp4->data)
						pass.idxs->j = pass.idxs->j - 1;
				}
			}
		}
		////printf("no no no\n");
    }   
	////printf("sors\n");
	return pass;
}

t_passing	attribute_pass(t_passing pass, t_list **la, t_list **lb, t_list **tmp3)
{
	pass.la = *la;
	////printf("pass->la[3]->data == %d\n", pass.la->data);
	pass.lb = *lb;
	////printf("pass->lb->data == %d\n", pass.lb->data);
	pass.tmp3 = *tmp3;
	return (pass);
}

t_passing	decalage_rrb(t_passing pass)
{
	////printf("TAILLLLE LB 5.0 === %d\n", ft_lstsize(pass.lb));

	if (pass.la->last < 0)
	{
		//si prochain push superieur au sommet
		////printf("pass.idxs->last2 == %d\n", pass.idxs->last2);
		////printf("max_int(pass.lb) == %d\n", max_int(pass.lb));
		if (pass.idxs->last2 > max_int(pass.lb))
		{
			////printf("superieur \n");
			while (pass.la->last <= 0)
			{
				rb_copy(&pass.tmp3);
				pass.la->last++;
				////printf("uooo\n");
				// char c;
				// read(0, &c, 1);
				pass.idxs->i++;
				pass.idxs->j = 5000;
			}
			////printf("TAILLLLE LB 5.1 === %d\n", ft_lstsize(pass.lb));
			// return pass;
		}
		//si prochain push inferieur au last push mais sup au min de b, donc dans l intervalle de rrb deja fait
		// ////printf("pass-idxs[9]->last2 == %d\n", pass->idxs[9].last2);
		else if (pass.idxs->last2 < pass.lb->data && pass.idxs->last2 > min_int(pass.lb))
		{
			////printf("tes vers la non\n");
			while (pass.idxs->last2 < pass.tmp3->data)
			{
				rb_copy(&pass.tmp3);
				pass.idxs->i++;
				// pass.idxs->j = 5000;
				pass.la->last++;
			}
			while (pass.idxs->last2 < pass.tmp4->data)
			{
				rrb_copy(&pass.tmp4);
				pass.idxs->j++;
				if (pass.idxs->last2 < pass.tmp4->data)
					pass.
					idxs->j = pass.idxs->j - 1;
			}
			while (pass.idxs->last2 > pass.tmp4->data)
			{
				rrb_copy(&pass.tmp4);
				pass.idxs->j++;
				// if (pass.idxs->last2 < pass.tmp4->data)
				// 	pass.
				// 	idxs->j = pass.idxs->j - 1;
			}
			// return pass;
		}
		//si prochain push superieur au last push, n'appartient donc pas au decalage
		else
		{
			if (pass.idxs->last2 > pass.lb->data)
			{
				while (pass.idxs->last2 > pass.tmp3->data)
				{
					rb_copy(&pass.tmp3);
					pass.idxs->i++;
				}
				//transition des plus petits renvoyes en bas au plus grand qui arrive au sommet de b
				if (pass.idxs->last2 < pass.tmp3->data)
				{
					while (pass.idxs->last2 < pass.tmp3->data)
					{
						rb_copy(&pass.tmp3);
						pass.idxs->i++;
					}
				}
				while (pass.idxs->last2 > pass.tmp4->data)
				{
					rrb_copy(&pass.tmp4);
					pass.idxs->j++;
					if (pass.idxs->last2 < pass.tmp4->data)
						pass.idxs->j = pass.idxs->j - 1;
				}
			}
			else
			{
				while (pass.idxs->last2 < pass.tmp3->data)
				{
					rb_copy(&pass.tmp3);
					pass.idxs->i++;
				}
				//transition des plus petits renvoyes en bas au plus grand qui arrive au sommet de b
				if (pass.idxs->last2 > pass.tmp3->data)
				{
					while (pass.idxs->last2 > pass.tmp3->data)
					{
						rb_copy(&pass.tmp3);
						pass.idxs->i++;
					}
				}
				while (pass.idxs->last2 < pass.tmp4->data)
				{
					rrb_copy(&pass.tmp4);
					pass.idxs->j++;
				}
			}
		}
		// return pass;
	}
	////printf("TAILLLLE LB 5.3 === %d\n", ft_lstsize(pass.lb));
	return pass;
}

t_passing	decalage_rb(t_passing pass)
{
	int	save;

	save = pass.la->last;
	if (pass.la->last > 0)
	{
		// pass.la->last = pass.la->last + 1;
		////printf("max int -> pass.lb == %d\n", max_int(pass.lb));
		if (pass.idxs->last2 > max_int(pass.lb))
		{
			////printf("pass.idxs->last 2 == %d\n", pass.idxs->last2);
			////printf("max_int(pass.lb) == %d\n", max_int(pass.lb));
			if (pass.idxs->last2 > pass.tmp3->data)
			{
				while (save > 0)
				{
				// char c;
				// read(0, &c, 1);
					////printf("toi5\n");
					rrb_copy(&pass.tmp3);
					save--;
					pass.la->last--;
					pass.idxs->j++;
					pass.idxs->i = 5000;
				}
				if (pass.tmp3->data == min_int(pass.lb))
					pass.idxs->j = pass.idxs->j - 1;
				// if (pass.idxs->i < pass.idxs->j)
				// 	pass.idxs->j = 5000;
			}
			////printf("tmp 3 == %d\n", pass.tmp3->data);
			////printf("tmp 4 == %d\n", pass.tmp4->data);
			// pass.idxs->j = 0;
			// while (pass.idxs->last2 > pass.tmp4->data && pass.tmp4->data != min_int(pass.lb))
			// {
			// 	rrb_copy(&pass.tmp4);	
			// 	////printf("tmp 4 == %d\n", pass.tmp4->data);
			// 	pass.idxs->j++;
			// }
			// ////printf("tmp 4 == %d\n", pass.tmp4->data);
			// while (pass.idxs->last2 < pass.tmp4->data)
			// {
			// 	rrb_copy(&pass.tmp4);
			// 	pass.idxs->j++;
			// }
			////printf("tmp 4 == %d\n", pass.tmp4->data);
			if (pass.idxs->i < pass.idxs->j)
				pass.idxs->j = 5000;
			// if (pass.tmp3->data < pass.idxs->last2)
			// {
			// 	rb.copy(&pass.tmp3);
			// }
			////printf("ft_lstsize->llb == %dd\n", ft_lstsize(pass.lb));
			
			return pass;
		}
		// se trouve dans l'intervalle decale par les rb precedents (entre last push et sommet b initiale)
		else if (pass.idxs->save > pass.lb->data && pass.idxs->save < max_int(pass.lb))
		{
			////printf("does i see u mt boy\n");
			////printf("pass.tmp\n");
			////printf("idxs->save == %d\n", pass.idxs->save);
			while (pass.idxs->save > pass.tmp3->data)
			{
				// ////printf("pass.tmp3->data  000 -- %d\n",  pass.tmp3->data);
				rb_copy(&pass.tmp3);
				pass.idxs->i++;
			}
			while (pass.idxs->save < pass.tmp3->data)
			{
				////printf("pass.tmp3->data 111 -- %d\n",  pass.tmp3->data);
				rb_copy(&pass.tmp3);
				pass.idxs->i++;
			}
			////printf("tmp 3 == %d\n", pass.tmp3->data);
			while (pass.idxs->save > pass.tmp4->data)
			{
				////printf("pass.tmp4->data -- %d\n",  pass.tmp4->data);
				rrb_copy(&pass.tmp4);
				pass.idxs->j++;
			}
			////printf("tmp 4 == %d\n", pass.tmp4->data);
			if (pass.idxs->save < pass.tmp4->data && pass.idxs->save < pass.tmp4->next->data)
			{
				while (pass.idxs->save < pass.tmp4->data)
				{
					////printf("pass.tmp4->data 111 -- %d\n",  pass.tmp4->data);
					rrb_copy(&pass.tmp4);
					pass.idxs->j++;
				}
			// pass.idxs->i = pass.idxs->i + 1;
			}
			if (pass.idxs->save > pass.tmp4->data)
				pass.idxs->j = pass.idxs->j - 1;
			
			////printf("idxs0>j == %d\n", pass.idxs->j);
			// if (pass.idxs->save < pass.tmp3->data)
			// {
			// 	pass.idxs->i = pass.idxs->i + 1;
			// } 	
		}
		else if (pass.idxs->save < pass.lb->data)
		{
			////printf("u are the ONE\n");
			while (pass.idxs->save < pass.tmp3->data)
			{
				rb_copy(&pass.tmp3);
				pass.idxs->i++;
				pass.la->last++;
			}
			////printf("tmp3 == %d\n", pass.tmp3->data);
			while (pass.idxs->save < pass.tmp4->data)
			{
				rrb_copy(&pass.tmp4);
				pass.idxs->j++;
				pass.la->last--;
			}
			while (pass.idxs->save > pass.tmp4->data)
			{
				rrb_copy(&pass.tmp4);
				pass.idxs->j++;
				pass.la->last--;
			}
			////printf("tmp4 == %d\n", pass.tmp4->data);
		}	//normalement tout recale, last == 0 ou -1 si le min vient de remonter
		// if (pass.idxs->save > pass.tmp4->data)
		// {
		// 	while (pass.idxs->save > pass.tmp4->data)
		// 	{
		// 		rrb_copy(&pass.tmp4);
		// 		pass.idxs->i++;
		// 		pass.la->last--;
		// 	}
		// }
		if (pass.idxs->save < pass.tmp3->data)
			pass.idxs->i = pass.idxs->i - 1;
		if (pass.idxs->save < pass.tmp4->data)
			pass.idxs->j = pass.idxs->j - 1;
	}
	return (pass);
}

int	y_up(t_list **la, int y)
{
	int	i;
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *la;
	tmp2 = copie_b(&tmp);
	i = y;
	////printf("TAILLE DE LA  2222ß == %d\n", ft_lstsize(*la));
	// //////printf("la == %d\n", (*la)->data);
	if (y == 0)
		return 0;
	while (y > 0)
	{
		ra_copy(&tmp2);
		// //////printf("la == %d\n", (*la)->data);
		y--;
	}
	return (i);
	//////printf("la dara = %d\n", (*la)->data);
	// if ((*la)->data > eleven_first_min(la))
	// 	rra(la);
}

int	y_down(t_list **la, int y)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;

	i = y;
	tmp = *la;
	tmp2 = copie_b(&tmp);
	while (y < 0)
	{
		rra_copy(&tmp2);
		y++;
	}
	return (i);
}

void	idxs_i_fast(t_list **la, t_list **lb, t_index_b *idxs)
{
	while (idxs->i > 0)
	{
		rrb(lb);
		idxs->i--;
		(*la)->last--;
	}
}

void	idxs_j_fast(t_list **la, t_list **lb, t_index_b *idxs)
{
	//////printf("idxs->j dans opti == %d\n", idxs->j);
	while (idxs->j > 0)
	{
		rb(lb);
		idxs->j--;
		(*la)->last++;
		////printf("est ce toi\n");
	}
	// //////printf("adidas\n");
}

int	abs(int c)
{
	int c2;

	c2 = -c;
	if (c >= 0)
		return c;
	else 
		return c2;
}

int	det(t_list **la, int y)
{
	int	ret;

	ret = 0;
	if (y == 0)
		ret = min_int(*la);
	else if (y == 1)
		ret = second_first_min(la);
	else if (y == 2)
		ret = third_first_min(la);
	else if (y == 3)
		ret = four_first_min(la);
	else if (y == 4)
		ret = five_first_min(la);
	else if (y == 5)
		ret = six_first_min(la);
	else if (y == 6)
		ret = seven_first_min(la);
	else if (y == 7)
		ret = eight_first_min(la);
	else if (y == 8)
		ret = nine_first_min(la);
	else if (y == 9)
		ret = ten_first_min(la);
	else if (y == 10)
		ret = eleven_first_min(la);
	return (ret);
}