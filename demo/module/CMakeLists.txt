project(module)

add_library(${PROJECT_NAME} SHARED src/module.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin)
