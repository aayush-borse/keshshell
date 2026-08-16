#pragma once

#include <memory>
#include <vector>

#include "kesh/filesystem/Node.h"

class Directory: public Node
{

private:
   std::vector<std::shared_ptr<Node>> children;


public:
   explicit Directory(const std::string& name);

   NodeType getType() const override;

   std::size_t getSize() const override;

   bool addChild(std::shared_ptr<Node> child);

   std::shared_ptr<Node> findChild(const std::string& name) const;
    
   const std::vector<std::shared_ptr<Node>>& getChildren() const;
};