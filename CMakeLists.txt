cmake_minimum_required (VERSION 3.0.2)

project ("TIL Compiler" VERSION "1.0" LANGUAGES "C")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake" )

add_subdirectory ("${CMAKE_CURRENT_SOURCE_DIR}/lib")

#enable optimization for gcc
if(CMAKE_COMPILER_IS_GNUCC)
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os")
endif(CMAKE_COMPILER_IS_GNUCC)

#set default prefix to /usr in Unix
if (UNIX AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "/usr" CACHE PATH "default install path" FORCE)
endif()

#FindLibXml2
set(LibXml2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
find_package(LibXml2 CONFIG REQUIRED)

if(NOT LIBXML2_FOUND)
	message(FATAL_ERROR "LibXml2 not found. Abort.")
endif()

include_directories(${LIBXML2_INCLUDE_DIR})
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCE_FILES
	"${CMAKE_CURRENT_SOURCE_DIR}/src/tilc.c"
)

add_executable(tilc ${SOURCE_FILES})

target_link_libraries(tilc tilcompiler ${LIBXML2_LIBRARIES})

install(TARGETS tilc RUNTIME DESTINATION bin)

