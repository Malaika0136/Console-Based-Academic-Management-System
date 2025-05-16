#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <ctime>
using namespace std; 

class User{
	string id;
	string password;
	char c;
	public:
	User(){
		string password = "0aA,bB,cC"; 
	}		
	bool is_valid_password(string pass) {
	    bool has_uppercase = false;
	    bool has_lowercase = false;
	    bool has_digit = false;
	    bool has_special_char = false;
	    
	    // Check length
	    if (pass.length() < 6) {
	        return false;
	    }
	    
	    // Check if it contains uppercase letters, lowercase letters, digits, and special characters
	    for (int i = 0; i < pass.length(); i++) {
	        char c = pass[i];
	        if (isupper(c)) {
	            has_uppercase = true;
	        } else if (islower(c)) {
	            has_lowercase = true;
	        } else if (isdigit(c)) {
	            has_digit = true;
	        } else if (ispunct(c)) {
	            has_special_char = true;
	        }
	    }
	    
	    // Return true only if all criteria are met
	    return has_uppercase && has_lowercase && has_digit && has_special_char;
		}
	bool checkpassword(string pass1){
		is_valid_password(pass1);
	}
};

class Teacher: public User{
protected: 
			string CourseName;
			int i;
			int iteration;
			int courseNo;
			int size;
		
			bool valid;
			bool check;
			string id;
			string name;
	public:
		Teacher(){
			iteration=0;
			courseNo=0;
			size=0;	
			 valid=false;
			 check=false;
		}
		int checkname(char* arr, int length1){
			string id(arr,length1);
		    // Open the CSV file
		    ifstream infile("teachers.csv");
		    if (!infile)
		    {
		        cout << "File cannot be opened";
		        return 1;
		    }
		
		    // Read each line of the CSV file
		    string line;
		    while (getline(infile, line))
		    {
		        string token;
		        istringstream ss(line);
				while (getline(ss, token, ','))
		        {		
		        	//cout<<"\n before comma print"<<endl;
		        	//cout << token << " ";
		            // Print the token to the console
		            if (token==id){
		            	check=true;
					//	cout<<"\n in loop"<<endl; 
		            //	cout << token << " ";        	
					}
				//	cout<<"\n after comma print"<<endl;
					if(check){
						iteration++;
						if(iteration==1){
							id=token;
						}
						else if(iteration==2){
							name=token;
						}
						else if(iteration==3){
							CourseName=token;
						}
					}
		        } 
		        if(check){
		        	break;
				} 
		    }
			    if(!check){
			    	cout<<"ID is not found"<<endl;
				}
			    else
				{
				cout<<"Name "<<id<<endl;
				cout<<"Course No "<<name<<endl;
				cout<<"Course Name "<<CourseName<<endl;
				
				}
			    // Close the CSV file
			    infile.close();
		
			    return 0;
		}
		
};

