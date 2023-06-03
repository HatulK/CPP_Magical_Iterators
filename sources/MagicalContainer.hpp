//
// Created by vboxuser on 6/3/23.
//

#ifndef CPP_MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
#define CPP_MAGICAL_ITERATORS_MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

namespace ariel {
    class MagicalContainer {

    public:
        void addElement(int num);

        void removeElement(int num);

        size_t size() const;

        //Constructor
        MagicalContainer();

        //Destructor
        ~MagicalContainer();

        //Copy constructor
        MagicalContainer(const MagicalContainer &other);

        //Move constructor
        MagicalContainer(MagicalContainer &&other);

    private:
        std::vector<int> primeContainer;
        std::vector<int> ascendingContainer;
        std::vector<int> sideCrossContainer;

        //I've written public 2 times in order to split between magical container functions and the rest of the code.
    public:
        class inheritanceIterator {
        public:

            bool operator==(const inheritanceIterator &other);

            bool operator!=(const inheritanceIterator &other) const;

            bool operator>(const inheritanceIterator &other) const;

            bool operator<(const inheritanceIterator &other) const;

            int operator*();

        private:
            int *num{};
        };

        class AscendingIterator : public inheritanceIterator {
        public:
            AscendingIterator();

            ~AscendingIterator();

            explicit AscendingIterator(MagicalContainer &container);

            AscendingIterator(const AscendingIterator &other);

            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator &operator++();

            AscendingIterator begin();

            AscendingIterator end();
        };

        class PrimeIterator : public inheritanceIterator {
        public:
            explicit PrimeIterator(MagicalContainer &container);

            PrimeIterator();

            PrimeIterator(const PrimeIterator &other);

            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator++();

            PrimeIterator begin();

            PrimeIterator end();
        };

        class SideCrossIterator : public inheritanceIterator {
        public:
            explicit SideCrossIterator(MagicalContainer &container);

            SideCrossIterator();

            SideCrossIterator(const SideCrossIterator &other);

            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator++();

            SideCrossIterator begin();

            SideCrossIterator end();
        };
    };
}

#endif //CPP_MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
