#pragma once
#include <iostream>
#include <string>

class Dog {
public:
	Dog();
	Dog(std::string name, std::string breed, int age, std::string gender);

	std::string getName() { return name; }
	std::string getBreed() { return breed; }
	int getAge() { return age; }
	std::string getGender() { return gender; }

	void setName(std::string aName);
	void setBreed(std::string aBreed);
	void setAge(int aAge);
	void setGender(std::string gender);

private:
	std::string name;
	std::string breed;
	int age;
	std::string gender;
};

Dog::Dog() {
	name = "";
	breed = "";
	age = 1;
	gender = "";
}

Dog::Dog(std::string name, std::string breed, int age, std::string gender) {
	this->name = name;
	this->breed = breed;
	this->age = age;
	this->gender = gender;
}

/*
std::string Dog::getName() {
	return name;
}*/

void Dog::setName(std::string aName) {
	name = aName;
}
void Dog::setBreed(std::string aBreed) {
	breed = aBreed;
}
void Dog::setAge(int aAge) {
	if (aAge > 0) {
		age = aAge;
	}
}
void Dog::setGender(std::string aGender) {
	if (aGender == "female" || aGender == "male" || aGender == "unknown") {
		gender = aGender;
	}
}
