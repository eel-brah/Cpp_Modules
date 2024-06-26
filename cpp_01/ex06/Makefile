CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp Harl.cpp
OBJS := $(SRCS:%.cpp=%.o)
INCLUDE := Harl.hpp

NAME := harlFilter

all: $(NAME)

%.o: %.cpp $(INCLUDE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDE)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean
