//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include "tonal.h"
#include <algorithm>

toneT tone_::tone() {
  return static_cast<toneT>(tone_::major);
}

toneT tone_::tone(keyT k,toneT t) {
  scaleT s = scale_::major;
//  std::iterator<scaleT, <#class _Tp#>>
  auto idx = 0;
  int gtd;
  
  transform(t.begin(),t.end(),t.begin(),[&](chordT c) {
//    std::cout << s.at(idx++) << " ";
    gtd = s.at(idx);
    
    transform(c.begin(),c.end(),c.begin(),[&](intervalT i) {
      return static_cast<intervalT>(i+k+gtd);
    });
    
    ++idx;
    
    return c;
  });
  
  return t;
}

//tone_::myTone<intervalT> = tone_::toneGen(tone_::myScale);

//template <typename T>
scaleT tone_::tonifyScale<scale_::major>(T s) {
  return {intervalT::t};
}
