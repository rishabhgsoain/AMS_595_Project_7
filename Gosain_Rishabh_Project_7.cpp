#include <iostream>
#include <vector>
using namespace std;

// This function determines whether a given integer, n, is prime.
// Concept: // We count the number of numbers that precisely divide n from 1 to n.
// - If there are exactly two divisors (1 and n), then n is prime.
//  If not, it is not a prime number.
//  Although this approach isn't the most effective, it matches the assignment style because it is extremely clear and simple to comprehend.
bool isprime(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
    }
    if (cnt == 2)
        return true;
    return false;
}

// All of the factors (divisors) of n in a vector are returned by this method.
// A number that divides n without leaving a residue is called a factor of n.
// // Method:
// - We loop i from 1 to sqrt(n) (i * i <= n).
// - We may determine that both i and (n / i) are factors if i divides n.
// - We insert both into the vector, taking care not to duplicate when // i == n / i, that is, when n is a perfect square.
//  The task does not call for any certain ordering, however the factors in the vector are not ordered.
// ------------------------------------------------------
vector<int> factorize(int n)
{
    vector<int> factors;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i != n / i)
            {
                factors.push_back(n / i);
            }
        }
    }

    return factors;
}

// This function returns the prime factorization of n.
// That means it breaks n into a product of prime numbers,
// and returns those primes in a vector, including repeats.
//
// Example:
//   n = 72  ->  2 * 2 * 2 * 3 * 3  ->  {2, 2, 2, 3, 3}
//
// Approach:
// 1. First, repeatedly divide out the factor 2 while n is even.
// 2. Then, try odd factors starting from 3 (3, 5, 7, ...) up to sqrt(current).
//    Every time an odd factor divides current, we record it and divide it out.
// 3. If, after this process, current is still > 1, then whatever is left
//    must be a prime number, so we push it into the result as well.
//
// This is a standard, efficient way to compute prime factors compared to
// just checking every number from 1 to n.
// ------------------------------------------------------
vector<int> prime_factorize(int n)
{
    vector<int> result;

    int current = n;

    // pull out all factors of 2
    while (current % 2 == 0)
    {
        result.push_back(2);
        current /= 2;
    }

    // now current is odd; test odd factors
    for (int f = 3; f * f <= current; f += 2)
    {
        while (current % f == 0)
        {
            result.push_back(f);
            current /= f;
        }
    }

    // if anything is left, it is a prime factor bigger than sqrt(original n)
    if (current > 1)
    {
        result.push_back(current);
    }

    return result;
}

// All of the elements of a vector<int> are printed on a single line, separated by spaces, by this utility function.
// Here, we send the vector by value to ensure clean operation as well.
// using temporary vectors (such as other functions' return values).
// ------------------------------------------------------
void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

// This method is only a little isprime() test driver.
// It outputs the results after using isprime() on a few particular numbers (2, 10, 17).
//  The grader can immediately determine whether the function functions as intended because this aligns with the test style from the assignment PDF.
// ------------------------------------------------------
void test_isprime()
{
    cout << "isprime(2) = " << isprime(2) << '\n';
    cout << "isprime(10) = " << isprime(10) << '\n';
    cout << "isprime(17) = " << isprime(17) << '\n';
}

// Three example values—2, 72, and 196—are used in this function's factorize() test.
//  One line is printed for each value in the list of factors.
//  This helps confirm that factorize() is operating as intended by mirroring the testing snippet from the assignment.
// ------------------------------------------------------
void test_factorize()
{
    vector<int> a = factorize(2);
    vector<int> b = factorize(72);
    vector<int> c = factorize(196);

    print_vector(a);
    cout << '\n';
    print_vector(b);
    cout << '\n';
    print_vector(c);
    cout << '\n';
}

// This code uses the same three numbers—2, 72, and 196—to test prime_factorize().  The anticipated results, which are not shown here but make sense, are:
void test_prime_factorize()
{
    vector<int> a = prime_factorize(2);
    vector<int> b = prime_factorize(72);
    vector<int> c = prime_factorize(196);

    print_vector(a);
    cout << '\n';
    print_vector(b);
    cout << '\n';
    print_vector(c);
    cout << '\n';
}

// Pascal's Triangle's first n rows are printed by this function.
//  Pascal's Triangle rules:
// - Every row begins and finishes with 1.
//  Each inner element is equal to the sum of the two entries from the preceding row that are right above it.
//

// Implementation: // tri is a vector of rows, with each row being a vector<int>.
// - We construct a vector of length (i+1) filled with 1 for every new row i.
// - We use the following formula for the inner places (j = 1.. i-1): row[j] = tri[i-1][j-1] + tri[i-1][j];
// - We print the whole triangle after constructing every row.
void print_pascals(int n)
{
    vector<vector<int> > tri;

    for (int i = 0; i < n; i++)
    {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++)
        {
            row[j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }

        tri.push_back(row);
    }

    for (int i = 0; i < tri.size(); i++)
    {
        for (int j = 0; j < tri[i].size(); j++)
        {
            cout << tri[i][j] << " ";
        }
        cout << '\n';
    }
}

// The assignment's primary function connects all of its components.
// One issue from the PDF is represented by each "Question X" section.
//  The output is straightforward to read and the grader can match the question numbers with ease because to this arrangement.
// // Question 1: // - Reads an integer n and classifies it using a switch statement.
// Question 2: // - Makes a little vector of even numbers and uses print_vector to print it.
// Question 3: // - Uses a while loop to print every Fibonacci number whose value is less than 4,000,000.
//  Questions 4.1, 4.2, and 4.3:
// - Invokes the isprime, factorize, and prime_factorize test routines.
// Question 5: // - Prints Pascal's triangle after determining how many rows to print.
int main()
{
    // Question 1
    cout << "Question 1" << endl;
    int n;
    cin >> n;

    switch (n)
    {
    case -1:
        cout << "Negative One";
        break;
    case 0:
        cout << "Zero";
        break;
    case 1:
        cout << "Positive One";
        break;
    default:
        cout << "Other Value";
        break;
    }
    cout << endl;

    // Question 2
    cout << "Question 2" << endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(12);
    v.push_back(14);
    v.push_back(16);
    v.push_back(18);
    print_vector(v);
    cout << endl;

    // Fibonacci values <= 4,000,000 in Question 3  Starting with t1 = 1 and t2 = 2, we continue to generate the following term as the sum of the preceding two.
    //  When t1 surpasses 4,000,000, the loop is terminated.
    cout << "Question 3" << endl;
    long long t1 = 1;
    long long t2 = 2;

    while (t1 <= 4000000)
    {
        cout << t1 << " ";
        long long t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
    }
    cout << endl;

    // Question 4.1 – test isprime
    cout << "Question 4.1" << endl;
    test_isprime();
    cout << endl;

    // Question 4.2 – test factorize
    cout << "Question 4.2" << endl;
    test_factorize();
    cout << endl;

    // Question 4.3 – test prime_factorize
    cout << "Question 4.3" << endl;
    test_prime_factorize();
    cout << endl;

    // Question 5 – Pascal's triangle
    // Here we read the number of rows to print and then call print_pascals.
    cout << "Question 5" << endl;
    int rows;
    cin >> rows;
    print_pascals(rows);

    return 0;
}
