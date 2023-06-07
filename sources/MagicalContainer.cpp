#include "MagicalContainer.hpp"

using namespace ariel;

///Magical container

void MagicalContainer::addElement(int num) {

}

void MagicalContainer::removeElement(int num) {

}

size_t MagicalContainer::size() const {
    return ascendingContainer.size();
}

bool MagicalContainer::operator==(const MagicalContainer &other) const {
    return ascendingContainer == other.ascendingContainer;
}

bool MagicalContainer::operator!=(const MagicalContainer &other) const {
    return ascendingContainer != other.ascendingContainer;
}

void MagicalContainer::updateAllVectors() {

}

///End of magical container

///Inheritance itreator
MagicalContainer::inheritanceIterator::inheritanceIterator(MagicalContainer &magicalContainer) {

}

MagicalContainer::inheritanceIterator::inheritanceIterator(const MagicalContainer::inheritanceIterator &other) {

}

bool MagicalContainer::inheritanceIterator::operator==(const MagicalContainer::inheritanceIterator &other) {
    return false;
}

bool MagicalContainer::inheritanceIterator::operator!=(const MagicalContainer::inheritanceIterator &other) {
    return false;
}

bool MagicalContainer::inheritanceIterator::operator>(const MagicalContainer::inheritanceIterator &other) {
    return false;
}

bool MagicalContainer::inheritanceIterator::operator<(const MagicalContainer::inheritanceIterator &other) {
    return false;
}


int MagicalContainer::inheritanceIterator::operator*() const {
    return 0;
}

///End of inheritance operator

///Start of ascending iterator


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : inheritanceIterator(container) {
    iterator = magicalContainer->ascendingContainer.begin();
}


MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return 0;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    return *this;
}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other)
        : inheritanceIterator(other) {

}

bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator &other) {
    return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &other) {
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &other) {
    return false;
}

bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &other) {
    return false;
}

///End off ascending iterator

///Start of prime iterator

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &magicalContainer1) : inheritanceIterator(
        magicalContainer1) {

}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other)  : inheritanceIterator(other) {

}


MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return 0;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator &other) {
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator &other) {
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) {
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) {
    return false;
}


///End if prime iterator

///Start of side cross iterator

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &magicalContainer1) : inheritanceIterator(
        magicalContainer1) {
}


MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return 0;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other)  : inheritanceIterator(other) {

}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) {
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) {
    return false;
}

///End of side cross iterator
