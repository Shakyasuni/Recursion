#include "recursive_list.h"
#include "project2.h"

int Sum(RecursiveList list) {
  if(ListIsEmpty(list)){
    return 0;
  }
  return ListFirst(list) + Sum(ListRest(list));
}


int Product(RecursiveList list) {
  if(ListIsEmpty(list)){
    return 1;
  }
  return ListFirst(list) * Product(ListRest(list));
}

int TailRecursiveSumHelper(RecursiveList list, int sum_so_far) {
  if(ListIsEmpty(list)){
    return sum_so_far;
  }
  sum_so_far += ListFirst(list);
  return TailRecursiveSumHelper(ListRest(list), sum_so_far);
}


int TailRecursiveSum(RecursiveList list) {
  return TailRecursiveSumHelper(list, 0);
}

RecursiveList FilterOddHelper(RecursiveList list, RecursiveList odd_list) {
  if(ListIsEmpty(list)){
    return Reverse(odd_list);
  }
  if(ListFirst(list) % 2 != 0){
    odd_list = MakeList(ListFirst(list), odd_list);
  }
    return FilterOddHelper(ListRest(list), odd_list);
}


RecursiveList FilterOdd(RecursiveList list) {
  RecursiveList odd_list = MakeList();
  return FilterOddHelper(list, odd_list);
}


RecursiveList FilterEvenHelper(RecursiveList list, RecursiveList even_list) {
  if(ListIsEmpty(list)){
    return Reverse(even_list);
  }
  if(ListFirst(list) % 2 == 0){
    even_list = MakeList(ListFirst(list), even_list);
  }
  return FilterEvenHelper(ListRest(list), even_list);
}


RecursiveList FilterEven(RecursiveList list) {
  RecursiveList even_list = MakeList();
  return FilterEvenHelper(list, even_list);
}


RecursiveList ReverseHelper(RecursiveList list, RecursiveList reverse_list){
  if(ListIsEmpty(list)){
    return reverse_list;
  }
  reverse_list = MakeList(ListFirst(list), reverse_list);
  return ReverseHelper(ListRest(list), reverse_list);
}


RecursiveList Reverse(RecursiveList list){
  RecursiveList reverse_list = MakeList();
  return ReverseHelper(list, reverse_list);
}


RecursiveList AppendHelper(RecursiveList first_list, RecursiveList second_list,RecursiveList merge_list) {
  if(ListIsEmpty(first_list)){
    if(ListIsEmpty(second_list)){
      return Reverse(merge_list);
    }
  }
  if(!ListIsEmpty(first_list)){
    merge_list = MakeList(ListFirst(first_list), merge_list);
    return AppendHelper(ListRest(first_list), second_list, merge_list);
  }else{
    merge_list = MakeList(ListFirst(second_list), merge_list);
    return AppendHelper(first_list, ListRest(second_list), merge_list);
  }
}


RecursiveList Append(RecursiveList first_list, RecursiveList second_list) {
  RecursiveList merge_list = MakeList();
  return AppendHelper(first_list, second_list, merge_list);
}

RecursiveList ChopHelper(RecursiveList list, unsigned int n, RecursiveList chopped_list) {
  if(ListIsEmpty(list)){
    return chopped_list;
  }
  if(n != 0){
    n--;
    return ChopHelper(ListRest(list), n, chopped_list);
  }
  chopped_list = MakeList(ListFirst(list), chopped_list);
  return ChopHelper(ListRest(list), n, chopped_list);
}

RecursiveList Chop(RecursiveList list, unsigned int n) {
  RecursiveList chopped_list = MakeList();
  list = Reverse(list);
  return ChopHelper(list, n, chopped_list);
}


RecursiveList RotateHelper(RecursiveList list, unsigned int n, RecursiveList RotateInitial, RecursiveList RotateFinal){  
  if(ListIsEmpty(list)){
    return Append(Reverse(RotateFinal),Reverse(RotateInitial));
  }
  if(n != 0){
    n--;
    RotateInitial = MakeList(ListFirst(list),RotateInitial);
    return RotateHelper(ListRest(list),n,RotateInitial,RotateFinal);
  }
  RotateFinal = MakeList(ListFirst(list),RotateFinal);
  return RotateHelper(ListRest(list),n,RotateInitial,RotateFinal);
}

RecursiveList Rotate(RecursiveList list, unsigned int n) {
  RecursiveList RotateInitial = MakeList();
  RecursiveList RotateFinal = MakeList();
  return RotateHelper(list, n, RotateInitial, RotateFinal);
}


RecursiveList InsertListHelper(RecursiveList first_list, RecursiveList second_list,unsigned int n, RecursiveList finalList, RecursiveList tempList){
  if(n != 0){
    n--;
    finalList = Append(finalList, MakeList(ListFirst(first_list), MakeList()));
    return InsertListHelper(ListRest(first_list), second_list,n,finalList,tempList);
  }
  if(!ListIsEmpty(first_list)){
    tempList = first_list;
    return InsertListHelper(MakeList(), second_list,n,finalList,tempList);
  }
  if(!ListIsEmpty(second_list)){
    finalList = Append(finalList, Append(second_list, tempList));
    return finalList;
  }
}


RecursiveList InsertList(RecursiveList first_list, RecursiveList second_list,
                         unsigned int n) {
  if (n == 0) {
    return Append(second_list, first_list);
  }
  if (ListIsEmpty(second_list)) {
    return first_list;
  }
  RecursiveList finalList = MakeList();
  RecursiveList tempList = MakeList();
  return InsertListHelper(first_list,second_list,n,finalList,tempList);
}

