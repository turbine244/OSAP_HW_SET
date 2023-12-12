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
 * FileName  : Settable.h
 * Content   : class 1
 * Test info : Not-yet
 *
 * !Remark!
 * Datatypes inheriting interface-Settable.
 * Set would Implicitly, protected-inherit one among the datatypes.
 * More datatypes can be updated later on, as an extension for Set.
 * The code follows the style guide - CSE3210.
 */

#ifndef OSAP_HDR_TYPEDEF_H_
#define OSAP_HDR_TYPEDEF_H_

#include "Settable.h"
#include "Node.h"

template <typename TYPE_KEY>
class AvlTree : public Settable<TYPE_KEY> {
public:
  AvlTree() : root_(nullptr), size_(0) {};

  int Get_size() {
    return size_;
  }

  int Return_Depth(TYPE_KEY x) {
      return AvlDepth(root_, x, 0);
  }

  TYPE_KEY Return_Minimum(TYPE_KEY x) {
      //temp는 key값이 x인 node를 가르킴
      Node<TYPE_KEY>* temp = Do_Search(root_, x);
      //temp가 루트노드가 되므로 NULL이 나올때까지 왼쪽으로 이동
      while (temp->left != NULL)
      {
          temp = temp->left;
      }
      //temp의 key값을 출력해야함
      cout << temp->key << " ";
      return temp->key;
  }

  TYPE_KEY Return_Maximum(TYPE_KEY x) {
    return 0;
  }

  void Do_Insert(TYPE_KEY x) {
      //size가 1 늘어남
      size_++;
      //Avl트리에 x가 key인 노드를 삽입
      AvlInsertNode(x, root_);
  }

  void Do_Erase(TYPE_KEY x) {

  }

private:
  Node<TYPE_KEY>* root_;

  int size_;

  int Return_Height(Node<TYPE_KEY>* node) {
    return 0;
  }
  int Return_BalanceFactor(Node<TYPE_KEY>* node) {
    return 0;
  }
  Node<TYPE_KEY>* Do_Rotation_Left(Node<TYPE_KEY>* node) {

  }
  Node<TYPE_KEY>* Do_Rotation_Right(Node<TYPE_KEY>* node) {

  }

  void Do_Rebalance(Node<TYPE_KEY>*& node, TYPE_KEY k) {

  }
  Node<TYPE_KEY>* Do_Search(Node<TYPE_KEY>* node, TYPE_KEY k) {

  }
  void AvlInsertNode(TYPE_KEY k, Node<TYPE_KEY>*& node) {

  }

  int AvlDepth(Node<TYPE_KEY>* node, TYPE_KEY k, int d) {

  }

};

#endif
