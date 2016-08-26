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
        typedef SimpleBST<T> self_type;
        typedef SimpleBSTNode<T> node_type;
        typedef typename node_type::ptr_type node_ptr_type;
        typedef SimpleBSTConstIterator<T> const_iterator;

        SimpleBST() : m_root(nullptr), m_size(0) {}

        SimpleBST(const std::initializer_list<T> &values) : SimpleBST(std::vector<T>(values)) {}

        SimpleBST(std::vector<T> values) : SimpleBST(values.begin(), values.end()) {}

        template<class RandomAccessIterator>
        SimpleBST(RandomAccessIterator begin, RandomAccessIterator end): SimpleBST() {
            std::sort(begin, end);
            _build_node(m_root, begin, end, m_size);
        }


        const_iterator begin() const {
            if (m_root == nullptr) {
                return end();
            }
            return const_iterator(const_iterator::get_leftmost_child(m_root));
        }

        const_iterator end() const {
            return const_iterator(nullptr);
        }

        bool contains(const value_type &value) {
            return _node_contains(m_root, value);
        }

        void insert(const value_type &value) {
            m_size++;
            _insert_to_node(m_root, value);
        }

        size_t const size() {
            return m_size;
        }

        bool operator==(const std::initializer_list<T> &l) {
            return std::equal(l.begin(), l.end(), begin(), end());
        }

        bool operator!=(const std::initializer_list<T> &l) {
            return !(*this == l);
        }

        bool operator==(const self_type &other) {
            return std::equal(begin(), end(), other.begin(), other.end());
        }

        bool operator!=(const self_type &other) {
            return !(*this == other);
        }

    private:
        template<class RandomAccessIterator>
        void _build_node(node_ptr_type &node, RandomAccessIterator begin, RandomAccessIterator end,
                         size_t &size, node_ptr_type parent = nullptr) {
            if (begin == end) {
                return;
            }
            RandomAccessIterator mid = begin + std::distance(begin, end) / 2;
            node = std::make_shared<node_type>(*mid, parent);
            size++;
            _build_node(node->left, begin, mid, size, node);
            _build_node(node->right, mid + 1, end, size, node);

        }




        bool _node_contains(node_ptr_type node, const value_type &value) {
            if (node == nullptr) {
                return false;
            }
            return node->value == value ||
                   _node_contains(node->left, value) ||
                   _node_contains(node->right, value);
        }

        void _insert_to_node(node_ptr_type &node, const value_type &value, node_ptr_type parent = nullptr) {
            if (node == nullptr) {
                node = std::make_shared<node_type>(value, parent);
                return;
            }
            if (value <= node->value) {
                _insert_to_node(node->left, value, node);
            } else {
                _insert_to_node(node->right, value, node);
            }

        }

        node_ptr_type m_root;
        size_t m_size;


    };
}

#endif //DATA_STRUCTURES_SIMPLE_BST_H
