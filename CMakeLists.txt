cmake_minimum_required(VERSION 3.5)
project(Ratatoskr)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

#find_package(PythonLibs 3 REQUIRED)
#find_package(Boost COMPONENTS python-py35 REQUIRED)

#include_directories(${PYTHON_INCLUDE_DIRS})
#include_directories(${BOOST_INCLUDEDIR} )

set(CORE_SOURCES
        core/representation/Builder.h
        core/representation/Genotype.h
        core/representation/VariationOperator.h
        core/util/Clonable.h)
        #core/Session.cpp core/Session.h)
        #core/evaluation/EvaluationFunction.h
        #core/evaluation/Evaluator.cpp core/evaluation/Evaluator.h
        #core/experience/EvolutionaryNetwork.cpp core/experience/EvolutionaryNetwork.h
        #core/experience/Replayer.cpp core/experience/Replayer.h
        #core/experience/ReplayMemory.cpp core/experience/ReplayMemory.h
        #core/initialization/Initializer.cpp core/initialization/Initializer.h
        #core/state/Individual.cpp core/state/Individual.h
        #core/state/Population.cpp core/state/Population.h
        #core/state/Relevance.cpp core/state/Relevance.h
        #core/statistics/Statistics.cpp core/statistics/Statistics.h
        #core/util/Thread.cpp core/util/Thread.h
        #core/variation/Breeder.cpp core/variation/Breeder.h
        #core/variation/BreedingOperator.cpp core/variation/BreedingOperator.h
        #core/variation/SelectionOperator.cpp core/variation/SelectionOperator.h
        #core/variation/VariationSource.cpp core/variation/VariationSource.h
        #core/EvolutionarySystem.cpp core/EvolutionarySystem.h
        #core/TerminationCondition.h)

set(CC_API
        cc/representation/Vector.cpp cc/representation/Vector.h)
#        cc/selection/FitnessProportionateSelection.cpp cc/selection/FitnessProportionateSelection.h
#        cc/common/TransitionTable.cpp cc/common/TransitionTable.h
#        cc/representation/vector/binary/BinaryVectorCrossover.cpp cc/representation/vector/binary/BinaryVectorCrossover.h
#        cc/representation/vector/binary/BinaryVectorMutation.cpp cc/representation/vector/binary/BinaryVectorMutation.h
#        cc/ndga/EvaluationFunctions.cpp cc/ndga/EvaluationFunctions.h
#        cc/representation/vector/binary/RandomBinaryVectorBuilder.cpp cc/representation/vector/binary/RandomBinaryVectorBuilder.h
#        cc/main.cpp core/representation/VariationOperator.h cc/representation/vector/Vector.cpp cc/representation/vector/Vector.h cc/algorithm/GeneticAlgorithm.cpp cc/algorithm/GeneticAlgorithm.h)

add_library(ratatoskr_cc SHARED ${CORE_SOURCES} ${CC_API})
#target_link_libraries(ratatoskr_cc ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

add_executable(ratatoskr_cc_debug main.cpp)
target_link_libraries(ratatoskr_cc_debug ratatoskr_cc)

#set(PYTHON_API_CORE
#        old/python/ext/wrapper/BreedingOperatorWrapper.cpp old/python/ext/wrapper/BreedingOperatorWrapper.h
#        old/python/ext/wrapper/BuilderWrapper.cpp old/python/ext/wrapper/BuilderWrapper.h
#        old/python/ext/wrapper/EvaluationFunctionWrapper.cpp old/python/ext/wrapper/EvaluationFunctionWrapper.h
#        old/python/ext/wrapper/FeatureMapWrapper.cpp old/python/ext/wrapper/FeatureMapWrapper.h
#        old/python/ext/wrapper/IndividualWrapper.cpp old/python/ext/wrapper/IndividualWrapper.h
#        old/python/ext/core.cpp old/python/ext/wrapper/RelevanceWrapper.cpp old/python/ext/wrapper/RelevanceWrapper.h
#        old/python/ext/wrapper/SelectionOperatorWrapper.cpp old/python/ext/wrapper/SelectionOperatorWrapper.h
#        old/python/ext/wrapper/VariationSourceWrapper.cpp old/python/ext/wrapper/VariationSourceWrapper.h)

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

#set(UNIT_SOURCES
#        old/unit/util/SimpleBreedingOperator.cpp old/unit/util/SimpleBreedingOperator.h
#        old/unit/util/SimpleBuilder.cpp old/unit/util/SimpleBuilder.h
#        old/unit/util/SimpleEvaluationFunction.cpp old/unit/util/SimpleEvaluationFunction.h
#        old/unit/util/SimpleEvolutionaryNetwork.cpp old/unit/util/SimpleEvolutionaryNetwork.h
#        old/unit/util/SimpleFeatureMap.cpp old/unit/util/SimpleFeatureMap.h
#        old/unit/util/SimpleIndividual.cpp old/unit/util/SimpleIndividual.h
#        old/unit/util/SimpleSelectionOperator.cpp old/unit/util/SimpleSelectionOperator.h
#        old/unit/util/SimpleVariationSource.cpp old/unit/util/SimpleVariationSource.h
#        old/unit/common.cpp
#        old/unit/core.cpp
#        old/unit/ndga.cpp
#        catch.hpp)

#add_executable(old/unit ${UNIT_SOURCES})
#target_link_libraries(old/unit ratatoskr_cc)





