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
 * Content   : function 9
 * Test info : Not-yet
 *
 * !Remark!
 * All comments are made with consideration
 * that the reader has prior knowledge of "AVL Tree"
 * The code follows the style guide - CSE3210.
 */

#include "AvlTree.h"

AvlTree::AvlTree() {}

AvlTree::root() {}

AvlTree::AvlInsertNode(int k) {}

AvlTree::AvlDeleteNode(int k) {}

AvlTree::AvlDepth(int k) {}

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