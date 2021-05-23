#include <bits/stdc++.h>
using namespace std;
#define _WIN32_WINNT 0x0500
#include<windows.h>
#include <conio.h>


/* --------------- time delay function --------------- */
void timeDelay()
{
	// int iCurrentTime = 0;
	// int iElapsedTime = 0;
	//
	// iCurrentTime = time(NULL);
	// do { // do1
	// 		iElapsedTime = time(NULL);
	// 	} while ((iElapsedTime - iCurrentTime) < 2);
	Sleep(1000);
	system("cls");

	//cout << "SMART CITY SYSTEM" << endl << endl;
}
// global parameters
COORD coord={45,13};

int row,col;

//To get the no. of rows and columns of the console screen
void GetScreenSize(int &row,int &col)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
    col=csbi.srWindow.Right-csbi.srWindow.Left+1;
    row=csbi.srWindow.Bottom-csbi.srWindow.Top+1;
}

//For Opening The console in Maximised mode
void Maximize(void)
{
    HWND consoleWindow=GetConsoleWindow();
    ShowWindow(consoleWindow,SW_MAXIMIZE);
}

//For Jumping to different parts of the screen and
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//For Borders and formatting
void border(int a,int b)
{
    for(int i=0;i<col;i++)
        {
            gotoxy(col-i-1,a);cout<<"-";
            gotoxy(i,0);cout<<"-";
            gotoxy(i,row-1);cout<<"~";
            Sleep(b);
        }
        for(int i=0;i<row;i++)
            {
                gotoxy(0,i);cout<<"|";
                gotoxy(col-1,i);cout<<"|";Sleep(b);
            }
}

void headingText(){
	gotoxy(col/2-37,1);std::cout<<"   _____ __  __          _____ _______     _____ _____ _________     __";
	gotoxy(col/2-37,2);std::cout<<"  / ____|  \\/  |   /\\   |  __ \\__   __|   / ____|_   _|__   __\\ \\   / /";
	gotoxy(col/2-37,3);std::cout<<" | (___ | \\  / |  /  \\  | |__) | | |     | |      | |    | |   \\ \\_/ / ";
	gotoxy(col/2-37,4);std::cout << "  \\___ \\| |\\/| | / /\\ \\ |  _  /  | |     | |      | |    | |    \\   /";
	gotoxy(col/2-37,5);std::cout << "  ____) | |  | |/ ____ \\| | \\ \\  | |     | |____ _| |_   | |     | |";
	gotoxy(col/2-37,6);std::cout << " |_____/|_|  |_/_/    \\_\\_|  \\_\\ |_|      \\_____|_____|  |_|     |_|";

}

/* --------------- CLASSES --------------- */

//class ADMIN
class ADMIN {

	public:

	string name;
	string password;

	public:
		ADMIN()
		{
			name = "ADMIN";
			password = "admin123";
		}

};


//class USER
class USER {

public:
	string name;
	int id;
	string password;

public:
	USER(string name, int id)
	{
		this -> name = name;
		this -> id = id;
		password = "xyz";

		setPassword();
	}

    void setPassword()
    {
    	string p;
    	gotoxy(col/2-13,row/2+2);cout << "Enter Password : ";
    	cin >> p;

    	password = p;
    }

    void changePassword()
    {
    	string oldPass;
    	cout << "Enter Previous Password : ";
    	cin >> oldPass;

    	if(oldPass == password)
    	{
    		string newPass;
    		cout << "Enter New Password : ";
    		cin >> newPass;

    		password = newPass;
    	}

    	else
    	{
    		cout << "Incorrect Password! ";
    	}
    }

    virtual void displayDetails()
    {
    	//cout << "User Name : " << name << "  ID : " << id << endl;
    }

};


//class STUDENT inherited from class USER
class STUDENT : public USER {

public:

    string email;
    int schoolId;

public:

	STUDENT(string name, int id, string email) : USER(name, id) {
		this -> email = email;

		int i;
		gotoxy(col/2-13,row/2+3);cout << "Enter School ID : ";
		cin >> i;
		this -> schoolId = i;
	}

	void displayDetails()
    {
    	cout << "Student Name : " << name << "  ID : " << id << "  Mail : " << email << endl;
    }

};


//class TOURIST inherited from class USER
class TOURIST : public USER {

public:
    string email;
    string country;

public:

	TOURIST(string name, int id, string email) : USER(name, id) {
		this -> email = email;

		string c;
		gotoxy(col/2-13,row/2+3);cout << "Enter Country : ";
		cin >> c;
		this -> country = c;
	}

	void displayDetails()
    {
    	cout << "Tourist Name : " << name << "  ID : " << id << "  Country : " << country << endl;
    }

};


//class WORK inherited from class USER
class WORK : public USER {

public:
    string email;
    string type;

public:

	WORK(string name, int id, string email) : USER(name, id) {
		this -> email = email;

        char workType;
		gotoxy(col/2-13,row/2+3);cout << "Enter Profile Type - BUSINESS(B) / JOBSEEKER(J) / SERVICES(S) : ";
		cin >> workType;

		type = workType;
	}

	void displayDetails()
    {
    	cout << "Name : " << name << "  ID : " << id << "  Profession : " << type << endl;
    }

};

/* --------------- function declarations --------------- */

vector <STUDENT> student;
vector <TOURIST> tourist;
vector <WORK> work;

void home();
void signUp();
void optionsStudent();
void optionsTourist();
void optionsWork();

/* --------------- INFORMATION SECTION --------------- */

