//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include <stdio.h>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>
#include "intervals.h"

const std::basic_regex<char> NOTE_OCT_REGEX = std::regex("[a-g][b|s]?[0-9]");
const std::basic_regex<char> NOTE_REGEX = std::regex("[a-g][b|s]?");
const std::basic_regex<char> OCT_REGEX = std::regex("[0-9]");

namespace Helper {
const std::map<std::string,uint16_t> noteIdx{{"c",0},{"cs",1},{"d",2},{"ds",3},{"e",4},{"f",5},{"fs",6},{"g",7},{"gs",8},{"a",9},{"as",10},{"b",11}};

std::pair<std::string,uint8_t> strToKeyAndOct(std::string keyAndOct) {
  std::smatch keyMatch, octMatch;
  std::string key, oct = "0";
  
  if (std::regex_match(keyAndOct,NOTE_OCT_REGEX)) {
    std::regex_search(keyAndOct,keyMatch,NOTE_REGEX);
    key = keyAndOct.substr(keyMatch.position(),keyMatch.length());
    
    std::regex_search(keyAndOct,octMatch,OCT_REGEX);
    oct = keyAndOct.substr(octMatch.position(),octMatch.length());
    
    return std::make_pair(key,std::stoi(oct.empty() ? "0" : oct));
  }
  
  throw std::runtime_error("Does not follow noteOct nomenclature.");
}
  
template<typename T>
void print(std::vector<T> v, typename std::enable_if<std::is_scalar<T>::value,void*>::type() = nullptr) {
  for (auto& _v : v)
    std::cout << _v << " ";
  
  std::cout << std::endl;
}
  
}
