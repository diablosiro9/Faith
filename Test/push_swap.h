/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:34:15 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/06 13:14:32 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct t_list
{	
	int				last;
	int				last2;
	int				last3;
	int				data;
	struct t_list	*next;
}t_list;

typedef struct s_index
{
	int	i;
	int	j;
	int	y;
	int	z;
	int	o;
}	t_index;

typedef struct s_index_f
{
	int	pos[5];
	int	dis[5];
}	t_index_f;

typedef struct s_index_b
{
	int	pos[11];
	int	dis[11];
	int	i;
	int	j;
	int	y;
	int	z;
	int	o;
	int	save;
	int	next_move;
	int	last;
	int	last2;
}	t_index_b;

typedef struct s_passing
{
	t_list 		*la;
	t_list	 	*lb;
	t_list 		*tmp3;
	t_list 		*tmp4;
	t_index_b 	*idxs;
}	t_passing;

void	swap_ten_last_up_res_down(t_list **la, t_list **lb, int res);
int	is_tri_reverse(t_list **sta);
t_passing	attribute_pass(t_passing pass, t_list **la, t_list **lb, t_list **tmp3);
t_passing	decalage_rb(t_passing pass);
t_passing	decalage_rrb(t_passing pass);
int		det(t_list **la, int y);
int		abs(int c);
t_passing	create_copies(t_list **la, t_list **lb, t_list *tmp2, t_index_b *idxs);
int		try_something(t_list **la, t_list **lb, int save);
void			add_to_remove(t_list **la, t_list **lb, t_index_b *idxs);
int			remove_in_func_ten(t_list **la, t_list **lb, t_index_b *idxs);
int			compare_la_lb_f_ten(t_list **la, t_list **lb, t_index_b *idxs,
				int res);
int			swap_ten_is_okay(t_list **la, t_index_b *idxs);
void		direct_bottom_ten(t_list **la, t_list **lb, t_index_b *idxs,
				int res);
void		do_for_real_ten(t_list **la, t_list **lb, t_index_b *idxs,
				int res);
void		attribute_struct_ten(t_list **la, t_index_b *idxs);
int			compare_ten_first(t_list **la, t_list **lb, t_index_b *idxs);
int			do_op_ra_rra_ten(t_list **la, t_list **lb, t_index_b *idxs,
				int index);
void		det_pos_first_ten(t_list **la, t_index_b *idxs);
int			return_plus_petit_ten(t_list **la, t_index_b idxs);
int			plus_petit_ten(t_list **la, t_index_b idxs, int index);
void		rrr_copy(t_list **la, t_list **lb);
void		rr_copy(t_list **la, t_list **lb);
int			main_rrb_copy_cent(t_list **la, t_list **tmp2, int i);
int			all_rrb_cent(t_list **la, t_list *tmp2, int i);
int			do_rrb_copy_cent(t_list **la, t_list **tmp2, int i);
int			check_before_rb_cent(t_list **la, t_list **lb);
int			check_before_rrb_cent(t_list **la, t_list **lb);
int			is_tri(t_list **sta);
int			str_letter(char *s);
void		check_error(char **av);
void		lagalere(void);
t_list		*or_you(int ac, char **av, t_list *la, t_list *tmp);
t_list		*maybe_you(int ac, char **av, t_list *la, t_list *tmp);
void		do_your_life(t_list **la, t_list **lb);
int			all_rrb(t_list *tmp2, t_index_b *idxs, int i);
void		start_rrb(t_list *tmp2, int i);
int			do_op_ra_rra(t_list **la, t_index_b *idxs, int index);
int			return_plus_petit(t_index_b idxs);
int			plus_petit(t_index_b idxs, int index);
void		attribute_struct(t_list **la, t_index_b *idxs);
int			ft_atoi(char const *s);
int			do_atoi(char const *s, int i, int res, int new_res);
void		error_atoi(int sign, int res);
void		det_pos_first(t_list **la, t_index_b *idxs);
//RULES
void		rra(t_list **l);
void		sa(t_list **la);
void		sb(t_list **lb);
void		ra(t_list **l);
void		pa(t_list **la, t_list **lb);
void		pb(t_list **lb, t_list **la);
void		rrb(t_list **l);
void		rb(t_list **l);
void		rb_copy(t_list **l);
void		rrb_copy(t_list **l);
void		ra_copy(t_list **l);
void		rra_copy(t_list **l);
void		rrr(t_list **la, t_list **lb);
void		rr(t_list **la, t_list **lb);