class Student: public User{
	protected:
			int i;
			int iteration;
			int courseNo;
			int size;
			int *course;
			bool valid;
			bool check;
			string id;
			string name;
	public:
		Student(){
			iteration=0;
			courseNo=0;
			size=0;	
			 valid=false;
			 check=false;
			course=new int[size];
		}
		int enterid(char* arr,int length1){
			string id(arr, length1);
			
			while(!valid){
				if (id.length() == 8 && id[0] == '2' && id[2] == 'I' && id[3] == '-' && isdigit(id[1]) && isdigit(id[4]) && isdigit(id[5]) && isdigit(id[6]))
					 {
		            valid = true; 
		       		 }
				else
					{
			            cout << "Invalid ID format. Please enter a valid ID in the format 2xI-xxxx." << endl;
			            cout<<"enter id ";
						getline(cin,id);
			        }
				
			}
			
		    // Open the CSV file
		    ifstream infile("students.csv");
		    if (!infile)
		    {
		        cout << "File cannot be opened";
		        return 1;
		    }
		
		    // Read each line of the CSV file
		    string line;
		    while (getline(infile, line))
		    {
		        string token;
		        istringstream ss(line);
				while (getline(ss, token, ','))
		        {		
		        	//cout<<"\n before comma print"<<endl;
		        	//cout << token << " ";
		            // Print the token to the console
		            if (token==id){
		            	check=true;
					//	cout<<"\n in loop"<<endl; 
		            //	cout << token << " ";        	
					}
				//	cout<<"\n after comma print"<<endl;
					if(check){
						iteration++;
						if(iteration==1){
							id=token;
						}
						else if(iteration==2){
							name=token;
						}
						if(token=="0" || token=="1"){
							courseNo++;
						
						if(token=="1"){
						
							course[size] = courseNo;
							size++;
						}
					
						}
					}
		        } 
		        if(check){
		        	break;
				} 
		    }
			    if(!check){
			    	cout<<"ID is not found"<<endl;
				}
			    else
				{
				cout<<"ID "<<id<<endl;
				cout<<"name "<<name<<endl;
				cout<<"course ";
				for(int i=0; i<size; i++){
					
					cout<<course[i]<<" ";
				}
				}
				
			    // Close the CSV file
			    infile.close();
			    delete course;
			    return 0;
		}
		
};

class Course: public Student{
	protected:
	bool check;
	int input;
	public:
		Course(){
			check=false;
		}
		void offeredCourses(){
			cout<<"";
		}
		void validCourse(){
				cout<<"Enter the course you want to attempt quiz for ";
				cin>>input;
					for(int i=0; i<size; i++){
						if(input==course[i]){
							check=true;
						}
					}
					
					while(!check){
						cout<<"!!!! You are not registered in this course !!!!"<<endl;
						cout<<"Enter the course you want to attempt quiz for ";
						cin>>input;
						for(int i=0; i<size; i++){
						if(input==course[i]){
							check=true;
						}
					}
					}	
				
				
			}
};


