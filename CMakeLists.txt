cmake_minimum_required(VERSION 4.2)
project(SFML-game LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SFML_VERSION 3.0.2)
find_package(SFML ${SFML_VERSION} QUIET COMPONENTS Graphics)

if(NOT SFML_FOUND)
    message(STATUS "SFML not found locally. Downloading... (this may take a while)")

    include(FetchContent)
    FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG ${SFML_VERSION}
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
    )
    FetchContent_MakeAvailable(SFML)
endif()

add_executable(main
    src/main.cpp
    src/game.cpp
    src/hud.cpp
    src/knight.cpp
    src/physics.cpp
    src/renderer.cpp
    src/sensors.cpp
    src/world.cpp
)

target_compile_features(main PRIVATE cxx_std_23)
target_link_libraries(main PRIVATE SFML::Graphics)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Make the assets a dependency
file(GLOB_RECURSE ASSET_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/assets/*"
)

# Copy the assets directory next to the bin directory
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
    DEPENDS ${ASSET_FILES}
)

add_dependencies(main copy_assets)
