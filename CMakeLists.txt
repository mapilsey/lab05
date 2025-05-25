cmake_minimum_required(VERSION 3.14)
project(banking LANGUAGES CXX)

# Настройки покрытия кода
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if(ENABLE_COVERAGE)
  message(STATUS "Code coverage enabled")
endif()

# Подключение GoogleTest
include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Поддиректории
add_subdirectory(src)
add_subdirectory(tests)
