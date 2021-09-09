#ifndef GSTACK_H
#define GSTACK_H

#include <ostream>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <cstddef>

/**
	@file gstack.h
	@brief Dichiarazione della classe templata gstack
*/


/**
	@brief Stack di elementi di tipo T
	Classe che rappresenta uno stack che contiene elementi generici.
	La dimensione dello stack può essere scelta in fase dicostruzione.
  @param T tipo dei dati contenuti
*/
template <typename T>
class gstack {

public:

  typedef T value_type;
  typedef unsigned int size_type;
  typedef int top_type;

private:

  value_type* _stack; ///< Puntatore all'array dinamico
  size_type _size; ///< Dimensione dell'array
  top_type _top; ///< Ultimo elemento dell'array

  /**
    @brief Accesso allo stato dello stack
    Metodo che controlla se lo stack è vuoto
    @return risposta alla domanda se lo stack è vuoto
  */
  bool is_empty() const {
    return (_stack == nullptr);
  }

  /**
		@brief Metodo di swap dei dati interni tra due gstack
		Funzione che scambia gli stati interni tra due gstack
		@param other gstack sorgente
	*/
  void swap(gstack &other) {
		std::swap(this->_stack, other._stack);
		std::swap(this->_size, other._size);
    std::swap(this->_top, other._top);
	}

public:

  /**
		@brief Costruttore di default
		Costruttore di default per istanziare un gstack vuoto.
		@post _stack == nullptr
		@post _size == 0
    @post _top == -1
	*/
  gstack() : _stack(nullptr), _size(0), _top(-1) {}

  /**
    @brief Costruttore di riempimento
    Costruttore che prende una coppia di iteratori: uno che punta all'elemento
    in cima dello stack e l'altro che punta alla fine della pila.
    Questo costruttore è usato per riempire lo stack.
    @param begin iteratore che punta all'elemento in cima alla pila
    @param begin iteratore che punta alla fine della pila
    @throw eccezione di allocazione di memoria
  */
  template<typename IteT>
  gstack(IteT begin, IteT end) : _stack(nullptr), _size(0), _top(-1) {
		try {
			while(begin != end) {
				push(static_cast<T>(*begin));
				begin++;
			}
		} catch(...) {
			clear();
			throw;
		}
	}

  /**
		@brief Copy constructor
		Costruttore di copia tra un gstack e un altro gstack.
		@param other gstack da copiare
    @throw eccezione di allocazione di memoria
	*/
  gstack(const gstack &other) : _stack(nullptr), _size (0), _top(-1) {
		_stack = new value_type[other._size];
		try{
			for(size_type i = 0; i < other._size; ++i)
				_stack[i] = other._stack[i];
		}
		catch(...){
			delete[] _stack;
			_stack = nullptr;
			_size = 0;
      _top = -1;
			throw;
		}
		_size = other._size;
    _top = other._top;
	}

  /**
		@brief Operatore di assegnamento
		Operatore di assegnamento che serve per copiare il contenuto di
		other in *this.
		@param other gstack da assegnare
		@return reference a gstack
    @throw eccezione di allocazione di memoria
	*/
  gstack& operator=(const gstack &other) {
		if (&other != this) {
			gstack tmp(other);
			tmp.swap(*this);
		}
		return *this;
	}

  /**
		@brief Distruttore della classe
    Rimuove tutti gli elementi e dealloca la memoria.
    @post _stack == nullptr
    @post _size == 0
		@post _top == -1
	*/
  ~gstack() {
    delete[] _stack;
    _stack = nullptr;
    _size = 0;
    _top = -1;
  }

  /**
    @brief Metodo PUSH di dati nel gstack
    Metodo che permette di aggiungere dati al gstack
    @param value dato generico che verrà aggiunto allo stack
    @post _stack != nullptr
		@post _size++
    @post _top++
  */
  void push(const value_type &value) {
    value_type *tmp = new value_type[_size + 1];
    for(unsigned int i = 0; i < _size; i++){
      tmp[i] = _stack[i];
    }
    delete[] _stack;
    _stack = tmp;

    _size++;
    _top++;
    _stack[_top] = value;
  }

  /**
    @brief Metodo POP di dati nel gstack
    Metodo che permette di togliere dati al gstack; viene ritornato
    il valore rimosso.
    @return val variabile che contiene il dato tolto dal gstack
    @post _stack != nullptr
		@post _size--
    @post _top--
  */
  value_type pop() {
    value_type val;
    if(size() != 0) {
      value_type *tmp = new value_type[_size - 1];
      val = _stack[_top];
      for(unsigned int i = 0; i < _size - 1; i++){
        tmp[i] = _stack[i];
      }
      delete[] _stack;
      _stack = tmp;
      _size--;
      _top--;
    }
    return val;
  }

