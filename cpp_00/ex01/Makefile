CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := Contact.cpp main.cpp PhoneBook.cpp utils.cpp getint.cpp
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE := header.hpp PhoneBook.hpp Contact.hpp

NAME := phonebook

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