// Utils
void		condi(t_list **la, t_list **lb);
t_list		*malloc_cell(int data);
int			nb_cell(t_list *l);
void		affichelist(t_list *l);
int			check_order(t_list *l);
int			return_data(t_list *l, int pos);
void		change_data(t_list **l, int pos, int new);
int			max_int(t_list *l);
int			min_int(t_list *l);
int			pos_max_cell(t_list *l);
int			pos_min_cell(t_list *l);
int			dist_top_bottom(t_list **la, int min);
int			doublon(t_list **l);
t_list		*copie_b(t_list **lb);
int			size_double(char **s);
//FT_LST
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		**ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstdeletefirst(t_list **lst);
void		ft_lstdeletelast(t_list *lst);
void		delete_list(t_list **l);

//CAS 2
void		ft_case_two_reverse(t_list **l);
void		ft_case_two(t_list **l);

//CAS 3
void		ft_case_three(t_list **l);
void		ft_case_three_reverse(t_list **l);
void		case_123(t_list **l);
void		case_132(t_list **l);
void		case_213(t_list *l);
void		case_231(t_list *l);
void		case_312(t_list **l);
void		case_321(t_list *l);
void		case_213_reverse(t_list *l);
void		case_231_reverse(t_list *l);
void		case_312_reverse(t_list **l);
void		case_321_reverse(t_list *l);
void		case_123_reverse(t_list **l);
void		case_132_reverse(t_list **l);
void		do_123_reverse(int i, int j, t_list **l, t_list *tmp);
void		do_three(t_list *tmp);
void		do_three2(t_list *tmp);
void		do_three_all(t_list *tmp);
int			condi_check_order(t_list *tmp);

//CAS 4
void		push_min_four(t_list **la, t_list **lb);
void		push_high_four(t_list **la, t_list **lb);
void		move_high_four(int j, t_list **la, t_list **lb);
void		move_min_four(int j, t_list **la, t_list **lb);

//CAS 5
void		ft_case_five(t_list **la, t_list **lb);
void		ft_case_five_reverse(t_list **la, t_list **lb);
void		push_highest_five(t_list **la, t_list **lb);
t_list		*push_min_five(t_list **la, t_list **lb);
void		move_highest_five(int j, t_list **la, t_list **lb);

//CAS 100
void		ft_case_hundred(t_list **la, t_list **lb);
void		just_do_it(t_list **la, t_list **lb);
void		sort_range(t_list **la, t_list **lb);
void		do_sec_range(t_list **la, t_list **lb);
void		do_third_range(t_list **la, t_list **lb);
void		do_four_range(t_list **la, t_list **lb);
void		do_last_range(t_list **la, t_list **lb);
int			compare_la_lb(t_list **la, t_list **lb, t_index *idxs);
void		compare_five_first(t_list **la);
int			second_first_min(t_list **la);
int			third_first_min(t_list **la);
int			four_first_min(t_list **la);
int			five_first_min(t_list **la);
int			pos_second_min(t_list *l);
int			pos_third_min(t_list *l);
int			pos_four_min(t_list *l);
int			pos_five_min(t_list *l);
int			dist_top_bottom_five(t_list **la, int min);
void		sort_range2(t_list **la, t_list **lb);
void		sort_range3(t_list **la, t_list **lb);
void		sort_range4(t_list **la, t_list **lb);
void		sort_range5(t_list **la, t_list **lb);

//CAS 500
void		ft_case_five_hundred(t_list **la, t_list **lb);
void		just_do_it_f(t_list **la, t_list **lb, t_index_b *idxs);
int			compare_eleven_first(t_list **la, t_index_b *idxs);
int			compare_la_lb_f(t_list **la, t_list **lb, t_index_b *idxs, int res);
int			check_before_rb(t_list **lb, t_index_b *idxs);
int			check_before_rrb(t_list **lb, t_index_b *idxs);
void		last_for_la(int z, t_list **la, t_list **lb);
int			check_before_push(t_list **la, t_list **lb);
int			pos_six_min(t_list *l);
int			pos_seven_min(t_list *l);
int			pos_eight_min(t_list *l);
int			pos_nine_min(t_list *l);
int			pos_ten_min(t_list *l);
int			pos_eleven_min(t_list *l);
int			pos_twelve_min(t_list *l);
int			pos_treize_min(t_list *l);
int			pos_fourt_min(t_list *l);
int			pos_sevent_min(t_list *l);
int			pos_sixt_min(t_list *l);
int			six_first_min(t_list **la);
int			seven_first_min(t_list **la);
int			eight_first_min(t_list **la);
int			nine_first_min(t_list **la);
int			ten_first_min(t_list **la);
int			eleven_first_min(t_list **la);
int			twelve_first_min(t_list **la);
int			treize_first_min(t_list **la);
int			fourt_first_min(t_list **la);
int			fift_first_min(t_list **la);
int			sixt_first_min(t_list **la);
int			sevent_first_min(t_list **la);
void		do_sec_range_five_hundred(t_list **la, t_list **lb,
				t_index_b *idxs);
void		do_third_range_five_hundred(t_list **la, t_list **lb,
				t_index_b *idxs);
