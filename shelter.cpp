#include "dog.h"
#include <iostream> //to cout and cin
#include <fstream> //reads in files
#include <string> //use strings
#include <map> //use maps
#include <iomanip> //use for set width

void readDogList(std::string filename, std::map<std::string, Dog> &dogList, int i) {
	//checking the file
	std::fstream filestr;
	filestr.open(filename);
	if (!filestr.is_open()) {
		std::cout << "Error opening file";
		return;
	}

	//creating our variables
	std::string dogname;
	std::string breed;
	int age;
	std::string gender;
	std::string trash;
	if (i == 0) {
		while (filestr >> dogname >> breed >> age >> gender) {
			Dog pup(dogname, breed, age, gender);
			dogList.insert(std::pair<std::string, Dog>(dogname, pup));
		}
	}
	else if (i == 1) {
		while (filestr >> trash >> dogname >> trash >> breed >> trash >> age >> trash >> gender) {
			Dog pup(dogname, breed, age, gender);
			dogList.insert(std::pair<std::string, Dog>(dogname, pup));
		}
	}
	filestr.close();
}

void printDogs(std::map<std::string, Dog> dogList, std::string file) {
	//iterate through it and put it into a file
	std::ofstream myfile;
	myfile.open(file);
	for (std::map<std::string, Dog>::iterator itr = dogList.begin(); itr != dogList.end(); itr++) {
		myfile << "NAME: " << std::setw(10) << std::left << itr->first
			<< " BREED: " << std::setw(15) << std::left << itr->second.getBreed()
			<< " AGE: " << std::setw(5) << std::left << itr->second.getAge()
			<< " GENDER: " << std::setw(10) << std::left << itr->second.getGender()
			<< std::endl;
	}
	myfile.close();
}

void update(std::string file_in, std::string file_update) {
	//file_in is going to be our orignal file and the one we are going to change
	//file_update is going to be the updates given

	//make a map of the first file
	std::map<std::string, Dog> oldList;
	readDogList(file_in, oldList, 1);

	//now to read through the new file and update the map accordingly
	std::fstream filestr;
	filestr.open(file_update);
	if (!filestr.is_open()) {
		std::cout << "Error opening file";
		return;
	}
	std::string action;
	std::string name;
	while (filestr>>action) {
		if (action == "adopt" ||action == "transfer") {
			filestr >> name;
			std::map<std::string, Dog>::iterator itr = oldList.find(name);
			oldList.erase(itr);
		}
		else if (action == "add") {
			std::string breed;
			int age;
			std::string gender;
			filestr >> name >> breed >> age >> gender;
			Dog pup(name, breed, age, gender);
			oldList.insert(std::pair<std::string, Dog>(name, pup));
		}
	}
	filestr.close();
	//print the new data in it
	printDogs(oldList, file_in);
}


//start with this function and go off of it. 
//this is the main function and will run all of the other functions we make
int main(int argc, char* argv[]) {

	std::string option = argv[1];
	if (option == "create") {
		//creating a map
		//you dont need keyword new
		std::map<std::string, Dog> dogList;

		//getting the file name
		std::string file_name = argv[2];
		readDogList(file_name, dogList, 0);
		//put dog map into a file
		printDogs(dogList, argv[3]);

	}
	else if (option == "update") {
		//updating the map
		update(argv[2], argv[3]);
	}
	else {
		std::cout << "not a valid option" << std::endl;
	}
	
	return 1;
}
