#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <Windows.h>
#include <stdint.h>

using namespace std;

struct Booking
{
    string customer_name;
    string movieTitle;
    int seats_booked;
    double price;
};

const Booking* bookings;
int booking_count = 0;

struct movieInformation
{
    string movieTitle, releaseDate, movieGenre, ageRating, movieLength, Director;
}; // movie title, movie release date, movie genre type, movie age rating, movie duration, director of the movie

const int MAX_MOVIES = 520;
movieInformation movieList[MAX_MOVIES];
int movieListSize = 0;
const movieInformation* movieListPtr = movieList;
//const movieInformation* movieList;

struct promoAnnouncementInformation
{
    string promoOrAnnouncement, promoAnnouncementTitle, promoAnnouncementDetails;
}; // type  of notice whether it is a promotion or announcement, promotion / announcement title, promotion / announcement details

const int MAX_PROMOANNOUNCEMENT = 1314;
promoAnnouncementInformation promoAnnouncementList[MAX_PROMOANNOUNCEMENT];
int promoAnnouncementListSize = 0;

struct AccountDetails 
{
    string accname;
    int accpassword;
}details;

bool truename = false;
bool trueacc = false;
ofstream outfile;
ifstream infile;

// user phase
void register_acc();
void user_login();
void userMainMenu();
void edit_profile(string username, int password)；
// verification phase
int login_acc(string username, int pass);
bool availability(int seats[][10]);
int ticket_price(int price);
//displaying phase
void display_movies();
void location();
void display_seats();
// miscellaneous phase
void promo();
void feedback();
//buying ticket phase
void booking();
void process_payment();
// Admin phase
void adminLogin();
void adminMenu();
// movie list phase
void showMovieList();
void addMovie();
void modifyMovie();
void deleteMovie();
// promotion / announcement phase
void showPromotionAnnouncementList();
void addPromotionAnnouncement();
void modifyPromotionAnnouncement();
void deletePromotionAnnouncement();


int main() 
{
    char choice1;
    // display main menu of the system
    cout << "             &&                                                                &&                   " << endl;
    cout << "          &&&&&&&&                                                            &&&                   " << endl;
    cout << "          &&&&&&&&&&&                                                    &&&&&&&&                   " << endl;
    cout << "           &&&&&&&&&&&&&                                             &&&&&&&&&&&                    " << endl;
    cout << "            &&&&&&&&&&&&&&                                        &&&&&&&&&&&&&&                    " << endl;
    cout << "             &&&&&&&&&&&&&&&                                   &&&&&&&&&&&&&&&&                     " << endl;
    cout << "               &&&&&&&&&&&&&&&         (&&&&&&&&&&&&#       *&&&&&&&&&&&&&&&&*              /&&&&&& " << endl;
    cout << "                  &&&&&&&&&&&&& ,&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&           %&&&&&&&&&&&&& " << endl;
    cout << "                     *&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&         &&&&&&&&&&&&&&&&&&&/ " << endl;
    cout << "                         (&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%,       /&&&&&&&&&&&&&&&&&&&&&&&&  " << endl;
    cout << "                         *&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&  &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&  " << endl;
    cout << "                         &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&,&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   " << endl;
    cout << "                        .&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&   " << endl;
    cout << "                         &&&&   *@@ &&&&&&&&&&&&&&&&&&& #@@   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&    " << endl;
    cout << "                        /&&&.    @@  &&&&&&&&&&&&&&&&&( ,@@    &&&&%&&&&&&&&&&&&&&&&&&&&&&&&&&&#    " << endl;
    cout << "                        &&&&& ..... &&&&&&&&&&&&&&&&&&&. .. , (&&&&&&&&&&&&&&&&&&&&&&&&&            " << endl;
    cout << "                       ,&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*&&&&&&&&&&                     " << endl;
    cout << "                       ////// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.//// ,&&&&&&                        " << endl;
    cout << "                       ////////,&&&&&&&&.  &&&&&&,  (&&&&&&&&,/////// &&&&&&&&                      " << endl;
    cout << "                       ,/////// &&&&&&&&&&&&&&&&&&&&&&&&&&&&.////////(&&&&&&&&&&                    " << endl;
    cout << "                         ///// &&&&&&&&&&&&&&&&&&&&&&&&&&&&&,//////* &&&&&&&&&&&&&                  " << endl;
    cout << "                           %&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&       &&&&&&&&&&&&               " << endl;
    cout << "                          &&&,&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& &&     &&&&&&&&&&&(                  " << endl;
    cout << "                          #&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&& &&&&&& &&&&&&&&&&                       " << endl;
    cout << "                         .&&&&&&&&&&&&&&%##%%%%%%##&&&&&&&&&&&&&&&&%&& &,                           " << endl;
    cout << "                        &&&&&&&&&&&&&&&&&&&&%%%&&&&&&&&&&&&&&&&&&&&&&(*****                         " << endl;
    cout << "                       &&&&&&&&&&&&&&&&&& &&&&&&&&&%&&&&&&&&&&&&&&&&&***/*                          " << endl;
    cout << "		               %&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&							 " << endl;
    cout << "                    &&&&&&&&&&&&&&&&&&&&&&#&&&&&&&#&&&&&&&&&&&&&&&&&&&&&                            " << endl;
    cout << "                   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&(&&&&&&&&&&&&&&&&,&&&&&&                           " << endl;
    cout << "              &   *&&&&&&&&&&&&&&&&&&&&&&&&,&&&&&*&&&&&&&&&&&&&&&&&&&&&&&&                          " << endl;
    cout << "           &(&/&&&#&&&&&& &&&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&& .&&/&                    " << endl;
    cout << "            &&&&%&&&&%&&&& &&&&&&&&&&&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&/&%%% %#/                    " << endl;
    cout << "              %%###%%&&&&&& &&&&&&&&&&&&&&& &%%&&&&&&&&&&&&&&&&&&&&&&%%######(                      " << endl;
    cout << "                ######%%&&&&&&&&&&&&&&&&&&%######,&&&&&&&&&&& &&&&&&%%#####                         " << endl;
    cout << "                   #######%%%%.&&&&&&&&&&&########%&&&&&&&&%%%%%%%%######                           " << endl;
    cout << "                    ######,###%%&&&&&&&&&(      %&&&&&&&&*####/######                               " << endl;
    cout << "\n\n\n";
    cout << "   _|          _|            _|                                                      _|                                 " << endl;
    cout << "   _|          _|    _|_|    _|    _|_|_|    _|_|    _|_|_|  _|_|      _|_|        _|_|_|_|    _|_|                     " << endl;
    cout << "   _|    _|    _|  _|_|_|_|  _|  _|        _|    _|  _|    _|    _|  _|_|_|_|        _|      _|    _|                   " << endl;
    cout << "     _|  _|  _|    _|        _|  _|        _|    _|  _|    _|    _|  _|              _|      _|    _|                   " << endl;
    cout << "       _|  _|        _|_|_|  _|    _|_|_|    _|_|    _|    _|    _|    _|_|_|          _|_|    _|_|                     " << endl;
    cout << "\n";
    cout << "     _|_|_|    _|_|_|  _|_|_|          _|_|_|  _|                                                                       " << endl;
    cout << "   _|        _|        _|    _|      _|            _|_|_|      _|_|    _|_|_|  _|_|      _|_|_|                         " << endl;
    cout << "   _|  _|_|    _|_|    _|_|_|        _|        _|  _|    _|  _|_|_|_|  _|    _|    _|  _|    _|                         " << endl;
    cout << "   _|    _|        _|  _|    _|      _|        _|  _|    _|  _|        _|    _|    _|  _|    _|                         " << endl;
    cout << "     _|_|_|  _|_|_|    _|_|_|          _|_|_|  _|  _|    _|    _|_|_|  _|    _|    _|    _|_|_|                         " << endl;

    cout << endl;
    cout << "1) User Login" << endl;
    cout << "2) New User Register" << endl;
    cout << "3) Administration Login" << endl;
    cout << "4) Exit" << endl;
    cout << endl;
    cout << "Please input 1-4 to proceed : ";
    cin >> choice1; // input value to proceed

    if (choice1 == 49)
    {
        system("CLS");
        user_login();
        // function call to display user login menu
    }
    else if (choice1 == 50)
    {
        system("CLS");
        register_acc();
        // function call to display user registeration menu
    }
    else if (choice1 == 51)
    {
        system("CLS");
        adminLogin();
        // function call to display admin login menu
    }
    else if (choice1 == 52)
    {
        cout << endl;
        cout << "Goodbye!!! Hope to see you next time! " << endl;
        // exit the system
        return 0;
    }
    else
    {
        system("cls");
        cout << "\nInvalid input. Press any key to back to the Main Menu. " << endl;
        // show invalid if value input is not within the range
        cin.ignore();
        cin.ignore();
        main();
    }

}

