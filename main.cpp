//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include "mnotation.h"
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void print(std::vector<T> v) {
  for (auto& _v : v)
    cout << _v << " ";
  
  cout << endl;
}

int main(int argc, const char * argv[]) {
 
 chordT myChord = {t,min2,maj2};
 chordT CM7 = {t,maj3,p5,maj7};
  
// cout << myChord.at(1) << " " << myChord.at(2);
  
//  print(transpose(chord(C,myChord),4));
//  print(transpose(chord(C,CM7),0));
  print(transpose(chord("c5",myChord),1));
  
//  cout << transpose(myChord, 6).at(1);
//  cout << invert(transpose(myChord, 4),0).at(0);

//  auto cch = ch("c7",chord::m);
//  
//  for (auto& n : cch)
//    cout << n << " ";

//  auto cch = ch("c7",chord::M);
//
//  for (auto& n : cch)
//    cout << n << " ";
//  
//  auto sscl = scl("d4",scale::major);
//  
//  for (auto& n : sscl)
//    cout << n << " ";
//  
// auto diatch = majorsch.at(0);

// std::cout << sclKey("E",scale::major).at(0);

//  cout << strToNoteOct("d5").first << " " << strToNoteOct("d5").second;
  
//
//  cch = inv(cch,4);
//
//  for (auto& n : cch)
//    cout << n << " ";
  
//  auto ahch = transp(ch(C,myChord),5);
//  
//  for (auto& n : ahch)
//    cout << n << " ";

  
  return 0;
}
