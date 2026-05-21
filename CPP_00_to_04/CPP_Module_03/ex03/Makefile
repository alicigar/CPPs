NAME = DiamondTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Wshadow -std=c++98
SRCS = ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp main.cpp   
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re