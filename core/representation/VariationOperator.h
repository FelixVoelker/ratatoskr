#ifndef RATATOSKR_VARIATIONOPERATOR_H
#define RATATOSKR_VARIATIONOPERATOR_H


#include <vector>
#include "../util/Thread.h"
#include "Genotype.h"

/**
 * The abstract base class for any variation operator of an individual's genotype. This functor is called during the
 * variation phase of an evolutionary algorithm and works on the genetic level, i.e. on the given individuals.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   12.10.2018
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
	 * @param parents A list of genotypes to serve as parents.
	 * @param thread  The variating thread.
	 */
	virtual std::vector<Genotype *> operator()(std::vector<Genotype *> &parents, Thread &thread) const = 0;

};


#endif //RATATOSKR_VARIATIONOPERATOR_H
