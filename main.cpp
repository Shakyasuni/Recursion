#include <iostream>
#include "recursive_list.h"
#include "project2.h"

int main() {
  RecursiveList listA = MakeList();
  RecursiveList listB = MakeList();
  for (int i = 5; i > 0; i--) {
    listA = MakeList(i, listA);
    listB = MakeList(i + 10, listB);
  }

  std::cout << "Original: " << std::endl;
  PrintList(listA);
  std::cout << std::endl;
  PrintList(listB);
  std::cout << std::endl;

  std::cout << "QUESTION 1" << std::endl;
  std::cout << "Sum: " << std::endl;
  std::cout << Sum(listA) <<std::endl;
  std::cout << Sum(listB) <<std::endl;

  std::cout << "Product: " << std::endl;
  std::cout << Product(listA) <<std::endl;
  std::cout << Product(listB) <<std::endl;

  std::cout << "QUESTION 2" << std::endl;
  std::cout << "Sum (Tail Recursive): " << std::endl;
  std::cout << TailRecursiveSum(listA) <<std::endl;
  std::cout << TailRecursiveSum(listB) <<std::endl;

  std::cout << "QUESTION 3" << std::endl;
  std::cout << "Filter Even: " << std::endl;
  PrintList(FilterEven(listA));
  std::cout << std::endl;
  PrintList(FilterEven(listB));
  std::cout << std::endl;

  std::cout << "Filter Odd: " << std::endl;
  PrintList(FilterOdd(listA));
  std::cout << std::endl;
  PrintList(FilterOdd(listB));
  std::cout << std::endl;

  std::cout << "QUESTION 4" << std::endl;
  std::cout << "Reverse: " << std::endl;
  PrintList(Reverse(listA));
  std::cout << std::endl;
  PrintList(Reverse(listB));
  std::cout << std::endl;
  
  std::cout << "QUESTION 5" << std::endl;
  std::cout << "Append: " << std::endl;
  PrintList(Append(listA, listB));
  std::cout << std::endl;

  std::cout << "QUESTION 6" << std::endl;
  std::cout << "Chop: " << std::endl;
  PrintList(Chop(listA, 0));
  std::cout << std::endl;
  PrintList(Chop(listA, 1));
  std::cout << std::endl;
  PrintList(Chop(listA, 2));
  std::cout << std::endl;
  PrintList(Chop(listA, 3));
  std::cout << std::endl;

  std::cout << "QUESTION 7" << std::endl;
  std::cout << "Rotate: " << std::endl;
  PrintList(Rotate(listA, 0));
  std::cout << std::endl;
  PrintList(Rotate(listA, 1));
  std::cout << std::endl;
  PrintList(Rotate(listA, 2));
  std::cout << std::endl;
  PrintList(Rotate(listA, 3));
  std::cout << std::endl;

  std::cout << "QUESTION 8" << std::endl;
  std::cout << "Insert List: " << std::endl;
  PrintList(InsertList(listA, listB, 0));
  std::cout << std::endl;
  PrintList(InsertList(listA, listB, 1));
  std::cout << std::endl;
  PrintList(InsertList(listA, listB, 2));
  std::cout << std::endl;
  PrintList(InsertList(listA, listB, 3));
  std::cout << std::endl;
}

