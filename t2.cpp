#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string line;
    
    std::cout << "Enter lines of text (Ctrl+D to end):" << std::endl;

    while (std::getline(std::cin, line)) {
        std::cout << "Read line: " << line << std::endl;
    }

    if (std::cin.eof()) {
        std::cout << "End of file reached." << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}

    std::cout << "Enter more lines of text:" << std::endl;
    while (std::getline(std::cin, line)) {
        std::cout << "Read line: " << line << std::endl;
    }

    return 0;
}
