#include <iostream>
using namespace std;

template<typename TYPE_KEY>
struct Node {
	TYPE_KEY key;
	Node* parent;
	Node* left;
	Node* right;
	int leftsize;
	int rightsize;
	int height;
};

template<typename TYPE_KEY>
class Settable {
public:
	virtual int Get_size() = 0;
	virtual int Return_Depth(TYPE_KEY x) = 0;
	virtual TYPE_KEY Return_Minimum(TYPE_KEY x) = 0;
	virtual TYPE_KEY Return_Maximum(TYPE_KEY x) = 0;
	virtual void Do_Insert(TYPE_KEY x) = 0;
	virtual void Do_Erase(TYPE_KEY x) = 0;
};

template<class TYPE_SETTABLE>
class Set : protected TYPE_SETTABLE {
public:
	template<typename TYPE_KEY> void Minimum(TYPE_KEY x) {
		std::cout << TYPE_SETTABLE::Return_Depth(TYPE_SETTABLE::Return_Minimum(x)) << "\n";
	}
	template<typename TYPE_KEY> void Maximum(TYPE_KEY x) {
		std::cout << TYPE_SETTABLE::Return_Depth(TYPE_SETTABLE::Return_Maximum(x)) << "\n";
	}
	void Empty() {
		std::cout << (TYPE_SETTABLE::Get_size() ? 0 : 1) << "\n";
	}
	void Size() {
		std::cout << TYPE_SETTABLE::Get_size() << "\n";
	}
	template<typename TYPE_KEY> void Find(TYPE_KEY x) {
		std::cout << TYPE_SETTABLE::Return_Depth(x) << "\n";
	}
	template<typename TYPE_KEY> void Insert(TYPE_KEY x) {
		TYPE_SETTABLE::Do_Insert(x);
		std::cout << TYPE_SETTABLE::Return_Depth(x) << "\n";
	}
	template<typename TYPE_KEY> void Rank(TYPE_KEY x) {
		std::cout << TYPE_SETTABLE::Return_Depth(x);
		TYPE_SETTABLE::Do_Rank(x);
	}
	template<typename TYPE_KEY> void Erase(TYPE_KEY x) {
		std::cout << TYPE_SETTABLE::Return_Depth(x);
		TYPE_SETTABLE::Do_Erase(x);
	}
};

template <typename TYPE_KEY>
class AvlTree : public Settable <TYPE_KEY> {
public:
	AvlTree() : root_(nullptr), size_(0) {};

	int Get_size() {
		return size_;
	}

	int Return_Depth(TYPE_KEY x) {
		return AvlDepth(root_, x, 0);
	}

	TYPE_KEY Return_Minimum(TYPE_KEY x) {
		Node<TYPE_KEY>* temp = Do_Search(root_, x);
		while (temp->left != NULL)
		{
			temp = temp->left;
		}

		cout << temp->key << " ";
		return temp->key;
	}

	TYPE_KEY Return_Maximum(TYPE_KEY x) {
		Node<TYPE_KEY>* temp = Do_Search(root_, x);
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		cout << temp->key << " ";
		return temp->key;
	}

	void Do_Insert(TYPE_KEY x) {
		size_++;
		AvlInsertNode(x, root_);
	}

	void Do_Erase(TYPE_KEY x) {
		// 1 : find node of key x
		Node<TYPE_KEY>* temp = Do_Search(root_, x);

		// 2 : find a node
		if (temp != NULL)
		{
			// 3 - 1 : minus a size
			size_--;

			// 3 - 2 : delete a node
			AvlDeleteNode(x, root_);
		}
		cout << "\n";
	}

	void Do_Rank(TYPE_KEY x) {
		// 1 : find node of key x
		Node<TYPE_KEY>* temp = Do_Search(root_, x);

		// 2 : find a node
		if (temp != NULL)
		{
			// 3 - 1 : find a rank
			cout << " " << Find_Rank(root_, x);
			
		}
		cout << "\n";
	}

private:
	Node<TYPE_KEY>* root_;
	int size_;

	int Return_Leftsize(Node<TYPE_KEY>* node) {
		// 1 : node is empty
		if (node == NULL) {
			return 0;
		}
		// 2 : leftsize of a node
		else {
			return node->leftsize;
		}
	}

	int Return_Rightsize(Node<TYPE_KEY>* node) {
		// 1 : node is empty
		if (node == NULL) {
			return 0;
		}
		// 2 : rightsize of a node
		else {
			return node->rightsize;
		}
	}

