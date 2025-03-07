include(FetchContent)
 
# -------------------
# Google Test 
# -------------------

set(gtest_force_shared_crt on)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.14.0
#	GIT_SHALLOW TRUE
#	GIT_PROGRESS TRUE
#	GIT_OVERRIDE_FIND_PACKAGE TRUE
)

# FetchContent_MakeAvailable(googletest)

if(NOT googletest_POPULATED)
	FetchContent_MakeAvailable(googletest)


#	message(STATUS "Google Test source dir is ${googletest_SOURCE_DIR}")
#	message(STATUS "Google Test binary dir is ${googletest_BINARY_DIR}")
#	message(STATUS "Google Test build dir is ${googletest_BUILD_DIR}")


#add_subdirectory(${googletest_SOURCE_DIR})
endif()

include_directories(${COMMON_INCLUDES})

add_definitions(${MSVC_COMPILER_DEFS})

enable_testing()

set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_automatedTests)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/src/gtest/*.cpp)

# Construct the testing executable
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})


#I'm not sure how your supposed to figure out target names, i did a cmake <tab>
#with no dependencies to get it work.
add_dependencies(${PROJECT_TEST_NAME} gtest) # google test target

# Make sure dependent projects are compiled first!
add_dependencies(${PROJECT_TEST_NAME} strings) # my target(s)
add_dependencies(${PROJECT_TEST_NAME} maths)
add_dependencies(${PROJECT_TEST_NAME} scene)
add_dependencies(${PROJECT_TEST_NAME} loader) 


target_include_directories(${PROJECT_TEST_NAME} PUBLIC ${googletest_SOURCE_DIR}/googletest/include)

# this is target inside googletest
target_link_libraries(${PROJECT_TEST_NAME} PUBLIC gtest)

# this is my target under test
target_link_libraries (${PROJECT_TEST_NAME} LINK_PUBLIC strings)
target_link_libraries (${PROJECT_TEST_NAME} LINK_PUBLIC maths)
target_link_libraries (${PROJECT_TEST_NAME} LINK_PUBLIC scene)
target_link_libraries (${PROJECT_TEST_NAME} LINK_PUBLIC loader)


include(GoogleTest)
gtest_discover_tests(${PROJECT_TEST_NAME}
					 DISCOVERY_MODE PRE_TEST)

#-------------------
# INSTALL TARGET
#-------------------

set(APP ${PROJECT_TEST_NAME})

# post-build copy for win32
if(WIN32 AND NOT MINGW)
	add_custom_command(TARGET ${APP} PRE_BUILD
		COMMAND if not exist .\\dist mkdir .\\dist)
	add_custom_command(TARGET ${APP} POST_BUILD
		COMMAND copy \"$(TargetPath)\" .\\dist)
endif(WIN32 AND NOT MINGW)

if(MINGW OR UNIX)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/dist)
endif(MINGW OR UNIX)

message(STATUS "Value of APP " ${APP})

install(TARGETS ${APP}
	CONFIGURATIONS Release RelWithDebInfo Debug
	RUNTIME DESTINATION ./
	)

if(WIN32)
	set_target_properties(${APP} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_INSTALL_PREFIX}")

	# file(GLOB_RECURSE GOOGLETEST_DLL_FILES ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/libg*.dll)
 	# file(TO_CMAKE_PATH "${GOOGLETEST_DLL_FILES}" GOOGLETEST_DLL_FILES_NATIVE)

else()

	# Output has correct LD_LIBRARY_PATH
	set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

#	file(GLOB_RECURSE SDL2_DLL_FILES ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libg*)
#	file(TO_CMAKE_PATH "${SDL2_DLL_FILES}" GOOGLETEST_DLL_FILES_NATIVE)

endif()

install(FILES ${GOOGLETEST_DLL_FILES_NATIVE}
	CONFIGURATIONS Release RelWithDebInfo Debug
	DESTINATION .
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/testfiles 
CONFIGURATIONS Release RelWithDebInfo Debug
DESTINATION ./) 