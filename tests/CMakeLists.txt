include(GoogleTest)

add_executable(GenesisMathTests
    "src/vector2_tests.cpp"
)

target_link_libraries(GenesisMathTests
    GTest::gtest_main
    genesis::math
)

gtest_discover_tests(GenesisMathTests)