#ifndef SH_VECTORS
#define SH_VECTORS
namespace SH {
struct vec2{int x; int y;};
struct vec3{int x; int y; int z;};
int dot(vec2, vec2);
int dot(vec3, vec3);
vec3 cross(vec2, vec2);
vec3 cross(vec3, vec3);
vec2 add(vec2, vec2);
vec3 add(vec3, vec3);
// subtract arg1 - arg2
vec2 subtract(vec2, vec2);
// subtract arg1 - arg2
vec3 subtract(vec3, vec3);
float distance(vec2, vec2);
float distance(vec3, vec3);

} // namespace SH
#endif
