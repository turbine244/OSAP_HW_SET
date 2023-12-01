/*
Copyright 2023 New_York_Cheesecake

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/*
 * FileName  : AvlTree.cc
 * Content   : function 11
 * Test info : Not-yet
 *
 * !Remark!
 * All comments are made with consideration
 * that the reader has prior knowledge of "AVL Tree"
 * The code follows the style guide - CSE3210.
 */

#include "AvlTree.h"

AvlTree::AvlTree() : root_(nullptr) {}

Node* AvlTree::root() {
    return root_;
}

Node* AvlTree::AvlSearchNode(Node* node, int k) {
    // 1 : current node is empty
    if (node == NULL) {
        return NULL;
    }

    // 2 - 1 : key of current node is equal to target key
    if (node->key == k) {
        return node;
    }

    // 2 - 2 : key of current node is less than target key
    else if (node->key < k) {
        return AvlSearchNode(node->right, k);
    }

    // 2 - 3 : key of current node is greater than target key
    else {
        return AvlSearchNode(node->left, k);
    }
}

void AvlTree::AvlInsertNode(int k, Node*& node) {

    // 1 : node is empty
    if (node == NULL) {
        // 1 - 1 : create a node with key of "k"
        node = new Node();
        node->key = k;
        node->left = NULL;
        node->right = NULL;
        
        // 1 - 2 : set root if root node is empty
        if (root_ == NULL) {
            root_ = node;
        }
    }
    // 2 : change current node by compare key value
    else
    {
        // 2 - 1 : key of current node is greater than target key
        if (k < node->key) {
            AvlInsertNode(k, node->left);
        }

        // 2 - 2 : key of current node is less than target key
        else if (k > node->key) {
            AvlInsertNode(k, node->right);
        }

        // 2 - 3 : key of current node is same with target key
        else {

        }
    }

    // 3 : Check the tree is balanced based on node
    AvlRebalance(node, k);

    // 4 : Change node height
    int left_subtree_height = AvlHeight(node->left);
    int right_subtree_height = AvlHeight(node->right);
    node->height = max(left_subtree_height, right_subtree_height) + 1;

}

void AvlTree::AvlDeleteNode(int k) {
    // 1 : search a node to delete with key of "k"
    Node* del_node = AvlSearchNode(root_, k);

    // 2 : tree is empty
    if (del_node == NULL) {
        return;
    }

    // create two nodes
    // one for the parent node of the node to delete
    // two for the child node
    Node* par_node = del_node->parent;
    Node* child_node;

    // 3 - 1 : node to delete has no children
    if (del_node->left == NULL && del_node->right == NULL) {
        child_node = NULL;
    }

    // 3 - 2 : node to delete has children only on the right
    else if (del_node->left == NULL && del_node->right != NULL) {
        child_node = del_node->right;
    }

    // 3 - 3 : node to delete has children only on the left
    else if (del_node->left != NULL && del_node->right == NULL) {
        child_node = del_node->left;
    }

    // 3 - 4 : node to delete has children on both sides
    else {
        child_node = del_node->right;

        // search for 'successor'
        while (child_node->left != NULL) {
            child_node = child_node->left;
        }

        // move the successor to the position of node to delete
        // move the successor's child node to the position of successor
        del_node->key = child_node->key;
        del_node = child_node;
        par_node = del_node->parent;
        child_node = del_node->right;
    }

    // 4 - 1 : node to delete has no parent
    if (par_node == NULL) {
        root_ = child_node;
        root_->parent = NULL;
    }

    // 4 - 2 : node to delete is left child of parent
    else if (del_node == par_node->left) {
        par_node->left = child_node;

        if (child_node != NULL) {
            child_node->parent = par_node;
        }
    }

    // 4 - 3 : node to delete is right child of parent
    else {
        par_node->right = child_node;

        if (child_node != NULL) {
            child_node->parent = par_node;
        }
    }

    // 5 : delete the node
    delete del_node;

    // 6 : rebalance the tree
    //AvlRebalance();
}

