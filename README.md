# CLI Calculator Engine

## 📖 Project Overview

**CLI_CALCULATOR_ENGINE** is a robust Command-Line Interface calculator application written in C++. This project demonstrates object-oriented programming principles, modular code structure, input validation, and exception handling. It serves as a practical implementation of a console-based calculator with a user-friendly menu system and error-resistant input processing.

---

## 📁 Project Structure

```
CLI_CALCULATOR_ENGINE/
├── include/
│   ├── calculator.h      # Calculator class declaration
│   ├── input.h           # Input validation function declaration
│   └── menu.h            # Menu display function declaration
├── src/
│   ├── calculator.cpp    # Calculator class implementation
│   ├── input.cpp         # Input validation implementation
│   ├── menu.cpp          # Menu display implementation
│   └── main.cpp          # Main program logic
├── build/                # Compiled object files and executable
├── makefile              # Build automation
└── app.exe               # Compiled executable (Windows)
```

## 📋 Header Files

### `include/calculator.h`
```cpp
#ifndef CALCULATOR_H
#define CALCULATOR_H

class calculator {
public:
    int add(int a, int b);
    int sub(int a, int b);
    int divide(int a, int b);
    int multiply(int a, int b);
    int remainder(int a, int b);
};

#endif
```

### `include/input.h`
```cpp
#ifndef INPUT_H
#define INPUT_H

#include <string>
using namespace std;

int getValidInput(const string& prompt);

#endif
```

### `include/menu.h`
```cpp
#ifndef MENU_H
#define MENU_H

void print();

#endif
```

## 📝 Source Files

### `src/main.cpp`
```cpp
#include <iostream>
#include <exception>
#include "../include/calculator.h"
#include "../include/menu.h"
#include "../include/input.h"
using namespace std;

int main() {
    calculator calc;
    
    while (true) {
        print();
        int choice = getValidInput("Enter calculation choice : ");
        
        if (choice == 0) {
            cout << " ======= Exiting calculator ======= \n ";
            break;
        }
        
        if (choice < 0 || choice > 5) {
            cout << "❌ Invalid menu choice. Try again.\n";
            continue;
        }

        int a = getValidInput("Enter the value of a : ");
        int b = getValidInput("Enter the value of b : ");
        bool success = false;
        
        while (!success) {
            try {
                switch (choice) {
                    case 1:
                        cout << "Result == " << calc.add(a, b) << endl; 
                        success = true;
                        break;
                    case 2:
                        cout << "Result == " << calc.sub(a, b) << endl; 
                        success = true;
                        break;
                    case 3:
                        cout << "Result == " << calc.multiply(a, b) << endl;
                        success = true; 
                        break;
                    case 4:
                        cout << "Result == " << calc.divide(a, b) << endl; 
                        success = true;
                        break;
                    case 5:
                        cout << "Result == " << calc.remainder(a, b) << endl; 
                        success = true;
                        break;
                }
            }
            catch (const exception& e) {
                cout << "⚠️  Error: " << e.what() << endl;
                cout << "Re-enter the values : " << endl;

                a = getValidInput("Enter the value of a : ");
                b = getValidInput("Enter the value of b : ");
            }
        }
    }

    return 0;
}
```

### `src/input.cpp`
```cpp
#include <iostream>
#include "../include/input.h"
using namespace std;

int getValidInput(const string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        cin >> x;
        if (!cin.fail())
            return x;
        
        cout << "Enter valid input " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
```

### `src/menu.cpp`
```cpp
#include <iostream>
#include "../include/menu.h"

using namespace std;

void print() {
    cout << endl << "========= Calculator Menu ==========" << endl;
    cout << "1. Addition " << endl;
    cout << "2. Subtraction " << endl;
    cout << "3. Multiplication " << endl;
    cout << "4. Division " << endl;
    cout << "5. Remainder " << endl;
    cout << "0. Exit " << endl;
}
```

## 🔧 Build Instructions

### Using Makefile
1. Navigate to the project directory
2. Run `make` to compile the project
3. Execute the program with `./app.exe` (Windows) or `./app` (Linux/Mac)

### Manual Compilation
```bash
g++ -c src/calculator.cpp -o build/calculator.o
g++ -c src/input.cpp -o build/input.o
g++ -c src/menu.cpp -o build/menu.o
g++ -c src/main.cpp -o build/main.o
g++ build/*.o -o app.exe
```

## 📊 Features

