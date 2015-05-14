/*
 * ReviewCleaner.cpp
 *
 *  Created on: May 13, 2015
 *      Author: fran
 */

#include "ReviewCleaner.h"
#include "FileHandler.h"


namespace std {

ReviewCleaner::ReviewCleaner() {
	// TODO Auto-generated constructor stub
	FileHandler fileHandler;
	stopwords = fileHandler.readFile("stop-words.txt");

	for (int x=0; x < stopwords.size();x++){
		trim(stopwords[x]);
	}

}

ReviewCleaner::~ReviewCleaner() {
	// TODO Auto-generated destructor stub
}


void ReviewCleaner::trim(string& s){
	const string& delimiters = " \f\n\r\t\v";
    s.erase( s.find_last_not_of( delimiters ) + 1 ).erase( 0, s.erase( s.find_last_not_of( delimiters ) + 1 ).find_first_not_of( delimiters ) );
}

string ReviewCleaner::removerSubstringsDeString(string s,string t){ //s: substring a remover , t:string original
	string::size_type i = t.find(s);

	while (i != string::npos){
	   t.erase(i,s.size());
	   i = t.find(s);
	}


	return t;
}
string ReviewCleaner::cleanReview(string review){

	string reviewLimpia = "";
	string html= "<br /";
	review = removerSubstringsDeString(html,review);
	for (int x=0;x<review.size();x++){
		if (!ispunct(review.at(x)) && !isdigit(review.at(x)))
			if(review.at(x)>='A' && review.at(x)<= 'Z')
				reviewLimpia+= (review.at(x) + ('a'-'A'));
			else
    			reviewLimpia+= review.at(x);

	}

	stringstream nuevaReview;
	nuevaReview.str(""); //Vacia le buffer
	copy(string_token_iterator(reviewLimpia),string_token_iterator(),ostream_iterator <string> (nuevaReview,"\n"));

	//Elimino las stopwords
	string reviewFinal = " ";
	bool esUnaStopword;

	string palabraTokenizada;
	while (nuevaReview >> palabraTokenizada){
		esUnaStopword = false;
		for (int x=0;x<stopwords.size() && !esUnaStopword;x++){
			if (palabraTokenizada == stopwords[x] || palabraTokenizada == "a"){
					esUnaStopword = true;
			}
		}
		if (!esUnaStopword){
			reviewFinal.append(palabraTokenizada);
		}

	}


	return reviewFinal;
	}
}
