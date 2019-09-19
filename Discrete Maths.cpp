#include  <iostream>
using namespace std;
#include <ctime>
#include <cmath>

//QUESTION NO 1
//PART a)
//  .
bool IsPrime(long long Number) {

	if (Number == 2)
	{
		return true;
	}
	else if (Number<2)
	{
		return false;
	}

	long long Limit = Number / 2;

	for (int counter = 2; counter <= Limit; counter++)
	{
		if (Number % counter == 0) {
			return false;

		}
	}

	return true;

}
//  .

bool IsPrimeFaster(long long Number)
{
	if (Number == 2)
	{
		return true;
	}
	else if (Number<2)
	{
		return false;
	}


	long long Limit = sqrt(Number);


	for (int counter = 2; counter <= Limit; counter++)
	{
		if (Number % counter == 0)
		{
			return false;
		}
	}

	return true;

}
//.
// EXECUTION TIME
//The execution time for the number 2147483647 is 27.00 seconds by n/2 method 
//and the execution time for the number 2147483647 is 0.00 seconds by sqrt(n) method

//PART b)

bool P(long long n)
{
	long long N = (n*n) + n + 41;

	if (IsPrimeFaster(N) == true)
	{
		return true;
	}

	else if (IsPrimeFaster(N) == false)
	{
		return false;
	}

}
//PART c)
void twinprime(long long range)
{
	for (long long start = range; start > 0; start--)
	{
		if (IsPrimeFaster(start) == true && IsPrimeFaster(start - 2)==true)
		{
			cout << "Twin Primes are: " << start << "," << start - 2 << endl;
			break;
		}

	}
}
//Part c

//Problem 2

bool EularConjucture(long long a, long long b, long long c, long long d)
{

	if (pow(a, 4) + pow(b, 4) + pow(c, 4) == pow(d, 4))
	{
		return true;

	}
	else if (pow(a, 4) + pow(b, 4) + pow(c, 4) != pow(d, 4))
	{
		return false;
	}

}

//problem 3

//part a
bool ellipticcurve(long long a, long long b, long long c)
{
	if (313 * (pow(a, 3) + pow(b, 3)) == pow(c, 3))
	{
		return true;
	}
	else if (313 * (pow(a, 3) + pow(b, 3)) != pow(c, 3))
	{
		return false;
	}
}
//part a

//part b


void goldbach(long long even)
{
	long long half = even / 2;

	if (IsPrimeFaster(half) == true)
	{
		cout << "The even number with the sum of two prime numbers is: " << half << "+" << half << endl;
	}



	else if (IsPrimeFaster(half) == false)
	{
		long long p1, p2 = 0;
		long long countx = 0, county = 0;
		for (long long x = half, y = half; x > 0, y < INT_MAX; x--, y++, countx++, county++)
		{
			if (IsPrimeFaster(x) == true && IsPrimeFaster(y) == true && countx == county)
			{
				p1 = x;
				p2 = y;
				break;
			}
		}


		cout << "The even number with the sum of two prime numbers is: " << p1 << "+" << p2 << endl;

	}


}




//part b

//part c


bool IsEven(long long Number) {
	if (Number % 2 == 0)
	{
		return true;
	}

	return false;

}

int Collatz(long long Number) {
	if (Number / 2 == 1)
	{
		cout << "The number that is shrunked by dividing it by 2 is " << Number << endl;
		cout << "It indeed shrunk to 1" << endl;
		return 0;
	}

	else if (IsEven(Number) == true)
	{
		cout << "The number that is shrunked by dividing it by 2 is " << Number << endl;
		long long Temp_for_Even = Number / 2;
		cout << "The number shrunked is " << Temp_for_Even << endl;
		return (Collatz(Temp_for_Even));
	}

	else if (IsEven(Number) == false)
	{
		cout << "The number that is tripled by multiplying it by 3 and adding 1 is " << Number << endl;
		long long Temp_for_ODD = (3 * Number) + 1;
		cout << "The number increased is" << Temp_for_ODD;
		return (Collatz(Temp_for_ODD));
	}

}


//part c

//problem 3







