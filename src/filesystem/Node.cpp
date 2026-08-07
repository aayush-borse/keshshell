#include "kesh/filesystem/Node.h"


Node::Node(const std::string& name)
   : name(name)
   { // called as initializer list

   }

const std::string& Node::getName() const
{
    return name;
}

void Node::setParent(std::weak_ptr<Directory> parent)
{
    this->parent = std::move(parent);
}