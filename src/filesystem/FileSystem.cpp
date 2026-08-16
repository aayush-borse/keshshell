#include "kesh/filesystem/FileSystem.h"
#include "kesh/filesystem/File.h"

FileSystem::FileSystem()
      :root(std::make_shared<Directory>("Root"))
      {

      }
      std::shared_ptr<Directory> FileSystem::getRoot() const
      {
        return root;
      }


      bool FileSystem::createDirectory(const std::string& name)
{
    auto directory = std::make_shared<Directory>(name);

    return root->addChild(directory);
}
    bool FileSystem::createFile(
    std::shared_ptr<Directory> directory,
    const std::string& name)
{
    if (!directory)
    {
        return false;
    }

    auto file = std::make_shared<File>(name);

    return directory->addChild(file);
}