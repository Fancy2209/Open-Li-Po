cmake_minimum_required(VERSION 3.0.0)
project(li-po 
   VERSION 0.1.0 
   LANGUAGES C CXX
)

add_subdirectory(third-party/SDL2 EXCLUDE_FROM_ALL)
add_subdirectory(third-party/mojoAL EXCLUDE_FROM_ALL)

# Lua just uses regular make
include(ExternalProject)
ExternalProject_Add(lua
   SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third-party/lua-4.0.1
   CONFIGURE_COMMAND ""
   BUILD_COMMAND make
   BUILD_ALWAYS true
   BUILD_IN_SOURCE true
   INSTALL_COMMAND ""
)
add_library(liblua STATIC IMPORTED)
if(WIN32)
   set(LUA_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/third-party/lua-4.0.1/lib/liblua.lib)
else()
   set(LUA_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/third-party/lua-4.0.1/lib/liblua.a)
endif()
set_target_properties(liblua PROPERTIES
    IMPORTED_LOCATION ${LUA_LIB_PATH}
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/third-party/lua-4.0.1/src
)

# Insert new source files here.
add_executable(li-po
        src/main.cpp
)

if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(li-po PRIVATE SDL2::SDL2main)
endif()
target_link_libraries(li-po PRIVATE liblua SDL2::SDL2 mojoal)

