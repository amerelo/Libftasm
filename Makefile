NAME = libfts.a

OBJ = obj/
SRC = src/

FILE_S = ft_isprint.s ft_isalpha.s ft_isdigit.s ft_isalnum.s ft_isascii.s \
ft_bzero.s ft_strlen.s ft_puts.s ft_toupper.s ft_tolower.s ft_memset.s ft_memcpy.s \
ft_strdup.s ft_strcpy.s ft_strcat.s ft_cat.s ft_strnew.s

FILE_O = $(FILE_S:.s=.o)

SRC_S := $(addprefix $(SRC), $(FILE_S))
SRC_O := $(addprefix $(OBJ), $(FILE_O))

NASM = nasm -f macho64

all: $(NAME)

$(OBJ):
	mkdir -p $@

obj/%.o: src/%.s
	$(NASM) $< -o $@

$(NAME): $(OBJ) $(SRC_O)
	ar rc $(NAME) $(SRC_O)
	# ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
