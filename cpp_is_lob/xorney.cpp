#include<iostream>
#define reverse(string) string=="Even" ? "Odd":"Even"
using namespace std;
int main()
{
    // For each testcase, in the new line print "Odd" if the XOR in the range is odd, else print "Even".
    long long t, l, r;
    cin >> t;
    
    int number_of_odds=0;
    string ans;
    // calculating number of odds
    
    // number of odds will determine the number of times xor changes from odd to even or even to odd
    // so if number_of_odds is even it will be even else odd
    while(t--)
    {
        scanf("%lld %lld", &l, &r);
        int total = (r-l+1);
        if(total%2 == 0)
        {
            number_of_odds = total/2;
        }
        else
        {
            number_of_odds = (l%2 != 0) ? total/2 + 1 : total/2;
        }
        number_of_odds%2 != 0 ? printf("Odd\n") : printf("Even\n");
    }
    // printf("%s", reverse("Odd"));
    return 0;
}