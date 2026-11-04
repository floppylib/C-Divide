cmake_minimum_required(VERSION 3.20)
project(CDivide VERSION 0.2.0 LANGUAGES CXX)
option(CDIVIDE_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
add_executable(cdiv src/main.cpp)
target_compile_features(cdiv PRIVATE cxx_std_20)
target_compile_definitions(cdiv PRIVATE CDIV_DEFAULT_CXX=\"${CMAKE_CXX_COMPILER}\")
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
  add_test(NAME native_run_smoke COMMAND cdiv run ${CMAKE_CURRENT_SOURCE_DIR}/tests/smoke.cdiv)
  add_test(NAME native_build_smoke
    COMMAND ${CMAKE_COMMAND}
      -DCDIV_EXECUTABLE=$<TARGET_FILE:cdiv>
      -DCDIV_SOURCE=${CMAKE_CURRENT_SOURCE_DIR}/tests/smoke.cdiv
      -DCDIV_OUTPUT=${CMAKE_CURRENT_BINARY_DIR}/cdiv-native-smoke${CMAKE_EXECUTABLE_SUFFIX}
      -P ${CMAKE_CURRENT_SOURCE_DIR}/tests/native_build.cmake)
endif()
include(GNUInstallDirs)
install(TARGETS cdiv RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES LICENSE DESTINATION ${CMAKE_INSTALL_DATADIR}/licenses/C-Divide)
install(FILES README.md LICENSE-DOCS
  DESTINATION ${CMAKE_INSTALL_DATADIR}/doc/C-Divide)
install(FILES docs/language.md docs/architecture.md docs/getting-started.md docs/native-backend.md
  DESTINATION ${CMAKE_INSTALL_DATADIR}/doc/C-Divide)
