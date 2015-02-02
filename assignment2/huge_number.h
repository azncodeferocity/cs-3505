class huge_number
{
public:
  huge_number();                          // default constructor
  huge_number(std::string _num);          // constructor
  huge_number(const huge_number &other);  // copy constructor

  std::string get_value() const;  
  const huge_number operator+ (const huge_number & rhs) const;
  const huge_number operator- (const huge_number & rhs) const;
  const huge_number operator* (const huge_number & rhs) const;
  const huge_number operator/ (const huge_number & rhs) const;
  const huge_number operator% (const huge_number & rhs) const;
  huge_number& operator= (const huge_number & rhs);

private:

  std::string number;   // the big number represented as a string
  bool is_bigger (std::string left, std::string right) const;  
  std::string remove_zeros(std::string num) const;

  std::string add (std::string left, std::string right) const;
  std::string subtract (std::string left, std::string right) const;
  std::string multiply (std::string left, std::string right) const;
  std::string divide (std::string left, std::string right) const;
  std::string mod (std::string left, std::string right) const;
};