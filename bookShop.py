#connects to sql databse where it is a databse for a book shop that contains
#the title, author, how many copies, and cost of the book for that bookShop
#it has the functions viewbook, search a book by either title or author
#checking if its in stock, checking the price, adding a book, and
#removing a copies if has been bought or increasing copies if a shipment has
#arrived

import os
import sys
import mysql.connector
from mysql.connector import Error

mypass = "#####"
mydatabase="books"


con = mysql.connector.connect(host='localhost',database='books',user='root', password='dog2971521')
cur = con.cursor()

def mainMenu():
    #running the menu until user selects 8
    while True:
        print()
        #A simple menu for the book shop
        print('''----------Welcome to the Literral book shop----------\n
                 Here are the following options for the shop
                 1) View books
                 2) Search Books
                 3) If its in stock
                 4) Check the Price
                 5) Add A book
                 6) Remove one copie since its been bought
                 7) Increase the number of copies
                 8) Exit''')
        #asking the user which one they want
        userSelection = input("Which would you like to select? ")
        if userSelection == "1":
            viewBook()

        elif userSelection == "2":
            searchBy = input("Would you like to search by title or author: ").lower()
            if searchBy == 'title':
                bookTitle = input("What is the book title you are looking for: ").lower()
                searchBookTitle(bookTitle)
            elif searchBy == 'author':
                bookAuthor = input("What is the book title you are looking for: ").lower()
                searchBookAuthor(bookAuthor)

        elif userSelection == '3':
            print("Enter the information fo the book you want to check if it is in stock?")
            bookTitle = input("Enter the title: ").lower()
            bookAuthor = input("Enter the author: ").lower()
            inStock(bookTitle, bookAuthor)

        elif userSelection == '4':
            print("Enter the information fo the book you want the price for?")
            bookTitle = input("Enter the title: ").lower()
            bookAuthor = input("Enter the author: ").lower()
            bookPrice(bookTitle, bookAuthor)

        elif userSelection == "5":
            print("You are about to add book. Please enter the values asked")
            title = input("Title: ").lower()
            author = input("Author: ").lower()
            copies = input("Copes: ")
            cost = input("Cost: ")
            addAbook(title, author, copies, cost)

        elif userSelection== "6":
            print("Enter the information fo the book that has been bought")
            bookTitle = input("Enter the title: ").lower()
            bookAuthor = input("Enter the author: ").lower()
            bought(bookTitle, bookAuthor)

        elif userSelection== "7":
            print("Enter the information fo the book that has more copies: ")
            bookTitle = input("Title: ").lower()
            bookAuthor = input("Author: ").lower()
            numCopies = input("How many NEW copies are there: ")
            addingCopies(bookTitle, bookAuthor,numCopies)

        elif userSelection == "8":
            sys.exit()
        else:
            print("Sorry, you did not select a valid choice.")
#shows all books on the database
def viewBook():
    try:
        cur.execute("SELECT * FROM bookShop")
        books = cur.fetchall()
        for row in books:
                print("Title = ", row[0])
                print("Author = ", row[1])
                print("Copies = ", row[2])
                print("Cost = ", row[3])
    except Error as e:
        print("Error reading data from MySQL table", e)

#serching by title and brings up all the information with the book matching the userInput
def searchBookTitle(bookTitle):
    searching = ("SELECT * FROM bookShop WHERE title = %s")
    searchTitle = (bookTitle,)
    try:
        cur.execute(searching, searchTitle)
        book = cur.fetchall()
        for row in book:
            print("Title = ", row[0])
            print("Author = ", row[1])
            print("Copies = ", row[2])
            print("Cost = ", row[3])
    except:
        print("Couldnt find sorry")

#serching by author and brings up all the information with the book matching the userInput
def searchBookAuthor(bookAuthor):
    searching = ("SELECT * FROM bookShop WHERE author = %s")
    searchTitle = (bookAuthor,)
    try:
        cur.execute(searching, searchTitle)
        book = cur.fetchall()
        for row in book:
            print("Title = ", row[0])
            print("Author = ", row[1])
            print("Copies = ", row[2])
            print("Cost = ", row[3])
    except:
        print("Couldnt find sorry")

#checking weather a book is in stock
def inStock(bookTitle, bookAuthor):
    try:
        cur.execute("SELECT copies FROM bookShop WHERE title = %s AND author = %s", (bookTitle, bookAuthor,))
        stock = cur.fetchone()

        #converting the tuple into a string
        newStock = str(stock).replace('(', '')
        newStock = str(newStock).replace(')','')
        newStock = str(newStock).replace(',','')
        #checking if it equals to 0
        if(newStock == '0'):
            print("Sorry not currently in stock")
        else:
            print("There are:", newStock, "Currently in stock")
    except:
        print("Couldnt find sorry")
#checking the price of a book
def bookPrice(bookTitle, bookAuthor):
    try:
        cur.execute("SELECT cost FROM bookShop WHERE title = %s AND author = %s", (bookTitle, bookAuthor,))
        price = cur.fetchone()
        #converting into a string
        newPrice = str(price).replace('(', '')
        newPrice = str(newPrice).replace(')','')
        newPrice = str(newPrice).replace(',','')
        print(bookTitle, "By ", bookTitle, "is:", newPrice)
    except:
        print("Couldnt find sorry")
#adding a book to the databse
def addAbook(title, author, copies, cost):
    insertBooks = "insert into bookShop values ('"+title+"','"+author+"','"+copies+"','"+cost+"')"
    try:
        cur.execute(insertBooks)
        con.commit()
    except:
        print("Couldnt enter data please try again")
#removing ONE copy from the database under copie row of a specific book that has been bought
def bought(bookTitle, bookAuthor):
    #hasBeenBought = "UPDATE bookShop SET copies = copies - 1 WHERE title = '%s' AND author = '%s'"
    try:
        cur.execute("UPDATE bookShop SET copies=copies-1 WHERE title = %s AND author = %s", (bookTitle, bookAuthor,))
        con.commit()
        print("One less copy of: ", bookTitle)
    except:
        print("Couldnt enter data please try again")
#adding how many copies of a book that has a new shipment in
def addingCopies(bookTitle, bookAuthor,numCopies):
    try:
        cur.execute("UPDATE bookShop SET copies=copies+ %s WHERE title = %s AND author = %s", (int(numCopies),bookTitle, bookAuthor,))
        con.commit()
    except:
        print("Couldnt enter data please try again")

#runs the function which will run the menu
mainMenu()