void		do_four_range_five_hundred(t_list **la, t_list **lb,
				t_index_b *idxs);
void		do_last_range_five_hundred(t_list **la, t_list **lb,
				t_index_b *idxs);
void		sort_range_five_hundred(t_list **la, t_list **lb,
				t_index_b *idxs);
void		sort_range2_five_hundred(t_list **la, t_list **lb,
				t_index_b *idxs);
void		sort_range3_five_hundred(t_list **la, t_list **lb,
				t_index_b *idxs);
void		sort_range4_five_hundred(t_list **la, t_list **lb,
				t_index_b *idxs);
void		sort_range5_five_hundred(t_list **la, t_list **lb,
				t_index_b *idxs);
void		do_that_five(t_index_f *idxs, t_list **la);
void		do_this_five(t_index_f *idxs, t_list **la);
void		or_that_five(t_index_f *idxs, t_list **la);
void		attribute_struct_cent(t_list **la, t_index_f *idxs);
void		det_pos_first_cent(t_list **la, t_index_f *idxs);
int			return_plus_petit_cent(t_index_f idxs);
int			plus_petit_cent(t_index_f idxs, int index);
void		do_op_ra_rra_cent(t_list **la, t_index_f *idxs, int index);
int			top_la_inf_lb(t_list **la, t_list **lb);
int			top_la_sec_lb(t_list **la, t_list **lb);
void		i_minus_j(t_list **lb, t_index idxs);
void		j_minus_i(t_list **lb, t_index *idxs);
void		z_minus_y(t_list **lb, t_index *idxs);
int			y_minus_z(t_list **lb, t_index *idxs);
t_index		*init_struct(t_index *idxs);
t_index_b	*init_struct_b(t_index_b *idxs);
int			case_less_one(t_list **la, t_list **lb);
int			finish_func(t_list **la, t_list **lb, t_index *idxs);
void		choose_minus(t_list **lb, t_index *idxs);
int			do_rrb_copy(t_list **tmp2, t_index_b *idxs, int i);
int			main_rrb_copy(t_list **tmp2, t_index_b *idxs, int i);
void		direct_bottom(t_list **la, t_list **lb, t_index_b *idxs,
				int res);
int			swap_is_okay(t_list **la, t_list **lb, t_index_b *idxs);
void		until_res_and_i_rb(t_list **la, t_list **lb, t_index_b *idxs,
				int res);
void		res_down_until_i_rb(t_list **la, t_list **lb, t_index_b *idxs,
				int res);
void		untils_res_and_i_rrb(t_list **la, t_list **lb, t_index_b *idxs,
				int res);
void		res_up_until_i_rrb(t_list **la, t_list **lb, t_index_b *idxs,
				int res);
void		do_op(t_list **la, t_list **lb, t_index_b *idxs, int res);
int			remove_in_func(t_list **la, t_list **lb, t_index_b *idxs);
void		do_for_real(t_list **la, t_list **lb, t_index_b *idxs, int res);
int			ft_check_c(const char s, char c);
int			count_char_c(char const *s, char c);
char		*ft_alloc_str(char const *s, char c);
char		**ft_split(char const *s, char c);
int			ft_strlen(char *s);
void		free_tab(char **tab);
void		delete_list(t_list **l);
void		do_swap_ten(t_list **la, t_list **lb, t_index_b *idxs, int res);
void		swap_ten_last_equal(t_list **la, int res);
void		swap_ten_last_res_up(t_list **la, t_list **lb, int res);
void		swap_ten_last_down_res_up(t_list **la, t_list **lb, int res);
void		swap_ten_last_res_down(t_list **la, t_list **lb, int res);
void		swap_ten_res_equal(t_list **la, t_list **lb);
int			do_remove_in_ten(t_list **la, t_list **lb, t_index_b *idxs);
void		do_op_ten_dis_equal(t_list **la, t_list **lb, t_index_b *idxs,
				t_list *tmp2);
int			do_op_ten_last_equal(t_list **la, t_list **lb, t_index_b *idxs,
				t_list *tmp2);
void		do_direct_ten_res_last_up(t_list **la, t_list **lb, int res);
void		do_direct_ten_last_up_res(t_list **la, t_list **lb, int res);
void		do_direct_ten_last_down_res(t_list **la, t_list **lb, int res);
void		do_direct_ten_last_res_down(t_list **la, t_list **lb, int res);
void		do_direct_ten_last_equal(t_list **la, int res);
int			do_op_ten_last_dis_up(t_list **la, t_list **lb, t_index_b *idxs,
				t_list *tmp2);
void		first_round(t_list **la, int i);
void	idxs_j_fast(t_list **la, t_list **lb, t_index_b *idxs);
void	idxs_i_fast(t_list **la, t_list **lb, t_index_b *idxs);
int		y_down(t_list **la, int y);
int		y_up(t_list **la, int y);

#endif