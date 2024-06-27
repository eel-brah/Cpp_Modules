CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE := Fixed.hpp Point.hpp

NAME := fixed

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
