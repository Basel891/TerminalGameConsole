#include "mazerunner.hpp"
#include "generalutils.hpp"
#include "shapes.hpp"
#include "vectors.hpp"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>
bool ray_march(SH::vec2 pixel_position, std::vector<SH::square> &sqlist,
               SH::vec2 CENTER_PIXEL) {
  float march_distance = 99999.0;
  while (march_distance > 0.01) {
    for (SH::square square : sqlist) {
      float signed_distance = square.get_signed_distance(pixel_position);
      if (signed_distance == 0.0)
        return false;
      march_distance = std::min(march_distance, signed_distance);
    }
    if (SH::distance(pixel_position, CENTER_PIXEL) < march_distance)
      return true;
    pixel_position =
        SH::add(pixel_position,
                SH::scalar_multiply(
                    SH::normalize(SH::subtract(CENTER_PIXEL, pixel_position)),
                    march_distance));
  }
  return false;
}
void render_pixel(int x, int y, int width, int height,
                  std::string &screen_buffer, SH::vec2 &CENTER_PIXEL_UI,
                  std::vector<SH::square> &sqlist, SH::vec2 &CENTER_PIXEL) {
  SH::vec2 CURRENT_PIXEL((float)x, (float)y);
  int r, g, b;
  r = ray_march(CURRENT_PIXEL, sqlist, CENTER_PIXEL)
          ? r = 255 /
                (std::max((int)SH::distance(CURRENT_PIXEL, CENTER_PIXEL), 1))
          : r = 0;
  g = r;
  b = r;
  if (x == CENTER_PIXEL.x && y == CENTER_PIXEL.y) {
    r = 0;
    g = 0;
    b = 255;
  }
  color_pixel(screen_buffer, r, g, b);
}
void color_pixel(std::string &buffer, int r, int g, int b) {

  buffer += "\033[38;2;";
  buffer += std::to_string(r);
  buffer += ";";
  buffer += std::to_string(g);
  buffer += ";";
  buffer += std::to_string(b);
  buffer += "m\033[48;2;";
  buffer += std::to_string(r);
  buffer += ";";
  buffer += std::to_string(g);
  buffer += ";";
  buffer += std::to_string(b);
  buffer += "mC\033[m";
}
void clear_buffer(std::string &screen_buffer) {
  Clear_Terminal();
  screen_buffer = "";
}
std::vector<SH::square> generate_level() {
  std::vector<SH::square> sqlist;
  for (int i = 0; i < 100; i++) {
    srand(i);
    SH::vec2 sqpos(rand() % 300, rand() % 300);
    SH::square new_square(sqpos, 5);
    sqlist.push_back(new_square);
  }
  return sqlist;
}
void init_mazerunner() {
  int width;
  int height;
  int width_offset = 0;
  int height_offset = 0;
  std::vector<int> mslist = {};
  std::string screen_buffer = "";
  bool running = true;
  while (running) {
    auto t1 = std::chrono::high_resolution_clock::now();
    clear_buffer(screen_buffer);
    get_terminal_size(width, height);
    SH::vec2 CENTER_PIXEL_UI((float)(width / 2), (float)(height / 2));
    SH::vec2 CENTER_PIXEL((float)(width / 2) + width_offset,
                          (float)(height / 2) + height_offset);
    std::vector<SH::square> sqlist = generate_level();
    for (int h = 0; h < height; h++) {
      for (int w = 0; w < width; w++) {
        render_pixel(w + width_offset, h + height_offset, width, height,
                     screen_buffer, CENTER_PIXEL_UI, sqlist, CENTER_PIXEL);
      }
    }
    std::cout << screen_buffer;
    auto t2 = std::chrono::high_resolution_clock::now();
    int ms = (std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1))
                 .count();
    mslist.push_back(ms);
    float fps = (float)ms;
    char input;
    std::cin >> input;
    switch (input) {
    case 'q':
      for (int mis : mslist) {
        fps = ((float)(fps + mis)) / 2.0;
      }
      std::cout << "\n" << fps << "\n" << width << "\n" << height << "\n";
      return;
      break;
    case 'a':
      width_offset -= 5;
      break;
    case 'd':
      width_offset += 5;
      break;
    case 's':
      height_offset += 5;
      break;
    case 'w':
      height_offset -= 5;
      break;
    default:
      continue;
    }
  }
}
