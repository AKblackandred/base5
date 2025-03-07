# CMake Lists (auto TinyXML). 

# This names our library (and for VS our project). 
set(LIB loader)  

#-------------------
# Configure TinyXML2
#-------------------

# TinyXML config here!

# Collect files matching this pattern
# into a list.
file(GLOB LIB_FILES *.cpp)

add_library(${LIB} ${LIB_FILES})

# Make sure dependent projects are compiled first!
add_dependencies(${LIB} strings) # my target(s)
add_dependencies(${LIB} maths)
add_dependencies(${LIB} scene)

# Link the current directory - for the local .h files. 
target_include_directories (${LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link TinyXML2

include(FetchContent)

# Checked the options and we can turn off testing. 
set(tinyxml2_BUILD_TESTING OFF CACHE STRING "Build tests for tinyxml2" FORCE)

# Setup FetchContent 
# Note: we're using a fixed repo. version
FetchContent_Declare(
    tinyxml2
    GIT_REPOSITORY https://github.com/leethomason/tinyxml2
    GIT_TAG 10.0.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    OVERRIDE_FIND_PACKAGE TRUE
)

if(NOT tinyxml2_POPULATED)
    FetchContent_MakeAvailable(tinyxml2)
endif()


# link TinyXML2 here ...
target_link_libraries(${LIB} LINK_PUBLIC tinyxml2::tinyxml2)

# Link other libraries
target_link_libraries (${LIB} LINK_PUBLIC strings)
target_link_libraries (${LIB} LINK_PUBLIC maths)
target_link_libraries (${LIB} LINK_PUBLIC scene)

install(TARGETS ${LIB}
	CONFIGURATIONS Release RelWithDebInfo Debug
	DESTINATION .
	)

message(STATUS "DONE!")