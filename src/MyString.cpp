#include "MyString.h"
#include <iostream>

using namespace std;

MyString::MyString()
{
    word=new char [1];
    word[0]='\0';
    lettersnum=0;
}

MyString::MyString(char * letters)
{
    for(int i =0 ; letters[i] != '\0';i++ )
    {
        lettersnum++;
    }
    //cout<<lettersnum;
    word=new char [lettersnum+1];
    for(int copier = 0 ; copier < lettersnum ; copier ++ )
    {
        newchar=letters[copier];
        word[copier]=newchar;
    }
    word[lettersnum]='\0';
}
MyString::MyString(const MyString &old)
{
    word=new char [(old.lettersnum)+1];
    lettersnum=old.lettersnum;
    for(int copier = 0 ; copier < lettersnum+1 ; copier ++ )
    {
        newchar=old.word[copier];
        word[copier]=newchar;
    }
}
void MyString:: Remove ()
{
    word[lettersnum-1]='\0';
    lettersnum--;
//  cout<<word;
}
void MyString::Add (char item)
{
    lettersnum++;
    //cout<<lettersnum;
    if(flag==1)
    {
        delete [] newcopy;
        newcopy=new char [lettersnum+1];
    }
    else
    {
        newcopy=new char [lettersnum+1];
        flag=1;
    }
    for(int copier = 0 ; copier < lettersnum-1 ; copier ++ )
    {
        newchar=word[copier];
        newcopy[copier]=newchar;
    }
    newcopy[lettersnum-1]=item;
    newcopy[lettersnum]='\0';
    //cout<<newcopy<<endl;

    delete [] word;
    word [lettersnum+1];
    for(int copier = 0 ; copier < lettersnum ; copier ++ )
    {
        newchar=newcopy[copier];
        word[copier]=newchar;
    }
    word[lettersnum]='\0';
    //delete [] newcopy;
//  cout<<word;
}
int MyString:: Length ()
{
    return lettersnum;
}
void MyString:: Swap(MyString &first )
{
    if(flag==1)
    {
        delete [] newcopy;
        newcopy=new char [lettersnum+1];
    }
    else
    {
        newcopy=new char [lettersnum+1];
        flag=1;
    }
//  cout<<endl << word <<" " <<first.word;
    char *newcopy ;
    int s=lettersnum;
    newcopy = new char [first.lettersnum+1];
    newcopy=first.word;
    first.word=word;
    word=newcopy;
    lettersnum=first.lettersnum;
    first.lettersnum=s;
//  cout<<endl << word <<" " <<first.word;
}
//1 based
char * MyString::Copy (int pos, int len)
{
    if(pos>lettersnum||len>lettersnum+1-pos)
    {
        cout<<"Invalid Input \nCheck the original word: ";
        return word;
    }
    if(flag==1)
    {
        delete [] newcopy;
        newcopy=new char [lettersnum+1];
    }
    else
    {
        newcopy=new char [len+1];
        flag=1;
    }
    char New ;
    for(int i = 0 ; i < len ; i++)
    {
        New=word[pos+i-1];
        newcopy [i]=New;
    }
    newcopy[len]='\0';
    return newcopy;
}
int MyString ::Compare(MyString string2)
{
    //cout<<endl<<word<<lettersnum<<" " << string2.Length();
    //string2.get();
    if(lettersnum>string2.lettersnum)
        return 1;
    else if(lettersnum<string2.lettersnum)
        return -1;
    else
        return 0;
}

char * MyString::Substring (int startIndex, int endIndex)
{
    return Copy(startIndex,(endIndex-startIndex+1));
}

