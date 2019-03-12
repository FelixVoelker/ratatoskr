#include <iostream>
#include "VariationOperator.h"

std::vector<Genotype *> VariationOperator::operator()(std::vector<Genotype *> &genotypes, Thread &thread) const {
    try {
        if (genotypes.size() == this->numParents()) {
            throw VariationOperatorException(VariationOperatorException::Type::PARENTS, genotypes.size(), this->numParents());
        }
        std::vector<Genotype *> offspring = this->vary(genotypes, thread);
        if (offspring.size() == this->numOffspring()) {
            throw VariationOperatorException(VariationOperatorException::Type::OFFSPRING, offspring.size(), this->numOffspring());
        }
        return offspring;
    } catch (VariationOperatorException &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

VariationOperatorException::VariationOperatorException(Type type, unsigned int given, unsigned int expected) {
    this->type = type;
    this->given = given;
    this->expected = expected;
}

const char* VariationOperatorException::what() const noexcept {
    std::string msg;
    if (type == VariationOperatorException::Type::PARENTS) {
        msg += "Number of given parents is " + std::to_string(given) + " but expected were " + std::to_string(expected) + ".";
    }
    if (type == VariationOperatorException::Type::OFFSPRING) {
        msg += "Number of returned offspring is " + std::to_string(given) + " but expected were " + std::to_string(expected) + ".";
    }
    return msg.c_str();
}