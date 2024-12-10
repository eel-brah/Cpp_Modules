CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE := Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp

NAME := form

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
