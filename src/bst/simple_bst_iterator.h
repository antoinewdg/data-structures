//
// Created by antoinewdg on 18/08/16.
//

#ifndef DATA_STRUCTURES_SIMPLE_BST_ITERATOR_H
#define DATA_STRUCTURES_SIMPLE_BST_ITERATOR_H

#include <memory>
#include <boost/iterator/iterator_facade.hpp>

#include "simple_bst_node.h"


namespace dst {
    template<class T>
    class SimpleBSTConstIterator :
            public boost::iterator_facade<SimpleBSTConstIterator<T>, T const, boost::forward_traversal_tag> {
    public:
        typedef SimpleBSTNode <T> node_type;
        typedef typename node_type::ptr_type node_ptr_type;

        SimpleBSTConstIterator() : m_node(nullptr) {}

        explicit SimpleBSTConstIterator(node_ptr_type node) : m_node(node) {}

        static node_ptr_type get_leftmost_child(node_ptr_type node) {
            while (node->left != nullptr) { node = node->left; }
            return node;
        }

    private:
        friend class boost::iterator_core_access;

        void increment() {
            if (m_node->right != nullptr) {
                m_node = get_leftmost_child(m_node->right);
                return;
            }

            m_node = _get_first_parent_from_left(m_node);


        }


        node_ptr_type _get_first_parent_from_left(node_ptr_type node) {
            node_ptr_type parent = node->parent.lock();
            while (parent != nullptr) {
                if (parent->left == node) { return parent; }
                node = parent;
                parent = node->parent.lock();
            }
            return nullptr;
        }

        bool equal(SimpleBSTConstIterator const &other) const {
            return m_node == other.m_node;
        }

        T const &dereference() const { return m_node->value; }

        node_ptr_type m_node;
    };
}

#endif //DATA_STRUCTURES_SIMPLE_BST_ITERATOR_H
