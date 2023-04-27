#include <iostream>
#include <string>
using namespace std;

int digit(int number)
{
if (number < 9)
	return number;
return number / 10 + number % 10;
}

int size(long long d)
{
string num = to_string(d);
return num.length();
}

long long getPrefix(long long number, int k)
{
if (size(number) > k)
{
	string num = to_string(number);
	return stol(num.substr(0, k));
}
return number;
}


bool prefixMatched(long long number, int d)
{
return getPrefix(number, size(d)) == d;
}


int sumOfDoubleEvenPlace(long long int number)
{
int sum = 0;
string num = to_string(number) ;
for (int i = size(number) - 2; i >= 0; i -= 2)
	sum += digit(int(num[i] - '0') * 2);

return sum;
}

int sumOfOddPlace(long long number)
{
int sum = 0;
string num = to_string(number) ;
for (int i = size(number) - 1; i >= 0; i -= 2)
	sum += num[i] - '0';
return sum;
}


bool isValid(long long int number)
{
return (size(number) >= 13 &&
		size(number) <= 16) &&
	(prefixMatched(number, 4) ||
	prefixMatched(number, 5) ||
	prefixMatched(number, 37) ||
	prefixMatched(number, 6)) &&
	((sumOfDoubleEvenPlace(number) +
	sumOfOddPlace(number)) % 10 == 0);
}


int main()
{
long long int number = 51006533546354645L;
cout << number << " is " << (isValid(number) ? "valid" : "invalid");
return 0;
}
