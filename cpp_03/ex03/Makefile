CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
# -Wno-shadow
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE := ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

NAME := diamondtrap

all: $(NAME)

%.o: %.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDE)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re