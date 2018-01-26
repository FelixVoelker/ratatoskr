#ifndef RATATOSKR_CLONABLE_H
#define RATATOSKR_CLONABLE_H


/**
 * Represents the interface for all polymorphic classes.
 *
 * @author  Felix Voelker
 * @version 0.1.1
 * @since   26.1.2018
 */
class Clonable {

public:
    explicit Clonable() = default;

    /**
     * Returns a copy of the calling object.
     */
    virtual Clonable * clone() const = 0;

protected:
    Clonable(const Clonable &obj) = default;

};


#endif //RATATOSKR_CLONABLE_H
