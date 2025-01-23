#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    int index = 1;
    int temp1 = 0;
    while (l1 != nullptr) {
      temp1 += l1->val * index;
      index *= 10;
      l1 = l1->next;
    }

    int temp2 = 0;
    index = 1;
    while (l2 != nullptr) {
      temp2 += l2->val * index;
      index *= 10;
      l2 = l2->next;
    }

    std::string something = std::to_string(temp1 + temp2);
    const char *somethingdamn = something.c_str();
    std::cout << std::atoi(somethingdamn) << "\n";

    ListNode *result = new ListNode(something[something.length() - 1]);

    std::cout << result->val << "\n";

    // for (int i = something.length() - 1; i <= 0; i--) {
    //   ListNode *temp = new ListNode(something[i]);
    //   result_copy->next = temp;
    //   result_copy = result_copy->next;
    // }

    // while (result != nullptr) {
    // result = result->next;
    // }
    return result;
  }
};

int main(int argc, char *argv[]) {
  ListNode *a1 = new ListNode(2);
  ListNode *b1 = new ListNode(4);
  ListNode *c1 = new ListNode(3);
  a1->next = b1;
  b1->next = c1;

  ListNode *a2 = new ListNode(5);
  ListNode *b2 = new ListNode(6);
  ListNode *c2 = new ListNode(4);
  a2->next = b2;
  b2->next = c2;

  Solution sol;
  ListNode *result = sol.addTwoNumbers(a1, a2);
}
