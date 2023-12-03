/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
enum PhoneNumberType {
    HOME,
    WORK,
    MOBILE,
    OFFICE,
    FAX
};

struct PhoneNumber{
    PhoneNumberType PhoneType;
    std::string Phone;
};

struct Person {
    std::string firstName;
    std::string lastName;
    std::string email;
    vector<PhoneNumber> PhoneList;
};

vector<Person> phoneBook;

void addPerson() {
    Person person;
    std::cout << "Enter first name: ";
    std::cin >> person.firstName;
    std::cout << "Enter last name: ";
    std::cin >> person.lastName;

    char choice;
    PhoneNumber newPhoneNumber;
    do {
        PhoneNumberType type;
        std::string number;
        std::cout << "Enter phone number type (1: Home, 2: Work, 3: Mobile, 4: OFFICE, 5: FAX): ";
        int typeChoice;
        std::cin >> typeChoice;
        switch (typeChoice) {
            case 1:
                newPhoneNumber.PhoneType = HOME;
                break;
            case 2:
                newPhoneNumber.PhoneType = WORK;
                break;
            case 3:
                newPhoneNumber.PhoneType = MOBILE;
                break;
            case 4:
                newPhoneNumber.PhoneType = OFFICE;
                break;
            case 5:
                newPhoneNumber.PhoneType = FAX;
                break;
            default:
                std::cout << "Invalid choice. Defaulting to Mobile." << std::endl;
                newPhoneNumber.PhoneType = MOBILE;
                break;
        }
        std::cout << "Enter phone number: ";
        std::cin >> newPhoneNumber.Phone;
        person.PhoneList.push_back(newPhoneNumber);
        
        std::cout << "Do you want to add another phone number? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    phoneBook.push_back(person);
    std::cout << "Person added to phone book." << std::endl;
}

void searchFirstName() 
{
    std::string name;
    std::cout << "Enter FirstName to search: ";
    std::cin >> name;

    bool found = false;
    for (int i=0;i < phoneBook.size();i++)
    {
        // const auto& person : phoneBook) {
        if (phoneBook[i].firstName == name) 
        {
            std::cout << "Person found " << i << " : " << phoneBook[i].firstName << " " << phoneBook[i].lastName << std::endl;
            found = true;
            for (int j=0;j < phoneBook[i].PhoneList.size();j++)//const auto& phone : phoneBook[i].PhoneList)
            {
                std::cout<<phoneBook[i].PhoneList[j].Phone<<endl;
            }
        }
    }

    if (!found) {
        std::cout << "Person not found." << std::endl;
    }
}

void searchLastName()
{
    std::string name;
    std::cout << "Enter phone number to search: ";
    std::cin >> name;

    bool found = false;
    for (int i=0;i < phoneBook.size();i++)
    {
        if (phoneBook[i].lastName == name)
        {
            std::cout << "Person found " << i << " : " << phoneBook[i].firstName << " " << phoneBook[i].lastName << std::endl;
            found = true;
            for (int j=0;j < phoneBook[i].PhoneList.size();j++)//const auto& phone : phoneBook[i].PhoneList)
            {
                std::cout<<phoneBook[i].PhoneList[j].Phone<<endl;
            }
        }
    }

    if (!found) {
        std::cout << "Person not found." << std::endl;
    }
}
void searchPhoneNumber() {
    std::string number;
    std::cout << "Enter phone number to search: ";
    std::cin >> number;

    bool found = false;
    for (int i=0;i < phoneBook.size();i++) {
        for (int j=0;j < phoneBook[i].PhoneList.size();j++){
            if (phoneBook[i].PhoneList[j].Phone == number) {
                std::cout << "Person found: " << i << " : " << phoneBook[i].firstName << " " << phoneBook[i].lastName << std::endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "Phone number not found." << std::endl;
    }
}

void search(){
    char choice;
    cout << "how do you want to search?\n1.First Name\n2.Last Name\n3.Phone Number" << endl;
    cin >> choice;
    switch (choice)
    {
        case '1':
            searchFirstName();
            break;
        case '2':
            searchLastName();
            break;
        case '3':
            searchPhoneNumber();
            break;
    }
}


void deletePerson() {
    char choice;
    cout << "how do you want to delete?\n1.First Name\n2.Last Name" << endl;
    cin >> choice;
    switch (choice)
    {
        case '1':
            searchFirstName();
            break;
        case '2':
            searchLastName();
            break;
    }
    int row;
    cout << "which one do you want to delete? ";
    cin >> row;
    
    phoneBook.erase(phoneBook.begin() + row);

    std::cout << "Person deleted from phone book." << std::endl;
}

void deleteAll(){
    char choice;
    cout << "Are you sure to delete all persons?(y/n): ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        for(int row= phoneBook.size() - 1;row >= 0;row--)
        {
            phoneBook.erase(phoneBook.begin() + row);
        }
    }
    
    cout << "All persons Are deleted!\n";
    
}

void displayPhoneBook() {
    if (phoneBook.empty()) {
        std::cout << "Phone book is empty." << std::endl;
        return;
    }

    for (int i=0;i <phoneBook.size();i++){//const auto& person : phoneBook) {
        std::cout << "First Name: " << phoneBook[i].firstName << std::endl;
        std::cout << "Last Name: " << phoneBook[i].lastName << std::endl;
        std::cout << "Phone Numbers:" << std::endl;
        for (int j=0;j < phoneBook[i].PhoneList.size();j++){
		//const auto& phoneNumber : person.PhoneList) {
            std::string type;
            switch (phoneBook[i].PhoneList[j].PhoneType) {
                case HOME:
                    type = "Home";
                    break;
                case WORK:
                    type = "Work";
                    break;
                case MOBILE:
                    type = "Mobile";
                    break;
                case FAX:
                    type = "Fax";
                    break;
                case OFFICE:
                    type = "Office";
                    break;
            }
            std::cout << "Type: " << type << ", Number: " << phoneBook[i].PhoneList[j].Phone << std::endl;
        }
        std::cout << std::endl;
    }
}

void sortingByFirstName(){
    for (int i=0;i<phoneBook.size();i++)
    {
        for (int j=0;j<phoneBook.size()-1;j++)
        {
            if(phoneBook[j].firstName.compare(phoneBook[j+1].firstName) > 0)
            {//strcmp(phoneBook[j].firstName,phoneBook[j+1].firstName) 
                Person temp = phoneBook[j];
                phoneBook[j]=phoneBook[j+1];
                phoneBook[j+1]=temp;
            }
        }
    }
}

void sortingByLastName(){
    for (int i=0;i<phoneBook.size();i++)
    {
        for (int j=0;j<phoneBook.size()-1;j++)
        {
            if(phoneBook[j].lastName.compare(phoneBook[j+1].lastName) > 0)
            {
                Person temp = phoneBook[j];
                phoneBook[j]=phoneBook[j+1];
                phoneBook[j+1]=temp;
            }
        }
    }
}

void sorting(){
    char choice;
    cout<<"how do you want to sort?\n1.first name\n2.last name\n";
    cin>> choice;
    if(choice == '1')
    {
        sortingByFirstName();
    }
    else{
        sortingByLastName();
    }
}

int main() {
    char choice;
    do {
        std::cout << "1. Add person" << std::endl;
        std::cout << "2. Delete person" << std::endl;
        std::cout << "3. Display phone book" << std::endl;
        std::cout << "4. Search" << std::endl;
        std::cout << "5. Delete All" << std::endl;
        std::cout << "6. Sorting" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addPerson();
                break;
            case '2':
                deletePerson();
                break;
            case '3':
                displayPhoneBook();
                break;
            case '4':
                search();
                break;
            case '5':
                deleteAll();
                break;
            case '6':
                sorting();
                break;
            case '7':
                cout << "Exiting..." << endl;
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    } while (choice != '7');

    return 0;
}
