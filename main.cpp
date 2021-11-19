/*
    Mohamed Ahmed Mohamed Shafei
*/
#include <iostream>
#include "MYSTRING.h"
#include <cstring>

using namespace std;

int main()
{
    char* Word;
    char* SecWord;
    int choice;
    char item,oldchar,newchar;
    int pos,len,worduse,startIndex,endIndex,retindex,indexFirst,indexSecond,asciion=0,asciiCode;
    Word=new char [1024];
    SecWord=new char[1024];
    cout<<"Enter  the first Word:";
    cin.getline(Word,1024);
    cout<<"Enter the second Word:";
    cin.getline(SecWord,1024);

    MyString First(Word);
    MyString Second(SecWord);
    while(true)
    {
        cout<<"Choose your required function from the following: \n ";
        cout<<"1.Remove function.\n 2.Add function \n 3.length function. \n 4.Copy function. \n 5.Swap function. \n 6.Concentrate function. \n 7.Compare which word is longer \n 8.get substring \n 9.Trim \n 10.Lowercase copy of the word\n 11.Uppercase copy of the word\n 12.First Index of specified character \n 13.Last Index of specified character \n 14.Replace character \n 15.Show word \n 16.End Program. \n 0.try copy constructor \n";
        cout<<"Your choice: ";
        cin>>choice;
        if(choice==16)
            break;
        else if(choice>16)
        {
            cout<<"Wrong choice please write again\n";
            continue;
        }
        if(choice!=5&&choice!=7)
        {
            cout<<"Choose first or second word: ";
            cin>>worduse;
        }
        if(choice==0)
        {
            if(worduse==1)
            {
                MyString Third (First);
                Third.get();
            }
            else
            {
                MyString Third (Second);
                Third.get();
            }
        }
        if (choice== 1)
        {
            if(worduse==1)
            {
                First.Remove();
                First.get();
            }
            else
            {
                Second.Remove();
                Second.get();
            }
        }
        else if (choice == 2)
        {

            cout<<"Enter the character: ";
            cin>>item;
            if(worduse==1)
            {
                First.Add(item);
                First.get();
            }
            else
            {
                Second.Add(item);
                Second.get();
            }

        }

        else if (choice == 3)
        {
            if(worduse==1)
            {
                cout<<First.Length()<<endl;
            }
            else
            {
                cout<<Second.Length()<<endl;
            }
        }
        else if (choice == 4)
        {
            cout<<"Enter position:";
            cin>>pos;
            cout<<"Enter length:";
            cin>>len;
            if(worduse==1)
            {
                cout<<First.Copy(pos,len)<<endl;
            }
            else
            {
                cout<<Second.Copy(pos,len)<<endl;
            }
        }

        else if (choice == 5)
        {
            First.Swap(Second);
            cout<<"First Word: ";
            First.get();
            cout<<endl<<"Second Word: ";
            Second.get();
        }
        else if (choice == 6)
        {
            if(worduse==1)
                cout<<First+Second<<endl;
            else
                cout<<Second+First<<endl;
        }
        else if (choice == 7)
        {
            cout<<"The Result: "<<First.Compare(Second)<<endl;
        }
        else if (choice == 8)
        {
            cout<<"Enter start index:";
            cin>>startIndex;
            cout<<"Enter end index:";
            cin>>endIndex;
            if(worduse==1)
            {
                cout<<First.Substring(startIndex,endIndex)<<endl;
            }
            else
            {
                cout<<Second.Substring(startIndex,endIndex)<<endl;
            }
        }
        else if (choice == 9)
        {
            if(worduse==1)
            {
                char *NewCopy= new char[First.Length()];
                NewCopy=First.Trim();
                cout<<"The word after trim :"<<NewCopy<<endl;
                delete []NewCopy;
            }
            else
            {
                char *NewCopy= new char[Second.Length()];
                NewCopy=Second.Trim();
                cout<<"The word after trim :"<<NewCopy<<endl;
                delete []NewCopy;
            }
        }
        else if (choice== 10)
        {
            if(worduse==1)
            {
                char *NewCopy= new char[First.Length()];
                NewCopy=First.ToLowerCase();
                cout<<NewCopy<<endl;
                delete []NewCopy;
            }
            else
            {
                char *NewCopy= new char[Second.Length()];
                NewCopy=Second.ToLowerCase();
                cout<<NewCopy<<endl;
                delete []NewCopy;
            }
        }
        else if (choice== 11)
        {
            if(worduse==1)
            {
                char *NewCopy= new char[First.Length()];
                NewCopy=First.ToUpperCase();
                cout<<NewCopy<<endl;
                delete []NewCopy;
            }
            else
            {
                char *NewCopy= new char[Second.Length()];
                NewCopy=Second.ToUpperCase();
                cout<<NewCopy<<endl;
                delete []NewCopy;
            }
        }
        else if (choice== 12)
        {

            cout<<"Do you want to use ascii code: 1-Yes \t 2-No\n";
            cin>>asciion;
            if(asciion==2)
            {
                cout<<"Enter the wanted character :";
                cin>>oldchar;
                if(worduse==1)
                {
                    retindex=First.FirstIndexOf(oldchar);
                    if(retindex==-1)
                        cout<<"This character is not found";
                    else
                        cout<<retindex+1;
                }
                else
                {
                    retindex=Second.FirstIndexOf(oldchar);
                    if(retindex==-1)
                        cout<<"This character is not found";
                    else
                        cout<<retindex+1;
                }
            }
            else if(asciion==1)
            {
                cout<<"Enter the wanted ascii :";
                cin>>asciiCode;
                if(worduse==1)
                {
                    retindex=First.FirstIndexOf(asciiCode);
                    if(retindex==-1)
                        cout<<"This character is not found";
                    else
                        cout<<retindex+1;
                }
                else
                {
                    retindex=Second.FirstIndexOf(asciiCode);
                    if(retindex==-1)
                        cout<<"This character is not found";
                    else
                        cout<<retindex+1;
                }
            }
            else
                cout<<"Wrong Input";
            cout<<endl;
        }
        else if (choice== 13)
        {
            cout<<"Do you want to use ascii code: 1-Yes \t 2-No\n";
            cin>>asciion;
            if(asciion==2)
            {
                cout<<"Enter the wanted character :";
                cin>>oldchar;
                if(worduse==1)
                {
                    retindex=First.LastIndexOf(oldchar);
                    if(retindex==-1)
                        cout<<"This character is not found";
                    else
                        cout<<retindex+1;
                }
                else
                {
                    retindex=Second.LastIndexOf(oldchar);
                    if(retindex==-1)
                        cout<<"This character is not found";
                    else
                        cout<<retindex+1;
                }
            }
            else if(asciion==1)
            {
                cout<<"Enter the wanted ascii :";
                cin>>asciiCode;
                if(worduse==1)
                {
                    retindex=First.LastIndexOf(asciiCode);
                    if(retindex==-1)
                        cout<<"This character is not found";
                    else
                        cout<<retindex+1;
                }
                else
                {
                    retindex=Second.LastIndexOf(asciiCode);
                    if(retindex==-1)
                        cout<<"This character is not found";
                    else
                        cout<<retindex+1;
                }
            }
            else
                cout<<"Wrong Input";
            cout<<endl;
        }

        else if (choice == 14)
        {
            cout<<"Enter old character :";
            cin>>oldchar;
            cout<<"Enter new character:";
            cin>>newchar;
            if(worduse==1)
            {
                cout<<First.Replace(oldchar,newchar)<<endl;
            }
            else
            {
                cout<<Second.Replace(oldchar,newchar)<<endl;
            }
        }
        else if(choice==15)
        {
            if(worduse==1)
            {
                First.get();
            }
            else
            {
                Second.get();
            }
        }
    }
    delete [] Word;
    delete [] SecWord;
    return 0;
}
/*
    char *x,*y;
    x= new char [1024];
    y= new char [1024];
    char z;
    x[0]='s';
    y[0]='w';
    z=x[0];
    *x='z';
    cin.getline(x,1024);
    MyString c(x,strlen(x));
    c.get();

    char* Word;
    char* SecWord;
    int choice;
    char item;
    int pos,len;
    Word=new char[1];
    SecWord=new char[1];
    cout<<"Enter  the first Word:";
    cin>>Word;
    cout<<"Enter the second Word:";
    cin>>SecWord;

    MyString x(Word,strlen(Word));
    MyString y(SecWord,strlen(SecWord));
    cout<<"Choose your required function from the following: \n ";
    cout<<"1.Remove function.\n 2.Add function \n 3.length function. \n 4.Copy function. \n 5.Swap function. \n 6.Concentrate function. \n";
    cout<<"Your choice: ";
    cin>>choice;

    if (choice== 1)
    {
        x.Remove();
        x.get();

    }
    else if (choice == 2)
    {

        cout<<"Enter the character: ";
        cin>>item;
        x.Add(item);
        x.get();

    }

    else if (choice == 3)
    {
        cout<<x.Length();
    }
    else if (choice == 4)
    {
        cout<<"Enter position:";
        cin>>pos;
        cout<<"Enter lenght:";
        cin>>len;
        cout<<x.Copy(pos,len);


    }

    else if (choice == 5)
    {
        x.Swap(y);
        x.get();
        cout<<endl;
        y.get();


    }
    else if (choice == 6)
    {


    }
    delete []x;
    delete []y;*/
