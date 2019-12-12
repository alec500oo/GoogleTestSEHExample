# Source include file. This is where the main project is built

file(GLOB SOURCES "*.cpp")

add_executable(tests ${SOURCES})

target_include_directories(tests PUBLIC "${CMAKE_SOURCE_DIR}/lib/googletest/googlemock/include")
target_include_directories(tests PUBLIC "${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include")

target_link_libraries(tests gtest)
target_link_libraries(tests gmock_main)
