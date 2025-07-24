
file(GLOB_RECURSE CORE_SRC CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS "include/*.h")

add_library(core STATIC ${CORE_SRC} ${CORE_HEADERS})

# Set the include path for others to find engine headers
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# Link SFML to the engine
target_link_libraries(core PUBLIC 
    sfml-graphics 
    sfml-window 
    sfml-system
)