char * MyString::Trim()
{
    int indexfirst=0,indexlast=0,copying=0;
    /*for(; i<lettersnum; i++ )
    {
        newchar=word[i];
        if(newchar!=' ')
        {
            newcopy[j]=newchar;
            j++;
        }
    }*/
    for(int i=0; i<lettersnum; i++ )
    {
        if(word[i]!=' ')
        {
            indexfirst=i;
            //cout<<"F:"<<indexfirst;
            break;
        }
    }
    for(int i=lettersnum-1; i>=0; i-- )
    {
        if(word[i]!=' ')
        {
            indexlast=i;
            //cout<<" L:"<<indexlast<<endl;
            break;
        }
    }
    if(flag==1)
    {
        delete [] newcopy;
        newcopy=new char [indexlast+2-indexfirst];
    }
    else
    {
        newcopy=new char [indexlast+2-indexfirst];
        flag=1;
    }
    for(int i=indexfirst; i<=indexlast; i++ )
    {
        newchar=word[i];
        newcopy[copying]=newchar;
        copying++;
    }
    newcopy[indexlast+1-indexfirst]='\0';
    return newcopy;
}

char * MyString::ToUpperCase()
{
    if(flag==1)
    {
        delete [] newcopy;
        newcopy=new char [lettersnum+1];
    }
    else
    {
        newcopy=new char [lettersnum+1];
        flag=1;
    }
    int ascii;
    for(int i=0; i<lettersnum; i++)
    {
        ascii=word[i];
        if(word[i]>=97 && word[i]<=122)
        {
            ascii=ascii-32;
            newcopy[i]=ascii;
        }
        else
            newcopy[i]=ascii;
    }
    newcopy[lettersnum]='\0';
    cout<<"Do you want to update in same word : 1-Yes \t2-No\n";
    int update;
    cin>>update;
    if(update==1)
    {
      for(int copier = 0 ; copier < lettersnum+1 ; copier ++ )
        {
            newchar=newcopy[copier];
            word[copier]=newchar;
        }
    }
    return newcopy;
}

char * MyString::ToLowerCase()
{
    if(flag==1)
    {
        delete [] newcopy;
        newcopy=new char [lettersnum+1];
    }
    else
    {
        newcopy=new char [lettersnum+1];
        flag=1;
    }
    int ascii;
    for (int i=0; i<lettersnum; i++)
    {
        ascii=word[i];
        if(word[i]>=65 && word[i]<=90)
        {
            ascii=ascii+32;
            newcopy[i]=ascii;
        }
        else
            newcopy[i]=ascii;
    }
    newcopy[lettersnum]='\0';
    cout<<"Do you want to update in same word : 1-Yes \t2-No\n";
    int update;
    cin>>update;
    if(update==1)
    {
      for(int copier = 0 ; copier < lettersnum+1 ; copier ++ )
        {
            newchar=newcopy[copier];
            word[copier]=newchar;
        }
    }
    return newcopy;
}

int MyString::FirstIndexOf (char ch)
{
    cout<<"Do you want it case sensitive: 1- Yes\t 2-No \n";
    cin>>caseSensitve;
    while(caseSensitve!=1&&caseSensitve!=2)
    {
        cout<<"Please choose 1 for Yes or 2 for No : ";
        cin>>caseSensitve;
    }
    if(caseSensitve==1)
    {

        for (int i=0; i<lettersnum; i++)
        {
            if(ch==word[i])
            {
                index=i;
                return index ;
            }
        }
        return -1 ;
    }
    else if(caseSensitve==2)
    {
        oldletter=ch ;
        for (int i=0; i<lettersnum; i++)
        {
            currentletter=word[i];
            if(oldletter==currentletter||oldletter-32==currentletter||oldletter+32==currentletter)
            {
                index=i;
                return index;
            }
        }
        return -1 ;
    }
}
int MyString::FirstIndexOf (int ch)
{
    for (int i=0; i<lettersnum; i++)
        {
            currentletter=word[i];
            if(ch==currentletter)
            {
                index=i;
                return index;
            }
        }
        return -1 ;
}

