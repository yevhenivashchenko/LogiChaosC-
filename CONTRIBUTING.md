# Contributing to LogiChaosC++

Thank you for your interest in contributing to LogiChaosC++! We believe that open-source software thrives on community collaboration. Whether you're fixing a bug, adding a new transformation algorithm, or improving documentation, your contributions are highly valued.

## How to Contribute

### 1. Reporting Issues
Before opening a new issue, please search the issue tracker to see if the problem has already been reported. If you find a new issue:
- Include a clear, descriptive title.
- Provide a detailed explanation of the problem.
- Include steps to reproduce the issue (if applicable).
- Mention your environment (OS, compiler, C++ standard).

### 2. Submitting Pull Requests
We encourage contributions via Pull Requests (PRs). Please follow these steps:
1. **Fork the repository** to your own GitHub account.
2. **Create a new branch** for your feature or fix: `git checkout -b feature/name-of-your-feature` or `git checkout -b fix/name-of-your-fix`.
3. **Write your code**, ensuring it adheres to our code style.
4. **Add tests** for any new features or bug fixes.
5. **Commit your changes** with descriptive messages.
6. **Push the branch** to your fork.
7. **Submit a Pull Request** against the `main` branch.

## Code Style & Standards

- **C++ Standard**: We follow C++17 or higher. Please utilize modern features (smart pointers, RAII, move semantics) to ensure safety and performance.
- **Formatting**: Keep code clean, readable, and well-commented.
- **Naming**: Use descriptive names for variables, classes, and functions.
- **Safety**: Since this is a data transformation library, ensure all transformations are binary-safe and deterministic.

## Development Environment

To compile the project, ensure you have:
- A C++17 compliant compiler (GCC, Clang, or MSVC).
- [CMake](https://cmake.org/) (minimum version 3.10).

## Code of Conduct

By participating in this project, you are expected to uphold our commitment to an inclusive, welcoming environment for all contributors.

---
*Questions? Feel free to open an issue or contact the maintainer directly.*
