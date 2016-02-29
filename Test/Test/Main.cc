#include<iostream>
#include <errno.h>

#include <signal.h>
#include <zlib.h>
#include <sys/resource.h>

#include "utils/System.h"
#include "utils/ParseUtils.h"
#include "utils/Options.h"
#include "core/Dimacs.h"
#include "simp/SimpSolver.h"
using namespace std;
using namespace Minisat;
int main(int argc, char **argv){
	

        setUsageHelp("Here to type in the help message!\n");
/*I don't understand the following code*/
//       IntOption    verb   ("MAIN", "verb",   "Verbosity level (0=silent, 1=some, 2=more).", 1, IntRange(0, 2));
//      BoolOption   pre    ("MAIN", "pre",    "Completely turn on/off any preprocessing.", true);
//        StringOption dimacs ("MAIN", "dimacs", "If given, stop after preprocessing and write the result to this file.");
//        IntOption    cpu_lim("MAIN", "cpu-lim","Limit on CPU time allowed in seconds.\n", INT32_MAX, IntRange(0, INT32_MAX));
//        IntOption    mem_lim("MAIN", "mem-lim","Limit on memory usage in megabytes.\n", INT32_MAX, IntRange(0, INT32_MAX));


	parseOptions(argc, argv, true);

	SimpSolver S;
	double initial_time = cpuTime();

	if(!pre) S.

	return 0;

}
