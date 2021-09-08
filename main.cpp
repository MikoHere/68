#include <iostream>
#include <fstream>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

ifstream file;
int iloscJednolitych;

class zad68{
	public:
		zad68();
        ~zad68();
        void loop();
        bool uniform(string s);
        void wypisz();
};
zad68::zad68()
{
        file.open("dane_napisy.txt");
        if (!file.good())
        {
                cerr << "Blad - pliku nie da sie otworzyc!\n";
                exit(1);
        }
}
zad68::~zad68()
{
        file.close();
}
void zad68::loop()
{
    string s1;
    string s2;
    while (!file.eof())
    {
        file >> s1;
        file >> s2;
        if(uniform(s1) && uniform(s2)){
        	if(s1[1] == s2[1]){
        		if(s1.length()==s2.length()){
        			iloscJednolitych++;
				}
			}
		}

	}
}
void zad68::wypisz(){
	cout<<iloscJednolitych;
}
bool zad68::uniform(string s)
{
	char litera=s[0];
	for (int i=1; i<s.length(); i++){
		if(litera!=s[i]){
			return false;
		}
	}
	return true;
}


int main(int argc, char** argv) {
	zad68 a;
	a.loop();
	a.wypisz();
	return 0;
}