void schools() {
	//system("cls");
	timeDelay();
cout<<"\n\n";
	gotoxy(col/2-13,3);cout << "SCHOOLS IN DELHI"<<"\n";
	cout << "Select to view details - ";

	cout << endl << "1. Ahlcon International School" << endl;
	cout << "2. Laxmi Public Senior Secondary School" << endl;
	cout << "3. Delhi Public School (DPS)" << endl;
	cout << "4. Don Bosco School" << endl;
	cout << "5. Modern School" << endl;
	cout << "6. Sanskriti School" << endl;
	cout << "7. Apeejay School" << endl;
	cout << "8. Springdales School" << endl;
	cout << "9. Mother's Global School" << endl;
	cout << "10. View more.." << endl;
	cout << "11. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

	if(c==1)
	{
		cout << "Ahlcon International School" << endl;
		cout << "Address - Mayur Vihar, Phase-1, Opp. Una Enclave, Near Delhi Police Apartment, New Delhi,11009" << endl;
		cout << "Board - CBSE" << endl;
		cout << "Contact - contact@ahlconinternational.in  |  011 4777 0777" << endl;
	}

    else if(c == 2)
    {
    	cout << "Laxmi Public Senior Secondary School" << endl;
		cout << "Address - X-20, Institutional Area, Karkardooma, New Delhi, Delhi-110092" << endl;
		cout << "Board - CBSE" << endl;
		cout << "Contact - 011 2237 6937" << endl;
    }

    else if(c == 3)
    {
    	cout << "Delhi Public School (DPS)" << endl;
		cout << "Address - Mathura Road, New Delhi, Delhi - 110003" << endl;
		cout << "Board - CBSE" << endl;
		cout << "Contact - 011 4339 9200" << endl;
    }

    else if(c == 4)
    {
    	cout << "Don Bosco School" << endl;
		cout << "Address - Alaknanda Rd, New Delhi, Delhi 110019" << endl;
		cout << "Board - CBSE" << endl;
		cout << "Contact - 011 2921 7712" << endl;
    }

    else if(c == 5)
    {
    	cout << "Modern School" << endl;
		cout << "Address - Barakhamba Road, New Delhi 110001" << endl;
		cout << "Board - CBSE" << endl;
		cout << "Contact - modern@modernschool.net  |  011-23311618/19/20" << endl;
    }

    else if(c == 6)
    {
    	cout << "Sanskriti School" << endl;
		cout << "Address - S Radhakrishna Marg, Chanakyapuri, New Delhi, Delhi 110021" << endl;
		cout << "Board - CBSE" << endl;
		cout << "Contact - 011 2688 3336" << endl;
    }

    else if(c == 7)
    {
    	cout << "Apeejay School" << endl;
		cout << "Address - Sheikh Sarai Road Near Malviya Nagar, Panchsheel Marg, Phase I, Sheikh Sarai, New Delhi, Delhi 110017" << endl;
		cout << "Board - CBSE" << endl;
		cout << "Contact - 011 2601 2218" << endl;
    }

    else if(c == 8)
    {
    	cout << "Springdales School" << endl;
		cout << "Address - Benito Juarez Road, Dhaula Kuan, New Delhi, Delhi 110021" << endl;
		cout << "Board - CBSE" << endl;
		cout << "Contact - 011 2411 6657" << endl;
    }

    else if(c == 9)
    {
    	cout << "Mothers Global School" << endl;
		cout << "Address - Preet Vihar, New Delhi 110092" << endl;
		cout << "Board - CBSE" << endl;
		cout << "Contact -  011 2250 1900 , 011 2252 7200" << endl;
    }

    else if(c == 10)
    {
    	cout << "For further info, visit xyz.org" << endl;
    }

    else if(c == 11)
    {
    	optionsStudent();
    	return;
    }

    cout << endl << "Do you want to view more schools? " << endl;
    cout << "For YES press 1, else press 2 " << endl;

    int p;
	cout << endl << "Enter Option : ";
	cin >> p;

	if(p == 1)
	{
       schools();
       return;
	}

	else
	{
		optionsStudent();
		return;
	}


}


void colleges() {
	//system("cls");
	timeDelay();

	gotoxy(col/2-13,3);cout << "COLLEGES & UNIVERSITIES IN DELHI" << endl;
	cout << endl << "Select to view details - ";

	cout << endl << "1. IIT-Delhi" << endl;
	cout << "2. Delhi Technological University (DTU)" << endl;
	cout << "3. Netaji Subhash University of Technology (NSUT)" << endl;
	cout << "4. University of Delhi (DU)" << endl;
	cout << "5. IP University (IPU)" << endl;
	cout << "6. Amity University" << endl;
	cout << "7. IIIT-Delhi" << endl;
	cout << "8. View more.." << endl;
	cout << "9. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;


    if(c == 1)
    {
    	cout << "Indian Institute of Delhi (IIT-D)" << endl;
    	cout << "Address - Hauz Khas, New Delhi, Delhi 110016" << endl;
    	cout << "Major courses - B.Tech, M.Tech, PhD" << endl;
    	cout << "Admission Criteria - via JEE Mains/Advanced" << endl;
    	cout << "Contact -  011-2659-7135 | info@iitd.ac.in" << endl;

    }

    else if(c == 2)
    {
    	cout << "Delhi Technological University (DTU)" << endl;
    	cout << "Address - Shahbad Daulatpur, Main Bawana Road, DL - 110042" << endl;
    	cout << "Major courses - B.Tech, M.Tech, PhD, MBA, BBA" << endl;
    	cout << "Admission Criteria - via JEE Mains/Advanced" << endl;
    	cout << "Contact - webmaster@dtu.ac.in | 011-27871018" << endl;

    }

    else if(c == 3)
    {
    	cout << "Netaji Subhash University of Technology (NSUT)" << endl;
    	cout << "Address - Dwarka Sector-3, Dwarka, Delhi, 110078" << endl;
    	cout << "Major courses - B.Tech, M.Tech, PhD" << endl;
    	cout << "Admission Criteria - via JEE Mains/Advanced" << endl;
    	cout << "Contact -  011-25000268" << endl;

    }

    else if(c == 4)
    {
    	cout << "University of Delhi (DU)" << endl;
    	cout << "Major Colleges - SRCC, Hindu, Miranda House, LSR etc." << endl;
    	cout << "Major courses - B.Com, B.Com Hons, BBA, BSc, MSc, Economic Hons etc." << endl;
    	cout << "Admission Criteria - via XII boards" << endl;
    	cout << "Contact - 011-27667853" << endl;

    }

    else if(c == 5)
    {
    	cout << "Indraprastha University (IPU)" << endl;
    	cout << "Address - Sector - 16C, Dwarka, New Delhi - 110078" << endl;
    	cout << "Major courses - B.Tech, M.Tech, BBA, MBA" << endl;
    	cout << "Admission Criteria - Info. Not Available" << endl;
    	cout << "Contact - +91-11-25302170" << endl;

    }

    else if(c == 6)
    {
    	cout << "Amity University" << endl;
    	cout << "Address - Amity Rd, Sector 125, Noida, Uttar Pradesh 201301" << endl;
    	cout << "Major courses - All courses available" << endl;
    	cout << "Admission Criteria - Info. Not Available" << endl;
    	cout << "Contact - 0120 439 2000" << endl;

    }

    else if(c == 7)
    {
    	cout << "IIIT Delhi" << endl;
    	cout << "Address - Okhla Industrial Estate, Phase III, Delhi 110020" << endl;
    	cout << "Major courses - Engineering" << endl;
    	cout << "Admission Criteria - via JEE Mains" << endl;
    	cout << "Contact - 011-26907400-7404" << endl;

    }

    else if(c == 8)
    {
    	cout << "For further info, visit xyz.org" << endl;
    }

    else if(c == 9)
    {
    	optionsStudent();
    	return;
    }

    cout << endl << "Do you want to view more colleges? " << endl;
    cout << "For YES press 1, else press 2 " << endl;

    int p;
	cout << endl << "Enter Option : ";
	cin >> p;

	if(p == 1)
	{
       colleges();
       return;
	}

	else
	{
		optionsStudent();
		return;
	}

	cout << endl << "Do you want to view more colleges? " << endl;
    cout << "For YES press 1, else press 2 " << endl;

    int o;
	cout << endl << "Enter Option : ";
	cin >> o;

	if(p == 1)
	{
       colleges();
       return;
	}

	else
	{
		optionsStudent();
		return;
	}

}


