project(hook)

include(FetchContent)

FetchContent_Declare(funchook GIT_REPOSITORY https://github.com/kubo/funchook)
FetchContent_MakeAvailable(funchook)

add_library(${PROJECT_NAME} SHARED library.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE funchook-static)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin)
