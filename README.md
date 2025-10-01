# online-library-management-system
C++ app to test cpp concepts 

# Online Library (C++ OOP)

A simple object-oriented library manager in **C++17**.

## Design
- **Book**: encapsulates id, title, author, genre, year, and availability; exposes `borrow()` / `giveBack()`.
- **User**: encapsulates id, name, and a set of borrowed book IDs; enforces a **borrow limit**.
- **Library**: hides storage (`unordered_map`); provides APIs: add/remove/search, borrow/return.
- **Status** enum: clear success/failure codes instead of raw booleans.

### OOP Principles
- **Encapsulation**: internal fields are private; only methods expose behavior.
- **Abstraction**: consumers use `Library` API; they don’t know about the underlying containers.
- **Single Responsibility**: each class manages its own concern.
- **Extensible**: easy to add reservations, fines, or persistence later.

## Build (CMake)
```bash
mkdir build && cd build
cmake ..
cmake --build .

