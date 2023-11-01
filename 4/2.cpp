#include <iostream>
#include <string>

void strpunct(std::string& s)
{
  std::string t;
  bool space = false;
  bool punct = false;

  for (char& c : s) {
    if (punct && c != ' ') {
      t += ' ';
      punct = false;
    } else if (c == ' ') {
      space = true;
      punct = false;
      continue;
    }
    if (c == '.' || c == ',' || c == '!' || c == '?') {
      t += c;
      space = false;
      punct = true;
      continue;
    } else if (space) {
      t += ' ';
      space = false;
    }
    t += c;
  }

  s = t;
}

int main()
{
  std::string s;

  std::getline(std::cin, s);
  strpunct(s);
  std::cout << s << std::endl;
  return 0;
}
