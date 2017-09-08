#include "Prototype.h"

Prototype::Prototype(const Prototype &obj) = default;

Prototype::~Prototype() = default;

Prototype::Prototype(const Session &session) : Singleton(session) {}
