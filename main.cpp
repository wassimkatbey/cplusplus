//
//  main.cpp
//  ConnectedHouseApp
//
//  Created by Wassim Katbey on 9/15/17.
//  Copyright © 2017 Wayne State University. All rights reserved.
//

#include "houseType.hpp"
#include <fstream>


void houseMenu();
void applianceMenu(string str);
void doorMenu();
void lightMenu();
void conditionerMenu();
void alarmMenu();
void primaryMenu();

template <class Type>
void insertionSort(vector<Type> list, unsigned long length);

template <class Type>
int binarySearchName(vector<Type> list, unsigned long length, string searchItem);


int main() {
    
    int pMenu;
    int hMenu;
    int aMenu;
    string appMenu;
    
    ifstream inFile("house.txt");
    ofstream outFile("house.txt");
    
    int doorNum;
    int lightNum;
    int conditionerNum;
    string name;
    
    double temperature;
    
    int index;
    
    string houseName;
    vector<houseType> houseIndex;
    
    //Reading input from a file
   /* while (!inFile.eof()) {
        houseType loadHouse;
        inFile >> loadHouse;
        houseIndex.push_back(loadHouse);
    } */
    
    primaryMenu();
    cin >> pMenu;
    
    while (pMenu != 3) {
        switch(pMenu) {
            case 1:
                cout << "Enter House Name: ";
                cin.ignore();
                getline(cin, name);
                
                index = binarySearchName(houseIndex, houseIndex.size(), name);
                
                if (index == -1)
                    throw("Does not Exist");
                
                cout << "Signed into " << houseIndex[index].getHouseName() << endl;
                cout << "Session has begun" << endl;
                
                houseMenu();
                cin >> hMenu;
                while (hMenu != 6) {
                    switch (hMenu) {
                        case 1:
                            doorMenu();
                            cin >> aMenu;
                            if (aMenu == 1)
                                houseIndex[index].openDoor();
                            else if (aMenu == 2)
                                houseIndex[index].closeDoor();
                            break;
                        case 2:
                            lightMenu();
                            cin >> aMenu;
                            if (aMenu == 1)
                                houseIndex[index].lightSwitchOn();
                            else if (aMenu == 2)
                                houseIndex[index].lightSwitchOff();
                            break;
                        case 3:
                            conditionerMenu();
                            cin >> aMenu;
                            if (aMenu == 1)
                                houseIndex[index].conditionerSwitchOn();
                            else if (aMenu == 2)
                                houseIndex[index].conditionerSwitchOff();
                            else if (aMenu == 3) {
                                cout << "Temperature: ";
                                cin >> temperature;
                                houseIndex[index].setConditionerTemperature(temperature);
                            }
                            break;
                            
                        case 4:
                            alarmMenu();
                            cin >> aMenu;
                            if (aMenu == 1)
                                houseIndex[index].alarmSwitchOn();
                            else if (aMenu == 2)
                                houseIndex[index].alarmSwitchOff();
                            else if (aMenu == 3)
                                houseIndex[index].armAlarm();
                            else if (aMenu == 4)
                                houseIndex[index].disarmAlarm();
                            
                            break;
                        case 5:
                            houseIndex[index].houseInformation();
                            break;
                        
                    } //end switch hMenu
                    houseMenu();
                    cin >> hMenu;
                } //end while
                
                break;
            case 2:
                cout << "Creating a new House." << endl;
                cout << "Enter House Name: ";
                cin.ignore();
                getline(cin, houseName);
                
                cout << "Enter the Number of: " << endl;
                cout << "Doors: ";
                cin >> doorNum;
                cout << "Lights: ";
                cin >> lightNum;
                cout << "Air Conditioners: ";
                cin >> conditionerNum;
                
                houseType userHouse(houseName, doorNum, lightNum, conditionerNum);
                houseIndex.push_back(userHouse);
                
                cout << "Created a house with " << doorNum << " doors, "
                << lightNum << " lights, " << "and " << conditionerNum
                << " air conditioners." << endl;
                
                cin.clear();
                
                cout << "Door Specifications:" << endl;
                for (unsigned long i = 0; i < userHouse.getNumOfDoors(); i++) {
                    cout << "Enter door " << i + 1 << " name: ";
                    cin.ignore();
                    getline(cin, name);
                    userHouse.setDoorName(i, name);
                }
                
                cout << "Light Specifications:" << endl;
                for (unsigned long i = 0; i < userHouse.getNumOfLights(); i++) {
                    cout << "Enter light " << i + 1 << " name: ";
                    cin.clear();
                    getline(cin, name);
                    userHouse.setLightName(i, name);
                }
                
                cout << "Air Conditioenr Specifications:" << endl;
                for (unsigned long i = 0; i < userHouse.getNumOfConditioners(); i++) {
                    cout << "Enter air conditioner " << i + 1 << " name: ";
                    cin.clear();
                    getline(cin, name);
                    userHouse.setConditionerName(i, name);
                }
                
                
                cout << "Created House with name " << userHouse.getHouseName() << "."
                << endl << "Returning to Primary Menu. Access "
                << userHouse.getHouseName() << " through 'My House' " << endl;
                
                
                insertionSort(houseIndex, houseIndex.size());
                break;
            
         
        }
        primaryMenu();
        cin >> pMenu;
    }
    
    
    for (unsigned i = 0; i < houseIndex.size(); i++)
        outFile << houseIndex[i];
    
    

    system("pause");
    return 0;
}

