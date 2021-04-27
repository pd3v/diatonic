//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include "scales.h"
#include "intervals.h"
#include <algorithm>
//#include <regex>

extern const uint8_t OCTAVE;
//extern const std::basic_regex<char> NOTE_N_OCT_REGEX;
//extern const std::basic_regex<char> NOTE_REGEX;
//extern const std::basic_regex<char> OCT_REGEX;
//
//const auto NOTE_N_OCT_REGEX = std::regex("[a-g]?[b|s]?[0-9]?");
//const auto NOTE_REGEX = std::regex("[a-g]?[b|s]?");
//const auto OCT_REGEX = std::regex("[^a-g][0-9]?");

/*
std::pair<std::string,uint16_t> sStrToNoteOct(std::string noteStr) {
  std::smatch noteMatch, octMatch;
  std::string _note, _oct = "0";
  
  if (std::regex_match(noteStr,NOTE_N_OCT_REGEX)) {
    std::regex_search(noteStr,noteMatch,NOTE_REGEX);
    _note = noteStr.substr(noteMatch.position(),noteMatch.length());
    
    std::regex_search(noteStr,octMatch,OCT_REGEX);
    _oct = noteStr.substr(octMatch.position(),octMatch.length());
    
    //    if (_oct.empty()) _oct = "0";
    
    return std::make_pair(_note,std::stoi(_oct.empty() ? "0" : _oct));
  }
  
  return std::make_pair("",0);
}
*/

scaleT sTranspOct(scaleT s,int oct) {
  //  chordT _ch (ch.begin(),ch.end());
  transform(s.begin(),s.end(),s.begin(),[&](intervalT i){return static_cast<intervalT>(OCTAVE*oct+i);});
  
  return s;
}

scaleT sclKey(keyT k,const scaleT s) {
  scaleT _s = s;
  
  transform(_s.begin(),_s.end(),_s.begin(),[&](intervalT i){return static_cast<intervalT>(i+k);});
  
  return _s;
}

//scaleT sclKey(std::string k,scaleT s) {
//  auto sclOct = sStrToNoteOct(k);
//  scaleT baseScl = sclKey(static_cast<keyT>(noteStrInt.at(sclOct.first)),s);
//  
//  return sTranspOct(baseScl,sclOct.second);
//}

