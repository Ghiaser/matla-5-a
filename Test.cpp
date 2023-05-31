
#include "sources/MagicalContainer.hpp" //no need for other includes

using namespace std;
using namespace ariel;

#include "doctest.h"
#include <stdexcept>
#include <list>

TEST_CASE("MagicalContainer Test") {

    MagicalContainer container;
    CHECK_EQ(container.size(), 0);

    container.addElement(1);
    CHECK_EQ(container.size(), 1);

    CHECK_THROWS(container.removeElement(10));   // element doesnt exist

    container.removeElement(1);
    CHECK_EQ(container.size(), 0);

    CHECK_THROWS(container.removeElement(10));   // empty  Container
}

TEST_CASE("AscendingIterator Test") {
    MagicalContainer container;

    MagicalContainer::AscendingIterator it(container);

    container.addElement(1);
    container.addElement(13);
    container.addElement(4);
    container.addElement(10);
    container.addElement(7);

    CHECK(*it.begin() == 1);                     // first element 1
    // CHECK(*it.end() == 13);                      // last 13

    MagicalContainer::AscendingIterator copy_it(it);               // using copy constructor

    CHECK(it.begin() == copy_it.begin());        /* same iterator */
    CHECK(it.end() == copy_it.end());

    CHECK_FALSE( it != copy_it );
    ++it;                                         // increment iterator it
    CHECK( it != copy_it );                       // should be not equal

    CHECK(it > copy_it);                          // compare the index not the value
    CHECK(copy_it < it);                          // opposite is correct
    
    ++copy_it;                                    // increment iterator copy_it
    CHECK( it == copy_it );                       // should return equals


    MagicalContainer otherContainer;              // define another container
    MagicalContainer::AscendingIterator other_it(otherContainer);   // define another AscendingIterator iterator

    /* cannot compare between two different containers */
    CHECK_THROWS(it.operator>(other_it));
    CHECK_THROWS(it.operator<(other_it));
    CHECK_THROWS(other_it.operator==(copy_it));

    otherContainer.addElement(4);      

    MagicalContainer::AscendingIterator ascIter(container);

    int i=1;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        CHECK(*it == i);                          // 1 4 7 10 13
        i+=3;
    }
}

TEST_CASE("SideCrossIterator Test") {
    MagicalContainer container;

    MagicalContainer::SideCrossIterator it(container);

    container.addElement(1);
    container.addElement(13);
    container.addElement(4);
    container.addElement(10);
    container.addElement(7);

    CHECK(*it.begin() == 1);                     // first element 1
    CHECK(*it.end() == 7);                       // last 7

    MagicalContainer::SideCrossIterator copy_it(it);                // using copy constructor

    CHECK(it.begin() == copy_it.begin());        /* same iterator */
    CHECK(it.end() == copy_it.end());

    CHECK_FALSE( it != copy_it );
    ++it;                                         // increment iterator it
    CHECK( it != copy_it );                       // should be not equal

    CHECK(it > copy_it);                          // compare the index not the value
    CHECK(copy_it < it);                          // opposite is correct
    
    ++copy_it;                                    // increment iterator copy_it
    CHECK( it == copy_it );                       // should return equals


    MagicalContainer otherContainer;              // define another container
    MagicalContainer::SideCrossIterator other_it(otherContainer);   // define another AscendingIterator iterator

    /* cannot compare between two different containers */
    CHECK_THROWS(it.operator>(other_it));
    CHECK_THROWS(it.operator<(other_it));
    CHECK_THROWS(other_it.operator==(copy_it));

    otherContainer.addElement(4);       

    MagicalContainer::SideCrossIterator sideCrossIter(container);

    int lst[] = {1,13,4,10,7};
    int i=0;
    for (auto it = sideCrossIter.begin(); it != sideCrossIter.end(); ++it) {
        CHECK(*it == lst[i]);                   // 1 13 4 10 7
        i++;
    }
}

TEST_CASE("PrimeIterator Test") {
    MagicalContainer container;

    MagicalContainer::PrimeIterator it(container);

    container.addElement(1);
    container.addElement(13);
    container.addElement(4);
    container.addElement(10);
    container.addElement(7);
    container.addElement(19);

    CHECK(*it.begin() == 13);                    // first prime number element 13
    CHECK(*it.end() == 19);                      // last 19

    MagicalContainer::PrimeIterator copy_it(it);                    // using copy constructor

    CHECK(it.begin() == copy_it.begin());        /* same iterator */
    CHECK(it.end() == copy_it.end());

    CHECK_FALSE( it != copy_it );
    ++it;                                         // increment iterator it
    CHECK( it != copy_it );                       // should be not equal

    CHECK(it > copy_it);                          // compare the index not the value
    CHECK(copy_it < it);                          // opposite is correct
    
    ++copy_it;                                    // increment iterator copy_it
    CHECK( it == copy_it );                       // should return equals


    MagicalContainer otherContainer;              // define another container
    MagicalContainer::PrimeIterator other_it(otherContainer);       // define another AscendingIterator iterator

    /* cannot compare between two different containers */
    CHECK_THROWS(it.operator>(other_it));
    CHECK_THROWS(it.operator<(other_it));
    CHECK_THROWS(other_it.operator==(copy_it));

    otherContainer.addElement(4);       

    MagicalContainer::PrimeIterator ascIter(container);

    int lst[] = {13,7,19};
    int i=0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        CHECK(*it == lst[i]);                          // 13 7 19
        i++;
    }
}