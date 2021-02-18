#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include<stdlib.h>

using namespace std;


class book{
    private:
        string isbn;
        string bookTitle;
        string bookAuthor;
        string findTitle;
        string findAuthor;
        int copies;
        int newCopies;
        float cost;
        vector<string> row;
    public:
        void viewBook();
        void searchBookTitle();
        void searchBookAuthor();
        void inStock();
        void getBookPrice();
        void addAbook();
        void boughtSearchByTA();
        void boughtSearchByISBN();
        void addingCopiesByTA();
        void addingCopiesByISBN();
        void deleteBookByTA();
        void deleteBookByISBN();
};

int main()	{
  book mybook;
  int userChoice;
  string search;
  //char bookTitile,bookPrice;
  do{
      cout << "\t----------Welcome to the Literral book shop----------\n"
            "Here are your options\n"
            "1) View books\n"
            "2) Search Books\n"
            "3) If its in stock\n"
            "4) Check the Price\n"
            "5) Add A book\n"
            "6) Remove one copie since its been bought\n"
            "7) Increase the number of copies\n"
            "8) deleting ALL the information of a book\n"
            "9) Exit"<< endl;
    cout << "Please enter the choice you would like to do: ";
    cin >> userChoice;
    switch(userChoice){
          case 1:
              mybook.viewBook();
              break;
          case 2:
              cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%"<<endl
                   << "\t\tplease enter: 'title'" << endl
                    << "\t\tIf you are looking for a title " << endl
                   << "\t\tIf you're looking for an author " << endl
                   << "\t\tplease enter: 'author'" << endl
                   <<"\t\tNow please enter your choice: ";
              getline(cin, search);
              if(search == "title" || search == "Title" || search == "TITLE")
                mybook.searchBookTitle();
              else if (search == "author" || search == "Author" || search == "AUTHOR")
                mybook.searchBookAuthor();
              else
                cout << "wrong input";
              break;
          case 3:
              mybook.inStock();
              break;
          case 4:
              mybook.getBookPrice();
              break;
          case 5:
              mybook.addAbook();
              break;
          case 6:
              cout << "Are you looking for the book by title and author or ISBN number"
                   << endl
                   << "Enter title or T for title and author \nor"
                   << "\nenter ISBN or I for Isbn: "
                   <<"\nPlease enter your decision here: ";
              cin >> search;
              if(search == "title" || "TITLE" || "Title" || "t" || "T")
                mybook.boughtSearchByTA();
              else if(search == "ISBN" || "isbn" || "Isbn" || "I" || "i")
                mybook.boughtSearchByISBN();
              else
                cout << "You entered the incorrect criteria";
              break;
          case 7:
              cout << "Are you looking for the book by title and author or ISBN number"
                   << endl
                   << "Enter title or T for title and author \nor"
                   << "\nenter ISBN or I for Isbn"
                   <<"\nPlease enter your decision here: ";
              cin >> search;
              if(search == "title" || "TITLE" || "Title" || "t" || "T")
                mybook.addingCopiesByTA();
              else if(search == "ISBN" || "isbn" || "Isbn" || "I" || "i")
                mybook.addingCopiesByISBN();
              else
                cout << "You entered the incorrect criteria";
              break;
          case 8:
              cout << "Are you looking for the book by title and author or ISBN number"
                   << endl
                   << "Enter 'title' or 'T' for title and author \nor"
                   << "\nenter ISBN or I for Isbn"
                   <<"\nPlease enter your decision here: ";
              cin >> search;
              if(search == "title" || "TITLE" || "Title" || "t" || "T")
                mybook.deleteBookByTA();
              else if(search == "ISBN" || "isbn" || "Isbn" || "I" || "i")
                mybook.deleteBookByISBN();
              else
                cout << "You entered the incorrect criteria";
              break;
          case 9:
              cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
                   << " Bye, Have a nice day";
                   << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
          default:
              cout << "Selection is not recognized" << endl;
              break;
      }
    }while(userChoice != 9);
    return 0;
}

