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
 * FileName  : Set.h
 * Content   : class 1
 * Test info : Not-yet
 *
 * !Remark!
 * The file works as a productive endpoint.
 * (Including this only file makes your target-user-file work)
 * The code follows the style guide - CSE3210.
 */

#ifndef OSAP_HDR_SET_H_
#define OSAP_HDR_SET_H_

#include <iostream>
#include "Typedef.h"

template<class TYPE_SETTABLE>
class Set : protected TYPE_SETTABLE {
public:
  template<typename TYPE_KEY> void Minimum(TYPE_KEY x) {
    std::cout << Return_Depth(Return_Minimum(x));
    //std::cout << TYPE_SETTABLE::Return_Depth(TYPE_SETTABLE::Return_Minimum(x)) << "\n";
  }
  template<typename TYPE_KEY> void Maximum(TYPE_KEY x) {
    std::cout << Return_Depth(Return_Maximum(x));
  }
  void Empty() {
    std::cout << (Get_size() ? 0 : 1);
  }
  void Size() {
    std::cout << Get_size();
  }
  template<typename TYPE_KEY> void Find(TYPE_KEY x) {
    std::cout << Return_Depth(x);
  }
  template<typename TYPE_KEY> void Insert(TYPE_KEY x) {
    Do_Insert(x);
    std::cout << Return_Depth(x);
  }
  template<typename TYPE_KEY> void Rank(TYPE_KEY x) {
    std::cout << Return_Depth(x);
    Do_Rank(x);
  }
  template<typename TYPE_KEY> void Erase(TYPE_KEY x) {
    std::cout << Return_Depth(x);
    Do_Erase(x);
  }
};

#endif