void register_acc() 
{
    outfile.open("GSB.txt", ios::app);
    if (!outfile.is_open()) 
    {
        cout << "Some errors occur" << endl;
        exit(0);
    }
    else
    {
        cout << "Enter your username for register: ";
        cin >> details.accname;
        cin.ignore();
        cout << "Enter your password: ";
        cin >> details.accpassword;
        cin.ignore();
        cout << "Registered Successfully" << endl;

        outfile << "Username: " << details.accname << endl;
        outfile << "Password: " << details.accpassword << endl;

        outfile.close();
        main();
    }
}

int login_acc(string username, int pass) {
    infile.open("GSB.txt");

    if (!infile.is_open()) 
    {
        cout << "Some errors occur" << endl;
        exit(0);
    }

    while (!infile.eof()) 
    {
        string line;
        getline(infile, line);
        if (line.find("Username:") != string::npos) 
        {
            size_t pos = line.find(":");
            string accname = line.substr(pos + 2);

            if (accname == username) 
            {
                truename = true;
            }
            else 
            {
                truename = false;
            }
        }
        else if (line.find("Password:") != string::npos) 
        {
            size_t pos = line.find(":");
            int accpassword = stoi(line.substr(pos + 2));

            if (truename && accpassword == pass) 
            {
                trueacc = true;
                break;
            }
        }
    }

    infile.close();

    if (truename && trueacc) {
        return pass;
    }
    else {
        return 0;
    }
}

void user_login() {
    string user;
    int password = 0;
    int choice;


    cout << "\t\t\t\t-----Welcome to GSB Cinema Ticketing System-------\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t Please Enter Your Login Details\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t Select (1) for login, (2) for new user\t\t\t\t" << endl;

login:
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter your username: ";
        cin >> user;
        cout << "Enter your password: ";
        cin >> details.accpassword;

        if (password = login_acc(user, details.accpassword)) 
        {
            system("cls");
            cout << "\nLogin Successfully" << endl;
            cin.ignore();
            userMainMenu();
        }
        else {
            cout << "Invalid account entered" << endl;
            goto login;
        }
    }
    else if (choice == 2) {
        register_acc();
        goto login;
    }
    else {
        cout << "Invalid input" << endl;
        exit(0);
    }
}

void userMainMenu() 
{

        char selection;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 2);
        cout << " __ __  ___  _  _ _    __ __  ___  _ _  _ _ " << endl;
        cout << "|  \\  \\| . || || \\ |  |  \\  \\| __]| \\ || | |" << endl;
        cout << "|     ||   || ||   |  |     || _] |   || | |" << endl;
        cout << "|_|_|_||_|_||_||_\\_|  |_|_|_||___]|_\\_| \\__|" << endl;
        cout << "********************G64*********************" << endl;	//Main Menu
        SetConsoleTextAttribute(hConsole, 15);
        cout << "1 - Book now" << endl;
        cout << "2 - View promotion and announcement" << endl;
        cout << "3 - Feedback" << endl;
        cout << "\nPlease select [1, 2, 3, 'X' to logout] >> ";
        cin >> selection;

        switch (selection)
        {
        case '1':system("cls");
            booking();
            break;

        case '2':system("cls");
            promo();
            break;

        case '3':system("cls");
            feedback();
            break;

        case 'x':system("cls");
            system("cls");
            cout << "You had successfullly logout! Press any key to back to main menu. " << endl;
            cin.ignore();
            break;
        }
    
}

void display_movies()
{
    ifstream inFile;
    inFile.open("movieList.txt"); // read the existing movie list in the moveList.txt file
    int i = 0;

    cout << "--------------------------------\n";
    cout << "|         Movie List           |\n";
    cout << "--------------------------------\n";

    while (getline(inFile, movieList[i].movieTitle), getline(inFile, movieList[i].releaseDate), getline(inFile, movieList[i].movieGenre), getline(inFile, movieList[i].ageRating), getline(inFile, movieList[i].movieLength), getline(inFile, movieList[i].Director))
    {
        cout << i + 1 << ". " << movieList[i].movieTitle << "\n" << "Release Date: " << movieList[i].releaseDate << "\n" << "Genre: " << movieList[i].movieGenre << "\n"
            << "Age Rating: " << movieList[i].ageRating << "\n" << "Movie Duration: " << movieList[i].movieLength << "\n" << "Director: " << movieList[i].Director << "\n" << endl;

        i++;
        movieListSize = i;
    }
    inFile.close();
}

void booking() {

    display_movies();

    // Ask the user to select a movie
    char booking;
    int selection;

    cout << "Do you want to book a movie?(Y-yes/N-no)" << endl;
    cin >> booking;
    cin.ignore();

    if (booking == 'Y' || booking == 'y') {
        cout << "Please select a movie: " << endl;
        cin >> selection;
        cin.ignore();
        system("cls");
        cout << "You have selected " << movieList[selection-1].movieTitle << "." << endl;


        while (selection < 1 || selection > movieListSize) {
            cout << "Invalid choice,please enter again." << endl;
        }

        if (selection >= 1 && selection <= movieListSize)
        {
            booking_count = selection;
            location();
        }

    }


    else if (booking == 'N' || booking == 'n') {
        cout << "Exit the page";
        system("pause");
        system("cls");
    }

    else {
        cout << "Invalid choice,please enter again according to the rules." << endl;
    }
}

