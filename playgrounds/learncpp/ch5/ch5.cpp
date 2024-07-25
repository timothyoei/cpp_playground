#include "ch5.h"

void constants() {
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

  // C-style string
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
  std::cout << std::oct << twelveInOctal << "\n";
  std::cout << std::hex << twelveInHexadecimal << "\n";
  std::cout << std::dec << twelveInDecimal << "\n";
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
  // - prefer constexpr vars over const integral vars
  // - use constexpr vars instead of magic numbers
  // - compile-time constants should be declared constexpr while runtime constants should be declared const
  // - some types are not compatible with constexpr (e.g., std::string, std::vector, etc) -> either use const or a different type that is constexpr compatible
  // - constexpr object can be evaluated at runtime (sometimes) or compile-time (usually) <- very confusing I know
  //  * normal function calls initialize parameters at runtime -> compile-time constants treated as runtime constants
  // - const constexpr is redundant
}

int main() {
  constants();
  return 0;
}