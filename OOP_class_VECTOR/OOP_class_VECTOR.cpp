#include <iostream>
using namespace std;

template<class T>
class Vector
{
public:
	typedef T* vector_iterator;
	typedef const T* const_vector_iterator;
	vector_iterator vv; // итератор контейнера
	const_vector_iterator cv;// константный итератор
	Vector();
	~Vector();
	vector_iterator begin_v(); // итератор на начало вектора
	vector_iterator end_v(); // итеротор на конец вектора
	void push_b(T);				// добавление элементов в конец вектора
	void pop_b();				//удаление элементов с конца вектора
	void insert_v(T, T*); //добавление элемента в вектор
	void erase_v(T*);		// удаление элемента с конца вектора
private:
	int size;  // размерность массива
};

template<class T>
Vector<T>::Vector()
{
	vv = new T;
	cv = vv;
	size = 0;
}

template<class T>
Vector<T>::~Vector()
{
	delete[]vv;
}

template<class T>
T* Vector<T>::begin_v()
{
	return vv;
}

template<class T>
T* Vector<T>::end_v()
{
	return vv + size;
}

template<class T>
void Vector<T>::push_b(T a)
{
	vector_iterator temp;
	temp = new T[++size];
	for (int i = 0; i < size-1; i++)
	{
		*(temp + i) = *(vv + i);
	}
	*(temp + size - 1) = a;
	delete[]vv;
	vv = temp;
}

template<class T>
void Vector<T>::pop_b()
{
	vector_iterator temp;
	temp = new T[--size];
	for (int i = 0; i < size; i++)
	{
		*(temp + i) = *(vv + i);
	}
	delete[] vv;
	vv = temp;
}

template<class T>
void Vector<T>::insert_v(T zn, T* adr)
{
	int k = 0;   // элемент контейнера
	vector_iterator temp;
	temp = new T[++size]; // врееный вектор
	for (vector_iterator i = vv; i < adr; i++)
	{
		*(temp + k++) = *i;
	}
	*(temp + k) = zn;
	for (vector_iterator i = adr;  i< vv+size-1;  i++)
	{
		*(temp + ++k) = *i;
	}
	delete[] vv;  // освобождения памяти для старого вектора
	vv = temp;		// vv указывает на новый вектор
}

template<class T>
void Vector<T>::erase_v(T* adr)
{}


void menu()
{
	cout << " [1]  ->  Добавление Элементов " << endl;
	cout << " [2]  ->  'pop' последний элемент " << endl;
	cout << " [3]  ->  'erase' элемент " << endl;
	cout << " [4]  ->  напечатать содежимое контейнера " << endl;
	cout << " [0]  ->  Окончание работы " << endl;

}

int main()
{
	setlocale(LC_ALL,"ru");

	int count{}, choice{}, pos{}, val{};

	Vector<int> Vectors;  // обьект вектора
	Vector<int>::vector_iterator itr; // итератор
	
	cout << "Сколько элементов вводиться в вектор?" << endl;
	cin >> count;
	int a{};
	for (int i = 0; i < count; i++)
	{
		cout << "Введите значение элемента [ "<<i+1<<" ]" << endl;
		cin >> a;					// инициализация вектора начальными значениями
		Vectors.push_b(a);
	}
	while (1)
	{
		menu();
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			cout << "Введиете значение и позицию " << endl;
			cin >> val >> pos;
			Vectors.insert_v(val, Vectors.begin_v() + pos - 1);
			cout << endl;
			break;
		}
		case 2:
		{
			Vectors.pop_b();
			cout << "Элемент удален!" << endl;
			break;
		}
		case 3:
		{	
			cout << "Введите позицию элемента для его удаления " << endl;
			cin >> pos;
			Vectors.erase_v(Vectors.begin_v() + pos - 1);
			break;
		}
		case 4:
		{
			for (itr=Vectors.begin_v();itr!=Vectors.end_v(); itr++)
			{
				cout << *itr << "\t";
			}
			break;
		}
		case 0: return 0;
		default:
			break;
		}
	}
	return 0;
}


