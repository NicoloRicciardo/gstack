/**
  @file main.cpp
  @brief Test d'uso della classe gstack
**/

#include "gstack.h"
#include <iostream>
#include <cassert>


/**
  Metodo che testa i metodi essenziali di un oggetto
  gstack di tipo intero.
**/
void test_essenziali() {
  std::cout << "TEST: gstack::gstack()" << std::endl;
  gstack<int> gs;
  assert(gs.size() == 0);
  std::cout << gs << std::endl;
  std::cout << "TEST: gstack::push(const value_type &value)" << std::endl;
  gs.push(4);
  gs.push(6);
  gs.push(81);
  gs.print();
  std::cout << "TEST: gstack::pop()" << std::endl;
  int val = gs.pop();
  std::cout << val << std::endl;
  std::cout << "TEST: gstack::size()" << std::endl;
  std::cout << gs.size() << std::endl;
  std::cout << gs << std::endl;
  std::cout << "TEST: gstack::gstack(const gstack &other)" << std::endl;
  gstack<int> gs2(gs);
  std::cout << gs2 << std::endl;
  gstack<int> gs3;
  std::cout << "TEST: gstack::operator=(const gstack &other)" << std::endl;
  gs3 = gs2;
  std::cout << gs3 << std::endl;
}

struct equal_string {
  bool operator()(std::string a) const {
    return a == "Gino";
  }
};

/**
  Metodo che testa tutti metodi di un oggetto
  gstack di tipo std::string.
**/
void test_secondari() {
  std::cout << "TEST: gstack::gstack()" << std::endl;
  gstack<std::string> gstr;
  gstr.push("Mario");
  gstr.push("Anna");
  gstr.push("Gino");
  std::cout << gstr << std::endl;
  std::cout << "TEST: gstack::gstack(IteT begin, IteT end)" << std::endl;
  gstack<std::string> gstr2(gstr.begin(), gstr.end());
  std::cout << gstr2 << std::endl;
  std::cout << "TEST: gstack::clear()" << std::endl;
  gstr2.clear();
  assert(gstr2.size() == 0);
  std::cout << gstr2 << std::endl;
  gstack<std::string> gstr3;
  gstr3.push("Giovanni");
  gstr3.push("Sofia");
  std::cout << gstr3 << std::endl;
  std::cout << "TEST: gstack::pop()" << std::endl;
  std::cout << gstr3.pop() << std::endl;
  std::cout << gstr3 << std::endl;
  std::cout << "TEST: gstack::rewrite(IteT begin, IteT end)" << std::endl;
  gstr3.rewrite(gstr.begin(), gstr.end());
  std::cout << gstr3 << std::endl;
  std::cout << "TEST: gstack::removeif(const P &funct)" << std::endl;
  gstr3.removeif(equal_string());
  std::cout << gstr3 << std::endl;
  std::cout << "TEST: gstack::value(size_type index)" << std::endl;
  std::cout << gstr.value(1) << std::endl;
  std::cout << "TEST: gstack::print()" << std::endl;
  gstr.print();
}

struct equal_char {
  bool operator()(char a) const {
    return a == 'N';
  }
};

/**
  Metodo che testa un oggetto gstack di tipo char.
**/
void test_aggiuntivi() {
  std::cout << "TEST: gstack::gstack()" << std::endl;
  gstack<char> gsc;
  gsc.push('A');
  gsc.push('M');
  gsc.push('S');
  gsc.push('N');
  std::cout << gsc << std::endl;
  std::cout << "TEST: gstack::gstack(const gstack &other)" << std::endl;
  gstack<char> gsc2(gsc);
  std::cout << gsc2 << std::endl;
  std::cout << "TEST: gstack::clear()" << std::endl;
  gsc2.clear();
  std::cout << gsc2 << std::endl;
  std::cout << "TEST: gstack::operator=(const gstack &other)" << std::endl;
  gsc2 = gsc;
  std::cout << gsc2 << std::endl;
  std::cout << "TEST: gstack::gstack(IteT begin, IteT end)" << std::endl;
  gstack<char> gsc3(gsc.begin(), gsc.end());
  std::cout << gsc3 << std::endl;
  std::cout << "TEST: gstack::pop()" << std::endl;
  std::cout << gsc3.pop() << std::endl;
  std::cout << "TEST: gstack::rewrite(IteT begin, IteT end)" << std::endl;
  gsc2.rewrite(gsc3.begin(), gsc3.end());
  std::cout << gsc2 << std::endl;
  std::cout << "TEST: gstack::removeif(const P &funct)" << std::endl;
  gsc2.removeif(equal_char());
  std::cout << gsc2 << std::endl;
  std::cout << "TEST: gstack::size()" << std::endl;
  std::cout << gsc.size() << std::endl;
  std::cout << "TEST: gstack::value(size_type index)" << std::endl;
  std::cout << gsc.value(2) << std::endl;
  std::cout << "TEST: gstack::print()" << std::endl;
  gsc3.print();
}

struct minus_double {
  bool operator()(double a) const {
    return a < 17.5;
  }
};

/**
  Metodo che testa principalmente i metodi di un oggetto
  gstack richiesti nella traccia di progetto.
**/
void test_progetto() {
  std::cout << "TEST: gstack::gstack()" << std::endl;
  gstack<double> gsd;
  std::cout << gsd << std::endl;
  std::cout << "TEST: gstack::push(const value_type &value)" << std::endl;
  gsd.push(4.2);
  gsd.push(16.8);
  gsd.push(72.1);
  std::cout << gsd << std::endl;
  std::cout << "TEST: gstack::pop()" << std::endl;
  double val = gsd.pop();
  std::cout << val << std::endl;
  std::cout << "TEST: gstack::size()" << std::endl;
  std::cout << gsd.size() << std::endl;
  std::cout << "TEST: gstack::gstack(IteT begin, IteT end)" << std::endl;
  gstack<double> gsd2(gsd.begin(), gsd.end());
  std::cout << gsd2 << std::endl;
  std::cout << "TEST: gstack::clear()" << std::endl;
  gsd.clear();
  std::cout << gsd << std::endl;
  gsd.push(5.22);
  std::cout << "TEST: gstack::rewrite(IteT begin, IteT end)" << std::endl;
  gsd.rewrite(gsd2.begin(), gsd2.end());
  std::cout << gsd << std::endl;
  gsd2.push(25.4);
  std::cout << "TEST: gstack::removeif(const P &funct)" << std::endl;
	gsd2.removeif(minus_double());
  std::cout << gsd2 << std::endl;
}

int main() {
  test_essenziali();
  test_secondari();
  test_aggiuntivi();
  test_progetto();
  return 0;
}
