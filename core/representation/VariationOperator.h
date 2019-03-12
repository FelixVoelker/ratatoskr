#ifndef RATATOSKR_VARIATIONOPERATOR_H
#define RATATOSKR_VARIATIONOPERATOR_H


#include <vector>
#include "../util/Thread.h"
#include "Genotype.h"

/**
 * The abstract base class for any variation operator of an individual's genotype. This functor is called during the
 * variation phase of an evolutionary algorithm and thus works on the genetic level.
 * TODO: Check parent, offspring, genotypes naming
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   5.3.2019
 */
class VariationOperator : public Clonable {

public:
	/**
	 * Returns the number of parents that the operator expects.
	 */
	virtual unsigned int numParents() const = 0;

	/**
	 * Returns the number of offspring that the operator produces.
	 */
	virtual unsigned int numOffspring() const = 0;

	/**
	 * Breeds new offspring from the given parent genotypes according to the operator's strategy.
	 * @param genotypes List of genotypes to serve as parents.
	 * @param thread  The varying thread.
	 * @throws VariationOperatorException
	 */
	std::vector<Genotype *> operator()(std::vector<Genotype *> &genotypes, Thread &thread) const;

protected:
	/**
	 * Actual breeding procedure to be implemented.
	 * @param genotypes List of genotypes to serve as parents.
	 * @param thread The varying thread.
	 */
    virtual std::vector<Genotype *> vary (std::vector<Genotype *> &genotypes, Thread &thread) const = 0;

};

/**
 * This exception is used to indicate improper use of VariationOperator.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   5.3.2019
 */
class VariationOperatorException : public std::exception {

public:
    enum Type { PARENTS, OFFSPRING };

	VariationOperatorException(Type type, unsigned int given, unsigned expected);

    const char* what() const noexcept override;

private:
	Type type;
	unsigned int given;
	unsigned int expected;

};


#endif //RATATOSKR_VARIATIONOPERATOR_H
