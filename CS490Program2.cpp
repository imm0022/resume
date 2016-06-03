// Name:	Ian Matteson
// CS490 Assignment 2
// Date March/ 28/2016
// Creating a hash tables to support storage and retrieval of data


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void check_frames(int& n, int& fr_num);

struct frames
{
	int frame_number;
	int frame_position;
	int frame1;
	int frame1toggle;
	int frame2;
	int frame2toggle;
	int frame3;
	int frame3toggle;
	int frame4;
	int frame4toggle;
	int frame5;
	int frame5toggle;
	int frame6;
	int frame6toggle;
	int frame7;
	int frame7toggle;

};





int main()
{
	
	string filename1, filename2;
	bool processFile1 = false;
	bool processFile2 = false;

	ifstream inputData;
	ofstream outputData;

	bool Filename2exist = true;
	bool looking_frame = false;
	bool page_fault_display = false;
	bool fill_pages = true;
	bool next_page = true;
	int pf_display_num = 0;
	int frameInput;	
	int position = 0;
	int position2 = 0;
	int frameFound = -1;
	int fr_num_sel = 0;

	
	float pageFaultFreq13;

	int oneThree0 = 0, oneThree1 = 0, oneThree2 = 0, oneThree3 = 0, oneThree4 = 0;
	int oneThree5 = 0, oneThree6 = 0, oneThree7 = 0, oneThree8 = 0, oneThree9 = 0;
 
	frames dataSetOne[100];
	frames dataSetTwo[100];
	
	frames oneThree[7];		// maximum nuber of frames 100
	frames oneFive[2];
	frames oneSeven[2];

	frames twoThree[2];
	frames twoFive[2];
	frames twoSeven[2];
	

		oneThree[1].frame1 = -1;
		oneThree[1].frame2 = -1;
		oneThree[1].frame3 = -1;

		oneFive[1].frame1 = -1;
		oneFive[1].frame2 = -1;
		oneFive[1].frame3 = -1;
		oneFive[1].frame4 = -1;
		oneFive[1].frame5 = -1;

		oneSeven[1].frame1 = -1;
		oneSeven[1].frame2 = -1;
		oneSeven[1].frame3 = -1;
		oneSeven[1].frame4 = -1;
		oneSeven[1].frame5 = -1;
		oneSeven[1].frame6 = -1;
		oneSeven[1].frame7 = -1;

		twoThree[1].frame1 = -1;
		twoThree[1].frame2 = -1;
		twoThree[1].frame3 = -1;

		twoFive[1].frame1 = -1;
		twoFive[1].frame2 = -1;
		twoFive[1].frame3 = -1;
		twoFive[1].frame4 = -1;
		twoFive[1].frame5 = -1;

		twoSeven[1].frame1 = -1;
		twoSeven[1].frame2 = -1;
		twoSeven[1].frame3 = -1;
		twoSeven[1].frame4 = -1;
		twoSeven[1].frame5 = -1;
		twoSeven[1].frame6 = -1;
		twoSeven[1].frame7 = -1;

	



	cout << " Please input the name and the location of the first data set: " << endl; // Input the first dataset

	getline(cin, filename1);

	inputData.open(filename1.c_str());

	

	while(inputData.fail()) //  for the correct file
		{
			cout << " Incorrect filename, please enter again. " << endl;
			cin >> filename1;
			inputData.open(filename1.c_str());
		}

	while ( inputData >> frameInput)     // find how many frames we have 
	{
		position++;

		dataSetOne[position].frame_position = position;
		dataSetOne[position].frame_number = frameInput;
	}

	


	inputData.close(); // close data set one

	
	cout << " If a second data set exist please enter the name and location of the file. " << endl; // Input the second dataset
	cout << " if there is not a second file name please type no: " << endl;

	getline(cin, filename2);

	if (filename2 == "no")
	{

		Filename2exist = false;
	}

	if (Filename2exist == true)
	{

		inputData.open(filename2.c_str());

		while(inputData.fail()) //  for the correct file
			{
				cout << "Incorrect filename, please enter again. " << endl;
				cin >> filename1;
				inputData.open(filename1.c_str());
			}

		while ( inputData >> frameInput)     // find how many frames we have 
	{
		position2++;

		dataSetTwo[position2].frame_position = position2;
		dataSetTwo[position2].frame_number = frameInput;
	}
		inputData.close(); // close data set one
	}

	

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	//		Second part of the program. All the input frames from the files have been copied and storied in memory
	//
	//
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
 

	int fr_pos = 1;
	int fr_num = 0;
	int frame_fault = 0, frame_fault15 = 0;
	bool page_fault = false;

	// Data set 1 resident set size 3

	for (int n = 1; n <= position ; n++)     // lops thru the entire data set
	{
		
	if (n == 1)
	{
		oneThree[1].frame1 = dataSetOne[n].frame_number;
		oneThree[1].frame1toggle = 1;
		frame_fault++;

	}

	if (n == 2)
	{
		oneThree[1].frame2 = dataSetOne[n].frame_number;
		oneThree[1].frame2toggle = 1;
		frame_fault++;

	}

	if (n == 3)      // the first three default automatically
	{
		oneThree[1].frame3 = dataSetOne[n].frame_number;
		oneThree[1].frame3toggle = 1;
		frame_fault++;

	}


	if (n > 3){

		looking_frame = true;
		fr_num = dataSetOne[n].frame_number;
		page_fault = false;


		while (looking_frame == true){

			if (fr_num == oneThree[1].frame1)  // Check frame 1
			{
				oneThree[1].frame1toggle = 1;
				looking_frame = false;
			}
			else
			{
				oneThree[1].frame1toggle = 0;
			}

			if ((fr_num == oneThree[1].frame2) && (looking_frame == true))   // check frame 2
			{
				oneThree[1].frame2toggle = 1;
				looking_frame = false;
			}
			else
			{
				oneThree[1].frame2toggle = 0;
			}

			if ((fr_num == oneThree[1].frame3) && (looking_frame == true))    // check frame 3
			{
				oneThree[1].frame3toggle = 1;
				looking_frame = false;
			}
			else
			{
				oneThree[1].frame3toggle = 0;
			}
		
			if (looking_frame == true)
				{
					looking_frame = false;
					frame_fault++;
					page_fault = true;

				}
		} // while loop I

		while (page_fault == true)
		{
			

			if ((oneThree[1].frame1toggle == 0) && (oneThree[1].frame2toggle == 1))
				{
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

			if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

			if ((oneThree[1].frame1toggle == 0) && (oneThree[1].frame2toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

			if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) && (page_fault == true))
				{
					
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = 0;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}
			if(page_fault == true )
			{

				cout << endl << "page_fault error" << endl;
			}

			oneThree[1].frame3 = fr_num;
			oneThree[1].frame3toggle = 1;

		} // while loop

		}  // n > 3

		

	}  // for loop calculating the number of frmes for each page

	for (int o = 1; o <= position ; o++){

	fr_num_sel = dataSetOne[o].frame_number;


		switch(fr_num_sel)
		{
			case 0 : oneThree0++;
						break;
			case 1 : oneThree1++;
						break;
			case 2 : oneThree2++;
						break;
			case 3 : oneThree3++;
						break;
			case 4 : oneThree4++;
						break;
			case 5 : oneThree5++;
						break;
			case 6 : oneThree6++;
						break;
			case 7 : oneThree7++;
						break;
			case 8 : oneThree8++;
						break;
			case 9 : oneThree9++;
						break;

			default: cout << endl << "Error, frame number is out of bounds. " << endl;
		}

	

	} // end of for loop

		
		pageFaultFreq13 = (float)(frame_fault) / (float)(position);

	cout << endl << "************************************************************************ " << endl;
	cout << endl << " Data Set 1: RSS = 3 "  << endl;
	cout << " Total number of pages that were referenced:  " << position << endl;
	cout << " Number of Faults:  " << frame_fault << endl;
	cout << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	cout << " Number of times each page is referenced: " << endl;
	cout << " 0:  " << oneThree0 << endl;
	cout << " 1:  " << oneThree1 << endl;		
	cout << " 2:  " << oneThree2 << endl;
	cout << " 3:  " << oneThree3 << endl;
	cout << " 4:  " << oneThree4 << endl;
	cout << " 5:  " << oneThree5 << endl;		
	cout << " 6:  " << oneThree6 << endl;
	cout << " 7:  " << oneThree7 << endl;
	cout << " 8:  " << oneThree8 << endl;
	cout << " 9:  " << oneThree9 << endl;

	outputData.open("short_data_set.txt");

	outputData << endl << "************************************************************************ " << endl;
	outputData << endl << " Data Set 1: RSS = 3 "  << endl;
	outputData << " Total number of pages that were referenced:  " << position << endl;
	outputData << " Number of Faults:  " << frame_fault << endl;
	outputData << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	outputData << " Number of times each page is referenced: " << endl;
	outputData << " 0:  " << oneThree0 << endl;
	outputData << " 1:  " << oneThree1 << endl;		
	outputData << " 2:  " << oneThree2 << endl;
	outputData << " 3:  " << oneThree3 << endl;
	outputData << " 4:  " << oneThree4 << endl;
	outputData << " 5:  " << oneThree5 << endl;		
	outputData << " 6:  " << oneThree6 << endl;
	outputData << " 7:  " << oneThree7 << endl;
	outputData << " 8:  " << oneThree8 << endl;
	outputData << " 9:  " << oneThree9 << endl;

	outputData.close();

	//*******************************************************************************************
	// Data set 1 resident set size 5

	cout << endl << "************************************************************************ " << endl;
	cout << endl << " Data Set 1: RSS = 5 "  << endl << endl;
	cout << " Page Referenced\t Page Replaced\t\t Current Page List   " << endl;

	outputData.open("large_data_set.txt");

	outputData << endl << "************************************************************************ " << endl;
	outputData << endl << " Data Set 1: RSS = 5 "  << endl << endl;
	outputData << " Page Referenced\t Page Replaced\t\t Current Page List   " << endl;

	outputData.close();





	frame_fault = 0;
	looking_frame = false;
	
	for (int n = 1; n <= position ; n++)     // lops thru the entire data set
	{


		page_fault_display = false;

	if (n == 1)
	{
		oneThree[1].frame1 = dataSetOne[n].frame_number;
		oneThree[1].frame1toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame1 << "\t\t\t\t\t\t " << oneThree[1].frame1 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame1 << "\t\t\t\t\t\t " << oneThree[1].frame1 << endl;

		outputData.close();
	}

	if (n == 2)
	{
		oneThree[1].frame2 = dataSetOne[n].frame_number;
		oneThree[1].frame2toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame2 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame2 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2 << endl;

		outputData.close();

	}

	if (n == 3)      // the first three default automatically
	{
		oneThree[1].frame3 = dataSetOne[n].frame_number;
		oneThree[1].frame3toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame3 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		cout << "  " << oneThree[1].frame3 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame3 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		outputData << "  " << oneThree[1].frame3 << endl;

		outputData.close();


	}

	if (n == 4)      // the first four default automatically
	{
		oneThree[1].frame4 = dataSetOne[n].frame_number;
		oneThree[1].frame4toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame4 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		cout << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame4 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		outputData << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << endl;

		outputData.close();
	}

    if (n == 5)      // the first four default automatically
	{
		oneThree[1].frame5 = dataSetOne[n].frame_number;
		oneThree[1].frame5toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame5 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		cout << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame5 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		outputData << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5 << endl;

		outputData.close();

	}

	if (n > 5){

		looking_frame = true;
		fr_num = dataSetOne[n].frame_number;
		page_fault = false;	

		while (looking_frame == true)
			{
				if (fr_num == oneThree[1].frame1)  // Check frame 1
				{
				oneThree[1].frame1toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame1toggle = 0;
				}

				if ((fr_num == oneThree[1].frame2) && (looking_frame == true))   // check frame 2
				{
				oneThree[1].frame2toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame2toggle = 0;
				}

				if ((fr_num == oneThree[1].frame3) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame3toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame3toggle = 0;
				}

				if ((fr_num == oneThree[1].frame4) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame4toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame4toggle = 0;
				}

				if ((fr_num == oneThree[1].frame5) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame5toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame5toggle = 0;
				}
		
				if (looking_frame == true)
				{
					looking_frame = false;
					frame_fault++;
					page_fault = true;
					page_fault_display = true;
				}

		
		
		}  // end of while loop


			while (page_fault == true)
			{
				if (oneThree[1].frame1toggle == 0)
				{
					pf_display_num = oneThree[1].frame1;
					
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					oneThree[1].frame3 = oneThree[1].frame4;
					oneThree[1].frame3toggle = oneThree[1].frame4toggle;

					oneThree[1].frame4 = oneThree[1].frame5;
					oneThree[1].frame4toggle = oneThree[1].frame5toggle;

					page_fault = false;
					  

				}
				
				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;

					pf_display_num = oneThree[1].frame2;

					oneThree[1].frame4 = oneThree[1].frame1;
					oneThree[1].frame4toggle = oneThree[1].frame1toggle;

					oneThree[1].frame1 = oneThree[1].frame3;
					oneThree[1].frame1toggle = oneThree[1].frame3toggle;

					oneThree[1].frame2 = oneThree[1].frame4;
					oneThree[1].frame2toggle = oneThree[1].frame4toggle;

					oneThree[1].frame3 = oneThree[1].frame5;
					oneThree[1].frame3toggle = oneThree[1].frame5toggle;

					page_fault = false;

				}

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) 
					&& (oneThree[1].frame3toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;

					pf_display_num = oneThree[1].frame3;

					oneThree[1].frame3 = oneThree[1].frame1;
					oneThree[1].frame3toggle = oneThree[1].frame1toggle;

					oneThree[1].frame4 = oneThree[1].frame2;
					oneThree[1].frame4toggle = oneThree[1].frame2toggle;

					oneThree[1].frame1 = oneThree[1].frame4;
					oneThree[1].frame1toggle = oneThree[1].frame4toggle;

					oneThree[1].frame2 = oneThree[1].frame5;
					oneThree[1].frame2toggle = oneThree[1].frame5toggle;

					page_fault = false;

				}
			
				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) 
					&& (oneThree[1].frame3toggle == 1) && (oneThree[1].frame4toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;

					pf_display_num = oneThree[1].frame4;

					oneThree[1].frame1 = oneThree[1].frame5;
					oneThree[1].frame1toggle = oneThree[1].frame5toggle;

					oneThree[1].frame2 = oneThree[1].frame1;
					oneThree[1].frame2toggle = oneThree[1].frame1toggle;

					oneThree[1].frame3 = oneThree[1].frame2;
					oneThree[1].frame3toggle = oneThree[1].frame2toggle;

					oneThree[1].frame4 = oneThree[1].frame3;
					oneThree[1].frame4toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

				// I don't think frame 5 can ever have a toggle of 0, therfore I didn't make a if statement for frame5toggle

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) && (oneThree[1].frame3toggle == 1)
					 && (oneThree[1].frame4toggle == 1) && (oneThree[1].frame5toggle == 1) && (page_fault == true))
				{
					
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;
					oneThree[1].frame4toggle = 0;
					oneThree[1].frame5toggle = 0;

					pf_display_num = oneThree[1].frame1;

					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					oneThree[1].frame3 = oneThree[1].frame4;
					oneThree[1].frame3toggle = oneThree[1].frame4toggle;

					oneThree[1].frame4 = oneThree[1].frame5;
					oneThree[1].frame4toggle = oneThree[1].frame5toggle;

					page_fault = false;

				}

				if (page_fault == true)
				{
					cout << endl << "Page fault error" << endl;
					page_fault = false;
				}

				oneThree[1].frame5 = fr_num;
				oneThree[1].frame5toggle = 1;


			}  // end of while loop

			if (page_fault_display == true)
			{

			cout << " " << fr_num << "\t\t\t " << pf_display_num << "\t\t\t " <<  oneThree[1].frame1 << "  " << oneThree[1].frame2;
			cout << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5  << endl;

			outputData.open("large_data_set.txt", ios::app);

			outputData << " " << fr_num << "\t\t\t " << pf_display_num << "\t\t\t " <<  oneThree[1].frame1 << "  " << oneThree[1].frame2;
			outputData << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5  << endl;

			outputData.close();

			}
			else
			{

			cout << " " << fr_num << "\t\t\t\t\t\t " <<  oneThree[1].frame1 << "  " << oneThree[1].frame2;
			cout << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5 << endl;

			outputData.open("large_data_set.txt", ios::app);

			outputData << " " << fr_num << "\t\t\t\t\t\t " <<  oneThree[1].frame1 << "  " << oneThree[1].frame2;
			outputData << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5 << endl;

			outputData.close();

			}

			/*

			cout << endl << "frame_fault:  " << frame_fault << "frame reference:  " << dataSetOne[n].frame_number << endl;
			cout << "frames " << oneThree[1].frame1 << "  ";
			cout << oneThree[1].frame2 << "  ";
			cout << oneThree[1].frame3 << "  ";
			cout << oneThree[1].frame4 << "  ";
			cout << oneThree[1].frame5 << "  " << endl;

			*/

			}

	} // end of for loop

	pageFaultFreq13 = (float)(frame_fault) / (float)(position);

	cout << endl << " Data Set 1: RSS = 5 "  << endl;
	cout << " Total number of pages that were referenced:  " << position << endl;
	cout << " Number of Faults:  " << frame_fault << endl;
	cout << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	cout << " Number of times each page is referenced: " << endl;
	cout << " 0:  " << oneThree0 << endl;
	cout << " 1:  " << oneThree1 << endl;		
	cout << " 2:  " << oneThree2 << endl;
	cout << " 3:  " << oneThree3 << endl;
	cout << " 4:  " << oneThree4 << endl;
	cout << " 5:  " << oneThree5 << endl;		
	cout << " 6:  " << oneThree6 << endl;
	cout << " 7:  " << oneThree7 << endl;
	cout << " 8:  " << oneThree8 << endl;
	cout << " 9:  " << oneThree9 << endl;


	outputData.open("large_data_set.txt", ios::app);

	outputData << endl << " Data Set 1: RSS = 5 "  << endl;
	outputData << " Total number of pages that were referenced:  " << position << endl;
	outputData << " Number of Faults:  " << frame_fault << endl;
	outputData << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	outputData << " Number of times each page is referenced: " << endl;
	outputData << " 0:  " << oneThree0 << endl;
	outputData << " 1:  " << oneThree1 << endl;		
	outputData << " 2:  " << oneThree2 << endl;
	outputData << " 3:  " << oneThree3 << endl;
	outputData << " 4:  " << oneThree4 << endl;
	outputData << " 5:  " << oneThree5 << endl;		
	outputData << " 6:  " << oneThree6 << endl;
	outputData << " 7:  " << oneThree7 << endl;
	outputData << " 8:  " << oneThree8 << endl;
	outputData << " 9:  " << oneThree9 << endl;

	outputData.close();

	outputData.open("short_data_set.txt", ios::app);

	outputData << "************************************************************************ " << endl;
	outputData << endl << " Data Set 1: RSS = 5 "  << endl;
	outputData << " Total number of pages that were referenced:  " << position << endl;
	outputData << " Number of Faults:  " << frame_fault << endl;
	outputData << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	outputData << " Number of times each page is referenced: " << endl;
	outputData << " 0:  " << oneThree0 << endl;
	outputData << " 1:  " << oneThree1 << endl;		
	outputData << " 2:  " << oneThree2 << endl;
	outputData << " 3:  " << oneThree3 << endl;
	outputData << " 4:  " << oneThree4 << endl;
	outputData << " 5:  " << oneThree5 << endl;		
	outputData << " 6:  " << oneThree6 << endl;
	outputData << " 7:  " << oneThree7 << endl;
	outputData << " 8:  " << oneThree8 << endl;
	outputData << " 9:  " << oneThree9 << endl;

	outputData.close();


