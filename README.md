
# Calculator Application

## Overview

The **Calculator Application** is a robust and efficient software program written in C, designed to parse and compute mathematical expressions. It supports basic arithmetic operations including addition, subtraction, multiplication, and division, while providing detailed error handling for syntax and mathematical issues.

![Simple Calculator Logo](https://github.com/user-attachments/assets/68c27d8a-943d-41a6-90c6-826b3b76c1c8)


## Features

- **Error Handling:**
  - Detects syntax errors in the input expression.
  - Identifies mathematical errors such as division by zero.
- **Arithmetic Operations:**
  - Supports `+`, `-`, `*`, and `/`.
  - Handles operations with negative numbers.
- **Expression Parsing:**
  - Dynamically calculates results based on operator precedence.
  - Updates expressions with intermediate results for multi-step calculations.
- **LCD Display Integration:**
  - Displays results or error messages on an LCD screen.

## Project Structure

- **Core Functions:**
  - `Calculator_VOIDOperationCalculation`: Handles individual arithmetic operations.
  - `Calculator_VOIDCalculation`: Manages the overall calculation process, including error detection and result display.
- **Supporting Utilities:**
  - `Calculator_VOIDGetNumberBefore`: Extracts the operand before the operator.
  - `Calculator_VOIDGetNumberAfter`: Extracts the operand after the operator.
  - `Calculator_U8OperationsOrder`: Determines the precedence and order of operations in the expression.
## Hardware Components
- **Microcontroller**: ATmega32
- **Input**: 4x4 Keypad
- **Output**: 16x2 LCD Display

## Software Details
- **Development Environment**: Eclipse IDE
- **Programming Language**: C
- **Libraries Used**:
  - Custom Hardware Abstraction Layer (HAL) for LCD and Keypad.
  - Standard Types Library for data type definitions.

## System Overview
### Modules
1. **Keypad Interface**: Captures user input.
2. **LCD Interface**: Displays input and results.
3. **Calculator Core**:
    - Validates expressions.
    - Determines operation precedence.
    - Performs calculations.

### Workflow
1. User enters a mathematical expression via the keypad.
2. The system validates the input for errors.
3. If the input is valid, the calculation module processes the expression.
4. The result is displayed on the LCD.

## How to Use
1. Power on the system.
2. Enter a mathematical expression using the keypad.
3. Press the '=' button to display the result.
4. If an error occurs, the system will display an appropriate message:
   - **SYNTAX ERROR!** for invalid input.
   - **MATH ERROR!** for operations like division by zero.


## Examples

- **Valid Input:**
  - Input: `3+5*2=`
  - Output: `13`
- **Invalid Input:**
  - Input: `3/0=`
  - Output: `MATH ERROR!`

## Development Environment

- **Programming Language:** C
- **Tools:** GCC, Makefiles, Eclipse IDE 
- **Optional Hardware:** LCD display , 4x4 KeyPad

## Contribution

Contributions are welcome! Feel free to submit issues, suggestions, or pull requests.

---

### Author

Developed by Omar Khedr, Ali Ashraf

### Test Results

You can view videos of the tests conducted for this project by clicking the link below:

[View Test Results](https://drive.google.com/drive/folders/1W4v_Gg-ppcrGGjJwUcFnKIVeQfmbgzZM?usp=sharing)
