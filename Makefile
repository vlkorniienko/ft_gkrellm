# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aorji <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/14 16:26:20 by aorji             #+#    #+#              #
#    Updated: 2018/10/14 16:26:22 by aorji            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm
OBJ_DIR = ./obj/
SRC_DIR = ./src/
INC_DIR = ./inc/

FLAGS = -Wall -Wextra -Werror
SRC = 	main.cpp Host.cpp OS.cpp Time.cpp Network.cpp \
		CPU.cpp RAM.cpp Disk.cpp Processes.cpp Window.cpp
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
HDRS = -I $(INC_DIR)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
		clang++ $(FLAGS) $(OBJ) -o $(NAME) $(HDRS) -lncurses 
		echo "\033[32m[ ✔ ] "$(NAME) created" \033[0m"

$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				@clang++ -c $< -o $@ $(FLAGS) $(HDRS) $(INCLUDES)

clean:
	rm -f $(OBJ)
	echo "\033[31m[ × ] "$(OBJ) removed" \033[0m"

fclean: clean
		rm -f $(NAME)
		rm -rf $(OBJ_DIR)
		echo "\033[31m[ × ] "$(NAME) removed" \033[0m"

re: fclean all
