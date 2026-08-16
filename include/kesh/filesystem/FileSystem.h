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

    std::shared_ptr<Directory> getRoot() const;

    bool createDirectory(const std::string& name);

    bool createFile(
        std::shared_ptr<Directory> directory,
        const std::string& name
    );
};