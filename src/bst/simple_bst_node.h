//
// Created by antoinewdg on 18/08/16.
//

#ifndef DATA_STRUCTURES_SIMPLE_BST_NODE_H
#define DATA_STRUCTURES_SIMPLE_BST_NODE_H

#include <memory>

namespace dst {
    template<class T>
    struct SimpleBSTNode {
        typedef T value_type;
        typedef SimpleBSTNode<T> self_type;
        typedef std::shared_ptr<self_type> ptr_type;
        typedef std::weak_ptr<self_type> weak_ptr_type;
        T value;
        ptr_type left, right;
        weak_ptr_type parent;

        SimpleBSTNode(T value, ptr_type &parent) : value(value), left(nullptr), right(nullptr), parent(parent) {}
    };
}
#endif //DATA_STRUCTURES_SIMPLE_BST_NODE_H
