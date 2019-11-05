#pragma once
#include <iostream>

/**HeadRecursion
*Recursive function that call itself before perform instruction
*Time complexity = O(n)
*Space complexity = O(n)
*/
void HeadRecursion(int n)
{
	if (n > 0)
	{
		HeadRecursion(n - 1);
		std::cout << n << ' ';
	}
}

/**TailRecursion
*Recursive function that call itself after perform instruction
*Time complexity = O(n)
*Space complexity = O(n)
*/
void TailRecursion(int n)
{
	if (n > 0)
	{
		std::cout << n << ' ';
		TailRecursion(n - 1);
	}
}

/**StaticVariableRecursion
*A static variable at same function are shared.
*Means only one static variable, whatever how many function exists.
*/
int StaticVariableRecursion(int n)
{
	static int x = 0;
	if (n > 0)
	{
		x++;
		return StaticVariableRecursion(n - 1) + x;
	}
	return 0;
}

/**TreeRecursion
*If a recursive functionstatic call itself multiple times then it's tree recursion.
*Time complexity = O(2^n)
*Space complexity = O(n)
*/
void TreeRecursion(int n)
{
	if (n > 0)
	{
		std::cout << n << ' ';
		TreeRecursion(n - 1);
		TreeRecursion(n - 1);
	}
}

void IndirectB(int n);
/**IndirectRecursion
*A call B, B call C, C call D, ...... , ? call A
*A recursion didn't call itself, but eventually will go back to itself.
*/
void IndirectA(int n)
{
	if (n > 0)
	{
		std::cout << n << ' ';
		IndirectB(n - 1);
	}
}
void IndirectB(int n)
{
	if (n > 1)
	{
		std::cout << n << ' ';
		IndirectA(n / 2);
	}
}

/**NestedRecursion
*A function call itself and use itself as parameter
*/
int NestedRecursion(int n)
{
	if (n > 100)
		return n - 10;
	return NestedRecursion(NestedRecursion(n + 11));
}

int SumRecursion(int n)
{
	if (n == 0)
		return 0;
	return SumRecursion(n - 1) + n;
}

int SumIteration(int n)
{
	int s = 0, i;
	for (i = 1; i <= n; i++)
		s = s + i;

	return s;
}

//FactorialRecursion : n!
int FactorialRecursion(int n)
{
	if (n == 0)
		return 1;
	return FactorialRecursion(n - 1) * n;
}
int FactorialIteration(int n)
{
	int f = 1, i;
	for (i = 1; i <= n; i++)
		f = f * i;

	return f;
}

// m multiple itself n times
int PowerRecursion1(int m, int n)
{
	if (n == 0)
		return 1;
	return PowerRecursion1(m, n - 1) * m;
}

/**PowerRecursionPlus
*If power is even
*2^8 = 2^2 * 2^4, 3^16 = 3^2 * 3^8, so m^n = m^2 * m^(n/2)
*If power is odd
*2^9 = 2 * 2^2 * 2^4, 3^17 = 3 * 3^2 * 3^8, so m^n = m * m^2 * m^((n-1)/2)
*/
int PowerRecursion2(int m, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return PowerRecursion2(m * m, n / 2);
	return m * PowerRecursion2(m * m, (n - 1) / 2);
}

/**Taylor Formula
*1 + x/1 + x^2/2! + x^3/3! + ...... + x^n/n!
*/
double TaylorRecursion(int x, int n)
{
	static double p = 1, f = 1; // p is x^n, f is n!
	double r;

	if (n == 0)
		return 1;
	r = TaylorRecursion(x, n - 1);
	p = p * x;
	f = f * n;
	return r + p / f;
}

/**TaylorHoner
*Taylor recursion using Honer's rule
*1 + x/1 + x^2/2! + x^3/3! + ...... + x^n/n!
*Equal to
*1 + x/1[ 1+ x/2 [ 1 + x/3 [ 1 + x/4[......]]]
*/
double TaylorHoner(int x, int n)
{
	static double s = 1;
	if (n == 0)
		return s;
	s = 1 + x * s / n;
	return TaylorHoner(x, n - 1);
}

double TaylorIteration(int x, int n)
{
	static double s = 1;
	while (n > 0)
	{
		s = 1 + x * s / n--;
	}
	return s;
}

/**FibonacciRecursion
*Fibonacci(n) = Fibonacci(n - 2) + Fibonacci(n - 1);
*Time complexity is O(2^n), very terrible
*/
int FibonacciRecursion(int n)
{
	if (n <= 1)return n;
	return FibonacciRecursion(n - 2) + FibonacciRecursion(n - 1);
}

int FibonacciIteration(int n)
{
	int t0 = 0, t1 = 1, s = 0, i;

	if (n <= 1) return n;

	for (i = 2; i <= n; i++)
	{
		s = t0 + t1;
		t0 = t1;
		t1 = s;
	}

	return s;
}

/**FibonacciMemorizeRecursion
*Fibonacci(n) = Fibonacci(n - 2) + Fibonacci(n - 1);
*FibonacciMemorizeRecursion use special way to reduce down Time complexity
*Because in original recursion, same function with same value have been called severl times
*We could use memory to memorize the result of same function with same value
*Trade space into time
*Time complexity is O(n)
*/
int F[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int FibonacciMemorizeRecursion(int n)
{
	if (n <= 1)
	{
		F[n] = n;
		return n;
	}
	else
	{
		if (F[n - 2] == -1)
			F[n - 2] = FibonacciMemorizeRecursion(n - 2);
		if (F[n - 1] == -1)
			F[n - 1] = FibonacciMemorizeRecursion(n - 1);
		F[n] = F[n - 2] + F[n - 1];
		return F[n - 2] + F[n - 1];
	}
}

/**Tower of Hanoi
*How to derive it?
*It's simple after list all situation of TowerHanoi(1, A, B, C)、TowerHanoi(2, A, B, C)、TowerHanoi(3, A, B, C)
*
*First : TowerHanoi(1, A, B, C), Move 1 disk from A to C
*Step1. Move disk 1 from A to C
*
*Second : TowerHanoi(2, A, B, C), Move 2 disks from A to C
*Step1. Move disk 2 from A to B, and that equal to TowerHanoi(1, A, C, B)
*Step2. Move disk 1 from A to C
*Step3. Move disk 2 from B to C, and that equal to TowerHanoi(1, B, A, C)
*
*Third : TowerHanoi(3, A, B, C), Move 3 disks from A to C
*Step1. Move disk 3 from A to B, and that equal to TowerHanoi(2, A, C, B)
*Step2. Move disk 1 from A to C
*Step3. Move disk 3 from B to C, and that equal to TowerHanoi(2, B, A, C)
*/
void TowerHanoi(int n, char A, char B, char C)
{
	if (n > 0)
	{
		TowerHanoi(n - 1, A, C, B);
		std::cout << "Move " << n << " from " << A << " to " << C << std::endl;
		TowerHanoi(n - 1, B, A, C);
	}
}