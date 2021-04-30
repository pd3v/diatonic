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
```

## Build

**In *diatonic*'s root directory**

	mkdir build && cmake -S . -B build/

**and then**

	cd build/ && make