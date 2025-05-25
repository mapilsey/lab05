# Создание библиотеки banking
add_library(banking STATIC
  Account.cpp
  Transaction.cpp
)

# Флаги покрытия
if(ENABLE_COVERAGE)
  target_compile_options(banking PRIVATE --coverage)
  target_link_libraries(banking PRIVATE --coverage)
endif()

# Публичные заголовки
target_include_directories(banking PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
