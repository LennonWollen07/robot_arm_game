class RobotArm {

  public:

    void setup();
    void changePositon(int x, int y, int z);
    int stickClick(int z, int positionBase);

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