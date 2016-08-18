//
// Created by antoinewdg on 18/08/16.
//

#ifndef DATA_STRUCTURES_SIMPLE_BST_NODE_H
#define DATA_STRUCTURES_SIMPLE_BST_NODE_H

namespace dst {
    template<class T>
    struct SimpleBSTNode {
        typedef SimpleBSTNode<T> self_type;

        T value;
        self_type *left, *right, *parent;

        SimpleBSTNode(T value, self_type *parent) : value(value), left(nullptr), right(nullptr), parent(parent) {}
    };
}
#endif //DATA_STRUCTURES_SIMPLE_BST_NODE_H
