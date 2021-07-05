/*#include <iostream>
using namespace std;

enum except {
    INVALID_ADDITION,
    INVALID_SUBSTRACION,
    DIVISION_BY_ZERO,
    ELEMENT_NOT_EXIST,
};

template <typename T>
class Iterator;

template <typename T>
class M_vector{
    friend Iterator<T>;
private:
    int length;
    T* elems;

    T& get_elem_for_iterator(int index) // костыль для возможности получения "фиктивного" элемента итератором
    {
        if (index < length + 1)
            return elems[index];
        else
            throw(ELEMENT_NOT_EXIST);
    }
public:
    M_vector(int len) //конструктор с указананием размерности
    {
        length = len;
        elems = new T[length + 1];
        for (int i = 0; i < length + 1; i++)
            elems[i] = 0;
    }
    M_vector(const M_vector& vect): M_vector(vect.length) //копирование
    {
        for (int i = 0; i < length; i++)
            elems[i] = vect.elems[i];
    }
    explicit M_vector(std::initializer_list<T> lst): M_vector(lst.size()) //список инициализации
    {
        int count = 0;
        for (T elem: lst)
        {
            elems[count] = elem;
            count++;
        }
    }

    ~M_vector() //деструктор
    {
        delete[] elems;
    }

    int get_length() //текущий размер
    {
        return length;
    }
    T& get_elem(int index) //получить элемент списка по индексу
    {
        if (index < length)
            return elems[index];
        else
            throw(ELEMENT_NOT_EXIST);
    }
    T& operator[](int index) //доступ к элементу
    {
        return get_elem(index);
    }
    void set_elem(int index, const T& elem) //изменить элемент вектора по списку
    {
        if (index < length)
            elems[index] = elem;
        else
            throw(ELEMENT_NOT_EXIST);
    }

    void delete_elem(int index) //доп. - удаление элемента
    {
        T* new_elems = new T[length];
        for (int i = 0; i < length - 1; i++)
            if (i < index)
                new_elems[i] = elems[i];
            else
                new_elems[i] = elems[i+1];
        delete[] elems;
        elems = new_elems;
        length--;
    }

    T* to_array() //новый массив для записи
    {
        T* arr = new T[length];
        for (int i = 0; i < length; i++)
            arr[i] = elems[i];
        return arr;
    }

    template <typename _T> //перегрузка оператора для вывода класса в поток
    friend std::ostream& operator <<(std::ostream& os, const M_vector<_T>& lst)
    {
        os << "[";
        for (int i = 0; i < lst.length - 1; i++)
            os << lst.elems[i] << ", ";
        os << lst.elems[lst.length - 1] << "]";
        return os;
    }

    M_vector<T>& operator =(const M_vector<T>& lst) //перегрузка =
    {
        length = lst.length;
        delete[] elems;
        elems = new T[length + 1];
        for (int i = 0; i < length +1; i++)
            elems[i] = lst.elems[i];

        return *this;
    }
    template <typename _T>
    friend M_vector<_T> glue_vectors(const M_vector<_T>& v1, const M_vector<_T>& v2) //склеивание двух векторов
    {
        M_vector<_T> v3(v1.length + v2.length);
        for (int i = 0; i < v3.length; i++)
            if (i < v1.length)
                v3.set_elem(i, v1.elems[i]);
            else
                v3.set_elem(i, v2.elems[i - v1.length]);

        return v3;

    }

    template <typename _T> //перегрузка оператора (v1 и v2)
    friend M_vector<_T> operator +(const M_vector<_T>& v1, const M_vector<_T>& v2)
    {
        M_vector<_T> v3(v1);
        if (v1.length == v2.length)
            for(int i = 0; i < v2.length; i++)
                v3.elems[i] += v2.elems[i];
        else
           throw INVALID_ADDITION;

        return v3;
    }
    template <typename _T> //...
    friend M_vector<_T> operator -(const M_vector<_T>& v1, const M_vector<_T>& v2)
    {
        M_vector<_T> v3(v1);
        if (v1.length == v2.length)
            for(int i = 0; i < v2.length; i++)
                v3.elems[i] -= v2.elems[i];
        else
            throw INVALID_SUBSTRACION;

        return v3;

    }
    template <typename _T> //* (v1 и val)
    friend M_vector<_T> operator *(const M_vector<_T>& v1,  const T& val)
    {
        M_vector<int> v2(v1);
        for(int i = 0; i < v2.length; i++)
            v2.elems[i] *= val;

        return v2;
    }
    template <typename _T> //...
    friend M_vector<_T> operator /(const M_vector<_T>& v1, const T& val)
    {
        M_vector<int> v2(v1);
        if (val != 0)
            for(int i = 0; i < v2.length; i++)
                v2.elems[i] /= val;
        else
            throw DIVISION_BY_ZERO;

        return v2;
    }

    M_vector<T>& operator +=(const M_vector<T>& vect) //перегрузка += (this и vect)
    {
        *this = *this + vect;
        return *this;
    }
    M_vector<T>& operator -=(const M_vector<T>& vect) //...
    {
        *this = *this - vect;
        return *this;
    }
    M_vector<T>& operator *=(const T& val) //* (this и val)
    {
        *this = *this * val;
        return *this;
    }
    M_vector<T>& operator /=(const T& val) //...
    {
        *this = *this / val;
        return *this;
    }

    Iterator<T> iterator_begin() //метод получения итератора на начало вектора
    {
        Iterator<T> iterator(*this);
        return iterator;
    }
    Iterator<T> iterator_end() //на конец списка
    {
        Iterator<T> iterator(*this);
        for (int i = 0; i < length; i++)
            iterator.next();
        return iterator;
    }

    bool operator == (M_vector<T> &b) //сравнение на тождество
    {
        bool equal = true;
        for (int i = 0; i < length && equal; i++)
            if (elems[i] != b[i])
                equal = false;
        return equal;
    }

    bool operator !=(M_vector &b)
    {
        return !(*this == b);
    }
};

template <typename T>
class Iterator //позволяет сделать алгоритм контейнеро-независимым; абстракция, позволяющая представить множество однотипных объектов
{
private:
    M_vector<T> vector{};
    int pos;
public:
    Iterator(M_vector<T> vect){
        vector = vect;
        pos = 0;
    }

    Iterator<T> next() {
        pos++;
        return *this;
    }

    T& value(){
        return vector.get_elem_for_iterator(pos);
    }

    Iterator &operator++(){
        return next();
    }

    T& operator*(){
        return value();
    }

    bool is_end(){
        return pos == vector.get_length();
    }

    bool operator ==(Iterator &b){
        return value() == b.value();
    }

    bool operator !=(Iterator &b){
        return value() != b.value();
    }
};*/
