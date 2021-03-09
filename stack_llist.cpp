#include <iostream>
#include <limits>

using namespace std;

struct node {
  char data;
  struct node *next, *prev;
};
typedef struct node node;
node *top = NULL, *tail = NULL;

int choice;
char item;
int count = 0;
int keluar = 0;

void push(char item) {
  node *temp = new node;
  temp->data = item;
  if(top == NULL) {
    top = temp;
    tail = temp;
  } else {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
  temp->next = NULL;
  top->prev = NULL;
  cout << "\n# PUSH : No urut/index : " << count << ", Push :" << temp->data;
  count++;
}

void pop() {
  if(top == NULL) {
    cout << "\n## Stack kosong";
  } else {
    --count;
    char item = top->data;
    node *temp = tail;
    tail = temp->prev;
    cout << "\n##POP hasil:" << item;
    cout << "\n##jumlah item dalam stack : " << count;
  }
}

void printAll() {
  cout << "\n## Stack Size : " << count;
  node *temp = tail;
  int i = count-1;
  while(temp != NULL) {
    cout << "\n## No Urut/index : " << i << ", Value :" << temp->data;
    temp = temp->prev;
    i--;
  }
  keluar = 0;
}

void menu() {
  cout << "\nMasukkan operasi yang akan dilakukan (1:push, 2:pop, 3:print) : ";
  cin >> choice;
  switch(choice) {
    case 1:
      cout << "\nMasukkan huruf yang akan dipush : ";
      cin >> item;
      addLast(item);
      break;
    case 2:
      removeLast();
      break;
    case 3:
      printAll();
      break;
    default:
      cout << "\n1:push, 2:pop, 3:print\n";
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
