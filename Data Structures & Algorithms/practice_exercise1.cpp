#include <iostream>
#include <vector>

using namespace std; 

class Artwork{
	string artist_name, art_title;
	unsigned int artwork_year; 
	
public:
	//Old Default constructor 
	void artwork(){
		artist_name = "";
		art_title = "";
		artwork_year = 0;	
	}
	
	//To access the pirvate data 
	string get_name() const {
		return artist_name; 
	}
	
	string get_title() const {
		return art_title; 
	}
	
	unsigned int get_year() const {
		return artwork_year; 
	}
	
	//Constructor
	void assign_artwork(string name, string title, int year){
		artist_name = name;
		art_title = title;
		artwork_year = year;
	}
	
	//Compares all variables between the two objects and returns a boolean on whether they are equal or not
	bool operator == (const Artwork& other) const {
		bool is_equal = artwork_year == other.artwork_year;
		is_equal = is_equal && art_title == other.art_title;
		is_equal = is_equal && artist_name == other.artist_name;
		return is_equal; 
	}
	
	void print() const{
		cout << "Artwork Name: " << artist_name << "  Year: " << artwork_year << "  Title: " << art_title << endl;
	}
	
};

//SoldArtwork is a child class of artwork
class SoldArtwork : public Artwork{
	string customer_name, customer_address;
	double sale_amount;
	
public:
	//Default Constructor
	SoldArtwork(): sale_amount(0) {}
	//Public Constructor 
	//By including Artwork you are going access to those class functions (Constructor -Implcit Setter Method) 
	SoldArtwork(string new_name, string new_address, double new_sale_amount, Artwork new_artwork):
		Artwork(new_artwork), customer_name(new_name), customer_address(new_address), sale_amount(new_sale_amount){}
		
	//To access the pirvate data 
	string get_customer_name() const {
		return customer_name; 
	}
	
	string get_address() const {
		return customer_address; 
	}
	
	double get_sale_amount() const {
		return sale_amount; 
	}

	bool operator == (const SoldArtwork& other) const {
		bool is_equal = customer_name == other.customer_name;
		is_equal = is_equal && customer_address == other.customer_address;
		is_equal = is_equal && sale_amount == other.sale_amount;
		is_equal = is_equal && Artwork::get_name() == other.get_name() 
		&& Artwork::get_title() == other.get_title() 
		&& Artwork::get_year() == other.get_year();
	return is_equal;
	}
	
void print() const {
		Artwork::print();
		cout << "Buyer name: " << customer_name << "  Address: " << customer_address << "  Price: " << sale_amount << endl; 
	}	
};

class ArtworkCollection{
	vector<Artwork> my_artwork; 
	vector<SoldArtwork> my_sold_artwork; 
	
	bool insert_artwork(const Artwork& artwork_info){ 
		for(auto element:my_artwork){
			if(my_artwork[element] == artwork_info){
			return false; 	
			}	 	
		}
		my_artwork.push_back(Artwork); // Double Check
		return true; 
	}
	
	bool sell_artwork(const SoldArtwork& artwork_info){
		bool success = false; 
		for(auto element:my_artwork){
			if(my_artwork[element] == artwork_info){
				my_artwork.erase(element);
				success = true;
			}
			else {
			return success;  
			}		
		}
		my_sold_artwork.push_back(SoldArtwork); //Double Check
		return success && true; 
	}
	
	bool operator == (const ArtworkCollection& other){
		bool success = false; 
		for(auto element:my_artwork){
			if(my_artwork[element] == other.my_artwork[element]) {
				success = true;
			}
		}
		for(auto element:my_sold_artwork){
			if(my_sold_artwork[element] == other.my_sold_artwork[element]) {
					success = success && true; 
			}
		}
		return success; 
	}
	
	ArtworkCollection operator + (ArtworkCollection& other);
};

ArtworkCollection operator + (ArtworkCollection& other){
	for(auto element:my_artwork){
		my_artwork.push_back(other.my_artwork[element])
	}
	for(auto element:my_sold_artwork){
		my_sold_artwork.push_back(other.my_sold_artwork[element])
	}
	return ArtworkCollection; 
}

bool test_insert_artwork(Artwork art1){
	success = insert_artwork(art1);
	return success; 
}

bool test_sell_artwork(SoldArtwork sold1){
	success = sell_artwork(sold1);
	return success; 
}

int main(){

Artwork Art1; 
Artwork Art2; 
Artwork Art3;
SoldArtwork Sold1;
SoldArtwork Sold2;
SoldArtwork Sold3;
SoldArtwork Sold4;

Art1.assign_artwork("Urban", "SlovakMan Circa 2019", 2019); 	
Art2.assign_artwork("Mason", "ChinaMan Circa 2019", 2019);
Art3.assign_artwork("Trelford", "Lin Alg God", 2018);

Sold1.SoldArtwork("Belatos", "Waterloo", 500000.0)
Sold2.SoldArtwork("Carol", "Kitchener", 5.0)
Sold3.SoldArtwork("Trelfor", "Cambridge", 5.0)
Sold4.SoldArtwork("Melek", "NASA", 500000000000000.0)

cout << Art1 << endl; 
cout << Art2 << endl;
cout << Art3 << endl; 
cout << Sold1 << endl; 
cout << Sold2 << endl;
cout << Sold3 << endl;
cout << Sold4 << endl;

bool s1 = test_insert_artwork(Art1);
bool s2 = test_insert_artwork(Art2);
bool s3 = test_insert_artwork(Art3);

if(s1==s2==s3){
	cout << s1 << s2 << s3 << endl;
}
else {
	cout << "Failure to insert"; 
}


system("PAUSE");
return EXIT_SUCCESS;
	
}
	
