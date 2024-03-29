/*
 * Dylan Greene
 * Kyle Gifaldi
 *
 * CLI.cpp
 * 		Implenation of our command line interface class
 *
 * 		Runs a loop for our command line interface and bascially is in charge
 * 		of managing and interacting with our Image and CompressedImage objects
 * 		
 */

#include <iostream>
#include <vector>
#include <string>

#include "CLI.h"
#include "Image.h"
#include "CompressedImage.h"

using namespace std;

//default constructor for when an image path is not used
CLI::CLI(){
	
	//get a image path
	cout << "Enter an image path: " << endl;
	cin >> imagePath;

	//instantiate an Image object using the image path
	Image tmpIm(imagePath);
	image = tmpIm;

	//instantiate a CompressedImage object
	CompressedImage tmpCIm(image);
	compressed = tmpCIm;

	//run the interface
	run();
	
}

//non default constructor for when an image path is passed
CLI::CLI(string ip){
	//set the imagepath
	imagePath = ip;

	//instantiate an Image object with that image
	Image tmpIm(imagePath);
	image = tmpIm;

	//instantiate a CompressedImage object with the Image
	CompressedImage tmpCIm(image);
	compressed = tmpCIm;
	
	//run the interface
	run();
}

//run the interface
void CLI::run(){
	
	//print a welcome message
	cout << "########################################################" << endl;
	cout << "                Welcome to the IMAGEn                   " << endl;
	cout << "########################################################" << endl;
	
	//execute the main interface loop which prompts the user and acts on that
	while(true){
		menu();
		prompt();
		waitKey(0);
	}
}

//displays a menu of options
void CLI::menu(){
	//display compressed image
	//dispaly a filter of original image
	//display a filter of the compressed imgae
	//write any of those those to a file
	
	cout << endl << "Options: " << endl;
	cout << "\t0: Display the orginal image" << endl;
	cout << "\t1: Display a filter of the original image" << endl;
	cout << "\t2: Display the compressed image" << endl;
	cout << "\t3: Display a filter of the compressed image" << endl;
	cout << "\t4: Write an image or filter to a file" << endl;
	cout << "\t5: Adjust the compression quality" << endl;
	cout << "\tQ: Quit the program" << endl;

}

//prompts the user to choose one of the main options 
//has invalid input checking and also executes the option
void CLI::prompt(){
	string choice = "";
	bool done = false;
	while(!done){
		done = true;
		cout << endl << "\t\tChoose an option: ";
		cin >> choice;
		if(choice == "0"){
			image.displayFilter(0);
		}else if(choice == "1"){
			cout << endl << "Orginal Image filter display options: " << endl;
			filterPrompt(false);
		}else if(choice == "2"){
			compressed.displayFilter(0);
		}else if(choice == "3"){
			cout << endl << "Compressed Image filter display options: " << endl;
			filterPrompt(true);
		}else if(choice == "4"){
			cout << endl << "Which image would you like to write?: " << endl;
			writePrompt();
		}else if(choice == "5"){
			cout << endl << "Enter the desired compression quality (1-100): ";
			int q;
			cin >> q;
			compressed.setQuality(q);
		}else if(choice == "Q"){
			exit(0);
		}else{
			cout << endl << "Invalid option!" << endl;
			menu();
			done = false;
		}
	}
}

//prompts the user for infomation about writing an image to a file
//when the write option is selected from the main options
void CLI::writePrompt(){
	string choice = "";

	//check if the user wants to save a version of the compressed image or the orginal
	bool isCompressed = false;
	do{
		cout << endl << "\tWould you like ORGINAL(1) or COMPRESSED(2) image options (1 or 2): ";
		cin >> choice;
		if(choice != "1" && choice != "2"){
			cout << "Invalid option" << endl;
			continue;
		}else if(choice == "2"){
			isCompressed = true;
		}
		break;
	}while(true);

	//give the options to save the various filters
	bool done = false;
	while(!done){

		if(isCompressed){
			cout << "\tChoose an option for the compressed Image:" << endl;
		}else{
			cout << "\tChoose an option for the orginal Image:" << endl;
		}

		cout << "\t\tOptions:									0: Image" << endl;
		cout << "\t\t1: Red Channel		2: Green Channel   		3: Blue Channel" << endl;
		cout << "\t\t4: Luminance  		5: Blue Chrominance		6: Red Chrominance" << endl;

		done = true;
		cout << endl << "\t\tChoice: ";
		cin >> choice;
		
		if(choice == "0"){
			(isCompressed) ? compressed.saveFilter(0) : image.saveFilter(0);
		}else if(choice == "1"){
			(isCompressed) ? compressed.saveFilter(1) : image.saveFilter(1);
		}else if(choice == "2"){
			(isCompressed) ? compressed.saveFilter(2) : image.saveFilter(2);
		}else if(choice == "3"){
			(isCompressed) ? compressed.saveFilter(3) : image.saveFilter(3);
		}else if(choice == "4"){
			(isCompressed) ? compressed.saveFilter(4) : image.saveFilter(4);
		}else if(choice == "5"){
			(isCompressed) ? compressed.saveFilter(5) : image.saveFilter(5);
		}else if(choice == "6"){
			(isCompressed) ? compressed.saveFilter(6) : image.saveFilter(6);
		}else{
			cout << endl << "Invalid option!" << endl;
			done = false;
		}
	}
	
}

//prompts the user to select which filter they want to display when
//they select display a filter from the main menu
void CLI::filterPrompt(bool isCompressed){
	string choice = "";
	bool done = false;
	while(!done){
		cout << "\t1: Red Channel		2: Green Channel   		3: Blue Channel" << endl;
		cout << "\t4: Luminance  		5: Blue Chrominance		6: Red Chrominance" << endl;

		done = true;
		cout << endl << "\t\tChoice: ";
		cin >> choice;
			
		if(choice == "0"){
			(isCompressed) ? compressed.displayFilter(0) : image.displayFilter(0);
		}else if(choice == "1"){
			(isCompressed) ? compressed.displayFilter(1) : image.displayFilter(1);
		}else if(choice == "2"){
			(isCompressed) ? compressed.displayFilter(2) : image.displayFilter(2);
		}else if(choice == "3"){
			(isCompressed) ? compressed.displayFilter(3) : image.displayFilter(3);
		}else if(choice == "4"){
			(isCompressed) ? compressed.displayFilter(4) : image.displayFilter(4);
		}else if(choice == "5"){
			(isCompressed) ? compressed.displayFilter(5) : image.displayFilter(5);
		}else if(choice == "6"){
			(isCompressed) ? compressed.displayFilter(6) : image.displayFilter(6);
		}else{
			cout << endl << "Invalid option!" << endl;
			done = false;
		}
				
	}
}