void primaryMenu() {
    cout << "Primary Menu" << endl;
    cout << "1 - My House" << endl;
    cout << "2 - Connect My House" << endl;
    cout << "3 - Exit" << endl;
    cout << "Enter an option: ";
}

void houseMenu() {
    cout << "House Menu:" << endl;
    cout << "1 - Doors" << endl;
    cout << "2 - Lights" << endl;
    cout << "3 - Air Conditioners" << endl;
    cout << "4 - Alarm" << endl;
    cout << "5 - House Status" << endl;
    cout << "6 - Return" << endl;
    cout << "Enter an option: ";
}

void applianceMenu(string str) {
    cout << "Enter " << str << "name: ";
}

void doorMenu() {
    cout << "Open Door" << endl;
    cout << "Close Door" << endl;
}

void lightMenu() {
    cout << "1 - Turn Light On" << endl;
    cout << "2 - Turn Light Off" << endl;
}

void conditionerMenu() {
    cout << "1 - Turn Conditioner On" << endl;
    cout << "2 - Turn Conditioner Off" << endl;
    cout << "3 - Set Temperature" << endl;
}

void alarmMenu() {
    cout << "1 - Set Alarm On" << endl;
    cout << "2 - Set Alarm Off" << endl;
    cout << "3 - Arm" << endl;
    cout << "4 - Disarm" << endl;
}

template <class Type>
void insertionSort(vector<Type> list, unsigned long length) {
    int firstOutOfOrder;
    int location;
    Type temp;
    
    for (firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++) {
        if (list[firstOutOfOrder].getHouseName() < list[firstOutOfOrder - 1].getHouseName()) {
            location = firstOutOfOrder;
            temp = list[location];
            
            do {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1].getHouseName() > temp.getHouseName());
            list[location] = temp;
        }
    }
}

template <class Type>
int binarySearchName(vector<Type> list, unsigned long length, string searchItem) {
    int first = 0;
    int last = length - 1;
    int mid;
    
    while (first <= last) {
        mid = first + (last - first)/2;
        
        if (list[mid].getHouseName() == searchItem)
            return mid;
        else if (list[mid].getHouseName() > searchItem)
            first = mid + 1;
        else
            last = mid - 1;
    }
    
    if (first > last)
        return -1;
    else
        return mid;
    
}





