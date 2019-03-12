

#include <iostream>
#include "../core/util/Thread.h"
#include "../core/util/RandomChoice.h"

int main() {
    auto thread = Thread();
    std::vector<int> choices = RandomChoice::sample(0, 10, thread, 10);
    for (unsigned int k = 0; k < choices.size(); k++) {
        std::cout << std::to_string(choices.at(k)) << std::endl;
    }
    return 0;
}