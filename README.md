# 🌌 Nova-Art: Roman Urdu to C++ Transpiler

**Nova-Art** is a custom systems-tool designed to bridge the gap between native language expression and C++ programming. It allows users to write logic in **Roman Urdu**, which is then analyzed, structured into an Abstract Syntax Tree (AST), and transpiled into optimized C++ code.

---

## 🛠 Project Status: Lexical Analysis Phase Complete ✅

We have successfully implemented the **Lexer (Scanner)**. The engine can now tokenize raw Roman Urdu scripts, distinguishing between keywords, identifiers, strings, and operators.

### Current Capabilities:

* **Tokenization:** Full support for vocabulary including `rakho`, `farmao`, and `pocho`.
* **String Handling:** Robust string literal extraction (e.g., `"Hello World!"`).
* **Identifier Management:** Case-insensitive recognition of variable names.
* **Numeric Scanning:** Support for integer and decimal literals.

---

## ✍️ Vocabulary & Syntax

| Nova-Art Keyword | C++ Equivalent | Purpose |
| --- | --- | --- |
| `rakho` | `auto` / `int` | Variable declaration and assignment |
| `farmao` | `std::cout` | Output/Print to console |
| `pocho` | `std::cin` | User input |
| `agar` | `if` | Conditional branch |
| `warna` | `else` | Alternative branch |
| `jabtak` | `while` | Loop construct |

---

## 🚀 The Roadmap (Next Steps)

The project is moving into the **Structural Analysis** phase. Our upcoming goals are:

1. **Phase 2: The Parser (In Progress):** * Implementation of a **Recursive Descent Parser**.
* Converting the token stream into a hierarchical **Abstract Syntax Tree (AST)**.


2. **Phase 3: Code Generation:**
* Designing the "Visitor" logic to walk the AST.
* Outputting standard C++17 source files.


3. **Phase 4: Automation:**
* Creating a "One-Click" build system that transpiles and compiles the `.nova` file into a runnable `.exe` using `g++`.



---

## 💻 Technical Stack

* **Language:** C++17
* **Build System:** CMake
* **Architecture:** AST-based Transpilation
* **Developer:** Solo Sprint (2-Week Timeline)

## 🔨 How to Build (Current Version)

```bash
# Generate build files
cmake -S . -B build

# Compile the project
cmake --build build

# Run the Lexer test
./build/Nova-Art tests/hello.nova

```

---