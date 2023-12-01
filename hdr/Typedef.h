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
    return 0;
  }
  TYPE_KEY Return_Minimum(TYPE_KEY x) {
    return 0;
  }
  TYPE_KEY Return_Maximum(TYPE_KEY x) {
    return 0;
  }
  void Do_Insert(TYPE_KEY x) {

  }
  void Do_Erase(TYPE_KEY x) {

  }

private:
  Node<TYPE_KEY>* root_;
  int size_;

  int Return_Height(Node<TYPE_KEY> node) {
    return 0;
  }
  int Return_BalanceFactor(Node<TYPE_KEY>* node) {
    return 0;
  }
  void Do_Rotation_Left(Node<TYPE_KEY>* node) {

  }
  void Do_Rotation_Right(Node<TYPE_KEY>* node) {
  }
  void Do_Rebalance(Node<TYPE_KEY>* node) {

  }
  void Do_Search(Node<TYPE_KEY>* node, TYPE_KEY k) {

  }
};

#endif