//
//  diatonic lib - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <regex>

const std::basic_regex<char> NOTE_OCT_REGEX = std::regex("[a-g][b|s]?[0-9]");
const std::basic_regex<char> NOTE_REGEX = std::regex("[a-g][b|s]?");
const std::basic_regex<char> OCT_REGEX = std::regex("[0-9]");

enum intervalT {t = 0,min2,maj2,min3,maj3,p4,a4,p5,min6,maj6,min7,maj7,oct,min9,maj9,min10,maj10,p11,a11,p12,min13,maj13,min14,maj14};
enum keyT {C = 0,Cs,D,Ds,E,F,Fs,G,Gs,A,As,B};
enum noteT {c = 0,cs,d,ds,e,f,fs,g,gs,a,as,b};

const intervalT OCTAVE = intervalT::oct;

using midiT = std::vector<intervalT>;

const intervalT d5 = a4;
const intervalT d12 = a11;

const noteT db = cs;
const noteT eb = ds;
const noteT gb = fs;
const noteT ab = gs;
const noteT bb = as;

const std::map<std::string,uint16_t> noteIdx{{"c",0},{"cs",1},{"d",2},{"ds",3},{"e",4},{"f",5},{"fs",6},{"g",7},{"gs",8},{"a",9},{"as",10},{"b",11}};
const std::vector<std::pair<uint16_t,std::string>> idxNote{{0,"c"},{1,"cs"},{2,"d"},{3,"ds"},{4,"e"},{5,"f"},{6,"fs"},{7,"g"},{8,"gs"},{9,"a"},{10,"as"},{11,"b"}};

std::pair<std::string,uint8_t> strToKeyAndOct(std::string keyAndOct);