void museums(int a) {

	timeDelay();

	gotoxy(col/2-13,3);cout << "MUSEUMS IN DELHI" << endl;
	cout << endl << "Select to view details - ";

	cout << endl << "1. National Museum" << endl;
	cout << "2. National Handicrafts and Handlooms Museum" << endl;
	cout << "3. National Rail Museum" << endl;
	cout << "4. Shankar’s International Dolls Museum" << endl;
	cout << "5. National Gallery of Modern Art" << endl;
	cout << "6. Nehru Memorial Museum & Library" << endl;
	cout << "7. Gandhi Smriti" << endl;
	cout << "8. View more.." << endl;
	cout << "9. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

	if(c == 1)
	{
	   cout << "National Museum" << endl << endl;
       cout << "The National Museum of India, it is one of the largest museums in Delhi. " << endl <<
       "Boasting of over 200,000 works of foreign and Indian art, this museum covers more than 5,000 years of worldwide rich cultural heritage."
       "It is home to a plethora of departments such as archaeology, manuscripts, pre-history archaeology, paintings, arms and armour and much more."
       << endl << "Location- Janpath, New Delhi" << endl <<
       "Entry Fee- Rs 20 for Indians and Rs 650 for Foreigners (Students up to class 12th get free entry ticket)"
       << endl << "Timings- 10 AM to 6 PM (Monday Closed)" << endl
       << "Speciality- Radha and Krishna in the boat of Love" << endl << endl;
	}

	else if(c == 2)
	{
	   cout << "National Handicrafts and Handlooms Museum" << endl << endl;

	   cout << "Run by the Ministry of Textiles, Government of India, this museum is home to over 35, 000 distinctive pieces of craft;"
	   "all of which reflect the amazing skills and craftsmanship of Indian craftsmen via embroidery, paintings, textiles and clay, wood and stone craft items."

<< endl << "Location- Pragati Maidan, Bhairon Marg" << endl <<
"Entry Fee- Re 1 for Indian students, Rs 10 for Indians and Rs 150 for Foreigners" << endl <<
"Timings- 10 AM to 5 PM (Monday Closed)" << endl <<
"Speciality- Rare and Distinctive Craft Work" << endl << endl;
}

	else if(c == 3)
	{
		cout << "National Rail Museum" << endl << endl;

		cout << "Home to a fascinating collection of more than 100 real size exhibits of the Indian Railways, "
		"one can find displays of static and working models, historical photographs, antique furniture and signalling equipment in this best museum in Delhi."

<< endl << "Location- Chanakyapuri" << endl <<
"Entry Fee- Rs 50 for Adults, Rs 10 for children between ages 3 to 12. Rates double up on weekends and government holidays." << endl <<
"Timings- 9:30 AM to 5:30 PM (Monday Closed)" << endl <<
"Speciality- Rail Heritage of India" << endl << endl;
	}

	else if(c == 4)
	{
		cout << "Shankar’s International Dolls Museum" << endl;
	}

	else if(c == 5)
	{
		cout << "National Gallery of Modern Art" << endl;
	}

	else if(c == 6)
	{
		cout << "Nehru Memorial Museum & Library" << endl;
	}

	else if(c == 7)
	{
		cout << "Gandhi Smriti" << endl;
	}

	else if(c == 8)
	{
		cout << "For further info & more museums, visit xyz.org" << endl;
	}

	else {
		optionsStudent();
		return;
	}

	cout << endl << "Do you want to view more museums? " << endl;
    cout << "For YES press 1, else press 2 " << endl;

    int p;
	cout << endl << "Enter Option : ";
	cin >> p;

	if(p == 1)
	{
       museums(1);
       return;
	}

	else
	{
		if(a == 1)
		    optionsStudent();

	    if(a == 2)
	    	optionsWork();

	    if(a == 3)
	    	optionsTourist();

		return;
	}

}


void historicalPlaces(int a) {

	timeDelay();

	gotoxy(col/2-13,3);cout << "HISTORICAL PLACES IN DELHI" << endl;
	cout << endl << "Select to view details - ";

	cout << endl << "1. Red Fort" << endl;
	cout << "2. Humanyun's Tomb" << endl;
	cout << "3. Qutub Minar" << endl;
	cout << "4. India Gate" << endl;
	cout << "5. Jama Masjid" << endl;
	cout << "6. Hauz Khas Village" << endl;
	cout << "7. Tughlaqabad Fort" << endl;
	cout << "8. View more.." << endl;
	cout << "9. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;


	if(c == 1)
	{
		cout << "Red Fort" << endl << endl;

		cout << "The Red Fort was the official seat of Mughal rule and authority from 1648 onwards, when the 5th Mughal emperor, Shah Jahan, decided to move the capital of the empire from Agra to Delhi." << endl;
		cout << "Constructed using red sandstone, it remains one of the architectural marvels of the Mughal era. In 2007, it became a UNESCO World Heritage Site." << endl;
		cout << "Open Time: 7:00 AM - 5:30 PM, Except on Mondays" << endl;
		cout << "Time Required: 2-3 hours" << endl;
		cout << "Cost: Indian Citizens, citizens of SAARC and BIMSTEC nations: INR 10, Other foreigners: INR 250, No fees for children below the age of 15" << endl;

	}

	else if(c == 2)
	{
		cout << "Humanyun's Tomb" << endl << endl;

		cout << "Apart from being known for its stunning architecture, this is the first garden-tomb on the Indian subcontinent." << endl;
		cout << "It is a UNESCO World Heritage Site declared in 1993, and has undergone widespread restoration work since then. The tomb was custom-built by Humayun's son Akbar during 1569-70." << endl;
		cout << "Open Time: 10:00 AM - 06:00 PM" << endl;
		cout << "Cost: Indians - INR 10, Foreigners - INR 250. Video filming - INR 25, Photography - Free" << endl;

	}

	else if(c == 3)
	{
		cout << "Qutub Minar" << endl << endl;

		cout << "The soaring and brave tower that allures tourists despite being destroyed by ravages of natural apocalypses several times, Qutub Minar is the tallest individual tower in the world and second tallest monument of Delhi. " << endl;
		cout << "A UNESCO World Heritage Site, it is located in Mehrauli and its construction was started in 1192 by Qutb Ud-Din-Aibak, founder of Delhi Sultanate." << endl;
		cout << "Open Time: 10:00 AM - 5:00 PM" << endl;
		cout << "Cost: Indians: INR 10, Foreign tourists: INR 250" << endl;
		cout << "Time Required: 2 to 3 hours" << endl;

	}

	else if(c == 4)
	{
		cout << "India Gate" << endl << endl;

		cout << "The All India War Memorial, popularly known as the India Gate, is a war memorial located in New Delhi." << endl;
		cout << "It is dedicated to the 82,000 soldiers, both Indian and British, who died during the First World War and the Third Anglo-Afghan War. " << endl;
		cout << "The Amar Jawan Jyoti is the burning structure, right underneath the archway, which symbolizes the eternal, immortal soldiers of India." << endl;
		cout << "No Ticket needed." << endl;

	}

	else if(c == 5)
	{
		cout << "Jama Masjid" << endl;
	}

	else if(c == 6)
	{
		cout << "Hauz Khas Village" << endl;
	}

	else if(c == 7)
	{
		cout << "Tughlaqabad Fort" << endl;

	}

    else if(c == 8)
	{
		cout << "For further info & more museums, visit xyz.org" << endl;
	}

	else {
		optionsStudent();
		return;
	}

	cout << endl << "Do you want to view more historical places? " << endl;
    cout << "For YES press 1, else press 2 " << endl;

    int p;
	cout << endl << "Enter Option : ";
	cin >> p;

	if(p == 1)
	{
       historicalPlaces(1);
       return;
	}

	else
	{
		if(a == 1)
		    optionsStudent();

	    if(a == 2)
	    	optionsWork();

	    if(a == 3)
	    	optionsTourist();

	    return;
	}

}

