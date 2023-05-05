cmake_minimum_required(VERSION 3.8)
project(astyle CXX)

add_subdirectory( AStyle )

# Only attempt to build wxWidgets if found
find_package(wxWidgets)
if (wxWidgets_FOUND)
    add_subdirectory( AStyleWx )
endif ()
