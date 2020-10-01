/*  Valeria Frolova, UVic
	Sep 23, 2020
	
	Function is used to find sequence in a string and replace it with another sequence.
	Simply an implementation, not tested yet
	*/
bool ReplaceWith(char* toModify, const char* toFind, const char* replaceWith){
	/*In-place substitution is not required (as stated).
	  Libraries for substitution and concatenation not used, 
	  such as memcpy, strcpy, strcat.
	
	
	  Firstly, we can allocate arbitrarily big 2nd string. 
	  We could also have dynamic allocation, where string will grow as it approaches the end. 
	  Third option is to calculate exactly how big the 2nd string would be.
	  This may require extra computation, but I'm curious to try the latter.
	  >> introducing "int numOccurrences()"
	*/
	
	if(toModify.find(toFind,pos)==string::npos)//no substring found
		return false; 
		
	int count = numOccurrences(toModify, toFind);
	//len will work even if "replaceWith" is smaller than "toFind"
	int len=length(toModify)+count*(length(replaceWith)-length(toFind));
	char *str2[len];
	memset(str2,0x00,len);
	int pos=0, k, j=0, i=0;
	
	while(1){
		pos=find(toModify,pos); //we have a match: assigning starting position index
		str2[j]=toModify[i]; //copy "free" chars from original string
		i++;
		j++;
		if (toModify[i]='\0') //if we reached EOL, break the loop and return true
			break;
		if(i==pos){ //when "i" reaches starting index of our match..
			//kick "i" aside. E.g., if "i" is at first "z" in "pizza", move it to "a"
			i+=length(toFind);
			for(k=0;k<length(replaceWith);k++){//actual substitution
				str2[j]=replaceWith[k];
				j++;
			}
			pos=i; //now update starting position to search at (required in line 10)
		}
	}
	return true; //shouldn't return pointer to a new array (str2)?
}
int numOccurrences(char* string, char* seq){
	int pos=0;
	int count=0;
	while (string.find(seq,pos)!=string::npos){//until no more matches left
		pos=string.find(seq,pos);		
		count++;//update occurrence count
		pos+=length(seq); //jump after sequence to start new search
	}
	return count;
}