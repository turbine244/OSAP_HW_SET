#ifndef LIBRARY_CODE_H_
#define LIBRARY_CODE_H_

#include <vector>
#include "../../src/node.h"

// Generate random integer (0~range)
int GenerateInteger(int range);

// Generate random intger vectors size of n (0~range)
std::vector<int> GenerateIntVectors(int n, int range);

//Inorder traverse
std::vector<int> InorderTraverse(Node<int>* node);

//Preorder traverse
std::vector<int> PreorderTraverse(Node<int>* node);

//Postorder traverse
std::vector<int> PostorderTraverse(Node<int>* node);

#endif // LIBRARY_CODE_H_
