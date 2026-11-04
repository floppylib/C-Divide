if(NOT DEFINED CDIV_EXECUTABLE OR NOT DEFINED CDIV_SOURCE)
  message(FATAL_ERROR "CDIV_EXECUTABLE and CDIV_SOURCE are required")
endif()

execute_process(
  COMMAND "${CDIV_EXECUTABLE}" run "${CDIV_SOURCE}"
  RESULT_VARIABLE run_result
  OUTPUT_VARIABLE run_stdout
  ERROR_VARIABLE run_stderr
)
if(NOT run_result STREQUAL "0")
  message(FATAL_ERROR "cdiv run failed:\n${run_stdout}\n${run_stderr}")
endif()

if(NOT run_stdout MATCHES "5")
  message(FATAL_ERROR "Expected function result 5 in cdiv run output, got:\n${run_stdout}")
endif()

message(STATUS "C÷ source compiled and ran successfully")
