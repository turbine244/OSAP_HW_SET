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
 * Content   : function 10
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
  // 1 : tree is empty
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

void AvlTree::AvlInsertNode(int k) {
  // 1 : create a node with key of "k"
  Node* new_node = new node(k);

  // 2 : tree is empty
  if(root_ == NULL) {
      root_ = new_node;
      return;
  }

  // create two nodes
  // one for the new node to insert
  // two for the parent node of that node
  Node* cur_node = root_;
  Node* par_node = NULL;

  // 3 : repeat search until reaching a leaf node
  while (cur_node != NULL) {
    par_node = cur_node;

    // 3 - 1 : key of current node is less than target key
    if (cur_node->key < k) {
      cur_node = cur_node->right;
    }

    // 3 - 1 : key of current node is greater than target key
    else {
      cur_node = cur_node->left;
    }
  }

  new_node->parent = par_node;

  // 4 : insert the node

  // 4 - 1 : key of parent node is less than target key
  if (par_node->key < k) {
      par_node->right = new_node;
  }

  // 4 - 2 : key of parent node is greater than target key
  else {
      par_node->left = new_node;
  }

  // 5 : rebalance the tree
  AvlRebalance();
}

void AvlTree::AvlDeleteNode(int k) {
  // 1 : search a node to delete with key of "k"
  Node* del_node = AvlSearchNode(root_, k);
  
  // 2 : tree is empty
  if (del_node == null) {
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
      child_node = chlid_node->left;
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
    root->parent = NULL;
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
  AvlRebalance();
}

int AvlTree::AvlDepth(Node* node, int k, int d) {
  // 1 : tree is empty
  if (node == NULL) {
    return -1;
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

int AvlTree::AvlBalanceFactor(Node *node) {
  // 1 : Get height of each subtrees
  int left_subtree_height = node->left->height;
  int right_subtree_height = node->right->height;

  // 2 : Returns the height difference between both subtrees
  return left_subtree_height - right_subtree_height;
}

void AvlTree::AvlRebalance() {
  // 1 : get balance factor (bf)
  int balance_factor = AvlBalanceFactor(root_);

  // 2 : z's left subtree is taller than right subtree
  if (balance_factor > 1) {

    // 2 - 1 : y's left subtree is taller than right one
    // LL rotation
    if (root_->key < root_->left->key) {
      // 2 - 1 - 1: do right rotation
      root_ = RightRotation(root_);

      // 2 - 2 : y's right subtree is taller than left one
      // LR rotation
    } else if (root_->key > root_->left->key) {
      // 2 - 2 - 1 : do left rotation for y, do right rotation for z
      root_->left = LeftRotation(root_->left);
      root_ = RightRotation(root_);

      // 2 - 3 : Error handling (error code : 1)
    } else {
    }
  }

  // 3 : z's right subtree is taller than left subtree
  else if (balance_factor < -1) {

    // 3 - 1 : y's right subtree is taller than left subtree
    // RR rotation
    if (root_->key > root_->left->key) {
      root_ = LeftRotation(root_);

      // 3 - 2 : y's left subtree is taller than right subtree
      // RL rotation
    } else if (root_->key < root_->left->key) {
      // 3 - 2 - 1 : do right rotation for y, do left rotation for z
      root_->right = RightRotation(root_->right);
      root_ = LeftRotation(root_);

      // 3 - 3 : Error handling (error code : 1)
    } else {
      ;
    }
  }

  // 4 : Tree is balanced
  else {
  }
}

Node *AvlTree::RightRotation(Node *node) {
  // 1 : Do right rotation
  Node *new_root = node->left;
  new_root->right = node;
  node->left = new_root->right;

  // 2 : Commit changed root
  root_ = new_root;
  return new_root;
}

Node *AvlTree::LeftRotation(Node *node) {
  // 1 : Do left rotation
  Node *new_root = node->right;
  new_root->left = node;
  node->right = new_root->left;

  // 2 : Commit changed root
  root_ = new_root;
  return new_root;
}