#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <cassert>
#include <dirent.h>
#include<vector>
using namespace std;

int main(void) {
    freopen("README.md", "w", stdout);
    puts("## Solutions to LeetCode Programming Problems\n\n");
    DIR *dir;
    const char *directoryPath = "/Users/kaidul/LeetCode_problems_solution/source-code/";
    struct dirent *ent;
    if ((dir = opendir (directoryPath)) != NULL) {
	vector<string> listItems;
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
            // ignoring Mac's .DS_Store
            if(sFileName == ".DS_Store") {
		continue;
	    }
            int dot = sFileName.find('.');
            assert(dot != string::npos);
            sFileName = sFileName.substr(0, dot); // trimming extension
            char buffer[512];
	    sprintf(buffer, "[%s](source-code/%s)", sFileName.c_str(), ent->d_name);
	    listItems.push_back(string(buffer));
        }
	sort(listItems.begin(), listItems.end());
	int serialNo = 0;
	for(string const& item : listItems) {
	    printf("%d. %s\n", ++serialNo, item.c_str());
	}
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("Directory open failed.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
