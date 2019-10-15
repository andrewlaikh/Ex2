#include <iostream>
#include <cstring>

using namespace std;

void encode (const char* surname, char* soundex);
bool compare(const char* str1, const char* str2);
int count(const char* surname, const char* sentenceOriginal);

int main()
{

  char soundex[5];

  cout << "====================== Question 1 =====================" << endl;

   encode("Washington", soundex);
   cout << "The soundex coding for 'Washington' is " << soundex << endl;
   
   encode("Leeson", soundex);
   cout << "The soundex coding for 'Leeson' is " << soundex << endl;

   encode("Jackson", soundex);
   cout << "The soundex coding for 'Jackson' is " << soundex << endl;
// question 2
/*
cout << "====================== Question 2 ======================" << endl;

cout << "The soundex codes S250 and S255 are ";
if (!compare("S250", "S255"))
  cout << "not ";
cout << "equal" << endl;

cout << "The soundex codes W252 and W252 are ";
if (!compare("W252", "W252"))
  cout << "not ";
cout << "equal" << endl;

// question 3

cout << "====================== Question 3 ======================" << endl;

cout << "There are ";
cout << count("Leeson", "Linnings, Leasonne, Lesson and Lemon.") << " ";
cout << "surnames in the sentence 'Linnings, Leasonne, Lesson and Lemon.'"
     << endl;
cout << "  that have the same Soundex encoding as 'Leeson'" << endl;

cout << "There are ";
cout << count("Jackson", "Jakes, Jaxin, J acksin, Jones.");
cout << " surnames in the sentence 'Jakes, Jaxin, J acksin, Jones.'"
     << endl;
cout << "  that have the same Soundex encoding as 'Jackson'" << endl << endl;*/
  return 0;
}


bool compare(const char* str1, const char* str2)
{
    if(str1[0]!='\0'||str2[0]!='\0')
    {
        if(str1[0]==str2[0])
        {
            compare((str1+1), (str2+1));
        }
        else
            return false;
    }
        return true;
}

void encode(const char* surname, char* soundex)
{
  soundex[0]='\0';
  char temp;
  int length = 1;
  int flag = 0;
  int count = 0;
  *(soundex) = *(surname);
  while (length < 4)
  {
    while (*(surname+count)!='\0')
    {
      switch(*(surname+count))
      {
        case 'b':
        case 'f':
        case 'p':
        case 'v':
          temp = '1';
          break;
        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
          temp = '2';
          break;
        case 'd':
        case 't':
          temp = '3';
          break;
        case 'l':
          temp = '4';
          break;
        case 'm':
        case 'n':
          temp = '5';
          break;
        case 'r':
          temp = '6';
          break;
        default:
          flag = 9;
          break;
        }
        if (temp!= *(soundex+length-1) && flag!= 9)
        {
          *(soundex+length) = temp;
          length++;
        }
        flag = 0;
        count++;
    }
  while(length < 4)
  {
      *(soundex+length) = '0';
      length++;
  }
  }
  *(soundex+4) = '\0';
  return;
}

int count(const char* surname, const char* sentenceOriginal)
{
  int count(0), trackerFront(0), trackerBack(0);
  char soundex[5],sentence[100], soundexSurname[5];
  strcpy(sentence,sentenceOriginal);
  encode (surname, soundex);
  strcpy(soundexSurname,soundex);
  while((int)*(sentence+trackerBack)!= '\0')
  {
    while((int)*(sentence+trackerBack)<32 || (int)*(sentence+trackerBack)>47)
    {
      trackerBack=trackerBack+1;
    }
    if (trackerBack-trackerFront>0)
    {
      char word[80];
      for(int i = 0; i < (trackerBack-trackerFront); i++)
      {
        *(word+i)=*(sentence+trackerFront+i);
      }
      *(word+trackerBack-trackerFront)='\0';
      encode(word,soundex);
      if(compare(soundex,soundexSurname)==true)
      {
        count++;
      }
      trackerBack=trackerBack+1;
      trackerFront=trackerBack;
    }
    else
    {
        trackerBack=trackerBack+1;
        trackerFront=trackerBack;
    }
  }
  return count;
}
