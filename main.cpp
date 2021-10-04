//For Basic IO
#include <iostream>
//For the Timing Related Tasks
#include <chrono>

using namespace std;

//Main Program Function
int run(int argc, char *argv[])
{
    //Initializing the File Objects
    FILE *ifile, *ofile;

    //Initializing the Files
    ifile = fopen(argv[1], "r");
    ofile = fopen(argv[2], "w");

    //Initializing the Variables
    char c;
    unsigned long long lineNos = 1;

    //Main Loop -> Getting Character by Character and Inserting them into the Out File
    while (true)
    {
        c = fgetc(ifile);

        //Checking if the File had came to the End
        if (static_cast<int>(c) == EOF)
            break;

        //Character Validation
        if (c == ' ')
        {
            ;
        }
        else if (c == '\n')
        {
            lineNos++;
        }
        else
        {
            //Writing to the Output File
            fprintf(ofile, "%c", c);
        }
    }

    //Closing the Files
    fclose(ifile);
    fclose(ofile);

    //Returning the No of Lines
    return lineNos;
}

//Usage
void printUsage()
{
    cout << "\n\t-----|> MINIFY <|-----\n\n";
    cout << "A Simple yet Powerful and Ultrafast File Minifier.\n";
    cout << "Usage:\n";
    cout << "\tminify [input file] [output file]\n\n";
}

int main(int argc, char *argv[])
{
    //Checking if the Arguments are Entered
    if (argc < 3)
    {
        printUsage();
        return 0;
    }

    cout << "Starting Execution....\n";

    //Getting Starting Time
    auto start = chrono::high_resolution_clock::now();

    //Executing the Main Program
    auto lines = run(argc, argv);

    //Getting Ending Time
    auto end = chrono::high_resolution_clock::now();

    //Getting Duration by the start and end difference
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    //Print the Result
    cout << "Execution Finished of " << lines << " lines in " << static_cast<float>(duration.count() / 1000) << "ms.\n";

    return 0;
}