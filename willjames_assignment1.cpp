// code for assignment 1
#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <cstdlib>
#include <cmath>


using namespace std;
     

int main(int argc, char *argv[])
{
	

	//initiate variables
	ifstream dnaFile;
	string newInFile = "";
	int choice2 = 1;
	bool choice = true;
	//while loop that for asking if you want to restart program
	while (choice == true)
	{  
		if(choice2 == 1)
		{
			        //create file stream for inputing text file
			dnaFile.open(argv[1]); //open file with ifstream for command prompt
		}
		else if (choice2 ==2)
		{
			dnaFile.open(newInFile.c_str());	
		}
		bool isOpen = dnaFile.is_open();   //creates bool that checks if file is open
		if(!isOpen) //quit if not open
		{
			return 0;//quit	
		}
		//create variables
		 using std::toupper;
		 string temp;
		 string line;
		 int lineCount = 0; //counts number of lines
		 char letter;
		 float probA = 0;  //variables for counting probability of nucleotides
		 float probT = 0;
		 float probC = 0;
		 float probG = 0;
		 float probAA = 0; //probabaility of bigrams
		 float probAT = 0;
		 float probAG = 0;
		 float probAC = 0;
		 float probGG = 0;
		 float probGT = 0;
		 float probGC = 0;
		 float probGA = 0;
		 float probCC = 0;
		 float probCA = 0;
		 float probCT = 0;
		 float probCG = 0;
		 float probTT = 0;
		 float probTG = 0;
		 float probTC = 0;
		 float probTA = 0;
		 int theA = 0;
		 int theC = 0;
		 int theG = 0;
		 int theT = 0;//counts sum of each nucleotide
		 //biogram sums
		 int aa = 0;
		 int ag = 0;
		 int at = 0;
		 int ac = 0;
		 int gg = 0;
		 int ga = 0;
		 int gc = 0;
		 int gt = 0;
		 int cc = 0;
		 int ct = 0;
		 int ca = 0;
		 int cg = 0;
		 int tt = 0;
		 int tc = 0;
		 int tg = 0;
		 int ta = 0;
		 int countN = 0; //count of nucleotides
		 int countB = 0; // count of biograms
		 int sum = 0;
		 //sort file line by line
		 while(std::getline(dnaFile,temp))
		 {
			 lineCount++; //counts number of lines
			 //checking each char in line
			sum += temp.size();
			for (int i = 0; i < temp.length(); ++i)
			{
				//cout << "line"; //testing
				letter = temp[i]; // sets each char to letter
				letter = toupper(letter);
				//if letter is A add to theA and add one to countN
				if (letter == 'A')
				{
					theA++;
					countN++;	
				}
				//if letter is G add to theG and add one to countN
				else if (letter == 'G')
				{
					theG++;
					countN++;
				}
				//if letter is T add to theT and add one to countN
				else if (letter == 'T')
				{
					theT++;
					countN++;
				}
				//if letter is C add to theC and add one to countN
				else if (letter == 'C')
				{
					theC++;
					countN++;
				}
				
			 }
			//new string of size of temp string 
			string str[temp.size()];
			//storing 
			
			string storageString = temp; //not sure yet
			//loop through e
			for (int j = 0; j < storageString.length(); ++j)
			{
				//first char
				char  nextN = storageString[j];
				//make uppercase
				nextN = toupper(nextN);
				//second char
				char  secondN = storageString[++j];
				//make upper case
				secondN = toupper(secondN);
				//if both chars == A add to aa count and add to countB
				if ( nextN == 'A' && secondN == 'A')
				{
					aa++;
					countB++;
				}
				//if char1 is A and char2 is C, add to ac and add to countB
				else if ( nextN == 'A' && secondN == 'C')
				{
					ac++;
					countB++;
				}
				//if char1 is A and char2 is C, add to ac and add to countB
				else if ( nextN == 'A' && secondN == 'T')
				{
					at++;
					countB++;
				}
				//if char1 is A and char2 is G, add to ag and add to countB
				else if ( nextN == 'A' && secondN == 'G')
				{
					ag++;
					countB++;
				}
				//if both chars == G add to gg count and add to countB
				else if ( nextN == 'G' && secondN == 'G')
				{
					gg++;
					countB++;
				}
				//if char1 is G and char2 is A, add to ga and add to countB
				else if ( nextN == 'G' && secondN == 'A')
				{
					ga++;
					countB++;
				}
				//if char1 is A and char2 is C, add to ac and add to countB
				else if ( nextN == 'G' && secondN == 'T')
				{
					gt++;
					countB++;
				}
				//if char1 is G and char2 is C, add to gc and add to countB
				else if ( nextN == 'G' && secondN == 'C')
				{
					gc++;
					countB++;
				}
				//if both chars == C add to cc count and add to countB
				else if ( nextN == 'C' && secondN == 'C')
				{
					cc++;
					countB++;
				}
				//if char1 is C and char2 is A, add to ca and add to countB
				else if ( nextN == 'C' && secondN == 'A')
				{
					ca++;
					countB++;
				}
				//if char1 is C and char2 is T, add to ct and add to countB
				else if ( nextN == 'C' && secondN == 'T')
				{
					ct++;
					countB++;
				}
				//if char1 is C and char2 is G, add to gc and add to countB
				else if ( nextN == 'C' && secondN == 'G')
				{
					cg++;
					countB++;
				}
				//if both chars == T add to tt count and add to countB
				else if ( nextN == 'T' && secondN == 'T')
				{
					tt++;
					countB++;
				}
				//if char1 is T and char2 is A, add to ta and add to countB
				else if ( nextN == 'T' && secondN == 'A')
				{
					ta++;
					countB++;
				}
				//if char1 is T and char2 is G, add to tg and add to countB
				else if ( nextN == 'T' && secondN == 'G')
				{
					tg++;
					countB++;
				}
				//if char1 is T and char2 is C, add to tc and add to countB
				else if ( nextN == 'T' && secondN == 'C')
				{
					tc++;
					countB++;
				}
				
			} 
			
			
			
			
		 }	
		 
		 
		 //calculating probability of nucleotides
		 probA = float(theA) / float(countN); 
		 probG = float(theG) / float(countN); 
		 probC = float(theC) / float(countN); 
		 probT = float(theT) / float(countN); 
		 
		 // calculate probabaility of bigrams
		 probAA = float(aa) / float(countB);
		 probAC = float(ac) / float(countB);
		 probAG = float(ag) / float(countB);
		 probAT = float(at) / float(countB);
		 probGG = float(gg) / float(countB);
		 probGC = float(gc) / float(countB);
		 probGT = float(gt) / float(countB);
		 probGA = float(ga) / float(countB);
		 probCC = float(cc) / float(countB);
		 probCG = float(cg) / float(countB);
		 probCT = float(ct) / float(countB);
		 probCA = float(ca) / float(countB);
		 probTT = float(tt) / float(countB);
		 probTA = float(ta) / float(countB);
		 probTG = float(tg) / float(countB);
		 probTC = float(tc) / float(countB);
		 //mean
		 float mean = 0;
		 mean = float(sum) / float(lineCount);
		 //for variance
		 float theVariance = 0;
		 
		 float accVariance = 0;
		 // the variance is (length of temp string - mean) squared
		 theVariance= pow(temp.length() - mean ,2); 
		 theVariance = float(theVariance);
		 //calculating accumulted variance
		 accVariance += theVariance;
		 //calculating final variance
		 float finalVariance = 0;
		 finalVariance = accVariance/lineCount;
		 
		 
		//calculate standard deviation
		 float standardDeviation = 0;
		 standardDeviation = sqrt(finalVariance);
		 
		  //close file so we can create new outfile
		 dnaFile.close();
		 ofstream outFile;
		
		 if (choice2 ==1)
		 {
			 outFile.open("willjames.out");
			 if (outFile.is_open())
			 {
				 outFile << "William James \n 1905095 \n Assignment1" << endl;
				 outFile << "Sum: " << sum << " Mean:" << mean << " Standard Deviation: " << standardDeviation << " Variance: " << theVariance << endl;
				 outFile << "Probability of A: " << probA << " Probability of C: " << probC << " Probability of G: " << probG << " Probability of T: " << probT << endl;
				 outFile << " Probability of AA: " << probAA << " Probability of AA: " << probAA << " Probability of AG: " << probAG << " Probability of AT: " << probAT << endl;
				 outFile << " Probability of CC: " << probCC << " Probability of CA: " << probCA << " Probability of CG: " << probCG << " Probability of CT: " << probCT << endl;
				 outFile << " Probability of GG: " << probGG << " Probability of GA: " << probGA << " Probability of GC: " << probGC << " Probability of GT: " << probGT << endl;
				 outFile << " Probability of TT: " << probTT << " Probability of TA: " << probTA << " Probability of TG: " << probTG << " Probability of TC: " << probTC << endl;
			 }
		  }
		 //create boolean if file is open
		 if(choice2 == 2)
		 {
		 	 outFile.open("willjames.out", ios::app);
			 //if file is open append results to to willjames.out
			 if (outFile.is_open())
			 {
				 outFile << "Sum: " << sum << " Mean:" << mean << " Standard Deviation: " << standardDeviation << " Variance: " << theVariance << endl;
				 outFile << "Probability of A: " << probA << " Probability of C: " << probC << " Probability of G: " << probG << " Probability of T: " << probT << endl;
				 outFile << " Probability of AA: " << probAA << " Probability of AA: " << probAA << " Probability of AG: " << probAG << " Probability of AT: " << probAT << endl;
				 outFile << " Probability of CC: " << probCC << " Probability of CA: " << probCA << " Probability of CG: " << probCG << " Probability of CT: " << probCT << endl;
				 outFile << " Probability of GG: " << probGG << " Probability of GA: " << probGA << " Probability of GC: " << probGC << " Probability of GT: " << probGT << endl;
				 outFile << " Probability of TT: " << probTT << " Probability of TA: " << probTA << " Probability of TG: " << probTG << " Probability of TC: " << probTC << endl;
			 }
		 }
		  outFile.close();
		  outFile.open("willjames.out", ios::app);
		  //rand max
		  float a = ((float)rand() / float((RAND_MAX))); //RAND_MAX 
		  float b = ((float)rand() / float((RAND_MAX))); //RAND_MAX
		  float c = 0;
		  float logA = 0;
		  //log of a
		  logA = log(a);
		  //calculating equation inside of cosine function
		  float tester = 0;
		  //converting degrees to radians
		  tester = (6.28*b); //*3.14)/180
		  //ocsine of tester
		  float cosine = 0;
		  cosine = cos(tester);
		  //eqaution for c
		  c = sqrt((-2 *(logA ))*cosine); 
		  float gaussian = 0;
		  //get gaussian 
		  gaussian = ((c*standardDeviation) + mean);
		  
		  //new probabilities
		  float newPA = 0;
		  float newPC = 0;
		  float newPG = 0;
		  float newPT = 0;
		  newPA = probA;
		  newPT = newPA + probT;
		  newPC = newPT + probC;
		  newPG = newPC + probG;
		  
		  //loop through 100 times
		  for (int k = 0; k < 1000; ++k )
		  {
		  	  //get random numbers again and gaussian
		  	  float a = ((float)rand() / float((RAND_MAX))); //RAND_MAX 
		  	  float b = ((float)rand() / float((RAND_MAX))); //RAND_MAX
		  	  
			 
			  //calculating equation inside of cosine function
			  float tester = 0;
			  //converting degrees to radians
			  tester = (6.28*b); //*3.14)/180)
			  //ocsine of tester
			  float cosine = 0;
			  cosine = cos(tester);
			  //eqaution for c
			  c = sqrt((-2 *(log(a) ))*cosine); 
		  	  gaussian = ((c*standardDeviation) + mean);		  		  
			  //create new string 
			  string newSequence = "";
			  //loop through length of gaussian
			  for(int  l =0; l < gaussian; ++l )
			  {
			  	  //random number generator
				  float randomNum = ((float)rand() / float((RAND_MAX)));
				  //add A to newsequence if new probabaility is bigger than random
				  if (randomNum < newPA)
				  {
					  newSequence += 'A';
				  }
				  //add T to newsequence if new probabaility is bigger than random
				  else if (randomNum < newPT)
				  {
					  newSequence += 'T';
				  }
				  //add C to newsequence if new probabaility is bigger than random
				  else if (randomNum < newPC)
				  {
					  newSequence += 'C';
				  }
				  //add G to newsequence if new probabaility is bigger than random
				  else if (randomNum < newPG)
				  {	  
					  newSequence += 'G';
				  }
				  
				  
			  }
			  		//putting it to the outfile
			  		newSequence += '\n';
			  		outFile.open("willjames.out",std::ios::app);
			  		outFile << newSequence;
			  		outFile.close();
				  	 
			  
		}
		//ask user to repeat program?
		cout << "do you want to repeat program? 1 = yes, anything else = no" << endl;
		int answer = 0;
		//take in user input
		cin >> answer;
		if (answer == 1)
		{
	
		//set choice to true
		choice = true;
		//ask user for name of text file
		cout << "what is the name of the new text file(don't need the .txt)?";
		cin >> newInFile;
		//add .text file to name of file
		newInFile.append(".txt");
		bool checker = true;
		choice2 = 2;
		
		}
		//not user doesnt enter 1 program will end
		else
		{
			//set choice to false
			choice = false;
		}
	}
	 
}

