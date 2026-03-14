#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[])
{
	switch (argc){
		case 1:
			cerr << "Non hai inserito il nome del file\n";
			return 1;
		
		case 2:{
			string nome_file = argv[1];
			ifstream ifs(nome_file);
			if (!ifs.is_open()) {
				cerr << "Il file non è stato aperto con successo\n";
				return 1;
			}
			
			string location;
			double temp1, temp2, temp3, temp4;
			
			ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
			
			while (!ifs.eof()) {
			cout << location << " " << (temp1+temp2+temp3+temp4)/4 << "\n";
			
			ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
			}
			return 0;
		}
		
		default:
			cerr << "Hai inserito troppi nomi\n";
			return 1;
			
	}
}