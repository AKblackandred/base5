#-------------------
# Google Test
#-------------------
# Updated based on https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For Windows: Prevent overriding the parent project's compiler/linker settings
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE) # Disable gmock, not needed for this project
set(BUILD_GTEST ON CACHE BOOL "" FORCE) # Enable gtest, needed for this project

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.17.0
	GIT_SHALLOW TRUE
	GIT_PROGRESS TRUE
	GIT_OVERRIDE_FIND_PACKAGE TRUE
)

# Populate only if Googltest is not already download. 
if(NOT googletest_POPULATED)
	FetchContent_MakeAvailable(googletest)
endif()

enable_testing()

set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_automatedTests)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/src/gtest/*.cpp)

# Construct the testing executable
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})


#I'm not sure how your supposed to figure out target names, i did a cmake <tab>
#with no dependencies to get it work.
add_dependencies(${PROJECT_TEST_NAME} gtest) # google test target

# Make sure dependent projects are compiled first!
add_dependencies(${PROJECT_TEST_NAME} GTest::gtest_main) # google test target
add_dependencies(${PROJECT_TEST_NAME} strings) # my target(s)
add_dependencies(${PROJECT_TEST_NAME} maths)
add_dependencies(${PROJECT_TEST_NAME} scene)
add_dependencies(${PROJECT_TEST_NAME} loader) 


target_include_directories(${PROJECT_TEST_NAME} PUBLIC ${googletest_SOURCE_DIR}/googletest/include)

# this is target inside googletest
target_link_libraries(${PROJECT_TEST_NAME} PUBLIC GTest::gtest_main)

# this is my target under test
target_link_libraries (${PROJECT_TEST_NAME} LINK_PUBLIC strings)
target_link_libraries (${PROJECT_TEST_NAME} LINK_PUBLIC maths)
target_link_libraries (${PROJECT_TEST_NAME} LINK_PUBLIC scene)
target_link_libraries (${PROJECT_TEST_NAME} LINK_PUBLIC loader)


include(GoogleTest)
gtest_discover_tests(${PROJECT_TEST_NAME}
					 DISCOVERY_MODE PRE_TEST)

if(WIN32)
	# # https://stackoverflow.com/questions/23950887/does-cmake-offer-a-method-to-set-the-working-directory-for-a-given-build-system
	# # Ignored due to a VS issue https://developercommunity.visualstudio.com/content/problem/268817/debugger-no-longer-respects-localdebuggerworkingdi.html
	set_target_properties(${PROJECT_TEST_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_INSTALL_PREFIX}")
endif()

#-------------------------------						   
# Install the test executable	
#-------------------------------

if(MINGW OR UNIX)
	set(EXECUTABLE_OUTPUT_PATH ${CMAKE_INSTALL_PREFIX})
endif(MINGW OR UNIX)

install(TARGETS ${PROJECT_TEST_NAME}
	CONFIGURATIONS Release RelWithDebInfo Debug
	RUNTIME DESTINATION .
)

#-------------------------------						   
# Install the test files		
#-------------------------------

install(DIRECTORY ${CMAKE_SOURCE_DIR}/src/testfiles
	CONFIGURATIONS Release RelWithDebInfo Debug
	DESTINATION .)
				 
#-------------------------------                           
# Install the Google Test Libraries  
#-------------------------------        

# No install for these, they are static libraries
# linked to the test executable.
