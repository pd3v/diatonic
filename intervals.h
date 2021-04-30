//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#pragma once

#include <map>
#include <regex>

const uint8_t OCTAVE = 12;
const std::basic_regex<char> NOTE_OCT_REGEX = std::regex("[a-g][b|s]?[0-9]");
const std::basic_regex<char> NOTE_REGEX = std::regex("[a-g][b|s]?");
const std::basic_regex<char> OCT_REGEX = std::regex("[0-9]");

enum intervalT {t = 0,min2,maj2,min3,maj3,p4,a4,p5,min6,maj6,min7,maj7,O,min9,maj9,min10,maj10,min11,maj11,p12,a12,min13,maj13};
enum keyT {C = 0,Cs,D,Ds,E,F,Fs,G,Gs,A,As,B};
enum noteT {c = 0,cs,d,ds,e,f,fs,g,gs,a,as,b};

using midiT = std::vector<intervalT>;

const intervalT d5 = a4;

const noteT db = cs;
const noteT eb = ds;
const noteT gb = fs;
const noteT ab = gs;
const noteT bb = as;

const std::map<std::string,uint16_t> noteIdx{{"c",0},{"cs",1},{"d",2},{"ds",3},{"e",4},{"f",5},{"fs",6},{"g",7},{"gs",8},{"a",9},{"as",10},{"b",11}};

std::pair<std::string,uint8_t> strToKeyAndOct(std::string keyAndOct);
