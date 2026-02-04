#include "Zombie.hpp"

int main() {
    std::cout << "=== Testing newZombie (heap allocation) ===" << std::endl;
    Zombie* heapZombie = newZombie("HeapWalker");
    heapZombie->announce();
    delete heapZombie;
    
    std::cout << "\n=== Testing randomChump (stack allocation) ===" << std::endl;
    randomChump("StackShambler");
    
    std::cout << "\n=== Demonstrating scope differences ===" << std::endl;
    std::cout << "Creating heap zombie..." << std::endl;
    Zombie* persistent = newZombie("Persistent");
    persistent->announce();
    
    std::cout << "Creating stack zombie in scope..." << std::endl;
    {
        Zombie temporary("Temporary");
        temporary.announce();
    }
    std::cout << "Stack zombie destroyed when leaving scope" << std::endl;
    
    std::cout << "Heap zombie still exists:" << std::endl;
    persistent->announce();
    delete persistent;
    
    return 0;
}