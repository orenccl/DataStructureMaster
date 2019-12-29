#include <iostream>

class Array
{
private:
	int* m_Array;
	unsigned int m_Size;
	unsigned int m_DataLength;

	void Swap(int& x, int& y);

public:
	Array()
		: m_Size(10), m_DataLength(0)
	{
		std::cout << "\nArray created!\n";
		m_Array = new int[m_Size];
		memset(m_Array, 0, sizeof(m_Array));
	}

	Array(unsigned int sz)
		: m_Size(sz), m_DataLength(0)
	{
		std::cout << "\nArray created with size " << sz << " !" << '\n';
		m_Array = new int[m_Size];
		memset(m_Array, 0, m_Size * sizeof(*m_Array));
	}

	~Array()
	{
		std::cout << "\nArray deleted!\n";
		delete[]m_Array;
	}

	void Display();
	void Append(int x);
	void Insert(unsigned int index, int x);
	int Delete(unsigned int index);
	int LinearSearch(int key);
	int BinarySearch(int key);
	int Get(unsigned int index);
	 int Set(unsigned int index, int x);
	int Max();
	int Min();
	int Sum();
	float Avg();
	void Reverse();
	void Reverse2();
	void InsertSort(int x);
	bool isSorted();
	void Rearrange();
	Array* Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Diff(Array arr2);
	Array* Inter(Array arr2);
};

void Array::Swap(int& x, int& y)
{
	int temp = y;
	y = x;
	x = temp;
}

void Array::Display()
{
	std::cout << "\nArray Size: "<< m_Size << ", Length: " << m_DataLength << '\n';

	for (unsigned int i = 0; i < m_DataLength; i++)
	{
		if((i%10) == 0)
			std::cout << '\n';
		std::cout << m_Array[i] << ' ';
	}
}

void Array::Append(int x)
{
	if (m_DataLength < m_Size)
		m_Array[m_DataLength++] = x;
}

void Array::Insert(unsigned int index, int x)
{
	if (index < m_DataLength)
	{
		if (m_DataLength == m_Size)
			return;

		for (unsigned int i = m_DataLength; i > index; i--)
			m_Array[i] = m_Array[i - 1];
		m_Array[index] = x;
		m_DataLength++;
		return;
	}

	if (index < m_Size)
	{
		m_DataLength = index;

		for (unsigned int i = m_DataLength; i > index; i--)
			m_Array[i] = m_Array[i - 1];
		m_Array[index] = x;

		m_DataLength++;
		return;
	}
}

int Array::Delete(unsigned int index)
{
	if (index < m_DataLength)
	{
		int x = m_Array[index];
		for (unsigned int i = index; i < m_DataLength - 1; i++)
		{
			m_Array[i] = m_Array[i + 1];
		}
		m_DataLength--;

		return x;
	}
	return 0;
}

int Array::LinearSearch(int key)
{
	for (unsigned int i = 0; i < m_DataLength; i++)
	{
		if (key == m_Array[i])
		{ 
			Swap(m_Array[0], m_Array[i]);	// Ready data for next time.
			return i;
		}
	}
	return -1;
}

