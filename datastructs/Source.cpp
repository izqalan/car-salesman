#include <iostream>
#include "Header.h"
using namespace std;
// car dealer db

int main(){
	struct car k;
	struct queue q;
	struct queue temp;
	
	for (int n = q.front; n <= 1; n++){
		get(&k);
		add(&k, &q);
	}

	display(&q);

	del(0, &k, &q, &temp); // notepad popup

	display(&q);
	
	return 0;
}