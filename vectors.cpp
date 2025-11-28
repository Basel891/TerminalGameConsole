#include "vectors.hpp"
#include <cstdlib>
#include <math.h>
namespace SH {
float dot(vec2 a, vec2 b) { return a.x * b.x + a.y * b.y; }
float dot(vec3 a, vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
vec3 cross(vec2 a, vec2 b) {
  vec3 c;
  c.z = a.x * b.y - a.y * b.x;
  return c;
}
vec3 cross(vec3 a, vec3 b) {
  vec3 c;
  c.x = a.y * b.z - a.z * b.y;
  c.y = -1 * (a.x * b.z - a.x * b.x);
  c.z = a.x * b.y - a.y * b.x;
  return c;
}
vec2 add(vec2 a, vec2 b) {
  vec2 c;
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  return c;
}
vec3 add(vec3 a, vec3 b) {
  vec3 c;
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  return c;
}
vec2 subtract(vec2 a, vec2 b) {
  vec2 c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  return c;
}
vec3 subtract(vec3 a, vec3 b) {
  vec3 c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  return c;
}
float distance(vec2 a, vec2 b) {
  return std::sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}
float distance(vec3 a, vec3 b) {
  return std::sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) +
                   pow((a.z - b.z), 2));
}
vec2 abs(vec2 a) {
  vec2 c;
  c.x = std::abs(a.x);
  c.y = std::abs(a.y);
  return c;
}
vec3 abs(vec3 a) {
  vec3 c;
  c.x = std::abs(a.x);
  c.y = std::abs(a.y);
  c.z = std::abs(a.z);
  return c;
}
float magnitude(vec2 a) { return std::sqrt((a.x * a.x) + (a.y * a.y)); }
float magnitude(vec3 a) {
  return std::sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}
vec2 normalize(vec2 a) {
  vec2 c;
  float mag = magnitude(a);
  c.x = a.x / mag;
  c.y = a.y / mag;
  return c;
}
vec3 normalize(vec3 a) {
  vec3 c;
  float mag = magnitude(a);
  c.x = a.x / mag;
  c.y = a.y / mag;
  c.z = a.z / mag;
  return c;
}
} // namespace SH
