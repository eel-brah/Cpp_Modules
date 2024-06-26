#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <cstdlib>

std::string read_file_to_str(const char* filename)
{
    std::ifstream input_file(filename);
    if (!input_file)
    {
        std::cerr << "Error opening " << filename << std::endl;
        std::exit(1);
    }

    input_file.seekg(0, std::ios::end);
    std::streamsize size = input_file.tellg();
    input_file.seekg(0, std::ios::beg);

    std::string str;
    str.resize(size);
    if (!input_file.read(&str[0], size))
    {
        std::cerr << "Could not read file " << filename << std::endl;
        input_file.close();
		std::exit(1);
    }

	input_file.close();
    return str;
}

void replace(std::ofstream& output_file, std::string str, char *s1, char *s2)
{
	size_t s1_len = std::strlen(s1); // 0
	size_t pos = 0;

	while ((pos = str.find(s1, pos)) != std::string::npos && s1_len)
	{
		output_file << str.substr(0, pos) << s2; 
		str = str.substr(pos + s1_len);
		pos = 0;
	}
	output_file << str;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " filename s1 s2\n";
		return 1;
	}

	std::string str = read_file_to_str(argv[1]);
	std::string output_name = std::string(argv[1]) + ".replace";
	std::ofstream output_file(output_name.c_str());
    if (!output_file)
	{
        std::cerr << "Error opening " << argv[2] << std::endl;
        return 1;
    }

	replace(output_file, str, argv[2], argv[3]);
	output_file.close();
}
