//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include "chords.h"
#include <algorithm>

extern const uint8_t OCTAVE;
//extern const std::basic_regex<char> NOTE_OCT_REGEX;
//extern const std::basic_regex<char> NOTE_REGEX;
//extern const std::basic_regex<char> OCT_REGEX;

//const auto NOTE_OCT_REGEX = std::regex("[a-g]?[b|s]?[0-9]?");
//const auto NOTE_REGEX = std::regex("[a-g]?[b|s]?");
//const auto OCT_REGEX = std::regex("[^a-g][0-9]?");

/*
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
  
  throw std::runtime_error("Chord creation does not follow noteOct nomenclature");
}
*/

chordT chord(keyT k,chordT c) {
  transform(c.begin(),c.end(),c.begin(),[&](intervalT i){return static_cast<intervalT>(i+k);});
  
  return c;
}

midiT chord(std::string k,chordT c) {
  auto keyAndOct = strToKeyAndOct(k);
  chordT _chord = chord(static_cast<keyT>(noteIdx.at(keyAndOct.first)),c);
  
  return transpose(_chord,keyAndOct.second);
}

chordT invert(chordT c,uint8_t p) {
  if (p < 1 || p > c.size()-1) return c;
  
  std::rotate(c.begin(),c.begin()+p,c.end());
  std::transform(c.end()-p,c.end(),c.end()-p,[](intervalT i){return static_cast<intervalT>(i+OCTAVE);});
  
  return c;
}

midiT transpose(chordT c,uint8_t o) {
  transform(c.begin(),c.end(),c.begin(),[&](intervalT i){return static_cast<intervalT>(OCTAVE*o+i);});
  
  return c;
}
