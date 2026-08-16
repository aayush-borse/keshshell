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

bool Directory::addChild(std::shared_ptr<Node> child)
{
    if (!child)
    {
        return false;
    }

    auto directory = std::dynamic_pointer_cast<Directory>(
        shared_from_this()
    );

    child->setParent(directory);

    children.push_back(child);

    return true;
}


std::shared_ptr<Node> Directory::findChild(const std::string& name) const
{
    for (const auto& child : children)
    {
        if (child->getName() == name)
        {
            return child;
        }
    }

    return nullptr;
}

const std::vector<std::shared_ptr<Node>>& Directory::getChildren() const
{
    return children;
}