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
        std::vector<int> ascendingContainer;
        std::vector<int *> primeContainer;

    public:
        void addElement(int num);

        void removeElement(int num);

        size_t size() const;

        void updateAllVectors();

        //Constructor
        MagicalContainer() = default;

        //Destructor
        ~MagicalContainer() = default;

        //Copy constructor
        MagicalContainer(const MagicalContainer &other) = default;

        //Move constructor
        MagicalContainer(MagicalContainer &&other) noexcept = default;

        MagicalContainer &operator=(MagicalContainer &&other) noexcept = default;

        //== operator
        bool operator==(const MagicalContainer &other) const;

        // != operator
        bool operator!=(const MagicalContainer &other) const;

        class inheritanceIterator;

        class AscendingIterator;

        class SideCrossIterator;

        class PrimeIterator;
    };

    class MagicalContainer::inheritanceIterator {
    public:

        explicit inheritanceIterator(MagicalContainer &magicalContainer);

        inheritanceIterator(const inheritanceIterator &other);

        inheritanceIterator() = default;

        ~inheritanceIterator() = default;

        inheritanceIterator(inheritanceIterator &&other) noexcept = default;

        inheritanceIterator &operator=(inheritanceIterator &&other) noexcept = default;

        inheritanceIterator &operator=(const inheritanceIterator &other) = default;

        virtual inheritanceIterator &operator++() = 0;

        virtual int operator*() const;

        bool operator==(const inheritanceIterator &other);

        bool operator!=(const inheritanceIterator &other);

        bool operator>(const inheritanceIterator &other);

        bool operator<(const inheritanceIterator &other);

    protected:
        MagicalContainer *magicalContainer{};
    };

    class MagicalContainer::AscendingIterator : public MagicalContainer::inheritanceIterator {
    public:
        explicit AscendingIterator(MagicalContainer &magicalContainer);

        AscendingIterator(const AscendingIterator &other);

        AscendingIterator() = default;

        ~AscendingIterator() = default;

        AscendingIterator(AscendingIterator &&other) noexcept = default;

        AscendingIterator &operator=(AscendingIterator &&other) noexcept = default;

        AscendingIterator &operator=(const AscendingIterator &other) = default;

        AscendingIterator &operator++() override;

        int operator*() const override;

        bool operator==(const AscendingIterator &other);

        bool operator!=(const AscendingIterator &other);

        bool operator>(const AscendingIterator &other);

        bool operator<(const AscendingIterator &other);

        AscendingIterator begin();

        AscendingIterator end();
        
    protected:
        std::vector<int>::iterator iterator;
        size_t index{};
    };

    class MagicalContainer::PrimeIterator : public MagicalContainer::inheritanceIterator {
    public:
        explicit PrimeIterator(MagicalContainer &magicalContainer);

        PrimeIterator(const PrimeIterator &other);

        PrimeIterator() = default;

        ~PrimeIterator() = default;

        PrimeIterator(PrimeIterator &&other) noexcept = default;

        PrimeIterator &operator=(PrimeIterator &&other) noexcept = default;

        PrimeIterator &operator=(const PrimeIterator &other) = default;

        PrimeIterator &operator++() override;

        int operator*() const override;

        bool operator==(const PrimeIterator &other);

        bool operator!=(const PrimeIterator &other);

        bool operator>(const PrimeIterator &other);

        bool operator<(const PrimeIterator &other);

        PrimeIterator begin();

        PrimeIterator end();

    protected:
        std::vector<int*>::iterator iterator;
        size_t index{};
    };

    class MagicalContainer::SideCrossIterator : public MagicalContainer::inheritanceIterator {
    public:
        explicit SideCrossIterator(MagicalContainer &magicalContainer);

        SideCrossIterator(const SideCrossIterator &other);

        SideCrossIterator() = default;

        ~SideCrossIterator() = default;

        SideCrossIterator(SideCrossIterator &&other) noexcept = default;

        SideCrossIterator &operator=(SideCrossIterator &&other) noexcept = default;

        SideCrossIterator &operator=(const SideCrossIterator &other) = default;

        SideCrossIterator &operator++() override;

        int operator*() const override;

        bool operator==(const SideCrossIterator &other);

        bool operator!=(const SideCrossIterator &other);

        bool operator>(const SideCrossIterator &other);

        bool operator<(const SideCrossIterator &other);

        SideCrossIterator begin();

        SideCrossIterator end();

    protected:
        std::vector<int>::iterator iterator;
        size_t index{}; 
    };
}
#endif //CPP_MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
