.PHONY: all libft clean fclean re

OBJDIR = obj
SRCDIR = src
LIBDIR = libft
HEADER = -I ./include
HEADER_LIBFT = -I ./libft/include -I ./libft/src/ft_printf/include
FLAGS = -Wall -Wextra -Werror -g

ASM = asm
SRC_ASM_NAME = main.c \
				asm_content.c \
				assemble.c \
				error.c \
				filename.c \
				title.c \
				tokenizing.c \
				buffer.c \
				string.c \
				helper.c

OBJ_ASM_NAME = $(SRC_ASM_NAME:.c=.o);
SRC_ASM = $(addprefix $(OBJDIR)/, $(SRC_ASM_NAME))
OBJ_ASM = $(addprefix $(OBJDIR)/, $(OBJ_ASM_NAME))

all: libft $(ASM)

$(ASM): $(OBJ_ASM)
	@gcc $(FLAGS) $^ -o $@ $(HEADER_LIBFT) $(HEADER) -L libft -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c include/asm.h
	@mkdir -p $(OBJDIR)
	@gcc $(FLAGS) $(HEADER_LIBFT) $(HEADER) -o $@ -c $<

libft:
	@make -C $(LIBDIR)

clean:
	@make clean -C $(LIBDIR)
	@rm -Rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBDIR)
	@rm -Rf $(ASM)

re: fclean all

norm:
	norminette $(SRCDIR)
	norminette ./include