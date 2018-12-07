/* Plagiarism FIle IO
 * Plagiarism Catcher by Felipe Palacios and Ahmad Ahsen
 * EE312 Priebe
 * */
#ifndef PLAGIARISMCATCHER_PLAGIARISMCATCHER_H
#define PLAGIARISMCATCHER_PLAGIARISMCATCHER_H




#include <string>
#include <vector>
#include <dirent.h>
#include <iostream>
#include <errno.h>
#include "hashMap.h"

using namespace std;

int getdir (string dir, vector<string> &files);

#endif //PLAGIARISMCATCHER_PLAGIARISMCATCHER_H