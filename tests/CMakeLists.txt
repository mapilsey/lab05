# Исполняемый файл тестов
add_executable(banking_tests
  test_account.cpp
  test_transaction.cpp
)

target_include_directories(banking_tests PRIVATE
  ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(banking_tests PRIVATE
  banking
  gmock
  gtest_main
)

gtest_discover_tests(banking_tests)
