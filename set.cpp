#include "set.h"
#include <vector>

Set::Set(size_t mp): _bitField(mp){
}
Set::Set(const Set& set): _maxPower(set._maxPower), _bitField(set._bitField){ //конструктор копирования
}
Set::Set(const BitField& bf):_maxPower(bf.GetLength()), _bitField(bf){//конструктор преобразования
}
Set::operator BitField(){ //оператор, который что-то принимает
    return _bitField;
}
size_t Set::GetMaxPower(){
    return _maxPower;
}
void Set:: InsertElem(uint64_t elem){ //вставить элемент
    if (elem<_maxPower){
        _bitField.SetBit(elem);
    }
}
void Set:: DeleteElem(uint64_t elem){
    if (elem < _maxPower){
        _bitField.ClrBit(elem);
    }
}
bool Set::IsMember(uint64_t elem){ //проверяет, является ли элемент элементом множества
    return elem < _maxPower && _bitField.GetBit(elem);
}
bool Set:: operator==(const Set& tmp){
    if (_maxPower != tmp._maxPower){
        return false;
    }
    return _bitField == tmp._maxPower;
}
Set& Set::operator=(const Set& tmp){
    _maxPower = tmp._maxPower;
    _bitField = tmp._bitField;
    return *this;
}
Set Set:: operator+(const Set& tmp){//объединение двух множеств
    Set result(_maxPower);
    result._bitField = _bitField | tmp._bitField;
    return result;
}
Set Set:: operator+(uint64_t elem){//добавить элемент в множество
    Set result(*this);
    result.InsertElem(elem);
    return result;
}
Set Set:: operator-(uint64_t elem){//убрать элемент из множества
    Set result(*this);
    result.DeleteElem(elem);
    return result;
}
Set Set:: operator*(const Set& tmp){//пересечение множеств
    Set result(_maxPower);
    result._bitField = _bitField & tmp._bitField;
    return result;
}
Set Set:: operator~(){//дополнение
    Set result(_maxPower);
    result._bitField = _bitField;
    return result;
}

std::vector<uint64_t> Set:: GetPrimary(){
    BitField b = _bitField;
    std::vector<uint64_t> array;
    for (size_t i=2; i<_maxPower; i++){
        if (b.GetBit(i)){
            
        }
    }

}