void markets(int a) {

	timeDelay();

	gotoxy(col/2-13,3);cout << "FAMOUS MARKETS IN DELHI" << endl;
	cout << endl << "Select to view details - ";

	cout << endl << "1. Janpath and Tibetan Market" << endl;
	cout << "2. Dilli Haat" << endl;
	cout << "3. Paharganj" << endl;
	cout << "4. Chandni Chowk" << endl;
	cout << "5. Sarojini Nagar" << endl;
	cout << "6. Khan Market" << endl;
	cout << "7. Connaught Place" << endl;
	cout << "8. View more.." << endl;
	cout << "9. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

    if(c == 1)
    {
    	cout << "Janpath and Tibetan Market" << endl << endl;

    	cout << "Location: Janpath, just off Connaught Place, in New Delhi" << endl;
    	cout << "Opening Hours: Daily except Sundays" << endl;
    	cout << "What to Buy: Handicrafts, hippy clothing, shoes, paintings, brassware, Indian artifacts, leather work, fragrances, and cheap jewelry" << endl;

    }

    else if(c == 2)
    {
    	cout << "Dilli Haat" << endl << endl;

    	cout << "Location: Opposite INA Market, South Delhi" << endl;
    	cout << "Opening Hours: Daily from 10.30 a.m. to 10 p.m., including national holidays" << endl;
    	cout << "What to Buy: Indian handcrafts and artifacts." << endl;

    }

    else if(c == 3)
    {
    	cout << "" << endl;
    }

    else if(c == 4)
    {
    	cout << "" << endl;
    }

    else if(c == 5)
    {
    	cout << "" << endl;
    }

    else if(c == 6)
    {
    	cout << "" << endl;
    }

    else if(c == 7)
    {
    	cout << "" << endl;
    }

    else if(c == 8)
	{
		cout << "For further info & more markets, visit xyz.org" << endl;
	}

	else {
		optionsStudent();
		return;
	}

	cout << endl << "Do you want to view more markets? " << endl;
    cout << "For YES press 1, else press 2 " << endl;

    int p;
	cout << endl << "Enter Option : ";
	cin >> p;

	if(p == 1)
	{
       markets(1);
       return;
	}

	else
	{
		if(a == 1)
		    optionsStudent();

	    if(a == 2)
	    	optionsWork();

	    if(a == 3)
	    	optionsTourist();

		return;
	}

}

void jobsList() {
	timeDelay();

	gotoxy(col/2-13,3);cout << "JOBS AVAILABLE - DELHI" << endl;
	cout << endl << "Select to view details - ";

	cout << endl << "1. WEB DEVELOPER, ABC CORP." << endl;
	cout << "2. SALES, SUPER STORES" << endl;
	cout << "3. HR, URBAN CLAP" << endl;
	cout << "4. HR, ORACLE" << endl;
	cout << "5. SDE, GOOGLE INDIA" << endl;
	cout << "6. SALES, PCJ JEWELLERS" << endl;
	cout << "7. MARKETTING, RAM SHYAM & SONS" << endl;
	cout << "8. View more.." << endl;
	cout << "9. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

	if(c == 1)
	{
	cout << "WEB DEVELOPER, ABC CORP." << endl << endl;

	cout << "Job Description - Required a experienced web developer to build the company website and look into daily activities." << endl;

	cout << "Location - Delhi" << endl;
	cout << "Contact - contact@abc.com | 9235461889" << endl;

	cout << "APPLY AT - abcapplication.in" << endl;

	}

	else if(c == 2)
	{
	  cout << "SALES, URBAN CLAP" << endl << endl;

	cout << "Job Description - Required a sales expert to look into daily sales & improve the company retail product sales." << endl;

    cout << "Females preferable" << endl;
	cout << "Location - Delhi" << endl;
	cout << "Contact - contact@abc.com | 9235461889" << endl;

	cout << "APPLY AT - jobs.in/urbanClap" << endl;

	}

	else if(c == 3)
	{
	cout << "3. HR, URBAN CLAP" << endl;
	}

	else if(c == 4)
	{
	cout << "4. HR, ORACLE" << endl;

	}

	else if(c == 5)
	{
	cout << "5. SDE, GOOGLE INDIA" << endl;

	}

	else if(c == 6)
	{
	cout << "6. SALES, PCJ JEWELLERS" << endl;
	}

	else if(c == 7)
	{
	cout << "7. MARKETTING, RAM SHYAM & SONS" << endl;

	}


    else if(c == 8)
	{
		cout << "For further info & more jobs, visit xyz.org" << endl;
	}

	else {
		optionsWork();
		return;
	}

    cout << endl << "Do you want to view more jobs? " << endl;
    cout << "For YES press 1, else press 2 " << endl;

    int p;
	cout << endl << "Enter Option : ";
	cin >> p;

	if(p == 1)
	{
       jobsList();
       return;
	}

    else {
    	optionsWork();
    }

}


