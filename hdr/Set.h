#ifndef OSAP_HDR_SET_H_
#define OSAP_HDR_SET_H_

#include <iostream>
#include "Typedef.h"

template<class TYPE_SETTABLE>
class Set : protected TYPE_SETTABLE {
public:
  template<typename TYPE_KEY> void Minimum(TYPE_KEY x) {
    std::cout << Return_Depth(Return_Minimum(x));
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