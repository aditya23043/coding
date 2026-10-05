#include <stdio.h>
#include <stdlib.h>

struct ListNode *create_list_node(int values[], int count);
void free_list(struct ListNode *head);

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {

  int mult = 1;
  int temp1 = 0;
  int count = 0;

  while (l1 != NULL) {
    count++;
    temp1 += mult * l1->val;
    l1 = l1->next;
    mult *= 10;
  }

  mult = 1;
  int temp2 = 0;

  while (l2 != NULL) {
    temp2 += mult * l2->val;
    l2 = l2->next;
    mult *= 10;
  }

  int temp = temp1 + temp2;

  // count the num of digits
  int _temp = temp;
  int size = 0;

  while (_temp != 0) {
    _temp /= 10;
    size++;
  }

  int digits[] = {0};

  if (size == 0) {
    int digits[] = {0};
  } else {

    int digits[size];

    //  123 -> 123 23 3
    int index = 10;
    for (int i = 0; i < size; i++) {
      digits[i] = temp % index;
      index *= 10;
    }

    // 123 23 3 -> 1 2 3
    index = 100;
    for (int i = size - 1; i >= 0; i--) {
      if (i != 0) {
        digits[i] -= digits[i - 1];
      }
      digits[i] /= index;
      index /= 10;
    }
  }

  struct ListNode *result = create_list_node(digits, count);

  return result;
}

int main(int argc, char *argv[]) {

  int a[] = {2, 4, 3};
  int b[] = {5, 6, 4};

  struct ListNode *l1 = create_list_node(a, 3);
  struct ListNode *l2 = create_list_node(b, 3);

  struct ListNode *result = addTwoNumbers(l1, l2);

  while (result != NULL) {
    printf("%d\n", result->val);
    result = result->next;
  }

  free_list(l1);
  free_list(l2);
  free_list(result);

  return 0;
}

struct ListNode *create_list_node(int values[], int count) {
  struct ListNode *head = malloc(sizeof(struct ListNode));
  struct ListNode *current = head;

  for (int i = 0; i < count; i++) {
    current->val = values[i];
    if (i == count - 1) {
      current->next = NULL;
    } else {
      current->next = malloc(sizeof(struct ListNode));
      current = current->next;
    }
  }
  return head;
}

void free_list(struct ListNode *head) {
  struct ListNode *temp = NULL;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}
