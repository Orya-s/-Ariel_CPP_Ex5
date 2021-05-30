#pragma once
#include <stack>
#include <stdexcept>
#include <iostream>
#include "Node.hpp"

namespace ariel 
{
    template<typename T>
    class PreOrderIterator
    {        
        private:
            Node<T>* pointer_to_current_node;
            std::stack<Node<T>*> nodes;  

        public:
            PreOrderIterator(Node<T>* ptr = nullptr) : pointer_to_current_node(ptr) 
            {
                if(ptr) nodes.push(ptr);
            } 
            ~PreOrderIterator() {}
            
            T& operator*() const 
            {
                if (!pointer_to_current_node)
                    std::cout << "No value in node" << std::endl;
                return pointer_to_current_node->val;
            }

            T* operator->() const 
            { 
                return &(pointer_to_current_node->val); 
            }
                        
            PreOrderIterator &operator++() {
                if (!nodes.empty()) 
                {
                    pointer_to_current_node = nodes.top();
                    nodes.pop();
            
                    if (pointer_to_current_node->right)
                    {
                        nodes.push(pointer_to_current_node->right);
                    }
                    if (pointer_to_current_node->left)
                    {
                        nodes.push(pointer_to_current_node->left);
                    }
                }
                else
                {
                    pointer_to_current_node = nullptr;
                }

                return *this;
            }
            
            const PreOrderIterator operator++(int) {

                PreOrderIterator tmp = *this;

                if (!nodes.empty()) 
                {
                    pointer_to_current_node = nodes.top();
                    nodes.pop();
            
                    if (pointer_to_current_node->right)
                    {
                        nodes.push(pointer_to_current_node->right);
                    }
                    if (pointer_to_current_node->left)
                    {
                        nodes.push(pointer_to_current_node->left);
                    }
                }
                else
                {
                    pointer_to_current_node = nullptr;
                }

                return tmp;
            }

            bool operator==(const PreOrderIterator &other) const {
                return pointer_to_current_node == other.pointer_to_current_node;
            }

            bool operator!=(const PreOrderIterator &other) const {
                return pointer_to_current_node != other.pointer_to_current_node;
            }

    };
}