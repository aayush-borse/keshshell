#include "kesh/filesystem/FileSystem.h"

FileSystem::FileSystem()
      :root(std::make_shared<Directory>("Root"))
      {

      }
      std::shared_ptr<Directory> FileSystem::getRoot() const
      {
        return root;
      }