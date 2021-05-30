#pragma once
#include <stack>
#include <stdexcept>
#include <iostream>
#include "Node.hpp"

namespace ariel 
{
    template<typename T>
    class InOrderIterator
    {        
        private:
            Node<T>* pointer_to_current_node;
            Node<T>* stk_iter;   
            std::stack<Node<T>*> nodes;  

        public:
            InOrderIterator(Node<T>* ptr = nullptr) : pointer_to_current_node(ptr), stk_iter(ptr) {}
            ~InOrderIterator() {}
            
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

            InOrderIterator &operator++() {
                if (stk_iter != nullptr || !nodes.empty()) {

                    while (stk_iter != nullptr) 
                    {
                        nodes.push(stk_iter);
                        stk_iter = stk_iter->left;
                    }  

                    stk_iter = nodes.top();
                    nodes.pop();
                    
                    pointer_to_current_node = stk_iter;
                    stk_iter = stk_iter->right;
                } 
                else 
                {
                    pointer_to_current_node = nullptr;
                }

                return *this;
            }

            
            const InOrderIterator operator++(int) {

                InOrderIterator tmp = *this;

                if (stk_iter != nullptr || !nodes.empty()) {

                    while (stk_iter != nullptr) 
                    {
                        nodes.push(stk_iter);
                        stk_iter = stk_iter->left;
                    }   

                    stk_iter = nodes.top();
                    nodes.pop();
                    
                    pointer_to_current_node = stk_iter;
                    stk_iter = stk_iter->right;
                } 
                else 
                {
                    pointer_to_current_node = nullptr;
                }

                return tmp;
            }

            bool operator==(const InOrderIterator &other) const {
                return pointer_to_current_node == other.pointer_to_current_node;
            }

            bool operator!=(const InOrderIterator &other) const {
                return pointer_to_current_node != other.pointer_to_current_node;
            }

            Node<T>* get_ptr() const
            {
                return pointer_to_current_node;
            }
    };
}