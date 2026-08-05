# Memory Ownership

Directories own their children using shared_ptr<Node>.

Each Node stores a weak_ptr<Directory> to its parent to avoid cyclic references.