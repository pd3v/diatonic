//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#pragma once

#include <vector>
#include <array>
#include <initializer_list>

template <typename T, size_t n>
struct ConstexprArray {
  constexpr ConstexprArray() : data{} {}
  
  constexpr ConstexprArray(std::initializer_list<T> l) {
    auto it = l.begin();
    for (size_t i = 0; i< l.size(); ++i) {
      data[i] = *it;
      ++it;
    }
  }
  
  constexpr ConstexprArray(std::vector<T> v) {
    auto it = v.begin();
    for (size_t i = 0; i< v.size(); ++i) {
      data[i] = *it;
      ++it;
    }
  }

  constexpr T& operator[](size_t i) {return data[i];}
  
  constexpr int size() {return n;};

  T data[n];
};
