#ifndef SH_SHAPES
#define SH_SHAPES
#include "vectors.hpp"
namespace SH {
class shape {
public:
  vec2 position;
  virtual float get_signed_distance(vec2) = 0;
};
class square : public shape {
public:
  float side_length;
  square(vec2, float);
  float get_signed_distance(vec2) override;
};
} // namespace SH

#endif