	int Return_Height(Node<TYPE_KEY>* node) {
		// 1 : node is empty
		if (node == NULL) {
			return -1;
		}
		// 2 : height of a node
		else {
			return node->height;
		}
	}

	int Return_BalanceFactor(Node<TYPE_KEY>* node) {
		// 1 : Get height of each subtrees
		int left_subtree_height = Return_Height(node->left);
		int right_subtree_height = Return_Height(node->right);

		// 2 : Returns the height difference between both subtrees
		return left_subtree_height - right_subtree_height;
	}

	Node<TYPE_KEY>* Do_Rotation_Left(Node<TYPE_KEY>* node) {
		// 1 : Do left rotation
		Node<TYPE_KEY>* new_node = node->right;
		node->right = new_node->left;
		new_node->left = node;

		// 2 : change node and new_node height
		node->height = max(Return_Height(node->left), Return_Height(node->right)) + 1;
		new_node->height = max(Return_Height(new_node->left), Return_Height(new_node->right)) + 1;

		// 3 : change node leftsize and rightsize
		if (node->left != NULL)
		{
			node->leftsize = Return_Leftsize(node->left) + Return_Rightsize(node->left) + 1;
		}
		else
		{
			node->leftsize = 0;
		}

		if (node->right != NULL)
		{
			node->rightsize = Return_Leftsize(node->right) + Return_Rightsize(node->right) + 1;
		}
		else
		{
			node->rightsize = 0;
		}


		// 4 : change new_node leftsize and rightsize
		if (new_node->left != NULL)
		{
			new_node->leftsize = Return_Leftsize(new_node->left) + Return_Rightsize(new_node->left) + 1;
		}
		else
		{
			new_node->leftsize = 0;
		}

		if (new_node->right != NULL)
		{
			new_node->rightsize = Return_Leftsize(new_node->right) + Return_Rightsize(new_node->right) + 1;
		}
		else
		{
			new_node->rightsize = 0;
		}

		// 5 : Commit changed node
		return new_node;
	}

	Node<TYPE_KEY>* Do_Rotation_Right(Node<TYPE_KEY>* node) {
		// 1 : Do right rotation
		Node<TYPE_KEY>* new_node = node->left;
		node->left = new_node->right;
		new_node->right = node;

		// 2 : change node and new_node height
		node->height = max(Return_Height(node->left), Return_Height(node->right)) + 1;
		new_node->height = max(Return_Height(new_node->left), Return_Height(new_node->right)) + 1;

		// 3 : change node leftsize and rightsize
		if (node->left != NULL)
		{
			node->leftsize = Return_Leftsize(node->left) + Return_Rightsize(node->left) + 1;
		}
		else
		{
			node->leftsize = 0;
		}

		if (node->right != NULL)
		{
			node->rightsize = Return_Leftsize(node->right) + Return_Rightsize(node->right) + 1;
		}
		else
		{
			node->rightsize = 0;
		}

		// 4 : change new_node leftsize and rightsize
		if (new_node->left != NULL)
		{
			new_node->leftsize = Return_Leftsize(new_node->left) + Return_Rightsize(new_node->left) + 1;
		}
		else
		{
			new_node->leftsize = 0;
		}
		if (new_node->right != NULL)
		{
			new_node->rightsize = Return_Leftsize(new_node->right) + Return_Rightsize(new_node->right) + 1;
		}
		else
		{
			new_node->rightsize = 0;
		}

		// 5 : Commit changed node
		return new_node;
	}

	void Do_Rebalance(Node<TYPE_KEY>*& node) {
		// 1 - 1 : get balance factor (bf)
		int balance_factor = Return_BalanceFactor(node);

		// check root is balance
		bool root_unbalance = false;

		// 2 : z's left subtree is taller than right subtree
		if (balance_factor > 1) {

			// root is unbalance
			if (node == root_) {
				root_unbalance = true;
			}

			// 2 - 1 : y's left subtree is taller than right one
			// LL rotation
			if (Return_Height(node->left->left) >= Return_Height(node->left->right)) {
				// 2 - 1 - 1: do right rotation
				node = Do_Rotation_Right(node);
			}

			// 2 - 2 : y's right subtree is taller than left one
			// LR rotation
			else if (Return_Height(node->left->left) < Return_Height(node->left->right)) {
				// 2 - 2 - 1 : do left rotation for y, do right rotation for z
				node->left = Do_Rotation_Left(node->left);
				node = Do_Rotation_Right(node);
			}

			// 2 - 3 : Error handling (error code : 1)
			else {
			}

			//change root if root is unbalance
			if (root_unbalance) {
				root_ = node;
			}
		}

		// 3 : z's right subtree is taller than left subtree
		else if (balance_factor < -1) {
			// root is unbalance
			if (node == root_) {
				root_unbalance = true;
			}

			// 3 - 1 : y's right subtree is taller than left subtree
			// RR rotation
			if (Return_Height(node->right->left) <= Return_Height(node->right->right)) {
				node = Do_Rotation_Left(node);
			}

			// 3 - 2 : y's left subtree is taller than right subtree
			// RL rotation
			else if (Return_Height(node->right->left) > Return_Height(node->right->right)) {
				// 3 - 2 - 1 : do right rotation for y, do left rotation for z
				node->right = Do_Rotation_Right(node->right);
				node = Do_Rotation_Left(node);
			}

			// 3 - 3 : Error handling (error code : 1)
			else {
			}

			//change root if root is unbalance
			if (root_unbalance) {
				root_ = node;
			}
		}
		// 4 : Tree is balanced
		else {
		}
	}