//showcases all the books in the databse and seperates them by commas
//will output them first by the identifier and then the actual item
void book::viewBook(){
  // File pointer
  ifstream fin("libraryDataBase.txt");
  //checks to make sure the file exist or else itll print out an error
  if(!fin.is_open()){
    cout << "ERROR" << endl;
  }
  //temporaries to be able to get them as string
  string copiesTemp, tempCost;
  //for getting the entire line
  string line;
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%"<<endl
       << "\t\t\t\tHere are all the books" << endl;
 //while the whole line is being grabbed it will store each piece in its respective spot
  while(getline(fin, line)){
    stringstream ss(line);
    getline(ss, isbn, ',');
    getline(ss, bookTitle, ',');
    getline(ss, bookAuthor, ',');
    getline(ss, copiesTemp, ',');
    //convert the string into an int
    copies = stoi(copiesTemp);
    getline(ss, tempCost);

    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%"<<endl
         << "\t\t*ISBN: " << isbn << endl
         << "\t\t*Title: " << bookTitle << endl
         << "\t\t*Author: " << bookAuthor << endl
         << "\t\t*Copies: " << copies << endl
         << "\t\t*Cost: " << tempCost << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%" << endl;
  }
}

//searches through the whole file to look for the matching title of what the
//user is trying to find and will then output all of its information
void book::searchBookTitle(){
  // File pointer and making sure file opens
  ifstream fin("libraryDataBase.txt");
  if(!fin.is_open()){
    cout << "ERROR" << endl;
  }
  //declaring temp strings to get the info into
  string copiesTemp, tempCost;
  string line;
  int found = 0;
  //getting user data
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%" << endl
       << "What is the title of the book you are trying to find: ";
  getline(cin, findTitle);

  //traversing the line to get the info
  while(getline(fin, line)){
    stringstream ss(line);
    getline(ss, isbn, ',');
    getline(ss, bookTitle, ',');
    getline(ss, bookAuthor, ',');
    getline(ss, copiesTemp, ',');
    //convert into string
    copies = stoi(copiesTemp);
    getline(ss, tempCost);
    //comparing the user input to the booktitle
    if(findTitle == bookTitle){
      //if found outputting it
      cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
           << "\tFound the book"<< endl
           << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
           << "ISBN: " << isbn << endl
           << "Title: " << bookTitle << endl
           << "Author: " << bookAuthor << endl
           << "Copies: " << copies << endl
           << "Cost: " << tempCost << endl
          << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
      found ++;
    }
  }
  //if not found outputting the message that it couldnt be found
  if(found == 0){
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "%Couldnt find a book with that title sorry%" << endl
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" <<endl;
  }
}
//searches through the whole file to look for the matching author of what the
//user is trying to find and will then output all of its information
void book::searchBookAuthor(){
  // File pointer and making sure file opens
  ifstream fin("libraryDataBase.txt");
  if(!fin.is_open()){
    cout << "ERROR" << endl;
  }
  //declaring temp strings to get the info into
  string copiesTemp, tempCost;
  string line;
  int found = 0;
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%" << endl
       << "What is the title of the book you are trying to find: ";
  getline(cin, findAuthor);
  //traversing the line to get the info
  while(getline(fin, line)){
    stringstream ss(line);
    getline(ss, isbn, ',');
    getline(ss, bookTitle, ',');
    getline(ss, bookAuthor, ',');
    getline(ss, copiesTemp, ',');
    //convert into string
    copies = stoi(copiesTemp);
    getline(ss, tempCost);
    //comparing the book author of the currrent line to the author the user asked for
    if(findAuthor == bookAuthor){
      cout << "\tFound the book"<< endl
           << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
           << "ISBN: " << isbn << endl
           << "Title: " << bookTitle << endl
           << "Author: " << bookAuthor << endl
           << "Copies: " << copies << endl
           << "Cost: " << tempCost << endl
           << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
      found ++;
      break;
    }
  }
  //incase its not found
  if(found == 0){
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
         << "Couldnt find a book with that title sorry" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" <<endl;
  }
}
//searches through the whole file to look for the matching title  and authorof what the
//user is trying to find and will then output all if it is currently in stock
void book::inStock(){
  // File pointer
  ifstream fin("libraryDataBase.txt");
  if(!fin.is_open()){
    cout << "ERROR" << endl;
  }
  //declaring temp info
  string copiesTemp, tempCost;
  string line;
  int found = 0;
  //asking user for info
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%" << endl
       << "What is the title of the book you are trying to find: ";
  getline(cin, findTitle);
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%" << endl
       << "what is the author of the book you are trying to find: ";
  getline(cin, findAuthor);
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%" << endl;
  //going through th file line by line
  while(getline(fin, line)){
    stringstream ss(line);
    getline(ss, isbn, ',');
    //convert into string
    getline(ss, bookTitle, ',');
    getline(ss, bookAuthor, ',');
    getline(ss, copiesTemp, ',');
    copies = stoi(copiesTemp);
    getline(ss, tempCost);
    //comparing the title and the author to what the user asked for
    if(findTitle == bookTitle && findAuthor==bookAuthor){
      if(copies != 0){
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%" << endl
             << "\tThere is "<< copies << " copies of "<< bookTitle
             << " by "<< bookAuthor<< endl
             << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%" << endl;
             break;
      }
      else{
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%" << endl
             << "Sorry but " << bookTitle << " is currently out of stock" << endl
             << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=%%%%%%%%" << endl;
      }
    }
    else{
      cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
           << "Couldnt find a book with that title sorry" << endl
           << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" <<endl;
    }
  }
}
//searches through the whole file to look for the matching title of what the
//user is trying to find and will then output the book price
void book::getBookPrice(){
  ifstream fin("libraryDataBase.txt");
  if(!fin.is_open()){
    cout << "ERROR" << endl;
  }
  string copiesTemp, tempCost;
  string line;
  int found = 0;
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "What is the title of the book you are trying to find: ";
  getline(cin, findTitle);
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "what is the author of the book you are trying to find: ";
  getline(cin, findAuthor);
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

  while(getline(fin, line)){
    stringstream ss(line);
    getline(ss, isbn, ',');
    //convert into string
    getline(ss, bookTitle, ',');
    getline(ss, bookAuthor, ',');
    getline(ss, copiesTemp, ',');
    copies = stoi(copiesTemp);
    getline(ss, tempCost);

    if(findTitle == bookTitle && findAuthor==bookAuthor){
      if(copies != 0){
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
             << bookTitle << " by "<< bookAuthor << " cost: "<< tempCost<< endl
             << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
             found ++;
             break;
      }
      else{
        cout << "Sorry but " << bookTitle << " is currently out of stock"<< endl;
        found++;
        break;
      }
    }
  }
  if(found == 0){

  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "Sorry we couldnt find the book in our store at all" << endl
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  }
}
//prompts the user to enter the information about the book step by step and then
//writes it into the title
void book::addAbook(){
  //to send info to the file
  ofstream fout;
  //opening file
  fout.open("libraryDataBase.txt", ios::out | ios::app);
  //tells user what to enter
    cout << "You are going to be adding a book to the data base of the store" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "Enter the book specific book details: " << endl;
    cout << "\nISBN: ";
    getline(cin, isbn);
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";

    cout << "\nBook Title: ";
    getline(cin, bookTitle);
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";

    cout << "\nBook Author: ";
    getline(cin, bookAuthor);
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";

    cout << "\nNumber of copies: ";
    cin >> copies;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";

    cout << "\nThe price of the book: ";
    cin >> cost;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    //puts it on the sheet
    fout << isbn << ","
         << bookTitle << ","
         << bookAuthor << ","
         << copies << ","
         << cost << endl;
}
//if a book has been bought and they want to search by title and author it will look
//and compre and if its found it will delete one copy of the book else it will output  that
//the book wasnt found
void book:: boughtSearchByTA(){

  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "A book is now being bought" << endl
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  // File pointer
  fstream fin, fout;
  //opening new file
  fin.open("libraryDataBase.txt", ios::in);
  //creating new file
  fout.open("libraryDataBaseNew.txt", ios::out);

  int found = 0;

  string line, word;

  //Gettiing the title and author of the book being looked for
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=" << endl;
  cout << "What is the title of the book that has been bought: ";
  getline(cin, findTitle);
  cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%=" << endl;
  cout << "what is the author of the book that has been bought: ";
  getline(cin, findAuthor);

  //traversing the Fil
  while(!fin.eof()){
    row.clear();

    getline(fin, line);
    stringstream ss(line);
    //adding the whole line into a vector seperated by a ,
    while(getline(ss, word, ',')){
      row.push_back(word);
    }
      //assigning row[1] and row[2] to title and author
      bookTitle = row[1];
      bookAuthor = row[2];

      int row_size = row.size();

      //comparing what is being looked for to the title and author of the line
      //if its found it will delete a copie
      if(findTitle == bookTitle && findAuthor==bookAuthor){
        found = 1;
        copies = stoi(row[3]);
        newCopies = copies - 1;

        //converting the new copies into a string in order to push itt back into the vecotr of strings
        stringstream convert;
        convert << newCopies;
        row[3] = convert.str();
        //sending it into the file
        if(!fin.eof()){
          for(int i = 0; i < row_size - 1; i++){
            fout << row[i] << ',';
          }
          fout <<row[row_size - 1] << "\n";
        }
        //showing how many new copies there are of the book that was just bought
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
             << "Book has been bought" << endl
             << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
             << "There are now only: " << row[3] << " copies of " << row[1]
             << "By: " << row[2]
             << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
      }
      //sending the lines that dont match to the new
      else{
        if(!fin.eof()){
          for(int i=0; i < row_size - 1; i++){
            fout << row[i] << ',';
          }
          fout <<row[row_size - 1] << "\n";
        }
      }
      if(fin.eof())
        break;
  }
  if(found == 0)
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
         << "\t\tBook not found" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  fin.close();
  fout.close();
  //removing the old file
  remove("libraryDataBase.txt");
  //renaming it so it stay the same name
  rename("libraryDataBaseNew.txt","libraryDataBase.txt");
}
//if a book has been bought and they want to search by isbn it will look
//and compre and if its found it will delete one copy of the book
//else it will output the book wasnt found
void book::boughtSearchByISBN(){
  //same code as boughtSearchByTA only with isbn this time
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "A book is now being bought" << endl
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

  // File pointer
  fstream fin, fout;
  //opening new file
  fin.open("libraryDataBase.txt", ios::in);
  //creating new file
  fout.open("libraryDataBaseNew.txt", ios::out);

  int isbnComp, findIsbn,found = 0;

  string line, word;

  //Gettiing the title and author of the book being looked for
  cout << "What is the ISBN of the book that has been bought: ";
  cin >> findIsbn;

  //traversing the Fil
  while(!fin.eof()){
    row.clear();

    getline(fin, line);
    stringstream ss(line);

    while(getline(ss, word, ',')){
      row.push_back(word);
    }
      //converting the isbn number from file into an int
      isbnComp = stoi(row[0]);
      int row_size = row.size();


      if(findIsbn == isbnComp){
        found = 1;
        copies = stoi(row[3]);
        newCopies = copies - 1;
        stringstream convert;


        convert << newCopies;
        row[3] = convert.str();

        if(!fin.eof()){
          for(int i = 0; i < row_size - 1; i++){
            fout << row[i] << ',';
          }
          fout <<row[row_size - 1] << "\n";
        }
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
             << "Book has been bought" << endl
             << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
             << "There are now only: " << row[3] << " copies\n of " << row[1]
             << "\nBy: " << row[2] << endl
             << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
      }
      else{
        if(!fin.eof()){
          for(int i=0; i < row_size - 1; i++){
            fout << row[i] << ',';
          }
          fout <<row[row_size - 1] << "\n";
        }
      }
      if(fin.eof())
        break;
  }
  if(found == 0)
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
         << "Book not found" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  fin.close();
  fout.close();

  remove("libraryDataBase.txt");

  rename("libraryDataBaseNew.txt","libraryDataBase.txt");
}
//similar to boughtSearchByISBN but in the case if theres a new shipment they can add more
//copies of the book
void book::addingCopiesByISBN(){
  //same code as the bought function only adding this time
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "A book had a new shipment" << endl
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

  // File pointer
  fstream fin, fout;
  //opening new file
  fin.open("libraryDataBase.txt", ios::in);
  //creating new file
  fout.open("libraryDataBaseNew.txt", ios::out);

  int isbnComp, findIsbn, copies, newCopies,found = 0;

  string line, word;
  vector<string> row;

  //Gettiing the title and author of the book being looked for
  cout << "What is the ISBN of the book that had a shipment: ";
  cin >> findIsbn;
  //traversing the Fil
  while(!fin.eof()){
    row.clear();

    getline(fin, line);
    stringstream ss(line);

    while(getline(ss, word, ',')){
      row.push_back(word);
    }
      //converting the isbn number to an int
      isbnComp = stoi(row[0]);
      int row_size = row.size();


      if(findIsbn == isbnComp){
        found = 1;
        copies = stoi(row[3]);
        cout << "How many new Copies of " << row[1] << ": ";
        cin >> newCopies;
        newCopies = newCopies + copies;
        stringstream convert;

        //sending it as a string into the copies position
        convert << newCopies;
        row[3] = convert.str();

        if(!fin.eof()){
          for(int i = 0; i < row_size - 1; i++){
            fout << row[i] << ',';
          }
          fout <<row[row_size - 1] << "\n";
        }
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
             << "There are now: " << row[3] << " copies\nof: " << row[1]
             << "\nBy: " << row[2] << endl
             << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
      }
      else{
        if(!fin.eof()){
          for(int i=0; i < row_size - 1; i++){
            fout << row[i] << ',';
          }
          fout <<row[row_size - 1] << "\n";
        }
      }
      if(fin.eof())
        break;
  }
  if(found == 0)
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
         << "\tBook not found" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  fin.close();
  fout.close();

  remove("libraryDataBase.txt");

  rename("libraryDataBaseNew.txt","libraryDataBase.txt");
}
//similar to boughtSearchByTA but in the case if theres a new shipment they can add more
//copies of the book
void book::addingCopiesByTA(){
  //same as bought only adding this time
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "A book had a new shipment" << endl
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

  // File pointer
  fstream fin, fout;
  //opening new file
  fin.open("libraryDataBase.txt", ios::in);
  //creating new file
  fout.open("libraryDataBaseNew.txt", ios::out);

  int found = 0;

  string line, word;
  vector<string> row;

  //Gettiing the title and author of the book being looked for
  cout << "What is the title of the book that has been bought: ";
  getline(cin, findTitle);
  cout << "what is the author of the book that has been bought: ";
  getline(cin, findAuthor);

  //traversing the Fil
  while(!fin.eof()){
    row.clear();

    getline(fin, line);
    stringstream ss(line);

    while(getline(ss, word, ',')){
      row.push_back(word);
    }

      bookTitle = row[1];
      bookAuthor = row[2];

      int row_size = row.size();


      if(findTitle == bookTitle && findAuthor==bookAuthor){
        found = 1;
        copies = stoi(row[3]);
        cout << "How many new Copies of " << row[1] << ": ";
        cin >> newCopies;
        newCopies = newCopies + copies;
        stringstream convert;

        //sending it as a string into the copies position
        convert << newCopies;
        row[3] = convert.str();

        if(!fin.eof()){
          for(int i = 0; i < row_size - 1; i++){
            fout << row[i] << ',';
          }
          fout <<row[row_size - 1] << "\n";
        }
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
             << "There are now: " << row[3] << " copies\nof: " << row[1]
             << "\nBy: " << row[2] << endl
             << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
      }
      else{
        if(!fin.eof()){
          for(int i=0; i < row_size - 1; i++){
            fout << row[i] << ',';
          }
          fout <<row[row_size - 1] << "\n";
        }
      }
      if(fin.eof())
        break;
  }
  if(found == 0){
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
         << "Book not found" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  }
  fin.close();
  fout.close();

  remove("libraryDataBase.txt");

  rename("libraryDataBaseNew.txt","libraryDataBase.txt");
}
//deleting a book and searching for the book by title and author
void book::deleteBookByTA(){
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "A book will be forever deleted" << endl
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

  // File pointer
  fstream fin, fout;
  //opening new file
  fin.open("libraryDataBase.txt", ios::in);
  //creating new file
  fout.open("libraryDataBaseNew.txt", ios::out);

  int found = 0;

  string line, word;
  vector<string> row;

  //Gettiing the title and author of the book being looked for
  cout << "What is the title of the book that is being deleted: ";
  getline(cin, findTitle);
  cout << "what is the author of the book that is being deleted: ";
  getline(cin, findAuthor);

  while(!fin.eof()){
    row.clear();

    getline(fin, line);
    stringstream ss(line);

    while(getline(ss, word, ',')){
      row.push_back(word);
    }

      bookTitle = row[1];
      bookAuthor = row[2];

      int row_size = row.size();

      //as long as it doesnt equal the title and author enter
      if(findTitle != bookTitle && findAuthor!=bookAuthor){
        if(!fin.eof()){
          for(int i = 0; i < row_size -1; i++){
            fout<<row[i] << ',';
          }
          fout << row[row_size - 1] << "\n";
        }
      }
      else
        found++;
      if(fin.eof())
        break;
  }
  if(found == 1){
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
         << "Book has been deleted" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  }
  else{
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
         << "Book not found" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  }
  fin.close();
  fout.close();
  remove("libraryDataBase.txt");

  rename("libraryDataBaseNew.txt","libraryDataBase.txt");
}