void businessListings() {

	timeDelay();

	gotoxy(col/2-13,3);cout << "BUSINESS LISTINGS - DELHI" << endl;
	cout << endl << "Select to view details - ";

	cout << endl << "1. ARORA PROPERTIES" << endl;
	cout << "2. AGGARWAL SWEETS" << endl;
	cout << "3. ROYAL HARDWARE SHOP" << endl;
	cout << "4. GUPTA FURNITURES" << endl;
	cout << "5. URBAN SALES CORP." << endl;
	cout << "6. PCJ JEWELLERS" << endl;
	cout << "7. RAM SHYAM & SONS" << endl;
	cout << "8. View more.." << endl;
	cout << "9. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

	if(c == 1)
	{
	cout << "ARORA PROPERTIES" << endl << endl;

	cout << "Address - A2/3 New Friends Colony, Delhi" << endl;
	cout << "Contact - 9235461879 , 9235461889" << endl;

	}

	else if(c == 2)
	{
	  cout << "2. AGGARWAL SWEETS" << endl;
	}

	else if(c == 3)
	{
	cout << "3. ROYAL HARDWARE SHOP" << endl;
	}

	else if(c == 4)
	{
	cout << "4. GUPTA FURNITURES" << endl;
	}

	else if(c == 5)
	{
	cout << "5. URBAN SALES CORP." << endl;
	}

	else if(c == 6)
	{
	cout << "6. PCJ JEWELLERS" << endl;
	}

	else if(c == 7)
	{
	cout << "7. RAM SHYAM & SONS" << endl;
	}


    else if(c == 8)
	{
		cout << "For further info & more local businesses, visit xyz.org" << endl;
	}

	else {
		optionsWork();
		return;
	}

    cout << endl << "Do you want to view more businesses? " << endl;
    cout << "For YES press 1, else press 2 " << endl;

    int p;
	cout << endl << "Enter Option : ";
	cin >> p;

	if(p == 1)
	{
       businessListings();
       return;
	}

    else {
    	optionsWork();
    }

}

void companyHQ () {
	timeDelay();


    gotoxy(col/2-13,3);cout << "COMPANY HEADQUARTERS & MAJOR OFFICES IN DELHI" << endl;
	//cout << endl << "Select to view details - ";

	cout << endl << "1. GOOGLE INDIA HQ" << endl;
	cout << "2. MICROSOFT INDIA HQ" << endl;
	cout << "3. SAMSUNG INDIA HQ" << endl;
	cout << "4. TATA HEADQUARTERS" << endl;
	cout << "5. RELIANCE JIO BRANCH OFFICE" << endl;
	cout << "6. AMAZON INDIA REGIONAL OFFICE" << endl;
	cout << "7. AIR INDIA HQ" << endl << endl;

	cout << "#1. To view more.." << endl;
	cout << "#2. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

    if(c == 1)
    {
    	companyHQ();
    	return;
    }

    else
    {
    	optionsWork();
    }

}


void localMarkets() {

	timeDelay();
	gotoxy(col/2-13,3);cout << "LOCAL MARKETS IN DELHI" << endl;
	//cout << endl << "Select to view details - ";

	cout << endl << "1. SAROJINI NAGAR MARKET - clothes" << endl;
	cout << "2. LAJPAT NAGAR - clothes & jewelry" << endl;
	cout << "3. KAMALA NAGAR" << endl;
	cout << "4. CONNAUGHT PLACE - clothes, cafes, hangout" << endl;
	cout << "5. CHANDNI CHOWK - everything!" << endl;
	cout << "6. KHAN MARKET - brand stores" << endl;
	cout << "7. NEHRU PLACE - IT, electronics" << endl << endl;

	cout << "#1. To view more.." << endl;
	cout << "#2. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

    if(c == 1)
    {
    	localMarkets();
    	return;
    }

    else
    {
    	optionsWork();
    }
}

void hotels() {

	timeDelay();
	gotoxy(col/2-13,3);cout << "HOTELS TO STAY IN DELHI" << endl;
	//cout << endl << "Select to view details - ";

	cout << endl << "1. THE TAJ" << endl;
	cout << "2. RADISSON BLU" << endl;
	cout << "3. THE LEELA" << endl;
	cout << "4. LE MERIDIEN" << endl;
	cout << "5. MARRIOT" << endl;
	cout << "6. ITC MAURYA" << endl;
	cout << "7. ASHOKA HOTEL" << endl << endl;

	cout << "FINE-DINE RESTAURANTS IN DELHI" << endl;
	//cout << endl << "Select to view details - ";

	cout << endl << "1. INDIAN ACCENT" << endl;
	cout << "2. DUM-PUKTH, ITC MAURYA" << endl;
	cout << "3. SEVILLA - THE CLARIDGES" << endl;
	cout << "4. BUKHARA - ITC MAURYA" << endl;
	cout << "5. K3 - JW MARRIOT" << endl;
	cout << "6. KIYAN - THE ROSEATE" << endl;
	cout << "7. HONK" << endl << endl;

	cout << "#1. To view more.." << endl;
	cout << "#2. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

    if(c == 1)
    {
    	hotels();
    	return;
    }

    else
    {
    	optionsTourist();
    }
}


void funActivities() {
	timeDelay();
	gotoxy(col/2-13,3);cout << "FUN ACTIVITIES TO DO IN DELHI" << endl;
	//cout << endl << "Select to view details - ";

    cout << endl << "1. Visit the Lotus Temple for Inner Peace" << endl;
	cout << "2. Pay a Visit to Akshardham Temple" << endl;
	cout << "3. Delhi Sightseeing Tour | Book Online @ ₹385" << endl;
	cout << "4. Taste the Delicacies at Paranthe Wali Gali" << endl;
	cout << "5. Visit the Fairs at Pragati Maidan" << endl;
	cout << "6. Paintball in Delhi | Book Online & Get Flat 12% off" << endl;
	cout << "7. Adventure Island Delhi Tickets | Book Online for 30% off" << endl << endl;


	cout << "#1. To view more.." << endl;
	cout << "#2. Go back" << endl;

    int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

    if(c == 1)
    {
    	funActivities();
    	return;
    }

    else
    {
    	optionsTourist();
    }
}


