class RobotArm {

  public:

    void setup();
    void changePositon(int x1, int y1, int z1, int x2, int y2, int z2);
    int stickClick(int stick1, int stick2, int positionSection, int maxDegree, int minDegree);
    int stickMove(int n, int positionSection, int maxDegree, int minDegree);

  private:

    int positionDelay = 10;
    int positionBase = 90;
    int positionShoulder = 90;
    int positionElbow = 90;
    int positionWristRot = 90;
    int positionWristVer = 90;
    int positionGripper = 10;

};