int AvlTree::AvlHeight(Node* node) {
    // 1 : node is empty
    if (node == NULL) {
        return -1;
    }
    // 2 : height of a node
    else {
        return node->height;
    }
}

int AvlTree::AvlDepth(Node* node, int k, int d) {
    // 1 : node is empty
    if (node == NULL) {
        return 0;
    }

    // 2 - 1 : key of current node is equal to target key
    if (node->key == k) {
        return d;
    }

    // 2 - 2 : key of current node is less than target key
    else if (node->key < k) {
        return AvlDepth(node->right, k, d + 1);
    }

    // 2 - 3 : key of current node is greater than target key
    else {
        return AvlDepth(node->left, k, d + 1);
    }
}

int AvlTree::AvlBalanceFactor(Node* node) {
    // 1 : Get height of each subtrees
    int left_subtree_height = AvlHeight(node->left);
    int right_subtree_height = AvlHeight(node->right);

    // 2 : Returns the height difference between both subtrees
    return left_subtree_height - right_subtree_height;
}

void AvlTree::AvlRebalance(Node* &node, int k) {
    // 1 - 1 : get balance factor (bf)
    int balance_factor = AvlBalanceFactor(node);

    // check root is balance
    bool root_unbalance = false;

    // 2 : z's left subtree is taller than right subtree
    if (balance_factor > 1) {

        // root is unbalance
        if (node == root_) {
            root_unbalance = true;
        }

        // 2 - 1 : y's left subtree is taller than right one
        // LL rotation
        if (node->left->key > k) {
            // 2 - 1 - 1: do right rotation
            node = RightRotation(node);
        }

        // 2 - 2 : y's right subtree is taller than left one
        // LR rotation
        else if (node->left->key < k) {
            // 2 - 2 - 1 : do left rotation for y, do right rotation for z
            node->left = LeftRotation(node->left);
            node = RightRotation(node);
        }

        // 2 - 3 : Error handling (error code : 1)
        else {
        }

        //change root if root is unbalance
        if (root_unbalance) {
            root_ = node;
        }
    }

    // 3 : z's right subtree is taller than left subtree
    else if (balance_factor < -1) {

        // root is unbalance
        if (node == root_) {
            root_unbalance = true;
        }

        // 3 - 1 : y's right subtree is taller than left subtree
        // RR rotation
        if (node->right->key < k) {
            node = LeftRotation(node);
        }

        // 3 - 2 : y's left subtree is taller than right subtree
        // RL rotation
        else if (node->right->key > k) {
            // 3 - 2 - 1 : do right rotation for y, do left rotation for z
            node->right = RightRotation(node->right);
            node = LeftRotation(node);
        }

        // 3 - 3 : Error handling (error code : 1)
        else {
        }

        //change root if root is unbalance
        if (root_unbalance) {
            root_ = node;
        }
    }
    // 4 : Tree is balanced
    else {
    }
}

Node* AvlTree::RightRotation(Node* node) {
    // 1 : Do right rotation
    Node* new_node = node->left;
    node->left = new_node->right;
    new_node->right = node;

    // 2 : change node and new_node height
    node->height = max(AvlHeight(node->left), AvlHeight(node->right)) + 1;
    new_node->height = max(AvlHeight(new_node->left), AvlHeight(new_node->right)) + 1;

    // 3 : Commit changed node
    return new_node;
}

Node* AvlTree::LeftRotation(Node* node) {
    // 1 : Do left rotation
    Node* new_node = node->right;
    node->right = new_node->left;
    new_node->left = node;

    // 2 : change node and new_node height
    node->height = max(AvlHeight(node->left), AvlHeight(node->right)) + 1;
    new_node->height = max(AvlHeight(new_node->left), AvlHeight(new_node->right)) + 1;


    // 3 : Commit changed node
    return new_node;
}
