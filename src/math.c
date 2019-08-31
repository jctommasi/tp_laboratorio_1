/*
 * math.c
 *
 *  Created on: Aug 31, 2019
 *      Author: root
 */

int math_getIntNumbers(int* pNum1, int* pNum2)
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

int math_showOperations(int* pOperationNumber, int* pNum1, int* pNum2)
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
			"\n\n	Opcion: ",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2);
	scanf("%d", &operationNumber);

	if(operationNumber >= 1 && operationNumber <= 5)
	{
		*pOperationNumber = operationNumber;
		traceback = 0;
	}
	return traceback;
}

int math_intSuma(int* resultado,int num1, int num2)
{
	*resultado = num1 + num2;
	return 0;
}
int math_intResta(int* resultado,int num1, int num2)
{
	*resultado = num1 - num2;
	return 0;
}
int math_intMultiply(int* resultado,int num1, int num2)
{
	*resultado = num1 * num2;
	return 0;
}
int math_intDiv(int* resultado,int num1, int num2)
{
	*resultado = num1 / num2;
	return 0;
}
int math_intFactorial(int* factNum1,int* factNum2,int num1,int num2)
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

int math_executeOperationChoosed(int* poperationNumber, int num1, int num2, int* resultado, int* factNum1, int* factNum2)
{
	int operationNumber = *poperationNumber;

	if(operationNumber == 1)
	{
		math_intSuma(resultado,num1,num2);
		printf("El resultado de la suma entre %d + %d es: %d \n",num1,num2,*resultado);
	}
	if(operationNumber == 2)
	{
		math_intResta(resultado,num1,num2);
		printf("El resultado de la resta entre %d - %d es: %d \n",num1,num2,*resultado);
	}
	if(operationNumber == 3)
	{
		math_intMultiply(resultado,num1,num2);
		printf("El resultado de la multiplicacion entre %d * %d es: %d \n",num1,num2,*resultado);
	}
	if(operationNumber == 4)
	{
		if(num1 == 0 || num2 == 0)
		{
			printf("No se puede dividir por 0 \n");
		} else
		{
			math_intDiv(resultado,num1,num2);
			printf("El resultado de la division entre %d / %d es: %d \n",num1,num2,*resultado);
		}
	}
	if(operationNumber == 5)
	{
		math_intFactorial(factNum1,factNum2,num1,num2);
		printf("El factorial de %d es: %d y El factorial de %d es: %d \n",num1,*factNum1,num2,*factNum2);
	}
	return 0;
}
