#pragma once
#include <string>
#include <memory>

class Directory;

enum class NodeType {
    File,
    Directory
};
// we used scoped enum here to avoid  conflict
/*
so lets say we do something like
enum colour
{
     Red,
     Blue
     };
     
enum fruit
{
      Red,
      Green
      };
      
      
    compiler will get confused
    */


    class Node : public std::enable_shared_from_this<Node>

    {
        friend class Directory;
        private:
        std::string name;
        std::weak_ptr<Directory> parent;

        protected:
         void setParent(std::weak_ptr<Directory> parent);

       
        public:
            explicit Node(const std::string& name);

            virtual ~Node() = default;

            const std::string& getName() const;

            virtual NodeType getType() const = 0;

            virtual std::size_t getSize() const = 0;
            std::shared_ptr<Directory> getParent() const;
        // Public api
    };