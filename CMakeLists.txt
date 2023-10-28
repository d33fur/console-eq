cmake_minimum_required(VERSION 3.22)

project(eq)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_subdirectory(JUCE)

set(SOURCE_FILES main.cpp process.h process.cpp)

add_executable(eq ${SOURCE_FILES})

#target_compile_definitions(eq
#        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_gui_app` call
#        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_gui_app` call
#        JUCE_APPLICATION_NAME_STRING="eq"
#        JUCE_APPLICATION_VERSION_STRING="1.0")

target_link_libraries(eq 
        ${CURSES_LIBRARIES}
        juce::juce_core
        juce::juce_data_structures
        juce::juce_events
        juce::juce_audio_utils
        juce::juce_audio_processors
        juce::juce_dsp
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
#install()
