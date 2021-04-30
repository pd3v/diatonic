//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include <iostream>
#include "scales.h"
#include "chords.h"

using namespace scale_;
using namespace chord_;

int main(int argc, const char * argv[]) {
  
  // create scales
  auto DSharpMajor = scale(Ds,scale_::major);
  auto DSharpPentaMajorOctave4 = scale("ds4",scale_::pentatonicmajor);
  
  // create chords
  auto Bminor7 = chord(B,m7);
  
  // 2nd inversion
  auto Bminor7_2nd = invert(Bminor7,2);
  
  return 0;
}
