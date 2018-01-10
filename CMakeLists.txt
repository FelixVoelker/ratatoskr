cmake_minimum_required(VERSION 3.7)
project(Ratatoskr)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package(PythonLibs 3 REQUIRED)
find_package(Boost COMPONENTS python3 REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${BOOST_INCLUDEDIR} )

set(CORE_SOURCES
        core/evaluation/Evaluator.cpp core/evaluation/Evaluator.h
        core/experience/EvolutionaryNetwork.cpp core/experience/EvolutionaryNetwork.h
        core/experience/Replayer.cpp core/experience/Replayer.h
        core/initialization/Builder.cpp core/initialization/Builder.h
        core/initialization/Initializer.cpp core/initialization/Initializer.h
        core/representation/Cost.cpp core/representation/Cost.h
        core/representation/FeatureMap.cpp core/representation/FeatureMap.h
        core/representation/Fitness.h core/representation/Fitness.cpp
        core/representation/Individual.cpp core/representation/Individual.h
        core/representation/Population.cpp core/representation/Population.h
        core/statistics/Statistics.cpp core/statistics/Statistics.h
        core/util/Prototype.h
        core/util/Singleton.h
        core/util/Thread.cpp core/util/Thread.h
        core/variation/Breeder.cpp core/variation/Breeder.h
        core/variation/BreedingOperator.cpp core/variation/BreedingOperator.h
        core/variation/SelectionOperator.cpp core/variation/SelectionOperator.h
        core/variation/VariationSource.cpp core/variation/VariationSource.h
        core/Configuration.cpp core/Configuration.h
        core/EvolutionarySystem.cpp core/EvolutionarySystem.h
        core/Problem.cpp core/Problem.h
        core/Session.cpp core/Session.h)

set(CC_API
        cc/common/Configuration.cpp cc/common/Configuration.h
        cc/common/FeatureVector.cpp cc/common/FeatureVector.h
        cc/common/FitnessProportionateSelection.cpp cc/common/FitnessProportionateSelection.h
        cc/common/Problem.cpp cc/common/Problem.h
        cc/common/TransitionTable.cpp cc/common/TransitionTable.h
        cc/common/VectorIndividual.cpp cc/common/VectorIndividual.h
        cc/ndga/BitVectorCrossover.cpp cc/ndga/BitVectorCrossover.h
        cc/ndga/BitVectorMutation.cpp cc/ndga/BitVectorMutation.h
#        cc/ec/ndga/NDGASession.cpp cc/ec/ndga/NDGASession.h
        cc/ndga/RandomBitVectorBuilder.cpp cc/ndga/RandomBitVectorBuilder.h
#        cc/problem/ndga/OneMaxProblem.cpp cc/getProblem/ndga/OneMaxProblem.h
        )

add_library(ratatoskr_cc SHARED ${CORE_SOURCES} ${CC_API})
target_link_libraries(ratatoskr_cc ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

add_executable(ratatoskr_cc_debug cc/main.cpp)
target_link_libraries(ratatoskr_cc_debug ratatoskr_cc)

set(PYTHON_API_CORE
        python/ext/wrapper/BreedingOperatorWrapper.cpp python/ext/wrapper/BreedingOperatorWrapper.h
        python/ext/wrapper/BuilderWrapper.cpp python/ext/wrapper/BuilderWrapper.h
        python/ext/wrapper/CostWrapper.cpp python/ext/wrapper/CostWrapper.h
        python/ext/wrapper/FeatureMapWrapper.cpp python/ext/wrapper/FeatureMapWrapper.h
        python/ext/wrapper/FitnessWrapper.cpp python/ext/wrapper/FitnessWrapper.h
        python/ext/wrapper/IndividualWrapper.cpp python/ext/wrapper/IndividualWrapper.h
        python/ext/wrapper/SelectionOperatorWrapper.cpp python/ext/wrapper/SelectionOperatorWrapper.h
        python/ext/wrapper/VariationSourceWrapper.cpp python/ext/wrapper/VariationSourceWrapper.h
        python/ext/core.cpp)

set(PYTHON_API_COMMON
        python/ext/common.cpp)

set(PYTHON_API_NDGA
        python/ext/ndga.cpp)

add_library(core SHARED ${PYTHON_API_CORE})
target_link_libraries(core ratatoskr_cc)
set_target_properties(core PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr PREFIX "")
#set_target_properties(core PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr SUFFIX ".pyd")

add_library(common SHARED ${PYTHON_API_COMMON})
target_link_libraries(common core)
set_target_properties(common PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr PREFIX "")
#set_target_properties(core PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr SUFFIX ".pyd")

add_library(ndga SHARED ${PYTHON_API_NDGA})
target_link_libraries(ndga core common)
set_target_properties(ndga PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr PREFIX "")
#set_target_properties(ndga PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr SUFFIX ".pyd")

add_custom_target(ratatoskr_py)
add_dependencies(ratatoskr_py core ndga)

set(UNIT_SOURCES
        unit/util/SimpleBreedingOperator.cpp unit/util/SimpleBreedingOperator.h
        unit/util/SimpleBuilder.cpp unit/util/SimpleBuilder.h
        unit/util/SimpleEvolutionaryNetwork.cpp unit/util/SimpleEvolutionaryNetwork.h
        unit/util/SimpleFeatureMap.cpp unit/util/SimpleFeatureMap.h
        unit/util/SimpleIndividual.cpp unit/util/SimpleIndividual.h
        unit/util/SimpleSelectionOperator.cpp unit/util/SimpleSelectionOperator.h
        unit/util/SimpleVariationSource.cpp unit/util/SimpleVariationSource.h
        unit/common.cpp
        unit/core.cpp
        unit/ndga.cpp
        catch.hpp)

add_executable(unit ${UNIT_SOURCES})
target_link_libraries(unit ratatoskr_cc)





