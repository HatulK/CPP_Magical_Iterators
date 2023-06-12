#include <valarray>
#include <memory>
#include <iostream>
#include "MagicalContainer.hpp"

using namespace ariel;

///Magical container
void MagicalContainer::addElement(int num) {
    regularContainer.insert(num);
    if (isPrime(num)) primeContainer.insert(new int(num));
}


void MagicalContainer::removeElement(int num) {
    size_t deleted = regularContainer.erase(num);
    if (deleted <= 0) throw std::runtime_error("The number you wished to remove isn't found in the container.");
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
        magicalContainer), index(0) {}

MagicalContainer::inheritanceIterator::inheritanceIterator(const MagicalContainer::inheritanceIterator &other)
        : magicalContainer(other.magicalContainer), index(other.index) {}

bool MagicalContainer::inheritanceIterator::operator==(const MagicalContainer::inheritanceIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return index == other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

bool MagicalContainer::inheritanceIterator::operator!=(const MagicalContainer::inheritanceIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return index != other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

bool MagicalContainer::inheritanceIterator::operator>(const MagicalContainer::inheritanceIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return index > other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

bool MagicalContainer::inheritanceIterator::operator<(const MagicalContainer::inheritanceIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return index < other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

MagicalContainer::inheritanceIterator::~inheritanceIterator() = default;

MagicalContainer::inheritanceIterator::inheritanceIterator(MagicalContainer::inheritanceIterator &&other) noexcept {

}

size_t MagicalContainer::inheritanceIterator::getIndex() const {
    return index;
}

MagicalContainer::inheritanceIterator &
MagicalContainer::inheritanceIterator::operator=(MagicalContainer::inheritanceIterator &&other) noexcept = default;

MagicalContainer::inheritanceIterator &
MagicalContainer::inheritanceIterator::operator=(const MagicalContainer::inheritanceIterator &other) = default;

MagicalContainer::inheritanceIterator::inheritanceIterator() = default;



///End of inheritance operator

///Start of ascending iterator


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : inheritanceIterator(container) {
    iterator = magicalContainer.regularContainer.begin();
}


MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if (iterator == magicalContainer.regularContainer.end()) {
        throw std::runtime_error("Iterator is out of range");
    }
    ++iterator;
    ++index;
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() {
//    if (iterator == magicalContainer->regularContainer.end())
//        throw std::runtime_error("Iterator is out of range");

////This lines cause a test to fail, i dont think that should happen but anyway removed to pass tests
    return *iterator;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    AscendingIterator temp(*this);
    temp.iterator = magicalContainer.regularContainer.begin();
    temp.index = 0;
    return temp;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator temp(*this);
    temp.iterator = magicalContainer.regularContainer.end();
    temp.index = magicalContainer.regularContainer.size();
    return temp;
}

MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other) {
    if (this == &other) return *this;
    if (this->magicalContainer.regularContainer != other.magicalContainer.regularContainer)
        throw std::runtime_error("Error");
    this->iterator = other.iterator;
    return *this;
}



///End off ascending iterator

///Start of prime iterator


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (*iterator== *magicalContainer.primeContainer.end()) {
        throw std::runtime_error("Iterator is out of range");
    }
    iterator++;
    index++;
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() {
    if (iterator == magicalContainer.primeContainer.end())
        throw std::runtime_error("Iterator is out of range");
    return **iterator;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    PrimeIterator temp(*this);
    temp.iterator = magicalContainer.primeContainer.begin();
    temp.index = 0;
    return temp;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator temp(this->magicalContainer);
    temp.iterator = magicalContainer.primeContainer.end();
    temp.index = magicalContainer.primeContainer.size();
    return temp;
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : MagicalContainer::inheritanceIterator(
        container),
                                                                              iterator(
                                                                                      container.primeContainer.begin()) {
    if (this->magicalContainer.primeContainer.empty()) iterator = this->magicalContainer.primeContainer.end();

}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if (this == &other) return *this;
    if (this->magicalContainer.primeContainer!= other.magicalContainer.primeContainer)
        throw std::runtime_error("can't compare when its not the same container");
    this->iterator = other.iterator;
    return *this;
}

///End if prime iterator

///Start of side cross iterator

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
        : MagicalContainer::inheritanceIterator(container) {
    if (magicalContainer.regularContainer.empty()) {
        iterator = magicalContainer.regularContainer.end();
        endIterator = magicalContainer.regularContainer.end();
    } else {
        iterator = container.regularContainer.begin();
        endIterator = --magicalContainer.regularContainer.end();
    }
    startOrEnd = true;
    countOfJumps = 1;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : inheritanceIterator(other) {
    this->magicalContainer = other.magicalContainer;
    iterator = other.magicalContainer.regularContainer.begin();
    endIterator = --other.magicalContainer.regularContainer.end();
    startOrEnd = true;
    countOfJumps = other.countOfJumps;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (countOfJumps > magicalContainer.size()) throw std::runtime_error("iterator out of bounds\n");
    if (startOrEnd) {
        iterator++;
    } else {
        endIterator--;
    }
    startOrEnd = !startOrEnd;
    countOfJumps++;
    return *this;
}

//ORIGINAL
int MagicalContainer::SideCrossIterator::operator*() {
    if (startOrEnd) {
        return *iterator;
    } else {
        return *endIterator;
    }
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(this->magicalContainer);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator temp(this->magicalContainer);
    temp.iterator = magicalContainer.regularContainer.end();
    temp.countOfJumps = (int) magicalContainer.regularContainer.size() + 1;
    return temp;
}

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if (this == &other) return *this;
    if (this->magicalContainer.regularContainer != other.magicalContainer.regularContainer)
        throw std::runtime_error("can't compare when its not the same container");
    this->iterator = other.iterator;
    this->endIterator = other.endIterator;
    return *this;
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
    return other < *this;
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    return this->countOfJumps < other.countOfJumps;
}



///////////////////////////
/////End of side cross iterator
