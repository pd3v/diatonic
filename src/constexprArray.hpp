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
    auto i = 0;
    for (auto it = l.cbegin(); it != l.cend(); ++it)
      data[i++] = *it;
  }
  
  constexpr ConstexprArray(std::vector<T> v) {
    auto i = 0;
    for (auto it = v.cbegin(); it != v.cend(); ++it)
      data[i++] = *it;
  }

  constexpr T& operator[](size_t i) {return data[i];}
  
  constexpr int size() {return n;};

  T data[n];
};
