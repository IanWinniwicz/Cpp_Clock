// including packages
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;

int currentHour = 0;
int currentMinute= 0;
int currentSeconds= 0;
// adds 0 to single digit number
string twoDigitString(unsigned int n) {
    string number;
    if (n < 10)
        number.append(to_string(0));
    number.append(to_string(n));

    return number;
}

// takes number of characters and makes the '*'
string nCharString(size_t n, char c) {
    string charString (n, c);
    return charString;
}
 //Formats the time in military format
 string formatTime24(unsigned int h, unsigned int m, unsigned int s) {

    string mTime;
    mTime.append(twoDigitString(h)+ ":");
    mTime.append(twoDigitString(m)+ ":");
    mTime.append(twoDigitString(s));
    return mTime; 
}
// formats the time into 12 hour time
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    int fixedTime = h;
    if (h > 11)
        fixedTime = h - 12;
    if (fixedTime == 0)
        fixedTime = 12;

    string sTime;
    sTime.append(twoDigitString(fixedTime)+ ":");
    sTime.append(twoDigitString(m)+ ":");
    sTime.append(twoDigitString(s));

    if (h <= 11)
        sTime.append(" A M");
    else
        sTime.append(" P M");

    return sTime;
}
// menu 
void printMenu(char * strings[], unsigned int numStrings, unsigned char width) {
    int w = (int) width;
    cout << nCharString(w, '*') << endl;
    for (int i = 0; i < numStrings; i++){
        int spacing = w - (6 + strlen(strings[i])) - 1;
        cout << "*" << " " << i + 1 << " - " << strings[i] << nCharString(spacing, ' ') << "*" << endl;
    }
}
// menu choice loop
unsigned int getMenuChoice(unsigned int maxChoice) {
    int getInput;
    while (1) {
        cin >> getInput;
        if (getInput > 0 && getInput <= maxChoice)
        return getInput;
    }
}
// displays both 12 hour and 24 hour time
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

  cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') <<endl;
  cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
  cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
  cout << endl;
  cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
  cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;
  cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl; 
}

int getMinute() {
    return currentMinute;
}

int getHour() {
    return currentHour;
}

void setMinute(int min) {
    currentMinute = min;
}

void setHour(int cHour) {
    currentHour = cHour;
}

// adds one hour
void addOneHour() {
  int hour = getHour();
  if (hour >= 0 && hour <= 22){
      hour++;
      setHour(hour);
  }
  
  else if (hour == 23) {
    hour = 0;
    setHour(hour);
  }
}

// adds one minute
void addOneMinute() {
  int minute = getMinute();
  if (minute >= 0 && minute <= 58){
    minute++;
    setMinute(minute); 
  }
  else if (minute == 59) {
      minute = 0;
      setMinute(minute);
      addOneHour();
  }
}

void mainMenu() {
    char * strings[3] = {"Add one hour", "Add one minute", "Exit Program"};
    printMenu(strings, 3, 26);
  while (1) {
      int choice = getMenuChoice(3);
    if (choice == 1)
        addOneHour();
        displayClocks(currentHour, currentMinute,  currentSeconds);
        printMenu(strings, 3, 26);
    if (choice == 2)
        addOneMinute();
        displayClocks(currentHour, currentMinute,  currentSeconds);
        printMenu(strings, 3, 26);
    if (choice == 3)
        return;
  }
}

int main() {
    displayClocks(currentHour, currentMinute,  currentSeconds);
    mainMenu();
}