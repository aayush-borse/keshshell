#include "kesh/filesystem/File.h"

File::File(const std::string& name)
    : Node(name)

    {

    }

NodeType File::getType() const
{
    return NodeType::File;
}

std::size_t File::getSize() const
{
    return content.size();
    
}

void File::write(const std::string& data)
{
    content = data;
}

const std::string& File::read() const
{
    return content;
}