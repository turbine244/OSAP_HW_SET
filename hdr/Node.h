#ifndef OSAP_HDR_NODE_H_
#define OSAP_HDR_NODE_H_

template<typename TYPE_KEY>
struct Node {
  TYPE_KEY key;
  Node* parent;
  Node* left;
  Node* right;
};

#endif