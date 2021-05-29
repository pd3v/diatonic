# diatonic
A library with diatonic transforms for music making.

## Some examples

 ```
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
```

## Build

**In *diatonic*'s root directory**

	mkdir build && cmake -S . -B build/

**and then**

	cd build/ && make