int Array::BinarySearch(int key)
{
	unsigned int l = 0, m, h = m_DataLength - 1;

	while (l <= h)
	{
		m = (l + h) / 2;
		if (key == m_Array[m])
			return m;
		else if (key < m_Array[m])
			h = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

int Array::Get(unsigned int index)
{
	if (index < m_DataLength)
		return m_Array[index];
	return -1;
}

int Array::Set(unsigned int index, int x)
{
	if (index < m_DataLength)
	{
		m_Array[index] = x;
		return index;
	}
	return -1;
}

int Array::Max()
{
	int max = m_Array[0];
	for (unsigned int i = 1; i < m_DataLength; i++)
	{
		if (max < m_Array[i])
			max = m_Array[i];
	}
	return max;
}

int Array::Min()
{
	int min = m_Array[0];
	for (unsigned int i = 1; i < m_DataLength; i++)
	{
		if (min > m_Array[i])
			min = m_Array[i];
	}
	return min;
}

int Array::Sum()
{
	int sum = 0;
	for (unsigned int i = 1; i < m_DataLength; i++)
		sum += m_Array[i];
	return sum;
}

float Array::Avg()
{
	return (float)Sum()/m_DataLength;
}

void Array::Reverse()
{
	for (unsigned int i = 0, j = m_DataLength - 1; i < j; i++, j--)
		Swap(m_Array[i], m_Array[j]);
}

void Array::InsertSort(int x)
{
	if (m_DataLength == m_Size)
		return;

	unsigned int i = m_DataLength;
	while (i > 0 && m_Array[i] > x)
	{
		m_Array[m_DataLength] = m_Array[m_DataLength - 1];
		i--;
	}
	m_Array[m_DataLength] = x;
	m_DataLength++;
}

bool Array::isSorted()
{
	for (unsigned int i = 1; i < m_DataLength; i++)
	{
		if (m_Array[i] < m_Array[i - 1])
			return false;
	}
	return true;
}

void Array::Rearrange()		// Rearrange negative and positive number
{
	unsigned int i = 0, j = m_DataLength - 1;

	while (i < j)
	{
		while (m_Array[i] < 0) i++;
		while (m_Array[j] >= 0) j--;
		if (i < j)
			Swap(m_Array[i], m_Array[j]);
	}
}

Array* Array::Merge(Array arr2)
{
	unsigned int i = 0, j = 0, k = 0;

	Array* arr3 = new Array(m_DataLength + arr2.m_DataLength);

	while (i < m_DataLength && j < arr2.m_DataLength)
	{
		if (m_Array[i] < arr2.m_Array[j])
			arr3->m_Array[k++] = m_Array[i++];
		else
			arr3->m_Array[k++] = arr2.m_Array[j++];
	}

	for (; i < m_DataLength; i++)
		arr3->m_Array[k++] = m_Array[i];

	for (; j < m_DataLength; j++)
		arr3->m_Array[k++] = arr2.m_Array[j];

	arr3->m_DataLength = arr3->m_Size;

	return arr3;
}

Array* Array::Union(Array arr2)
{
	unsigned int i = 0, j = 0, k = 0;

	Array* arr3 = new Array(m_DataLength + arr2.m_DataLength);

	while (i < m_DataLength && j < arr2.m_DataLength)
	{
		if (m_Array[i] < arr2.m_Array[j])
			arr3->m_Array[k++] = m_Array[i++];
		else if (m_Array[i] > arr2.m_Array[j])
			arr3->m_Array[k++] = arr2.m_Array[j++];
		else
		{
			arr3->m_Array[k++] = m_Array[i++];
			j++;
		}
	}

	for (; i < m_DataLength; i++)
		arr3->m_Array[k++] = m_Array[i];

	for (; j < m_DataLength; j++)
		arr3->m_Array[k++] = arr2.m_Array[j];

	arr3->m_DataLength = k;

	return arr3;
}

Array* Array::Diff(Array arr2)
{
	unsigned int i = 0, j = 0, k = 0;

	Array* arr3 = new Array(m_DataLength + arr2.m_DataLength);

	while (i < m_DataLength && j < arr2.m_DataLength)
	{
		if (m_Array[i] < arr2.m_Array[j])
			arr3->m_Array[k++] = m_Array[i++];
		else if (m_Array[i] > arr2.m_Array[j])
			j++;
		else
		{
			i++;
			j++;
		}
	}

	for (; i < m_DataLength; i++)
		arr3->m_Array[k++] = m_Array[i];

	arr3->m_DataLength = k;

	return arr3;
}

Array* Array::Inter(Array arr2)
{
	unsigned int i = 0, j = 0, k = 0;

	Array* arr3 = new Array(m_DataLength + arr2.m_DataLength);

	while (i < m_DataLength && j < arr2.m_DataLength)
	{
		if (m_Array[i] < arr2.m_Array[j])
			i++;
		else if (m_Array[i] > arr2.m_Array[j])
			j++;
		else
		{
			arr3->m_Array[k++] = m_Array[i++];
			j++;
		}
	}

	arr3->m_DataLength = k;

	return arr3;
}

int main()
{
	Array* arr1;
	int ch, sz;
	int x, index;
	std::cout << "Enter Size of Array: ";
	scanf_s("%d", &sz);    arr1 = new Array(sz);
	do {
		std::cout << "\n\nMenu\n";
		std::cout << "1. Insert\n";
		std::cout << "2. Delete\n";
		std::cout << "3. Search\n";
		std::cout << "4. Sum\n";
		std::cout << "5. Display\n";
		std::cout << "6.Exit\n";
		std::cout << "enter you choice ";
		std::cin >> ch;
		switch (ch) {
		case 1: 
			std::cout << "Enter an element and index ";
			std::cin >> x >> index;
			arr1->Insert(index, x);
			break;
		case 2: 
			std::cout << "Enter index ";
			std::cin >> index;
			x = arr1->Delete(index);
			std::cout << "Deleted Element is" << x;
			break;            
		case 3:
			std::cout << "Enter element to search ";
			std::cin >> x;
			index = arr1->LinearSearch(x);
			std::cout << "Element index " << index;
			break;            
		case 4:
			std::cout << "Sum is " << arr1->Sum();
			break;
		case 5:
			arr1->Display();
		}
	} while (ch < 6);   

	return 0;
}