//

#include <iostream>

using namespace std;

class stackException{
private:
	string errMsg;
	
public:
	
	stackException(const string& err){
		errMsg=(err);
	}
	
	string getError(){
		return errMsg;
	}
};