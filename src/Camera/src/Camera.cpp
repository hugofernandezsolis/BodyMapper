#include "Camera.h"

Camera::Camera(void) {
  this->id_ = 0;
  LOG_INFO << "Created empty camera";
}

Camera::Camera(const int& iId) {
  this->id_ = iId;
  LOG_INFO << "Created camera with id";
}



std::string Camera::to_string(void) {
  return "Camera()";
}