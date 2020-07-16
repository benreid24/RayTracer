add_executable(RayTracer
    main.cpp

    Line.hpp
)

target_link_libraries(RayTracer
    BLIB
    sfml-graphics
    sfml-main
)

target_include_directories(RayTracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})