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
 * FileName  : avltree.cc
 * Content   : class 1
 * Test info : 9/9 public
 *
 * !Remark!
 * Datatypes inheriting interface-Settable.
 * Another class, "Set" would Implicitly, protected-inherit this class.
 * Expected readers - Ones who already have base knowledge
 * on the data-structure, "AVL Tree"
 * The code follows the style guide - CSE3210.
 */

#ifndef OSAP_CC_AVLTREE_H_
#define OSAP_CC_AVLTREE_H_

#include "node.h"
#include "settable.h"
#include <algorithm>

template <typename TYPE_KEY>
class AvlTree : public Settable <TYPE_KEY> {
public:
  //==== ctor
  AvlTree() : root_(nullptr), size_(0) {};

  //==== getter
  Node<TYPE_KEY>* Get_Root() {
    return root_;
  }

  int Get_size() {
    return size_;
  }

  //==== virtual
  int Return_Depth(TYPE_KEY x) {
    return Avl_Depth(root_, x, 0);
  }

  TYPE_KEY Return_Minimum(TYPE_KEY x) {
    Node<TYPE_KEY>* temp = Avl_Search(root_, x);

    if (temp == nullptr) {
      return (TYPE_KEY)0xFFFFFFFF;
    }
    else {
      while (temp->left != nullptr) {
        temp = temp->left;
      }
      return temp->key;
    }
  }

  TYPE_KEY Return_Maximum(TYPE_KEY x) {
    Node<TYPE_KEY>* temp = Avl_Search(root_, x);

    if (temp == nullptr) {
      return (TYPE_KEY)0xFFFFFFFF;
    }
    else {
      while (temp->right != nullptr) {
        temp = temp->right;
      }
      return temp->key;
    }
  }

  int Return_Rank(TYPE_KEY x) {
    Node<TYPE_KEY>* temp = Avl_Search(root_, x);

    if (temp == nullptr) {
      return -1;
    }
    else {
      return Avl_Rank(root_, x);
    }
  }

  void Do_Insert(TYPE_KEY x) {
    Avl_Insert(x, root_);
    size_++;
  }

  void Do_Erase(TYPE_KEY x) {
    Node<TYPE_KEY>* temp = Avl_Search(root_, x);

    if (temp != nullptr) {
      Avl_Erase(x, root_);
      size_--;
    }
  }

private:
  //==== member
  Node<TYPE_KEY>* root_;
  int size_;

  //==== method
  void Avl_Insert(TYPE_KEY k, Node<TYPE_KEY>*& node) {
    if (node == nullptr) {
      node = new Node<TYPE_KEY>();
      node->key = k;
      if (root_ == nullptr) {
        root_ = node;
      }
    }
    else {
      if (k < node->key) {
        Avl_Insert(k, node->left);
      }
      else if (k > node->key) {
        Avl_Insert(k, node->right);
      }
      else {
        // NON-BUISINESS
      }
    }

    Avl_Rebalance(node);
    Avl_UpdateNode(node);
  }

  void Avl_Erase(TYPE_KEY k, Node<TYPE_KEY>*& node) {
    if (node->key > k) {
      Avl_Erase(k, node->left);
    }
    else if (node->key < k) {
      Avl_Erase(k, node->right);
    }
    else if (node->key == k) {
      Node<TYPE_KEY>* temp = node;

      if (node->left == nullptr) {
        node = node->right;

        if (temp == root_) {
          root_ = node->right;
        }

        delete temp;
      }
      else if (node->right == nullptr) {
        node = node->left;

        if (temp == root_) {
          root_ = node->left;
        }

        delete temp;
      }
      else {
        Node<TYPE_KEY>* successor = node->right;
        Node<TYPE_KEY>* parentsuccessor = node;

        while (successor->left != nullptr) {
          parentsuccessor = successor;
          successor = successor->left;
        }

        node->key = successor->key;

        if (parentsuccessor == node) {
          node->right = successor->right;
        }
        else {
          parentsuccessor->left = successor->right;
        }

        temp = successor;

        delete temp;
        
        Avl_Successor(parentsuccessor->key, node);
      }
    }
    else {
      // ERROR
    }

    if (node != nullptr) {
      Avl_Rebalance(node);
      Avl_UpdateNode(node);
    }
  }

