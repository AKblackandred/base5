# CMake Lists  

# This names our executable (and for VS our project). 
set(APP ui)  

include(FetchContent)

set(ONLY_LIBS ON CACHE BOOL "Build libs only" FORCE)
set(glew-cmake_BUILD_STATIC ON CACHE BOOL "Build the static glew library" FORCE)
set(glew-cmake_BUILD_SHARED OFF CACHE BOOL "Build the shared glew library" FORCE)
set(USE_GLU OFF CACHE BOOL "Use GLU")

FetchContent_Declare(
    glew
    GIT_REPOSITORY https://github.com/Perlmint/glew-cmake
    GIT_TAG glew-cmake-2.2.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    OVERRIDE_FIND_PACKAGE TRUE
)

if(NOT glew_POPULATED)
	FetchContent_MakeAvailable(glew)   
	FetchContent_GetProperties(glew)
endif()

# Defaults are fine .. 
set(wxBUILD_SAMPLES OFF CACHE BOOL "SOME, ALL or OFF" FORCE)
set(wxBUILD_SHARED OFF CACHE BOOL "Build shared or static libraries" FORCE)
set(wxUSE_GLCANVAS_EGL OFF CACHE BOOL "use EGL backend for wxGLCanvas" FORCE)

FetchContent_Declare(
    wxwidgets
    GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets
    GIT_TAG v3.2.6
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    OVERRIDE_FIND_PACKAGE TRUE
)

if(NOT wxwidgets_POPULATED)
    FetchContent_MakeAvailable(wxwidgets)
endif()
 
file(GLOB UI_FILES *.cpp)

IF (WIN32)
	add_executable(${APP} WIN32 ${UI_FILES})
ELSE()
	add_executable(${APP} ${UI_FILES})
ENDIF()

if(WIN32)
	set_target_properties(${APP} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_INSTALL_PREFIX}")
else()
	# Output has correct LD_LIBRARY_PATH
	set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)
endif()

# Make sure dependent projects are compiled first!
add_dependencies(${APP} libglew_static)
add_dependencies(${APP} wx::core wx::base wx::gl)

add_dependencies(${APP} strings) # my target(s)
add_dependencies(${APP} maths)
add_dependencies(${APP} scene)
add_dependencies(${APP} loader) 

# Link the current directory - for the local .h files. 
target_include_directories (${APP} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link glew
target_link_libraries(${APP} LINK_PUBLIC libglew_static)

# Link wxWidgets
target_link_libraries(${APP} LINK_PUBLIC wx::gl wx::core wx::base)

# Link our libraries
target_link_libraries (${APP} LINK_PUBLIC strings)
target_link_libraries (${APP} LINK_PUBLIC maths)
target_link_libraries (${APP} LINK_PUBLIC scene)
target_link_libraries (${APP} LINK_PUBLIC loader)

install(TARGETS ${APP}
	CONFIGURATIONS Release RelWithDebInfo Debug
	DESTINATION .
	)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/assets
	CONFIGURATIONS Release RelWithDebInfo Debug
	DESTINATION ./) 

message(STATUS "DONE!")