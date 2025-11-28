#include "shapes.hpp"
#include "vectors.hpp"
#include <math.h>
namespace SH {
square::square(vec2 position, float side_length) {
  this->side_length = side_length;
  this->position = position;
}
float square::get_signed_distance(vec2 position) {
  // if the point is bounded by the vertical lines of the square
  if (position.x < this->position.x + this->side_length / 2.0 &&
      position.x > this->position.x - this->side_length / 2.0) {
    // if the point is bounded by the horizontal lines of the square and also
    // the vertical lines
    if (position.y < this->position.y + this->side_length / 2.0 &&
        position.y > this->position.y - this->side_length / 2.0) {
      return 0.0;
    }
    // if only bounded by the vertical lines
    else {
      // if the point lies above square
      if (position.y > this->position.y) {
        vec2 intersection_point(position.x,
                                this->position.y + this->side_length / 2.0);
        return distance(position, intersection_point);
        // itf the point lies beneath square
      } else {
        vec2 intersection_point(position.x,
                                this->position.y - this->side_length / 2.0);
        return distance(position, intersection_point);
      }
    }
    // if the point is only bounded by the horizontal lines of the square
  } else if (position.y < this->position.y + this->side_length / 2.0 &&
             position.y > this->position.y - this->side_length / 2.0) {
    // if the point lies to the right side of square
    if (position.x > this->position.x) {
      vec2 intersection_point(this->position.x + this->side_length / 2.0,
                              position.y);
      return distance(intersection_point, position);
      // if the point lies to the left side of square
    } else {
      vec2 intersection_point(this->position.x - this->side_length / 2.0,
                              position.y);
      return distance(intersection_point, position);
    }
    // if the point is closest to a corner of the square(doesnt lie inside its
    // vertical or horizontal boundaries)
  } else {
    // if the point is closest to the upper right corner of square
    if (position.x > this->position.x && position.y > this->position.y) {
      vec2 upperright_corner(this->position.x + this->side_length / 2.0,
                             this->position.y + this->side_length / 2.0);
      return distance(position, upperright_corner);
    }
    // if the point is closest to the bottom right corner of square
    if (position.x > this->position.x && position.y < this->position.y) {
      vec2 bottomright_corner(this->position.x + this->side_length / 2.0,
                              this->position.y - this->side_length / 2.0);
      return distance(position, bottomright_corner);
    }
    // if the point is closest to the upper left corner of square
    if (position.x < this->position.x && position.y > this->position.y) {
      vec2 upperleft_corner(this->position.x - this->side_length / 2.0,
                            this->position.y + this->side_length / 2.0);
      return distance(position, upperleft_corner);
    }
    // if the point is closest to the bottom left corner of square
    if (position.x < this->position.x && position.y < this->position.y) {
      vec2 bottomleft_corner(this->position.x - this->side_length / 2.0,
                             this->position.y - this->side_length / 2.0);
      return distance(position, bottomleft_corner);
    }
  }
  return 0.0;
}
} // namespace SH