int MyString ::LastIndexOf(char ch)
{
    cout<<"Do you want it case sensitive: 1- Yes\t 2-No \n";
    cin>>caseSensitve;
    while(caseSensitve!=1&&caseSensitve!=2)
    {
        cout<<"Please choose 1 for Yes or 2 for No : ";
        cin>>caseSensitve;
    }
    if(caseSensitve==1)
    {

        for (int i=lettersnum-1; i>-1; i--)
        {
            if(ch==word[i])
            {
                index=i;
                return index ;
            }
        }
        return -1 ;
    }
    else if(caseSensitve==2)
    {
        oldletter=ch ;
        for (int i=lettersnum-1; i>-1; i--)
        {
            currentletter=word[i];
            if(oldletter==currentletter||oldletter-32==currentletter||oldletter+32==currentletter)
            {
                index=i;
                return index;
            }
        }
        return -1 ;
    }
}

int MyString ::LastIndexOf(int ch)
{
    for (int i=lettersnum-1; i>-1; i--)
        {
            currentletter=word[i];
            if(ch==currentletter)
            {
                index=i;
                return index;
            }
        }
    return -1 ;
}


char * MyString::Replace (char oldCharacter, char newCharacter)
{
    if(flag==1)
    {
        delete [] newcopy;
        newcopy=new char [lettersnum+1];
    }
    else
    {
        newcopy=new char [lettersnum+1];
        flag=1;
    }
    cout<<"Do you want it case sensitive: 1- Yes\t 2-No \n";
    cin>>caseSensitve;
    while(caseSensitve!=1&&caseSensitve!=2)
    {
        cout<<"Please choose 1 for Yes or 2 for No : ";
        cin>>caseSensitve;
    }
    if(caseSensitve==1)
    {

        for (int i=0; i<lettersnum; i++)
        {
            if(oldCharacter!=word[i])
            {
                newchar=word[i];
                newcopy[i]=newchar;
            }
            else
            {
                newcopy[i]=newCharacter;
            }
        }
    }
    else if(caseSensitve==2)
    {
        oldletter=oldCharacter ;
        for (int i=0; i<lettersnum; i++)
        {
            currentletter=word[i];
            if(oldletter==currentletter||oldletter-32==currentletter||oldletter+32==currentletter)
            {
                newcopy[i]=newCharacter;
            }
            else
            {
                newchar=word[i];
                newcopy[i]=newchar;
            }
        }
    }
    newcopy[lettersnum]='\0';
    cout<<"Do you want to update in same word : 1-Yes \t2-No\n";
    int update;
    cin>>update;
    if(update==1)
    {
      for(int copier = 0 ; copier < lettersnum+1 ; copier ++ )
        {
            newchar=newcopy[copier];
            word[copier]=newchar;
        }
    }
    return newcopy;
}

char * MyString::operator+(const MyString& str)
{
    if(flag==1)
    {
        delete [] newcopy;
        newcopy=new char [lettersnum+1+str.lettersnum];
    }
    else
    {
        newcopy=new char [lettersnum+1+str.lettersnum];
        flag=1;
    }
    int copier = 0;
    for( ; copier < lettersnum ; copier ++ )
        {
            newchar=word[copier];
            newcopy[copier]=newchar;
        }
    for(; copier < lettersnum+str.lettersnum ; copier ++ )
        {
            newchar=str.word[copier-lettersnum];
            newcopy[copier]=newchar;
        }
    newcopy[copier]='\0';
    cout<<"Do you want to update in same word : 1-Yes \t2-No\n";
    int update;
    cin>>update;
    if(update==1)
    {
        delete [] word;
        word=new char [lettersnum+1+str.lettersnum];
      for(int Copier = 0 ; Copier < lettersnum+1+str.lettersnum ; Copier++ )
        {
            newchar=newcopy[Copier];
            word[Copier]=newchar;
        }
    }
    lettersnum=lettersnum+str.lettersnum;
    return newcopy;
}

MyString:: ~MyString()
{
    delete [ ]word;
    delete []newcopy;
}

void MyString::get()
{
    cout<<word<<endl;
}
