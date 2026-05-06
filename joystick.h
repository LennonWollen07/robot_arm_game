class JoyStick {

  public:

    JoyStick(int JoyStick_X, int JoyStick_Y, int JoyStick_Z);

    void setup();
    void readValues();

    int x,y,z; // positions of the joystick

  private:

    int JoyStick_X; //x
    int JoyStick_Y; //y
    int JoyStick_Z; //key

};