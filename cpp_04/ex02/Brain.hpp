/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-brah <eel-brah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:35:21 by eel-brah          #+#    #+#             */
/*   Updated: 2024/08/05 18:35:21 by eel-brah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H_
#define BRAIN_H_

#include <iostream>

class Brain {
private:
  std::string ideas[100];
  unsigned int ideaNbr;

public:
  Brain();
  ~Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);

  void add_idea(const std::string &idea);
  std::string get_idea(const unsigned int i);
};

#endif
