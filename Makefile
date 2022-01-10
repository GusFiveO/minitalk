INC_DIR = includes/
SRC_DIR = src/
OBJ_DIR = bin/
LIBFT_DIR = libft/

SRCS = client.c server.c utils.c
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

SERVER = server
CLIENT = client

CFLAGS = -Wall -Wextra -Werror
INCPATH = -I $(INC_DIR) -I $(LIBFT_DIR)includes/

LIBFT = libft/libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER) : $(LIBFT) $(OBJ_DIR) $(OBJS)
	gcc $(CFLAGS) bin/server.o bin/utils.o -o $(SERVER) $(LIBFT)

$(CLIENT) : $(LIBFT) $(OBJ_DIR) $(OBJS)
	gcc $(CFLAGS) bin/client.o -o $(CLIENT) $(LIBFT)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	gcc $(CFLAGS) $(INCPATH) -c $< -o $@

$(OBJ_DIR) : 
	@mkdir -p $(OBJ_DIR)

$(LIBFT) : 
	make -C libft/

clean:
	rm -rf $(OBJ_DIR)
	cd libft && $(MAKE) fclean

fclean: clean
	rm -f $(CLIENT) $(SERVER) 

bonus: all

re: fclean all

.PHONY: all clean fclean libft re 
