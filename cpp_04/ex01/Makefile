CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE := Animal.hpp Dog.hpp Cat.hpp WrongCat.hpp WrongAnimal.hpp Brain.hpp

NAME := animal

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