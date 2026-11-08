#include "core/core.hpp"

namespace core {

std::string greet(std::string_view name) {
    return "Hello, " + std::string(name) + "!";
}

} // namespace core
