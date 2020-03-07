# We need thread support

add_executable(
    unit_tests
    List.cpp
    ../List.h
    )

  target_link_libraries(unit_tests gtest)


add_test(
  NAME
    unit_tests
  COMMAND
    unit_tests
  )

  add_custom_command (
  TARGET unit_tests POST_BUILD
  COMMAND unit_tests --gtest_output=xml:${unit_tests}.xml
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}
)