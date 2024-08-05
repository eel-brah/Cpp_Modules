CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS :=  Zombie.cpp main.cpp randomChump.cpp newZombie.cpp
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE := Zombie.hpp

NAME := zombie

all: $(NAME)

%.o: %.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDE)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
