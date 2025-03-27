#include <iostream>

using namespace std;

class Rect {
 protected:
  float width, length, area;

 public:
  Rect() { width = length = area = 0.0f; }
  Rect(float w, float l) : width(w), length(l), area(w * l) {}
  virtual float getArea() { return area; }
  float getLen() { return length; }
  float getWidth() { return width; }
};

class Cube : public Rect {
 private:
  float height;

 public:
  Cube() : Rect() { height = 0.0f; }
  Cube(float w, float l, float h) : Rect(w, l), height(h) {}
  float getArea() {
    return 2 * (height * width + width * length + length * height);
  }
};

int main() {
  Rect rect(3.0f, 4.0f);
  cout << "Rectangle Area: " << rect.getArea() << endl;

  Cube cube(3.0f, 4.0f, 5.0f);

  Rect* rectPtr = &cube;
  cout << "Cube Surface Area: " << rectPtr->getArea() << endl;
}