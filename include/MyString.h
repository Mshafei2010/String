#ifndef MYSTRING_H
#define MYSTRING_H


class MyString
{
    public:
        MyString();
        MyString(char * letters );
        MyString(const MyString &old);
        void Remove ();
        void Add (char item);
        int Length ();
        void Swap(MyString &first );
        char * Copy (int pos ,int len);
        void get();
        int Compare ( MyString string2);
        char* ToUpperCase();
        char* ToLowerCase();
        char* Trim();
        char* Substring (int startIndex,int endIndex);
        int FirstIndexOf (char ch);
        int LastIndexOf (char ch);
        char * Replace (char oldChar, char newChar);
        char * operator+(const MyString& str);
        int LastIndexOf(int ch);
        int FirstIndexOf (int ch);
        ~MyString();
    protected:

    private:
        int index;
        char newchar;
        int lettersnum=0;
        char * word;
        char * newcopy;
        bool flag=0;
        int caseSensitve;
        int oldletter,currentletter;
};

#endif // MYSTRING_H