void location()
{
    const int capacity = 8;

    string places[capacity] = {
        "GSB Cinema,kampar,Perak","GSB Cinema,George Town,Penang","GSB Cinema,Petaling Jaya,Selangor","GSB Cinema,Seremban,Negeri Sembilan",
        "GSB Cinema,Kuantan,Pahang","GSB Cinema,Alor Setar,Kedah","GSB Cinema,Batu Pahat,Johor","GSB Cinema,Kota Bharu,Kelantan" };

    cout << "--------------------------------\n";
    cout << "|         Location List        |\n";
    cout << "--------------------------------\n";

    for (int i = 0; i < capacity; i++) {
        cout << i + 1 << ". " << places[i] << endl;
    }

    // Ask the user to select a location
    int choice;
    cout << "Select a location: ";
    cin >> choice;
    cin.ignore();


    while (choice < 1 || choice > 8) {
        cout << "Invalid choice. Please select again: ";
        cin >> choice;
        cin.ignore();
    }

    cout << "You have selected " << places[choice - 1] << endl;
    cin.ignore();
    system("cls");

    display_seats(booking_count);
}

void display_seats(int booking_count) 
{
    // Create an array to represent the seats
    // Initialize all seats to 0 (unbooked)

    int seats[10][10] = {};

    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            seats[i][j] = 0;
        }
    }

    // Mark the booked seats
    for (int i = 0; i < booking_count; i++) 
    {
        if (bookings[i].movieTitle == movieList[i].movieTitle) 
        {
            int row = (bookings[i].seats_booked - 1) / 10;
            int seat = (bookings[i].seats_booked - 1) % 10;

        }
    }

    // Display the seat layout
    cout << "        Screen            \n";
    cout << "--------------------------\n";
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            if (seats[i][j] == 0) 
            {
                cout << "O ";
            }
            else {
                cout << "X ";
            }
        }
        cout << endl;
    }
    cout << endl;

    make_booking(movieList, const_cast<Booking*>(bookings), booking_count);  // Use const_cast to remove the const qualifier
}

void promo() 
{
    ifstream inFile;
    inFile.open("promoAnnounceList.txt"); // read existing promotion / announcement list in the promoAnnounceList.txt
    int i = 0;
    while (getline(inFile, promoAnnouncementList[i].promoOrAnnouncement) && getline(inFile, promoAnnouncementList[i].promoAnnouncementTitle) && getline(inFile, promoAnnouncementList[i].promoAnnouncementDetails))
    {
        // display promotion / announcement accordingly
        cout << i + 1 << ". " << endl;
        cout << promoAnnouncementList[i].promoOrAnnouncement << endl;
        cout << "=" << promoAnnouncementList[i].promoAnnouncementTitle << "=" << endl;
        cout << endl;
        cout << " [ " << promoAnnouncementList[i].promoAnnouncementDetails << " ] " << endl;
        cout << endl;

        i++;
        promoAnnouncementListSize = i;
    }
    inFile.close();

    cout << endl;
    cout << "(Press any key to back to Main Menu)" << endl;
    cin.ignore();
}

void feedback() 
{
    string comment;
    ofstream feedback;
    feedback.open("feedback.txt");

    cout << "Enter your feedback\t:";
    getline(cin, comment);
    getline(cin, comment);
    feedback << comment;
    feedback.close();
    cout << "Feedback Succesful";
}

// Function to make a booking for a movie