void book::deleteBookByISBN(){
  cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
       << "A book will be forever deleted" << endl
       << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

  // File pointer
  fstream fin, fout;
  //opening new file
  fin.open("libraryDataBase.txt", ios::in);
  //creating new file
  fout.open("libraryDataBaseNew.txt", ios::out);

  int isbnComp, findIsbn,found = 0;

  string line, word;
  vector<string> row;

  cout << "What is the ISBN of the book that is being deleted: ";
  cin >> findIsbn;
  //traversing the Fil
  while(!fin.eof()){
    row.clear();
    getline(fin, line);
    stringstream ss(line);

    while(getline(ss, word, ',')){
      row.push_back(word);
    }
      //converting the isbn number to an int
      isbnComp = stoi(row[0]);
      int row_size = row.size();

      if(findIsbn != isbnComp){
        if(!fin.eof()){
          for(int i = 0; i < row_size -1; i++){
            fout<<row[i] << ',';
          }
          fout <<row[row_size - 1] << "\n";
        }
      }
      else
        found++;
      if(fin.eof())
        break;
  }
  if(found == 1){
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
         << "Book has been deleted" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  }
  else{
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl
         << "Book not found" << endl
         << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
  }
  fin.close();
  fout.close();
  remove("libraryDataBase.txt");

  rename("libraryDataBaseNew.txt","libraryDataBase.txt");

}
