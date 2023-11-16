#define N_CARDS 10
#define N_ZOGS 4
#define N_PAIR 3

class Card {
public:
  int n;
  int zog;

  Card(int n, int zog) : n{n}, zog{zog} {}
};

class Player {
public:
  std::string name;
  std::vector<Card> cards;
  int points;

  Player(std::string name) : name{name} {
    cards.reserve(N_CARDS);
  }

  void update();
};

class Deck {
  std::vector<Card> cards;
  std::random_device rd;
  std::mt19937 g;
public:
  Deck();
  void shuffle();
  void deal(std::vector<Player>& players);
};
