#ifndef LIBRARY_CODE_H_
#define LIBRARY_CODE_H_

#include <vector>
#include "../../src/node.h"

// range 내의 정수 하나를 반환하는 함수
int GenerateInteger(int range);

// range 내의 정수 n개를 vector로 반환하는 함수
std::vector<int> GenerateIntVectors(int n, int range);

//Inorder traverse 함수
std::vector<int> InorderTraverse(Node<int>* node);

//Preorder traverse 함수
std::vector<int> PreorderTraverse(Node<int>* node);

//Postorder traverse 함수
std::vector<int> PostorderTraverse(Node<int>* node);

#endif // LIBRARY_CODE_H_