	Node<TYPE_KEY>* Do_Search(Node<TYPE_KEY>* node, TYPE_KEY k) {
		// 1 : current node is empty
		if (node == NULL) {
			return NULL;
		}

		// 2 - 1 : key of current node is equal to target key
		if (node->key == k) {
			return node;
		}

		// 2 - 2 : key of current node is less than target key
		else if (node->key < k) {
			return Do_Search(node->right, k);
		}

		// 2 - 3 : key of current node is greater than target key
		else {
			return Do_Search(node->left, k);
		}
	}

	void AvlInsertNode(TYPE_KEY k, Node<TYPE_KEY>*& node) {

		// 1 : node is empty
		if (node == NULL) {
			// 1 - 1 : create a node with key of "k"
			node = new Node<TYPE_KEY>();
			node->key = k;
			node->left = NULL;
			node->right = NULL;
			node->leftsize = 0;
			node->rightsize = 0;
			// 1 - 2 : set root if root node is empty
			if (root_ == NULL) {
				root_ = node;
			}
		}
		// 2 : change current node by compare key value
		else
		{
			// 2 - 1 : key of current node is greater than target key
			if (k < node->key) {
				AvlInsertNode(k, node->left);
			}

			// 2 - 2 : key of current node is less than target key
			else if (k > node->key) {
				AvlInsertNode(k, node->right);
			}

			// 2 - 3 : key of current node is same with target key
			else {

			}
		}

		// 3 : Check the tree is balanced based on node
		Do_Rebalance(node);

		// 4 : Change node height
		int left_subtree_height = Return_Height(node->left);
		int right_subtree_height = Return_Height(node->right);
		node->height = max(left_subtree_height, right_subtree_height) + 1;

		// 5 : Change node leftsize and rightsize
		if (node->left != NULL)
		{
			node->leftsize = Return_Leftsize(node->left) + Return_Rightsize(node->left) + 1;
		}
		else
		{
			node->leftsize = 0;
		}
		if (node->right != NULL)
		{
			node->rightsize = Return_Leftsize(node->right) + Return_Rightsize(node->right) + 1;
		}
		else
		{
			node->rightsize = 0;
		}

	}

	int AvlDepth(Node<TYPE_KEY>* node, TYPE_KEY k, int d) {
		// 1 : node is empty
		if (node == NULL) {
			return 0;
		}

		// 2 - 1 : key of current node is equal to target key
		if (node->key == k) {
			return d;
		}

		// 2 - 2 : key of current node is less than target key
		else if (node->key < k) {
			return AvlDepth(node->right, k, d + 1);
		}

		// 2 - 3 : key of current node is greater than target key
		else {
			return AvlDepth(node->left, k, d + 1);
		}
	}

