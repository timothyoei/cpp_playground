#include "ch5.h"

void ch5() {
  // Constant variable cannot change values
  // Don't use const when passing by value -> copy destroyed anyway
  // Don't use const when returning by value
  // - fundamental types
  //  * ignored by compiler
  // - objects
  //  * destroyed anyway
  //  * can impede compiler optimizations involving move semantics

  // Prefer constant vars over preprocessor macros
  // - easy to mess up
  // - file-level scope regardless of where it's defined
  // - hard to debug
  const int sidesInSquare{4};

  // Volatile vars can change values at any time
  // - disables certain types of optimizations
  volatile int mayChange{5};

  // Default literal types
  // ===================================
  // 5, 0, -3 -> int
  // true, false -> bool
  // 1.2, 0.0, 3.4 -> double
  // 'a', '\n' -> char
  // "Hello, world!" -> const char[14] (C-style string)

  // Can change literal type by adding a literal suffix
  // - usually only F is used
  //  * compiler handles conversion for most other types but can generate narrowing warning
  // - suffixes often used in type deduction
  const float gravityOfEarth{9.8f};
  const double pi{3.14159};
  const double avogadro{6.02e23};
  const double electronCharge{1.6e-19};

  // Lower-case L can look like a 1 in some fonts
  const int sidesInCircle{0l};

  // C-style string literals
  // - implicit null terminator (i.e., '\0') used to determine end of string
  // - const objects created at program start and guaranteed to exist for entirety of program
  const char helloWorld[14] = "Hello, world!";

  // Binary literal -> 0b prefix
  const int twelveInBinary{0b1100}; // C++14

  // Octal literal -> 0 prefix
  const int twelveInOctal{014};

  // Hexadecimal literal -> 0x prefix
  const int twelveInHexadecimal{0xc};

  // Decimal literal -> default
  const int twelveInDecimal{12};

  // I/O manipulators change output format until another manipulator is applied
  std::cout << std::oct << twelveInOctal << '\n';
  std::cout << std::hex << twelveInHexadecimal << '\n';
  std::cout << std::dec << twelveInDecimal << '\n';
  // No binary I/O manipulator -> use below workarounds
  std::cout << std::format("{:b}\n", twelveInBinary);  // C++20, {:b} formats the argument as binary digits
  std::cout << std::format("{:#b}\n", twelveInBinary); // C++20, {:#b} formats the argument as 0b-prefixed binary digits
  std::println("{:b} {:#b}", twelveInBinary, twelveInBinary);  // C++23, format / print two arguments and a newline

  // Digit separaters -> purely visual
  const int oneMillion{1'000'000};

  // as-if rule: compiler can modify program in any way to (sometimes) optimize it as long as program's "observable behavior" is not affected
  // - exception: unnecessary calls to a copy constructor can be omitted even if those copy constructors have observable behavior

  // Compile-time evaluation: compiler can evaluate some expressions at compile-time rather than during runtime
  // - trades longer compilation time for shorter runtime / less memory
  // - needs optimization flag turned on
  // Compile-time constant: constant whose value must be known at compile-time (e.g., literals, constexpr vars, const integral vars, non-type template params, enumerators, etc)
  // Constant expression: expression containing only compile-time constants and operators / functions that support compile-time evaluation (e.g., arithmetic operators, constexpr / consteval functions, etc)
  // - constant expressions can always be evaluated at compile-time
  // - type AND value available at compile-time -> catch bugs faster
  // - certain C++ features require constant expressions (e.g., initializer of constexpr var, non-type template argument, defined length of a std::array)
  // - only required to be evaluated in contexts that require a constant expression (e.g., initializer of a compile-time constant) -> usually evaluated at compile-time
  // Runtime constant: non-compile-time constant (e.g., const non-integral vars, etc)
  // Runtime expression: non-constant expression (e.g., initialization with a non-const var, etc)
  // Runtime constants / expressions can still be optimized depending on how sophisticated the compiler / complex the code is
  // Constant expression examples
  const int isConstExpr{5 + 5}; // compile-time constant + constant expression: evaluated at compile time
  int isConstExpr2{1 + 1}; // runtime constant + constant expression: evaluated at either compile-time (if compiler is smart) or runtime
  const int notConstExpr{isConstExpr2}; // runtime constant + runtime expression: evaluated at either compile-time (if compiler is smart) or runtime
  int notConstExpr{isConstExpr2}; // runtime constant + runtime expression: evaluated at either compile-time (if compiler is smart) or runtime
  // Optimization can make programs harder to debug -> code no longer resembles source code / debugger can't find symbols that exist in source code but not in optimized code

  // constexpr vars are always compile-time constants and work for both integral / non-integral types
  // - prefer constexpr vars over const integral vars and magic numbers
  // - compile-time constants should be declared `constexpr` while runtime constants should be declared `const`
  // - some types are not compatible with `constexpr` (e.g., `std::string`, `std::vector`, etc) -> either use `const` or a different type that is `constexpr` compatible (e.g., `std::string_view`)
  // - `constexpr` object evaluated at either compile-time (usually) or runtime (e.g., function call initializing param with `constexpr` argument at runtime)
  // - `constexpr` is implicitly `const` but `const` is not implicitly `constexpr`

  // C-style string vars are hard to use
  // - no reassignment
  // - UB if assigning larger string to var previously storing smaller string

  // Prefer `std::string` over C-style string vars
  // - `std::string` initialization makes a copy of the initializing string -> copying strings is expensive, unlike fundamental types
  // - if `std::string` doesn't have enough memory to store a string, it requests more at runtime (dynamic memory allocation)
  // - avoid passing a `std::string` by value -> use `std::string_view` instead
  //   * function param initialized with copy of initializer
  // - avoid returning a `std::string` by value
  //   * can sometimes return `std::string` by (const) reference, avoiding a copy
  //   * can sometimes return `std::string` by value when return expression reolves to:
  //     * local variable of type `std::string`
  //     * `std::string` returned by value from another function call or operator
  //     * `std::string` temporary that is created as part of return statement
  // - `std::string` supports move semantics
  std::string name{"Timothy"};

  // Prefer '\n' over "\n" and `std::endl`;
  std::cout << name << '\n';

  // `>>` op stops at first non-leading whitespace in `std::cin`
  // - `std::getline()` gets whole line
  //  * if using `std::getline()`, also use `std::cin >> std::ws` to ignore leading whitespace (`std::ws` not preserved across calls)
  std::getline(std::cin >> std::ws, name);

  // `std::string::length()` (`size_t`) or `std::ssize` (`std::ptrdiff_t`) to get string length
  std::cout << name.length() << " " << std::ssize(name) << '\n';

  using namespace std::string_literals // s suffix
  // initializing `std::string` with C-style string literal is ok, but `std::string` literals can help type deduction (e.g., auto)
  name = "John"s // `std::string("John", 4)` <- excludes null-terminator

  // `std::string_view` read-only access to an existing string (e.g., C-style string, `std::string`, `std::string_view`) without making copies
  // - C-style strings and `std::string` implicitly convert to `std::string_view`, but not other way around
  // - prefer `std::string_view` over `std::string` when you need a read-only string, especially for function parameters
  std::string_view strView1{"Hello"}; // initialization with C-style string
  std::string_view strView2{"Hello\n"s}; // initialization with `std::string`
  std::string_view strView3{strView2}; // initialization `std::string_view`

  // C-style strings and `std::string` implicitly convert to `std::string_view`, but must explicitly convert `std::string_view` to `std::string`, either by initialization or `static_cast`
  std::string stdStrFromStrView{strView1};
  std::string stdStrFromStrView2{static_cast<std::string>(strView1)};

  // Assignment changes what `std::string_view` is viewing

  // Initialize with C-style string literals or `std::string_view` literal (uses C-style string under the hood)
  std::string_view strViewLit{"Hello\n"sv};

  // Support for `constexpr`
  constexpr std::string_view kStrView{"Hello again\n"};

  // If object being viewed is destroyed OR modified while view is still being used, UB results -> dangling view
  // - do not initialize `std::string_view` with `std::string` literal
  // - modifying a `std::string` invalides all views into that `std::string`
  {
    std::string s{"Hello"};
    std::string_view sv{s};

    s = "Hello again"; // sv invalidated
    sv = s; // sv revalidated
  }

  // Prefer `std::string_view` over `const std::string&` function params in most cases

  // If argument is a temporary that is destroyed at end of full expression containing function call, returned std::string_view must be used immediately, as it will be dangling afterward

  // Modify view of string
  // - must reassign view to source string to reset
  kStrView.remove_prefix(1); // "ello again"
  kStrView.remove_suffix(2); // ello aga"

  // C-style string literals / `std::string` always null-terminated while a `std::string_view` may or may not be null-terminated (e.g., after modifying view)
  // - usually doesn't matter -> can still convert `std::string_view` to `std::string`
  // - if a null-terminated string is needed, convert `std::string_view` to `std::string` 
}

int main() {
  ch5();
  return 0;
}
