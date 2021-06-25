//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#pragma once

#include <vector>
#include <string>
#include "intervals.h"

extern const intervalT OCTAVE;

using chordT = std::vector<intervalT>;
using i = intervalT;

namespace chord_ {
  const chordT M({i::t,i::maj3,i::p5});
  const chordT M7({i::t,i::maj3,i::p5,i::maj7});
  const chordT dom({i::t,i::maj3,i::p5,i::min7});
  const chordT m({i::t,i::min3,i::p5});
  const chordT m7({i::t,i::min3,i::p5,i::min7});
  const chordT sus2({i::t,i::maj2,i::p5});
  const chordT sus4({i::t,i::p4,i::p5});
  const chordT halfdim({i::t,i::min3,i::a4,i::min7});
  const chordT dim({i::t,i::min3,i::a4,i::maj6});

  chordT chord(keyT k,chordT c);
  chordT chord(std::string k,chordT c);
  chordT chordOct0(chordT c);
  chordT invert(chordT c,uint8_t p);
  midiT transpose(chordT c,intervalT i);
  midiT transpose(chordT c,uint8_t o);
  std::vector<uint8_t> chordAsInt(chordT c);
}