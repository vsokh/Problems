#include <iostream>
#include <string>

using namespace std;

#define ll long long
string decrypt( const string& word )
{
  // e[n] = d[n] + (d[0..n-1] + 1) - m26
  // d[n] = e[n] - (d[0..n-1] + 1) + m26

  // + m26
  auto to_lower_alpha = [](ll n) {
    while (n < 'a') n += 26;
    return n;
  };

  string s = word;
  ll decLettersSum = 0;
  // O(n)
  for (ll i = 0; i < s.length(); ++i) {
    s[i] = to_lower_alpha(s[i] - decLettersSum - 1);
    decLettersSum += s[i];
  }
  return s;
}

int main() {
  cout << decrypt("dnotq") << endl;
  return 0;
}
