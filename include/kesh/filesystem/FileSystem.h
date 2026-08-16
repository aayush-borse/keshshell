#pragma once
#include <memory>

#include "kesh/filesystem/Directory.h"


class FileSystem
{
    private:
    std::shared_ptr<Directory> root;

    
    public:
    FileSystem();

    std::shared_ptr<Directory> getRoot() const;
};