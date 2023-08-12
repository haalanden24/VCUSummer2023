#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/

int main(void) {

	
    ifstream infile;
    //ofstream outfile; //may need to change this to not hardcoded.
    //FILE *infile = NULL;
	//FILE *outfile = NULL;
	
    string infilename;
	string outfilename;
	//char infilename[256] = {0};
	//char outfilename[256] = {0};

	string last_name_buffer;
	string first_name_buffer;

	//char last_name_buffer[64];
	//char first_name_buffer[64];
	double balance;
	int account_no;

	// get input file name from the user - change to command line input
	while (true) {
    cout << "Input filename: ";
    cin >> infilename;
    
    infile.open(infilename); // Open input file
    
    if (!infile.is_open()) {
        cout << "ERROR: file " << infilename << " can not be opened!" << endl;
        // ...
    } else {
        break; // Exit the loop since the file was opened successfully
    }
}

	// construct output file name from input file name - change to command line input
	size_t delimit = infilename.find('.');
	//filename = strtok(infilename, ".");
	

	string filename = infilename.substr(0, delimit);

	outfilename = filename;
	outfilename = outfilename + "_out.txt";
	ofstream outfile(outfilename);
	
	//strcpy(outfilename, filename);
	//strcat(outfilename, "_out.txt");

	// out output file
	if(!outfile.is_open()) {
		
		cout << "ERROR: file " << outfilename << " can not be opened!\n" ; 
		//printf("ERROR: file %s can not be opened!\n",outfilename);
		return 1;
	}

	// read input file into linked list
	cout << "Current contents of file:\n\n";
	while(
	  infile >> last_name_buffer >> first_name_buffer >> account_no >> balance
	) {
		cout << "Name: " << first_name_buffer << " " << last_name_buffer << " (" << account_no << ")\n";
		cout << "Balance: " << fixed << setprecision(2) << balance << "\n\n";
        //printf("Balance: %.2lf\n\n", balance);
	}
    
    cout << "Enter new member's last name: ";
    cin >> last_name_buffer;
    cout << "Enter new member's first name: ";
    cin >> first_name_buffer;
    cout << "Enter new member's account number: ";
    cin >> account_no;
    cout << "Enter new member's balance: ";
    cin >> balance;
    
    
    
    /*
	printf("Enter new member's last name ?");
	scanf("%s", last_name_buffer);
	printf("Enter new member's first name ?");
	scanf("%s", first_name_buffer);
	printf("Enter new member's account number ?");
	scanf("%d", &account_no);
	printf("Enter new member's balance ?");
	scanf("%lf", &balance);
    */

	// write output file
	
    cout << "Writing output file " << outfilename << endl;
    //printf("Writing output file %s\n", outfilename);
	outfile << last_name_buffer << " " << first_name_buffer << " " << account_no << " " << fixed << setprecision(2) << balance << "\n";
    //fprintf(outfile, "%s %s %d %.2lf\n", last_name_buffer, first_name_buffer, account_no, balance);

	// close files
	//fclose(infile);
	//fclose(outfile);

	return 0;
}		/* end main */