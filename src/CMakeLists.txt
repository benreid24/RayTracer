add_executable(RayTracer
    main.cpp
)

target_link_libraries(RayTracer
    BLIB
    sfml-graphics
    sfml-main
)