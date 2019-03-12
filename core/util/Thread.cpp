#include "Thread.h"

Thread::Thread() {
    generator = std::mt19937(std::random_device()());
}
