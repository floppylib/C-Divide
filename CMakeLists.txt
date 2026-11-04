cmake_minimum_required(VERSION 3.20)
project(CDivide VERSION 0.1.0 LANGUAGES CXX)
option(CDIVIDE_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
add_executable(cdiv src/main.cpp)
target_compile_features(cdiv PRIVATE cxx_std_20)
set_target_properties(cdiv PROPERTIES CXX_EXTENSIONS OFF)
if(MSVC)
  target_compile_options(cdiv PRIVATE /W4)
  if(CDIVIDE_WARNINGS_AS_ERRORS)
    target_compile_options(cdiv PRIVATE /WX)
  endif()
else()
  target_compile_options(cdiv PRIVATE -Wall -Wextra -Wpedantic)
  if(CDIVIDE_WARNINGS_AS_ERRORS)
    target_compile_options(cdiv PRIVATE -Werror)
  endif()
endif()
include(CTest)
if(BUILD_TESTING)
  add_test(NAME syntax_smoke COMMAND cdiv check ${CMAKE_CURRENT_SOURCE_DIR}/tests/smoke.cdiv)
  add_test(NAME lexer_smoke COMMAND cdiv lex ${CMAKE_CURRENT_SOURCE_DIR}/tests/smoke.cdiv)
  add_test(NAME invalid_syntax_is_rejected
    COMMAND ${CMAKE_COMMAND}
      -DCDIV_EXECUTABLE=$<TARGET_FILE:cdiv>
      -DCDIV_SOURCE=${CMAKE_CURRENT_SOURCE_DIR}/tests/invalid.cdiv
      -P ${CMAKE_CURRENT_SOURCE_DIR}/tests/expect_failure.cmake)
endif()
include(GNUInstallDirs)
install(TARGETS cdiv RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES LICENSE DESTINATION ${CMAKE_INSTALL_DATADIR}/licenses/C-Divide)
install(FILES README.md LICENSE-DOCS
  DESTINATION ${CMAKE_INSTALL_DATADIR}/doc/C-Divide)
install(FILES docs/language.md docs/architecture.md docs/getting-started.md
  DESTINATION ${CMAKE_INSTALL_DATADIR}/doc/C-Divide)
