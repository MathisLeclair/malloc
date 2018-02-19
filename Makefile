# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 19:21:21 by mleclair          #+#    #+#              #
#    Updated: 2018/02/19 14:12:15 by mleclair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

LINK = libft_malloc.so

FILE =	malloc \
		show_alloc_mem \
		realloc \
		init \
		free
		
OBJ  := $(addsuffix .o, $(FILE))

all: $(NAME)

test: all
	@ cc -o t0 ./test/test0.c 

	@ cc -o t1 ./test/test1.c
	@ cc -o t2 ./test/test2.c
	@ cc -o t3 ./test/test3.c
	@ cc -o t3b ./test/test3bis.c
	@ cc -o t4 ./test/test4.c
	@ cc -w -o t5 ./test/test5.c -L. -lft_malloc

testex: test
	@ echo '############# launching test 0 ################'
	@ /usr/bin/time -l ./t0
	@ echo '############# launching test 1 ################'
	@ ./test/run.sh /usr/bin/time -l ./t1
	@ echo '############# launching test 2 ################'
	@ ./test/run.sh /usr/bin/time -l ./t2
	@ echo '############# launching test 3 ################'
	@ ./test/run.sh ./t3
	@ echo '############# launching test 3b ################'
	@ ./test/run.sh ./t3b
	@ echo '############# launching test 4 ################'
	@ ./test/run.sh ./t4
	@ echo '############# launching test 5 ################'
	@ ./t5

$(NAME): $(OBJ)
	@echo "----------------------------------------"
	@echo "|       Debut de la compilation        |"
	@echo "|              Ecole 42                |"
	@make -C ./libft
	@clang -Wall -Wextra -Werror -L./libft -lft -shared -o $(NAME) $(OBJ)
	@rm -f $(LINK)
	@ln -s $(NAME) $(LINK)
	@echo "|                 FIN                  |"
	@echo "----------------------------------------"
	@echo "               ________"
	@echo "          _,.-Y  |  |  Y-._"
	@echo "      .-~\"   ||  |  |  |   \"-."
	@echo "      I\" \"\"==\"|\" !\"\"! \"|\"[]\"\"|     _____"
	@echo "      L__  [] |..------|:   _[----I\" .-{\"-."
	@echo "     I___|  ..| l______|l_ [__L]_[I_/r(=}=-P"
	@echo "    [L______L_[________]______j~  '-=c_]/=-^"
	@echo "     \_I_j.--.\==I|I==_/.--L_]"
	@echo "       [_((==)[\`-----\"](==)j"
	@echo "          I--I\"~~\"\"\"~~\"I--I"
	@echo "          |[]|         |[]|"
	@echo "          l__j         l__j"
	@echo "          |!!|         |!!|"
	@echo "          |..|         |..|"
	@echo "          ([])         ([])"
	@echo "          ]--[         ]--["
	@echo "          [_L]         [_L]"
	@echo "         /|..|\       /|..|\\"
	@echo "        \`=}--{='     \`=}--{=i'"
	@echo "       .-^--r-^-.   .-^--r-^-."
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

$(OBJ): %.o: %.c
	@gcc -c -g -Wall -Wextra -Werror -I. $< -o $@

clean:
	@make -C ./libft clean
	@rm -rf $(OBJ)

tclean:
	@rm -rf t0 t1 t2 t3 t3b t4 t5

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME) $(LINK)
	@rm -rf t0 t1 t2 t3 t3b t4 t5

re: fclean all

.PHONY : all clean fclean re test testex tclean
