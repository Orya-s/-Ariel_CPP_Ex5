#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include "InOrderIterator.hpp"
#include "PreOrderIterator.hpp"
#include "PostOrderIterator.hpp"


namespace ariel
{
    template<typename T>
    class BinaryTree
    {
        
        private:
            Node<T>* root;

        public:
            
            BinaryTree() : root(nullptr) {} 
            BinaryTree(const BinaryTree<T> &bt) 
            {
                root = new Node<T>(*bt.root);
            }
            ~BinaryTree() 
            {
                delete root;
            }
            

            /// Adding nodes functions ///

            BinaryTree& add_root(T val)
            {
                if (root)
                {
                    root->val = val;
                }
                else
                {
                    root = new Node<T>(val);
                }
                return *this;
            }

            BinaryTree& add_left(T father, T son)
            {
                if (!root)
                {
                    throw("Illegal action - this tree has no root");
                }

                Node<T> *temp = nullptr;
                for (auto it = begin_inorder() ; it != end_inorder() ; ++it) 
                {   
                    if (*it == father)
                    {
                        temp = it.get_ptr();
                        it = end_inorder();
                    }
                }  

                if (temp == nullptr)
                {
                    throw "First Element Does Not Exist In The Binary Tree";
                }

                if (temp->left)
                {
                    temp->left->val = son;
                    return *this;
                }
                
                temp->left = new Node<T>(son);

                return *this;
            }

            BinaryTree& add_right(T father, T son)
            {
                if (!root)
                {
                    throw("Illegal action - this tree has no root");
                }
                
                Node<T> *temp = nullptr;
                for (auto it = begin_inorder() ; it != end_inorder() ; ++it) 
                {   
                    if (*it == father)
                    {
                        temp = it.get_ptr();
                        it = end_inorder();
                    }
                }  

                if (temp == nullptr)
                {
                    throw "First Element Does Not Exist In The Binary Tree";
                }

                if (temp->right)
                {
                    temp->right->val = son;
                    return *this;
                }
                
                temp->right = new Node<T>(son);

                return *this;
            }


            // assigning operator
            BinaryTree& operator=(const BinaryTree<T>& other) 
            {
                if (this != &other)
                {
                    delete root;
                    root = new Node<T>(*other.root);
                }
                
                return *this;
            }

            /// Move constructor and operator ///
            BinaryTree(BinaryTree&& other) noexcept
            {
                root = other.root;
                other.root = nullptr;
            }
            BinaryTree& operator=(BinaryTree&& other) noexcept
            {
                if (root) {delete root;}
                root  = other.root;
                other.root = nullptr;
                return *this;
            }


            /// Iterating functions ///

            InOrderIterator<T> begin()
            {
                return begin_inorder();
            }
            InOrderIterator<T> end()
            {
                return end_inorder();
            }

            PreOrderIterator<T> begin_preorder()
            {
                return ++(PreOrderIterator<T>(root));
            }
            PreOrderIterator<T> end_preorder()
            {
                return PreOrderIterator<T>(nullptr);
            }

            InOrderIterator<T> begin_inorder()
            {
                return ++(InOrderIterator<T>(root));
            }
            InOrderIterator<T> end_inorder()
            {
                return InOrderIterator<T>(nullptr);
            }

            PostOrderIterator<T> begin_postorder()
            {
                return ++(PostOrderIterator<T>(root));
            }
            PostOrderIterator<T> end_postorder()
            {
                return PostOrderIterator<T>(nullptr);
            }

           

            static void printBT(std::ostream& out, const std::string& prefix, const Node<T>* node, bool isLeft)
            {
                if( node != nullptr )
                {
                    out << prefix;

                    if (isLeft)
                    {
                        out << "├──";
                    }
                    else
                    {
                        out << "└──";
                    }
                    
                    out << node->val << std::endl;

                    // enter the next tree level - left and right branch
                    printBT(out, prefix + (isLeft ? "│   " : "    "), node->left, true);
                    printBT(out, prefix + (isLeft ? "│   " : "    "), node->right, false);
                }
            }

            friend std::ostream& operator<<(std::ostream& out, const BinaryTree& tree) {

                printBT(out, "", tree.root, false);
                return out;
            }

    };    
} 