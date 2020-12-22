#ifndef PAIR_H
#define PAIR_H

template<class K, class V>
class Pair
{
private:
  K key;
  V value;

public:
  Pair(){};
  Pair(K key, V value)
  {
    this->key = key;
    this->value = value;
  }
  K first()
  {
    return this->key;
  }
  V second()
  {
    return this->value;
  }

  bool operator>(const Pair &e) { return this->key > e.key; }
  bool operator>=(const Pair &e) { return this->key >= e.key; }
  bool operator<(const Pair &e) { return this->key < e.key; }
  bool operator<=(const Pair &e) { return this->key <= e.key; }
};

#endif