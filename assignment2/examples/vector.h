

class vector
{
public:
  vector(int _x, int _y);  // Constructor
  ~vector(); // destructor

  int get_x();
  int get_y();

  vector operator+ (const vector & rhs) const;
  
private:

    int x;
    int y;

};
  