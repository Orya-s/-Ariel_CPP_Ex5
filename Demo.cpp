#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;


int main()
{
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1);
    tree_of_ints.add_left(1, 2);
    tree_of_ints.add_right(1, 3);
    tree_of_ints.add_left(2, 4);
    tree_of_ints.add_right(2, 5);
    tree_of_ints.add_left(3, 6);
    tree_of_ints.add_right(3, 7);
    tree_of_ints.add_left(4, 8);
    tree_of_ints.add_right(4, 9);
    tree_of_ints.add_right(9, 17);
    tree_of_ints.add_left(5, 10);
    tree_of_ints.add_right(5, 11);
    tree_of_ints.add_left(6, 12);   
    tree_of_ints.add_right(6, 13);   
    tree_of_ints.add_left(7, 14);
    tree_of_ints.add_right(7, 15);
 
    cout << tree_of_ints << endl;
    return 0;
}