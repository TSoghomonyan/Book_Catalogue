cmake_minimum_required (VERSION 3.12)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Book_Catalogue")

file(GLOB SOURCES CONFIGURE_DEPENDS
	*.cpp *.h 
	Core/*.cpp Core/*.h 
	Books/*.cpp Books/*.h
)

add_executable (Book_Catalogue ${SOURCES})

target_include_directories(Book_Catalogue PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set_property(TARGET Book_Catalogue PROPERTY CXX_STANDARD 20)
