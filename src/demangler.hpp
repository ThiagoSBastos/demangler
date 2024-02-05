#include <cxxabi.h>
#include <cstdlib>
#include <stdexcept>

// Based on https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a01696.html
class MangledType {
public:
    explicit MangledType(const char* mytype) {
        int status;
        realName = abi::__cxa_demangle(mytype, nullptr, nullptr, &status);
        switch (status) {
            case 0:
                break;
            case -1:
                throw std::runtime_error("Memory allocation failure occurred");
            case -2:
                throw std::runtime_error("The mangled name is not a valid name under the C++ ABI mangling rules");
            case -3:
                throw std::runtime_error("MangledType class assumptions are not valid");
        }
    }
    ~MangledType() { std::free(realName); }
    MangledType& operator=(MangledType const&) = default;
    MangledType(MangledType&) = default;
    MangledType& operator=(MangledType&&) = default;
    MangledType(MangledType&&) = default;

    inline const char* getDemangledName() { return realName; }
private:
    char* realName = nullptr;
};
