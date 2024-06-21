CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := PhoneBook.cpp
OBJS := $(SRCS:%.cpp=%.o)

NAME := phonebook

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean
