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
using il = intervalT;

namespace chord_ {
  const chordT M({il::t,il::maj3,il::p5});
  const chordT M7({il::t,il::maj3,il::p5,il::maj7});
  const chordT dom({il::t,il::maj3,il::p5,il::min7});
  const chordT m({il::t,il::min3,il::p5});
  const chordT m7({il::t,il::min3,il::p5,il::min7});
  const chordT sus2({il::t,il::maj2,il::p5});
  const chordT sus4({il::t,il::p4,il::p5});
  const chordT halfdim({il::t,il::min3,il::a4,il::min7});
  const chordT dim({il::t,il::min3,il::a4,il::maj6});

  chordT chord(keyT k,chordT c);
  chordT chord(std::string k,chordT c);
  chordT chordOct0(chordT c);
  int octave(chordT c);
  chordT invert(chordT c,uint8_t p);
  midiT transpose(chordT c,intervalT il);
  midiT transpose(chordT c,uint8_t o);
  std::vector<int> chordAsInt(chordT c);
}
