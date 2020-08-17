#include<iostream>
#include"Date.hpp"
#include<string>
#include <sstream>
#include<vector>
#include<math.h>

using namespace std;

/**
* @brief default constructor
*/
Date::Date(){  
  m_year = 0;
  m_month = 0;
  m_day = 0;
  m_hour = 0;
  m_minute = 0;
}

/**
* @brief constructor with arguments
*/
Date::Date(int t_year, int t_month, int t_day, int t_hour, int t_minute)
{
  this->m_year = t_year;
  this->m_month = t_month;
  this->m_day = t_day;
  this->m_hour = t_hour;
  this->m_minute = t_minute;
}

/**
* @brief constructor with a string
*/
Date::Date(const string& dataString){
   string temp_str;
   int my_follow = 1;
   int len = dataString.szie();
   if(len != 16){
    my_follow = 0;
   }
   if(dateString[4] != '-'){
    my_follow = 0;
   }
  if(dateString[7] != '-'){
    my_follow = 0;
   }
  if(dateString[10] != '/'){
    my_follow = 0;
   }
  if(dateString[13] != ':'){
    my_follow = 0;
   }
    for(int count = 0; count < 4; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
    my_follow = 0;
   }
  }
  for(int count = 5; count < 7; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
    my_follow = 0;
   }
  }
  for(int count = 8; count < 10; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
    my_follow = 0;
   }
  }
  for(int count = 11; count < 13; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
    my_follow = 0;
   }
  }
  for(int count = 14; count < 16; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
     my_follow = 0;
   }
  }
   if(my_follow == 0)
   { 
     this->m_year = 0;
     this->m_month = 0;
     this->m_day = 0;
     this->m_hour = 0;
     this->m_minute = 0;
   }
   else{
     stringstream ss;
     int year1, month1, day1, hour1, minute1;
     char pun;
     ss << dateString;
     ss >> year1 >> pun >> month1 >> pun >> day1 >> pun >> hour1 >> pun >> minute1;
     this->m_year = year1;
     this->m_month = month1;
     this->m_day = day1;
     this->m_hour = hour1;
     this->m_minute = minute1;
    }
}

/**
  * @brief return the year of a Date
  * @return   a integer indicate the year of a date
  */
int Date::getYear(void) const
{
  return m_year;
}

/**
* @brief set the year of a date
* @param a integer indicate the new year of a date
*/
void Date::setYear(const int t_year){
  m_year = t_y;
}

/**
* @brief return the month of a Date
* @return   a integer indicate the month of a date
*/
int Date::getMonth(void) const
{
  return m_month;
}

/**
* @brief set the month of a date
* @param a integer indicate the new month of a date
*/
void Date::setMonth(const int t_month)
{
  m_month = t_m;
}

/**
* @brief return the day of a Date
* @return   a integer indicate the day of a date
*/
int Date::getDay(void) const
{
  return m_day;
}

/**
* @brief set the day of a date
* @param a integer indicate the new day of a date
*/
void Date::setDay(const int t_day)
{
  m_day = t_d;
}

/**
* @brief return the hour of a Date
* @return   a integer indicate the hour of a date
*/
int Date::getHour(void) const
{
  return m_hour;
}

/**
* @brief set the hour of a date
* @param a integer indicate the new hour of a date
*/
void Date::setHour(const int t_h)
{
  m_hour = t_h;
}

/**
* @brief return the minute of a Date
* @return   a integer indicate the minute of a date
*/
int Date::getMinute(void) const
{
  return m_minute;
}

/**
* @brief set the minute of a date
* @param a integer indicate the new minute of a date
*/
void Date::setMinute(const int t_minute)
{
  m_minute = t_m;
}

/**
*   @brief check whether the date is valid or not
*   @return the bool indicate valid or not
*/
static bool Date::isValid(const Date &t_date)
{
  if(t_date.m_year < 1000 || t_date.m_year > 9999){ 
    return false;
  }
  int leap = 0
  if(t_date.m_year % 4 == 0 && t_date.m_year % 100 != 0){
    leap = 1;
  }
  if(t_date.m_yearr % 400 == 0){
    leap = 1;
  }
  int array1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int array2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
  if(leap == 0){
    if(t_date.m_month <= 0 || t_date.m_month >= 13 || t_date.m_day > array1[m-1] || t_date.m_day <= 0){
      return false;
      }
  }
  else{

    if(t_date.m_month <= 0 || t_date.m_month >= 13 || t_date.m_day > array2[m-1] || t_date.m_day <= 0){
      return false;
    }
  }
  if(t_date.m_hour < 0 || t_date.m_hour >= 24 ){
    return false;
  } 
  if(t_date.m_hour < 0 || t_date.m_hour >= 60){
    return false;
  } 
  return true;
}

