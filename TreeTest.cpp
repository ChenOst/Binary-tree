/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree; 
  ariel::Tree mytree; 
  ariel::Tree mytree2; 
  ariel::Tree mytree3; 

  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  mytree.insert(1);
  mytree.insert(2);
  mytree.insert(3);
  mytree.insert(4);
  mytree.insert(5);
  mytree.insert(6);

  mytree2.insert(8);
  mytree2.insert(7);
  mytree2.insert(6);
  mytree2.insert(5);
  mytree2.insert(4);
  mytree2.insert(3);

  mytree3.insert(4);
  mytree3.insert(5);
  mytree3.insert(2);
  mytree3.insert(1);
  mytree3.insert(3);
  mytree3.insert(7);
  mytree3.insert(6);
  mytree3.insert(8);

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (mytree.contains(3), true)
  .CHECK_THROWS(mytree.insert(3))
  .CHECK_EQUAL (mytree.right(1), 2)
  .CHECK_OK    (mytree.remove(1))
  .CHECK_EQUAL (mytree.root(), 2)
  .CHECK_THROWS(mytree.remove(1))
  .CHECK_EQUAL (mytree.size() ,5)
  .CHECK_THROWS(mytree.right(10))
  .CHECK_OK    (mytree.print())

  .CHECK_EQUAL (mytree2.size(), 6)
  .CHECK_EQUAL (mytree2.root(), 8)
  .CHECK_EQUAL (mytree2.left(8), 7)
  .CHECK_OK    (mytree2.remove(7))
  .CHECK_EQUAL (mytree2.left(8), 6)
  .CHECK_OK    (mytree2.remove(8))
  .CHECK_THROWS(mytree2.remove(8))
  .CHECK_EQUAL (mytree2.root(), 6)
  .CHECK_OK    (mytree2.print())

  .CHECK_EQUAL (mytree3.root(), 4)
  .CHECK_EQUAL (mytree3.left(4), 2)
  .CHECK_EQUAL (mytree3.right(4), 5)
  .CHECK_OK    (mytree3.remove(2))
  .CHECK_OK    (mytree3.remove(5))
  .CHECK_EQUAL (mytree3.left(4), 3)
  .CHECK_EQUAL (mytree3.right(4), 7)
  .CHECK_THROWS(mytree3.remove(2))
  .CHECK_EQUAL (mytree3.contains(5), false)
  .CHECK_EQUAL (mytree3.size(), 6)



  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}