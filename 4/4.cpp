#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

bool isvowel(char c)
{
  std::string vw = "aeiouAEIOU";
  return vw.find(c) != std::string::npos;
}

std::string translate(std::string& s)
{
  std::stringstream ss(s);
  std::string w, t;

  while (ss >> w) {
    if (isvowel(w[0]))
      t += w + "hay";
    else {
      size_t n = 0;

      for (char& c : w) {
        if (isvowel(c))
          break;
        n++;
      }

      t += w.substr(n, w.size()) + w.substr(0, n) + "ay"; 
    }
    t += ' ';
  }

  return t;
}

int main()
{
  std::string s;
  std::vector<std::string> v;
  std::random_device rd;
  std::mt19937 mt{rd()};

  while (std::getline(std::cin, s))
    v.push_back(s);
  std::uniform_int_distribution<int> dist(0, v.size() - 1);
  std::cout << translate(v[dist(mt)]) << std::endl;
  return 0;
}
