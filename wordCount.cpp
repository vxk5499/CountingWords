#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<deque>
#include<map>
#include<list>
#include<set>
#include<string.h>
#include <stdlib.h>
#include <sstream>
#include <sstream>
#include<stdlib.h>
#include<stdio.h>
#include <ctime>
using namespace std;

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()




using namespace std;


//static string cube="eqeffvxnhnalxvqbcaypicpvxtacesqgcyrnrygmmzhvxcvrdsutfwawokdqsyrs";
set<string> words;
int height = -1;
map<int, vector<int> > hm;

class Node{
public:
		char data;
		vector<Node*> child;

		Node(char a){
			data = a;
		}

};

void insert(string word, struct Node* root){
	int i = 0;
	while(i<word.length()){
		int it = 0;
		bool present = false;
		while(it<root->child.size()){
		    Node* current = root->child[it];

			if(current->data == word[i]){
				root=current;
				i++;
				present = true;

			}
			it = it+1;
		}
		if(present == false){
			 Node* temp = new struct Node(word[i]);

			root->child.push_back(temp);
			root = temp;
			i++;
		}
	}
}



 Node* isContains(vector<Node*> children, char val){
	int i = 0;
	while(i<children.size()){
		if(children[i]->data==val)
			return children[i];
			i++;

	}
	return NULL;
}

 set<char> getValidChildren (string current, Node* root){
	 set<char> result;
	 int i=0;
	 vector<Node*> resultArr;
	 while(i<current.length()){
		 root = isContains(root->child,current[i]);
		 i++;
		 if(root==NULL)
			 return result;
		 if(i==current.length()){
			 resultArr = root->child;
			 break;
		 }
	 }
	 i =0;
	 while(i<resultArr.size()){
		 result.insert(resultArr[i]->data);
		 i++;
	 }
	 return result;
 }



