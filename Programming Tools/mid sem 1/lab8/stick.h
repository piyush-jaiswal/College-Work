
struct Length
{
  double meter;
  double centimeter;
};

class Stick
{
  private:
     Length len;

  public:
    Stick();
    Stick(double, double);
    Stick operator+(const Stick&);
    bool operator==(const Stick&);
    void display();
};
