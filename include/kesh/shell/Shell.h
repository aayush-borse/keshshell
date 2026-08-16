#pragma once 

#include <string>
#include "kesh/filesystem/FileSystem.h"


class Shell
{
    private:
    FileSystem fileSystem;
    
    void executeCommand(const std::string& input);

    public:
    Shell();

    void run();
};