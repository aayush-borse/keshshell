#include "kesh/filesystem/Directory.h"


Directory::Directory(const std::string& name) : Node(name)
{

}
NodeType Directory::getType() const
{
    return NodeType::Directory;
}

std::size_t Directory::getSize() const
{
    std::size_t totalSize = 0;

    for (const auto& child : children)
    {
        totalSize += child->getSize();
    }

    return totalSize;
}