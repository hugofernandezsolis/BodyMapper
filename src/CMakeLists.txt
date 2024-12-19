###############################################################################
###                      INTEGRATE EXTERNAL LIBRARIES                       ###
###############################################################################
## Integrate GTest for unit testing.
## Integrate SFML 2D graphics.
###############################################################################

include(FetchContent)

message(STATUS "Fetching GTest...")

# Download and configure Google Test as part of the build
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main  # Specify the version you need
)

FetchContent_MakeAvailable(googletest)

find_package(
  GTest
    REQUIRED
)

message(STATUS "Fetching OpenCV...")

# Download and configure OpenCV as part of the build
FetchContent_Declare(
    opencv
    GIT_REPOSITORY https://github.com/opencv/opencv.git
    GIT_TAG 4.x  # Replace with the specific version tag you need, e.g., 4.5.2
)

FetchContent_MakeAvailable(opencv)

# Find the OpenCV package
find_package(OpenCV REQUIRED)


###############################################################################
###                               COMPONENTS                                ###
###############################################################################
## Include project components and subdirectories.
###############################################################################

# Get a list of subdirectories in the current directory
set (
  COMPONENTS
    common          # common
    Camera          
)

add_executable (
  ${PROJECT_NAME}
    ./main.cpp
)

# Iterate over each subdirectory
foreach(COMPONENT ${COMPONENTS})
  # Set the name of the component library.
  set (COMPONENT_LIB ${COMPONENT}_lib)
  # Enter into the component
  add_subdirectory(${COMPONENT})
  # Link the new lib to the executable
  target_link_libraries (
    ${PROJECT_NAME}
      ${COMPONENT}_lib
  )
endforeach()
