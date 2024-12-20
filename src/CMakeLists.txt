###############################################################################
###                      INTEGRATE EXTERNAL LIBRARIES                       ###
###############################################################################
## Integrate GTest for unit testing.
## Integrate SFML 2D graphics.
###############################################################################

# Find the GTest package
find_package (GTest REQUIRED)

# Find the OpenCV package
find_package (OpenCV REQUIRED)


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
