#pragma once

#include "kesh/filesystem/Node.h"

class File : public Node{
    private:
    std::string content;


    public:
    explicit File(const std::string& name);

    NodeType getType() const override;

    std::size_t getSize() const override;

    void write(const std::string& data);

    const std::string& read() const;
};