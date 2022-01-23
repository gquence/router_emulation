CC = g++
FLAGS = --std=c++17 -Wextra -Werror -Wall

SRC_DIR = ./srcs
INC_DIR = ./includes
SRCS = common_packet.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = librouter_packets.a
OBJ_DIR = ./obj

SRC = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir $(OBJ_DIR) 2< /dev/null || true
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) $(CFLAGS)

clean:
	rm -rf  $(OBJ_DIR)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all