void bookTickets() {

	timeDelay();
	gotoxy(col/2-13,3);cout << "WELCOME TO TICKET BOOKING PLATFORM" << endl;
	//cout << endl << "Select to view details - ";

    cout << endl << "1. Search Railway Tickets" << endl;
	cout << "2. Search Bus Tickets" << endl;
	cout << "3. Search Air Tickets" << endl << endl;

	cout << "4. Go back to options" << endl;
	int c;
	cout << endl << "Enter Option : ";
	cin >> c;

	cout << endl << endl;

	if(c == 1)
	{
		timeDelay();
		string name, d, date, phone;
		gotoxy(col/2-13,3);cout << "WELCOME TO RAILWAY TICKET BOOKING" << endl;

		cout << endl << "Enter Your Name - ";
		cin >> name;

		cout << endl << "Enter Destination - ";
		cin >> d;

		cout << endl << "Enter Journey Date (dd-mm-yy) - ";
		cin >> date;

		cout << endl << "Enter contact no. - ";
		cin >> phone;

		cout << endl << "Thanks for searching Mr/Mrs/Ms " << name << "!"  << endl <<
		"AVAILABLE TRAIN details have been sent to " << phone << endl;

	}

	else if(c == 2)
	{
		timeDelay();
		string name, d, date, phone;
		gotoxy(col/2-13,3);cout << "WELCOME TO BUS TICKET BOOKING" << endl;

		cout << endl << "Enter Your Name - ";
		cin >> name;

		cout << endl << "Enter Destination - ";
		cin >> d;

		cout << endl << "Enter Journey Date (dd-mm-yy) - ";
		cin >> date;

		cout << endl << "Enter contact no. - ";
		cin >> phone;

		cout << endl << "Thanks for searching Mr/Mrs/Ms " << name << "!" << endl <<
		"AVAILABLE BUS details have been sent to " << phone << endl;

	}

	else if(c == 3)
	{
		timeDelay();
		string name, d, date, phone;
		gotoxy(col/2-13,3);cout << "WELCOME TO FLIGHT TICKET BOOKING" << endl;

		cout << endl << "Enter Your Name - ";
		cin >> name;

		cout << endl << "Enter Destination - ";
		cin >> d;

		cout << endl << "Enter Journey Date (dd-mm-yy) - ";
		cin >> date;

		cout << endl << "Enter contact no. - ";
		cin >> phone;

		cout << endl << "Thanks for searching Mr/Mrs/Ms " << name << "!" << endl <<
		"AVAILABLE FLIGHT details have been sent to " << phone << endl;

	}

	else
	{
		optionsTourist();
		return;
	}

    cout << endl << "Do you want to check more tickets? " << endl;
    cout << "For YES press 1, else press 2 " << endl;

    int p;
	cout << endl << "Enter Option : ";
	cin >> p;

	if(p == 1)
	{
       bookTickets();
       return;
	}

    else {
    	optionsTourist();
    }


}



/* --------------- MENUS FOR DIFFERENT ACCESS MODES --------------- */

//options for STUDENT MODE
void optionsStudent() {
	//system("cls");
	timeDelay();
	headingText();
	border(9,0);
	gotoxy(col/2-13, row/2-5);std::cout << "STUDENT LOGIN";


	gotoxy(col/2-13,row/2-1);cout << "OPTIONS" ;
	gotoxy(col/2-13,row/2-0);cout << "1. Schools" ;
	gotoxy(col/2-13,row/2+1);cout << "2. Colleges & Universities";
	gotoxy(col/2-13,row/2+2);cout << "3. Museums" ;
	gotoxy(col/2-13,row/2+3);cout << "4. Historical Places";
	gotoxy(col/2-13,row/2+4);cout << "5. Famous Markets";
	gotoxy(col/2-13,row/2+5);cout << "6. LOG-OUT" ;

	int c;
	gotoxy(col/2-13,row/2+6);cout << "Enter Option : ";
	cin >> c;

	if(c == 1){
		//call schools info. function
		schools();
	}

	else if(c == 2){
        //colleges
        colleges();
	}

	else if(c == 3){
        //museums
        museums(1);
	}

	else if(c == 4){
        //historical places
        historicalPlaces(1);
	}

	else if(c == 5){
        //markets
        markets(1);
	}

	else if(c == 6){
        //log-out
        gotoxy(col/2-13,col/2+9);cout << "LOGGING OUT.." << endl;
        home();
	}
}


//options for WORK MODE
void optionsWork() {
	//system("cls");
	timeDelay();
	headingText();
	border(9,0);

	gotoxy(col/2-13, row/2-5);cout << "WORK LOGIN";

	gotoxy(col/2-13,row/2-1);cout << "OPTIONS";
	gotoxy(col/2-13,row/2-0);cout << "1. View Business Listings"  ;
	gotoxy(col/2-13,row/2+1);cout << "2. Jobs Available"  ;
	gotoxy(col/2-13,row/2+2);cout << "3. Famous Markets"  ;
	gotoxy(col/2-13,row/2+3);cout << "4. Company Headquarters and Offices in Delhi"  ;
	gotoxy(col/2-13,row/2+4);cout << "5. Local Markets"  ;
	gotoxy(col/2-13,row/2+5);cout << "6. View Live Stock (to be available soon)"  ;
	gotoxy(col/2-13,row/2+6);cout << "7. LOG-OUT"  ;

	int c;
	gotoxy(col/2-13,row/2+7);cout<< "Enter Option : ";
	cin >> c;

	if(c == 1){
		//business listings
		businessListings();
	}

	else if(c == 2){
        //jobs
        jobsList();
	}

	else if(c == 3){
        //markets
        markets(2);
	}

	else if(c == 4){
        //offices
        companyHQ();
	}

	else if(c == 5){
        //local markets
        localMarkets();
	}

	else if(c == 6){
        //list jobs

        cout << "COMING SOON!" << endl;
        optionsWork();
	}

	else if(c == 7){
        //log-out
        cout << "LOGGING OUT.." << endl;
        home();
	}

}


//options for TOURIST MODE
void optionsTourist() {
    //system("cls");

    timeDelay();
		headingText();
		border(9,0);

		gotoxy(col/2-13, row/2-5);std::cout << "TOURIST LOGIN";


	gotoxy(col/2-13,row/2-1);cout << "OPTIONS"  ;
	gotoxy(col/2-13,row/2-0);cout << "1. Historical Places"  ;
	gotoxy(col/2-13,row/2+1);cout << "2. Museums"  ;
	gotoxy(col/2-13,row/2+2);cout << "3. Markets"  ;
	gotoxy(col/2-13,row/2+3);cout << "4. Hotels & Restaurants"  ;
	gotoxy(col/2-13,row/2+4);cout << "5. Adventures & Fun activities"  ;
	gotoxy(col/2-13,row/2+5);cout << "6. Book Tickets - Rail/ Road/ Air"  ;
	gotoxy(col/2-13,row/2+6);cout << "7. City Map"  ;
	gotoxy(col/2-13,row/2+7);cout << "8. LOG-OUT"  ;

	int c;
	gotoxy(col/2-13,row/2+8);cout  << "Enter Option : ";
	cin >> c;

	if(c == 1){
		//historical places
		historicalPlaces(3);
	}

	else if(c == 2){
        //museums
        museums(3);
	}

	else if(c == 3){
        //markets
        markets(3);
	}

	else if(c == 4){
        //hotels & rests.
        hotels();
	}

	else if(c == 5){
        //fun activities
        funActivities();
	}

	else if(c == 6){
        //book tickets
        bookTickets();
	}

	else if(c == 7){
        //map
        gotoxy(col/2-13,col/2+9);cout << "Delhi Map - COMING SOON! " <<endl;
        optionsTourist();
	}

	else if(c == 8){
        //log-out
        cout << "LOGGING OUT.." << endl;
        home();
	}

}


