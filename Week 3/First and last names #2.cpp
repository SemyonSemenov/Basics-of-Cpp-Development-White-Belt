#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  last_names[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
	  string first_name = "";
	  string last_name = "";

	  for (auto const &pair: first_names) {
		  if(pair.first <= year){
			  first_name = pair.second;
		  }
	  }
	  for (auto const &pair: last_names) {
		  if(pair.first <= year){
			  last_name = pair.second;
	  	  }
	  }
	  if (first_name == "" && last_name == ""){
		  return "Incognito";
	  }
	  else if(first_name == "" && last_name != ""){
		  return last_name + " with unknown first name";
	  }
	  else if(first_name != "" && last_name == ""){
		  return first_name + " with unknown last name";
	  }
	  else{
		  return first_name + " " + last_name;
	  }
  }
  string GetFullNameWithHistory(int year) {
  	  // получить все имена и фамилии по состоянию на конец года year
	  string first_name = "";
	  string first_names_history = "";
	  for (auto const &pair: first_names) {
		  if(pair.first <= year){
			  if (first_name == ""){
				  first_name = pair.second;
			  }
			  else{
				  if (first_name != pair.second){
					  if (first_names_history == ""){
						  first_names_history += first_name;
					  }
					  else{
						  first_names_history = first_name + ", " + first_names_history;
					  }
				  }
				  first_name = pair.second;
			  }
		  }
	  }

	  string last_name = "";
	  string last_names_history = "";
	  for (auto const &pair: last_names) {
		  if(pair.first <= year){
			  if (last_name == ""){
				  last_name = pair.second;
			  }
			  else{
				  if (last_name != pair.second){
					  if (last_names_history == ""){
						  last_names_history += last_name;
					  }
					  else{
						  last_names_history = last_name + ", " + last_names_history;
					  }
				  }
				  last_name = pair.second;
			  }
		  }
	  }

	  if (first_name == "" && last_name == ""){
		  return "Incognito";
	  }
	  else if(first_name == "" && last_name != ""){
		  if (last_names_history == ""){
			  return last_name + " with unknown first name";
		  }
		  return last_name + " (" + last_names_history + ") " + "with unknown first name";
	  }
	  else if(first_name != "" && last_name == ""){
		  if (first_names_history == ""){
			  return first_name + " with unknown last name";
		  }
		  return first_name + " (" + first_names_history + ") " + "with unknown last name";
	  }
	  else{
		  if(first_names_history != "" && last_names_history == ""){
			  return first_name + " (" + first_names_history + ") " + last_name;
		  }
		  else if(first_names_history == "" && last_names_history != ""){
			  return first_name + " " + last_name + " (" + last_names_history + ")";
		  }
		  else if(first_names_history == "" && last_names_history == ""){
			  return first_name + " " + last_name;
		  }
		  return first_name + " (" + first_names_history + ") " + last_name + " (" + last_names_history + ")";
	  }
  }
private:
  // приватные поля
  map<int, string> first_names;
  map<int, string> last_names;
};


int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}
