cmake_minimum_required(VERSION 3.7)
project(NDEC)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package(PythonLibs 3 REQUIRED)
find_package(Boost COMPONENTS python3 REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${BOOST_INCLUDEDIR} )

set(CORE_SOURCES
        core/evaluation/Evaluator.cpp core/evaluation/Evaluator.h
        core/evaluation/Problem.cpp core/evaluation/Problem.h
        core/initialization/Builder.cpp core/initialization/Builder.h
        core/representation/FeatureMap.cpp core/representation/FeatureMap.h
        core/representation/Fitness.h core/representation/Fitness.cpp
        core/representation/Individual.cpp core/representation/Individual.h
        core/representation/Population.cpp core/representation/Population.h
        core/statistics/Statistics.cpp core/statistics/Statistics.h
        core/util/Prototype.cpp core/util/Prototype.h
        core/util/Randomizer.cpp core/util/Randomizer.h
        core/util/Singleton.cpp core/util/Singleton.h
        core/variation/Breeder.cpp core/variation/Breeder.h
        core/variation/BreedingOperator.cpp core/variation/BreedingOperator.h
        core/variation/SelectionOperator.cpp core/variation/SelectionOperator.h
        core/variation/VariationSource.cpp core/variation/VariationSource.h
        core/EvolutionarySystem.cpp core/EvolutionarySystem.h
        core/Session.cpp core/Session.h)

set(CC_API
        cc/toolbox/ec/common/FitnessProportionateSelection.cpp cc/toolbox/ec/common/FitnessProportionateSelection.h
        cc/toolbox/ec/common/RawFitness.cpp cc/toolbox/ec/common/RawFitness.h
        cc/toolbox/ec/ndga/BitVectorCrossover.cpp cc/toolbox/ec/ndga/BitVectorCrossover.h
        cc/toolbox/ec/ndga/BitVectorIndividual.cpp cc/toolbox/ec/ndga/BitVectorIndividual.h
        cc/toolbox/ec/ndga/BitVectorMutation.cpp cc/toolbox/ec/ndga/BitVectorMutation.h
        cc/toolbox/ec/ndga/FeatureVector.cpp cc/toolbox/ec/ndga/FeatureVector.h
        cc/toolbox/ec/ndga/NDGAProblem.cpp cc/toolbox/ec/ndga/NDGAProblem.h
        cc/toolbox/ec/ndga/NDGASession.cpp cc/toolbox/ec/ndga/NDGASession.h
        cc/toolbox/ec/ndga/RandomBitVectorBuilder.cpp cc/toolbox/ec/ndga/RandomBitVectorBuilder.h
        cc/toolbox/problem/ndga/OneMaxProblem.cpp cc/toolbox/problem/ndga/OneMaxProblem.h)

set(PYTHON_API
        python/wrapper/core_wrapper.cpp python/wrapper/core_wrapper.h)

set(UNIT_SOURCES
        unit/TestComponents.cpp unit/TestComponents.h
        unit/core.cpp
        unit/common.cpp
        unit/ndga.cpp
        catch.hpp)

add_library(ndec_cc SHARED ${CORE_SOURCES} ${CC_API})
target_link_libraries(ndec_cc ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

add_library(core SHARED python/ext/core_ext.cpp)
target_link_libraries(core ndec_cc)
set_target_properties(core PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ndec PREFIX "")

add_library(ndga SHARED python/ext/ndga_ext.cpp)
target_link_libraries(ndga ndec_cc)
set_target_properties(ndga PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ndec PREFIX "")

add_executable(Unit ${UNIT_SOURCES})
target_link_libraries(Unit ndec_cc)





