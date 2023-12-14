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
 * FileName  : set.h
 * Content   : class 1
 * Test info : 8/8 public
 *
 * !Remark!
 * The file works as a productive endpoint.
 * Including this and random "Settable" class src file
 * Would make your target-user-file be in action.
 * The code follows the style guide - CSE3210.
 */

#ifndef OSAP_CC_SET_H_
#define OSAP_CC_SET_H_

#include <iostream>
#include "settable.h"

template<class TYPE_SETTABLE>
class Set : protected TYPE_SETTABLE {
public:
  template<typename TYPE_KEY> void Minimum(TYPE_KEY x) {
    std::cout
      << TYPE_SETTABLE::Return_Minimum(x) << " "
      << TYPE_SETTABLE::Return_Depth(TYPE_SETTABLE::Return_Minimum(x)) << "\n";
  }
  template<typename TYPE_KEY> void Maximum(TYPE_KEY x) {
    std::cout
      << TYPE_SETTABLE::Return_Maximum(x) << " "
      << TYPE_SETTABLE::Return_Depth(TYPE_SETTABLE::Return_Maximum(x)) << "\n";
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
    if (TYPE_SETTABLE::Return_Rank(x) != -1) {
      std::cout << " " << TYPE_SETTABLE::Return_Rank(x);
    }
    std::cout << "\n";
  }
  template<typename TYPE_KEY> void Erase(TYPE_KEY x) {
    std::cout << TYPE_SETTABLE::Return_Depth(x);
    TYPE_SETTABLE::Do_Erase(x);
    std::cout << "\n";
  }
};

#endif