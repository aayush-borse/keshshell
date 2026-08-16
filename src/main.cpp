#include <iostream>
#include <memory>

#include "kesh/filesystem/File.h"
#include "kesh/filesystem/Directory.h"

int main()
{
    auto root = std::make_shared<Directory>("Root");

    auto file1 = std::make_shared<File>("hello.txt");
    auto file2 = std::make_shared<File>("notes.txt");

    file1->write("Hello User");
    file2->write("Welcome to Kesh Shell we are here to compile!!");

    root->addChild(file1);
    root->addChild(file2);

    auto found = root->findChild("notes.txt");

if (found)
{
    std::cout << "Found: " << found->getName() << '\n';
}
else
{
    std::cout << "File not found.\n";
}

    std::cout << "Directory: " << root->getName() << '\n';
    std::cout << "Total Size: " << root->getSize() << " bytes\n";

    return 0;
}