  void Avl_Successor(TYPE_KEY k, Node<TYPE_KEY>*& node) {
    if (k < node->key) {
      Avl_Successor(k, node->left);
    }
    else if (k > node->key) {
      Avl_Successor(k, node->right);
    }
    else {

    }

    Avl_Rebalance(node);
    Avl_UpdateNode(node);
  }

  void Avl_Rebalance(Node<TYPE_KEY>*& node) {
    int bf = Avl_BalanceFactor(node);
    bool is_root_unbalance = (node == root_);

    if (bf > 1) {
      if (Avl_Height(node->left->left) >= Avl_Height(node->left->right)) {
        // LL rotation
        node = Avl_Rotate(node, false);
      }
      else if (Avl_Height(node->left->left) < Avl_Height(node->left->right)) {
        // LR rotation
        node->left = Avl_Rotate(node->left, true);
        node = Avl_Rotate(node, false);
      }
      else {
        // ERROR
      }
    }
    else if (bf < -1) {
      if (Avl_Height(node->right->left) <= Avl_Height(node->right->right)) {
        // RR rotation
        node = Avl_Rotate(node, true);
      }
      else if (Avl_Height(node->right->left) > Avl_Height(node->right->right)) {
        // RL rotation
        node->right = Avl_Rotate(node->right, false);
        node = Avl_Rotate(node, true);
      }
      else {
        // ERROR
      }
    }
    else {
      // Balanced perfectly
    }

    if (is_root_unbalance) {
      root_ = node;
    }
  }

  int Avl_BalanceFactor(Node<TYPE_KEY>* node) {
    return Avl_Height(node->left) - Avl_Height(node->right);
  }

  Node<TYPE_KEY>* Avl_Rotate(Node<TYPE_KEY>* node, bool isLeft) {
    Node<TYPE_KEY>* new_node;

    if (isLeft) {
      new_node = node->right;
      node->right = new_node->left;
      new_node->left = node;
    }
    else {
      new_node = node->left;
      node->left = new_node->right;
      new_node->right = node;
    }

    Avl_UpdateNode(node);
    Avl_UpdateNode(new_node);

    return new_node;
  }

  int Avl_SubtreeSize(Node<TYPE_KEY>* node, bool isLeft) {
    if (node == nullptr) {
      return 0;
    }
    else {
      return (isLeft ? node->leftsize : node->rightsize);
    }
  }

  int Avl_Height(Node<TYPE_KEY>* node) {
    if (node == nullptr) {
      return -1;
    }
    else {
      return node->height;
    }
  }

  int Avl_Depth(Node<TYPE_KEY>* node, TYPE_KEY k, int d) {
    if (node == nullptr) {
      return 0;
    }
    else {
      if (node->key == k) {
        return d;
      }
      else if (node->key < k) {
        return Avl_Depth(node->right, k, d + 1);
      }
      else {
        return Avl_Depth(node->left, k, d + 1);
      }
    }
  }

  Node<TYPE_KEY>* Avl_Search(Node<TYPE_KEY>* node, TYPE_KEY k) {
    if (node == nullptr) {
      return nullptr;
    }
    else {
      if (node->key == k) {
        return node;
      }
      else if (node->key < k) {
        return Avl_Search(node->right, k);
      }
      else {
        return Avl_Search(node->left, k);
      }
    }
  }

  int Avl_Rank(Node<TYPE_KEY>* node, TYPE_KEY k) {
    if (node->key == k) {
      return node->leftsize + 1;
    }
    else if (node->key < k) {
      return Avl_Rank(node->right, k) + node->leftsize + 1;
    }
    else {
      return Avl_Rank(node->left, k);
    }
  }

  void Avl_UpdateNode(Node<TYPE_KEY>*& node) {
    // height
    node->height = std::max(Avl_Height(node->left), Avl_Height(node->right)) + 1;

    // leftsize
    if (node->left == nullptr) {
      node->leftsize = 0;
    }
    else {
      node->leftsize = Avl_SubtreeSize(node->left, true) + Avl_SubtreeSize(node->left, false) + 1;
    }

    // rightsize
    if (node->right == nullptr) {
      node->rightsize = 0;
    }
    else {
      node->rightsize = Avl_SubtreeSize(node->right, true) + Avl_SubtreeSize(node->right, false) + 1;
    }
  }
};

#endif