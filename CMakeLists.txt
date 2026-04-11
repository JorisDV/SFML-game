cmake_minimum_required(VERSION 4.2)
project(SFML-game LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SFML_VERSION 3.0.2)
set(SFML_BUILD_EXAMPLES OFF)
SET(SFML_BUILD_TEST_SUITE OFF)
set(SFML_BUILD_DOC OFF)
set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)
set(SFML_USE_SYSTEM_DEPS OFF)

find_package(SFML ${SFML_VERSION} QUIET COMPONENTS Graphics)

if(NOT SFML_FOUND)
    include(FetchContent)

    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG ${SFML_VERSION}
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
    )
    FetchContent_MakeAvailable(SFML)
endif()

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game.cpp
    src/hud.cpp
    src/knight.cpp
    src/physics.cpp
    src/renderer.cpp
    src/sensors.cpp
    src/world.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics stdc++exp) # stdc++exp needed for std::print
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

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

add_dependencies(${PROJECT_NAME} copy_assets)