void make_booking(movieInformation* movieList, Booking* bookings, int& booking_count)
{


    // Display the available seats for the movie
    display_seats(booking_count);

    // Ask the user to select a seat
    int seat;
    cout << "Enter the seat number you want to book (1-100): ";
    cin >> seat;
    cin.ignore();

    // Validate the user's choice
    while (seat < 1 || seat > 100)
    {
        cout << "Invalid seat number. Please enter again: ";
        cin >> seat;
        cin.ignore();
    }

    // Check if the seat is already booked
    for (int i = 0; i < booking_count; i++)
    {
        if (bookings[i].movieTitle == movieList[i].movieTitle && bookings[i].seats_booked == seat)
        {
            cout << "Seat already booked. Please select another seat." << endl;
            make_booking(movieList, bookings, booking_count); // Call the function again to continue the booking process
            return;

            // Add the booking to the movie
            bookings[booking_count].movieTitle = movieList[i].movieTitle;
            bookings[booking_count].seats_booked = seat;

            booking_count = booking_count + 1;
        }
    }


    // Confirm the booking
    cout << "Confirm booking (Y/N)? ";
    char confirm;
    cin >> confirm;
    cin.ignore();

    if (confirm == 'Y' || confirm == 'y')
    {
        cout << "Seat " << seat << " booked successfully." << endl;
        cout << "Thank you for your booking." << endl;
    }
    else if (confirm == 'N' || confirm == 'n')
    {
        cout << "Booking is cancelled." << endl;
    }
    else
    {
        cout << "Please enter a valid input" << endl;
        cin >> confirm;
        cin.ignore();
    }
}

    // Function to display the review summary for a movie
    void display_review_summary(const movieInformation * movieList)
    {
        for (int i = 0; i < booking_count; i++)
        {
            if (bookings[i].movieTitle == movieList[i].movieTitle)
            {
                cout << "Review Summary for " << movieList[i].movieTitle << endl;
                cout << "Release Date: " << movieList[i].releaseDate << endl;
                cout << "Genre: " << movieList[i].movieGenre << " minutes" << endl;
                cout << "Age Rating: " << movieList[i].ageRating << endl;
                cout << "Duration: " << movieList[i].movieLength << endl;
                cout << "Director: " << movieList[i].Director << endl;
            }
        }
    }

    void review() 
    {
        for (int i = 0; i < booking_count; i++)
        {
            if (bookings[i].movieTitle == movieList[i].movieTitle)
            {
                movieInformation movieList[MAX_MOVIES] = {movieList[i].movieTitle, movieList[i].releaseDate, movieList[i].movieGenre, movieList[i].ageRating, movieList[i].movieLength, movieList[i].Director};
            }
        }

        // Display the review summary for the movie
        display_review_summary(movieList);
    }

    double calculate_price(const Booking* booking) 
    {
        double base_price = 12.0;
        double price = base_price * ((double)booking->seats_booked);

        // Set the price in the booking structure
        //booking->price = price;

        return price;
    }

    // Function to process a payment
    void process_payment(const Booking& booking)
    {
        int method = 0;
        // Display the booking details and price
        cout << "Booking Details\n";
        cout << "---------------\n";
        cout << "Customer Name: " << booking.customer_name << endl;
        cout << "Movie Name: " << booking.movieTitle << endl;
        cout << "Seats Booked: " << booking.seats_booked << endl;
        cout << "Price: $" << booking.price << endl;

        // Ask the user to enter their payment information

        cout << "PLease select your payment method" << endl;
        cout << "1.  Credit Card " << endl;
        cout << "2.  Online Banking" << endl;
        cout << "3.  E-wallet " << endl;

        cin >> method;
        cin.ignore();

        if (method == 1)
        {

            cout << "Enter your credit card number: ";
            string card_number;
            cin >> card_number;
            cin.ignore();

            cout << "Enter the expiration date (MM/YY): ";
            string expiration_date;
            cin >> expiration_date;
            cin.ignore();

            cout << "Enter the security code: ";
            string security_code;
            cin >> security_code;
            cin.ignore();

        }
        else if (method == 2)
        {

            cout << "Enter the name of your bank: " << endl;
            string bank_name;
            cin >> bank_name;
            cin.ignore();

            cout << "Enter your login ID: " << endl;
            string login_ID;
            cin >> login_ID;
            cin.ignore();

            cout << "Enter your password: " << endl;
            string password;
            cin >> password;
            cin.ignore();

        }

        else if (method == 3)
        {
            cout << "Enter your phone number: " << endl;
            string phone_number;
            cin >> phone_number;
            cin.ignore();

            cout << "Enter your pin number: " << endl;
            int pin_number;
            cin >> pin_number;
            cin.ignore();

        }

        else
        {
            cout << "Invalid input. Please select again";
            process_payment(booking);
            return;
        }

        // Process the payment 
        cout << "Processing payment..." << endl;
        cout << "Payment successful!" << endl;

    }

    void adminLogin() // display admin login menu
    {
        string adminPass = "abc12345", adminID = "12345"; 
        // fixed adminID and admin password
        cout << "========================" << endl;
        cout << "=  Admin Login Page    =" << endl;
        cout << "========================" << endl;
        
        cout << "Please input your ID and Password" << endl;
        cout << "ID       : ";
        cin >> adminID; // input adminID
        cout << "Password   : ";
        cin >> adminPass; // input admin password

        if (adminID == "12345" && adminPass == "abc12345") // to verify whether adminID and admin password filled matched
        {
            // adminID and admin password matched
            system("cls"); 
            adminMenu(); // function call to display the admin main menu
        }
        else
        {
            // adminID or admin password not match
            cout << endl;
            cout << "Invalid ID or password, press any key to back to main menu and try again or contact management for further support. " << endl;
            cin.ignore();
            cin.ignore();
            system("cls");
            main();
        }
    }

    void adminMenu() // display admin main menu
    {
        char choice2;
        cout << "1) Show movie list" << endl;
        cout << "2) View promotion and announcement" << endl;
        cout << "3) Logout" << endl;
        cout << "\nPlease insert a value from 1 to 3 to continue : ";
        cin >> choice2; //input a value to proceed 

        while (choice2)
        {

            if (choice2 < '1' || choice2 > '3') // to check whether choice input is within the range 
            {
                // the choice input is out of range
                system("cls");
                cout << endl;
                cout << "Invalid input. Please only insert a value from 1 to 3 to proceed. " << endl;
                cout << endl;
                adminMenu();
            }
            else
            {
                switch (choice2) // the choice input is within the range
                {
                case '1':
                    system("CLS");
                    showMovieList(); // function call to display the movie list main menu
                    break;
                case '2':
                    system("CLS");
                    showPromotionAnnouncementList(); // function call to display the promotion / announcement list main menu
                    break;
                case '3':
                    system("CLS");
                    main(); // function call to display and return to the main menu of the system
                    break;
                }
            }
        }
    }

    void showMovieList() // display movie list main menu
    {
           ifstream inFile;
           inFile.open("movieList.txt"); // read the existing movie list in the moveList.txt file
           int i = 0;
           while (getline(inFile, movieList[i].movieTitle), getline(inFile, movieList[i].releaseDate), getline(inFile, movieList[i].movieGenre), getline(inFile, movieList[i].ageRating), getline(inFile, movieList[i].movieLength), getline(inFile, movieList[i].Director))
           {
                   // display movie list accordingly
                   cout << i+1 << ". " << endl;
                   cout << "Title: " << movieList[i].movieTitle << endl;
                   cout << "Release Date: " << movieList[i].releaseDate << endl;
                   cout << "Genre: " << movieList[i].movieGenre << endl;
                   cout << "Age Rating: " << movieList[i].ageRating << endl;
                   cout << "Movie Duration: " << movieList[i].movieLength << endl;
                   cout << "Director: " << movieList[i].Director << endl;
                   cout << endl;

                   i++;
                   movieListSize = i;
           }

           inFile.close();

           char choice3;
           cout << endl;
           cout << "1. Add Movie   " << endl;
           cout << "2. Modify Movie  " << endl;
           cout << "3. Delete Movie" << endl;
           cout << "4. Back to Main Menu" << endl;
           cout << "Please insert a value to proceed: ";
           cin >> choice3; // input a value to proceed

           while (choice3)
           {
               if (choice3 < '1' || choice3 > '4') // to check if the value input is wiithin the range
               {
                   // the value input is out of range
                   system("cls");
                   cout << endl;
                   cout << "---(Invalid input. Please only insert a value from 1 to 4 to continue)---" << endl;
                   cout << endl;
                   showMovieList();
               }
               else
               {
                   switch (choice3) // the value input is within the range
                   {
                   case '1':
                       system("CLS");
                       addMovie(); // function call to display adding movie menu
                       break;
                   case '2':
                       system("CLS");
                       modifyMovie(); // function call to display modifying movie menu
                       break;
                   case '3':
                       system("CLS");
                       deleteMovie(); // function call to display deleting movie menu
                       break;
                   case '4':
                       system("cls");
                       adminMenu(); // function call to display and return to admin main menu
                       break;
                   }
               }
           }
    }

    void addMovie() // display adding movie menu
    {
        char continue1;

        do
        {
            if (movieListSize >= MAX_MOVIES) // to check if the movie size is in maximum capacity
            {
                // movie size is in maximum capacity
                cout << "Maximum capacity of movies listed. Please modify some movies before proceed to add more movie to the list. " << endl;
                cin.ignore();
                adminMenu();
            }
            else
            {
                // still able to add more movie
                string movieTitle, releaseDate, movieGenre, ageRating, movieLength, Director;
                cout << "Insert movie title here: ";
                cin.ignore();
                getline(cin, movieTitle); // input title of movie to be add
                cout << "Insert movie release date here: ";
                getline(cin, releaseDate); // input release date of movie to be add
                cout << "Insert movie genre here: ";
                getline(cin, movieGenre); // input genre of movie to be add
                cout << "Insert movie age rating here: ";
                getline(cin, ageRating); // input age rating of movie to be add
                cout << "Insert movie duration here: ";
                getline(cin, movieLength); // input duration of movie to be add
                cout << "Insert director of the movie here: ";
                getline(cin, Director); // input director of movie to be add

                movieList[movieListSize++] = { movieTitle, releaseDate, movieGenre, ageRating, movieLength, Director };
                // add one movie into the list

                ofstream addMovie("movieList.txt", ios::app);
                // save the information into the movieList.txt file
                addMovie << movieTitle << endl;
                addMovie << releaseDate << endl;
                addMovie << movieGenre << endl;
                addMovie << ageRating << endl;
                addMovie << movieLength << endl;
                addMovie << Director << endl;
                addMovie.close();

                do // to determine whether is there any more movie to add
                {
                    system("CLS");
                    cout << endl;
                    cout << "Movie was added successfully.\n";
                    cout << endl;
                    cout << "Do you want to add more movies? [Y] = Yes [N] = No " << endl;
                    cout << "==> ";
                    cin >> continue1; // input a character to proceed

                    if (continue1 == 'N' || continue1 == 'n') // stop adding more movie
                    {
                        system("cls");
                        showMovieList(); // function call to display and return to movie list main menu
                    }
                    else if (continue1 == 'Y' || continue1 == 'y') // to add more movie
                    {
                        system("cls");
                    }
                    else // character input is invalid
                    {
                        cout << "\nInvalid input, press any key to try again. " << endl;
                        cin.ignore();
                        cin.ignore();
                    }
                } while (continue1 != 'N' && continue1 != 'n' && continue1 != 'Y' && continue1 != 'y'); // if character input is invalid, ask again

            }
        } while ( continue1 == 'Y' || continue1 == 'y' ); // if proceed to add more movie

    }
    
   void modifyMovie() // display modifying movie menu
   {
       char modify1, confirm1, continue2;

       do
       {
           do
           {
               if (movieListSize == 0) // to check if there is any movie in the list
               {
                   // no movie in the list
                   cout << " There is no movies in the list available to modify. " << endl;
                   cin.ignore();
                   showMovieList();
               }
        
               string movieToModify;
               cout << "Enter the movie title to modify: ";
               cin.ignore();
               getline(cin, movieToModify); // insert the title of movie to modify

               int index = -1;
               for (int i = 0; i < movieListSize; i++) // to check if movie title inserted matched one of the movie title in the list
               {
                   if (movieList[i].movieTitle == movieToModify) 
                   {
                       index = i; //assign index to the number position of the selected movie 
                       break;
                   }
               }

               if (index == -1) // if movie title inserted does not matched any of the movie title in the list
               {
                   cout << "\nNo movie was found in the list. Press any key to back to main menu and try again with an existing title.  " << endl;
                   cin.ignore();
                   showMovieList(); // function call to display and return to movie list main menu
               }

               ofstream modifyingMovie;
               modifyingMovie.open("movieList.txt", ios::trunc); // modifying and replacing one of the movie information
               for (int i = 0; i < movieListSize; i++)
               {
                   if (movieList[i].movieTitle == movieToModify)// if movie title inserted matched one of the movie title in the list
                   {
                       movieInformation updatedMovie; // movie information modified

                       cout << "1. " << movieList[i].movieTitle << endl;
                       cout << "2. " << movieList[i].releaseDate << endl;
                       cout << "3. " << movieList[i].movieGenre << endl;
                       cout << "4. " << movieList[i].ageRating << endl;
                       cout << "5. " << movieList[i].movieLength << endl;
                       cout << "6. " << movieList[i].Director << endl;
                       cout << endl;
                       cout << "1. Movie Title " << endl;
                       cout << "2. Release Date " << endl;
                       cout << "3. Movie Genre " << endl;
                       cout << "4. Age Rating " << endl;
                       cout << "5. Movie Duration" << endl;
                       cout << "6. Director " << endl;
                       cout << "7. Cancel Modifying " << endl;                    
                       cout << "\nEnter a number to proceed: ";
                       cin >> modify1; // input a value to choose information of the selected movie to modify
                       cin.ignore();

                       while (modify1 < 49 || modify1 > 55)
                       {
                           cout << "\nInvalid input, please only insert value from 1 to 7 to proceed. " << endl;
                           cout << "Enter a number to proceed: ";
                           cin >> modify1;
                           cin.ignore();
                       }

                       switch (modify1) 
                       {
                       case '1': // modify movie title
                           cout << "Enter a modified movie title: ";
                           getline(cin, updatedMovie.movieTitle); // input new movie title 

                           movieList[i].movieTitle = updatedMovie.movieTitle; // replace with new movie title
                           modifyingMovie << movieList[i].movieTitle << endl; // update information, other information remain the same
                           modifyingMovie << movieList[i].releaseDate << endl;
                           modifyingMovie << movieList[i].movieGenre << endl;
                           modifyingMovie << movieList[i].ageRating << endl;
                           modifyingMovie << movieList[i].movieLength << endl;
                           modifyingMovie << movieList[i].Director << endl;

                           modifyingMovie.close();
                           break;

                       case '2': // modify movie release date
                           cout << "Enter a modified movie release date: ";
                           getline(cin, updatedMovie.releaseDate); // input new movie release date

                           movieList[i].releaseDate = updatedMovie.releaseDate; // replace with new movie release date
                           modifyingMovie << movieList[i].movieTitle << endl; 
                           modifyingMovie << movieList[i].releaseDate << endl;// update information, other information remain the same
                           modifyingMovie << movieList[i].movieGenre << endl;
                           modifyingMovie << movieList[i].ageRating << endl;
                           modifyingMovie << movieList[i].movieLength << endl;
                           modifyingMovie << movieList[i].Director << endl;

                           modifyingMovie.close();
                           break;

                       case '3': // modify movie genre
                           cout << "Enter a modified movie genre: ";
                           getline(cin, updatedMovie.movieGenre); // input new movie genre

                           movieList[i].movieGenre = updatedMovie.movieGenre; // replace with new movie genre
                           modifyingMovie << movieList[i].movieTitle << endl; 
                           modifyingMovie << movieList[i].releaseDate << endl;
                           modifyingMovie << movieList[i].movieGenre << endl;// update information, other information remain the same
                           modifyingMovie << movieList[i].ageRating << endl;
                           modifyingMovie << movieList[i].movieLength << endl;
                           modifyingMovie << movieList[i].Director << endl;

                           modifyingMovie.close();
                           break;

                       case '4': // modify movie age rating
                           cout << "Enter a modified movie age rating: ";
                           getline(cin, updatedMovie.ageRating); // input new movie age rating

                           movieList[i].ageRating = updatedMovie.ageRating; // replace with new movie age rating
                           modifyingMovie << movieList[i].movieTitle << endl; 
                           modifyingMovie << movieList[i].releaseDate << endl;
                           modifyingMovie << movieList[i].movieGenre << endl;
                           modifyingMovie << movieList[i].ageRating << endl;// update information, other information remain the same
                           modifyingMovie << movieList[i].movieLength << endl;
                           modifyingMovie << movieList[i].Director << endl;

                           modifyingMovie.close();
                           break;

                       case '5': // modify movie duration
                           cout << "Enter a modified movie duration: ";
                           getline(cin, updatedMovie.movieLength); // input new movie duration

                           movieList[i].movieLength = updatedMovie.movieLength; // replace with new movie duration
                           modifyingMovie << movieList[i].movieTitle << endl; 
                           modifyingMovie << movieList[i].releaseDate << endl;
                           modifyingMovie << movieList[i].movieGenre << endl;
                           modifyingMovie << movieList[i].ageRating << endl;
                           modifyingMovie << movieList[i].movieLength << endl;// update information, other information remain the same
                           modifyingMovie << movieList[i].Director << endl;

                           modifyingMovie.close();
                           break;

                       case '6': // modify director of movie
                           cout << "Enter a modified director of the movie: ";
                           getline(cin, updatedMovie.Director); // input new director of movie

                           movieList[i].Director = updatedMovie.Director; // replace with new director of movie
                           modifyingMovie << movieList[i].movieTitle << endl; 
                           modifyingMovie << movieList[i].releaseDate << endl;
                           modifyingMovie << movieList[i].movieGenre << endl;
                           modifyingMovie << movieList[i].ageRating << endl;
                           modifyingMovie << movieList[i].movieLength << endl;
                           modifyingMovie << movieList[i].Director << endl;// update information, other information remain the same

                           modifyingMovie.close();
                           break;

                       case '7':
                           do
                           {
                               // remain the same
                               modifyingMovie << movieList[i].movieTitle << endl; 
                               modifyingMovie << movieList[i].releaseDate << endl;
                               modifyingMovie << movieList[i].movieGenre << endl;
                               modifyingMovie << movieList[i].ageRating << endl;
                               modifyingMovie << movieList[i].movieLength << endl;
                               modifyingMovie << movieList[i].Director << endl;

                               modifyingMovie.close();

                               cout << "\nDo you sure want to stop modifying? [Y] = Yes [N] = No " << endl;
                               cout << "==>" ;
                               cin >> confirm1; // input a character to proceed or stop modifying

                               if (confirm1 == 'Y' || confirm1 == 'y') // stop modifying
                               {
                                   system("cls");
                                   showMovieList(); // function call to display and return to the movie list main menu
                               }
                               else if (confirm1 == 'N' || confirm1 == 'n') // proceed to continue modifying
                               {
                                   system("cls");
                                   modifyMovie();
                               }
                               else // the character input is invalid
                               {
                                   cout << "\nInvalid input, presss any key to reconfirmation. " << endl;
                                   cin.ignore();
                                   cin.ignore();
                               }

                           } while (confirm1 != 'N' && confirm1 != 'n' && confirm1 != 'Y' && confirm1 != 'y'); // if the character input is invalid, ask again 

                       default:
                           cout << "\n Invalid input, please only insert value from 1 to 7 to proceed. " << endl;
                           cin.ignore();
                           break;
                       }

                   }
                   else // if movie title inserted does not matched the selected movie title in the list
                   {
                       // remain the same
                       modifyingMovie << movieList[i].movieTitle << endl;
                       modifyingMovie << movieList[i].releaseDate << endl;
                       modifyingMovie << movieList[i].movieGenre << endl;
                       modifyingMovie << movieList[i].ageRating << endl;
                       modifyingMovie << movieList[i].movieLength << endl;
                       modifyingMovie << movieList[i].Director << endl;

                   }

               }

               do
               {
                   // display movie modified successfully
                   system("cls");
                   cout << endl;
                   cout << "The selected movie updated successfully! " << endl;
                   cout << endl;
                   cout << "Do you want to modify another movies? [Y] = Yes [N] = No " << endl;
                   cout << "==> ";
                   cin >> continue2; // input a character whether to proceed modify other movie

                   if (continue2 == 'N' || continue2 == 'n') // stop modify other movie
                   {
                       system("cls");
                       showMovieList(); // function call to display and return to the movie list main menu
                   }
                   else if (continue2 == 'Y' || continue2 == 'y') // proceed to modify other movie
                   {
                       system("cls");
                   }
                   else // the character input is invalid
                   {
                       cout << "\nInvalid input, press any key to try again. " << endl;
                       cin.ignore();
                       cin.ignore();
                   }

               } while (continue2 != 'N' && continue2 != 'n' && continue2 != 'Y' && continue2 != 'y'); // if the character input is invalid, ask again

           }while (continue2 == 'Y' || continue2 == 'y'); // if proceed to modify other movie

       } while (confirm1 == 'N' || confirm1 == 'n'); // if proceed to continue modifying the selected movie 

   }

   void deleteMovie() // display deleting movie menu
   {     
       char continue3;
       
       do
       {
           if (movieListSize == 0) // to check if there is any movie in the list
           {
               //no movie is in the list
               cout << "There is no movies in the list available to delete." << endl;
               cin.ignore(); 
               showMovieList();
           }

           string movieToDelete;
           cout << "Enter the movie title to delete: ";
           cin.ignore();
           getline(cin, movieToDelete); // input a movie title to delete


           int index = -1;
           for (int i = 0; i < movieListSize; i++) // to check if movie title inserted matched one of the movie title in the list
           { 
               if (movieList[i].movieTitle == movieToDelete) 
               {
                   index = i; //assign index to the number position of the selected movie
                   break;
               }
           }

           if (index == -1) // if movie title inserted does not matched any of the movie title in the list
           {
               cout << "\nNo movie was found in the list. Press any key to back to main menu and try again with an existing title. " << endl;
               cin.ignore();
               showMovieList(); // function call to display and return to movie list main menu
           }

           for (int i = index; i < movieListSize - 1; i++)
           {
               movieList[i] = movieList[i + 1]; // replace the number position of some movie if affected
           }

           movieListSize--; // remove one movie from the list

           ofstream deleteMovie("movieList.txt", ios::trunc); // remove the selected movie from the list
           for (int i = 0; i < movieListSize; i++)
           {
               if (movieToDelete != movieList[i].movieTitle)
               {
                   deleteMovie << movieList[i].movieTitle << endl;
                   deleteMovie << movieList[i].releaseDate << endl;
                   deleteMovie << movieList[i].movieGenre << endl;
                   deleteMovie << movieList[i].ageRating << endl;
                   deleteMovie << movieList[i].movieLength << endl;
                   deleteMovie << movieList[i].Director << endl;
               }
           }
           deleteMovie.close();

           do
           {
               // display movie deleted successfully
               system("cls");
               cout << endl;
               cout << "The selected movie deleted successfully! " << endl;
               cout << endl;
               cout << "Do you want to delete another movies? [Y] = Yes [N] = No " << endl;
               cout << "==> ";
               cin >> continue3; // input a character to proceed or stop deleting movie

               if (continue3 == 'N' || continue3 == 'n') // stop deleting movie
               {
                   system("cls");
                   showMovieList(); // function call to display and return to the movie list main menu
               }
               else if (continue3 == 'Y' || continue3 == 'y') // proceed to delete more movie
               {
                   system("cls");
               }
               else // the character input is invalid
               {
                   cout << "\nInvalid input, please any key to try again. " << endl;
                   cin.ignore();
                   cin.ignore();
               }

           } while (continue3 != 'N' && continue3 != 'n' && continue3 != 'Y' && continue3 != 'y'); // if the character input is invalid, ask again
       
       } while (continue3 == 'Y' || continue3 == 'y'); // if proceed to delete more movie

   }

   void showPromotionAnnouncementList() // display promotion / announcement list main menu
   {
       ifstream inFile;
       inFile.open("promoAnnounceList.txt"); // read existing promotion / announcement list in the promoAnnounceList.txt
       int i = 0;
       while (getline(inFile, promoAnnouncementList[i].promoOrAnnouncement) && getline(inFile, promoAnnouncementList[i].promoAnnouncementTitle) && getline(inFile, promoAnnouncementList[i].promoAnnouncementDetails))
       {
           // display promotion / announcement accordingly
           cout << i+1 << ". " << endl;
           cout << promoAnnouncementList[i].promoOrAnnouncement << endl;
           cout << "=" << promoAnnouncementList[i].promoAnnouncementTitle << "=" << endl;
           cout << endl;
           cout << " [ " << promoAnnouncementList[i].promoAnnouncementDetails << " ] " << endl;
           cout << endl;

           i++;
           promoAnnouncementListSize = i;
       }

       inFile.close();

       char choice4;
       cout << endl;
       cout << "1. Add Promotion / Announcement " << endl;
       cout << "2. Modify Promotion / Announcement  " << endl;
       cout << "3. Delete Promotion / Announcement" << endl;
       cout << "4. Back to Main Menu" << endl;
       cout << "Please insert a value to proceed :";
       cin >> choice4;

       while (choice4)
       {
           if (choice4 < '1' || choice4 > '4') // to check if the value input is within the range
           {
               // the value input is out of range
               system("cls");
               cout << endl;
               cout << "---(Invalid Input. Please only insert a value from 1 to 4 to continue)---" << endl;
               cout << endl;
               showPromotionAnnouncementList();
           }
           else
           {
               switch (choice4) // the value input is within the range
               {
               case '1':
                   system("CLS");
                   addPromotionAnnouncement(); // function call to display adding promotion / announcement menu
                   break;
               case '2':
                   system("CLS");
                   modifyPromotionAnnouncement(); // function call to display modifying promotion / announcement menu
                   break;
               case '3':
                   system("CLS");
                   deletePromotionAnnouncement(); // function call to display deleting promotion / announcement menu
                   break;
               case '4':
                   system("cls");
                   adminMenu(); // function call to display and return to admin main
                   break;
               }
           }
       }
   }

   void addPromotionAnnouncement() // display adding promotion / announcement menu
   {
       char continue4;
       
       do
       {
           if (promoAnnouncementListSize >= MAX_PROMOANNOUNCEMENT) // tocheck if the promotion / announcement size is in maximum capacity
           {
               // promotion / announcement size is in maximum capacity
               cout << "Maximum capacity of promotions / announcement listed. Please modify some promotions / announcement before proceed to add more promotions / announcement to the list. " << endl;
               cin.ignore();
               adminMenu();
           }
           else
           {
               // still able to add more promotion / announcement
               string promoOrAnnouncement, promoAnnouncementTitle, promoAnnouncementDetails;
               cout << "Insert Promotion / Announcement here: ";
               cin.ignore();
               getline(cin, promoOrAnnouncement); // input Promotion / Announcement
               cout << "Insert promotion / announcement title here: ";
               getline(cin, promoAnnouncementTitle); // input promotion / announcement title
               cout << "Insert promotion / announcement details here: ";
               getline(cin, promoAnnouncementDetails); // input promotion / announcement details

               promoAnnouncementList[promoAnnouncementListSize++] = { promoOrAnnouncement, promoAnnouncementTitle, promoAnnouncementDetails };
               // add one promotion / announcement into the list

               ofstream addPromoAnnouncement("promoAnnounceList.txt", ios::app);
               // save the information into the promoAnnounceList.txt file
               addPromoAnnouncement << promoOrAnnouncement << endl;
               addPromoAnnouncement << promoAnnouncementTitle << endl;
               addPromoAnnouncement << promoAnnouncementDetails << endl;
               addPromoAnnouncement.close();

               do // to determine whether is there any more promotion / announcement to add
               {
                   system("CLS");
                   cout << endl;
                   cout << "Promotion / Announcement was added successfully.";
                   cout << endl;
                   cout << "Do you want to add more promotion / announcement? [Y] = Yes [N] = No " << endl;
                   cout << "==> ";
                   cin >> continue4; // input a character to proceed

                   if (continue4 == 'N' || continue4 == 'n') // stop adding more promotion / announcement
                   {
                       system("cls");
                       showPromotionAnnouncementList(); // function call to display and return to promotion / announcement list menu
                   }
                   else if (continue4 == 'Y' || continue4 == 'y') // to add more promotion / announcement
                   {
                       system("cls");
                   }
                   else // the character input is invalid
                   {
                       cout << "\nInvalid input, please any key to try again. " << endl;
                       cin.ignore();
                       cin.ignore();
                   }
               } while (continue4 != 'N' && continue4 != 'n' && continue4 != 'Y' && continue4 != 'y'); // if character input is invalid, ask again
           }
       } while (continue4 == 'Y' || continue4 == 'y'); // if procced to add more promotion / announcement
   }

