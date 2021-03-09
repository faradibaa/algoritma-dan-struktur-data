#include <iostream>
#include <limits>
#define MAX_SIZE 5

using namespace std;

int choice, i;
char item;
char arr_stack[MAX_SIZE];
int count = 0;
int keluar = 0;

void push(char item) {
  if (count == MAX_SIZE) {
    cout << "\n# Stack Penuh";
  } else {
    arr_stack[count] = item;
    cout << "\n# PUSH No urut/index : " << count << ", Push :" << item;
    count++;
  }
}

void pushNol(char item) {
  if(count == MAX_SIZE) {
    cout << "\n# Stack Penuh";
  } else{
      for(i = count; i > 0; i--) {
        arr_stack[i] = arr_stack[i-1];
      }
      arr_stack[0] = item;
      cout << "\n# PUSH No urut/index : 0, " << "Push :" << item;
      count++;
    }
}

void pop() {
  if(count == 0) {
    cout << "\n## Stack kosong";
  } else {
    --count;
    cout << "\n##POP No urut/index : " << count << ", Value :" << arr_stack[count];
  }
}

void popNol() {
  cout << "\n##POP No urut/index : 0, " << "Value :" << arr_stack[0];
  for(i = 0; i < count; i++) {
    arr_stack[i] = arr_stack[i+1];
  }
  count--;
}

void printAll() {
  cout << "\n## Stack size : " << count;
  for(i = (count-1); i >= 0; i--) {
    cout << "\n## No Urut/index : " << i << ", Value :" << arr_stack[i];
  }
}

void menu() {
  cout << "\nMasukkan operasi yang akan dilakukan (1:push, 2:pop, 3:print, 4:push index ke-0, 5:pop index ke-0) : ";
  cin >> choice;
  switch(choice) {
    case 1:
      cout << "\nMasukkan huruf yang akan di push : ";
      cin >> item;
      push(item);
      break;
    case 2:
      pop();
      break;
    case 3:
      printAll();
      break;
    case 4:
      cout << "\nMasukkan huruf yang akan di push : ";
      cin >> item;
      pushNol(item);
      break;
    case 5:
      popNol();
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
