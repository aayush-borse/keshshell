#include <iostream>
#include <memory>
#include "kesh/filesystem/File.h"

int main()
{
    auto file = std::make_shared<File>("hello.txt");

    file->write("Welcome to Kesh Shell!");

    std::cout << "Name    : " << file->getName() << '\n';
    std::cout << "Content : " << file->read() << '\n';
    std::cout << "Size    : " << file->getSize() << " bytes\n";

    if (file->getType() == NodeType::File)
    {
        std::cout << "Type    : File\n";
    }

    return 0;
}