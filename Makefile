#					MACRO INITIALIZATION

NAME				= ft_ping


#		DEBUG TOOLS

RESET				= \033[0m
UNDERLINE			= \033[4m
BOLD				= \033[1m
RED					= \033[0;91m
GREEN				= \033[0;92m
YELLOW				= \033[0;93m
BLUE				= \033[0;94m
PURPLE				= \033[0;35m
CYAN				= \033[0;96m
WHITE				= \033[0;37m

define	logs
	@printf "$(1)\r\t $(2) $(RESET)"
endef

LOG__TITLE			= @echo "$(BOLD) \nULTIMAKEFILE - CUB3D $(RESET)\n\n\n"
LOG__PREL			= @echo "$(PURPLE) \nMAKEFILE $(RESET)\n"
LOG__SUCCESS		= @printf "$(GREEN)\rDONE $(RESET)\n"
LOG__ALLSUCCESS		= @printf "\033[1;92m\n\rALL DONE $(RESET)\n\n"


#			DIRECTORIES

SRC_DIR				= src/
HEAD_DIR			= src/
OBJ_DIR				= $(SRC_DIR)OBJ/


#			FILES

ALL_SRC				= main.c \
					utils.c

ALL_HEADERS			= ping.h


PREFIX_SRC			= $(addprefix $(SRC_DIR), $(ALL_SRC))
PREFIX_HEADER		= $(addprefix $(HEAD_DIR), $(ALL_HEADERS))
SRC					= $(wildcard $(PREFIX_SRC))
HEADER				= $(wildcard $(PREFIX_HEADER))
OBJ					= $(sort $(patsubst %.c, $(OBJ_DIR)%.o, $(notdir $(ALL_SRC))))
DEP					= $(OBJ:.o=.d)

DIRS				= $(sort $(dir $(OBJ)))


#			UTILITIES

CC = cc

CFLAGS				= -Wextra -Wall -Werror -g3 -MMD

FLAGS				= $(CFLAGS)
ALL_INCLUDE			= -I $(SRC_DIR) \
					-I /usr/include \
					$(MLX_INCLUDE)

#					RULES

all : $(NAME)
	$(LOG__ALLSUCCESS)

$(NAME): $(OBJ)
	$(call logs, $(CYAN),"Compiling\ Executable")
	$(CC) $(FLAGS) $(OBJ) $(ALL_INCLUDE) -o $(NAME)
	$(LOG__SUCCESS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRS) :
	$(call logs, $(CYAN),"Creating\ directories")
	@mkdir -p $(DIRS)
	$(LOG__SUCCESS)

clean : 
	$(call logs, $(YELLOW),"Cleaning\ OBJ\ files")
	rm -rf $(OBJ_DIR)
	$(LOG__SUCCESS)

fclean : clean
	$(call logs, $(YELLOW),"Cleaning\ Executable")
	rm -f $(NAME)
	$(LOG__SUCCESS)

re : fclean all

-include $(DEP)

.SILENT:

.PHONY: all clean re fclean force