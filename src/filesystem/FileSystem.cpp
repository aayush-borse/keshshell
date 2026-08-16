#include "kesh/filesystem/FileSystem.h"

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