### 1. **Modular Architecture**
- Separated header and implementation files
- Clean separation of concerns (input, calculation, display)
- Easy to extend with new operations

### 2. **Robust Input Validation**
- `getValidInput()` function handles invalid data types
- Prevents program crashes from bad input
- Clears input buffer after failures

### 3. **Comprehensive Error Handling**
- Exception handling for mathematical errors
- Graceful recovery from division by zero
- User-friendly error messages

### 4. **Mathematical Operations**
- **Addition**: Sum of two integers
- **Subtraction**: Difference between two integers
- **Multiplication**: Product of two integers
- **Division**: Integer division with error handling
- **Remainder**: Modulo operation

### 5. **User Experience**
- Clear, formatted menu interface
- Continuous operation until explicit exit
- Immediate feedback for invalid choices

## 🎯 Usage Example

```
========= Calculator Menu ==========
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Remainder
0. Exit

Enter calculation choice : 4
Enter the value of a : 10
Enter the value of b : 2
Result == 5

========= Calculator Menu ==========
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Remainder
0. Exit

Enter calculation choice : 4
Enter the value of a : 10
Enter the value of b : 0
⚠️  Error: Division by zero!
Re-enter the values : 
Enter the value of a : 10
Enter the value of b : 3
Result == 3
```

## 🛠️ Technical Implementation Details

### Design Patterns
- **Modular Programming**: Each component (calculator, input, menu) is isolated
- **Separation of Concerns**: Clear division between UI, logic, and data handling
- **Encapsulation**: Calculator operations are bundled in a class

### Memory Management
- Stack-based allocation for simplicity
- Proper input stream management with `cin.clear()` and `cin.ignore()`
- No dynamic memory allocation required

### Compilation
- Compatible with standard C++11 and above
- Uses header guards to prevent multiple inclusions
- Organized build process with object files

## ⚠️ Limitations & Known Issues

1. **Integer Only**: Currently supports only integer operations
2. **No History**: Calculations aren't stored for future reference
3. **Basic Operations**: Limited to five fundamental operations
4. **Console Only**: No graphical interface available

## 🔄 Future Enhancements

### Planned Features
1. **Floating-point Support**: Add `double` and `float` operations
2. **Extended Operations**: 
   - Power/exponentiation
   - Square roots
   - Trigonometric functions
   - Logarithmic operations
3. **Calculation History**:
   - Store previous calculations
   - Recall and reuse results
   - Export to file
4. **Advanced UI**:
   - Color-coded output
   - Progress indicators
   - Batch operation mode
5. **Configuration Options**:
   - Precision settings
   - Number formatting
   - Theme customization
6. **Testing Suite**:
   - Unit tests for each operation
   - Integration tests
   - Performance benchmarks

### Technical Improvements
1. **Template Support**: Generic operations for different numeric types
2. **Multi-threading**: Parallel computation for complex operations
3. **Plugin Architecture**: Loadable operation modules
4. **Cross-platform GUI**: Using frameworks like Qt or NCurses
5. **Web Interface**: REST API for remote calculations

## 🧪 Testing & Quality Assurance

### Recommended Testing Strategy
```bash
# Compile with debugging symbols
g++ -g -o test_app src/*.cpp -Iinclude

# Run valgrind for memory leaks
valgrind --leak-check=full ./test_app

# Create unit tests for each component
# Example test cases:
# - Division by zero handling
# - Large number calculations
# - Negative number operations
# - Input validation edge cases
```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Code Standards
- Follow C++ Core Guidelines
- Use meaningful variable names
- Add comments for complex logic
- Include error handling for all operations

## 📝 License & Credits

This project is open-source and available for educational and personal use. Feel free to modify, extend, and distribute with proper attribution.

---

## 👨‍💻 Author

**Deep Lukhi**  
DSA Enthusiast | C++ Developer | SDE Intern Aspirant  
GitHub: https://github.com/deeplukhi

### About the Author
Deep is a passionate programmer with strong interest in Data Structures, Algorithms, and System Design. This project demonstrates practical application of OOP concepts, modular programming, and robust error handling in C++. The CLI Calculator Engine serves as a foundation for more complex computational tools and showcases industry-standard coding practices.

Connect for collaborations, internship opportunities, or technical discussions!

---

*Note: This project is maintained as part of a portfolio to demonstrate C++ programming skills and software engineering principles. The modular architecture allows for easy extension and serves as a template for larger command-line applications.*