void modifyPromotionAnnouncement() // display modifying promotion / announcement menu
{
       char modify2, confirm2, continue5;
       
       do
       {
           do
           {
           if (promoAnnouncementListSize == 0) // to check if there is any promotion / announcement in the list
           {
               // no promotion / announcement in the list
               cout << " There is no promotion / announcement in the list available to modify. " << endl;
               cin.ignore();
               showPromotionAnnouncementList();
           }

           string promoAnnouncementToModify;
           cout << "Enter the promotion / announcement title to modify: ";
           cin.ignore();
           getline(cin, promoAnnouncementToModify); // insert the title of promotion / announcement to modify

           int index = -1;
           for (int i = 0; i < promoAnnouncementListSize; i++) // to check if the promotion / announcement title inserted matched one of the promotion / announcement title in the list
           {
               if (promoAnnouncementList[i].promoAnnouncementTitle == promoAnnouncementToModify)
               {
                   index = i; //assign index to the number posistion of the selected promotion / announcement
                   break;
               }
           }

           if (index == -1) // promotion / announcement inserted does not matched any of the promotion / announcement title in the list
           {
               cout << "No promotion / announcement was found in the list. Press any key to back to main menu and try again with an existing title." << endl;
               cin.ignore();
               showPromotionAnnouncementList(); // function call to display and return to promotion / announcement list main menu
           }

           ofstream updatePromoAnnounce;
           updatePromoAnnounce.open("promoAnnounceList.txt", ios::trunc); // modifying and replacing one of the promotion / announcement information
           for (int i = 0; i < promoAnnouncementListSize; i++)
           {
               if (promoAnnouncementList[i].promoAnnouncementTitle == promoAnnouncementToModify) // if the promotion / announcement title inserted matched one of the movie title in the list
               {
                   promoAnnouncementInformation updatedPromoAnnouncement; // promotion / announcement information modified

                   cout << "1. " << promoAnnouncementList[i].promoOrAnnouncement << endl;
                   cout << "2. " << promoAnnouncementList[i].promoAnnouncementTitle << endl;
                   cout << "3. " << promoAnnouncementList[i].promoAnnouncementDetails << endl;
                   cout << endl;
                   cout << "1. Promotion / Announcement " << endl;
                   cout << "2. Promotion / Announcement Title " << endl;
                   cout << "3. Promotion / Announcement Details " << endl;
                   cout << "4. Cancel Modifying " << endl;
                   cout << "\nEnter a number to proceed : ";
                   cin >> modify2; // input a value to choose information of the selected promotion / announcement to modify
                   cin.ignore();

                   while (modify2 < 49 || modify2 > 52)
                   {
                       cout << "\nInvalid input, please only insert value from 1 to 4 to proceed. " << endl;
                       cout << "Enter a number to proceed : ";
                       cin >> modify2;
                       cin.ignore();
                   }

                   switch (modify2)
                   {
                   case '1': // modify Promotion or Announcement
                       cout << "Enter a modified Promotion / Announcement: ";
                       getline(cin, updatedPromoAnnouncement.promoOrAnnouncement); // input new Promotion or Announcement

                       promoAnnouncementList[i].promoOrAnnouncement = updatedPromoAnnouncement.promoOrAnnouncement; // replace with new Promotion or Announcement
                       updatePromoAnnounce << promoAnnouncementList[i].promoOrAnnouncement << endl; // update information, other information remain the same
                       updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementTitle << endl;
                       updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementDetails << endl;

                       updatePromoAnnounce.close();
                       break;

                   case '2': // modify promotion / announcement title
                       cout << "Enter a modified promotion / announcement title: ";
                       getline(cin, updatedPromoAnnouncement.promoAnnouncementTitle); // input new promotion / announcement title

                       promoAnnouncementList[i].promoAnnouncementTitle = updatedPromoAnnouncement.promoAnnouncementTitle; // replace with new promotion / announcement title
                       updatePromoAnnounce << promoAnnouncementList[i].promoOrAnnouncement << endl;
                       updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementTitle << endl; // update information, other information remain the same
                       updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementDetails << endl;

                       updatePromoAnnounce.close();
                       break;

                   case '3': // modify promotion / announcement details
                       cout << "Enter a modified promotion / announcement details: ";
                       getline(cin, updatedPromoAnnouncement.promoAnnouncementDetails); // input new promotion / announcement details

                       promoAnnouncementList[i].promoAnnouncementDetails = updatedPromoAnnouncement.promoAnnouncementDetails; // replace with new promotion / announcement details
                       updatePromoAnnounce << promoAnnouncementList[i].promoOrAnnouncement << endl;
                       updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementTitle << endl;
                       updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementDetails << endl; // update information, other information remain the same

                       updatePromoAnnounce.close();
                       break;

                   case '4':
                       do
                       {
                           // remain the same
                           updatePromoAnnounce << promoAnnouncementList[i].promoOrAnnouncement << endl;
                           updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementTitle << endl;
                           updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementDetails << endl;

                           updatePromoAnnounce.close();

                           cout << "\nDo you sure want to stop modifying? [Y] = Yes [N] = No " << endl;
                           cout << "==>" ;
                           cin >> confirm2; // input a character to proceed or stop modifying

                           if (confirm2 == 'Y' || confirm2 == 'y') // stop modifying
                           {
                               system("cls");
                               showPromotionAnnouncementList(); // function call to display and return to the promotion / announcement list main menu
                           }
                           else if (confirm2 == 'N' || confirm2 == 'n') // proceed to continue modifying
                           {
                               system("cls");
                               modifyPromotionAnnouncement();
                           }
                           else // the character input is invalid
                           {
                               cout << "\nInvalid input, please any key to reconfirmation. " << endl;
                               cin.ignore();
                               cin.ignore();
                           }

                       } while (confirm2 != 'N' && confirm2 != 'n' && confirm2 != 'Y' && confirm2 != 'y'); // if the character input is invalid, ask again
                   
                   default:
                       cout << "\n Invalid input, please only insert value from 1 to 7 to proceed. " << endl;
                       cin.ignore();
                       break;

                   }

               }
               else // if promotion / announcement title does not matched the selected movie title in the list
               {
                   // remain the same
                   updatePromoAnnounce << promoAnnouncementList[i].promoOrAnnouncement << endl;
                   updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementTitle << endl;
                   updatePromoAnnounce << promoAnnouncementList[i].promoAnnouncementDetails << endl;

               }
           }

               do
               {
                   // display promotion / announcement modified successfully
                   system("cls");
                   cout << endl;
                   cout << "The selected promotion / announcement updated successfully! " << endl;
                   cout << endl;
                   cout << "Do you want to modify another promotion / announcement? [Y] = Yes [N] = No " << endl;
                   cout << "==> ";
                   cin >> continue5; // input a character whether to proceed modify other promotion / announcement

                   if (continue5 == 'N' || continue5 == 'n') // stop modify other promotion / announcement
                   {
                       system("cls");
                       showPromotionAnnouncementList(); // function call to display and return to the promotion / announcement list main menu
                   }
                   else if (continue5 == 'Y' || continue5 == 'y') // proceed to modify other promotion / announcement
                   {
                       system("cls");
                   }
                   else // the character input is invalid
                   {
                       cout << "\nInvalid input, please any key to try again. " << endl;
                       cin.ignore();
                       cin.ignore();
                   }
               } while (continue5 != 'N' && continue5 != 'n' && continue5 != 'Y' && continue5 != 'y'); // if the character input is invalid, ask again

           }while (continue5 == 'Y' || continue5 == 'y'); // if procced to modify other promotion / announcement
       
       }while (confirm2 == 'N' || confirm2 == 'n'); // if proceed to continue modifying the selected promotion / announcement 

   }

   void deletePromotionAnnouncement() // display deleting promotion / announcement menu
   {
       char continue6;

       do
       {
           if (promoAnnouncementListSize == 0) // to check if there is any promotion / announcement in the list
           {
               // no promotion / announcement is in the list
               cout << "There is no promotion / announcement in the list available to delete." << endl;
               showPromotionAnnouncementList();
               cin.ignore();
           }
           string promoAnnouncementToDelete;
           cout << "Enter the promotion / announcement title to delete: ";
           cin.ignore();
           getline(cin, promoAnnouncementToDelete); // input a promotion / announcement title to delete

           int index = -1;
           for (int i = 0; i < promoAnnouncementListSize; i++) // to check if promotion / announcement title inserted matched one of the promotion / announcement title in the list
           {
               if (promoAnnouncementList[i].promoAnnouncementTitle == promoAnnouncementToDelete)
               {
                   index = i; // assign index to the number position of the selected promotion / announcement
                   break;
               }
           }

           if (index == -1) // if promotion / announcement title inserted does not matched any of the movie title in the list
           {
               cout << "No promotion / announcement was found in the list. Press any key to back to main menu and try again with an existing title. " << endl;
               cin.ignore();
               showPromotionAnnouncementList(); // function call to display and return to promotion / announcement list main menu
           }

           for (int i = index; i < promoAnnouncementListSize - 1; i++) 
           {
               promoAnnouncementList[i] = promoAnnouncementList[i + 1]; // replace the number position of some promotion / announcement if affected
           }

           promoAnnouncementListSize--; // remove one movie from the list

           ofstream deletePromoAnnounce("promoAnnounceList.txt", ios::trunc); // remove the selected movie from the list
           for (int i = 0; i < promoAnnouncementListSize; i++)
           {
               if (promoAnnouncementList[i].promoAnnouncementTitle != promoAnnouncementToDelete)
               {
                   deletePromoAnnounce << promoAnnouncementList[i].promoOrAnnouncement << endl;
                   deletePromoAnnounce << promoAnnouncementList[i].promoAnnouncementTitle << endl;
                   deletePromoAnnounce << promoAnnouncementList[i].promoAnnouncementDetails << endl;
               }
           }
           deletePromoAnnounce.close();

           do
           {
               // display movie deleted successfully
               system("cls");
               cout << endl;
               cout << "The selected promotion / announcement deleted successfully! " << endl;
               cout << endl;
               cout << "Do you want to delete another promotion / announcement? [Y] = Yes [N] = No " << endl;
               cout << "==> ";
               cin >> continue6; // input a character to proceed or stop deleting promotion / announcement

               if (continue6 == 'N' || continue6 == 'n') // stop deleting promotion / announcement
               {
                   system("cls");
                   showPromotionAnnouncementList(); // function call to display and return to the promotion / announcement list main menu
               }
               else if (continue6 == 'Y' || continue6 == 'y') // proceed to delete more promotion / announcement
               {
                   system("cls");
               }
               else // the character input is invalid
               {
                   cout << "\nInvalid input, please any key to try again. " << endl;
                   cin.ignore();
                   cin.ignore();
               }
           } while (continue6 != 'N' && continue6 != 'n' && continue6 != 'Y' && continue6 != 'y'); // if the character input is invalid, ask again

       } while (continue6 == 'Y' || continue6 == 'y'); // if proceed to delete more promotion / announcement

   }



                                                                                                                       


                                                    

