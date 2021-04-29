//
//  mnotation - music scales, chords and transforming functions
//
//  Created by @pd3v_
//

#include "scales.h"
//#include "intervals.h"


scaleT scale(keyT k,scaleT s) {
  transform(s.begin(),s.end(),s.begin(),[&](intervalT i){return static_cast<intervalT>(i+k);});
  
  return s;
}

scaleT scale(std::string k,scaleT s) {
  std::pair<std::string,uint8_t> keyAndOct = strToKeyAndOct(k);
  scaleT _scale = scale(static_cast<keyT>(noteIdx.at(keyAndOct.first)),s);
  
//  return transpose<scaleT>(_scale,keyAndOct.second);
  scaleT ah;
  
  return ah;
}

/*
scaleT _transpose(scaleT s,uint8_t o) {
  transform(s.begin(),s.end(),s.begin(),[&](intervalT i){return static_cast<intervalT>(OCTAVE*o+i);});
  
  return s;
}
*/
