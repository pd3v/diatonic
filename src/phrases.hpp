//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#pragma once

#include "intervals.h"
#include "scales.h"

using phraseT = std::vector<int>;

phraseT phrasing(std::vector<std::string> p) {
  static phraseT _p;
  uint8_t _n;

  _p.clear();

  for_each(p.begin(),p.end(),[&](std::string n) {  
    if (n == "x") 
      _n = 127; // silent note
    else {
      std::pair<std::string,uint8_t> noteAndOct = strToKeyAndOct(n);
      _n = OCTAVE*noteAndOct.second+noteIdx.at(noteAndOct.first);
    }

    _p.emplace_back(_n);
  });

  return _p;
}
  