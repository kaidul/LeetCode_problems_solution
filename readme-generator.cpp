#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <cassert>
#include <dirent.h>
using namespace std;

int main(void) {
    freopen("README.md", "w", stdout);
    puts("## Solutions to LeetCode Programming Problems\n\n");
    DIR *dir;
    char *directoryPath = "/Users/kaidul/LeetCode_problems_solution/source-code/";
    struct dirent *ent;
    int serialNo = 0;
    if ((dir = opendir (directoryPath)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            int n = strlen(ent->d_name);
            if(n < 5) { // skip hidden files
                continue;
            }
            char filename[260];
            for(int i = 0; i < n; ++i) {
                if(ent->d_name[i] == '_')
                    filename[i] = ' ';
                else filename[i] = ent->d_name[i];
            }
            filename[n] = '\0';
            string sFileName = string(filename);
            int dot = sFileName.find('.');
            assert(dot != string::npos);
            sFileName = sFileName.substr(0, dot); // trimming extension
            printf("%d. [%s](source-code/%s)\n", ++serialNo, sFileName.c_str(), ent->d_name);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("Directory open failed.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
