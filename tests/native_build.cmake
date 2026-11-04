if(NOT DEFINED CDIV_EXECUTABLE OR NOT DEFINED CDIV_SOURCE OR NOT DEFINED CDIV_OUTPUT)
  message(FATAL_ERROR "CDIV_EXECUTABLE, CDIV_SOURCE, and CDIV_OUTPUT are required")
endif()

execute_process(
  COMMAND "${CDIV_EXECUTABLE}" build "${CDIV_SOURCE}" -o "${CDIV_OUTPUT}"
  RESULT_VARIABLE build_result
  OUTPUT_VARIABLE build_stdout
  ERROR_VARIABLE build_stderr
)
if(NOT build_result STREQUAL "0")
  message(FATAL_ERROR "cdiv build failed:\n${build_stdout}\n${build_stderr}")
endif()

execute_process(
  COMMAND "${CDIV_OUTPUT}"
  RESULT_VARIABLE program_result
  OUTPUT_VARIABLE program_stdout
  ERROR_VARIABLE program_stderr
)
if(NOT program_result STREQUAL "0")
  message(FATAL_ERROR "Native program failed:\n${program_stdout}\n${program_stderr}")
endif()

if(NOT program_stdout MATCHES "5")
  message(FATAL_ERROR "Expected function result 5 in native program output, got:\n${program_stdout}")
endif()

file(REMOVE "${CDIV_OUTPUT}")
message(STATUS "Native executable built and ran successfully")
