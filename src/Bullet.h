class Bullet {
  public:
  Bullet(int startX, int startY, int targetX, int targetY);
  int x = 0;
  int y = 0;
  int speedX = 0;
  int speedY = 0;
  int ticksLeft = 10;

  void tick();
};
