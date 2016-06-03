// Name:	Ian Matteson
// CS490 Assignment 1
// Date Feb/01/2016
// Creating a hash tables to support storage and retrieval of data


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct hash_table    // creation of a hash table stuct
{
	int hash_key;
	int load_key;
	float data_key;
};

int main()
{
	int hash_tag = 97;
	int hash_tag_four;
	bool status = true;
	bool overflow = false;		//if the hash position is already taken
	bool duplicate_key = false;
	bool error_key = false;
	bool key_probe = false;
	string line;
	char command;
	int key;
	float data_number;
	int prime_key_remainder;
	int prime_key_lookup;

	int number_of_lookups = 1;

	int overflow_table_position = 0;	// iniatilize the position of the overflow table to 0

	int number_items_in_hash = 0;		// initialize the number of items to 0

	int key_probe_position = 0;
	int overflow_summary = 0;
	float data_key_summary;
	int Table_Index;

	// summary file variables

	int total_number_commands = 0;
	int total_insertions = 0;
	int total_lookups = 0;
	int total_collisions = 0;
	float load_factor = 0;

	ifstream input;
	ofstream outData;

	hash_tag_four = hash_tag / 4;

	hash_table first_table[97];		// size of hash table
	hash_table overflow_table[25];	// size of overflow table

	// Initialize hash_table to -1

	for (int i = 0; i <= 96; i++)									// HASH TAG -1 
		{
			first_table[i].hash_key = i;
			first_table[i].load_key = -1;
		}

	// Initialize overflow_table to -1

	for (int k = 0; k <= 24; k++)									// HASH TAG - 1 /4
		{
			overflow_table[k].hash_key = k;
			overflow_table[k].load_key = -1;
		}

   outData.open("logout.txt");       // open output file logout.txt

	cout << "CS490 Assignment 1" << endl;
	
	string filename;
	cout << "Enter the file name: " << endl;
	cin >> filename;
	input.open(filename.c_str());
	

	while(input.fail()) // looking for the correct file
		{
			cout << "Incorrect filename, please enter again. " << endl;
			cin >> filename;
			input.open(filename.c_str());
		}

	

	while ((input >> command ) && (status == true)) // Once the file is open it will go on one line at a time
				// Input the first character, it is either I for insert or L for lookup
				// Check if the overall status is OK
	{
		if (command == 'I')       // insert command
			{
				total_number_commands++;		// increment total number of commands

				(input  >> key >> data_number);  // download key and data from indata.txt file

				prime_key_remainder = key % 97;   // calculate index							HASH TAG

				if (first_table[prime_key_remainder].load_key == key)  // Checking for duplicate keys
					{
						cout << endl << "ERROR " << key << " is a duplicate key. " << endl << endl;
						duplicate_key = true;

						outData <<  endl << "ERROR " << key << " is a duplicate key. " << endl << endl; // data to logout.txt
						
					}

				if (duplicate_key == false)
					{

					if (first_table[prime_key_remainder].load_key == -1)
						{
							first_table[prime_key_remainder].load_key = key;
							first_table[prime_key_remainder].data_key = data_number;

							total_insertions++;		// increament total insertions

							// output to output.txt
							outData << "************************************************************" << endl;
							outData << "Command I " << key << " " << data_number << endl;
							outData << "Item Added: Key " << key << ", data value " << data_number << endl;
							outData << "Hash value: " << prime_key_remainder << endl;
							outData << "Number of Probes: 1 " << endl;
							outData << "Table Index: " <<  prime_key_remainder << endl;
							outData << "************************************************************" << endl << endl;
						}
					else
						overflow = true; // collision occurred
				
					if ((overflow == true) && (overflow_table_position <= 24))					//HASH TAG four - 1 /4
						{
							total_collisions++;		// increment total collision
							overflow_table[overflow_table_position].load_key = key;
							overflow_table[overflow_table_position].data_key = data_number;
							overflow_table_position++;

							
							overflow_summary = overflow_table_position -1;

							total_insertions++;
							total_collisions++;

							// output to output.txt
							outData << "************************************************************" << endl;
							outData << "Command I " << key << " " << data_number << endl;
							outData << "Item Added: Key " << key << ", data value " << data_number << endl;
							outData << "Hash value: " << prime_key_remainder << endl;
							outData << "Number of Probes: 2 " << endl;
							outData << "Table Index: " <<  overflow_summary << endl;
							outData << "************************************************************" << endl << endl;

						}

					if (overflow_table_position == 24) // Overflow hash table is full.						Hash TAG 4 -1

						{
							cout << "Overflow hash table is full. Terminating program!!!!! " << endl;
							outData << "Overflow hash table is full. Terminating program!!!!! " << endl;

							status = false;
						}
																							
				}

				overflow = false;       // reset overflow to false
				duplicate_key = false;  // reset overflow to false
			}

		if (command == 'L')				// lookup command L
			{
				(input >> key);
				total_number_commands++;
				total_lookups;			// increament the number of lookups

				prime_key_lookup = key % 97;    // calculate index										HASH TAG

				if (first_table[prime_key_lookup].load_key == -1)
					{
						cout << endl << "ERROR: No data was found with "  << key << " in the hash table. " << endl << endl;
						outData << endl << "ERROR: No data was found with "  << key << " in the hash table. " << endl << endl;
						error_key = true;
					}

				if (error_key == false)
					{
					if (first_table[prime_key_lookup].load_key == key)   // found hash key and data in the first table
						{
							cout << "Key value " << key << " has been found. Data for the key is ";
							cout << first_table[prime_key_lookup].data_key << endl;
							cout << "Number of Probes: " << number_of_lookups << endl << endl;

                            outData << "************************************************************" << endl;
							outData << "Command L " << key << endl;
							outData << "Item Look Up: Key " << key << " Data: " << first_table[prime_key_lookup].data_key << endl;
							outData << "Hash value: " << prime_key_lookup << endl;
							outData << "Number of Probes: 1 " << endl;
							outData << "Table Index: " << prime_key_lookup << endl;
							outData << "************************************************************" << endl << endl;

							total_lookups++;
						}
					else
						{
							while (key_probe == false)  // looking for index value in second table
							{
								if ((overflow_table[key_probe_position].load_key == key) && (key_probe_position <= 24)) // Hash tag 4 -1
									{
										
										cout << "Key value " << key << " has been found. Data for the key is ";
										cout << overflow_table[key_probe_position].data_key << endl;
										data_key_summary = overflow_table[key_probe_position].data_key;
										Table_Index = key_probe_position;
										key_probe_position++;
										
										number_of_lookups = number_of_lookups + key_probe_position;
										cout << "Number of Probes: " << number_of_lookups << endl << endl;

										outData << "************************************************************" << endl;
										outData << "Command L " << key << endl;
										outData << "Item Look Up: Key " << key << " Data: " << data_key_summary << endl;
										outData << "Hash value: " << prime_key_lookup << endl;
										outData << "Number of Probes: " << number_of_lookups << endl;
										outData << "Table Index: " << Table_Index << endl;
										outData << "************************************************************" << endl << endl;

										key_probe = true;
									}
								 
								 key_probe_position++;
								 total_lookups++;

								
								if (key_probe_position == 24)										// HASH TAG 4 -1
									{
										cout << "All overflow keys have been checked, and no match has been found for key: ";
										cout << key << endl << endl;

										outData << "All overflow keys have been checked, and no match has been found for key: ";
										outData << key << endl << endl;

										key_probe = true;
									}
							}
						}

					}

				key_probe_position = 0;		// reinitilize variables
				number_of_lookups = 1;
				error_key = false;
				key_probe = false;
				
			}


	}		// stopped looking up data form the indata.txt

	input.close();
	outData.close();			// close the logout.txt file
	outData.open("summary.txt");

	cout << " HASH TABLE  "   << endl;									// for the output
	cout << "Index			Key/Label		Data " << endl;
	cout << "*****************************************************" << endl;

	outData << " HASH TABLE  "   << endl;									// for the summary.txt file
	outData << "Index			Key/Label		Data " << endl;
	outData << "*****************************************************" << endl;

	for (int j = 0; j <= 96; j++)					// display data in hash table							hash tag -1
	    {
			cout << first_table[j].hash_key << "	                " << first_table[j].load_key << "\t\t\t";
			outData << first_table[j].hash_key << "	                " << first_table[j].load_key << "\t\t\t";
				if (first_table[j].load_key != -1)					// not equal to -1 print the data
					{
						cout << first_table[j].data_key;
						outData << first_table[j].data_key;
					}
				
			cout << endl;
			outData << endl;
		}

	cout << endl << " OVERFLOW TABLE   " << endl;				// for the output
	cout << "Index			Key/Label		Data " << endl;
	cout << "*****************************************************" << endl;

	outData << endl << " OVERFLOW TABLE   " << endl;				// for the summary.txt
	outData << "Index			Key/Label		Data " << endl;
	outData << "*****************************************************" << endl;

	for (int l = 0; l <= 24; l++)														// Hash tag 4 -1
	    {
			cout << overflow_table[l].hash_key << "	                " << overflow_table[l].load_key << "\t\t\t";
			outData << overflow_table[l].hash_key << "	                " << overflow_table[l].load_key << "\t\t\t";
				if (overflow_table[l].load_key != -1)					// not equal to -1 print the data
					{
						cout << overflow_table[l].data_key;
						outData << overflow_table[l].data_key;
					}
				
			cout << endl;
			outData << endl;
		}

	cout << endl << " Statistics   " << endl;				// for the summary.txt
	cout << "*****************************************************" << endl;
	cout << "Total Number Of Commands: " << total_number_commands << endl;
    cout << "Total Number Of Insertions: " << total_insertions << endl;
	cout << "Total Number Of Lookups: " << total_lookups << endl;
	cout << "Total Number Of Collisions: " << total_collisions << endl ;

	

	load_factor = (total_insertions / 122.0) * 100.0;								//hash tag + hashtag 4

	cout << "Load factor is: " << load_factor << " %" << endl;
	cout << "*****************************************************" << endl << endl;

	outData << endl << " Statistics   " << endl;				// for the summary.txt
	outData << "*****************************************************" << endl;
	outData << "Total Number Of Commands: " << total_number_commands << endl;
	outData << "Total Number Of Insertions: " << total_insertions << endl;
    outData << "Total Number Of Lookups: " << total_lookups << endl;
	outData << "Total Number Of Collisions: " << total_collisions << endl;
	outData << "Load factor is: " << load_factor << " %" << endl;
	outData << "*****************************************************" << endl << endl;

	outData.close();

	system("PAUSE");

	return 0;

}