/**
* @brief convert a string to date, if the format is not correct return
* 0000-00-00/00:00
* @return a date
*/
static Date Date::stringToDate(const string &t_dateString)
{ int my_follow = 1;
   int len = dataString.szie();
   if(len != 16){
    my_follow = 0;
   }
   if(dateString[4] != '-'){
    my_follow = 0;
   }
  if(dateString[7] != '-'){
    my_follow = 0;
   }
  if(dateString[10] != '/'){
    my_follow = 0;
   }
  if(dateString[13] != ':'){
    my_follow = 0;
   }
    for(int count = 0; count < 4; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
    my_follow = 0;
   }
  }
  for(int count = 5; count < 7; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
    my_follow = 0;
   }
  }
  for(int count = 8; count < 10; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
    my_follow = 0;
   }
  }
  for(int count = 11; count < 13; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
    my_follow = 0;
   }
  }
  for(int count = 14; count < 16; count++)
  {
    if(dateString[count] < '0' || dateString[count] > '9'){
     my_follow = 0;
   }
  }
   if(my_follow == 0)
   { 
     this->m_year = 0;
     this->m_month = 0;
     this->m_day = 0;
     this->m_hour = 0;
     this->m_minute = 0;
   }
   else{
     stringstream ss;
     int year1, month1, day1, hour1, minute1;
     char pun;
     ss << t_dateString;
     ss >> year1 >> pun >> month1 >> pun >> day1 >> pun >> hour1 >> pun >> minute1;
     this->m_year = year1;
     this->m_month = month1;
     this->m_day = day1;
     this->m_hour = hour1;
     this->m_minute = minute1;
    }
}

/**
* @brief convert a date to string, if the date is invalid return
* 0000-00-00/00:00
*/
static string Date::dateToString(const Date &t_date){ 
  if(t_data.isValid(t_data) == false)
  {
    string temp_str = "0000-00-00/00:00";
    return temp_str;
  }
  stringstream ss;
  ss << t_date.getYear() << "-"<< t_date.getMonth() << "-"<< t_date.getDay() << "/"<< t_date.getHour() << ":"<< t_date.getMinute();
  ss >> y >> t >> m >> t
      >> d >> t >> h >> t >> mi;
  return ss.str();
}

/**
  *  @brief overload the assign operator
  */
Date &Date::operator=(const Date &t_date){
  m_year = t_date.m_year;
  m_month = t_date.m_month;
  m_day = t_date.m_day;
  m_hour = t_date.m_hour;
  m_minute = t_date.m_minute;
  return *this;
}

/**
* @brief check whether the CurrentDate is equal to the t_date
*/
bool Date::operator==(const Date &t_date) const{
  if(m_year != t_date.m_year || m_month != t_date.m_month)  
    return false;
  if(m_day != t_date.m_day || m_hour != t_date.m_hour)  
    return false;
  if(m_minute != t_date.m_minute)  
    return false;
  return true;
}

/**
* @brief check whether the CurrentDate is  greater than the t_date
*/
bool Date::operator>(const Date &t_date) const
{
  if(m_year > t_date.m_year){ 
    return true;}
  if(m_year < t_date.m_year){ 
    return false;}
  if(m_month > t_date.m_month){
    return true;}
  if(m_month < t_date.m_month){
    return false;}
  if(m_day > t_date.m_day){
    return true;}
  if(m_day < t_date.m_day){ 
    return false;}
  if(m_hour > t_date.m_hour){
    return true;}
  if(m_hour < t_date.m_hour){
    return false;}
  if(m_minute > t_date.m_minute){
    return true;}
  return false;
}
 /**
  * @brief check whether the CurrentDate is  less than the t_date
  */
bool Date::operator<(const Date &t_date) const{
  if(m_year < t_date.m_year){ 
    return true;}
  if(m_year > t_date.m_year){ 
    return false;}
  if(m_month < t_date.m_month){
    return true;}
  if(m_month > t_date.m_month){
    return false;}
  if(m_day < t_date.m_day){
    return true;}
  if(m_day > t_date.m_day){ 
    return false;}
  if(m_hour < t_date.m_hour){
    return true;}
  if(m_hour > t_date.m_hour){
    return false;}
  if(m_minute < t_date.m_minute){
    return true;}
  return false;
}

/**
* @brief check whether the CurrentDate is  greater or equal than the t_date
*/
bool Date::operator>=(const Date &t_date) const
{
  if(m_year > t_date.m_year){ 
    return true;}
  if(m_year < t_date.m_year){ 
    return false;}
  if(m_month > t_date.m_month){
    return true;}
  if(m_month < t_date.m_month){
    return false;}
  if(m_day > t_date.m_day){
    return true;}
  if(m_day < t_date.m_day){ 
    return false;}
  if(m_hour > t_date.m_hour){
    return true;}
  if(m_hour < t_date.m_hour){
    return false;}
  if(m_minute >= t_date.m_minute){
    return true;}
  return false;
}

/**
* @brief check whether the CurrentDate is  less than or equal to the t_date
*/
bool Date::operator<=(const Date &t_date) const
{
   if(m_year < t_date.m_year){ 
    return true;}
  if(m_year > t_date.m_year){ 
    return false;}
  if(m_month < t_date.m_month){
    return true;}
  if(m_month > t_date.m_month){
    return false;}
  if(m_day < t_date.m_day){
    return true;}
  if(m_day > t_date.m_day){ 
    return false;}
  if(m_hour < t_date.m_hour){
    return true;}
  if(m_hour > t_date.m_hour){
    return false;}
  if(m_minute <= t_date.m_minute){
    return true;}
  return false;
}
}
