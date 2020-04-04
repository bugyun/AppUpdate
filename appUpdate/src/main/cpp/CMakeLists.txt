cmake_minimum_required(VERSION 3.4.1)

# DEBUG 不压缩
#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS}  -O0 -Wall -g2 -ggdb")
# RELEASE 压缩c++代码体积
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS}  -Os -Wall -s")

# 添加头文件地址 .h
include_directories(${CMAKE_SOURCE_DIR}/core)
# 添加源文件地址 .cpp
aux_source_directory(${CMAKE_SOURCE_DIR}/core CORE_DIR)


add_library( # Sets the name of the library.
        appUpdate
        SHARED
        appUpdate.cpp
        ${CORE_DIR}
        )

find_library( # Sets the name of the path variable.
        log-lib
        log)

target_link_libraries( # Specifies the target library.
        appUpdate
        ${log-lib})