#include "MagicalContainer.hpp"

using namespace ariel;

    MagicalContainer::MagicalContainer(){}

    MagicalContainer::~MagicalContainer(){}

    void MagicalContainer::addElement(int element){
        /*
         initial the containers with the numbers 

            * not final - adjustable *
            
        */
        this->elements.push_back(element);
        this->ascContainer.push_back(element);
        this->PrimeContainer.push_back(element);
        this->sideCrossContainer.push_back(element);
    }

    void MagicalContainer::removeElement(int element){
    }

    int MagicalContainer::size() const{return this->elements.size();}





/*   -----------------    AscendingIterator      -----------------    */


    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
            : container(container){
                this->itr = container.getascContainer().begin();
            }

    MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator& other)
            : container(other.container){
                this->itr = other.container.getascContainer().begin();
            }

    MagicalContainer::AscendingIterator::~AscendingIterator(){}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other){return *this;}

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {return (this->index == other.index);}

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {return (this->index != other.index);}

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {return true;}

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {return true;}

    int MagicalContainer::AscendingIterator::operator*() const {
        return *itr;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(){
        // cout <<"inside ++: " <<  *itr << endl;
        ++itr;
        ++index;
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin(){
        // cout <<"inside begin: " <<  *container.getascContainer().begin() << endl;
        itr = container.getascContainer().begin();
        index = 0;
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end(){
        // cout <<"inside end: " <<  *container.getascContainer().end() << endl;
        itr = container.getascContainer().end();
        index = container.getascContainer().size();
        return *this;
    }




/*   -----------------    PrimeIterator      -----------------    */

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
            : container(container){
                this->itr = container.getPrimeContainer().begin();
            }

    MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator& other)
            : container(other.container){
                this->itr = other.container.getPrimeContainer().begin();
            }

    MagicalContainer::PrimeIterator::~PrimeIterator(){}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other){return *this;}

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {return (this->index == other.index);}

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {return (this->index != other.index);}

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {return true;}

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {return true;}

    int MagicalContainer::PrimeIterator::operator*() const {
        return *itr;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++(){
        // cout <<"inside ++: " <<  *itr << endl;
        ++itr;
        ++index;
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::begin(){
        // cout <<"inside begin: " <<  *container.getPrimeContainer().begin() << endl;
        itr = container.getPrimeContainer().begin();
        index = 0;
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::end(){
        // cout <<"inside end: " <<  *container.getPrimeContainer().end() << endl;
        itr = container.getPrimeContainer().end();
        index = container.getPrimeContainer().size();
        return *this;
    }


    /*   -----------------    SideCrossIterator      -----------------    */

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
            : container(container){
                this->itr = container.getsideCrossContainer().begin();
            }

    MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator& other)
            : container(other.container){
                this->itr = other.container.getsideCrossContainer().begin();
            }

    MagicalContainer::SideCrossIterator::~SideCrossIterator(){}

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){return *this;}

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {return (this->index == other.index);}

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {return (this->index != other.index);}

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {return true;}

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {return true;}

    int MagicalContainer::SideCrossIterator::operator*() const {
        return *itr;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++(){
        // cout <<"inside ++: " <<  *itr << endl;
        ++itr;
        ++index;
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::begin(){
        // cout <<"inside begin: " <<  *container.getsideCrossContainer().begin() << endl;
        itr = container.getsideCrossContainer().begin();
        index = 0;
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::end(){
        // cout <<"inside end: " <<  *container.getsideCrossContainer().end() << endl;
        itr = container.getsideCrossContainer().end();
        index = container.getsideCrossContainer().size();
        return *this;
    }