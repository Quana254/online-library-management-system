# Test Plan & Commands

Build and run each test as its own executable:

## Book
"C:\msys64\mingw64\bin\g++.exe" -std=c++17 -O2 -Wall ^
  src\book.cpp tests\Tests_Book.cpp ^
  -o bin\test_book.exe
.\bin\test_book.exe

## User
"C:\msys64\mingw64\bin\g++.exe" -std=c++17 -O2 -Wall ^
  src\user.cpp tests\Tests_User.cpp ^
  -o bin\test_user.exe
.\bin\test_user.exe

## Library
"C:\msys64\mingw64\bin\g++.exe" -std=c++17 -O2 -Wall ^
  src\book.cpp src\user.cpp src\library.cpp tests\Tests_Library.cpp ^
  -o bin\test_library.exe
.\bin\test_library.exe

## Integration
"C:\msys64\mingw64\bin\g++.exe" -std=c++17 -O2 -Wall ^
  src\book.cpp src\user.cpp src\library.cpp tests\Tests_Integration.cpp ^
  -o bin\test_integration.exe
.\bin\test_integration.exe
