#include "library_code.h"
#include <cstdlib>
#include <vector>

// Generate random integer (0~range)
int GenerateInteger(int range) { return rand() % range; }

// Generate random intger vectors size of n (0~range)
std::vector<int> GenerateIntVectors(int n, int range) {
  std::vector<int> result;
  while (n--)
    result.push_back(rand() % range);

  return result;
}

// Preorder traversal
std::vector<int> PreorderTraverse(Node<int> *node) {
  std::vector<int> result;

  if (node) {
    result.push_back(node->key);
    std::vector<int> leftResult = PreorderTraverse(node->left);
    result.insert(result.end(), leftResult.begin(), leftResult.end());
    std::vector<int> rightResult = PreorderTraverse(node->right);
    result.insert(result.end(), rightResult.begin(), rightResult.end());
  }

  return result;
}

// Inorder traverse
std::vector<int> InorderTraverse(Node<int> *node) {
  std::vector<int> result;

  if (node) {
    result = InorderTraverse(node->left);
    result.push_back(node->key);
    std::vector<int> rightResult = InorderTraverse(node->right);
    result.insert(result.end(), rightResult.begin(), rightResult.end());
  }

  return result;
}

// Postorder traverse
std::vector<int> PostorderTraverse(Node<int> *node) {
  std::vector<int> result;
  if (node) {
    std::vector<int> leftResult = PostorderTraverse(node->left);
    result.insert(result.end(), leftResult.begin(), leftResult.end());
    std::vector<int> rightResult = PostorderTraverse(node->right);
    result.insert(result.end(), rightResult.begin(), rightResult.end());
    result.push_back(node->key);
  }

  return result;
}
