CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT("VeritasEngine")

FILE(GLOB_RECURSE HEADERS relative include/*.h)
FILE(GLOB_RECURSE SOURCES relative src/*.cpp)
FILE(GLOB_RECURSE GLSL relative src/*.glsl)

ADD_LIBRARY(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${GLSL})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC include)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} VeritasAudio VeritasWindowing OpenImageIO assimp)

TARGET_COMPILE_OPTIONS(${PROJECT_NAME} PUBLIC -std=c++11)

ADD_CUSTOM_TARGET(DO_ALWAYS ALL COMMAND ${CMAKE_COMMAND} -E copy
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Runtime/*.glsl" "${CMAKE_CACHEFILE_DIR}/assets/"
)
