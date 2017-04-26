#include <string>
#include <sstream>
class Part{

public:
	//This is the class constructor
Part(std::string id, std::string dwg, int qty);
	//returns Identity
	std::string getId();
	//returns Drawiing file name
	std::string getDrawing();
	//returns quantity
	int getQuantity();
	//returns combined string which includes id drawing file name and quantity
	std::string toString();

	//sets Identity
	void setId(std::string id);
	//sets Drawing file name
	void setDrawing(std::string dwg);
	//sets quantity
	void setQuantity(int qty);


private:
	std::string output;
	std::string Id;
	std::string Drawing;
	int    Quantity;

};




#include <iostream>

using namespace std;

Part::Part(string id, string dwg, int qty)
{
  this->Id = id;
  this->Drawing = dwg;
  this->Quantity = qty;
}

//returns identity
string Part::getId()
{
  return this->Id;
}

//returns name of drawing file name
string Part::getDrawing()
{
  return this->Drawing;
}

//returns quantity
int Part::getQuantity()
{
  return this->Quantity;
}


//set the identity
void Part::setId(std::string id)
{
  this->Id = id;

}

//set the drawing file name
void Part::setDrawing(string dwg)
{
  this->Drawing = dwg;

}

//returns quantity
void Part::setQuantity(int qty)
{
  this->Quantity = qty;

}

//returns combined string which includes id drawing file name and quantity
std::string Part::toString()
{
  	std::stringstream sstm;
	sstm << Quantity;
    output="Id: "+Id+" drawing: "+Drawing+" qty: "+sstm.str();
    return this->output;
}
