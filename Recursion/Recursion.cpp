#include "Recursion.hpp"
#include <chrono>

#define RecordTimeSpent( Instruction ) \
{ \
	start = std::chrono::high_resolution_clock::now(); \
	Instruction; \
	finish = std::chrono::high_resolution_clock::now(); \
	elapsed = finish - start; \
	std::cout << "\nElapsed time: " << elapsed.count() << " s\n"; \
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;

	/**Head and Tail
	*Generally head and tail recursive have more space complexity than a loop
	*while(n)
	*{
	*	printf("%d ", n--);
	*}
	*Time complexity = O(n), Space complexity = O(1)
	*/
	std::cout << "HeadRecursion : ";
	RecordTimeSpent(HeadRecursion(3))

	std::cout << "\n\nHeadRecursion : ";
	RecordTimeSpent(TailRecursion(3))

	RecordTimeSpent(std::cout << "\n\nStaticVariableRecursion : " << StaticVariableRecursion(3))

	/**Formula for TreeRecursion
	*When given n, TreeRecursion will be called totally 2^0 + 2^1 + 2^2 + 2^3 ...... + 2^n
	*There has a formula 2^0 + 2^1 + 2^2 + 2^3 ...... + 2^n = 2^(n+1) - 1
	*So Time complexity = O(2^n)
	*
	*And when we calculate SX at tree recursion, we only consider it's Height
	*That's because cpu use same stack memory for same function with same variable
	*So Space complexity = O(n)
	*/
	std::cout << "\n\nTreeRecursion : ";
	RecordTimeSpent(TreeRecursion(3))

	std::cout << "\n\nIndirectA : ";
	RecordTimeSpent(IndirectA(3))

	RecordTimeSpent(std::cout << "\n\nNestedRecursion : " << NestedRecursion(95))
	
	// Time complexity = O(n), Space complexity = O(n)
	RecordTimeSpent(std::cout << "\n\nSumRecursion : " << SumRecursion(500))
	
	// Time complexity = O(n), Space complexity = O(1)
	RecordTimeSpent(std::cout << "\n\nSumIteration : " << SumIteration(500))
	
	// Time complexity = O(n), Space complexity = O(n) 
	RecordTimeSpent(std::cout << "\n\nFactorialRecursion : " << FactorialRecursion(500))
	
	// Time complexity = O(n), Space complexity = O(1)
	RecordTimeSpent(std::cout << "\n\nFactorialIteration : " << FactorialIteration(500))
	
	// Time complexity = O(n), Space complexity = O(n) 
	RecordTimeSpent(std::cout << "\n\nPowerRecursion1 : " << PowerRecursion1(4, 15))
	
	// Time complexity = O(n), Space complexity = O(n) 
	RecordTimeSpent(std::cout << "\n\nPowerRecursion2 : " << PowerRecursion2(4, 15))
	
	// Time complexity = O(n), Space complexity = O(n) 
	RecordTimeSpent(std::cout << "\n\nTaylorRecursion : " << TaylorRecursion(4, 25))
	
	// Time complexity = O(n), Space complexity = O(n) 
	RecordTimeSpent(std::cout << "\n\nTaylorHoner : " << TaylorHoner(4, 25))
	
	// Time complexity = O(n), Space complexity = O(1) 
	RecordTimeSpent(std::cout << "\n\nTaylorIteration : " << TaylorIteration(4, 25))
	
	// Time complexity = O(2^n), Space complexity = O(n) 
	RecordTimeSpent(std::cout << "\n\nFibonacciRecursion : " << FibonacciRecursion(20))
	
	// Time complexity = O(n), Space complexity = O(1)  
	RecordTimeSpent(std::cout << "\n\nFibonacciIteration : " << FibonacciIteration(20))
	
	/** Time complexity = O(n), Space complexity = O(n)
	*Fixed memory will be occupied for FibonacciMemorizeRecursion int F[20] for example
	*/
	RecordTimeSpent(std::cout << "\n\nFibonacciMemorizeRecursion : " << FibonacciMemorizeRecursion(20))
	
	// A famous test TowerHanoi
	RecordTimeSpent(std::cout << "\n\n"; TowerHanoi(4, 'A', 'B', 'C'))
}