void createMap(){

	int temp[] = { 17, 18, 21, 22, 34, 37, 38, 49, 50, 53, 54 };
	vector<int> vec (temp, temp + sizeof(temp) / sizeof(temp[0]) );
    hm.insert(std::pair<int, vector<int> >(33, vec ));
	int temp1[] = { 19, 20, 23, 24, 35, 39, 40, 51, 52, 55, 56 };
	vector<int> vec1 (temp1, temp1 + sizeof(temp1) / sizeof(temp1[0]) );
    hm.insert(std::pair<int, vector<int> >(36, vec1));
	int temp2[] = { 27, 28, 31, 32, 43, 44, 47, 59, 60, 63, 64 };
	vector<int> vec2 (temp2, temp2 + sizeof(temp2) / sizeof(temp2[0]) );
    hm.insert(std::pair<int, vector<int> >(48,  vec2));
	int temp3[] = { 25, 26, 29, 30, 41, 42, 46, 57, 58, 61, 62 };
	vector<int> vec3 (temp3, temp3 + sizeof(temp3) / sizeof(temp3[0]) );
    hm.insert(std::pair<int, vector<int> >(45, vec3 ));
	int temp4[] = { 17, 18, 19, 21, 22, 23, 33, 35, 37, 38, 39,
			49, 50, 51, 53, 54, 55 };
	vector<int> vec4 (temp4, temp4 + sizeof(temp4) / sizeof(temp4[0]) );
    hm.insert(std::pair<int, vector<int> >(34,  vec4));
	int temp5[] = { 18, 19, 20, 22, 23, 24, 34, 36, 38, 39, 40,
			50, 51, 52, 54, 55, 56 };
	vector<int> vec5 (temp5, temp5 + sizeof(temp5) / sizeof(temp5[0]) );
	hm.insert(std::pair<int, vector<int> >(35,  vec5));
	int temp6[] =  { 23, 24, 27, 28, 19, 20, 35, 36, 39, 43, 44,
			51, 52, 55, 56, 59, 60 };
	vector<int> vec6 (temp6, temp6 + sizeof(temp6) / sizeof(temp6[0]) );
    hm.insert(std::pair<int, vector<int> >(40, vec6));
	int temp7[] =  { 23, 24, 27, 28, 31, 32, 39, 40, 43, 47, 48,
			55, 56, 59, 60, 63, 64 };
	vector<int> vec7 (temp7, temp7 + sizeof(temp7) / sizeof(temp7[0]) );
    hm.insert(std::pair<int, vector<int> >(44,  vec7));
	int temp8[] =  { 25, 26, 27, 29, 30, 31, 41, 42, 43, 45, 47,
			57, 58, 59, 61, 62, 63 };
	vector<int> vec8 (temp8, temp8 + sizeof(temp8) / sizeof(temp8[0]) );
    hm.insert(std::pair<int, vector<int> >(46, vec8));
	int temp9[] =  { 26, 27, 28, 30, 31, 32, 42, 43, 44, 46, 48,
			58, 59, 60, 62, 63, 64 };
	vector<int> vec9 (temp9, temp9 + sizeof(temp9) / sizeof(temp9[0]) );
    hm.insert(std::pair<int, vector<int> >(47,  vec9));
	int temp10[] =  { 17, 18, 21, 22, 25, 26, 33, 34, 38, 41, 42,
			49, 50, 53, 54, 57, 58 };
	vector<int> vec10 (temp10, temp10 + sizeof(temp10) / sizeof(temp10[0]) );
    hm.insert(std::pair<int, vector<int> >(37,  vec10));
	int temp11[] =  { 21, 22, 25, 26, 29, 30, 37, 38, 42, 45, 46,
			53, 54, 57, 58, 61, 62 };
	vector<int> vec11 (temp11, temp11 + sizeof(temp11) / sizeof(temp11[0]) );
    hm.insert(std::pair<int, vector<int> >(41, vec11));
	int temp12[] =  { 17, 18, 19, 21, 22, 23, 25, 26, 27, 33, 34,
			35, 37, 39, 41, 42, 43, 49, 50, 51, 53, 54, 55, 57, 58, 59 };
	vector<int> vec12 (temp12, temp12 + sizeof(temp12) / sizeof(temp12[0]) );
    hm.insert(std::pair<int, vector<int> >(38,  vec12));
	int temp13[] =  { 18, 19, 20, 22, 23, 24, 26, 27, 28, 34, 35,
			36, 38, 40, 42, 43, 44, 50, 51, 52, 54, 55, 56, 58, 59, 60 };
	vector<int> vec13 (temp13, temp13 + sizeof(temp13) / sizeof(temp13[0]) );
    hm.insert(std::pair<int, vector<int> >(39,  vec13));
	int temp14[] =  { 21, 22, 23, 25, 26, 27, 29, 30, 31, 37, 38,
			39, 41, 43, 45, 46, 47, 53, 54, 55, 57, 58, 59, 61, 62, 63 };
	vector<int> vec14 (temp14, temp14 + sizeof(temp14) / sizeof(temp14[0]) );
    hm.insert(std::pair<int, vector<int> >(42,  vec14));
	int temp15[] =  { 22, 23, 24, 26, 27, 28, 30, 31, 32, 38, 39,
			40, 42, 44, 46, 47, 48, 54, 55, 56, 58, 59, 60, 62, 63, 64 };
	vector<int> vec15 (temp15, temp15 + sizeof(temp15) / sizeof(temp15[0]) );
    hm.insert(std::pair<int, vector<int> >(43, vec15));
	int temp16[] =  { 18, 21, 22, 1, 2, 5, 6, 33, 34, 37, 38 };
	vector<int> vec16 (temp16, temp16 + sizeof(temp16) / sizeof(temp16[0]) );
    hm.insert(std::pair<int, vector<int> >(17, vec16));
	int temp17[] =  { 25, 26, 30, 9, 10, 13, 14, 41, 42, 45, 46 };
	vector<int> vec17 (temp17, temp17 + sizeof(temp17) / sizeof(temp17[0]) );
    hm.insert(std::pair<int, vector<int> >(29, vec17));
	int temp18[] =  { 19, 23, 24, 3, 4, 7, 8, 35, 36, 39, 40 };
	vector<int> vec18 (temp18, temp18 + sizeof(temp18) / sizeof(temp18[0]) );
    hm.insert(std::pair<int, vector<int> >(20, vec18));
	int temp19[] =   { 27, 28, 31, 11, 12, 15, 16, 43, 44, 47, 48 };
	vector<int> vec19 (temp19, temp19 + sizeof(temp19) / sizeof(temp19[0]) );
    hm.insert(std::pair<int, vector<int> >(32, vec19));
	int temp20[] =  { 17, 19, 21, 22, 23, 33, 34, 35, 37, 38, 39,
			1, 2, 3, 5, 6, 7 };
	vector<int> vec20 (temp20, temp20 + sizeof(temp20) / sizeof(temp20[0]) );
    hm.insert(std::pair<int, vector<int> >(18, vec20));
	int temp21[] =  { 18, 20, 22, 23, 24, 2, 3, 4, 6, 7, 8, 34,
			35, 36, 38, 39, 40 };
	vector<int> vec21 (temp21, temp21 + sizeof(temp21) / sizeof(temp21[0]) );
    hm.insert(std::pair<int, vector<int> >(19, vec21));
	int temp22[] =  { 26, 27, 25, 29, 31, 9, 10, 11, 13, 14, 15,
			41, 42, 43, 45, 46, 47 };
	vector<int> vec22 (temp22, temp22 + sizeof(temp22) / sizeof(temp22[0]) );
    hm.insert(std::pair<int, vector<int> >(30, vec22));
	int temp23[] =  { 30, 26, 27, 28, 32, 10, 11, 12, 14, 15, 16,
			42, 43, 44, 46, 47, 48 };
	vector<int> vec23 (temp23, temp23 + sizeof(temp23) / sizeof(temp23[0]) );
    hm.insert(std::pair<int, vector<int> >(31, vec23));
	int temp24[] =  { 17, 18, 22, 25, 26, 1, 2, 5, 6, 9, 10, 33,
			34, 37, 38, 41, 42 };
	vector<int> vec24 (temp24, temp24 + sizeof(temp24) / sizeof(temp24[0]) );
    hm.insert(std::pair<int, vector<int> >(21, vec24));
	int temp25[] =  { 21, 22, 26, 29, 30, 5, 6, 9, 10, 13, 14, 37,
			38, 41, 42, 45, 46 };
	vector<int> vec25 (temp25, temp25 + sizeof(temp25) / sizeof(temp25[0]) );
    hm.insert(std::pair<int, vector<int> >(25, vec25));
	int temp26[] =  { 19, 20, 23, 27, 28, 3, 4, 7, 8, 11, 12, 35,
			36, 39, 40, 43, 44 };
	vector<int> vec26 (temp26, temp26 + sizeof(temp26) / sizeof(temp26[0]) );
    hm.insert(std::pair<int, vector<int> >(24, vec26));
	int temp27[] =  { 23, 24, 27, 31, 32, 7, 8, 11, 12, 15, 16,
			39, 40, 43, 44, 47, 48 };
	vector<int> vec27 (temp27, temp27 + sizeof(temp27) / sizeof(temp27[0]) );
    hm.insert(std::pair<int, vector<int> >(28, vec27));
	int temp28[] =  { 17, 18, 19, 21, 23, 25, 26, 27, 5, 6, 7, 1,
			2, 3, 9, 10, 11, 33, 34, 35, 37, 38, 39, 41, 42, 43 };
	vector<int> vec28 (temp28, temp28 + sizeof(temp28) / sizeof(temp28[0]) );
    hm.insert(std::pair<int, vector<int> >(22, vec28));
	int temp29[] =  { 18, 19, 20, 22, 24, 26, 27, 28, 6, 7, 8, 10,
			11, 12, 2, 3, 4, 34, 35, 36, 38, 39, 40, 42, 43, 44 };
	vector<int> vec29 (temp29, temp29 + sizeof(temp29) / sizeof(temp29[0]) );
    hm.insert(std::pair<int, vector<int> >(23, vec29));
	int temp30[] =  { 21, 22, 23, 25, 27, 29, 30, 31, 9, 10, 11,
			13, 14, 15, 5, 6, 7, 37, 38, 39, 41, 42, 43, 45, 46, 47 };
	vector<int> vec30 (temp30, temp30 + sizeof(temp30) / sizeof(temp30[0]) );
    hm.insert(std::pair<int, vector<int> >(26, vec30));
	int temp31[] =  { 22, 23, 24, 26, 28, 30, 31, 32, 6, 7, 8, 10,
			11, 12, 14, 15, 16, 38, 39, 40, 42, 43, 44, 46, 47, 48 };
	vector<int> vec31 (temp31, temp31 + sizeof(temp31) / sizeof(temp31[0]) );
    hm.insert(std::pair<int, vector<int> >(27, vec31));
	int temp32[] =  { 50, 53, 54, 33, 34, 37, 38 };
	vector<int> vec32 (temp32, temp32 + sizeof(temp32) / sizeof(temp32[0]) );
    hm.insert(std::pair<int, vector<int> >(49, vec32));
	int temp33[] =   { 51, 55, 56, 35, 36, 39, 40 };
	vector<int> vec33 (temp33, temp33 + sizeof(temp33) / sizeof(temp33[0]) );
    hm.insert(std::pair<int, vector<int> >(52, vec33));
	int temp34[] =  { 57, 58, 62, 41, 42, 45, 46 };
	vector<int> vec34 (temp34, temp34 + sizeof(temp34) / sizeof(temp34[0]) );
    hm.insert(std::pair<int, vector<int> >(61,  vec34));
	int temp35[] =  { 59, 60, 63, 43, 44, 47, 48 };
	vector<int> vec35 (temp35, temp35 + sizeof(temp35) / sizeof(temp35[0]) );
    hm.insert(std::pair<int, vector<int> >(64, vec35));
	int temp36[] =  { 49, 53, 54, 55, 51, 33, 34, 35, 37, 38, 39 };
	vector<int> vec36 (temp36, temp36 + sizeof(temp36) / sizeof(temp36[0]) );
    hm.insert(std::pair<int, vector<int> >(50, vec36));
	int temp37[] =  { 50, 54, 55, 56, 52, 34, 38, 39, 40, 36, 35 };
	vector<int> vec37 (temp37, temp37 + sizeof(temp37) / sizeof(temp37[0]) );
    hm.insert(std::pair<int, vector<int> >(51, vec37));
	int temp38[] = { 52, 51, 55, 59, 60, 35, 36, 39, 40, 43, 44 };
	vector<int> vec38 (temp38, temp38 + sizeof(temp38) / sizeof(temp38[0]) );
    hm.insert(std::pair<int, vector<int> >(56, vec38));
	int temp39[] =  { 56, 55, 59, 63, 64, 39, 40, 43, 44, 47, 48 };
	vector<int> vec39 (temp39, temp39 + sizeof(temp39) / sizeof(temp39[0]) );
    hm.insert(std::pair<int, vector<int> >(60,  vec39));
	int temp40[] =  { 64, 60, 59, 58, 62, 42, 43, 44, 46, 47, 48 };
	vector<int> vec40 (temp40, temp40 + sizeof(temp40) / sizeof(temp40[0]) );
    hm.insert(std::pair<int, vector<int> >(63, vec40));
	int temp41[] =  { 57, 58, 59, 61, 63, 41, 42, 43, 45, 46, 47 };
	vector<int> vec41 (temp41, temp41 + sizeof(temp41) / sizeof(temp41[0]) );
    hm.insert(std::pair<int, vector<int> >(62,  vec41));
	int temp42[] =  { 49, 50, 54, 58, 57, 33, 34, 38, 42, 41, 37 };
	vector<int> vec42 (temp42, temp42 + sizeof(temp42) / sizeof(temp42[0]) );
    hm.insert(std::pair<int, vector<int> >(53, vec42));
	int temp43[] =  { 53, 54, 58, 62, 61, 37, 38, 41, 42, 45, 46 };
	vector<int> vec43 (temp43, temp43 + sizeof(temp43) / sizeof(temp43[0]) );
    hm.insert(std::pair<int, vector<int> >(57, vec43));
	int temp44[] =  { 49, 50, 51, 53, 55, 57, 58, 59, 33, 34, 35,
			37, 38, 39, 41, 42, 43 };
	vector<int> vec44 (temp44, temp44 + sizeof(temp44) / sizeof(temp44[0]) );
    hm.insert(std::pair<int, vector<int> >(54,vec44));
	int temp45[] =  { 50, 51, 52, 54, 56, 58, 59, 60, 34, 35, 36,
			38, 39, 40, 42, 43, 44 };
	vector<int> vec45 (temp45, temp45 + sizeof(temp45) / sizeof(temp45[0]) );
    hm.insert(std::pair<int, vector<int> >(55, vec45));
	int temp46[] =  { 53, 54, 55, 57, 59, 61, 62, 63, 37, 38, 39,
			41, 42, 43, 45, 46, 47 };
	vector<int> vec46 (temp46, temp46 + sizeof(temp46) / sizeof(temp46[0]) );
    hm.insert(std::pair<int, vector<int> >(58,  vec46));
	int temp47[] =  { 54, 55, 56, 58, 60, 62, 63, 64, 38, 39, 40,
			42, 43, 44, 46, 47, 48 };
	vector<int> vec47 (temp47, temp47 + sizeof(temp47) / sizeof(temp47[0]) );
    hm.insert(std::pair<int, vector<int> >(59,  vec47));
	int temp48[] =  { 2, 6, 5, 17, 18, 21, 22 };
	vector<int> vec48 (temp48, temp48 + sizeof(temp48) / sizeof(temp48[0]) );
    hm.insert(std::pair<int, vector<int> >(1,  vec48));
	int temp49[] =   { 9, 10, 14, 25, 26, 29, 30 };
	vector<int> vec49 (temp49, temp49 + sizeof(temp49) / sizeof(temp49[0]) );
    hm.insert(std::pair<int, vector<int> >(13, vec49));
	int temp50[] = { 3, 8, 7, 19, 20, 23, 24 };
	vector<int> vec50 (temp50, temp50 + sizeof(temp50) / sizeof(temp50[0]) );
    hm.insert(std::pair<int, vector<int> >(4,  vec50));
	int temp51[] =   { 11, 12, 15, 27, 28, 32, 31 };
	vector<int> vec51 (temp51, temp51 + sizeof(temp51) / sizeof(temp51[0]) );
    hm.insert(std::pair<int, vector<int> >(16, vec51));
	int temp52[] =  { 1, 3, 5, 6, 7, 17, 18, 19, 21, 22, 23 };
	vector<int> vec52 (temp52, temp52 + sizeof(temp52) / sizeof(temp52[0]) );
    hm.insert(std::pair<int, vector<int> >(2,vec52));
	int temp53[] ={ 2, 4, 6, 7, 8, 18, 19, 20, 22, 23, 24 };
	vector<int> vec53 (temp53, temp53 + sizeof(temp53) / sizeof(temp53[0]) );
    hm.insert(std::pair<int, vector<int> >(3,  vec53));
	int temp54[] = { 9, 10, 11, 13, 15, 25, 26, 27, 29, 30, 31 };
	vector<int> vec54 (temp54, temp54 + sizeof(temp54) / sizeof(temp54[0]) );
    hm.insert(std::pair<int, vector<int> >(14, vec54));
	int temp55[] =  { 10, 11, 12, 14, 16, 26, 27, 28, 30, 31, 32 };
	vector<int> vec55 (temp55, temp55 + sizeof(temp55) / sizeof(temp55[0]) );
    hm.insert(std::pair<int, vector<int> >(15,  vec55));
	int temp56[] =  { 1, 2, 6, 10, 9, 17, 18, 21, 22, 25, 26 };
	vector<int> vec56 (temp56, temp56 + sizeof(temp56) / sizeof(temp56[0]) );
    hm.insert(std::pair<int, vector<int> >(5,  vec56));
	int temp57[] =  { 5, 6, 10, 13, 14, 21, 25, 29, 22, 26, 30 };
	vector<int> vec57 (temp57, temp57 + sizeof(temp57) / sizeof(temp57[0]) );
    hm.insert(std::pair<int, vector<int> >(9, vec57));
	int temp58[] =  { 3, 4, 7, 11, 12, 19, 23, 27, 20, 24, 28 };
	vector<int> vec58 (temp58, temp58 + sizeof(temp58) / sizeof(temp58[0]) );
    hm.insert(std::pair<int, vector<int> >(8,  vec58));
	int temp59[] =  { 7, 8, 11, 15, 16, 23, 24, 27, 28, 31, 32 };
	vector<int> vec59 (temp59, temp59 + sizeof(temp59) / sizeof(temp59[0]) );
    hm.insert(std::pair<int, vector<int> >(12,  vec59));
	int temp60[] =  { 5, 1, 2, 3, 9, 10, 7, 11, 17, 18, 19, 21, 22,
			23, 25, 26, 27 };
	vector<int> vec60 (temp60, temp60 + sizeof(temp60) / sizeof(temp60[0]) );
    hm.insert(std::pair<int, vector<int> >(6, vec60));
	int temp61[] =  { 2, 3, 4, 6, 8, 10, 11, 12, 18, 19, 20, 22,
			23, 24, 26, 27, 28 };
	vector<int> vec61 (temp61, temp61 + sizeof(temp61) / sizeof(temp61[0]) );
    hm.insert(std::pair<int, vector<int> >(7, vec61));
	int temp62[] =   { 5, 6, 7, 9, 11, 13, 14, 15, 21, 22, 23, 25,
			26, 27, 29, 30, 31 };
	vector<int> vec62 (temp62, temp62 + sizeof(temp62) / sizeof(temp62[0]) );
    hm.insert(std::pair<int, vector<int> >(10, vec62));
	int temp63[] =  { 6, 7, 8, 10, 12, 14, 15, 16, 22, 23, 24, 26,
			27, 28, 30, 31, 32 };
	vector<int> vec63 (temp63, temp63 + sizeof(temp63) / sizeof(temp63[0]) );
    hm.insert(std::pair<int, vector<int> >(11,  vec63));





}

