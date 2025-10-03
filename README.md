# Online Library Management System (C++ OOP)

**Entities:** Book, User, Library  
**Features:** add/remove/search books; add/remove users; borrow/return with limits  
**Why OOP here?** Encapsulation of state, clear roles, and modular coordination.

## Build & Run (Windows + VS Code + MSYS2)
1. Ensure `C:\msys64\mingw64\bin` is in PATH (`g++ --version` works).
2. Open this folder in VS Code → **Ctrl+Shift+B** to build.
3. Run demo: `.\bin\app.exe`

## Test instructions
See `TESTING.md` for per-test build commands.

## Design choices
- **Encapsulation:** private fields; mutating actions exposed as methods.
- **Separation of concerns:** Book/User maintain invariants; Library orchestrates flows.
- **Safety:** cannot remove borrowed books; users have borrow limits; simple rollback in `borrowBook`.

## GitHub
Publish this folder to: `https://github.com/Quana254/online-library-management-system.git`