	void AvlDeleteNode(TYPE_KEY k, Node<TYPE_KEY>*& node) {

		// 1 - 1 : key of current node is greater than target key
		if (node->key > k) {
			AvlDeleteNode(k, node->left);
		}

		// 1 - 2 : key of current node is less than target key
		else if (node->key < k) {
			AvlDeleteNode(k, node->right);
		}

		// 1 - 3 : key of current node is equal to target key
		else if (node->key == k) {

			Node<TYPE_KEY>* temp = node;

			// 2 - 1 : node left is null
			if (node->left == NULL) {
				node = node->right;
				if (temp == root_)
				{
					root_ = node->right;
				}

				delete temp;
			}
			// 2 - 2 : node right is null
			else if (node->right == NULL) {
				node = node->left;
				if (temp == root_)
				{
					root_ = node->left;
				}

				delete temp;
			}
			// 2 - 3 : have two child
			else {
				// 3 - 1 : find successor and parentsuccessor
				Node<TYPE_KEY>* successor = node->right;
				Node<TYPE_KEY>* parentsuccessor = node;
				while (successor->left != nullptr) {
					parentsuccessor = successor;
					successor = successor->left;
				}
				// 3 - 2 : change node key to successor key
				node->key = successor->key;

				if (parentsuccessor == node) {
					node->right = successor->right;
				}
				else {
					parentsuccessor->left = successor->right;
				}
				temp = successor;

				delete temp;
				// 3 - 3 : find parentsuccessor and start balancing
				AvlSuccessor(parentsuccessor->key, node);
			}
		}

		// 4 : if node is not delete
		if (node != NULL)
		{
			// 4 - 1 : Check the tree is balanced based on node
			Do_Rebalance(node);

			// 4 - 2 : Change node height
			int left_subtree_height = Return_Height(node->left);
			int right_subtree_height = Return_Height(node->right);
			node->height = max(left_subtree_height, right_subtree_height) + 1;

			// 4 - 3 : Change node leftsize and rightsize
			if (node->left != NULL)
			{
				node->leftsize = Return_Leftsize(node->left) + Return_Rightsize(node->left) + 1;
			}
			else
			{
				node->leftsize = 0;
			}

			if (node->right != NULL)
			{
				node->rightsize = Return_Leftsize(node->right) + Return_Rightsize(node->right) + 1;
			}
			else
			{
				node->rightsize = 0;
			}
		}

	}

	void AvlSuccessor(TYPE_KEY k, Node<TYPE_KEY>*& node) {

		// 1 : node is empty
		if (node->key == k) {
			
		}
		// 2 : change current node by compare key value
		else
		{
			// 2 - 1 : key of current node is greater than target key
			if (k < node->key) {
				AvlSuccessor(k, node->left);
			}

			// 2 - 2 : key of current node is less than target key
			else if (k > node->key) {
				AvlSuccessor(k, node->right);
			}

			// 2 - 3 : key of current node is same with target key
			else {

			}
		}

		// 3 : Check the tree is balanced based on node
		Do_Rebalance(node);

		// 4 : Change node height
		int left_subtree_height = Return_Height(node->left);
		int right_subtree_height = Return_Height(node->right);
		node->height = max(left_subtree_height, right_subtree_height) + 1;

		// 5 : Change node leftsize and rightsize
		if (node->left != NULL)
		{
			node->leftsize = Return_Leftsize(node->left) + Return_Rightsize(node->left) + 1;
		}
		else
		{
			node->leftsize = 0;
		}

		if (node->right != NULL)
		{
			node->rightsize = Return_Leftsize(node->right) + Return_Rightsize(node->right) + 1;
		}
		else
		{
			node->rightsize = 0;
		}

	}

	int Find_Rank(Node<TYPE_KEY>* node, TYPE_KEY k) {
		// 1 - 1 : key of current node is equal to target key
		if (node->key == k) {
			// 2 - 1 : plus node leftsize + 1
			return node->leftsize + 1;
		}

		// 1 - 2 : key of current node is less than target key
		else if (node->key < k) {
			// 2 : plus node leftsize + 1
			return Find_Rank(node->right, k) + node->leftsize + 1;
		}

		// 1 - 3 : key of current node is greater than target key
		else {
			return Find_Rank(node->left, k);
		}
	}

};


void TestSet();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	std::cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		TestSet();
	}
}

void TestSet() {
	//Set Avltree, Q
	Set<AvlTree<int>> a;
	int Q;
	std::cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		std::string command;
		std::cin >> command;

		// Command minimum
		if (command == "minimum") {
			int x;
			std::cin >> x;
			a.Minimum(x);
		}
		// Command maximum
		else if (command == "maximum") {
			int x;
			std::cin >> x;
			a.Maximum(x);
		}
		// Command empty
		else if (command == "empty") {
			a.Empty();
		}
		// Command size
		else if (command == "size") {
			a.Size();
		}
		// Command find
		else if (command == "find") {
			int x;
			std::cin >> x;
			a.Find(x);
		}
		// Command Insert
		else if (command == "insert") {
			int x;
			std::cin >> x;
			a.Insert(x);
		}
		// Command rank
		else if (command == "rank") {
			int x;
			std::cin >> x;
			a.Rank(x);
		}
		// Command erase
		else if (command == "erase") {
			int x;
			std::cin >> x;
			a.Erase(x);
		}
	}
}