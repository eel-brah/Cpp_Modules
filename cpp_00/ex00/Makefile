CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := megaphone.cpp
OBJS := $(SRCS:%.cpp=%.o)

NAME := megaphone

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
