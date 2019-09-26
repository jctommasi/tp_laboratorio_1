/*
 * global.h
 *
 *  Created on: Aug 31, 2019
 *      Author: root
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

void stuff_clearScreen();
void stuff_displayBanner();
int math_getIntNumbers(int* pNum1, int* pNum2);
int math_showOperations(int* pOperationNumber, int* pNum1, int* pNum2);
int math_intSuma(int* resultado,int num1, int num2);
int math_intResta(int* resultado,int num1, int num2);
int math_intMultiply(int* resultado,int num1, int num2);
int math_intDiv(int* resultado,int num1, int num2);
int math_intFactorial(int* factNum1,int* factNum2,int num1,int num2);
int math_executeOperationChoosed(int* poperationNumber, int num1, int num2, int* resultado, int* factNum1, int* factNum2);

#endif /* GLOBAL_H_ */