/* --------------- function to verify email & password --------------- */


bool searchMail(string mail, string pass, char userType){

  if(userType == 'S')
  {
  	for(int i = 0; i < student.size(); i++)
  	{
  		if(student[i].email == mail && student[i].password == pass)
  		{
  			return true;
  		}
  	}

  	return false;
  }

  if(userType == 'W')
  {
  	for(int i = 0; i < work.size(); i++)
  	{
  		if(work[i].email == mail && work[i].password == pass)
  		{
  			return true;
  		}
  	}

  	return false;
  }

  if(userType == 'T')
  {
  	for(int i = 0; i < tourist.size(); i++)
  	{
  		if(tourist[i].email == mail && tourist[i].password == pass)
  		{
  			return true;
  		}
  	}

  	return false;
  }

  return false;
}


/* --------------- HOME PAGE FUNCTIONS --------------- */


//Log-In Function
void logIn()
{
	//system("cls");

    timeDelay();
		headingText();
		border(9,0);

	gotoxy(col/2-13,row/2-5);cout << "LOG-IN" ;

	gotoxy(col/2-13,row/2-1);cout << "Choose USER type - ";
	gotoxy(col/2-13,row/2+0);cout << "1. STUDENT";
	gotoxy(col/2-13,row/2+1);cout << "2. WORK" ;
	gotoxy(col/2-13,row/2+2);cout << "3. TOURIST";
	gotoxy(col/2-13,row/2+3);cout << "4. RETURN TO HOME PAGE";

	int c;
	gotoxy(col/2-13,row/2+5);cout << "Enter Option : ";
	cin >> c;

	if(c == 4)
	{
		home();
		return;
	}

	if(c == 1)
	{
	  string mail;
	  gotoxy(col/2-13,row/2+7);cout << "Enter email : ";
	  cin >> mail;

	  //string pass;
	  gotoxy(col/2-13,row/2+8);cout << "Enter password : ";
	  //cin >> pass;

	  string pass ="";
      char ch;
      ch = _getch();

      while(ch != 13){
      //character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();

      }

      cout << endl;

	  if(searchMail(mail, pass, 'S'))
	  {
	 	gotoxy(col/2-13,row/2+10);cout << "LOG-IN SUCCESSFULL!";

	 	optionsStudent();
	  }

	  else {
		gotoxy(col/2-13,row/2+10);cout << "INVALID E-MAIL ADDRESS! PLEASE SIGN-UP";
		signUp();
	  }
	}

	else if(c == 2)
	{
      string mail;
	  gotoxy(col/2-13,row/2+7);cout << "Enter email : ";
	  cin >> mail;

	  //string pass;
	  gotoxy(col/2-13,row/2+8);cout << "Enter password : ";
	  string pass ="";
      char ch;
      ch = _getch();

      while(ch != 13){
      //character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();

      }

	  if(searchMail(mail, pass, 'W'))
	  {
	 	gotoxy(col/2-13,row/2+10);cout << "LOG-IN SUCCESSFULL!" ;

	 	optionsWork();
	  }

	  else {
		gotoxy(col/2-13,row/2+10);cout << "INVALID E-MAIL ADDRESS! PLEASE SIGN-UP";
		signUp();
	  }
	}

	else if(c == 3)
	{
      string mail;
	  gotoxy(col/2-13,row/2+7);cout << "Enter email : ";
	  cin >> mail;

	  //string pass = "";
	  gotoxy(col/2-13,row/2+8);cout << "Enter password : ";
	  string pass ="";
      char ch;
      ch = _getch();

      while(ch != 13){
      //character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();

      }

	  if(searchMail(mail, pass, 'T'))
	  {
	 	gotoxy(col/2-13,row/2+10);cout << "LOG-IN SUCCESSFULL!";

	 	optionsTourist();
	  }

	  else {
		gotoxy(col/2-13,row/2+10);cout << "INVALID E-MAIL ADDRESS! PLEASE SIGN-UP";
		signUp();
	  }
	}

	else
	{
		gotoxy(col/2-13,row/2+7);cout << "INVALID!";
		gotoxy(col/2-15,row/2+8);cout << "TRY AGAIN!!!";
		logIn();
		return;
	}


}



//Sign-Up Function
void signUp()
{
	//system("cls");
	timeDelay();
	headingText();
	border(9,0);

	gotoxy(col/2-13,row/2-5);cout << "SIGN-UP" ;

	gotoxy(col/2-13,row/2-1);cout << "Choose USER type - ";
	gotoxy(col/2-13,row/2+0);cout << "1. STUDENT";
	gotoxy(col/2-13,row/2+1);cout << "2. WORK";
	gotoxy(col/2-13,row/2+2);cout << "3. TOURIST";
	gotoxy(col/2-13,row/2+3);cout << "4. RETURN TO HOME PAGE";

	int c;
	gotoxy(col/2-13,row/2+5);cout << "Enter Option : ";
	cin >> c;

	if(c == 4)
	{
		home();
		return;
	}

	  string name;
		int id;
		string email;


	if(c == 1)
	{
		timeDelay();
		//system("cls");
		headingText();
		border(9,0);
		gotoxy(col/2-13,row/2-1);cout << "Enter Name : ";
		cin >> name;

		gotoxy(col/2-13,row/2+0);cout << "Enter ID : ";
		cin >> id;

		gotoxy(col/2-13,row/2+1);cout << "Enter E-mail : ";
		cin >> email;
		STUDENT s1(name, id, email);
		student.push_back(s1);
		gotoxy(col/2-13,row/2+5);cout << "SIGNED UP SUCCESSFULLY! PLEASE LOG-IN TO ACCESS." << endl;
		logIn();
	}

	else if(c == 2)
	{
		timeDelay();
		headingText();
		border(9,0);
		gotoxy(col/2-13,row/2-1);cout << "Enter Name : ";
		cin >> name;

		gotoxy(col/2-13,row/2+0);cout << "Enter ID : ";
		cin >> id;

		gotoxy(col/2-13,row/2+1);cout << "Enter E-mail : ";
		cin >> email;
        WORK w1(name, id, email);
        work.push_back(w1);
        gotoxy(col/2-13,row/2+5);cout << "SIGNED UP SUCCESSFULLY! PLEASE LOG-IN TO ACCESS." << endl;
		logIn();
	}

	else if(c == 3)
	{
		timeDelay();
		headingText();
		border(9,0);
		gotoxy(col/2-13,row/2-1);cout << "Enter Name : ";
		cin >> name;

		gotoxy(col/2-13,row/2+0);cout << "Enter ID : ";
		cin >> id;

		gotoxy(col/2-13,row/2+1);cout << "Enter E-mail : ";
		cin >> email;

        TOURIST t1(name, id, email);
        tourist.push_back(t1);
        gotoxy(col/2-13,row/2+5);cout << "SIGNED UP SUCCESSFULLY! PLEASE LOG-IN TO ACCESS." << endl;
		logIn();
	}

	else
	{
		cout << "INVALID!" << endl;
		return;
	}

}


