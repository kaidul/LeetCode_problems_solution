#include <bits/stdc++.h>
#include <dirent.h>
using namespace std;

int main(void) {
    DIR *dir;
    char *directoryPath = "E:\\LeetCode_problems_solution\\";
    struct dirent *ent;
    if ((dir = opendir (directoryPath)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            char filename[1000];
            for(int i = 0; i < strlen(ent->d_name); ++i) {
                if(ent->d_name[i] == ' ')
                    filename[i] = '_';
                else filename[i] = ent->d_name[i];
            }
            filename[strlen(ent->d_name)] = '\0';
            int result = rename(ent->d_name, filename);
            if(result == 0) puts ( "File successfully renamed" );
            else perror( "Error renaming file" );
//            printf ("%s, %s\n", ent->d_name, filename); // foo bar, foo_bar
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }
    return 0;
}
