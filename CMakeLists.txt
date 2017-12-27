cmake_minimum_required(VERSION 3.7)
project(Ratatoskr)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package(PythonLibs 3 REQUIRED)
find_package(Boost COMPONENTS python3 REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${BOOST_INCLUDEDIR} )

set(CORE_SOURCES
#        core/evaluation/Evaluator.cpp core/evaluation/Evaluator.h
#        core/evaluation/EvolutionaryNetwork.cpp core/evaluation/EvolutionaryNetwork.h
        core/evaluation/Problem.cpp core/evaluation/Problem.h
#        core/experience/Replayer.cpp core/experience/Replayer.h
        core/initialization/Builder.cpp core/initialization/Builder.h
        core/representation/Cost.cpp core/representation/Cost.h
        core/representation/FeatureMap.cpp core/representation/FeatureMap.h
        core/representation/Fitness.h core/representation/Fitness.cpp
        core/representation/Individual.cpp core/representation/Individual.h
#        core/representation/Population.cpp core/representation/Population.h
#        core/statistics/Statistics.cpp core/statistics/Statistics.h
        core/util/Clonable.h
        core/util/Prototype.h
#        core/util/Randomizer.cpp core/util/Randomizer.h
        core/util/Singleton.h
#        core/variation/Breeder.cpp core/variation/Breeder.h
#        core/variation/BreedingOperator.cpp core/variation/BreedingOperator.h
#        core/variation/SelectionOperator.cpp core/variation/SelectionOperator.h
#        core/variation/VariationSource.cpp core/variation/VariationSource.h
#        core/EvolutionarySystem.cpp core/EvolutionarySystem.h
        core/Session.cpp core/Session.h
        )

set(CC_API
#        cc/ec/common/FitnessProportionateSelection.cpp cc/ec/common/FitnessProportionateSelection.h
#        cc/ec/ndga/BitVectorCrossover.cpp cc/ec/ndga/BitVectorCrossover.h
#        cc/ec/ndga/BitVectorIndividual.cpp cc/ec/ndga/BitVectorIndividual.h
#        cc/ec/ndga/BitVectorMutation.cpp cc/ec/ndga/BitVectorMutation.h
#        cc/ec/ndga/FeatureVector.cpp cc/ec/ndga/FeatureVector.h
#        cc/ec/ndga/NDGAProblem.cpp cc/ec/ndga/NDGAProblem.h
#        cc/ec/ndga/NDGASession.cpp cc/ec/ndga/NDGASession.h
#        cc/ec/ndga/RandomBitVectorBuilder.cpp cc/ec/ndga/RandomBitVectorBuilder.h
#        cc/problem/ndga/OneMaxProblem.cpp cc/getProblem/ndga/OneMaxProblem.h
        )

add_library(ratatoskr_cc SHARED ${CORE_SOURCES} ${CC_API})
target_link_libraries(ratatoskr_cc ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

add_executable(ratatoskr_cc_debug cc/main.cpp)
target_link_libraries(ratatoskr_cc_debug ndec_cc)

set(PYTHON_API_CORE
        python/ext/wrapper/core/BuilderWrapper.cpp python/ext/wrapper/core/BuilderWrapper.h
        python/ext/wrapper/core/CostWrapper.cpp python/ext/wrapper/core/CostWrapper.h
        python/ext/wrapper/core/FeatureMapWrapper.cpp python/ext/wrapper/core/FeatureMapWrapper.h
        python/ext/wrapper/core/FitnessWrapper.cpp python/ext/wrapper/core/FitnessWrapper.h
        python/ext/wrapper/core/IndividualWrapper.cpp python/ext/wrapper/core/IndividualWrapper.h
        python/ext/wrapper/core/ProblemWrapper.cpp python/ext/wrapper/core/ProblemWrapper.h
        python/ext/wrapper/core/SessionWrapper.cpp python/ext/wrapper/core/SessionWrapper.h
        python/ext/core_ext.cpp)

set(PYTHON_API_NDGA
        python/ext/wrapper/ndga/ProblemWrapper.cpp python/ext/wrapper/ndga/ProblemWrapper.h
        python/ext/ndga_ext.cpp)

add_library(core SHARED ${PYTHON_API_CORE})
target_link_libraries(core ratatoskr_cc)
set_target_properties(core PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr PREFIX "")
#set_target_properties(core PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr SUFFIX ".pyd")

add_library(ndga SHARED ${PYTHON_API_NDGA})
target_link_libraries(ndga core)
set_target_properties(ndga PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr PREFIX "")
#set_target_properties(ndga PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/python/ratatoskr SUFFIX ".pyd")

add_custom_target(ratatoskr_py)
add_dependencies(ratatoskr_py core ndga)

set(UNIT_SOURCES
#        unit/core/util/TestBreedingOperator.cpp unit/core/util/TestBreedingOperator.h
        unit/core/util/SimpleBuilder.cpp unit/core/util/SimpleBuilder.h
        unit/core/util/SimpleFeatureMap.cpp unit/core/util/SimpleFeatureMap.h
        unit/core/util/SimpleIndividual.cpp unit/core/util/SimpleIndividual.h
        unit/core/util/SimpleProblem.cpp unit/core/util/SimpleProblem.h
        unit/core/util/SimpleSession.cpp unit/core/util/SimpleSession.h
#        unit/core/util/TestVariationSource.cpp unit/core/util/TestVariationSource.h
        unit/core/unit.cpp
#        unit/common.cpp
#        unit/ndga.cpp
        catch.hpp)

add_executable(unit ${UNIT_SOURCES})
target_link_libraries(unit ratatoskr_cc)





