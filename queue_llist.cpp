#include <iostream>
#include <limits>

using namespace std;

struct node {
  char data;
  struct node *next, *prev;
};
typedef struct node node;

node *head, *tail;
int choice;
char item;
int count = 0;
int keluar = 0;

void enqueue(char item) {
  node *temp = new node;
  temp->data = item;
  if(head == NULL) {
    head = temp;
    tail = temp;
  } else {
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
  tail->next = NULL;
  head->prev = NULL;
  cout << "\n# Queue : No urut/index : " << count << ", Value :" << item;
  count++;
}

void dequeue() {
  if(head == NULL) {
    cout << "\n## Queue kosong";
  } else {
    --count;
    node *temp = tail;
    tail = temp->prev;
    tail->next = NULL;
  }
  cout << "\n##Dequeue result:" << item;
  cout << "\n##jumlah item dalam queue : " << count;
}

void printAll() {
  cout << "\n## Queue Size : " << count;
  node *temp;
  temp = tail;
  int i = 0;
  while(temp != NULL) {
    cout << "\n## No Urut/index : " << i << ", Value :" << temp->data;
    temp = temp->prev;
    i++;
  }
}

void menu() {
  cout << "\nMasukkan operasi yang akan dilakukan (1:enqueue, 2:dequeue, 3:print) : ";
  cin >> choice;
  switch(choice) {
    case 1:
      cout << "\nMasukkan huruf yang akan dimasukkan dalam queue : ";
      cin >> item;
      enqueue(item);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      printAll();
      break;
    default:
      cout << "\n1:enqueue, 2:dequeue, 3:print\n";
      keluar = 1;
      break;
  }
}

int main() {
  do {
    menu();
  } while(keluar == 0);
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cin.get();
  return 0;
}
