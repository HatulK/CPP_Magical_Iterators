#include <valarray>
#include <memory>
#include "MagicalContainer.hpp"

using namespace ariel;

///Magical container
void MagicalContainer::addElement(int num) {
    int *pointer(new int(num));
    regularContainer.insert(*pointer);
    if (isPrime(num)) primeContainer.insert(pointer);
}


void MagicalContainer::removeElement(int num) {
    int deleted = regularContainer.erase(num);
    if (deleted <= 0) throw std::invalid_argument("The number you wished to remove isn't found in the container.");
    if (isPrime(num)) {
        for (auto iterator = primeContainer.begin(); iterator != primeContainer.end();) {
            if (**iterator == num) {
                iterator = primeContainer.erase(iterator);
            } else {
                ++iterator;
            }
        }
    }
}

size_t MagicalContainer::size() const {
    return regularContainer.size();
}

bool MagicalContainer::operator==(const MagicalContainer &other) const {
    return regularContainer == other.regularContainer;
}

bool MagicalContainer::operator!=(const MagicalContainer &other) const {
    return regularContainer != other.regularContainer;
}


bool MagicalContainer::isPrime(int num) {
    if (num <= 1)
        return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

///End of magical container

///Inheritance iterator
MagicalContainer::inheritanceIterator::inheritanceIterator(MagicalContainer &magicalContainer) : magicalContainer(
        &magicalContainer), index(0) {}

MagicalContainer::inheritanceIterator::inheritanceIterator(const MagicalContainer::inheritanceIterator &other)
        : magicalContainer(other.magicalContainer), index(other.index) {}

bool MagicalContainer::inheritanceIterator::operator==(const MagicalContainer::inheritanceIterator &other) const{
    if (other.magicalContainer == this->magicalContainer) return index == other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

bool MagicalContainer::inheritanceIterator::operator!=(const MagicalContainer::inheritanceIterator &other) const{
    if (other.magicalContainer == this->magicalContainer) return index != other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

bool MagicalContainer::inheritanceIterator::operator>(const MagicalContainer::inheritanceIterator &other) const{
    if (other.magicalContainer == this->magicalContainer) return index > other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

bool MagicalContainer::inheritanceIterator::operator<(const MagicalContainer::inheritanceIterator &other) const{
    if (other.magicalContainer == this->magicalContainer) return index < other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}



///End of inheritance operator

///Start of ascending iterator


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : inheritanceIterator(container) {
    iterator = magicalContainer->regularContainer.begin();
}


MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if (iterator == magicalContainer->regularContainer.end()) {
        throw std::runtime_error("Iterator is out of range");
    }
    ++iterator;
    ++index;
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() const {
    if (iterator == magicalContainer->regularContainer.end())
        throw std::runtime_error("Iterator is out of range");
    return *iterator;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    AscendingIterator temp(*this);
    temp.iterator = magicalContainer->regularContainer.begin();
    temp.index = 0;
    return temp;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator temp(*this);
    temp.iterator = magicalContainer->regularContainer.end();
    temp.index = magicalContainer->regularContainer.size();
    return temp;
}

MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other) {
    if (this->magicalContainer != other.magicalContainer)
        throw std::runtime_error("Copying is available only for the same container");
    magicalContainer = other.magicalContainer;
    index = other.index;
    iterator = other.iterator;
    return *this;
}

///End off ascending iterator

///Start of prime iterator

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magicalContainer1) : inheritanceIterator(
        magicalContainer1) {}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (iterator == magicalContainer->primeContainer.end()) {
        throw std::runtime_error("Iterator is out of range");
    }
    ++iterator;
    ++index;
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() const {
    if (iterator == magicalContainer->primeContainer.end())
        throw std::runtime_error("Iterator is out of range");
    return **iterator;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    PrimeIterator temp(*this);
    temp.iterator = magicalContainer->primeContainer.begin();
    temp.index = 0;
    return temp;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator temp(*this);
    temp.iterator = magicalContainer->primeContainer.end();
    temp.index = magicalContainer->primeContainer.size();
    return temp;
}



///End if prime iterator

///Start of side cross iterator

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magicalContainer1) : inheritanceIterator(
        magicalContainer1) {
    if (magicalContainer->size() == 0) endIterator = magicalContainer->regularContainer.end();
    else {
        endIterator = --magicalContainer->regularContainer.end();
    }
}


MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (countOfJumps == magicalContainer->size()+2) throw std::runtime_error("iterator 111111 out of bounds\n");
    if (startOrEnd) {
        iterator++;
    } else {
        endIterator--;
    }
    startOrEnd = !startOrEnd;
    countOfJumps++;
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    if (countOfJumps == magicalContainer->size()+1 ) throw std::runtime_error("iterator asdfasdf out of bounds\n");
    if (startOrEnd) {
        return *iterator;
    }
    else{
        return *endIterator;
    }
}



MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    SideCrossIterator temp(*this);
    temp.iterator = magicalContainer->regularContainer.begin();
    temp.index = 0;
    return temp;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator temp(*this);
    temp.iterator = magicalContainer->regularContainer.end();
    temp.countOfJumps = (int)magicalContainer->regularContainer.size()+1;
    return temp;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return countOfJumps == other.countOfJumps;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return countOfJumps != other.countOfJumps;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    return false;
}


///End of side cross iterator
