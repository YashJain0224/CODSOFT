#include <iostream>
using namespace std;

int main() {

  char operatorSymbol;
  float operand1, operand2;

  cout << "Enter operator: +, -, *, /: ";
  cin >> operatorSymbol;

  cout << "Enter two operands: ";
  cin >> operand1 >> operand2;

  switch(operatorSymbol) {

    case '+':
      cout << operand1 << " + " << operand2 << " = " << operand1 + operand2;
      break;

    case '-':
      cout << operand1 << " - " << operand2 << " = " << operand1 - operand2;
      break;

    case '*':
      cout << operand1 << " * " << operand2 << " = " << operand1 * operand2;
      break;

    case '/':
      if (operand2 != 0) {
        cout << operand1 << " / " << operand2 << " = " << operand1 / operand2;
      } else {
        cout << "Error! Division by zero is not allowed";
      }
      break;

    default:
      // If the operator is other than +, -, * or /, an error message is shown
      cout << "Error! Operator is not correct";
      break;
  }

  return 0;
}
