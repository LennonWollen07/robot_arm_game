class RobotArm {

  public:

    void setup();
    void changePositon(int x, int y, int z);
    int stickClick(int n, int positionSection, int maxDegree, int minDegree);
    int stickMove(int n, int positionSection, int maxDegree, int minDegree);

  private:

    int positionDelay = 10;
    int positionBase = 90;
    int positionShoulder = 90;
    int positionElbow = 90;
    int positionWristRot = 90;
    int positionWristVer = 90;
    int positionGripper = 73;

    bool isStickCLickAdding = true;

};