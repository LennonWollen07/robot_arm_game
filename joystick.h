class JoyStick {

  public:

    void setup();
    void readValues();

    int x,y,z; // positions of the joystick

  private:

    int JoyStick_X = 0; //x
    int JoyStick_Y = 1; //y
    int JoyStick_Z = 8; //key

};