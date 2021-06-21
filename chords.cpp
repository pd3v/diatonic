//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include "chords.h"
#include <algorithm>

chordT chord_::chord(keyT k,chordT c) {
  transform(c.begin(),c.end(),c.begin(),[&](intervalT i){return static_cast<intervalT>(i+k);});
  
  return c;
}

midiT chord_::chord(std::string k,chordT c) {
  auto keyAndOct = strToKeyAndOct(k);
  chordT _chord = chord_::chord(static_cast<keyT>(noteIdx.at(keyAndOct.first)),c);

  return chord_::transpose(_chord,keyAndOct.second);
}

chordT chord_::chordOct0(chordT c) {
  transform(c.begin(),c.end(),c.begin(),[&](intervalT i){return static_cast<intervalT>(i%OCTAVE);});
  std::sort(c.begin(),c.end(),[&](uint8_t n1,uint8_t n2){return n1 < n2;});
  
  return c;
}

chordT chord_::invert(chordT c,uint8_t p) {
  if (p <= 0 || p > c.size()) return c;
  
  p -= 1;
  
  std::rotate(c.begin(),c.begin()+p,c.end());
  std::transform(c.end()-p,c.end(),c.end()-p,[](intervalT i){return static_cast<intervalT>(i+OCTAVE);});
  
  return c;
}

midiT chord_::transpose(chordT c,uint8_t o) {
  chordT _c = chordOct0(c);
  transform(_c.begin(),_c.end(),_c.begin(),[&](intervalT i){return static_cast<intervalT>(OCTAVE*o+i);});
  
  return _c;
}

std::vector<int> chord_::chordAsInt(chordT c) {
  static std::vector<int> cAsInt;
  
  cAsInt.clear();
  for_each(c.begin(),c.end(),[&](intervalT n){cAsInt.push_back(static_cast<int>(n));});  

  return cAsInt;
}
