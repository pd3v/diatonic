# diatonic
A library with diatonic transforms for music making.

## Some examples

 ```
  // create scales
  auto DSharpMajor = scale(Ds,scale_::major);
  auto DSharpPentaMajorOctave4 = scale("ds4",scale_::pentatonicmajor);
  
  // create chords
  auto Bminor7 = chord(B,m7);

  // create custom chords 
  auto myChord = {intervalT::t,intervalT::min2,intevalT::d5}; 
  // or shorter version
  auto myChord2 = {i::t,i::min2,i::d5}; 
  
  // 2nd chord inversion
  auto Bminor7_2nd = invert(Bminor7,2);

  // create all tonality chords (4 notes each chord)
  toneT CMajorChords = tone(C,tone_::major);
  
  // transpose tonality chords to the 3rd octave
  toneT CMajorChords3 = transpose(CMajorChords,3);

  // get a tonality's Dominant chord
  chordT GMajor7minorChord = CMajorChords3.at(dominant);

  // Write a melodic phrase where "x" (midi 127) is consired silence. Returns a vector of midi notes
  phraseT aMelody = phrasing({"c1","c2","x","c3"});

```

## Build

**In *diatonic*'s root directory**

	mkdir build && cmake -S . -B build/

**and then**

	cd build/ && make