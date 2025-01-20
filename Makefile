# VALGRIND
VALGRIND_LOG := valgrind.log


# COLORS
GREEN := \033[32m
RED := \033[31m
CYAN := \033[36m
VIOLET := \033[38;5;208m
COLOR_LIMITER := \033[0m


# NAME
NAME := so_long


# FLAGS
CFLAGS := -Ofast -fno-stack-protector -ffast-math -Wall -Wextra -Wunreachable-code -g3 -Werror
LIBS := -ldl -lglfw -pthread -lm


# LIBS
LIB_PATH := ./libs/libft
LIB_NAME := libft.a
MLX_PATH := ./libs/MLX42
MLX_BUILD_PATH := $(MLX_PATH)/build
MLX_NAME := libmlx42.a


# PATHS
SRC_PATH := ./src/
BIN_PATH := ./bin/
HEADER_PATH := ./includes/


# SOURCES AND OBJECTS
FILES := \
	validation.c \
	image.c \
	error.c \
	utils.c \
	hook.c \
	init.c \
	map.c \
	mlx.c \
	main.c
SRCS := $(addprefix $(SRC_PATH), $(FILES))
OBJS := $(addprefix $(BIN_PATH), $(FILES:%.c=%.o))

# BONUS
BONUS_NAME := so_long_bonus
BONUS_SRC_PATH := ./src/bonus/
BONUS_FILES := \
	animation_utils_bonus.c \
	validation_bonus.c \
	animation_bonus.c \
	image_bonus.c \
	error_bonus.c \
	utils_bonus.c \
	hook_bonus.c \
	init_bonus.c \
	map_bonus.c \
	mlx_bonus.c \
	main_bonus.c 
BONUS_SRCS := $(addprefix $(BONUS_SRC_PATH), $(BONUS_FILES))
BONUS_OBJS := $(addprefix $(BIN_PATH), $(BONUS_FILES:%.c=%.o))

all: mlx libft $(BIN_PATH) print $(NAME)
bonus: mlx libft $(BIN_PATH) print_bonus $(BONUS_NAME)

mlx: 
ifeq ($(wildcard $(MLX_BUILD_PATH)/$(MLX_NAME)),)
	@printf "$(CYAN)-------------------- --------------- --------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)--------------------| COMPILING MLX |--------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)-------------------- --------------- --------------------$(COLOR_LIMITER)\n"
	@cmake $(MLX_PATH) -B $(MLX_BUILD_PATH)
	@make -C $(MLX_BUILD_PATH) -j4 --no-print-directory
endif

libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@printf "$(CYAN)------------------- ----------------- -------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)-------------------| COMPILING LIBFT |-------------------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------------------- ----------------- -------------------$(COLOR_LIMITER)\n"
	@make build -C $(LIB_PATH) --no-print-directory
endif

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

print:
ifeq ($(wildcard $(NAME)),)
	@printf "$(GREEN) ------------------------$(COLOR_LIMITER)"
	@printf "$(GREEN)| Compiling Main Project |$(COLOR_LIMITER)"
	@printf "$(GREEN)------------------------$(COLOR_LIMITER)"
	@echo " "
endif

print_bonus:
ifeq ($(wildcard $(BONUS_NAME)),)
	@printf "$(GREEN) ------------------------$(COLOR_LIMITER)"
	@printf "$(GREEN)| Compiling Bonus Project |$(COLOR_LIMITER)"
	@printf "$(GREEN)------------------------$(COLOR_LIMITER)"
	@echo " "
endif

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_PATH)/$(LIB_NAME) $(MLX_BUILD_PATH)/$(MLX_NAME) $(LIBS) -I$(HEADER_PATH)
	@printf "$(CYAN)------ ----------------------------------------------- ------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------| SO_LONG executable was created successfully!! |------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------ ----------------------------------------------- ------$(COLOR_LIMITER)\n"
	@echo " "

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIB_PATH)/$(LIB_NAME) $(MLX_BUILD_PATH)/$(MLX_NAME) $(LIBS) -I$(HEADER_PATH)
	@printf "$(CYAN)------ ----------------------------------------------------- ------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------| SO_LONG_BONUS executable was created successfully!! |------$(COLOR_LIMITER)\n"
	@printf "$(CYAN)------ ----------------------------------------------------- ------$(COLOR_LIMITER)\n"
	@echo " "

$(BIN_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_PATH)
	@echo " "

$(BIN_PATH)%.o: $(BONUS_SRC_PATH)%.c
	@printf "$(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_PATH)
	@echo " "

clean:
	@printf "$(RED)[Removing Objects...]$(COLOR_LIMITER)\n"
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(MLX_BUILD_PATH)
	@rm -rf $(BIN_PATH)
	@rm -rf $(VALGRIND_LOG)

fclean: clean
	@printf "$(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)\n"
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)

re: fclean
	@make --no-print-directory

valgrind: all
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--track-fds=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME) maps/test.ber
	@cat $(VALGRIND_LOG)

valgrind_bonus: bonus
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--track-fds=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(BONUS_NAME) maps/bonus.ber
	@cat $(VALGRIND_LOG)

.PHONY: all clean fclean re print libft mlx print_bonus valgrind_bonus