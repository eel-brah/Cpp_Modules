/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:35:18 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:35:18 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
  ideaNbr = 0;
  std::cout << "\033[0;36m==>> Brain created!\033[0m" << std::endl;
}
Brain::~Brain() {
  std::cout << "\033[0;36m==>> Destructor for Brain called\033[0m" << std::endl;
}
Brain::Brain(const Brain &other) {
  *this = other;
  std::cout << "\033[0;36m==>> Brain has been copied!\033[0m" << std::endl;
}
Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    ideaNbr = other.ideaNbr;
    for (int i = 0; i < 100; i++)
      ideas[i] = other.ideas[i];
  }
  std::cout << "\033[0;36m==>> Brain's copy assignment operator has been "
               "called!\033[0m"
            << std::endl;
  return *this;
}

void Brain::add_idea(const std::string &idea) {
  ideas[ideaNbr % 100] = idea;
  ideaNbr++;
}

std::string Brain::get_idea(const unsigned int i) {
  if (i < 100)
    return ideas[i];
  return "";
}
