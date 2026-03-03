#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int health;

public:
    Player(std::string playerName, int startingHealth);
    void takeDamage(int damageAmount);
    void heal(int healAmount);
    void showStats();
};


Player::Player(std::string playerName, int startingHealth) {
    name = playerName;
    health = startingHealth;
}

void Player::takeDamage(int damageAmount) {
    health = health - damageAmount;
    std::cout << name << " took " << damageAmount << " damage! Health is now " << health << ".\n";
}

void Player::heal(int healAmount) {
    health = health + healAmount;
    std::cout << name << " healed " << healAmount << " HP! Health is now " << health << ".\n";
}

void Player::showStats() {
    std::cout << "Player Name: " << name << " | HP: " << health << "\n";
}





void classes_and_objects();

int main() {
    using namespace std; 

    int choice;
    do {
        cout << "\n================================" << endl;
        cout << "   CHOOSE A SECTION TO RUN" << endl;
        cout << "================================" << endl;
        cout << "1. Classes and Objects (Player Example)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "--------------------------------\n" << endl;

        switch (choice) {
            case 1: 
                classes_and_objects(); 
                break;
            case 0: 
                cout << "Exiting program..." << endl; 
                break;
            default: 
                cout << "Invalid choice! Try again." << endl; 
                break;
        }
    } while (choice != 0);

    return 0;
}




void classes_and_objects() {
    std::string heroName, monsterName;
    int heroHealth, monsterHealth;
    int damageTaken, healAmount;

    std::cout << "Starting the game simulation...\n\n";

    std::cout << "Enter your Hero's name: ";
    std::cin >> heroName;
    std::cout << "Enter " << heroName << "'s starting health: ";
    std::cin >> heroHealth;

    std::cout << "\nEnter the Monster's name: ";
    std::cin >> monsterName;
    std::cout << "Enter " << monsterName << "'s starting health: ";
    std::cin >> monsterHealth;

    Player hero(heroName, heroHealth);
    Player monster(monsterName, monsterHealth);

    std::cout << "\n--- Starting Stats ---\n";
    hero.showStats();
    monster.showStats();
    std::cout << "--------------------------------\n";

    std::cout << "\nA fight breaks out!\n";
    std::cout << "How much damage does " << heroName << " take? ";
    std::cin >> damageTaken;
    hero.takeDamage(damageTaken);

    std::cout << "How much damage does " << monsterName << " take? ";
    std::cin >> damageTaken;
    monster.takeDamage(damageTaken);
    
    std::cout << "\n" << heroName << " drinks a potion...\n";
    std::cout << "How much health does " << heroName << " recover? ";
    std::cin >> healAmount;
    hero.heal(healAmount);

    std::cout << "\n--- Final Stats ---\n";
    hero.showStats();
    monster.showStats();
    
    std::cout << "\nFinished running classes and objects section.\n";
}