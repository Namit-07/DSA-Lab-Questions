#ifndef STACK111_H
#define STACK111_H

#include <iostream>
#include <stdexcept>

template <class X>
class linkedlist
{
    struct list
    {
        X data;
        list *next;
    } *start = nullptr;

    void clear()
    {
        while (start != nullptr)
        {
            list *next = start->next;
            delete start;
            start = next;
        }
    }

    void display_reverse(list *current) const
    {
        if (current == nullptr)
            return;
        display_reverse(current->next);
        std::cout << current->data << ' ';
    }

public:
    linkedlist() = default;

    ~linkedlist()
    {
        clear();
    }

    linkedlist(const linkedlist &) = delete;
    linkedlist &operator=(const linkedlist &) = delete;

    void insert_beg(X element)
    {
        start = new list{element, start};
    }

    void insert_end(X element)
    {
        list *new_node = new list{element, nullptr};
        if (start == nullptr)
        {
            start = new_node;
            return;
        }

        list *current = start;
        while (current->next != nullptr)
            current = current->next;
        current->next = new_node;
    }

    void insert_after(X element, X target)
    {
        list *current = start;
        while (current != nullptr && current->data != target)
            current = current->next;
        if (current == nullptr)
            throw std::out_of_range("target element not found");
        current->next = new list{element, current->next};
    }

    void insert_before(X element, X target)
    {
        if (start == nullptr)
            throw std::out_of_range("target element not found");
        if (start->data == target)
        {
            insert_beg(element);
            return;
        }

        list *current = start;
        while (current->next != nullptr && current->next->data != target)
            current = current->next;
        if (current->next == nullptr)
            throw std::out_of_range("target element not found");
        current->next = new list{element, current->next};
    }

    X delete_beg()
    {
        if (start == nullptr)
            throw std::out_of_range("cannot delete from an empty list");
        list *old = start;
        X value = old->data;
        start = old->next;
        delete old;
        return value;
    }

    X delete_end()
    {
        if (start == nullptr)
            throw std::out_of_range("cannot delete from an empty list");
        if (start->next == nullptr)
            return delete_beg();

        list *current = start;
        while (current->next->next != nullptr)
            current = current->next;
        list *old = current->next;
        X value = old->data;
        current->next = nullptr;
        delete old;
        return value;
    }

    X delete_specific(X element)
    {
        if (start == nullptr)
            throw std::out_of_range("element not found");
        if (start->data == element)
            return delete_beg();

        list *current = start;
        while (current->next != nullptr && current->next->data != element)
            current = current->next;
        if (current->next == nullptr)
            throw std::out_of_range("element not found");

        list *old = current->next;
        X value = old->data;
        current->next = old->next;
        delete old;
        return value;
    }

    void traverse_forward() const
    {
        for (list *current = start; current != nullptr; current = current->next)
            std::cout << current->data << ' ';
        std::cout << '\n';
    }

    void traverse_backward() const
    {
        display_reverse(start);
        std::cout << '\n';
    }

    void reverse()
    {
        list *previous = nullptr;
        list *current = start;
        while (current != nullptr)
        {
            list *next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        start = previous;
    }

    void fun(list *current) const
    {
        if (current == nullptr)
            return;
        std::cout << current->data << ' ';
        fun(current->next);
    }

    void display() const
    {
        traverse_forward();
    }
};

#endif