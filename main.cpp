#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

int max(int r, int g, int b) {
  if (r >= g && r >= b)
    return r;
  else if (g >= r && g >= b)
    return g;
  else
    return b;
}

int min(int r, int g, int b) {
  if (r <= g && r <= b)
    return r;
  else if (g <= r && g <= b)
    return g;
  else
    return b;
}

int getShade(sf::Color color) {
  int maxS = max(color.r, color.g, color.b);
  int minS = min(color.r, color.g, color.b);
  return (minS + maxS) / 2;
}

char shadeASCII(int shade) {
  if (shade >= 0 && shade < 8) return ' ';
  if (shade >= 8 && shade < 16) return '`';
  if (shade >= 16 && shade < 24) return '\'';
  if (shade >= 24 && shade < 32) return '\"';
  if (shade >= 32 && shade < 40) return '.';
  if (shade >= 40 && shade < 48) return ',';
  if (shade >= 48 && shade < 56) return '-';
  if (shade >= 56 && shade < 64) return '~';
  if (shade >= 64 && shade < 72) return '=';
  if (shade >= 72 && shade < 80) return '+';
  if (shade >= 80 && shade < 88) return '*';
  if (shade >= 88 && shade < 96) return '<';
  if (shade >= 96 && shade < 104) return '>';
  if (shade >= 104 && shade < 112) return '(';
  if (shade >= 112 && shade < 120) return ')';
  if (shade >= 120 && shade < 128) return '[';
  if (shade >= 128 && shade < 136) return ']';
  if (shade >= 136 && shade < 144) return '{';
  if (shade >= 144 && shade < 152) return '}';
  if (shade >= 152 && shade < 160) return 'U';
  if (shade >= 160 && shade < 168) return 'O';
  if (shade >= 168 && shade < 176) return '0';
  if (shade >= 176 && shade < 184) return 'Y';
  if (shade >= 184 && shade < 192) return 'P';
  if (shade >= 192 && shade < 200) return 'A';
  if (shade >= 200 && shade < 208) return 'K';
  if (shade >= 208 && shade < 216) return 'V';
  if (shade >= 216 && shade < 224) return 'N';
  if (shade >= 224 && shade < 232) return 'M';
  if (shade >= 232 && shade < 240) return 'G';
  if (shade >= 240 && shade < 248) return 'X';
  if (shade >= 248 && shade < 256) return '@';

  return 0;
}

int main(int argc, char const *argv[]) {
  sf::Image img;
  std::string name = argv[1];
  if ((img.loadFromFile(name))) {
    std::cout << "Success" << std::endl;
  } else
    std::cout << "Smth get wrong" << std::endl;

  std::ofstream ftxt("result.txt");

  int sizeX = img.getSize().x;
  int sizeY = img.getSize().y;

  sf::Color pixelColor;

  for (int y = 0; y < sizeY; y++) {
    for (int x = 0; x < sizeX; x++) {
      pixelColor = img.getPixel(x, y);
      ftxt << shadeASCII(getShade(pixelColor));
    }
    ftxt << "|\n";
  }
  return 0;
}
