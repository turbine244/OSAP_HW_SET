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
 * FileName  : Test_Basic.cc
 * Content   : function 1
 * Test info : Done_Online
 * Contributors : 박근원 김성준 양희령 전주원
 *
 * !Remark!
 * All comments are made with consideration
 * that the reader has prior knowledge of "AVL Tree"
 * The code follows the style guide - CSE3210.
 */

#include <iostream>
#include <string>
#include "Set.h"
using namespace std;

void TestSet();

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		TestSet();
	}
}

void TestSet() {
	//Set Avltree, Q
	Set Avltree;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		string command;
		cin >> command;

		// Command minimum
		if (command == "minimum") {
			int x;
			cin >> x;
			Avltree.Minimum(x);
		}
		// Command maximum
		else if (command == "maximum") {
			int x;
			cin >> x;
			Avltree.Maximum(x);
		}
		// Command empty
		else if (command == "empty") {
			Avltree.Empty();
		}
		// Command size
		else if (command == "size") {
			Avltree.Size();
		}
		// Command find
		else if (command == "find") {
			int x;
			cin >> x;
			Avltree.Find(x);
		}
		// Command Insert
		else if (command == "insert") {
			int x;
			cin >> x;
			Avltree.Insert(x);
		}
	}
}
