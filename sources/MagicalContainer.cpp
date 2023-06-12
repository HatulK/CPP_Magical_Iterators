#include <valarray>
#include <memory>
#include <iostream>
#include "MagicalContainer.hpp"

using namespace ariel;

/// Magical container

// Add an element to the container
void MagicalContainer::addElement(int num) {
    regularContainer.insert(num); // Insert element into regularContainer set
    if (isPrime(num)) primeContainer.insert(new int(num)); // Insert element into primeContainer set if it is prime
}

// Remove an element from the container
void MagicalContainer::removeElement(int num) {
    size_t deleted = regularContainer.erase(num); // Erase element from regularContainer set
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

// Get the size of the container
size_t MagicalContainer::size() const {
    return regularContainer.size();
}

// Equality comparison operator
bool MagicalContainer::operator==(const MagicalContainer &other) const {
    return regularContainer == other.regularContainer;
}

// Inequality comparison operator
bool MagicalContainer::operator!=(const MagicalContainer &other) const {
    return regularContainer != other.regularContainer;
}

// Check if a number is prime
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

/// End of magical container

/// Inheritance iterator

// Constructor for the inheritance iterator
MagicalContainer::inheritanceIterator::inheritanceIterator(MagicalContainer &magicalContainer)
        : magicalContainer(magicalContainer), index(0) {}

// Copy constructor for the inheritance iterator
MagicalContainer::inheritanceIterator::inheritanceIterator(const MagicalContainer::inheritanceIterator &other)
        : magicalContainer(other.magicalContainer), index(other.index) {}

// Equality comparison operator for the inheritance iterator
bool MagicalContainer::inheritanceIterator::operator==(const MagicalContainer::inheritanceIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return index == other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

// Inequality comparison operator for the inheritance iterator
bool MagicalContainer::inheritanceIterator::operator!=(const MagicalContainer::inheritanceIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return index != other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

// Greater than comparison operator for the inheritance iterator
bool MagicalContainer::inheritanceIterator::operator>(const MagicalContainer::inheritanceIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return index > other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

// Less than comparison operator for the inheritance iterator
bool MagicalContainer::inheritanceIterator::operator<(const MagicalContainer::inheritanceIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return index < other.index;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

// Destructor for the inheritance iterator
MagicalContainer::inheritanceIterator::~inheritanceIterator() = default;

// Move constructor for the inheritance iterator
MagicalContainer::inheritanceIterator::inheritanceIterator(
        MagicalContainer::inheritanceIterator &&other) noexcept = default;

// Get the current index of the inheritance iterator
size_t MagicalContainer::inheritanceIterator::getIndex() const {
    return index;
}

// Move assignment operator for the inheritance iterator
MagicalContainer::inheritanceIterator &
MagicalContainer::inheritanceIterator::operator=(MagicalContainer::inheritanceIterator &&other) noexcept = default;

// Copy assignment operator for the inheritance iterator
MagicalContainer::inheritanceIterator &
MagicalContainer::inheritanceIterator::operator=(const MagicalContainer::inheritanceIterator &other) = default;

// Default constructor for the inheritance iterator
MagicalContainer::inheritanceIterator::inheritanceIterator() = default;

// Ascending iterator

// Constructor for the ascending iterator
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : inheritanceIterator(container) {
    iterator = magicalContainer.regularContainer.begin();
}

// Pre-increment operator for the ascending iterator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if (iterator == magicalContainer.regularContainer.end()) {
        throw std::runtime_error("Iterator is out of range");
    }
    ++iterator;
    ++index;
    return *this;
}

// Dereference operator for the ascending iterator
int MagicalContainer::AscendingIterator::operator*() {
    return *iterator;
}

// Get the beginning iterator of the ascending iterator
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    AscendingIterator temp(*this);
    temp.iterator = magicalContainer.regularContainer.begin();
    temp.index = 0;
    return temp;
}

// Get the ending iterator of the ascending iterator
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator temp(*this);
    temp.iterator = magicalContainer.regularContainer.end();
    temp.index = magicalContainer.regularContainer.size();
    return temp;
}

// Assignment operator for the ascending iterator
MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other) {
    if (this == &other) return *this;
    if (this->magicalContainer.regularContainer != other.magicalContainer.regularContainer)
        throw std::runtime_error("Error");
    this->iterator = other.iterator;
    return *this;
}

///End of ascending iterator

///Start of prime iterator

// Pre-increment operator for the prime iterator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (*iterator == *magicalContainer.primeContainer.end()) {
        throw std::runtime_error("Iterator is out of range");
    }
    iterator++;
    index++;
    return *this;
}

// Dereference operator for the prime iterator
int MagicalContainer::PrimeIterator::operator*() {
    if (iterator == magicalContainer.primeContainer.end())
        throw std::runtime_error("Iterator is out of range");
    return **iterator;
}

// Get the beginning iterator of the prime iterator
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    PrimeIterator temp(*this);
    temp.iterator = magicalContainer.primeContainer.begin();
    temp.index = 0;
    return temp;
}

// Get the ending iterator of the prime iterator
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator temp(this->magicalContainer);
    temp.iterator = magicalContainer.primeContainer.end();
    temp.index = magicalContainer.primeContainer.size();
    return temp;
}

// Constructor for the prime iterator
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : MagicalContainer::inheritanceIterator(
        container),
                                                                              iterator(
                                                                                      container.primeContainer.begin()) {
    if (this->magicalContainer.primeContainer.empty()) iterator = this->magicalContainer.primeContainer.end();
}

// Assignment operator for the prime iterator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if (this == &other) return *this;
    if (this->magicalContainer.primeContainer != other.magicalContainer.primeContainer)
        throw std::runtime_error("can't compare when its not the same container");
    this->iterator = other.iterator;
    return *this;
}

///End if prime iterator

///Start of side cross iterator

// Constructor for the side cross iterator
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

// Copy constructor for the side cross iterator
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : inheritanceIterator(other) {
    this->magicalContainer = other.magicalContainer;
    iterator = other.magicalContainer.regularContainer.begin();
    endIterator = --other.magicalContainer.regularContainer.end();
    startOrEnd = true;
    countOfJumps = other.countOfJumps;
}

// Pre-increment operator for the side cross iterator
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

// Dereference operator for the side cross iterator
int MagicalContainer::SideCrossIterator::operator*() {
    if (startOrEnd) {
        return *iterator;
    } else {
        return *endIterator;
    }
}

// Get the beginning iterator of the side cross iterator
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(this->magicalContainer);
}

// Get the ending iterator of the side cross iterator
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator temp(this->magicalContainer);
    temp.iterator = magicalContainer.regularContainer.end();
    temp.countOfJumps = (int) magicalContainer.regularContainer.size() + 1;
    return temp;
}

// Assignment operator for the side cross iterator
MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if (this == &other) return *this;
    if (this->magicalContainer.regularContainer != other.magicalContainer.regularContainer)
        throw std::runtime_error("can't compare when its not the same container");
    this->iterator = other.iterator;
    this->endIterator = other.endIterator;
    return *this;
}

// Equality comparison operator for the side cross iterator
bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return countOfJumps == other.countOfJumps;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

// Inequality comparison operator for the side cross iterator
bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    if (other.magicalContainer == this->magicalContainer) return countOfJumps != other.countOfJumps;
    else throw std::invalid_argument("Comparing is available only when there is the same Magical Container.");
}

// Greater than comparison operator for the side cross iterator
bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    return other < *this;
}

// Less than comparison operator for the side cross iterator
bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    return this->countOfJumps < other.countOfJumps;
}

/////End of side cross iterator
