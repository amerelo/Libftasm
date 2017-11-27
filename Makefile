NAME = libfts.a

OBJ = objs/
SRC = src/

FILE_S = ft_isprint.s ft_isalpha.s ft_isdigit.s ft_isalnum.s ft_tolower.s \
ft_bzero.s ft_strlen.s ft_puts.s ft_toupper.s ft_memset.s ft_memcpy.s \
ft_strdup.s

FILE_O = $(FILE_S:.s=.o)

SRC_S := $(addprefix $(SRC), $(FILE_S))
SRC_O := $(addprefix $(OBJ), $(FILE_O))

NASM = nasm -f macho64

all: $(OBJ) $(NAME)

$(OBJ):
	mkdir -p $@

objs/%.o: src/%.s
	$(NASM) $< -o $@

$(NAME): $(SRC_O)
	ar rc $(NAME) $(SRC_O)
	# ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
