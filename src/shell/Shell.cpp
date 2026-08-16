#include <iostream>
#include <sstream>
#include <string>


#include "kesh/shell/Shell.h"

Shell::Shell()
{

}

void Shell::run()
{
    std::cout << "Kesh Shell\n";

   while (true)
{
    std::cout << "Kesh> ";

    std::string input;
    std::getline(std::cin, input);

    if (input == "exit")
    {
        break;
    }

    executeCommand(input);
}
}
void Shell::executeCommand(const std::string& input)
{
    std::istringstream stream(input);

    std::string command;
    stream >> command;

    if (command == "mkdir")
    {
        std::string name;
        stream >> name;

        if (name.empty())
        {
            std::cout << "Usage: mkdir <name>\n";
            return;
        }

        if (fileSystem.createDirectory(name))
        {
            std::cout << "Directory created: " << name << '\n';
        }
        else
        {
            std::cout << "Failed to create directory.\n";
        }
    }
    else if (!command.empty())
    {
        std::cout << "Unknown command: " << command << '\n';
    }
}