class Time {
protected:
    int hour, minute, second;

public:
    Time(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    bool isBetween(Time start, Time end) {
        time_t now = time(0);
        tm* currentTime = localtime(&now);

        int currentHour = currentTime->tm_hour;
        int currentMinute = currentTime->tm_min;
        int currentSecond = currentTime->tm_sec;

        if (currentHour < start.hour || currentHour > end.hour) {
            return false;
        } else if (currentHour == start.hour && currentMinute < start.minute) {
            return false;
        } else if (currentHour == end.hour && currentMinute > end.minute) {
            return false;
        } else if (currentHour == start.hour && currentMinute == start.minute && currentSecond < start.second) {
            return false;
        } else if (currentHour == end.hour && currentMinute == end.minute && currentSecond > end.second) {
            return false;
        }

        return true;
    }
};

class Date {
protected:
    int year, month, day;

public:
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    bool isBetween(Date start, Date end) {
        time_t now = time(0);
        tm* currentTime = localtime(&now);

        int currentYear = currentTime->tm_year + 1900;
        int currentMonth = currentTime->tm_mon + 1;
        int currentDay = currentTime->tm_mday;

        if (currentYear < start.year || currentYear > end.year) {
            return false;
        } else if (currentYear == start.year && currentMonth < start.month) {
            return false;
        } else if (currentYear == end.year && currentMonth > end.month) {
            return false;
        } else if (currentYear == start.year && currentMonth == start.month && currentDay < start.day) {
            return false;
        } else if (currentYear == end.year && currentMonth == end.month && currentDay > end.day) {
            return false;
        }

        return true;
    }
};


class Quiz: public Teacher, public Student, public Course{
	int iteration;
	string correct_ans;
	string inp;
	int o;
	float marks;
	public:
		Quiz(){
			iteration=0;
			marks=0;
	}
		attemptQuiz(){
			o= Course::input;
			if(Course::check){
					switch(o){
							case 1:
								{	
									ifstream infile("PF.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									    	break;
									//attemptpfQuiz(); //marks will also be saved sath sath, 
								}
							case 2:								{	
									ifstream infile("oop.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									    	break;
									//attemptpfQuiz(); //marks will also be saved sath sath, 
								}
							case 3:								{	
									ifstream infile("ITC.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									    	break;
									//attemptpfQuiz(); //marks will also be saved sath sath, 
								}
							case 4:								{	
									ifstream infile("DS.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									    	break;
									//attemptpfQuiz(); //marks will also be saved sath sath, 
								}
							case 5:								{	
									ifstream infile("AOA.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									    	break;
									//attemptpfQuiz(); //marks will also be saved sath sath, 
								}
							case 6:								{	
									ifstream infile("SRC.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									   	break; 
									//attemptpfQuiz(); //marks will also be saved sath sath, 
								}
							case 7:								{	
									ifstream infile("RM.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									break;	    
									//attemptpfQuiz(); //marks will also be saved sath sath, 
								}
							case 8:								{	
									ifstream infile("BDA.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									    	break;
									//attemptpfQuiz(); //marks will also be saved sath sath, 
								}
							case 9:								{	
									ifstream infile("AI.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									    	break;
									//attemptpfQuiz(); //marks will also be saved sath sath, 
								}
							case 10:								{	
									ifstream infile("DL.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									    
									//attemptpfQuiz(); //marks will also be saved sath sath, 
									break;
								} 
							case 11:								{	
									ifstream infile("DIP.txt");
								    if (!infile)
								    {
								        cout << "File cannot be opened";
								        return 1;
								    }
								
								    // Read each line of the CSV file
								    string line;
								    while (getline(infile, line))
								    {
								        string token;
								        istringstream ss(line);
										while (getline(ss, token, ','))
								        {		
								        		cout<<token<<endl;
												iteration++;
												if(iteration==6){
													correct_ans=token;
												}
												cin>>inp;
												if(inp==correct_ans){
													marks++;
												}												
											}
											cout<<endl;								         								       
								    }
						
									
										
									    infile.close();
									    
									//attemptpfQuiz(); //marks will also be saved sath sath, 
									break;
								}
							default: cout<<"Course not found"<<endl;
						
						}
				
			}
			
			
		}
		makeQuiz(){
			
		}
};

int main() 
{	
	int option;
	string id;
	int length=0;
	char c;
	char *chararray=new char[length];
	char ch;
    string password;
	cout<<"1. Login As teacher"<<endl;
	cout<<"2. Login As Student"<<endl;
	cin>>option;
	switch(option){
		
		case 1: {
			
			Teacher t;
			cout<<"Enter your login id ";
			cin>>chararray;
			while (c != '\n')  {
		        c = getchar();
		        if (c == '\n') {
		            break;
       				}
      			chararray[length++] = c;
  			  } 
			t.checkname(chararray,length);
			cout << "Enter Password: ";
		
		    // Read password character-by-character until Enter is pressed
		    while ((ch = _getch()) != '\r') { 
		        // Display asterisk on the console and store actual character in the password string
		        cout << "*";
		        password += ch;
		    }
			t.checkpassword(password);
			break;
		}
			
			
		case 2: {
			Student t;
			cout<<"Enter your login id ";
			
			while (c != '\n')  {
		        c = getchar();
		        if (c == '\n') {
		            break;
       				}
      			chararray[length++] = c;
  			  }
				t.enterid(chararray, length); 
			cout << "Enter Password: ";
		
		    // Read password character-by-character until Enter is pressed
		    while ((ch = _getch()) != '\r') { 
		        // Display asterisk on the console and store actual character in the password string
		        cout << "*";
		        password += ch;
		    }	
			t.checkpassword(password);		
			break;
		}
		
			
		default: cout<<"option must be 1 or 2";
	
 		}

	
	
    return 0;
}
