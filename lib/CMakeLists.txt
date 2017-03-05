cmake_minimum_required (VERSION 3.0.2)

project ("TIL Compiler Library" VERSION "1.0" LANGUAGES "C")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/" )

#enable optimization for gcc
if(CMAKE_COMPILER_IS_GNUCC)
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os")
endif(CMAKE_COMPILER_IS_GNUCC)

#set default prefix to /usr in Unix
if (UNIX AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "/usr" CACHE PATH "default install path" FORCE)
endif()

#FindLibXml2
set(LibXml2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/")
find_package(LibXml2 CONFIG REQUIRED)

if(NOT LIBXML2_FOUND)
	message(FATAL_ERROR "LibXml2 not found. Abort.")
endif()

include_directories(${LIBXML2_INCLUDE_DIR})
include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include")

set(SOURCE_FILES
	assembler.c
	compile.c
	natives.c
	start.c
	bytes.c
	funcs.c
	parser.c
	strings.c
	types.c
	libs.c
	scanner.c
	structs.c
)

add_library(tilcompiler SHARED ${SOURCE_FILES})

target_link_libraries(tilcompiler ${LIBXML2_LIBRARIES})

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	install(TARGETS tilcompiler RUNTIME DESTINATION lib)
else()
	install(TARGETS tilcompiler LIBRARY DESTINATION lib)
endif()

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/../include/til.h" DESTINATION include)


