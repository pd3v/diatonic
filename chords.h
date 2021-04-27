//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#pragma once

#include "intervals.h"
#include <vector>
#include <string>

using chordT = std::vector<intervalT>;
using i = intervalT;

const chordT M({i::t,i::maj3,i::p5});
const chordT M7({i::t,i::maj3,i::p5,i::maj7});
const chordT dom({i::t,i::maj3,i::p5,i::min7});
const chordT m({i::t,i::min3,i::p5});
const chordT m7({i::t,i::min3,i::p5,i::min7});
const chordT sus2({i::t,i::maj2,i::p5});
const chordT sus4({i::t,i::p4,i::p5});
const chordT halfdim({i::t,i::min3,i::a4,i::min7});
const chordT dim({i::t,i::min3,i::a4,i::maj6});

//std::pair<std::string,uint8_t> strToKeyAndOct(std::string keyAndOct);

chordT chord(keyT k,chordT c);
chordT chord(std::string k,chordT c);
chordT invert(chordT c,uint8_t p);
midiT transpose(chordT c,uint8_t o);


