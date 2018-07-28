#include <iostream>
#include <istream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <string>
#define max 10

using namespace std;

/**
 * TODO
 * Search function
 * Update / edit record fucntion
 */


string filename;

struct car{
	// value
	int id;
	char brand[20];
	char model[20];
	char year[5];
	int nextId;
};

typedef struct queue{
	int front = 0;
	int rear = -1;
	car data[max];
}qq;

car get(struct car *c){

	// TODO year can only take numbers

	cout << "Manufacture: ";
	cin >> c->brand;
	//cin->ignore();
	//cin->getline(c->brand, 20);
	cout << "Model: ";
	//cin->ignore();
	//cin->getline(c->model, 20);
	cin >> c->model;
	cout << "Year: ";
	//cin->ignore();
	//cin->getline(c->year, 20);
	cin >> c->year;
	return *c;
}

string mkfile(){

	// filename based on current time
	char filename[50];
	time_t getTime;
	struct tm now;
	time(&getTime);
	localtime_s(&now, &getTime);
	char strTime[50];

	strftime(strTime, 50, "%H-%M-%S.txt", &now);
	strcpy_s(filename, strTime);
	return filename;

}

void sav(struct queue *q){
	
	//stringstream ss;

	string filename = mkfile();

	ofstream record;
	record.open(filename);

	for (int i = q->front; i <= q->rear; i++){
		// need null checking
		record << "ID: " << q->data[i].id;
		record << " Manufacture: " << q->data[i].brand;
		record << " Model: " << q->data[i].model;
		record << " Year released: " << q->data[i].year << endl;
	}
	record.close();
	 
	//ss << "notepad.exe " << filename;
	//char notepad[50];
	//string s = ss.str();
	//strcpy_s(notepad,filename.c_str());

	cout << "file saved: " <<filename.c_str() << endl;

}

void popup(){
	// will popup .txt file
	// apperently 'notepad.exe' is not required in system param
	
	int result = system(filename.c_str());

	// just incase some system require 'notepad.exe' in the system param function
	if (result != 0){
		
		stringstream ss;
		char notepad[50];
		ss << "notepad.exe " << notepad;
		strcat_s(notepad, filename.c_str());
		int result = system(notepad);

		if (result != 0){
			cout << "save filed ... please contact the coders" << endl;
		}
	}
}


void display(struct queue *q){

	// TODO need null cheking

	for (int i = q->front; i <= q->rear; i++){
		cout << "ID: " << q->data[i].id;
		cout << " Manufacture: " << q->data[i].brand;
		cout << " Model: " << q->data[i].model;
		cout << " Year released: " << q->data[i].year << endl;
	}
	
}

void add(car *c, queue *q){

	// TODO need to check queue memory availability

	if (q->rear != -1){
		c->nextId = q->rear + 1;
	}
	q->rear = q->rear + 1;
	c->id = q->rear;
	q->data[q->rear] = *c;

}

void del(int id, car *c, queue *q, queue *temp){

	// After delete a record it will save the record.

	cout << "deleting :" << id << endl;
	c->id = id;
	for (int i = 0; i <= q->rear; i++){
		cout << "i " << i << endl;
		if (c->id != q->data[i].id)
		{
			cout << "adding data into temp" << endl;
			car n = q->data[i];
			cout << "this is : " << q->data[i].id << endl;
			temp->rear = temp->rear + 1;
			temp->data[temp->rear] = n;
		}
	}
	*q = *temp;
	sav(q);
}

