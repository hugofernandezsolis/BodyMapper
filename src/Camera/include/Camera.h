#include <string>

#include "logs.h"

class Camera {
  public:
    Camera(void);
    Camera(const int& iId);

    std::string to_string(void);
  
  private:
    int id_;
};