int main() {


	cout << "Enter the number of the problem to check that problem (1 to 3)" << endl;

	int problem;
	cin >> problem;

	system("cls");

	//problem 1
	if (problem == 1)
	{
		cout << "Enter the part of the question you want to check. Enter a,b or c to check." << endl;
		char part;
		cin >> part;

		system("cls");

		//part a
		if (part == 'a')
		{
			cout << "Enter n if you want to check by n/2 method otherwise enter s if you want to check by square root method: " << endl;

			char check;
			cin >> check;

			if (check == 'n')
			{
				system("cls");

				cout << "Enter the number you want to check" << endl;

				long long number = 0;
				cin >> number;

				time_t begin, end;
				time(&begin);

				system("cls");


				if (IsPrime(number) == true)
				{
					cout << "its a prime number" << endl;
				}
				else if (IsPrime(number) == false)
				{
					cout << "its not a prime number" << endl;
				}

				time(&end);

				double difference = difftime(end, begin);

				printf("time taken by function to get executed function() %.2lf seconds.\n", difference);
			}
			else if (check == 's')
			{

				system("cls");

				cout << "Enter the number you want to check" << endl;

				long long number = 0;
				cin >> number;

				time_t begin, end;
				time(&begin);

				system("cls");


				if (IsPrimeFaster(number) == true)
				{
					cout << "its a prime number" << endl;
				}
				else if (IsPrimeFaster(number) == false)
				{
					cout << "its not a prime number" << endl;
				}

				time(&end);

				double difference = difftime(end, begin);

				printf("time taken by function to get executed function() %.2lf seconds.\n", difference);
			}

			//part a
		}
		//part b
		else if (part == 'b')
		{
			cout << "Press u to enter user defined values to check if the proposition p(n)=n^2+n+41 is prime or not else press c to check at which number the proposition fails:" << endl;

			char choice;
			cin >> choice;

			system("cls");
			if (choice == 'u'){

				cout << "Enter the number n to check  p(n)=n^2+n+41 is prime or not" << endl;
				long long n;
				cin >> n;


				if (P(n) == true)
				{
					cout << "its a prime number" << endl;
				}
				else if (P(n) == false)
				{
					cout << "its not a prime number" << endl;
				}


			}
			else if (choice == 'c')
			{
				for (int n = 0; n < INT_MAX; n++)
				{
					if (P(n) == false)
					{
						cout << "Claim failed at the number:" << n << endl;
						break;
					}
				}

			}


		}
		//part b

		//part c
		else if (part == 'c')
		{
			cout << "Enter the maximum range under which you want to get twin primes " << endl;
			long long range;
			cin >> range;
			twinprime(range);
		}
		//partc

	}
	//problem 1

	//Problem 2
	else if (problem == 2)
	{
		cout << "Enter a to check first part of the question otherwise enter b to check second part" << endl;
		char choice;
		cin >> choice;
		//part a
		system("cls");
		if (choice == 'a'){
			system("cls");
			cout << "Enter a b c and d" << endl;
			long long a, b, c, d;
			cout << "Enter a:"; cin >> a;
			cout << "Enter b:"; cin >> b;
			cout << "Enter c:"; cin >> c;
			cout << "Enter d:"; cin >> d;
			system("cls");

			if (EularConjucture(a, b, c, d) == true)
			{
				cout << "Conjucture satisfied" << endl;
				cout << "a=" << a << endl;
				cout << "b=" << b << endl;
				cout << "c=" << c << endl;
				cout << "d=" << d << endl;

			}
			else if (EularConjucture(a, b, c, d) == false)
			{
				cout << "Conjucture Failed" << endl;
				cout << "a=" << a << endl;
				cout << "b=" << b << endl;
				cout << "c=" << c << endl;
				cout << "d=" << d << endl;
			}


		}
		//part a

		//part b
		else if (choice == 'b')
		{
			long long range = 2147383647;

			for (int a = range; a>0; a--)
			{
				for (int b = range; b > 0; b--)
				{
					for (int c = range; c > 0; c--)
					{
						for (int d = range; d > 0; d--)
						{
							if (EularConjucture(a, b, c, d) == true)
							{
								cout << "Finally" << endl;
								cout << "Conjucture satisfied" << endl;
								cout << "a=" << a << endl;
								cout << "b=" << b << endl;
								cout << "c=" << c << endl;
								cout << "d=" << d << endl;


							}
						}
					}
				}
			}

			// 2682440, 15365639, 18796760, 20615673. Solution after long term testing.
		}
		//part b

	}
	//problem2

	//problem 3
	else if (problem == 3)
	{
		cout << "Enter The part of the question you want to check (a,b,c)" << endl;
		char part;
		cin >> part;

		system("cls");

		//part a
		if (part == 'a')
		{
			cout << "Press e to enter triptlet to check if it satisfies 313(a^3+b^3)=c^3.\n\nElse press t to find 3 tuple which satisfies given proposition:" << endl;

			char option;
			cin >> option;

			system("cls");

			if (option == 'e')
			{
				cout << "Enter a,b and c" << endl;
				long long a, b, c;
				cout << "Enter a:"; cin >> a;
				cout << "Enter b:"; cin >> b;
				cout << "Enter c:"; cin >> c;
				system("cls");
				if (ellipticcurve(a, b, c) == true)
				{
					cout << "Conjucture satisfied" << endl;
					cout << "a=" << a << endl;
					cout << "b=" << b << endl;
					cout << "c=" << c << endl;

				}
				else if (ellipticcurve(a, b, c) == false)
				{
					cout << "Conjucture Failed" << endl;
					cout << "a=" << a << endl;
					cout << "b=" << b << endl;
					cout << "c=" << c << endl;
				}
			}
			else if (option == 't')
			{
				long long range = 2147383647;

				for (int a = range; a > 0; a--)
				{
					for (int b = range; b > 0; b--)
					{
						for (int c = range; c > 0; c--)
						{
							if (ellipticcurve(a, b, c) == true)
							{
								cout << "Finally!!" << endl;
								cout << "Conjucture satisfied" << endl;
								cout << "a=" << a << endl;
								cout << "b=" << b << endl;
								cout << "c=" << c << endl;

							}

						}
					}
				}


			}
		}
		//part b
		else if (part == 'b')
		{
			cout << "How many numbers you want to test :" << endl;
			int limit;
			cin >> limit;
			system("cls");

			for (int start = 0; start < limit; start++)
			{
				cout << "Enter only the even number you want to test: " << endl;
				long long number;
				cin >> number;

				goldbach(number);
				cout << endl;


			}

		}
		//part b

		else if (part == 'c')
		{
			cout << "How many numbers you want to test :" << endl;
			int limit;
			cin >> limit;
			system("cls");

			for (int start = 0; start < limit; start++)
			{
				cout << "Enter number you want to test: " << endl;
				long long number;
				cin >> number;

				Collatz(number);
				cout << endl;


			}

		}



	}
	//problem 3



	system("pause");
}