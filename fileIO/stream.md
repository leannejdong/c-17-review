## Stream Types

* iostream 

    - ostream (cout)

    - istream (cin)

* fstream

    - ofstream (file stream for writing)

    - ifstream (file stream for reading)

* Your computer has many files, one need to associate the stream instance with the file we are using

    - One easiest way to open a file is to pass its name to the fstream constructor. This creates a stream variable which will open the file and bind to it. For instance, if we want to open `verona.csv` or `majid.txt`. We would

    ```cpp
    // Opens verona.csv for reading and binds it to the ifile1 stream variable
    ifstream ifile1("verona.csv");

    // Opens majid.txt for reading and binds it to the ifile2 stream variable
    ifstream ifile2("majid.txt")
    ```
    - Don't forget to check the stream state before using it.  The overloaded bool operator, i.e. `.operator bool()` will return true if the stream is ready for use, false otherwise.

    ```cpp
    // equivalent to if(ifile.operator bool())
    if(ifile1){
        std::cout << " verona.csv opened success\n";
    }

### Example

```cpp
ifstream ifile1("verona.csv");
if(ifile1){
    // Read a word from ifile1 and store it in str
    ifile1 >> str;
    // Release the binding between ifile1 and verona.csv
    ifile1.close();
}
```
Or pictorially,

```
            ifile1
verona.csv -------> ifstream ---> str

```

### Reading from a file

#### Read a file word by word

```cpp
while(ifile1 >> text){
    cout << text << ",";
}
```

* This will read one word at a time and remove all whitespace from the input. (May not be what you want)

* Sometimes we have file involve text, numbers of different type. It could be difficult to code unless the file structure exactly meets the program's expectations.

#### Read from a file line by line

* The `getline()` reads an entire line from the file into a std::string.

```
    std::string text;
    // reads one line from ifile and stores it in text
    while (getline(ifile, text)){
        cout << text << "\n";
    }

* The string variable `text` will contain the entire line of text, except for the final newline character.



