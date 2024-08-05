CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp AMateria.cpp Ice.cpp Cure.cpp MateriaSource.cpp Character.cpp 
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE := AMateria.hpp IMateriaSource.hpp MateriaSource.hpp ICharacter.hpp Character.hpp Ice.hpp Cure.hpp

NAME := matria

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