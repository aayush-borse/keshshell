# Memory Ownership

## Overview

Kesh Shell models the filesystem as a tree.

Each Directory owns its child nodes using:

- std::shared_ptr<Node>

Each Node stores a non-owning reference to its parent using:

- std::weak_ptr<Directory>

## Why?

If both parent and child used shared_ptr, they would keep each other alive forever, creating a reference cycle.

Using weak_ptr for the parent breaks the cycle while still allowing upward navigation (`cd ..`, `pwd`).