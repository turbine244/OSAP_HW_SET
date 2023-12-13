#include "library_code.h"
#include <vector>
#include <cstdlib>

int GenerateInteger(int range) {
       return rand() % range;
}

std::vector<int> GenerateIntVectors(int n, int range) {
	std::vector<int> result;
	while(n--)
		result.push_back(rand() % range);

	return result;
}

// Preorder traversal 함수
std::vector<int> PreorderTraverse(Node<int>* node) {
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


//Inorder traverse 함수	
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


//Postorder traverse 함수
std::vector<int> PostorderTraverse(Node<int>* node) {
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

