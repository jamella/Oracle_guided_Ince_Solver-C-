#include<iostream>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <zlib.h>
#include <sys/resource.h>
#include <unistd.h>

#include "utils/incresolver.h"
#include "utils/System.h"
#include "utils/ParseUtils.h"
#include "utils/Options.h"
#include "core/Dimacs.h"
#include "simp/SimpSolver.h"

using namespace Minisat;
using std::string;
using Incre::existFile;

static Solver* solver;
int main(int argc, char **argv){

const char* milter_file;

try{	

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

/* the folloing lines specify some feature of solver, I will not consider it right now*/
//	if(!pre) S.eliminate(true);
//	S.verbosity = verb;
	solver = &S;

//	signal(SIGINT, SIGINT_exit);
//  signal(SIGXCPU,SIGINT_exit);

    // Set limit on CPU-time:
    /*
    if (cpu_lim != INT32_MAX){
        rlimit rl;
        getrlimit(RLIMIT_CPU, &rl);
        if (rl.rlim_max == RLIM_INFINITY || (rlim_t)cpu_lim < rl.rlim_max){
            rl.rlim_cur = cpu_lim;
            if (setrlimit(RLIMIT_CPU, &rl) == -1)
                printf("WARNING! Could not set resource limit: CPU-time.\n");
        } }
	*/
    // Set limit on virtual memory:
    /*
    if (mem_lim != INT32_MAX){
        rlim_t new_mem_lim = (rlim_t)mem_lim * 1024*1024;
        rlimit rl;
        getrlimit(RLIMIT_AS, &rl);
        if (rl.rlim_max == RLIM_INFINITY || new_mem_lim < rl.rlim_max){
            rl.rlim_cur = new_mem_lim;
            if (setrlimit(RLIMIT_AS, &rl) == -1)
                printf("WARNING! Could not set resource limit: Virtual memory.\n");
            } }
	*/
     //print help info if solver called without any parameter
	if (argc == 1)
		printf("Reading from standard input... Use '--help' for help.\n");


/*------------------------------------------------------------------------------------------------*/
/*																								  */
/*																								  */
/*								HERE, I START OUR OWN PARSER									  */
/*																								  */
/*																								  */
/*------------------------------------------------------------------------------------------------*/

milter_file = "testtest";
	gzFile in = (existFile(milter_file) == 1) ? gzopen(milter_file, "rb") : gzopen(0, "rb");
	return 0;

}
catch (OutOfMemoryException&){
printf("===============================================================================\n");
printf("INDETERMINATE\n");
exit(0);}
}
