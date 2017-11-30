#ifndef RATATOSKR_CLONABLE_H
#define RATATOSKR_CLONABLE_H

/**
 * Represents the basic interface for all polymorphic classes in Ratatoskr.
 *
 * @author  Felix Voelker
 * @version 0.0.2
 * @since   11.10.2017
 */
class Clonable {

protected:
    Clonable(const Clonable &obj) = default;

public:
    explicit Clonable() = default;

    /**
     * Returns a copy of the calling object.
     */
    virtual Clonable * clone() const = 0;

};


#endif //RATATOSKR_CLONABLE_H
