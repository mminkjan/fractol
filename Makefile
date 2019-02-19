# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jesmith <jesmith@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/13 12:32:27 by jesmith        #+#    #+#                 #
#    Updated: 2019/02/19 17:05:32 by jesmith       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CFLAGS := -Wall -Werror -Wextra
HEAD := libft.h
SRCS := ft_lstmap.c ft_lstdelone.c ft_lstiter.c \
		ft_lstadd.c ft_lstnew.c ft_islower.c \
		ft_lstdel.c ft_strarradel.c ft_strsplit.c \
		ft_wrdcount.c ft_strndup.c ft_strnstr.c \
		ft_strstr.c ft_itoa.c ft_putnbr_fd.c \
		ft_putendl_fd.c ft_isupper.c ft_putstr_fd.c \
		ft_putchar_fd.c ft_strtrim.c ft_strjoin.c \
		ft_strsub.c ft_intlen.c ft_strncmp.c \
		ft_strnequ.c ft_strequ.c ft_strmapi.c \
		ft_strmap.c ft_striteri.c ft_striter.c \
		ft_strclr.c ft_strdel.c ft_strnew.c \
		ft_memdel.c ft_memalloc.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcmp.c ft_strcat.c \
		ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_isspace.c \
		ft_atoi.c ft_putchar.c ft_putstr.c \
		ft_putendl.c ft_putnbr.c ft_isupper.c \
		ft_islower.c ft_stralloc.c ft_strrev.c \
		ft_lstaddback.c ft_del.c ft_strarradel.c \

FILES := $(SRCS:%.c=ft_%.o) 
SRCO := $(SRCS:.c=.o)

NORM := norminette $(HEAD) $(SRCS) | grep -e "Warning" -e "Error" -B 1

all: $(NAME)

norm:
	@$(NORM)

add:
	@git add $(SRCS) $(HEAD)
	@git status

push:
ifdef MSG
	@git commit -m "$(MSG)"
	@git push
	@make norm
else
	@echo "WARNING NO MESSAGE"
endif

print:
	@echo "$(SRCO)"

$(NAME):
	@gcc $(CFLAGS) -c $(SRCS)   
	@ar rc	$(NAME) $(SRCO) $(HEAD)
	@ranlib	$(NAME)

clean:
	@/bin/rm -f $(SRCO) *~

fclean:
	@/bin/rm -f $(SRCO) libft.a

re: fclean all
