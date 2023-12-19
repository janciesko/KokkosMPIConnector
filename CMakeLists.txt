cmake_minimum_required(VERSION 3.18)
project(KokkosMPIConnector LANGUAGES CXX)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)

set (NAME KokkosMPIConnector)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/modules)

option(KMC_ENABLE_TESTS "Whether to build tests" OFF)
option(KMC_ENABLE_DEBUG "Whether to enable debug output" OFF)
option(KMC_ENABLE_KOKKOS "Whether to build with Kokkos support" OFF)
option(KMC_ENABLE_MDSPAN "Whether to build with mdspan support" OFF)

if(KMC_ENABLE_KOKKOS)
  set(BACKEND KOKKOS)
  find_package(Kokkos REQUIRED)
endif()
if(KMC_ENABLE_MDSPAN)
  set(BACKEND MDSPAN)
  find_package(MDSPAN REQUIRED)
endif()

list(LENGTH BACKEND N_BACKENDS)
if (NOT ${N_BACKENDS} GREATER_EQUAL "1")
  message(FATAL_ERROR "Must give valid backend(s). ${N_BACKENDS} given.")
endif()

find_package(MPI REQUIRED)

set(SOURCES)
set(HEADERS)

set (SOURCE_DIRS "./src")

set (PUBLIC_DEPS MPI::MPI_CXX)

if(KMC_ENABLE_KOKKOS)
  list(APPEND PUBLIC_DEPS Kokkos::kokkos)
endif()

if(KMC_ENABLE_MDSPAN)
  list(APPEND PUBLIC_DEPS MDSPAN)
endif()

foreach(DIR ${SOURCE_DIRS})
  file(GLOB DIR_SRCS ${DIR}/*.cpp)
  file(GLOB DIR_HDRS ${DIR}/*.hpp)
  list(APPEND SOURCES ${DIR_SRCS})
  list(APPEND HEADERS ${DIR_HDRS})
endforeach()

add_library(${NAME} ${HEADERS} ${SOURCES})

if(KMC_ENABLE_DEBUG OR CMAKE_BUILD_TYPE STREQUAL "Debug")
 target_compile_definitions(${NAME} PUBLIC KMC_ENABLE_DEBUG)
 message(STATUS "Enabled build mode: debug")
endif()

target_include_directories(${NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/>)
target_include_directories(${NAME} PUBLIC $<INSTALL_INTERFACE:include>)

target_link_libraries(${NAME} PUBLIC ${PUBLIC_DEPS})

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/${NAME}Config.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/${NAME}ConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${NAME}})

install(FILES
  ${HEADERS}
  DESTINATION include DESTINATION include}
)

IF (KMC_ENABLE_TESTS)
  enable_testing()
  add_subdirectory(test)
ENDIF()
