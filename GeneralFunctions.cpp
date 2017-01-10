#include "GeneralFunctions.hpp"

const float& min (const float& a, const float& b){
  return !(b<a)?a:b;     // or: return !comp(b,a)?a:b; for version (2)
}

const float& max (const float& a, const float& b){
  return (a<b)?b:a;     // or: return comp(a,b)?b:a; for version (2)
}