  /**
    @brief Cancellazione dei dati dello stack
    Metodo che permette di cancellare tutti i dati all'interno dello stack.
    @post _stack == nullptr
		@post _size == 0
    @post _top == -1
  */
  void clear() {
    delete[] _stack;
    _stack = nullptr;
    _size = 0;
    _top = -1;
  }

  /**
    @brief Metodo che sovrascrive i dati nel gstack
    Metodo che permette di sovrascirevere tutti i dati all'interno dello stack
    con quelli presenti dentro lo stack che si riferisce ai due iteratori.
    Se lo stack è pieno, prima viene svuotato.
    @param begin iteratore che punta all'elemento in cima alla pila
    @param begin iteratore che punta alla fine della pila
    @throw eccezione di allocazione di memoria
  */
  template<typename IterT>
  void rewrite(IterT begin, IterT end) {
    bool empty = true;
    value_type *tmp;
    size_type sz;
    int tp;
    if(!is_empty()) {
      empty = false;
      sz = _size;
      tp = _top;
      tmp = new value_type[sz];
      for(unsigned int i = 0; i < sz; i++){
        tmp[i] = _stack[i];
      }
      clear();
    }
		try {
			while(begin != end) {
				push(static_cast<T>(*begin));
				begin++;
			}
		} catch(...) {
			clear();
      _stack = tmp;
      _size = sz;
      _top = tp;
			throw;
		}
    if(!empty)
      delete[] tmp;
  }

  /**
    @brief Metodo che elimina dati dallo stack
    Metodo che elimina dallo stack tutte le occorrenze dei dati che
    rispettano un certo predicato generico P.
    @param funct predicato generico di tipo P
  */
  template <typename P>
  void removeif(const P &funct) {
    unsigned int c = 0;
    for(unsigned int i = 0; i < _size; i++) {
      if(funct(_stack[i]))
        c++;
    }
    if(c != 0){
      unsigned int new_size = _size - c;
      value_type *tmp = new value_type[new_size];
      c = 0;
      for(unsigned int i = 0; i < _size; i++) {
        if(!funct(_stack[i])) {
          tmp[c] = _stack[i];
          c++;
        }
      }
      delete[] _stack;
      _stack = tmp;
      _size = new_size;
      _top = _size - 1;
    }
  }

  /**
		@brief Accesso alla dimensione dello stack
		Metodo per ottenere la dimensione dello stack
		@return dimensione dello stack
	*/
	size_type size() const {
		return _size;
	}

  /**
		@brief Getter della cella index-esima
		Funzione che permette di leggere la cella index-esima dello stack
		@param index della cella da leggere
		@return reference alla cella index-esima
	*/
	const value_type &value(size_type index) const {
		assert(index < _size);
		return _stack[index];
	}

  /**
		@brief Funzione di stampa del contento del gstack
		Funzione che stampa a schermo il contenuto della classe gstack.
	*/
  void print() const {
    if(is_empty()) {
      std::cout << "{}" << std::endl;
    } else {
      std::cout << "{";
      for(size_type i = 0; i < _size; ++i){
        if(i == (size() - 1))
          std::cout << _stack[i];
        else
          std::cout << _stack[i] << ", ";
      }
  		std::cout << "}" << std::endl;
    }
	}


  class const_iterator {
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

    // Costruttore di default
		const_iterator() : ptr(nullptr) {}

    // Costruttore di copia
		const_iterator(const const_iterator &other) : ptr(other.ptr) {}

    // Operatore di assegnamento
		const_iterator& operator=(const const_iterator &other) {
			ptr = other.ptr;
			return *this;
		}

    // Distruttore
		~const_iterator() {}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return ptr;
		}

		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tmp(*this);
			--ptr;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			--ptr;
			return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return (ptr == other.ptr);
		}

		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return (ptr != other.ptr);
		}

	private:
		//Dato membro
    const T* ptr;

		friend class gstack;

		// Costruttore privato di inizializzazione usato dalla classe container
		const_iterator(const T* p) : ptr(p) {}
	}; // classe const_iterator

	// Ritorna un iteratore che punta alla cima dello stack
	const_iterator begin() const {
    return const_iterator(_stack + _size - 1);
	}

	// Ritorna un iteratore che punta alla fine dello stack
	const_iterator end() const {
    return const_iterator(_stack - 1);
	}
}; // fine classe gstack

/**
	@brief Ridefinizione operatore di stream
	Ridefinizione dell'operatore di stream per scrivere un
	gstack su uno stream di output
	@param os stream di output (operando di sinistra)
	@param gs gstack da scrivere (operando di destra)
	@return reference allo stream di output
*/
template <typename U>
std::ostream& operator<<(std::ostream &os, const gstack<U> &gs) {
  os << '{';
	for(typename gstack<U>::size_type i = 0; i < gs.size(); ++i)
    if(i == (gs.size() - 1)) {
      os << gs.value(i);
    } else {
      os << gs.value(i) << ", ";
    }
	os << '}';
	return os;
}

#endif
