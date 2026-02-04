#include "Zombie.hpp"

int main() {
    int N = 5;
    std::string name = "HordeMember";
    
    std::cout << "=== Creating zombie horde of " << N << " zombies ===" << std::endl;
    Zombie* horde = zombieHorde(N, name);
    
    if (horde == NULL) {
        std::cout << "Failed to create zombie horde" << std::endl;
        return 1;
    }
    
    std::cout << "\n=== All zombies announce themselves ===" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }
    
    std::cout << "\n=== Destroying the horde ===" << std::endl;
    delete[] horde;
    
    std::cout << "\n=== Testing edge cases ===" << std::endl;
    Zombie* emptyHorde = zombieHorde(0, "EmptyName");
    if (emptyHorde == NULL) {
        std::cout << "Correctly handled N=0 case" << std::endl;
    }
    
    Zombie* singleZombie = zombieHorde(1, "Loner");
    if (singleZombie != NULL) {
        std::cout << "Single zombie created: ";
        singleZombie->announce();
        delete[] singleZombie;
    }
    
    return 0;
}