#include "PhoneBook.hpp"

int main(void)
{    
    std::string input;
    PhoneBook phonebook;

    while (true)
    {
        std::cout << "Please, Choose a command from ADD, SEARCH, or EXIT:\n";
        std::cin >> input;

        if (input == "EXIT")
            break;
        else if (input == "SEARCH")
        {
            phonebook.ShowAllList();
            phonebook.ShowOneContact();
        }
        else if (input == "ADD")
            phonebook.AddList();
        else
            std::cout << "Wrong command! Input a right command.\n";
    }    
    return 0;
}