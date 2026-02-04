#include "Harl.hpp"

int getLevelIndex(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }
    
    std::string level = argv[1];
    Harl harl;
    int levelIndex = getLevelIndex(level);
    
    switch (levelIndex) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            std::cout << std::endl;
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
    
    return 0;
}