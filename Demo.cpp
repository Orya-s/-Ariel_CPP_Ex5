#include <stdlib.h>
#include "doctest.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;


TEST_CASE("Check Binary Tree Complex Additions")
{

    SUBCASE("InOrder")
    {
        /*********************** SUBCASE("InOrder") *****************************
        *************************************************************************
        *                                ____iteration,(11)___                  *
        *                               /                     \                 *
        *                             in(9)                    logical(21)      *
        *                            /  \                     /       \         *
        *                          to(7) InOrder(10)     exact(19)     order(22)*
        *                        /   \                  /     \                 *
        *                   we're(5)  check,(8)      In(17)    same(20)         *
        *                  /     \                   /  \                       *
        *          sentence(3)    going(6)      be(15)   THE(18)                *
        *         /        \                      /  \                          *
        *       is(1)       that(4)     Sentence(13)  presented(16)             *
        *     /    \                     /        \                             *
        * This(0)      the(2)         The(12)      should(14)                   *
        *                                                                       *
        *************************************************************************
        */

        string s = "This is the sentence that we're going to check, in InOrder iteration, The Sentence should be presented In THE exact same logical order.";
        BinaryTree<string> t_str;
        istringstream iss(s);
        /* Create a vector of all the words in the senctence, without the spaces */
        vector<string> words{istream_iterator<string>{iss}, istream_iterator<string>{}};
        /* Add "iteration" as the root of the tree, "in" as his left son and "logical" as his right son */
        t_str.add_root(string("iteration,"));
        t_str.add_left(string("iteration,"), string("in"));
        t_str.add_right(string("iteration,"), string("logical"));
        /* Add the words based on the index of the word in the vector (view the image above for better understaing) */
        for (unsigned long i = 9; i >= 3; i-=2)
        {
            string prev_l = words[i];
            string left_l = words[i - 2];
            string right_l = words[i + 1];
            t_str.add_left(prev_l, left_l);
            t_str.add_right(prev_l, right_l);
        }
        t_str.add_left(string("is"), string("This"));
        t_str.add_right(string("is"), string("the"));
        for (unsigned long i = 21; i >= 15; i-=2)
        {
            string prev_l = words[i];
            string left_l = words[i - 2];
            string right_l = words[i + 1];
            t_str.add_left(prev_l, left_l);
            t_str.add_right(prev_l, right_l);
        }
        t_str.add_left(string("Sentence"), string("The"));
        t_str.add_right(string("Sentence"), string("should"));
        string ans, ans_in;
        /* Create the comparison string by adding the word with spaces sperating them */
        for (auto it = t_str.begin_inorder(); it != t_str.end_inorder(); it++)
        {
            ans_in = ans_in + " " + *it;
        }
        /* Check both regular and inOrder iterator because they should act the same */
        for (auto it = t_str.begin(); it != t_str.end(); it++)
        {
            ans = ans + " " + *it;
        }
        /* Remove the space before the first word, and compare */
        CHECK_EQ(s, ans.substr(1));
        CHECK_EQ(s, ans_in.substr(1));
    }
}