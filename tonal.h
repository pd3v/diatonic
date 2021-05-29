//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#pragma once

#include <vector>
#include <string>
#include "intervals.h"
#include "scales.h"
#include "chords.h"

extern const uint8_t OCTAVE;

using toneT = std::vector<chordT>;

using namespace scale_;
using namespace chord_;

namespace tone_ {
  const toneT major{M7,m7,m7,M7,dom,m7,halfdim};
  
  toneT tone();
  toneT tone(keyT k,toneT t);
  constexpr intervalT* toneGen(intervalT a[]) {
//    for (int i = 0;i < 10;++i)
//      a[i] = static_cast<intervalT>(i);
//    
    return a;
  };
  
  template <typename T>
  scaleT tonifyScale<T>(T s);
  
//  intervalT myScale[2] {intervalT::t,intervalT::min2};
//  intervalT* myTone;// = toneGen(myScale);
}
