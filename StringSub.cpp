#include <string>
#include <algorithm>    // std::find
#include <string>
/*  Valeria Frolova, UVic
	Sep 23, 2020
	
	Function is used to find sequence in a string and replace it with another sequence.
	Simply an implementation, not tested yet
	*/

bool ReplaceWith(const char* toModify, const char* toFind, const char* replaceWith){
	/*In-place substitution is not required (as stated).
	  Libraries for substitution and concatenation not used, 
	  such as memcpy, strcpy, strcat.
	
	
	  Firstly, we can allocate arbitrarily big 2nd string. 
	  We could also have dynamic allocation, where string will grow as it approaches the end. 
	  Third option is to calculate exactly how big the 2nd string would be.
	  This may require extra computation, but I'm curious to try the latter.
	  >> introducing "int numOccurrences()"
	*/
	std::string Modify(toModify);
	std::string Find(toFind);
	std::string repWith(replaceWith);

	int pos=0;
	if(Modify.find(Find,pos)==-1)//no substring found
		return false; 
		
	int count = numOccurrences(Modify, toFind);
	//len will work even if "replaceWith" is smaller than "toFind"
	int len=length(Modify)+count*(length(repWith)-length(Find));
	char* str2=(char*)malloc(sizeof(char)*len);
	int k, j=0, i=0;
	
	while(1){
		pos=find(Modify,pos); //we have a match: assigning starting position index
		str2[j]=Modify[i]; //copy "free" chars from original string
		i++;
		j++;
		if (Modify[i]='\0') //if we reached EOL, break the loop and return true
			break;
		if(i==pos){ //when "i" reaches starting index of our match..
			//kick "i" aside. E.g., if "i" is at first "z" in "pizza", move it to "a"
			i+=length(Find);
			for(k=0;k<length(repWith);k++){//actual substitution
				str2[j]=repWith[k];
				j++;
			}
			pos=i; //now update starting position to search at (required in line 10)
		}
	}
	return true; //shouldn't return pointer to a new array (str2)?
}
int numOccurrences(string str, string seq) {
	int pos = 0;
	int count = 0;
	while (str.find(seq, pos) != string::npos) {//until no more matches left
		pos = str.find(seq, pos);
		count++;//update occurrence count
		pos += length(seq); //jump after sequence to start new search
	}
	return count;
}
