cmake_minimum_required(VERSION 3.5)
project(Ratatoskr)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

# Core engine
set(CORE_SOURCES
        core/representation/Genotype.h
        core/representation/InitializationOperator.h
        core/representation/MutationOperator.cpp core/representation/MutationOperator.h
        core/representation/RecombinationOperator.cpp core/representation/RecombinationOperator.h
        core/representation/VariationOperator.h
        core/state/Individual.cpp core/state/Individual.h
        core/state/Population.cpp core/state/Population.h
        core/state/Relevance.cpp core/state/Relevance.h
        core/util/Clonable.h
        core/util/Thread.cpp core/util/Thread.h)

# CC api
set(CC_SOURCES
        cc/representation/integer/RandomBitInitialization.cpp cc/representation/integer/RandomBitInitialization.h
        cc/representation/integer/BitFlipMutation.cpp cc/representation/integer/BitFlipMutation.h
        cc/representation/integer/PointCrossover.cpp cc/representation/integer/PointCrossover.h
        cc/representation/integer/UniformCrossover.cpp cc/representation/integer/UniformCrossover.h)

add_library(ratatoskr_cc SHARED ${CORE_SOURCES} ${CC_SOURCES})

# Python api
#find_package(PythonLibs 3 REQUIRED)
#include_directories(${PYTHON_INCLUDE_DIRS})

#find_package(Boost COMPONENTS python-py35 REQUIRED)
#include_directories(${BOOST_INCLUDEDIR} )

#target_link_libraries(ratatoskr_cc ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

#set(PY_SOURCES )

#set(PYTHON_API_COMMON
#        old/python/ext/common.cpp core/representation/RecombinationOperator.h)

#set(PYTHON_API_NDGA
#        old/python/ext/ndga.cpp)

#add_library(core SHARED ${PYTHON_API_CORE})
#target_link_libraries(core ratatoskr_cc)
#set_target_properties(core PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr PREFIX "")

#add_library(common SHARED ${PYTHON_API_COMMON})
#target_link_libraries(common core)
#set_target_properties(common PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr PREFIX "")

#add_library(ndga SHARED ${PYTHON_API_NDGA})
#target_link_libraries(ndga core common)
#set_target_properties(ndga PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr PREFIX "")

#add_custom_target(ratatoskr_py)
#add_dependencies(ratatoskr_py core ndga)

# Develloper
add_executable(ratatoskr_debug debug/main.cpp)
target_link_libraries(ratatoskr_debug ratatoskr_cc)



