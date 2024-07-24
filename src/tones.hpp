//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//


#include <vector>
#include <string>
#include <functional>
#include "intervals.h"
#include "scales.h"
#include "chords.h"
#include "constexprArray.hpp"

extern const intervalT OCTAVE;

using toneT = std::vector<chordT>;
using chordGlyphT = std::vector<std::string>;
using toneGlyphT = std::vector<chordGlyphT>;

enum chordDegreeT {tonic = 0,supertonic,mediant,subdominant,dominant,submediant,subtonic};
std::vector<std::string> idxChordDegree{"tonic","supertonic","mediant","subdominant","dominant","submediant","subtonic"};
std::vector<std::string> idxChordPos{"T","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII"};

namespace tone_ {
  
  template <typename T=intervalT,size_t chordSize=4,size_t scaleSize=7>
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
  toneT tone(const keyT& k,ConstexprArray<ConstexprArray<T,chordSize>,scaleSize>& t) {
    toneT _t;
    chordT _c;
    uint8_t currNote, prevNote;

    for (int i = 0; i < scaleSize; ++i) {
      for (int j = 0; j < chordSize; ++j) {
        currNote = static_cast<intervalT>(t[i][j]);
        if (currNote < prevNote) currNote += OCTAVE;
        _c.emplace_back(static_cast<intervalT>(currNote+k));
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

  template <typename T=intervalT,size_t chordSize=4,size_t scaleSize=7>
  toneT tone(const std::string& k,ConstexprArray<ConstexprArray<T,chordSize>,scaleSize>& t) {
    std::pair<std::string,uint8_t> keyAndOct = strToKeyAndOct(k);
    toneT _t = tone(static_cast<keyT>(noteIdx.at(keyAndOct.first)),t);
    _t = transpose(_t,keyAndOct.second);

    return _t;
  }

  toneGlyphT toGlyphs(toneT t) {
    toneGlyphT vToneChords;
    chordGlyphT vChordGlyph;
    auto in = idxNote;

    for (auto& chord : t) {
      for (auto& intrv : chord) {
        auto iterator = std::find_if(in.begin(), in.end(), [&](auto& _in){return _in.first == (intrv % 12);});
        vChordGlyph.emplace_back((*iterator).second);
      }
      vToneChords.emplace_back(vChordGlyph);
      vChordGlyph.clear();
    }
    
    return vToneChords;
  }
  
  auto chromatic = toneChords<intervalT,4,12>(scale_::chromatic);
  auto major = toneChords(scale_::major);
  auto minor = toneChords(scale_::minor);
  auto harmonicminor = toneChords(scale_::harmonicminor);
  auto whole = toneChords<intervalT,4,6>(scale_::whole);
  auto pentatonicmajor = toneChords<intervalT,4,5>(scale_::pentatonicmajor);
  auto pentatonicminor = toneChords<intervalT,4,5>(scale_::pentatonicminor);
  auto blues = toneChords<intervalT,4,6>(scale_::blues);
  
  // Major scale modes
  auto ionian = major;
  auto dorian = toneChords(scale_::dorian);
  auto phrygian = toneChords(scale_::phrygian);
  auto lydian = toneChords(scale_::lydian);
  auto mixolydian = toneChords(scale_::mixolydian);
  auto aeolian = minor;
  auto locrian = toneChords(scale_::locrian);
}
