# CMake Lists 

# This names our library (and for VS our project). 
set(LIB scene) 

# Collect files matching this pattern
# into a list.
file(GLOB LIB_FILES *.cpp)

add_library(${LIB} ${LIB_FILES})

# Link the current directory - for the local .h files. 
target_include_directories (${LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_dependencies(${LIB} maths)

# Link other libraries

target_link_libraries (${LIB} LINK_PUBLIC maths)

install(TARGETS ${LIB}
	CONFIGURATIONS Release RelWithDebInfo Debug
	DESTINATION .
	)

message(STATUS "DONE!")