//About Us
void aboutUs() {

	timeDelay();

	cout << "ABOUT US" << endl << endl;

	cout << "Smart City System - is an innovative project developed by RIDHAM JAIN & RISHABH BAFNA." << endl << endl
	     << "There is an evident problem faced by people who are new to a city and even for the residents, " << endl
	     << "in most cases people cannot find guides and often find themselves lost and confused. " << endl
	     << "Our project aims to work upon this real-life problem and provide the important details, be it " << endl
	     << "about the places to go, hotels, markets, schools, colleges, jobs in a city, major company HQs, " << endl
	     << "getting ticket info and much more. "<< endl << endl
	     << "The system can be accessed by the USER in 3 different modes - WORK, STUDENT & TOURIST." << endl
	     << "In all the 3 modes, the user will be able to retrieve various information from the system " << endl
	     << "which not only helps the user in a new city but also saves time and money." << endl
	     << "This is just the beginning and further updates can be made in the system with a GUI & more pictures" << endl
	     << "and maps of the city." << endl << endl;

	cout << "The project uses various programming techniques. It is completely built in C++ using VS Code & Sublime " << endl
	     << "as text editors and the GNU C++ compiler. The project mainly focuses on using the OBJECT ORIENTED PROGRAMMING " << endl
	     << "techniques and uses its various features such as CLASSES & OBJECTS, ABSTRACTION & ENCAPSULATION, INHERITENCE, " << endl
	     << "and POLYMORPHISM. The project also includes various other features like using VIRTUAL FUNCTIONS & FRIEND FUNCTIONS" << endl << endl;

    cout << "The project is made jointly by RIDHAM JAIN (2K19/SE/093) and RISHABH BAFNA(2K19/SE/095) for the subject " << endl
         << "Object Oriented Programming taught by Mr. MANOJ SETHI (Dept. of Computer Science & Engineering)." << endl << endl;

    cout << "THANKYOU." << endl;

    cout << "Press 1 to go back : ";
    int n;
    cin >> n;

    if(n == 1)
    {
    	home();
    }

    else
    {
    	home();
    }


}

void admin();

//admin Log-In SignUp
void adminLogIn()
{
	timeDelay();

	headingText();
	border(9,0);

	gotoxy(col/2-13,row/2-5);cout << "WELCOME TO ADMIN MODE";

	gotoxy(col/2-26,row/2-4);cout << "FOR ACCESSING THE SYSTEM, ENTER USERNAME & PASSWORD - ";
    ADMIN a;
    string user, pass;

    gotoxy(col/2-13,row/2-1);cout << "Enter username : " ;
    cin >> user;

    gotoxy(col/2-13,row/2-0);cout << "Enter password : ";
    cin >> pass;

    if(user == a.name && pass == a.password)
    {
    	gotoxy(col/2-13,row/2+1);cout << "LOGGING-IN..";
    	admin();
    }

    else {
    	gotoxy(col/2-13,row/2+1);cout << "INCORRECT USERNAME & PASSWORD! TRY AGAIN";

    	home();

    }

}

//function to access Admin mode
void admin() {

    timeDelay();
		headingText();
		border(9,0);
	gotoxy(col/2-13,row/2-5);cout << "WELCOME TO ADMIN MODE";

	gotoxy(col/2-13,row/2-3);cout << "MENU - ";

	gotoxy(col/2-13,row/2-2);cout << "#1. Check DATABASE ";
	gotoxy(col/2-13,row/2-1);cout << "#2. Check Uploaded Information ";
	gotoxy(col/2-13,row/2-0);cout << "#3. About the Developers";
	gotoxy(col/2-13,row/2+1);cout << "#4. Check User's (STUDENT) Data ";
	gotoxy(col/2-13,row/2+2);cout << "#5. Check User's (WORK) Data ";
	gotoxy(col/2-13,row/2+3);cout << "#6. Check User's (TOURIST) Data ";
	gotoxy(col/2-13,row/2+4);cout << "#7. Exit ADMIN Mode";

	gotoxy(col/2-13,row/2+5);cout << "Enter option :: ";

	int n;
	cin >> n;

	if(n == 1)
	{
	gotoxy(col/2-13,row/2+7);	cout << "DATA TO BE UPLOADED SOON!";

		admin();
	}

	else if(n == 2)
	{
		timeDelay();
		headingText();
		border(9,0);

		gotoxy(col/2-13,row/2-1);cout << "1. DATA FOR STUDENTS";
		gotoxy(col/2-13,row/2-0);cout << "2. DATA FOR WORK";
		gotoxy(col/2-13,row/2+1);cout << "3. DATA FOR TOURISTS";
		gotoxy(col/2-13,row/2+2);cout << "4. Back To Menu";

		int p;

		gotoxy(col/2-13,row/2+4);cout << "Enter option :: ";
	    cin >> p;

        if(p == 1)
        	optionsStudent();

        else if(p == 2)
        	optionsWork();

        else if(p == 3)
        	optionsTourist();

        else
        	admin();


	}

	else if(n == 3)
	{
		aboutUs();
	}

    else if(n == 7)
    {
    	gotoxy(col/2-13,row/2+7);cout << "LOGGING OUT.." << endl;

    	home();
    }

    else {

    	gotoxy(col/2-13,row/2+7);cout << "DATA CURRENTLY NOT-AVAILABLE!" << endl;
    	admin();
    }


}


//Home Screen

void home() {

	system("cls");
	headingText();
	border(9,1);
	    //timeDelay();

	gotoxy(col/2-15,10);cout << "WELCOME TO SMART CITY - DELHI" ;

	gotoxy(col/2-13,row/2-1);cout << "1. LOG-IN";
	gotoxy(col/2-13,row/2);cout << "2. SIGN-UP";
	gotoxy(col/2-13,row/2+1);cout << "3. ABOUT";
	gotoxy(col/2-13,row/2+2);cout << "4. ADMIN MODE";
	gotoxy(col/2-13,row/2+3);cout << "5. EXIT";


	int c;
	gotoxy(col/2-13,row/2+5);cout << "Enter Option : ";
	cin >> c;

	if(c == 1)
	{
	logIn();
	}

	else if(c == 2)
	{
	signUp();
	}

	else if(c == 3)
	{
	aboutUs();
	}

	else if(c == 4)
	{
	adminLogIn();
	}

	else {
		system("cls");
		headingText();
		border(9,0);
	gotoxy(col/2-13,row/2);cout << "Have a nice day! See you soon.";
	gotoxy(0,row);
	return;
	}
}


// MAIN FUNCTION

int main()
{
		Maximize();
		GetScreenSize(row,col);
    home();

}
