#include <iostream>
#include <limits>
#define MAX_SIZE 5

using namespace std;

int choice, i;
char item;
char arr_queue[MAX_SIZE];
int count = 0;
int keluar = 0;
int front, rear = 0;

void enqueue(char item) {
  if(rear == MAX_SIZE) {
    cout << "\n# Queue Penuh";
  } else {
    cout << "\n# Queue No urut/index : " << rear << ", Queue :" << item;
    arr_queue[rear++] = item;
  }
}

void dequeue() {
  if(rear == 0) cout << "\n## Queue kosong";
  else {
    cout << "\n##Dequeue Value :" << arr_queue[0];
    for(i = 1; i <= rear; i++) {
      char temp = arr_queue[i];
      arr_queue[i-1] = temp;
    }
  rear--;
  }
}

void printAll() {
  cout << "\n## Queue Size : " << rear;
  for(i = 0; i < rear; i++) {
    cout << "\n## No Urut/index : " << i << ", Value" << arr_queue[i];
  }
}

void menu() {
  cout << "\nMasukkan operasi yang akan dilakukan (1:enqueue, 2:dequeue, 3:print) : ";
  cin >> choice;
  switch(choice) {
    case 1:
      cout << "\nMasukkan huruf yang akan di-enqueue : ";
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
