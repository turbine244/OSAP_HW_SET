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
 * FileName	: AvlTree.h
 * Content	: struct 1 | class 1
 * Test info : Not-yet
 *
 * !Remark!
 * AVL Tree implementation as a C++ class.
 * All comments are made with consideration
 * that the reader has prior knowledge of "AVL Tree"
 * The code follows the style guide - CSE3210.
 *
 * struct 1 - Node
 *   !Members(3)
 *     int key
 *     Node* left
 *     Node* right
 *
 * class 1 - AvlTree
 *   !Members(1)
 *     Node* root_
 *
 *   !Methods(4 public | 2 private)
 *     public
 *       Node *root()
 *         ~ Getter of the member "root_".
 *
 *       void AvlInsertNode(int k)
 *         ~ Inset a node with key of "k".
 *         ~ "root_" may be changed.
 *
 *       void AvlDeleteNode(int k)
 *         ~ Delete a node with key of "k".
 *         ~ "root_" may be changed.
 *
 *       int AvlDepth(int k)
 *         ~ Return depth of the node with key of "k".
 *
 *     + Constructor(1)
 *       AvlTree()
 *         ~ Create an empty "AVL Tree".
 *
 *     private
 *       int AvlBalanceFactor()
 *         ~ Return the "Balance Factor".
 *
 *       void AvlRotate()
 *         ~ Do 4 different rotation, depending on the "Balance Factor"
 */

struct Node {
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

class AvlTree {
public:
  AvlTree() : root_(nullptr) {}

  Node *root() {
    return root_;
  }
  
  void AvlSearchNode(Node* curnode, int k) {
    if (curnode == NULL) {
      return NULL;
    }
    
    if (curnode->key == k) {
      return curnode;
    }
    else if (curnode->key < k) {
      return AvlSearchNode(curnode->right, k);
    }
    else {
      return AvlSearchNode(curnode->left, k);
    }
  }

  void AvlInsertNode(int k) {
    Node* newnode = new node(k);

    if(root_ == NULL) {
      root_ = newnode;
      return;
    }
    
    Node* curnode = root_;
    Node* parnode = NULL;

    while (curnode != NULL) {
      parnode = curnode;

      if (curnode->key < k) {
        curnode = curnode->right;
      }
      else {
        curnode = curnode->left;
      }
    }

    newnode->parent = parnode;

    if (parnode->key < k) {
      parnode->right = newnode;
    }
    else {
      parnode->left = newnode;
    }

    AvlRotate();
  }

  void AvlDeleteNode(int k) {
    Node* delnode = AvlSearchNode(root_, k);
    
    if (delnode == null) {
      return;
    }

    Node* parnode = delnode->parent;
    Node* childnode;

    if (delnode->left == NULL && delnode->right == NULL) {
      childnode = NULL;
    }
    else if (delnode->left == NULL && delnode->right != NULL) {
      childnode = delnode->right;
    }
    else if (delnode->left != NULL && delnode->right == NULL) {
      childnode = delnode->left;
    }
    else {
      childnode = delnode->right;

      while (childnode->left != NULL) {
        childnode = chlidenode->left;
      }

      delnode->key = childnode->key;
      delnode = childnode;
      parnode = delnode->parent;
      childnode = delnode->right;
    }

    if (parnode == NULL) {
      root_ = childnode;
      root->parent = NULL;
    }
    else if (delnode == parnode->left) {
      parnode->left = childnode;

      if (childnode != NULL) {
        childnode->parent = parnode;
      }
    }
    else {
      parnode->right = childnode;

      if (childnode != NULL) {
        childnode->parent = parnode;
      }
    }

    delete delnode;

    AvlRotate();
  }

  int AvlDepth(Node* curnode, int k, int d) {
    if (curnode == NULL) {
      return -1;
    }

    if (curnode->key == k) {
      return d;
    }
    else if (curnode->key < k) {
      return AvlDepth(curnode->right, k, d + 1);
    }
    else {
      return AvlDepth(curnode->left, k, d + 1);
    }
  }

private:
  int AvlBalanceFactor();
  void AvlRotate();

  Node *root_;
}