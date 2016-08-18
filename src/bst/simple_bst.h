//
// Created by antoinewdg on 18/08/16.
//

#ifndef DATA_STRUCTURES_SIMPLE_BST_H
#define DATA_STRUCTURES_SIMPLE_BST_H

#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <iostream>

#include "simple_bst_node.h"
#include "simple_bst_iterator.h"

namespace dst {
    template<class T>
    class SimpleBST {
    public:
        typedef T value_type;
        typedef SimpleBSTNode<T> node_type;
        typedef SimpleBSTConstIterator<T> const_iterator;

        SimpleBST(const std::initializer_list<T> &values) : SimpleBST(std::vector<T>(values)) {
        }

        SimpleBST(std::vector<T> values) : SimpleBST(values.begin(), values.end()) {
        }

        ~SimpleBST() {
            _delete_node(root);
        }

        template<class RandomAccessIterator>
        SimpleBST(RandomAccessIterator begin, RandomAccessIterator end): root(nullptr) {
            std::sort(begin, end);
            _build_node(root, begin, end);
        }


        const_iterator begin() {
            if (root == nullptr) {
                return end();
            }
            return const_iterator(const_iterator::get_leftmost_child(root));
        }

        const_iterator end() {
            return const_iterator(nullptr);
        }

    private:
        template<class RandomAccessIterator>
        void _build_node(node_type *&node, RandomAccessIterator begin, RandomAccessIterator end,
                         node_type *parent = nullptr) {
            if (begin == end) {
                return;
            }
            RandomAccessIterator mid = begin + std::distance(begin, end) / 2;
            node = new node_type(*mid, parent);
            _build_node(node->left, begin, mid, node);
            _build_node(node->right, mid + 1, end, node);

        }


        void _delete_node(node_type *node) {
            if (node != nullptr) {
                _delete_node(node->left);
                _delete_node(node->right);
            }
            delete node;
        }

        node_type *root;


    };
}

#endif //DATA_STRUCTURES_SIMPLE_BST_H
