//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#pragma once

#include "intervals.h"
#include <vector>
#include <string>

// silent note
const int x = 127;

typedef std::vector<intervalT> scaleT;

namespace scale {
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
}

scaleT sTranspOct(scaleT s,int oct);
scaleT sclKey(keyT k,scaleT s);
scaleT sclKey(std::string k,scaleT c);
//scaleT relminor(scaleT s);
//scaleT relmajor(scaleT s);
