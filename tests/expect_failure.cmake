execute_process(
  COMMAND "${CDIV_EXECUTABLE}" check "${CDIV_SOURCE}"
  RESULT_VARIABLE result
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error_output
)
if(result EQUAL 0)
  message(FATAL_ERROR "The invalid fixture unexpectedly passed syntax checking")
endif()
if(NOT error_output MATCHES "expected ';' after print statement")
  message(FATAL_ERROR "Expected syntax diagnostic was not found. stderr: ${error_output}")
endif()
