#pragma once
#include <iostream>

namespace ariel
{
    template<typename T>
    struct Node
    {
        T val;
        Node* left;
        Node* right;
        Node() {}
        Node(const T& v) : val(v) {left = right = nullptr;}
        Node(const Node &other) : val(other.val)
        {   
            if (other.right)
            {
                right = new Node(*other.right);
            }
            else
            {
                right = nullptr;
            }
            if (other.left)
            {
                left = new Node(*other.left);
            }
            else
            {
                left = nullptr;
            }
        }

        ~Node() 
        {
            delete left;
            delete right;
        }
    };
}