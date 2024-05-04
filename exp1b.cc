#include<iostream>
#include<ncurses.h>
using namespace std;
int main() {
   string preexisting_password = "password123";
   string entered_password;
   char ch;
   initscr(); // Initialize ncurses
   noecho();  // Don't echo characters to the console
   printw("Enter password: ");
   refresh();

   while (true) {
       ch = getch();
       if (ch == '\n') // Enter key pressed
           break;
       entered_password += ch;
       printw("*");
       refresh();
   }

   endwin(); // End ncurses
   cout << endl;
   if (entered_password == preexisting_password) {
       cout << "Password correct!" << endl;
   } else {
       cout << "Password incorrect!" << endl;
   }
   return 0;
}