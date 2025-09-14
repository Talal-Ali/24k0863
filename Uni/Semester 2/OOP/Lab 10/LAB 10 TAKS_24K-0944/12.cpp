#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("debug_target.txt", std::ios::binary);
    if (!file) {
        std::cerr << "Cannot open file.\n";
        return 1;
    }

    std::string input;
    std::streampos offset;

    std::cout << "Enter byte offset (type 'exit' to quit):\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") break;

        offset = std::stoi(input);  

        file.clear();
        file.seekg(offset);

        std::cout << "Pointer before: " << file.tellg() << "\n";

        char buffer[101] = {0}; 
        file.read(buffer, 100);

        std::cout << "Content:\n" << buffer << "\n";
        std::cout << "Pointer after: " << file.tellg() << "\n";
    }

}
