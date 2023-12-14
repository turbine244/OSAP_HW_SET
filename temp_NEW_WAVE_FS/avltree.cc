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
 * Test info : 0/9 public
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

template <typename TYPE_KEY>
class AvlTree : public Settable <TYPE_KEY> {
public:
  //==== ctor
  AvlTree() : root_(NULL), size_(0) {};

  //==== getter
  Node<TYPE_KEY>* Get_Root() {
    return root_;
  }

  int Get_size() {
    return size_;
  }

  //==== virtual
  int Return_Depth(TYPE_KEY x) {
  }

  TYPE_KEY Return_Minimum(TYPE_KEY x) {
  }

  TYPE_KEY Return_Maximum(TYPE_KEY x) {
  }

  int Return_Rank(TYPE_KEY x) {
  }

  void Do_Insert(TYPE_KEY x) {
  }

  void Do_Erase(TYPE_KEY x) {
  }

private:
  //==== member
  Node<TYPE_KEY>* root_;
  int size_;

  //==== method
  void Avl_Insert(TYPE_KEY k, Node<TYPE_KEY>*& node) {
  }

  void Avl_Erase(TYPE_KEY k, Node<TYPE_KEY>*& node) {
  }

  void Avl_Successor(TYPE_KEY k, Node<TYPE_KEY>*& node) {
  }

  void Avl_Rebalance(Node<TYPE_KEY>*& node) {
  }

  int Avl_BalanceFactor(Node<TYPE_KEY>* node) {
    
  }

  Node<TYPE_KEY>* Avl_Rotate(Node<TYPE_KEY>* node, bool isLeft) {
  }

  int Avl_SubtreeSize(Node<TYPE_KEY>* node, bool isLeft) {
  }

  int Avl_Height(Node<TYPE_KEY>* node) {
  }

  int Avl_Depth(Node<TYPE_KEY>* node, TYPE_KEY k, int d) {
  }

  Node<TYPE_KEY>* Avl_Search(Node<TYPE_KEY>* node, TYPE_KEY k) {
  }

  int Avl_Rank(Node<TYPE_KEY>* node, TYPE_KEY k) {
  }

  void Avl_UpdateNode(Node<TYPE_KEY>*& node) {
  }
};

#endif