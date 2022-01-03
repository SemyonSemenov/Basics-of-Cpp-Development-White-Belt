#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
using namespace std;

class Person {
public:
  Person(string first_name, string last_name, int year){
	  first_names[year] = first_name;
	  last_names[year] = last_name;
	  birth_year = year;
  }

  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  if(year >= birth_year){
		  first_names[year] = first_name;
	  }

  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  if(year >= birth_year){
		  last_names[year] = last_name;
	  }

  }
  string GetFullName(int year) const {
    // получить имя и фамилию по состоянию на конец года year
	  if(year < birth_year){
		  return "No person";
	  }
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
  string GetFullNameWithHistory(int year) const {
  	  // получить все имена и фамилии по состоянию на конец года year
	  if(year < birth_year){
		  return "No person";
	  }
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
  int birth_year;
};


int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}

