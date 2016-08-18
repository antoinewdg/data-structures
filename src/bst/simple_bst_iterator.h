//
// Created by antoinewdg on 18/08/16.
//

#ifndef DATA_STRUCTURES_SIMPLE_BST_ITERATOR_H
#define DATA_STRUCTURES_SIMPLE_BST_ITERATOR_H

#include <boost/iterator/iterator_facade.hpp>

#include "simple_bst_node.h"


namespace dst {
    template<class T>
    class SimpleBSTConstIterator :
            public boost::iterator_facade<SimpleBSTConstIterator<T>, T const, boost::forward_traversal_tag> {
    public:
        typedef SimpleBSTNode <T> node_type;

        SimpleBSTConstIterator() : node(nullptr) {}

        explicit SimpleBSTConstIterator(node_type *node) : node(node) {}

        static node_type *get_leftmost_child(node_type *node) {
            while (node->left != nullptr) { node = node->left; }
            return node;
        }

    private:
        friend class boost::iterator_core_access;

        void increment() {
            if (node->right != nullptr) {
                node = get_leftmost_child(node->right);
                return;
            }

            node = _get_first_parent_from_left(node);


        }


        node_type *_get_first_parent_from_left(node_type *node) {
            while (node->parent != nullptr) {
                if (node->parent->left == node) { return node->parent; }
                node = node->parent;
            }
            return nullptr;
        }

        bool equal(SimpleBSTConstIterator const &other) const {
            return node == other.node;
        }

        T const &dereference() const { return node->value; }

        node_type *node;
    };
}

#endif //DATA_STRUCTURES_SIMPLE_BST_ITERATOR_H
