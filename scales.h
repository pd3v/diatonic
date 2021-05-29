//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#pragma once

#include <vector>
#include "intervals.h"

extern const intervalT OCTAVE;

using scaleT = std::vector<intervalT>;

using i = intervalT;

namespace scale_ {
  //scales by intervals
  const scaleT chromatic{t,min2,maj2,min3,maj3,p4,a4,p5,min6,maj6,min7,maj7};
  const scaleT major({t,maj2,maj3,p4,p5,maj6,maj7});
  const scaleT minor({t,maj2,min3,p4,p5,min6,min7});
  const scaleT harmonicminor({t,maj2,min3,p4,p5,maj6,maj7});
  const scaleT whole({t,maj2,maj3,p4,p5,maj6,maj7});
  const scaleT pentatonicmajor({t,maj2,maj3,p5,maj6});
  const scaleT pentatonicminor({t,min3,p4,p5,min7});
  const scaleT blues({t,maj3,p4,a4,p5,maj6});
  
  // Major scale modes
  const scaleT ionian = major;
  const scaleT dorian({t,maj2,min3,p4,p5,maj6,min7});
  const scaleT phrygian({t,min2,min3,p4,p5,min6,min7});
  const scaleT lydian({t,maj2,maj3,a4,p5,maj6,maj7});
  const scaleT mixolydian({t,maj2,maj3,p4,p5,maj6,min7});
  const scaleT aeolian = minor;
  const scaleT locrian({t,min2,min3,p4,d5,min6,min7});

  scaleT scale(keyT k,scaleT s);
  scaleT scale(std::string k,scaleT s);
  midiT transpose(scaleT s,uint8_t o);
}
