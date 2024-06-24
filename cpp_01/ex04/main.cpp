#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

std::string read_file_to_str(const char* filename)
{
    std::ifstream input_file(filename);
    if (!input_file)
    {
        std::cerr << "Error opening " << filename << std::endl;
        return "";
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
		return "";
    }

	input_file.close();
    return str;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " filename s1 s2\n";
		return 1;
	}

	std::string str = read_file_to_str(argv[1]);

	std::string new_file = std::string(argv[1]) + ".replace";
	std::ofstream output_file(new_file);
    if (!output_file)
	{
        std::cerr << "Error opening " << argv[2] << std::endl;
        return 1;
    }

	size_t s1_len = std::strlen(argv[2]); // 0
	size_t s2_len = std::strlen(argv[3]); // 0
	size_t pos = 0;

	while ((pos = str.find(argv[2], pos)) != std::string::npos)
	{
		output_file << str.substr(0, pos) << argv[3]; 
		str = str.substr(pos + s1_len);
		pos = 0;
	}

	output_file << str;

	output_file.close();
}

// #include <iostream>
// #include <fstream>
// #include <cstring>
// #include <sstream>


// int main(int argc, char **argv)
// {
// 	if (argc != 4)
// 	{
// 		std::cerr << "Usage: " << argv[0] << " filename s1 s2\n";
// 		return 1;
// 	}

// 	std::ifstream input_file(argv[1]);
//     if (!input_file)
// 	{
//         std::cerr << "Error opening " << argv[1] << std::endl;
//         return 1;
//     }

// 	std::ofstream output_file(argv[2]);
//     if (!output_file)
// 	{
//         std::cerr << "Error opening " << argv[2] << std::endl;
//         return 1;
//     }


// 	size_t s1_len = std::strlen(argv[2]); // 0
// 	size_t s2_len = std::strlen(argv[3]); // 0
// 	size_t pos = 0;

// 	std::string line;
//     while (std::getline(input_file, line))
// 	{
// 		pos = 0;
// 		while ((pos = line.find(argv[2], pos)) != std::string::npos)
// 		{
//             output_file << line.substr(0, pos) << argv[3]; 
//             line = line.substr(pos + s1_len);
// 			pos = 0;
//         }

//         output_file << line << std::endl;
//     }

// 	input_file.close();
// 	output_file.close();
// }