#include <iostream>
#include <sstream>
#include <string>


#include "kesh/shell/Shell.h"

Shell::Shell() 
         : currentDirectory(fileSystem.getRoot())
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
     if (command == "ls")
{
    for (const auto& child : currentDirectory->getChildren())
    {
        std::cout << child->getName() << '\n';
    }

    return;
}

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
     else if (command == "cd")
{
    std::string name;
    stream >> name;

    if (name.empty())
    {
        std::cout << "Usage: cd <directory>\n";
        return;
    }

    if (!changeDirectory(name))
    {
        std::cout << "Directory not found: " << name << '\n';
    }
}   
else if (command == "pwd")
{
    std::cout << getCurrentPath() << '\n';
}
   else if (command == "touch")
{
    std::string name;
    stream >> name;

    if (name.empty())
    {
        std::cout << "Usage: touch <filename>\n";
        return;
    }

    if (fileSystem.createFile(currentDirectory, name))
    {
        std::cout << "File created: " << name << '\n';
    }
    else
    {
        std::cout << "Failed to create file.\n";
    }
}
    else if (!command.empty())
    {
        std::cout << "Unknown command: " << command << '\n';
    }
   
}
bool Shell::changeDirectory(const std::string& name)
{
    if (name == "..")
    {
        auto parent = currentDirectory->getParent();

        if (parent)
        {
            currentDirectory = parent;
        }

        return true;
    }

    auto node = currentDirectory->findChild(name);

    if (!node)
    {
        return false;
    }

    auto directory = std::dynamic_pointer_cast<Directory>(node);

    if (!directory)
    {
        return false;
    }

    currentDirectory = directory;

    return true;
}
std::string Shell::getCurrentPath() const
{
    std::string path;
    auto current = currentDirectory;

    while (current)
    {
        path = "/" + current->getName() + path;
        current = current->getParent();
    }

    return path;
}