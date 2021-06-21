//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

// #pragma once

#include <vector>
#include <string>
#include <functional>
#include "intervals.h"
#include "scales.h"
#include "chords.h"
#include "constexprArray.hpp"

extern const intervalT OCTAVE;

using toneT = std::vector<chordT>;

enum chordDegreeT {tonic = 0,supertonic,mediant,subdominant,dominant,submediant,subtonic};

namespace tone_ {
  
  template <typename T,size_t chordSize,size_t scaleSize>
  constexpr auto toneChords(std::vector<T> s) -> ConstexprArray<ConstexprArray<T,chordSize>,scaleSize> {
    ConstexprArray<T,scaleSize> _s(s);
    ConstexprArray<ConstexprArray<T,chordSize>,scaleSize>_toneChords{};

    for (int i = 0;i < scaleSize;++i)
      for (int j = 0;j < chordSize;++j)
        _toneChords[i][j] = _s[(j*2+(i%scaleSize))%scaleSize];

    return _toneChords;
  }

  template <typename T,size_t chordSize,size_t scaleSize>
  constexpr auto toneChords(std::initializer_list<T> s) -> ConstexprArray<ConstexprArray<T,chordSize>,scaleSize> {
    ConstexprArray<T,scaleSize> _s(s);
    ConstexprArray<ConstexprArray<T,chordSize>,scaleSize>_toneChords{};

    for (int i = 0;i < scaleSize;++i)
      for (int j = 0;j < chordSize;++j)
        _toneChords[i][j] = _s[(j*2+(i%scaleSize))%scaleSize];

    return _toneChords;
  }
  
  template <typename T=intervalT,size_t chordSize=4,size_t scaleSize=7>
  toneT tone(keyT k,ConstexprArray<ConstexprArray<T,chordSize>,scaleSize> t) {
    static toneT _t; // it works, but static?! hummm...
    chordT _c;
    uint8_t currNote, prevNote;; 

    for (int i = 0; i < scaleSize; ++i) {
      for (int j = 0; j < chordSize; ++j) {
        currNote = static_cast<intervalT>(t[i][j]);
        if (currNote < prevNote) currNote += OCTAVE;
        _c.emplace_back(static_cast<intervalT>(currNote));
        prevNote = currNote;
      }
      _t.push_back(_c);

      prevNote = 0;
      _c.clear();
    }   
    
    return _t;
  }

  toneT transpose(toneT t,uint8_t o) {
    transform(t.begin(),t.end(),t.begin(),[&o](chordT c) {
      transform(c.begin(),c.end(),c.begin(),[&o](intervalT i) {
        return static_cast<intervalT>(OCTAVE*o+i);
      });
      return c;
    });

    return t;
  }

  // TODO: Add tone function with key as a key/octave string. Similiar the already existent function for chord and scale 

  auto chromatic = toneChords<intervalT,4,12>(scale_::chromatic);
  auto major = toneChords<intervalT,4,7>(scale_::major);
  auto minor = toneChords<intervalT,4,7>(scale_::minor);
  auto harmonicminor = toneChords<intervalT,4,7>(scale_::harmonicminor);
  auto whole = toneChords<intervalT,4,7>(scale_::whole);
  auto pentatonicmajor = toneChords<intervalT,4,5>(scale_::pentatonicmajor);
  auto pentatonicminor = toneChords<intervalT,4,5>(scale_::pentatonicminor);
  auto blues = toneChords<intervalT,4,6>(scale_::blues);
}