//*******************************************************************************************
	// Data set 1 resident set size 7

	cout << endl << "************************************************************************ " << endl;
	cout << endl << " Data Set 1: RSS = 7 "  << endl << endl;

	outputData.open("short_data_set.txt", ios::app);

	outputData << endl << "************************************************************************ " << endl;
	outputData << endl << " Data Set 1: RSS = 7 "  << endl << endl;

	outputData.close();

	oneThree[1].frame1 = -1;
	oneThree[1].frame2 = -1;
	oneThree[1].frame3 = -1;
	oneThree[1].frame4 = -1;
	oneThree[1].frame5 = -1;
	oneThree[1].frame6 = -1;
	oneThree[1].frame7 = -1;

	next_page = true;
	frame_fault = 0;
	fill_pages = true;
	
	
	for (int n = 1; n <= position ; n++)     // lops thru the entire data set
	{

		fill_pages = true;
		page_fault_display = false;
	
		while (fill_pages == true)
		{
			if (oneThree[1].frame1 == -1)
			{
			oneThree[1].frame1 = dataSetOne[n].frame_number;
			oneThree[1].frame1toggle = 1;
			frame_fault++;
			fill_pages = false;
		
			}

		
			if ((dataSetOne[n].frame_number != oneThree[1].frame1) && (oneThree[1].frame2 == -1) && (fill_pages == true))
			{
				oneThree[1].frame2 = dataSetOne[n].frame_number;
				oneThree[1].frame2toggle = 1;
				frame_fault++;
				fill_pages = false;
	
			}	
		

			if ((dataSetOne[n].frame_number != oneThree[1].frame1) && (dataSetOne[n].frame_number != oneThree[1].frame2)
				&& (oneThree[1].frame3 == -1) && (fill_pages == true))
			{
				oneThree[1].frame3 = dataSetOne[n].frame_number;
				oneThree[1].frame3toggle = 1;
				frame_fault++;
				fill_pages = false;
	
			
			}

			if ((dataSetOne[n].frame_number != oneThree[1].frame1) && (dataSetOne[n].frame_number != oneThree[1].frame2)
				&& (dataSetOne[n].frame_number != oneThree[1].frame3) && (oneThree[1].frame4 == -1) && (fill_pages == true))
			{
				oneThree[1].frame4 = dataSetOne[n].frame_number;
				oneThree[1].frame4toggle = 1;
				frame_fault++;
				fill_pages = false;
				

			}

			if ((dataSetOne[n].frame_number != oneThree[1].frame1) && (dataSetOne[n].frame_number != oneThree[1].frame2)
				&& (dataSetOne[n].frame_number != oneThree[1].frame3) && (dataSetOne[n].frame_number != oneThree[1].frame4)
				&& (oneThree[1].frame5 == -1) && (fill_pages == true))
			{
				oneThree[1].frame5 = dataSetOne[n].frame_number;
				oneThree[1].frame5toggle = 1;
				frame_fault++;
				fill_pages = false;
				

			}

			if ((dataSetOne[n].frame_number != oneThree[1].frame1) && (dataSetOne[n].frame_number != oneThree[1].frame2)
				&& (dataSetOne[n].frame_number != oneThree[1].frame3) && (dataSetOne[n].frame_number != oneThree[1].frame4)
				&& (dataSetOne[n].frame_number != oneThree[1].frame5) && (oneThree[1].frame6 == -1) && (fill_pages == true))
			{
				oneThree[1].frame6 = dataSetOne[n].frame_number;
				oneThree[1].frame6toggle = 1;
				frame_fault++;
				fill_pages = false;
		

			}

			if ((dataSetOne[n].frame_number != oneThree[1].frame1) && (dataSetOne[n].frame_number != oneThree[1].frame2)
				&& (dataSetOne[n].frame_number != oneThree[1].frame3) && (dataSetOne[n].frame_number != oneThree[1].frame4)
				&& (dataSetOne[n].frame_number != oneThree[1].frame5) && (dataSetOne[n].frame_number != oneThree[1].frame6)
				&& (oneThree[1].frame7 == -1) && (fill_pages ==true))
			{
				oneThree[1].frame7 = dataSetOne[n].frame_number;
				oneThree[1].frame7toggle = 1;
				frame_fault++;
				fill_pages = false;


			}

			fill_pages = false;

			

		}//end of the while loop fill pages

		if ((fill_pages == false) && (frame_fault >= 7))
		{

		looking_frame = true;
		fr_num = dataSetOne[n].frame_number;
		page_fault = false;	

		while (looking_frame == true)
			{
				if (fr_num == oneThree[1].frame1)  // Check frame 1
				{
				oneThree[1].frame1toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame1toggle = 0;
				}

				if ((fr_num == oneThree[1].frame2) && (looking_frame == true))   // check frame 2
				{
				oneThree[1].frame2toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame2toggle = 0;
				}

				if ((fr_num == oneThree[1].frame3) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame3toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame3toggle = 0;
				}

				if ((fr_num == oneThree[1].frame4) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame4toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame4toggle = 0;
				}

				if ((fr_num == oneThree[1].frame5) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame5toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame5toggle = 0;
				}

				if ((fr_num == oneThree[1].frame6) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame6toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame6toggle = 0;
				}

				if ((fr_num == oneThree[1].frame7) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame7toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame7toggle = 0;
				}

		
				if (looking_frame == true)
				{
					looking_frame = false;
					frame_fault++;
					page_fault = true;
				}

		} // end of the while loop

		while (page_fault == true)
			{
				if (oneThree[1].frame1toggle == 0)
				{
					
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					oneThree[1].frame3 = oneThree[1].frame4;
					oneThree[1].frame3toggle = oneThree[1].frame4toggle;

					oneThree[1].frame4 = oneThree[1].frame5;
					oneThree[1].frame4toggle = oneThree[1].frame5toggle;

					oneThree[1].frame5 = oneThree[1].frame6;
					oneThree[1].frame5toggle = oneThree[1].frame6toggle;

					oneThree[1].frame6 = oneThree[1].frame7;
					oneThree[1].frame6toggle = oneThree[1].frame7toggle;

					page_fault = false;
					  

				}
				
				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;

					oneThree[1].frame6 = oneThree[1].frame1;
					oneThree[1].frame6toggle = oneThree[1].frame1toggle;

					oneThree[1].frame1 = oneThree[1].frame3;
					oneThree[1].frame1toggle = oneThree[1].frame3toggle;

					oneThree[1].frame2 = oneThree[1].frame4;
					oneThree[1].frame2toggle = oneThree[1].frame4toggle;

					oneThree[1].frame3 = oneThree[1].frame5;
					oneThree[1].frame3toggle = oneThree[1].frame5toggle;

					oneThree[1].frame4 = oneThree[1].frame6;
					oneThree[1].frame4toggle = oneThree[1].frame6toggle;

					oneThree[1].frame5 = oneThree[1].frame7;
					oneThree[1].frame5toggle = oneThree[1].frame7toggle;

					page_fault = false;

				}

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) 
					&& (oneThree[1].frame3toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;

					oneThree[1].frame5 = oneThree[1].frame1;
					oneThree[1].frame5toggle = oneThree[1].frame1toggle;

					oneThree[1].frame6 = oneThree[1].frame2;
					oneThree[1].frame6toggle = oneThree[1].frame2toggle;

					oneThree[1].frame1 = oneThree[1].frame4;
					oneThree[1].frame1toggle = oneThree[1].frame4toggle;

					oneThree[1].frame2 = oneThree[1].frame5;
					oneThree[1].frame2toggle = oneThree[1].frame5toggle;

					oneThree[1].frame3 = oneThree[1].frame6;
					oneThree[1].frame3toggle = oneThree[1].frame6toggle;

					oneThree[1].frame4 = oneThree[1].frame7;
					oneThree[1].frame4toggle = oneThree[1].frame7toggle;

					page_fault = false;

				}
			
				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) 
					&& (oneThree[1].frame3toggle == 1) && (oneThree[1].frame4toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;

					oneThree[1].frame1 = oneThree[1].frame5;
					oneThree[1].frame1toggle = oneThree[1].frame5toggle;

					oneThree[1].frame2 = oneThree[1].frame1;
					oneThree[1].frame2toggle = oneThree[1].frame1toggle;

					oneThree[1].frame3 = oneThree[1].frame2;
					oneThree[1].frame3toggle = oneThree[1].frame2toggle;

					oneThree[1].frame4 = oneThree[1].frame3;
					oneThree[1].frame4toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

				

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) && (oneThree[1].frame3toggle == 1)
					 && (oneThree[1].frame4toggle == 1) && (oneThree[1].frame5toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;
					oneThree[1].frame4toggle = 0;


					oneThree[1].frame1 = oneThree[1].frame6;
					oneThree[1].frame1toggle = oneThree[1].frame6toggle;

					oneThree[1].frame2 = oneThree[1].frame7;
					oneThree[1].frame2toggle = oneThree[1].frame7toggle;

					oneThree[1].frame3 = oneThree[1].frame1;
					oneThree[1].frame3toggle = oneThree[1].frame1toggle;

					oneThree[1].frame4 = oneThree[1].frame2;
					oneThree[1].frame4toggle = oneThree[1].frame2toggle;

					oneThree[1].frame5 = oneThree[1].frame3;
					oneThree[1].frame5toggle = oneThree[1].frame3toggle;

					oneThree[1].frame6 = oneThree[1].frame4;
					oneThree[1].frame6toggle = oneThree[1].frame4toggle;


					page_fault = false;

				}

				// I don't think frame 7 can ever have a toggle of 0, therfore I didn't make a if statement for frame5toggle

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) && (oneThree[1].frame3toggle == 1)
					 && (oneThree[1].frame4toggle == 1) && (oneThree[1].frame5toggle == 1) && (oneThree[1].frame6toggle == 1) 
					 && (page_fault == true))
				{
					
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;
					oneThree[1].frame4toggle = 0;
					oneThree[1].frame5toggle = 0;
					oneThree[1].frame5toggle = 0;

					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					oneThree[1].frame3 = oneThree[1].frame4;
					oneThree[1].frame3toggle = oneThree[1].frame4toggle;

					oneThree[1].frame4 = oneThree[1].frame5;
					oneThree[1].frame4toggle = oneThree[1].frame5toggle;

					oneThree[1].frame5 = oneThree[1].frame6;
					oneThree[1].frame5toggle = oneThree[1].frame6toggle;

					oneThree[1].frame6 = oneThree[1].frame7;
					oneThree[1].frame6toggle = oneThree[1].frame7toggle;

					page_fault = false;

				}
				if (page_fault == true)
				{
					cout << endl << "Page fault error" << endl;
					page_fault = false;
				}

				oneThree[1].frame7 = fr_num;
				oneThree[1].frame7toggle = 1;


			}  // end of while loop

		}
		/*
			cout << endl << "frame_fault:  " << frame_fault << "frame reference:  " << dataSetOne[n].frame_number << endl;
			cout << "frames " << oneThree[1].frame1 << "  ";
			cout << oneThree[1].frame2 << "  ";
			cout << oneThree[1].frame3 << "  ";
			cout << oneThree[1].frame4 << "  ";
			cout << oneThree[1].frame5 << "  ";
			cout << oneThree[1].frame6 << "  ";
			cout << oneThree[1].frame7 << "  " << endl;

			*/

	} // end of for loop

		
		pageFaultFreq13 = (float)(frame_fault) / (float)(position);



	cout << " Total number of pages that were referenced:  " << position << endl;
	cout << " Number of Faults:  " << frame_fault << endl;
	cout << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	cout << " Number of times each page is referenced: " << endl;
	cout << " 0:  " << oneThree0 << endl;
	cout << " 1:  " << oneThree1 << endl;		
	cout << " 2:  " << oneThree2 << endl;
	cout << " 3:  " << oneThree3 << endl;
	cout << " 4:  " << oneThree4 << endl;
	cout << " 5:  " << oneThree5 << endl;		
	cout << " 6:  " << oneThree6 << endl;
	cout << " 7:  " << oneThree7 << endl;
	cout << " 8:  " << oneThree8 << endl;
	cout << " 9:  " << oneThree9 << endl;
	
	outputData.open("short_data_set.txt", ios::app);

	outputData << " Total number of pages that were referenced:  " << position << endl;
	outputData << " Number of Faults:  " << frame_fault << endl;
	outputData << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	outputData << " Number of times each page is referenced: " << endl;
	outputData << " 0:  " << oneThree0 << endl;
	outputData << " 1:  " << oneThree1 << endl;		
	outputData << " 2:  " << oneThree2 << endl;
	outputData << " 3:  " << oneThree3 << endl;
	outputData << " 4:  " << oneThree4 << endl;
	outputData << " 5:  " << oneThree5 << endl;		
	outputData << " 6:  " << oneThree6 << endl;
	outputData << " 7:  " << oneThree7 << endl;
	outputData << " 8:  " << oneThree8 << endl;
	outputData << " 9:  " << oneThree9 << endl;

	outputData.close();


	//***************************************************************************************************
	//
	//
	//    Dataset 2 set size 3


	fr_pos = 1;
	fr_num = 0;
	frame_fault = 0; 
	frame_fault15 = 0;
	page_fault = false;

	// Data set 1 resident set size 3

	for (int n = 1; n <= position2 ; n++)     // lops thru the entire data set
	{
		
	if (n == 1)
	{
		oneThree[1].frame1 = dataSetTwo[n].frame_number;
		oneThree[1].frame1toggle = 1;
		frame_fault++;

	}

	if (n == 2)
	{
		oneThree[1].frame2 = dataSetTwo[n].frame_number;
		oneThree[1].frame2toggle = 1;
		frame_fault++;

	}

	if (n == 3)      // the first three default automatically
	{
		oneThree[1].frame3 = dataSetTwo[n].frame_number;
		oneThree[1].frame3toggle = 1;
		frame_fault++;

	}


	if (n > 3){

		looking_frame = true;
		fr_num = dataSetTwo[n].frame_number;
		page_fault = false;


		while (looking_frame == true){

			if (fr_num == oneThree[1].frame1)  // Check frame 1
			{
				oneThree[1].frame1toggle = 1;
				looking_frame = false;
			}
			else
			{
				oneThree[1].frame1toggle = 0;
			}

			if ((fr_num == oneThree[1].frame2) && (looking_frame == true))   // check frame 2
			{
				oneThree[1].frame2toggle = 1;
				looking_frame = false;
			}
			else
			{
				oneThree[1].frame2toggle = 0;
			}

			if ((fr_num == oneThree[1].frame3) && (looking_frame == true))    // check frame 3
			{
				oneThree[1].frame3toggle = 1;
				looking_frame = false;
			}
			else
			{
				oneThree[1].frame3toggle = 0;
			}
		
			if (looking_frame == true)
				{
					looking_frame = false;
					frame_fault++;
					page_fault = true;

				}
		} // while loop I

		while (page_fault == true)
		{
			

			if ((oneThree[1].frame1toggle == 0) && (oneThree[1].frame2toggle == 1))
				{
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

			if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

			if ((oneThree[1].frame1toggle == 0) && (oneThree[1].frame2toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

			if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) && (page_fault == true))
				{
					
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = 0;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}
			if(page_fault == true )
			{

				cout << endl << "page_fault error" << endl;
			}

			oneThree[1].frame3 = fr_num;
			oneThree[1].frame3toggle = 1;

		} // while loop

		}  // n > 3

		

	}  // for loop calculating the number of frmes for each page

	for (int o = 1; o <= position2 ; o++){

	fr_num_sel = dataSetTwo[o].frame_number;


		switch(fr_num_sel)
		{
			case 0 : oneThree0++;
						break;
			case 1 : oneThree1++;
						break;
			case 2 : oneThree2++;
						break;
			case 3 : oneThree3++;
						break;
			case 4 : oneThree4++;
						break;
			case 5 : oneThree5++;
						break;
			case 6 : oneThree6++;
						break;
			case 7 : oneThree7++;
						break;
			case 8 : oneThree8++;
						break;
			case 9 : oneThree9++;
						break;

			default: cout << endl << "Error, frame number is out of bounds. " << endl;
		}

	

	} // end of for loop

		
		pageFaultFreq13 = (float)(frame_fault) / (float)(position2);

	cout << endl << "************************************************************************ " << endl;
	cout << endl << " Data Set 2: RSS = 3 "  << endl;
	cout << " Total number of pages that were referenced:  " << position2 << endl;
	cout << " Number of Faults:  " << frame_fault << endl;
	cout << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	cout << " Number of times each page is referenced: " << endl;
	cout << " 0:  " << oneThree0 << endl;
	cout << " 1:  " << oneThree1 << endl;		
	cout << " 2:  " << oneThree2 << endl;
	cout << " 3:  " << oneThree3 << endl;
	cout << " 4:  " << oneThree4 << endl;
	cout << " 5:  " << oneThree5 << endl;		
	cout << " 6:  " << oneThree6 << endl;
	cout << " 7:  " << oneThree7 << endl;
	cout << " 8:  " << oneThree8 << endl;
	cout << " 9:  " << oneThree9 << endl;

	outputData.open("short_data_set.txt", ios::app);

	outputData << endl << "************************************************************************ " << endl;
	outputData << endl << " Data Set 2: RSS = 3 "  << endl;
	outputData << " Total number of pages that were referenced:  " << position2 << endl;
	outputData << " Number of Faults:  " << frame_fault << endl;
	outputData << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	outputData << " Number of times each page is referenced: " << endl;
	outputData << " 0:  " << oneThree0 << endl;
	outputData << " 1:  " << oneThree1 << endl;		
	outputData << " 2:  " << oneThree2 << endl;
	outputData << " 3:  " << oneThree3 << endl;
	outputData << " 4:  " << oneThree4 << endl;
	outputData << " 5:  " << oneThree5 << endl;		
	outputData << " 6:  " << oneThree6 << endl;
	outputData << " 7:  " << oneThree7 << endl;
	outputData << " 8:  " << oneThree8 << endl;
	outputData << " 9:  " << oneThree9 << endl;

	outputData.close();

	//**************************************************************************************************
	//
	//
	// Data set 2 resident set size 5

	cout << endl << "************************************************************************ " << endl;
	cout << endl << " Data Set 2: RSS = 5 "  << endl << endl;
	cout << " Page Referenced\t Page Replaced\t\t Current Page List   " << endl;

	outputData.open("large_data_set.txt", ios::app);

	outputData << endl << "************************************************************************ " << endl;
	outputData << endl << " Data Set 2: RSS = 5 "  << endl << endl;
	outputData << " Page Referenced\t Page Replaced\t\t Current Page List   " << endl;

	outputData.close();





	frame_fault = 0;
	looking_frame = false;
	
	for (int n = 1; n <= position2 ; n++)     // lops thru the entire data set
	{


		page_fault_display = false;

	if (n == 1)
	{
		oneThree[1].frame1 = dataSetTwo[n].frame_number;
		oneThree[1].frame1toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame1 << "\t\t\t\t\t\t " << oneThree[1].frame1 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame1 << "\t\t\t\t\t\t " << oneThree[1].frame1 << endl;

		outputData.close();
	}

	if (n == 2)
	{
		oneThree[1].frame2 = dataSetTwo[n].frame_number;
		oneThree[1].frame2toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame2 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame2 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2 << endl;

		outputData.close();

	}

	if (n == 3)      // the first three default automatically
	{
		oneThree[1].frame3 = dataSetTwo[n].frame_number;
		oneThree[1].frame3toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame3 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		cout << "  " << oneThree[1].frame3 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame3 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		outputData << "  " << oneThree[1].frame3 << endl;

		outputData.close();


	}

	if (n == 4)      // the first four default automatically
	{
		oneThree[1].frame4 = dataSetTwo[n].frame_number;
		oneThree[1].frame4toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame4 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		cout << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame4 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		outputData << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << endl;

		outputData.close();
	}

    if (n == 5)      // the first four default automatically
	{
		oneThree[1].frame5 = dataSetTwo[n].frame_number;
		oneThree[1].frame5toggle = 1;
		frame_fault++;
		cout << " " << oneThree[1].frame5 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		cout << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5 << endl;

		outputData.open("large_data_set.txt", ios::app);

		outputData << " " << oneThree[1].frame5 << "\t\t\t\t\t\t " << oneThree[1].frame1 << "  " << oneThree[1].frame2;
		outputData << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5 << endl;

		outputData.close();

	}

	if (n > 5){

		looking_frame = true;
		fr_num = dataSetTwo[n].frame_number;
		page_fault = false;	

		while (looking_frame == true)
			{
				if (fr_num == oneThree[1].frame1)  // Check frame 1
				{
				oneThree[1].frame1toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame1toggle = 0;
				}

				if ((fr_num == oneThree[1].frame2) && (looking_frame == true))   // check frame 2
				{
				oneThree[1].frame2toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame2toggle = 0;
				}

				if ((fr_num == oneThree[1].frame3) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame3toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame3toggle = 0;
				}

				if ((fr_num == oneThree[1].frame4) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame4toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame4toggle = 0;
				}

				if ((fr_num == oneThree[1].frame5) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame5toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame5toggle = 0;
				}
		
				if (looking_frame == true)
				{
					looking_frame = false;
					frame_fault++;
					page_fault = true;
					page_fault_display = true;
				}

		
		
		}  // end of while loop


			while (page_fault == true)
			{
				if (oneThree[1].frame1toggle == 0)
				{
					pf_display_num = oneThree[1].frame1;
					
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					oneThree[1].frame3 = oneThree[1].frame4;
					oneThree[1].frame3toggle = oneThree[1].frame4toggle;

					oneThree[1].frame4 = oneThree[1].frame5;
					oneThree[1].frame4toggle = oneThree[1].frame5toggle;

					page_fault = false;
					  

				}
				
				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;

					pf_display_num = oneThree[1].frame2;

					oneThree[1].frame4 = oneThree[1].frame1;
					oneThree[1].frame4toggle = oneThree[1].frame1toggle;

					oneThree[1].frame1 = oneThree[1].frame3;
					oneThree[1].frame1toggle = oneThree[1].frame3toggle;

					oneThree[1].frame2 = oneThree[1].frame4;
					oneThree[1].frame2toggle = oneThree[1].frame4toggle;

					oneThree[1].frame3 = oneThree[1].frame5;
					oneThree[1].frame3toggle = oneThree[1].frame5toggle;

					page_fault = false;

				}

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) 
					&& (oneThree[1].frame3toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;

					pf_display_num = oneThree[1].frame3;

					oneThree[1].frame3 = oneThree[1].frame1;
					oneThree[1].frame3toggle = oneThree[1].frame1toggle;

					oneThree[1].frame4 = oneThree[1].frame2;
					oneThree[1].frame4toggle = oneThree[1].frame2toggle;

					oneThree[1].frame1 = oneThree[1].frame4;
					oneThree[1].frame1toggle = oneThree[1].frame4toggle;

					oneThree[1].frame2 = oneThree[1].frame5;
					oneThree[1].frame2toggle = oneThree[1].frame5toggle;

					page_fault = false;

				}
			
				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) 
					&& (oneThree[1].frame3toggle == 1) && (oneThree[1].frame4toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;

					pf_display_num = oneThree[1].frame4;

					oneThree[1].frame1 = oneThree[1].frame5;
					oneThree[1].frame1toggle = oneThree[1].frame5toggle;

					oneThree[1].frame2 = oneThree[1].frame1;
					oneThree[1].frame2toggle = oneThree[1].frame1toggle;

					oneThree[1].frame3 = oneThree[1].frame2;
					oneThree[1].frame3toggle = oneThree[1].frame2toggle;

					oneThree[1].frame4 = oneThree[1].frame3;
					oneThree[1].frame4toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

				// I don't think frame 5 can ever have a toggle of 0, therfore I didn't make a if statement for frame5toggle

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) && (oneThree[1].frame3toggle == 1)
					 && (oneThree[1].frame4toggle == 1) && (oneThree[1].frame5toggle == 1) && (page_fault == true))
				{
					
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;
					oneThree[1].frame4toggle = 0;
					oneThree[1].frame5toggle = 0;

					pf_display_num = oneThree[1].frame1;

					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					oneThree[1].frame3 = oneThree[1].frame4;
					oneThree[1].frame3toggle = oneThree[1].frame4toggle;

					oneThree[1].frame4 = oneThree[1].frame5;
					oneThree[1].frame4toggle = oneThree[1].frame5toggle;

					page_fault = false;

				}

				if (page_fault == true)
				{
					cout << endl << "Page fault error" << endl;
					page_fault = false;
				}

				oneThree[1].frame5 = fr_num;
				oneThree[1].frame5toggle = 1;


			}  // end of while loop

			if (page_fault_display == true)
			{

			cout << " " << fr_num << "\t\t\t " << pf_display_num << "\t\t\t " <<  oneThree[1].frame1 << "  " << oneThree[1].frame2;
			cout << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5  << endl;

			outputData.open("large_data_set.txt", ios::app);

			outputData << " " << fr_num << "\t\t\t " << pf_display_num << "\t\t\t " <<  oneThree[1].frame1 << "  " << oneThree[1].frame2;
			outputData << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5  << endl;

			outputData.close();

			}
			else
			{

			cout << " " << fr_num << "\t\t\t\t\t\t " <<  oneThree[1].frame1 << "  " << oneThree[1].frame2;
			cout << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5 << endl;

			outputData.open("large_data_set.txt", ios::app);

			outputData << " " << fr_num << "\t\t\t\t\t\t " <<  oneThree[1].frame1 << "  " << oneThree[1].frame2;
			outputData << "  " << oneThree[1].frame3 << "  " << oneThree[1].frame4 << "  " << oneThree[1].frame5 << endl;

			outputData.close();

			}

			/*

			cout << endl << "frame_fault:  " << frame_fault << "frame reference:  " << dataSetTwo[n].frame_number << endl;
			cout << "frames " << oneThree[1].frame1 << "  ";
			cout << oneThree[1].frame2 << "  ";
			cout << oneThree[1].frame3 << "  ";
			cout << oneThree[1].frame4 << "  ";
			cout << oneThree[1].frame5 << "  " << endl;

			*/

			}

	} // end of for loop

	pageFaultFreq13 = (float)(frame_fault) / (float)(position2);

	cout << endl << " Data Set 2: RSS = 5 "  << endl;
	cout << " Total number of pages that were referenced:  " << position2 << endl;
	cout << " Number of Faults:  " << frame_fault << endl;
	cout << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	cout << " Number of times each page is referenced: " << endl;
	cout << " 0:  " << oneThree0 << endl;
	cout << " 1:  " << oneThree1 << endl;		
	cout << " 2:  " << oneThree2 << endl;
	cout << " 3:  " << oneThree3 << endl;
	cout << " 4:  " << oneThree4 << endl;
	cout << " 5:  " << oneThree5 << endl;		
	cout << " 6:  " << oneThree6 << endl;
	cout << " 7:  " << oneThree7 << endl;
	cout << " 8:  " << oneThree8 << endl;
	cout << " 9:  " << oneThree9 << endl;


	outputData.open("large_data_set.txt", ios::app);

	outputData << endl << " Data Set 2: RSS = 5 "  << endl;
	outputData << " Total number of pages that were referenced:  " << position2 << endl;
	outputData << " Number of Faults:  " << frame_fault << endl;
	outputData << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	outputData << " Number of times each page is referenced: " << endl;
	outputData << " 0:  " << oneThree0 << endl;
	outputData << " 1:  " << oneThree1 << endl;		
	outputData << " 2:  " << oneThree2 << endl;
	outputData << " 3:  " << oneThree3 << endl;
	outputData << " 4:  " << oneThree4 << endl;
	outputData << " 5:  " << oneThree5 << endl;		
	outputData << " 6:  " << oneThree6 << endl;
	outputData << " 7:  " << oneThree7 << endl;
	outputData << " 8:  " << oneThree8 << endl;
	outputData << " 9:  " << oneThree9 << endl;

	outputData.close();

	outputData.open("short_data_set.txt", ios::app);

	outputData << "************************************************************************ " << endl;
	outputData << endl << " Data Set 2: RSS = 5 "  << endl;
	outputData << " Total number of pages that were referenced:  " << position2 << endl;
	outputData << " Number of Faults:  " << frame_fault << endl;
	outputData << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	outputData << " Number of times each page is referenced: " << endl;
	outputData << " 0:  " << oneThree0 << endl;
	outputData << " 1:  " << oneThree1 << endl;		
	outputData << " 2:  " << oneThree2 << endl;
	outputData << " 3:  " << oneThree3 << endl;
	outputData << " 4:  " << oneThree4 << endl;
	outputData << " 5:  " << oneThree5 << endl;		
	outputData << " 6:  " << oneThree6 << endl;
	outputData << " 7:  " << oneThree7 << endl;
	outputData << " 8:  " << oneThree8 << endl;
	outputData << " 9:  " << oneThree9 << endl;

	outputData.close();

	//***********************************************************************************************

	// Data set 2 resident set size 7

	cout << endl << "************************************************************************ " << endl;
	cout << endl << " Data Set 2: RSS = 7 "  << endl << endl;

	outputData.open("short_data_set.txt", ios::app);

	outputData << endl << "************************************************************************ " << endl;
	outputData << endl << " Data Set 2: RSS = 7 "  << endl << endl;

	outputData.close();

	oneThree[1].frame1 = -1;
	oneThree[1].frame2 = -1;
	oneThree[1].frame3 = -1;
	oneThree[1].frame4 = -1;
	oneThree[1].frame5 = -1;
	oneThree[1].frame6 = -1;
	oneThree[1].frame7 = -1;

	next_page = true;
	frame_fault = 0;
	fill_pages = true;
	
	
	for (int n = 1; n <=position2 ; n++)     // lops thru the entire data set
	{

		fill_pages = true;
		page_fault_display = false;
	
		while (fill_pages == true)
		{
			if (oneThree[1].frame1 == -1)
			{
			oneThree[1].frame1 = dataSetTwo[n].frame_number;
			oneThree[1].frame1toggle = 1;
			frame_fault++;
			fill_pages = false;
		
			}

		
			if ((dataSetTwo[n].frame_number != oneThree[1].frame1) && (oneThree[1].frame2 == -1) && (fill_pages == true))
			{
				oneThree[1].frame2 = dataSetTwo[n].frame_number;
				oneThree[1].frame2toggle = 1;
				frame_fault++;
				fill_pages = false;
	
			}	
		

			if ((dataSetTwo[n].frame_number != oneThree[1].frame1) && (dataSetTwo[n].frame_number != oneThree[1].frame2)
				&& (oneThree[1].frame3 == -1) && (fill_pages == true))
			{
				oneThree[1].frame3 = dataSetTwo[n].frame_number;
				oneThree[1].frame3toggle = 1;
				frame_fault++;
				fill_pages = false;
	
			
			}

			if ((dataSetTwo[n].frame_number != oneThree[1].frame1) && (dataSetTwo[n].frame_number != oneThree[1].frame2)
				&& (dataSetTwo[n].frame_number != oneThree[1].frame3) && (oneThree[1].frame4 == -1) && (fill_pages == true))
			{
				oneThree[1].frame4 = dataSetTwo[n].frame_number;
				oneThree[1].frame4toggle = 1;
				frame_fault++;
				fill_pages = false;
				

			}

			if ((dataSetTwo[n].frame_number != oneThree[1].frame1) && (dataSetTwo[n].frame_number != oneThree[1].frame2)
				&& (dataSetTwo[n].frame_number != oneThree[1].frame3) && (dataSetTwo[n].frame_number != oneThree[1].frame4)
				&& (oneThree[1].frame5 == -1) && (fill_pages == true))
			{
				oneThree[1].frame5 = dataSetTwo[n].frame_number;
				oneThree[1].frame5toggle = 1;
				frame_fault++;
				fill_pages = false;
				

			}

			if ((dataSetTwo[n].frame_number != oneThree[1].frame1) && (dataSetTwo[n].frame_number != oneThree[1].frame2)
				&& (dataSetTwo[n].frame_number != oneThree[1].frame3) && (dataSetTwo[n].frame_number != oneThree[1].frame4)
				&& (dataSetTwo[n].frame_number != oneThree[1].frame5) && (oneThree[1].frame6 == -1) && (fill_pages == true))
			{
				oneThree[1].frame6 = dataSetTwo[n].frame_number;
				oneThree[1].frame6toggle = 1;
				frame_fault++;
				fill_pages = false;
		

			}

			if ((dataSetTwo[n].frame_number != oneThree[1].frame1) && (dataSetTwo[n].frame_number != oneThree[1].frame2)
				&& (dataSetTwo[n].frame_number != oneThree[1].frame3) && (dataSetTwo[n].frame_number != oneThree[1].frame4)
				&& (dataSetTwo[n].frame_number != oneThree[1].frame5) && (dataSetTwo[n].frame_number != oneThree[1].frame6)
				&& (oneThree[1].frame7 == -1) && (fill_pages ==true))
			{
				oneThree[1].frame7 = dataSetTwo[n].frame_number;
				oneThree[1].frame7toggle = 1;
				frame_fault++;
				fill_pages = false;


			}

			fill_pages = false;

			

		}//end of the while loop fill pages

		if ((fill_pages == false) && (frame_fault >= 7))
		{

		looking_frame = true;
		fr_num = dataSetTwo[n].frame_number;
		page_fault = false;	

		while (looking_frame == true)
			{
				if (fr_num == oneThree[1].frame1)  // Check frame 1
				{
				oneThree[1].frame1toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame1toggle = 0;
				}

				if ((fr_num == oneThree[1].frame2) && (looking_frame == true))   // check frame 2
				{
				oneThree[1].frame2toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame2toggle = 0;
				}

				if ((fr_num == oneThree[1].frame3) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame3toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame3toggle = 0;
				}

				if ((fr_num == oneThree[1].frame4) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame4toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame4toggle = 0;
				}

				if ((fr_num == oneThree[1].frame5) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame5toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame5toggle = 0;
				}

				if ((fr_num == oneThree[1].frame6) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame6toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame6toggle = 0;
				}

				if ((fr_num == oneThree[1].frame7) && (looking_frame == true))    // check frame 3
				{
				oneThree[1].frame7toggle = 1;
				looking_frame = false;
				}
				else
				{
				oneThree[1].frame7toggle = 0;
				}

		
				if (looking_frame == true)
				{
					looking_frame = false;
					frame_fault++;
					page_fault = true;
				}

		} // end of the while loop

		while (page_fault == true)
			{
				if (oneThree[1].frame1toggle == 0)
				{
					
					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					oneThree[1].frame3 = oneThree[1].frame4;
					oneThree[1].frame3toggle = oneThree[1].frame4toggle;

					oneThree[1].frame4 = oneThree[1].frame5;
					oneThree[1].frame4toggle = oneThree[1].frame5toggle;

					oneThree[1].frame5 = oneThree[1].frame6;
					oneThree[1].frame5toggle = oneThree[1].frame6toggle;

					oneThree[1].frame6 = oneThree[1].frame7;
					oneThree[1].frame6toggle = oneThree[1].frame7toggle;

					page_fault = false;
					  

				}
				
				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;

					oneThree[1].frame6 = oneThree[1].frame1;
					oneThree[1].frame6toggle = oneThree[1].frame1toggle;

					oneThree[1].frame1 = oneThree[1].frame3;
					oneThree[1].frame1toggle = oneThree[1].frame3toggle;

					oneThree[1].frame2 = oneThree[1].frame4;
					oneThree[1].frame2toggle = oneThree[1].frame4toggle;

					oneThree[1].frame3 = oneThree[1].frame5;
					oneThree[1].frame3toggle = oneThree[1].frame5toggle;

					oneThree[1].frame4 = oneThree[1].frame6;
					oneThree[1].frame4toggle = oneThree[1].frame6toggle;

					oneThree[1].frame5 = oneThree[1].frame7;
					oneThree[1].frame5toggle = oneThree[1].frame7toggle;

					page_fault = false;

				}

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) 
					&& (oneThree[1].frame3toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;

					oneThree[1].frame5 = oneThree[1].frame1;
					oneThree[1].frame5toggle = oneThree[1].frame1toggle;

					oneThree[1].frame6 = oneThree[1].frame2;
					oneThree[1].frame6toggle = oneThree[1].frame2toggle;

					oneThree[1].frame1 = oneThree[1].frame4;
					oneThree[1].frame1toggle = oneThree[1].frame4toggle;

					oneThree[1].frame2 = oneThree[1].frame5;
					oneThree[1].frame2toggle = oneThree[1].frame5toggle;

					oneThree[1].frame3 = oneThree[1].frame6;
					oneThree[1].frame3toggle = oneThree[1].frame6toggle;

					oneThree[1].frame4 = oneThree[1].frame7;
					oneThree[1].frame4toggle = oneThree[1].frame7toggle;

					page_fault = false;

				}
			
				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) 
					&& (oneThree[1].frame3toggle == 1) && (oneThree[1].frame4toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;

					oneThree[1].frame1 = oneThree[1].frame5;
					oneThree[1].frame1toggle = oneThree[1].frame5toggle;

					oneThree[1].frame2 = oneThree[1].frame1;
					oneThree[1].frame2toggle = oneThree[1].frame1toggle;

					oneThree[1].frame3 = oneThree[1].frame2;
					oneThree[1].frame3toggle = oneThree[1].frame2toggle;

					oneThree[1].frame4 = oneThree[1].frame3;
					oneThree[1].frame4toggle = oneThree[1].frame3toggle;

					page_fault = false;

				}

				

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) && (oneThree[1].frame3toggle == 1)
					 && (oneThree[1].frame4toggle == 1) && (oneThree[1].frame5toggle == 0) && (page_fault == true))
				{
					
					oneThree[1].frame1toggle = 0;
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;
					oneThree[1].frame4toggle = 0;


					oneThree[1].frame1 = oneThree[1].frame6;
					oneThree[1].frame1toggle = oneThree[1].frame6toggle;

					oneThree[1].frame2 = oneThree[1].frame7;
					oneThree[1].frame2toggle = oneThree[1].frame7toggle;

					oneThree[1].frame3 = oneThree[1].frame1;
					oneThree[1].frame3toggle = oneThree[1].frame1toggle;

					oneThree[1].frame4 = oneThree[1].frame2;
					oneThree[1].frame4toggle = oneThree[1].frame2toggle;

					oneThree[1].frame5 = oneThree[1].frame3;
					oneThree[1].frame5toggle = oneThree[1].frame3toggle;

					oneThree[1].frame6 = oneThree[1].frame4;
					oneThree[1].frame6toggle = oneThree[1].frame4toggle;


					page_fault = false;

				}

				// I don't think frame 7 can ever have a toggle of 0, therfore I didn't make a if statement for frame5toggle

				if ((oneThree[1].frame1toggle == 1) && (oneThree[1].frame2toggle == 1) && (oneThree[1].frame3toggle == 1)
					 && (oneThree[1].frame4toggle == 1) && (oneThree[1].frame5toggle == 1) && (oneThree[1].frame6toggle == 1) 
					 && (page_fault == true))
				{
					
					oneThree[1].frame2toggle = 0;
					oneThree[1].frame3toggle = 0;
					oneThree[1].frame4toggle = 0;
					oneThree[1].frame5toggle = 0;
					oneThree[1].frame5toggle = 0;

					oneThree[1].frame1 = oneThree[1].frame2;
					oneThree[1].frame1toggle = oneThree[1].frame2toggle;

					oneThree[1].frame2 = oneThree[1].frame3;
					oneThree[1].frame2toggle = oneThree[1].frame3toggle;

					oneThree[1].frame3 = oneThree[1].frame4;
					oneThree[1].frame3toggle = oneThree[1].frame4toggle;

					oneThree[1].frame4 = oneThree[1].frame5;
					oneThree[1].frame4toggle = oneThree[1].frame5toggle;

					oneThree[1].frame5 = oneThree[1].frame6;
					oneThree[1].frame5toggle = oneThree[1].frame6toggle;

					oneThree[1].frame6 = oneThree[1].frame7;
					oneThree[1].frame6toggle = oneThree[1].frame7toggle;

					page_fault = false;

				}
				if (page_fault == true)
				{
					cout << endl << "Page fault error" << endl;
					page_fault = false;
				}

				oneThree[1].frame7 = fr_num;
				oneThree[1].frame7toggle = 1;


			}  // end of while loop

		}
		/*
			cout << endl << "frame_fault:  " << frame_fault << "frame reference:  " << dataSetTwo[n].frame_number << endl;
			cout << "frames " << oneThree[1].frame1 << "  ";
			cout << oneThree[1].frame2 << "  ";
			cout << oneThree[1].frame3 << "  ";
			cout << oneThree[1].frame4 << "  ";
			cout << oneThree[1].frame5 << "  ";
			cout << oneThree[1].frame6 << "  ";
			cout << oneThree[1].frame7 << "  " << endl;

			*/

	} // end of for loop

		
		pageFaultFreq13 = (float)(frame_fault) / (float)(position);



	cout << " Total number of pages that were referenced:  " <<position2 << endl;
	cout << " Number of Faults:  " << frame_fault << endl;
	cout << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	cout << " Number of times each page is referenced: " << endl;
	cout << " 0:  " << oneThree0 << endl;
	cout << " 1:  " << oneThree1 << endl;		
	cout << " 2:  " << oneThree2 << endl;
	cout << " 3:  " << oneThree3 << endl;
	cout << " 4:  " << oneThree4 << endl;
	cout << " 5:  " << oneThree5 << endl;		
	cout << " 6:  " << oneThree6 << endl;
	cout << " 7:  " << oneThree7 << endl;
	cout << " 8:  " << oneThree8 << endl;
	cout << " 9:  " << oneThree9 << endl;
	
	outputData.open("short_data_set.txt", ios::app);

	outputData << " Total number of pages that were referenced:  " <<position2 << endl;
	outputData << " Number of Faults:  " << frame_fault << endl;
	outputData << " Page Fault Frequency:  " << (pageFaultFreq13 * 100) << " %" << endl;
	outputData << " Number of times each page is referenced: " << endl;
	outputData << " 0:  " << oneThree0 << endl;
	outputData << " 1:  " << oneThree1 << endl;		
	outputData << " 2:  " << oneThree2 << endl;
	outputData << " 3:  " << oneThree3 << endl;
	outputData << " 4:  " << oneThree4 << endl;
	outputData << " 5:  " << oneThree5 << endl;		
	outputData << " 6:  " << oneThree6 << endl;
	outputData << " 7:  " << oneThree7 << endl;
	outputData << " 8:  " << oneThree8 << endl;
	outputData << " 9:  " << oneThree9 << endl;

	outputData.close();

		system("pause");
		
	return 0;
	
}

