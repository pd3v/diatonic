//
// 	diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include <iostream>
#include "scales.h"
//#include "chords.h"
#include "tonal.h"

using namespace scale_;
using namespace chord_;
using namespace tone_;

int main(int argc, const char * argv[]) {
  
  // create scales
//  auto DSharpMajor = scale(Ds,scale_::major);
  auto DSharpPentaMajorOctave4 = scale("Cs5",scale_::pentatonicmajor);
  
  // create chords
//  auto Bminor7 = chord(B,m7);
  
  // 2nd inversion
//  auto Bminor7_2nd = invert(Bminor7,2);
  
  // C major chords
//  toneT CMajorChords = tone(Cs,tone_::major);
//
//  for (auto& c : CMajorChords) {
//    for (auto n : c)
//      std::cout << n << " ";
//    
//    std::cout << std::endl;
//  }
  
  
//  auto ah = chord_::transpose(tone_::major.at(t),0);
  toneT t = tone_::tone(C,tone_::major);
//
  for (auto& c : t) {
    for (auto& n : c)
      std::cout << n << " ";
    std::cout << std::endl;
  }
  
  //{intervalT::t,min2,maj2,min2,maj3,p4,d5,p5,maj6,min7};
  //intervalT ah[10] = scale_::major;
  
//  std::cout << tone_::tone(ah)[0];
  std::cout << tone_::myTone[0];
  return 0;
}
