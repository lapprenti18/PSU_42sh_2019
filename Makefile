##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	lib/my/my_putnbr_base.c	\
		lib/my/my_compute_power_rec.c	\
		lib/my/my_compute_square_root.c	\
		lib/my/my_find_prime_sup.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_isneg.c	\
		lib/my/my_is_prime.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_revstr.c	\
		lib/my/my_showmem.c	\
		lib/my/my_showstr.c	\
		lib/my/my_strcapitalize.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strdup.c	\
		lib/my/my_str_isalpha.c	\
		lib/my/my_str_islower.c	\
		lib/my/my_str_isprintable.c	\
		lib/my/my_str_isupper.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strlowcase.c	\
		lib/my/my_strncat.c	\
		lib/my/my_strncmp.c	\
		lib/my/my_strncpy.c	\
		lib/my/my_strstr.c	\
		lib/my/my_strupcase.c	\
		lib/my/my_swap.c	\
		lib/my/my_delete_neg.c	\
		lib/my/my_str_is_negative.c	\
		lib/my/my_str_to_word_array.c	\
		lib/my/my_supr_same.c	\
		lib/my/my_mult_zero.c	\
		lib/my/my_add_x_zero.c	\
		lib/my/my_delete_mult.c	\
		lib/my/my_zeroo.c	\
		lib/my/my_infin_tol.c	\
		lib/my/my_bistro_error.c	\
		lib/my/my_occ.c	\
		lib/my/my_str_isnum.c	\
		lib/my/my_print_b.c	\
		lib/my/my_print_c.c	\
		lib/my/my_print_caps.c	\
		lib/my/my_print_capx.c	\
		lib/my/my_print_d.c	\
		lib/my/my_print_o.c	\
		lib/my/my_print_p.c	\
		lib/my/my_print_s.c	\
		lib/my/my_print_u.c	\
		lib/my/my_print_x.c	\
		lib/my/my_printf.c

NAME	=	42sh

COMP	=	src/minishell_loop.c	\
			src/minishell_nodes.c	\
			src/minishell_bin.c	\
			src/minishell_owns_functions.c	\
			src/minishell_cd.c	\
			src/minishell_setenv.c	\
			src/minishell_unsetenv.c	\
			src/modif_string.c	\
			src/minishell_error_handling.c	\
			src/minishell_list.c	\
			src/minishell_free_list.c	\
			src/minishell_check_special.c	\
			src/minishell_two_loop.c	\
			src/minishell_check_own.c	\
			src/exec_tree.c	\
			src/alias.c	\
			src/minishell_parse_tree.c	\
			src/chek_key.c	\
			src/getline.c	\
			src/tab_lenght.c	\
			src/delet.c	\
			src/fill.c	\
			src/add_key.c	\
			src/rewrite.c	\
			src/test.c	\
			src/down.c	\
			src/up.c	\
			src/control_c.c	\
			src/path.c	\
			src/minishell_where.c	\
			src/variables.c	\
			src/minishell_repeat.c	\
			src/minishell_foreach.c	\
			src/minishell_history.c	\
			src/buffer.c

MAIN	=	src/main.c

TESTS	=	tests/criterion.c	\
			tests/test_criterion.c	\
			tests/test_my_str_isnum.c	\
			tests/test_my_str_isupper.c	\
			tests/test_my_strlen.c	\
			tests/test_my_str_lowcase.c	\
			tests/test_my_strncat.c	\
			tests/test_my_strncmp.c	\
			tests/test_my_strstr.c	\
			tests/test_my_str_to_word_array.c	\
			tests/test_my_strupcase.c	\
			tests/test_my_swap.c	\
			tests/test_str_isprintable.c	\
			tests/test_strncpy.c	\
			tests/test_my_find_prime_sup.c	\
			tests/test_my_getnbr.c	\
			tests/test_my_isneg.c	\
			tests/test_my_is_prime.c	\
			tests/test_my_putchar.c	\
			tests/test_my_put_nbr.c	\
			tests/test_my_putnbr_base.c	\
			tests/test_my_putstr.c	\
			tests/test_my_revstr.c	\
			tests/test_my_showmem.c	\
			tests/test_my_showstr.c	\
			tests/test_my_strcapitalize.c	\
			tests/test_my_strcat.c	\
			tests/test_my_strcmp.c	\
			tests/test_my_strcpy.c	\
			tests/test_my_str_isalpha.c	\
			tests/test_my_str_islower.c

CFLAGS  =	-W -Wall -Wextra -Iinclude -g3

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

CFLAGS_TESTS	=	--coverage -lcriterion

OBJ_TESTS	=	$(COMP:.c=.o) $(SRC:.c=.o) $(TESTS:.c=.o)


all	:	$(NAME)

$(NAME)	: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(COMP) $(CFLAGS)


unit_tests:	$(OBJ_TESTS)
	$(CC) -o $@ $^ $(CFLAGS) $(CFLAGS_TESTS)
	./$@

tests_run:	CFLAGS	+=	$(CFLAGS_TESTS)

tests_run:	unit_tests

clean	:
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f test
	rm -f $(NAME)
	rm -f unit_tests


re	: fclean all