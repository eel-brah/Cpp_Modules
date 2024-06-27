CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp Zombie.cpp zombieHorde.cpp
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE := Zombie.hpp

NAME := zombies

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
