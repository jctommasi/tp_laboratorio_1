/*
 ============================================================================
 Name        : calculat0r.c
 Author      : juan cruz tommasi
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getIntNumbers(int* pNum1, int* pNum2);
int showOperations(int* pOperationNumber, int* pNum1, int* pNum2);
int executeOperationChoosed(int* operationNumber, int num1, int num2, int* resultado, int* factNum1, int* factNum2);

int main(void) {
	int num1;
	int num2;
	int operationNumber;
	int resultado;
	int factNum1;
	int factNum2;

	getIntNumbers(&num1,&num2);
	showOperations(&operationNumber,&num1,&num2);
	executeOperationChoosed(&operationNumber, num1, num2, &resultado, &factNum1, &factNum2);

	return EXIT_SUCCESS;
}

int getIntNumbers(int* pNum1, int* pNum2)
{
	int num1;
	int num2;
	printf("Ingrese el primer operando: ");
	scanf("%d", &num1);
	printf("Ingrese el segundo operando: ");
	scanf("%d", &num2);
	*pNum1 = num1;
	*pNum2 = num2;

	return 0;
}

int showOperations(int* pOperationNumber, int* pNum1, int* pNum2)
{
	int operationNumber;
	int traceback = -1;
	int num1 = *pNum1;
	int num2 = *pNum2;

	printf("Que operacion desea realizar?\n"
			"\n		1. Suma (%d+%d)"
			"\n		2. Resta (%d-%d)"
			"\n		3. Multiplicacion (%d*%d)"
			"\n		4. Division (%d/%d)"
			"\n		5. Factoriales (%d! - %d!)"
			"\n\nOpcion: ",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2);
	scanf("%d", &operationNumber);

	if(operationNumber >= 1 && operationNumber <= 5)
	{
		*pOperationNumber = operationNumber;
		traceback = 0;
	}
	return traceback;
}

int intSuma(int* resultado,int num1, int num2)
{
	*resultado = num1 + num2;
	return 0;
}
int intResta(int* resultado,int num1, int num2)
{
	*resultado = num1 - num2;
	return 0;
}
int intMultiply(int* resultado,int num1, int num2)
{
	*resultado = num1 * num2;
	return 0;
}
int intDiv(int* resultado,int num1, int num2)
{
	*resultado = num1 / num2;
	return 0;
}
int intFactorial(int* factNum1,int* factNum2,int num1,int num2)
{
	int factorial1 = num1;
	int factorial2 = num2;
	int i;

	for(i=1; i<=num1; i++)
	{
	factorial1 = factorial1*i;
	}
	*factNum1 = factorial1;

	for(i=1; i<=num2; i++)
	{
	factorial2 = factorial2*i;
	}
	*factNum2 = factorial2;

	return 0;
}

int executeOperationChoosed(int* poperationNumber, int num1, int num2, int* resultado, int* factNum1, int* factNum2)
{
	int operationNumber = *poperationNumber;

	if(operationNumber == 1)
	{
		intSuma(resultado,num1,num2);
		printf("El resultado de la suma entre %d + %d es: %d",num1,num2,*resultado);
	}
	if(operationNumber == 2)
	{
		intResta(resultado,num1,num2);
		printf("El resultado de la resta entre %d - %d es: %d",num1,num2,*resultado);
	}
	if(operationNumber == 3)
	{
		intMultiply(resultado,num1,num2);
		printf("El resultado de la multiplicacion entre %d * %d es: %d",num1,num2,*resultado);
	}
	if(operationNumber == 4)
	{
		intDiv(resultado,num1,num2);
		printf("El resultado de la division entre %d / %d es: %d",num1,num2,*resultado);
	} else if (num1 == 0 || num2 == 0) {
		printf("No se puede dividir por 0");
	}
	if(operationNumber == 5)
	{
		intFactorial(factNum1,factNum2,num1,num2);
		printf("El factorial de %d es: %d y El factorial de %d es: %d",num1,*factNum1,num2,*factNum2);
	}
	return 0;
}
