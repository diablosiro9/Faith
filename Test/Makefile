# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 16:02:58 by dojannin          #+#    #+#              #
#    Updated: 2022/09/30 02:00:45 by mehdi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJ = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra -g -fsanitize=address

SRCS = rules.c \
		rules2.c \
		rules3.c \
		rules_copy.c \
		opti.c \
		parsing.c \
		max_min_pos.c \
		need_compare5.c \
		need_compare10.c \
		need_compare11.c \
		sort.c \
		compare_rb_rrb.c \
		rrb_hundred.c \
		sort4.c \
		sort6.c \
		ft_lst.c \
		ft_lst2.c \
		fcts_direct_ten.c \
		fcts_swap_ten.c \
		fcts_compare_la_lb_ten.c \
		fcts_compare_ten_f.c \
		do_op_fcts.c \
		pos_three_four_five.c \
		pos_six_seven_eight.c \
		pos_eight_nine_ten.c \
		pos_eleven_minus_i.c \
		main.c \
		utils_compare_la_lb.c \
		utils.c \
		utils2.c \
		utils3.c \
		utils4.c \
		utils9.c \
		utils10.c \
		cases_three.c \
		cases_three1.c \
		cases_three2.c \
		cases_three3.c \
		case_four.c \
		case_five.c \
		cases_hundred.c \
		cases_hundred2.c \
		case_five_hundred.c \
		case_five_hundred2.c \
		

$(NAME):		$(OBJ)
						gcc -g ${CFLAGS} $(OBJ) -o $(NAME)

all:			$(NAME)

clean:			
				rm -f $(OBJ)

fclean:			clean
					rm -f $(NAME)

norme:
					norminette -R CheckForbiddenSourceHeader $(SRCS) 

re:				fclean all

.PHONY :		all clean fclean re
