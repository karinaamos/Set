#include "BitField.h"

class Set{
private:
    BitField _bitField; //структура хранения множества
    size_t _maxPower; //максимальный размер множества
public:
    Set(size_t mp);
    Set(const Set& set); //конструктор копирования
    Set(const BitField& bf);//конструктор преобразования
    operator BitField(); //оператор, который что-то принимает

    size_t GetMaxPower();
    void InsertElem(uint64_t elem); //вставить элемент
    void DeleteElem(uint64_t elem);
    bool IsMember(uint64_t elem); //проверяет, является ли элемент элементом множества

    bool operator==(const Set& tmp);
    Set& operator=(const Set& tmp);
    Set operator+(const Set& tmp);//объединение двух множеств
    Set operator+(uint64_t elem);//добавить элемент в множество
    Set operator-(uint64_t elem);//убрать элемент из множества
    Set operator*(const Set& tmp);//пересечение множеств
    Set operator~();//дополнение

    friend std::istream& operator>>(std::istream& istr, Set& set);
    friend std::istream& operator<<(std::istream& istr, const Set& set);
};
