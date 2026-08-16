#pragma once 

#include <string>
#include "kesh/filesystem/FileSystem.h"


class Shell
{
    private:
    FileSystem fileSystem;
      std::shared_ptr<Directory> currentDirectory;
      
    
    void executeCommand(const std::string& input);
     bool changeDirectory(const std::string& name);
     std::string getCurrentPath() const;
    public:
    Shell();

    void run();
};
