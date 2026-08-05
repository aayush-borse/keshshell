#include "kesh/filesystem/Node.h"


Node::Node(const std::string& name)
   : name(name)
   { // called as initializer list

   }

const std::string& Node::getName() const
{
    return name;
}