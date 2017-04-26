//including Assembly.h to implement defined methods
#include "Assembly.h"
#include <iostream> //for printing on console

//defining assembly constructor
Assembly::Assembly(string id, string dwg, int qty) : Part(id, dwg, qty) //base class constructor must be called
{

}

//defining addPart() to add a new part in assembly
void Assembly::addPart(Part p)
{
    this->m_parts.push_back(p); //append the part in m_parts (vector of Part)
}

//overriding toString() method for Assembly
string Assembly::toString()
    {
        std::stringstream str; //declaring a string stream variable
        //append formatted string in str
        str << "Assembly Id: " << this->getId() << "\n";
        str << "Assembly Drawing: " << this->getDrawing() << "\n";
        str << "Assembly Quantity: " << this->getQuantity() << "\n";

        //appending a summary of Parts lists in the Assembly
        str << "Assembly Parts List:\n";
        //iterating through Parts vector
        for(int i=0; i<m_parts.size(); ++i)
        {
            //appending each Part value in the str
            str << m_parts[i].toString() << "\n";
        }

        //finally returning str after converting it into a string object
        return str.str();
    }

int main()
{
    //declaring variables for holding assembly data
    string assemblyId, assemblyDwg;
    int assemblyQty, nParts;

    //collecting assembly data now
    cout << "Enter the Assembly id: "; //user prompt to enter assembly id
    cin >> assemblyId; //taking id now

    cout << "Enter the Assembly drawing id: "; //user prompt to enter assembly drawing id
    cin >> assemblyDwg; //taking drawing id now

    cout << "Enter the Assembly quantity: "; //user prompt to enter assembly quantity
    cin >> assemblyQty; //taking quantity now

    cout << "Enter the number of Parts that make up this Assembly: "; //user prompt to add no. of parts
    cin >> nParts;

    //creating an instance of assembly with the user provided data
    Assembly assembly(assemblyId,assemblyDwg,assemblyQty); //calling constructor to initialize Assembly

    /*iterating for nParts times to collect data about all the parts
     that make up the assembly*/
    for(int i=0; i<nParts; ++i)
    {
        //declaring variables to hold Part data
        string partId, partDwg;
        int partQty;

        //collecting data from user for each Part now
        cout << "Enter the Part id: "; //user prompt to enter Part id
        cin >> partId; //taking id now

        cout << "Enter the Part drawing id: "; //user prompt to enter Part drawing id
        cin >> partDwg; //taking drawing id now

        cout << "Enter the Part quantity: "; //user prompt to enter part quantity
        cin >> partQty; //taking quantity now

        //creating a new object of part with the provided data
        Part* part = new Part(partId,partDwg,partQty);
        assembly.addPart(*part); //add this part to assembly
    }

    //displaying the assembly
    cout << "\nThis  is your completed Assembly:\n";
    cout << assembly.toString();

    return 0;
}


