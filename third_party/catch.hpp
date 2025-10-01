// third_party/catch.hpp
// Minimal test header compatible with the subset used in your project.
// Supports: CATCH_CONFIG_MAIN, TEST_CASE, SECTION, REQUIRE, REQUIRE_FALSE.
// Public domain / CC0 by <you>.

#ifndef MINI_CATCH_HPP
#define MINI_CATCH_HPP

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <exception>

namespace mini_catch {

// ---------- Assertion exception ----------
struct assertion_failure : public std::exception {
    std::string msg;
    explicit assertion_failure(std::string m) : msg(std::move(m)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

// ---------- Test registry ----------
struct TestCase {
    std::string name;
    std::function<void()> func;
};

inline std::vector<TestCase>& registry() {
    static std::vector<TestCase> r;
    return r;
}

struct Registrar {
    Registrar(const std::string& name, std::function<void()> func) {
        registry().push_back({name, std::move(func)});
    }
};

// ---------- Runner ----------
inline int run_all() {
    int failed = 0;
    int passed = 0;

    std::cout << "[mini-catch] Running " << registry().size() << " test(s)\n";
    for (const auto& t : registry()) {
        std::cout << "-> " << t.name << " ... ";
        try {
            t.func();
            std::cout << "OK\n";
            ++passed;
        } catch (const assertion_failure& e) {
            std::cout << "FAIL\n";
            std::cerr << "   Assertion failed: " << e.what() << "\n";
            ++failed;
        } catch (const std::exception& e) {
            std::cout << "ERROR\n";
            std::cerr << "   Uncaught std::exception: " << e.what() << "\n";
            ++failed;
        } catch (...) {
            std::cout << "ERROR\n";
            std::cerr << "   Unknown exception\n";
            ++failed;
        }
    }
    std::cout << "\nSummary: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}

} // namespace mini_catch

// ---------- Macros (Catch-like) ----------

// Define main if requested
#ifdef CATCH_CONFIG_MAIN
int main() { return ::mini_catch::run_all(); }
#endif

// Create a unique identifier helper
#define MC_UNIQUE_NAME2(x, y) x##y
#define MC_UNIQUE_NAME(x, y) MC_UNIQUE_NAME2(x, y)
#define MC_ANON MC_UNIQUE_NAME(_mc_sym_, __LINE__)

// TEST_CASE("name")
#define TEST_CASE(name) \
    static void MC_ANON(); \
    static ::mini_catch::Registrar MC_UNIQUE_NAME(_mc_reg_, __LINE__){name, MC_ANON}; \
    static void MC_ANON()

// SECTION("name")
// (simple one-shot scope; not full Catch2 branching semantics)
#define SECTION(name) for (int MC_ANON = 0; MC_ANON < 1; ++MC_ANON)

// REQUIRE(expr) — stops current test on failure
#define REQUIRE(expr) \
    do { \
        if (!(expr)) { \
            throw ::mini_catch::assertion_failure( \
                std::string(#expr) + " at " + __FILE__ + ":" + std::to_string(__LINE__)); \
        } \
    } while (0)

// REQUIRE_FALSE(expr)
#define REQUIRE_FALSE(expr) REQUIRE(!(expr))

#endif // MINI_CATCH_HPP
