#include "MagicalContainer.hpp"

using namespace ariel;
////MAGICAL CONTAINER
//Constructor
MagicalContainer::MagicalContainer() = default;

//Destructor
MagicalContainer::~MagicalContainer() = default;

//Copy Constructor
MagicalContainer::MagicalContainer(const MagicalContainer &other) {

}

//Move constructor
MagicalContainer::MagicalContainer(MagicalContainer &&other) {

}

//Add element to the container
void MagicalContainer::addElement(int num) {

}

//Delete an element from the container
void MagicalContainer::removeElement(int num) {

}

//Return the size of the container
size_t MagicalContainer::size() const {
    return 0;
}

////ASCENDING ITERATOR
MagicalContainer::AscendingIterator::AscendingIterator() = default;

MagicalContainer::AscendingIterator::~AscendingIterator() = default;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) {}


MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) {

}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {

    return *this;
}


MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {

    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {

    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {

    return *this;
}

//// SideCrossIterator
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) {

}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) {

}

MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {

    return *this;
}


MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {

    return *this;
}


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {

    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {

    return *this;
}

MagicalContainer::SideCrossIterator::SideCrossIterator() {

}

//// PrimeIterator
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) {

}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) {

}

MagicalContainer::PrimeIterator::~PrimeIterator() = default;

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {

    return *this;
}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {

    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {

    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {

    return *this;
}

MagicalContainer::PrimeIterator::PrimeIterator() {

}

bool MagicalContainer::inheritanceIterator::operator>(const MagicalContainer::inheritanceIterator &other) const {
    return false;
}

bool MagicalContainer::inheritanceIterator::operator<(const MagicalContainer::inheritanceIterator &other) const {
    return false;
}


bool MagicalContainer::inheritanceIterator::operator!=(const MagicalContainer::inheritanceIterator &other) const {
    return false;
}

int MagicalContainer::inheritanceIterator::operator*() {
    return 0;
}

bool MagicalContainer::inheritanceIterator::operator==(const MagicalContainer::inheritanceIterator &other) {
    return false;
}
