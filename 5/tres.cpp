#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#define N_CARDS 10
#define N_ZOGS 4
#define N_PAIR 3

class Card {
public:
  int n;
  int zog;

  Card(int n, int zog) {
    this->n = n;
    this->zog = zog;
  }
};

class Player {
public:
  std::string name;
  std::vector<Card> cards;
  int points;

  Player(std::string name) {
    this->name = name;
    cards.reserve(N_CARDS);
  }

  void update() {
    int pairs[N_ZOGS][N_PAIR] = { { 0 } };

    for (int i = 0; i < N_ZOGS; i++) {
      int* pair = pairs[i];
      for (Card& card : cards) {
        if (card.zog == i && (card.n >= 1 && card.n <= N_PAIR))
          pair[card.n - 1]++;
      }
      points += std::min(std::min(pair[0], pair[1]), pair[2]) * 3;
    }

    int pair[N_PAIR] = { 0 };

    for (int i = 0; i < N_ZOGS; i++)
      for (int j = 0; j < N_PAIR; j++)
        pair[j] += pairs[i][j];
    for (int i = 0; i < N_PAIR; i++)
      points += (pair[i] / 3) * 3;
  }
};

class Deck {
  std::vector<Card> cards;
  std::random_device rd;
  std::mt19937 g;
public:
  Deck() {
    static constexpr int card_n[N_CARDS] = {
      1, 3, 13, 12, 11, 7, 6, 5, 4, 2
    };

    for (int i = 0; i < N_ZOGS; i++)
      for (int j = 0; j < N_CARDS; j++)
        cards.push_back(Card(card_n[j], i));
    g = std::mt19937(rd());
  }

  void shuffle() {
    std::shuffle(cards.begin(), cards.end(), g);
  }

  void deal(std::vector<Player>& players) {
    for (size_t i = 0; i < players.size(); i++) {
      size_t cur = i * 10;
      players[i].cards.assign(cards.begin() + cur,
                              cards.begin() + cur + 10);
    }
  }
};

int main()
{
  int np = 0;
  std::vector<Player> players;
  Deck deck;

  std::cout << "no. of players (must be 2 or 4)" << std::endl;
  std::cin >> np;
  if (np != 2 && np != 4)
    return 0;
  for (int i = 0; i < np; i++) {
    std::string name;
    std::cout << "player " << i + 1 << " name: ";
    std::cin >> name;
    players.push_back(Player(name));
  }

  deck.shuffle();
  deck.deal(players);
  for (Player& player : players) {
    player.update();
    std::cout << "player " << player.name << ": " << player.points << std::endl;
  } 
  return 0;
}
