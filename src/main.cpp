#include <iostream>

#include <Camera.h>

int main(void) {

  LOG_INFO << "Init logs" << std::endl;
  Camera a;
  Camera b(2);

  std::cout << "Camera " << b.to_string();
}