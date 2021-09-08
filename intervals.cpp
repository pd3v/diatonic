//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include "intervals.h"
#include <algorithm>

std::pair<std::string,uint8_t> strToKeyAndOct(std::string keyAndOct) {
  std::smatch keyMatch,octMatch;
  std::string key,oct;

  // key user input to lowercase
  transform(keyAndOct.begin(),keyAndOct.end(),keyAndOct.begin(),::tolower);
  
  if (std::regex_match(keyAndOct,NOTE_OCT_REGEX)) {
    std::regex_search(keyAndOct,keyMatch,NOTE_REGEX);
    key = keyAndOct.substr(keyMatch.position(),keyMatch.length());
    
    std::regex_search(keyAndOct,octMatch,OCT_REGEX);
    oct = keyAndOct.substr(octMatch.position(),octMatch.length());
    
    return std::make_pair(key,std::stoi(oct));
  }

  throw std::runtime_error("Key and octave do not follow <keyoct> nomenclature.");
}
