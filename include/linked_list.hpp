#pragma once
#ifndef LCODE_LIST_H
#define LCODE_LIST_H

#include <cstddef>  // size_t
#include <string>
#include <stdexcept>    // std::out_of_range

namespace LCode
{

// this has no template; definition will be in .cpp file
std::string say_hi();

// this has a template; all method definitions will be in .tcpp file
template <typename ElemT>
class LinkedList
{
    class Node
    {
        ElemT data;
        Node * next;
        Node * prev;
    public:
        Node(ElemT new_data)
        : data{new_data}, next{nullptr}, prev{nullptr}
        { }

        Node(const Node & other)
        : data{other.data}, next{other.next}, prev{other.prev}
        { }

        Node * set_next(Node * ptr)
        {
            next = ptr;
            return next;
        }

        Node * get_next()
        {
            return next;
        }

        Node * set_prev(Node * ptr)
        {
            prev = ptr;
            return prev;
        }

        Node * get_prev()
        {
            return prev;
        }

        ElemT set_data(ElemT new_data)
        {
            data = new_data;
        }

        ElemT get_data()
        {
            return data;
        }

        const Node & operator = (const Node & other)
        {
            data = other.data;
            prev = other.prev;
            next = other.next;
        }

    };

    Node * head;
    Node * tail;
    size_t list_size;

public:
    LinkedList();

    LinkedList(LinkedList<ElemT> & other);

    void append(ElemT new_element);

    size_t size()
    {
        return list_size;
    }

    ElemT operator [] (long long index)
    {
        if (index < 0 || index >= static_cast<long long>(list_size))
        {
            throw std::out_of_range{"index " + std::to_string(index)
                                    + " is invalid."};
        }

        Node * n = head;
        for (size_t i = 0; i < static_cast<size_t>(index); ++i)
        {
            n = n->get_next();
        }
        return n->get_data();
    }
};
}

// Needed for separate compilation of template functions
#ifdef TEMPLATE_SEPARATE_COMPILATION
    #include "../src/linked_list.tcpp"
#endif

#endif // LCODE_LIST_H