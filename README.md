# 🌌 Nova-Art: Roman Urdu to C++ Transpiler

![Version](https://img.shields.io/badge/version-1.0-blue)
![Build](https://img.shields.io/badge/build-passing-brightgreen)

**Nova-Art** is a custom systems-programming tool that transforms **Roman Urdu** scripts into optimized, executable **C++ code**. By bridging the gap between native language expression and high-performance computing, Nova-Art makes programming more accessible and intuitive.

---

## 🛠 Project Status: End-to-End Pipeline Ready 🚀

We have successfully moved beyond lexical analysis. The engine now features a complete "source-to-binary" pipeline.

### ✅ Completed Milestones:

* **Lexer (Scanner):** Full tokenization of Urdu keywords, literals, and operators.
* **Recursive Descent Parser:** Hierarchical structuring of code into an **Abstract Syntax Tree (AST)**.
* **Transpiler:** Context-aware conversion of AST nodes into C++17 source code.
* **Automation Engine:** Integrated "one-click" compilation that invokes `g++` and runs the resulting binary automatically.

---

## ✍️ Language Features & Vocabulary

| Nova-Art Keyword | C++ Equivalent | Purpose |
| --- | --- | --- |
| `rakho` | `auto` | Variable declaration and assignment |
| `farmao` | `std::cout` | Output/Print to console |
| `pocho` | `std::cin` | User input (Type-safe) |
| `agar` | `if` | Conditional logic (Coming Soon) |
| `jabtak` | `while` | Iterative loops (Coming Soon) |

---

## 📊 Capabilities & Limitations

To ensure a smooth developer experience, please note the current scope of the Nova-Art engine:

### 🌟 What you CAN do:

* **Declare Variables:** Use `rakho name = 10`.
* **Standard Output:** Print strings and variables using `farmao`.
* **User Interaction:** Accept terminal input via `pocho`.
* **Auto-Compile:** The tool automatically creates an `output.cpp` and compiles it into `app.exe`.
* **Case Insensitivity:** Keywords like `Farmao`, `farmao`, and `FARMAO` are all recognized.

### ⚠️ What you CANNOT do (Current Version):

* **Complex Math:** Multi-step expressions (e.g., `rakho x = 10 + 5 * 2`) are currently being refined.
* **Custom Functions:** All code currently lives within the `main()` scope.
* **Error Recovery:** If a syntax error is found, the transpiler reports it but does not attempt to "fix" the code for compilation.

---

## 🚀 The Updated Roadmap

With the core pipeline built, our next sprint focuses on **Turing Completeness**:

1. **Phase 4: Logic Gates:** Implementing `agar` (if) and `warna` (else) nodes in the AST.
2. **Phase 5: Loops:** Adding `jabtak` (while) for repetitive tasks.
3. **Phase 6: Expression Parsing:** Upgrading the parser to handle complex mathematical formulas using the Shunting-yard algorithm or recursive precedence.

---

## 🔨 How to Use

1. **Write your Nova-Art script** (e.g., `tests/hello.nova`):
```urdu
farmao "Apna naam likhen:"
rakho naam = ""
pocho naam
farmao "Khushamdeed!"
farmao naam

```


2. **Run the Transpiler:**
```bash
./build/Nova-Art tests/hello.nova

```


3. **Result:** The engine will generate `output.cpp`, compile it, and launch your program instantly.

---

## 💻 Technical Stack

* **Language:** C++17
* **Build System:** CMake
* **Compiler Requirements:** MinGW-w64 (g++) or Clang.
* **Architecture:** Abstract Syntax Tree (AST) with Unique Pointer ownership.

---