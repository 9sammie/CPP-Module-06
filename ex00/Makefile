NAME					=		ScalarConvert

CXX						=		c++

OBJ_DIR					=		obj

CXXFLAGS					=		-std=c++98 -Wall -Wextra -Werror

################################################################################
###									FILES									 ###
################################################################################

HEADERS					=		ScalarConvert.hpp

SRC						=		main.cpp ScalarConvert.cpp convertUtils.cpp

OBJ						=		$(SRC:%.cpp=$(OBJ_DIR)/%.o)

################################################################################
###									ARCHIVES								 ###
################################################################################

all: $(NAME)

$(NAME): $(OBJ)
			$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
			$(CXX) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

re: fclean
			$(MAKE) all

fclean: clean
			rm -f $(NAME)

clean: 
			rm -rf $(OBJ_DIR)

.PHONY: all clean fclean re