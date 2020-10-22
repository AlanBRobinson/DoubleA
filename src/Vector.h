class Vector {
  Vector(int x, int y);
  float x = 0;
  float y = 0;

  float getAngle();
  void setAngle(float angle);

  float getMagnitude();
  void setMangnitude(float magnitude);

  Vector addVector(Vector vector);
  Vector normalize();
};