int main(){
	int start_s=clock();
	Node* head = new Node('#');

	string line;

	ifstream in("words.txt");
	if (!in) {
	    cout << "unable to open file";
	    exit(1);
	}

	while (std::getline(in,line)){
		bool valid = true;

		for(int i=0; i<line.length();i++){
			if(!isalpha(line[i])){
				 valid = false;
			}
		}
		 if(valid){

			 for(int j=0;j<line.length();j++)
				 line[j]= tolower(line[j]);
			 insert(line,head);
			 words.insert(line);
		 }
	}

	in.close();

	createMap();
	ifstream in1("cubes.txt");


	if (!in1) {
		    cout << "unable to open file";
		    exit(1);
		}
	while (std::getline(in1,line))
	{
		 for(int j=0;j<line.length();j++)
		 line[j]= tolower(line[j]);
		 string cube = line;

	int count=0;
	set<string> answers;
	for(int cubes=0;cubes<64;cubes++){
		string start;
		start.push_back(cube[cubes]);
		deque<string> bfsW;
		deque<int> bfsI;
		deque<string> bfsV;
		bfsI.push_back(cubes+1);
		bfsW.push_back(start);

		int i = cubes+1;

		std::string s = SSTR( i );



		bfsV.push_back(s);
		string current = start;
		while(bfsW.size()!=0){
			current = bfsW.front();
			bfsW.pop_front();
			int currentI = bfsI.front();
			bfsI.pop_front();
			string currentV = bfsV.front();
			bfsV.pop_front();
			int word=0;
			vector<int> visitedIndices;

		  for(int j=0;j<currentV.length();j++){
						 if(currentV[j]!=' ')
							 word = word*10 + static_cast<int>(currentV[j])-48;
						else
						{

							visitedIndices.push_back(word);
							word=0;
						}
					}

			if(words.find(current)!=words.end()){


				answers.insert(current);
			}

			set<char> children = getValidChildren(current,head);
			if(children.size()>0){

				vector<int> cur = hm.find(currentI)->second;
				int iterator=0;
				while(iterator<cur.size()){
					int index = cur[iterator];
					bool visit = false;
					if(find(visitedIndices.begin(),visitedIndices.end(),index)!=visitedIndices.end())
											visit = true;
					if(children.find(cube[index-1])!=children.end()&& !visit)
					{
						string temp = current;
						temp.push_back(cube[index-1]);
						bfsW.push_back(temp);
						bfsI.push_back(index);

						std::string ind = SSTR( index );
						string temp1 = currentV+' '+ind;

						bfsV.push_back(temp1);

					}
					iterator = iterator +1;
				}
			}
		}
	}

	cout<<answers.size()<<endl;
	}
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	in1.close();

}
