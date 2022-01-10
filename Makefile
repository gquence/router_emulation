CC = g++
FLAGS = --std=c++17 -Wextra -Werror -Wall

SRC_DIR = ./srcs
INC_DIR = ./includes
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

EXEPTIONS_LIB_DIR = ./exceptions
EXEPTIONS_LIB_INC_DIR = $(addprefix $(EXEPTIONS_LIB_DIR)/,$(INC_DIR))
EXEPTIONS_LIB_NAME = router_exception

MEMORY_HANDLING_LIB_DIR = ./memory_handling
MEMORY_HANDLING_LIB_INC_DIR = $(addprefix $(MEMORY_HANDLING_LIB_DIR)/,$(INC_DIR))
MEMORY_HANDLING_LIB_NAME = looped_queue

NAME = router
OBJ_DIR = ./obj

SRC = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJS))

IS_GCC_MINGW = $(shell g++ --version | grep -o MinGW)

COMMON_CFLAGS = -O3
ifeq "$(IS_GCC_MINGW)" "MinGW"
    COMMON_CFLAGS += -D__cplusplus=201703L
endif

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(EXEPTIONS_LIB_DIR) CFLAGS="$(COMMON_CFLAGS)"
	make -C $(MEMORY_HANDLING_LIB_DIR) CFLAGS="$(COMMON_CFLAGS)"
	$(CC) $^ -o $@ -L $(EXEPTIONS_LIB_DIR) -l $(EXEPTIONS_LIB_NAME) -L $(MEMORY_HANDLING_LIB_DIR) -l $(MEMORY_HANDLING_LIB_NAME) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir $(OBJ_DIR) 2< /dev/null || true
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(EXEPTIONS_LIB_INC_DIR) -I $(MEMORY_HANDLING_LIB_INC_DIR) $(COMMON_CFLAGS)

clean:
	rm -rf  $(OBJ_DIR)
	make -C $(EXEPTIONS_LIB_DIR) clean
	make -C $(MEMORY_HANDLING_LIB_DIR) clean
	
fclean: clean
	rm -rf $(NAME)
	make -C $(EXEPTIONS_LIB_DIR) fclean
	make -C $(MEMORY_HANDLING_LIB_DIR) fclean

re: fclean all
