#include "Serializer.hpp"
#include <iostream>

int main(void)
{

	Data *data = new Data;
	data->s = "string";
	data->i = 7;
	data->j = 0;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

  std::cout << "Original data ptr= " << data << std::endl;
  std::cout << "Copy data ptr= " << serialized << std::endl;

	std::cout << serialized->s << std::endl;
	std::cout << serialized->i << std::endl;
	std::cout << serialized->j << std::endl;

	delete data;
	return (0);
}
