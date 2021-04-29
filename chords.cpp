//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include "chords.h"
#include <algorithm>

chordT chord(keyT k,chordT c) {
  transform(c.begin(),c.end(),c.begin(),[&](intervalT i){return static_cast<intervalT>(i+k);});
  
  return c;
}

midiT chord(std::string k,chordT c) {
  auto keyAndOct = strToKeyAndOct(k);
  chordT _chord = chord(static_cast<keyT>(noteIdx.at(keyAndOct.first)),c);
  
  chordT ah;
//  return transpose<chordT>(_chord,keyAndOct.second);
  return ah;
}

chordT chordBase(keyT k,chordT c) {
  transform(c.begin(),c.end(),c.begin(),[&](intervalT i){return static_cast<intervalT>((i+k)%OCTAVE);});
  std::sort(c.begin(),c.end(),[&](uint8_t n1,uint8_t n2){return n1 < n2;});
  
  return c;
}

chordT invert(chordT c,uint8_t p) {
  if (p < 1 || p > c.size()-1) return c;
  
  std::rotate(c.begin(),c.begin()+p,c.end());
  std::transform(c.end()-p,c.end(),c.end()-p,[](intervalT i){return static_cast<intervalT>(i+OCTAVE);});
  
  return c;
}

//midiT transpose(chordT c,uint8_t o) {
//  transform(c.begin(),c.end(),c.begin(),[&](intervalT i){return static_cast<intervalT>(OCTAVE*o+i);});
//  
//  return c;
//}
