#pragma once
#include <memory>
#include <string>
#include "kesh/filesystem/Directory.h"


class FileSystem
{
    private:
    std::shared_ptr<Directory> root;

    
    public:
    FileSystem();
    bool createDirectory(const std::string& name);

    std::shared_ptr<Directory> getRoot() const;
};