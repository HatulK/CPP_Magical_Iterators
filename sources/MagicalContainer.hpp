//
// Created by vboxuser on 6/3/23.
//

#ifndef CPP_MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
#define CPP_MAGICAL_ITERATORS_MAGICALCONTAINER_HPP

#include <set>
#include <algorithm>
#include <stdexcept>

namespace ariel {
    struct Comparator {
        bool operator() (const int* a, const int* b) const {
            return *a < *b;
        }
    };


    class MagicalContainer {
        std::set<int> regularContainer; //No pointer, already sorted
        std::set<int *,Comparator> primeContainer;

    public:
        void addElement(int num);

        void removeElement(int num);

        size_t size() const;

        //Constructor
        MagicalContainer() = default;

        //Destructor
        ~MagicalContainer() = default;

        //Copy constructor
        MagicalContainer(const MagicalContainer &other) = default;

        //Move constructor
        MagicalContainer(MagicalContainer &&other) noexcept = default;

        MagicalContainer &operator=(MagicalContainer &&other) noexcept = default;

        MagicalContainer &operator=(const MagicalContainer &other)= default;

        bool operator==(const MagicalContainer &other) const;

        bool operator!=(const MagicalContainer &other) const;

        class inheritanceIterator;

        class AscendingIterator;

        class SideCrossIterator;

        class PrimeIterator;

        static bool isPrime(int num) ;
    };

    class MagicalContainer::inheritanceIterator {
    public:

        explicit inheritanceIterator(MagicalContainer &magicalContainer);

        inheritanceIterator(const inheritanceIterator &other);

        size_t getIndex() const;

        inheritanceIterator();

        ~inheritanceIterator();

        inheritanceIterator(inheritanceIterator &&other) noexcept ;

        inheritanceIterator &operator=(inheritanceIterator &&other) noexcept ;

        inheritanceIterator &operator=(const inheritanceIterator &other);

        virtual inheritanceIterator &operator++() = 0;

        virtual int operator*() =0;

        bool operator==(const inheritanceIterator &other) const;

        bool operator!=(const inheritanceIterator &other) const;

        bool operator>(const inheritanceIterator &other) const;

        bool operator<(const inheritanceIterator &other) const;

    protected:
        MagicalContainer magicalContainer;
        size_t index;
        std::set<int>::iterator iterator;
    };

    class MagicalContainer::AscendingIterator : public MagicalContainer::inheritanceIterator {
    public:
        explicit AscendingIterator(MagicalContainer &magicalContainer);

        AscendingIterator(const AscendingIterator &other) =default;

        AscendingIterator() = default;

        ~AscendingIterator() = default;

        AscendingIterator(AscendingIterator &&other) noexcept = default;

        AscendingIterator &operator=(AscendingIterator &&other) noexcept = default;

        AscendingIterator &operator=(const AscendingIterator &other);

        AscendingIterator &operator++() override;

        int operator*()  override;

        AscendingIterator begin();

        AscendingIterator end();
        
    };

    class MagicalContainer::PrimeIterator : public MagicalContainer::inheritanceIterator {
    public:
        explicit PrimeIterator(MagicalContainer &magicalContainer);

        PrimeIterator(const PrimeIterator &other) = default;

        PrimeIterator() = default;

        ~PrimeIterator() = default;

        PrimeIterator(PrimeIterator &&other) noexcept = default;

        PrimeIterator &operator=(PrimeIterator &&other) noexcept = default;

        PrimeIterator &operator=(const PrimeIterator &other);

        PrimeIterator &operator++() override;

        int operator*() override;


        PrimeIterator begin();

        PrimeIterator end();

    protected:
        std::set<int*>::iterator iterator;
    };

    class MagicalContainer::SideCrossIterator : public MagicalContainer::inheritanceIterator {
    public:
        explicit SideCrossIterator(MagicalContainer &magicalContainer);

        SideCrossIterator(const SideCrossIterator &other);

        SideCrossIterator() = default;

        ~SideCrossIterator() = default;

        SideCrossIterator(SideCrossIterator &&other) noexcept = default;

        SideCrossIterator &operator=(SideCrossIterator &&other) noexcept = default;

        SideCrossIterator &operator=(const SideCrossIterator &other);

        SideCrossIterator &operator++() override;

        int operator*() override;

        SideCrossIterator begin();

        SideCrossIterator end();

        bool operator==(const SideCrossIterator &other) const;

        bool operator!=(const SideCrossIterator &other) const;

        bool operator>(const SideCrossIterator &other) const;

        bool operator<(const SideCrossIterator &other) const;

    protected:
        std::set<int>::iterator endIterator;
        bool startOrEnd = true; // Start = true,  End = false;
        int countOfJumps = 1;
    };
}
#endif //CPP_MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
