//
// 	diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include <iostream>
#include "diatonic.h"

using namespace scale_;
using namespace chord_;
using namespace tone_;

int main(int argc, const char * argv[]) {

  // create scales
  auto DSharpMajor = scale(Ds,scale_::major);
  auto DSharpPentaMajorOctave4 = scale("ds4",scale_::pentatonicmajor);
  
  // create chords
  auto Bminor7 = chord(B,m7);
  
  // 2nd chord inversion
  auto Bminor7_2nd = invert(Bminor7,2);

  // create all tonality chords (4 notes each chord)
  toneT CMajorChords = tone(C,tone_::major);
  
  // transpose tonality chords to the 3rd octave
  toneT CMajorChords3 = transpose(CMajorChords,3);

  // get a tonality's Dominant chord
  chordT GMajor7minorChord = CMajorChords3.at(dominant);

  // Write a melodic phrase where "x" (midi 127) is consired silence
  phraseT aMelody = phrasing({"c1","c2","x","c3"});

  return 0;
}
