#include <iostream>
#include <memory>

#include "kesh/filesystem/File.h"
#include "kesh/filesystem/FileSystem.h"

int main()
{
    FileSystem fs;

    auto root = fs.getRoot();

    auto file1 = std::make_shared<File>("hello.txt");
    auto file2 = std::make_shared<File>("notes.txt");

    file1->write("Hello");
    file2->write("Welcome to Kesh Shell");

    root->addChild(file1);
    root->addChild(file2);

    std::cout << "Root: " << root->getName() << '\n';
    std::cout << "Total Size: " << root->getSize() << " bytes\n";

    auto found = root->findChild("notes.txt");

    if (found)
    {
        std::cout << "Found: " << found->getName() << '\n';
    }

    return 0;
}