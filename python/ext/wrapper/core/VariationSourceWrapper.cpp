#include "VariationSourceWrapper.h"

VariationSourceWrapper::VariationSourceWrapper(boost::shared_ptr<Session> session)
        : VariationSource(*session) {}

unsigned long VariationSourceWrapper::expectedSources() const {
    return this->get_override("expectedSources")();
}

std::vector<Individual *> VariationSourceWrapper::perform(std::vector<Individual *> &parents,
                                                          unsigned int epoch,
                                                          Thread &thread) const {
    return this->get_override("perform")(parents, epoch, thread);
}
